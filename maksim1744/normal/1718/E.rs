/*
    author:  Maksim1744
    created: 07.10.2022 13:22:58
*/

pub use __cargo_equip::prelude::*;

use rlib_io::*;
use rlib_tensor::*;
use std::collections::{BTreeMap, BTreeSet, HashMap, HashSet};

fn solve(cin: &mut Reader, cout: &mut Writer, _test: usize) {
    make_output_macro!(cout);

    let (n, m): (usize, usize) = cin.read();
    let a: Tensor<i32, 2> = Tensor::read([n, m], cin);
    let b: Tensor<i32, 2> = Tensor::read([n, m], cin);

    // eprintln!("{:?}", a);
    // eprintln!("{:?}", b);

    let get_graph = |t: Tensor<i32, 2>| -> (Vec<BTreeMap<i32, usize>>, Vec<usize>, Vec<usize>) {
        let mut v: Vec<(i32, (usize, usize))> = Vec::new();
        for i in 0..n {
            for j in 0..m {
                if t[[i, j]] == 0 {
                    continue;
                }
                v.push((t[[i, j]], (i, j)));
            }
        }
        v.sort();
        let mut used = vec![vec![false; m]; n];
        let mut last_ind = 0;
        let mut row_ind: Vec<Option<usize>> = vec![None; n];
        let mut col_ind: Vec<Option<usize>> = vec![None; m];
        for (_, (i, j)) in v.into_iter() {
            if used[i][j] {
                continue;
            }
            for x in 0..n {
                used[x][j] = true;
            }
            for y in 0..m {
                used[i][y] = true;
            }
            row_ind[i] = Some(last_ind);
            col_ind[j] = Some(last_ind);
            last_ind += 1;
        }

        for i in 0..n {
            if row_ind[i].is_none() {
                row_ind[i] = Some(last_ind);
                last_ind += 1;
            }
        }
        for j in 0..m {
            if col_ind[j].is_none() {
                col_ind[j] = Some(last_ind);
                last_ind += 1;
            }
        }

        let row_ind = row_ind.into_iter().map(|i| i.unwrap()).collect::<Vec<_>>();
        let col_ind = col_ind.into_iter().map(|i| i.unwrap()).collect::<Vec<_>>();

        let mut res = vec![BTreeMap::new(); last_ind];
        for i in 0..n {
            for j in 0..m {
                if t[[i, j]] == 0 {
                    continue;
                }
                assert!(res[row_ind[i]].insert(t[[i, j]], col_ind[j]).is_none());
            }
        }
        (res, row_ind, col_ind)
    };

    let mut hashes: HashMap<Vec<(i64, i64)>, i64> = HashMap::new();

    const SHIFT: i64 = 1e13 as i64;

    let mut get_hash = |v: Vec<(i64, i64)>| -> i64 {
        let sz = hashes.len();
        *hashes.entry(v).or_insert(SHIFT + (sz as i64))
    };

    let (ga, row_ind_a, col_ind_a) = get_graph(a.clone());
    let (gb, row_ind_b, col_ind_b) = get_graph(b.clone());

    let make_inv_ind = |v: &Vec<usize>| -> Vec<Option<usize>> {
        let mut result = vec![None; ga.len()];
        for i in 0..v.len() {
            result[v[i]] = Some(i);
        }
        result
    };

    let row_ind_a_inv = make_inv_ind(&row_ind_a);
    let col_ind_a_inv = make_inv_ind(&col_ind_a);
    // let row_ind_b_inv = make_inv_ind(&row_ind_b);
    // let col_ind_b_inv = make_inv_ind(&col_ind_b);

    // eprintln!("{:?}", ga);
    // eprintln!("{:?}", gb);

    let mut init_hashes = |g: &Vec<BTreeMap<i32, usize>>| -> Vec<i64> {
        let mut cycles: Vec<Vec<(i32, usize)>> = vec![Vec::new(); g.len()];
        let mut used_colors: HashSet<(usize, i32)> = HashSet::new();

        for v in 0..g.len() {
            for (&color, &to) in g[v].iter() {
                if used_colors.contains(&(v, color)) {
                    continue;
                }
                let mut cycle = vec![v];
                let mut k = to;
                while k != v && !used_colors.contains(&(k, color)) {
                    cycle.push(k);
                    match g[k].get(&color) {
                        Some(next) => k = *next,
                        None => break,
                    };
                }
                if k == v {
                    let ln = cycle.len();
                    for x in cycle.into_iter() {
                        cycles[x].push((color, ln));
                        used_colors.insert((x, color));
                    }
                } else {
                    for x in cycle.into_iter() {
                        used_colors.insert((x, color));
                    }
                }
            }
        }

        cycles
            .into_iter()
            .enumerate()
            .map(|(i, v)| {
                let mut v = v
                    .into_iter()
                    .map(|(a, b)| (-1 as i64, (a + 1) as i64 * 1_000_000 + (b as i64 + 1)))
                    .collect::<Vec<_>>();
                v.sort();
                if i < n {
                    v.insert(0, (-2, 1));
                } else {
                    v.insert(0, (-2, 2));
                }
                get_hash(v)
            })
            .collect()
    };

    let mut ha = init_hashes(&ga);
    let mut hb = init_hashes(&gb);
    // eprintln!("{:?}", ha);
    // eprintln!("{:?}", hb);

    let mut reduce = |h: &mut Vec<i64>, g: &Vec<BTreeMap<i32, usize>>| loop {
        let cur_dif = h.iter().cloned().collect::<HashSet<i64>>().len();

        let mut vecs: Vec<Vec<(i64, i64)>> = vec![Vec::new(); h.len()];

        for v in 0..g.len() {
            for (&color, &to) in g[v].iter() {
                vecs[to].push((color as i64, h[v]));
                vecs[v].push((color as i64 + 1_000_000, h[to]));
            }
            vecs[v].push((-3, h[v]));
        }

        *h = vecs
            .into_iter()
            .map(|mut v| {
                v.sort();
                get_hash(v)
            })
            .collect();

        let next_dif = h.iter().cloned().collect::<HashSet<i64>>().len();
        if cur_dif == next_dif {
            break;
        }
    };

    reduce(&mut ha, &ga);
    reduce(&mut hb, &gb);
    // eprintln!("{:?}", ha);
    // eprintln!("{:?}", hb);

    {
        let mut has = ha.clone();
        has.sort();
        let mut hbs = hb.clone();
        hbs.sort();
        if has != hbs {
            // assert!(false);
            outln!(-1);
            return;
        }
    }

    let get_ginv = |g: &Vec<BTreeMap<i32, usize>>| -> Vec<BTreeMap<i32, usize>> {
        let mut result = vec![BTreeMap::new(); g.len()];
        for v in 0..g.len() {
            for (&color, &k) in g[v].iter() {
                result[k].insert(color + 1, v);
                result[v].insert(-color - 1, k);
            }
        }
        result
    };

    let gai = get_ginv(&ga);
    let gbi = get_ginv(&gb);

    let mut ua = vec![false; ga.len()];
    let mut ub = vec![false; ga.len()];

    let mut sa: BTreeSet<(i64, usize)> = ha.iter().cloned().enumerate().map(|(a, b)| (b, a)).collect();
    let mut sb: BTreeSet<(i64, usize)> = hb.iter().cloned().enumerate().map(|(a, b)| (b, a)).collect();

    let mut with: Vec<Option<usize>> = vec![None; ga.len()];

    while !sa.is_empty() {
        let (ha0, va) = sa.iter().next().unwrap().clone();
        let (hb0, vb) = sb.iter().next().unwrap().clone();

        assert_eq!(ha0, hb0);

        fn dfs(
            va: usize,
            vb: usize,
            ga: &Vec<BTreeMap<i32, usize>>,
            gb: &Vec<BTreeMap<i32, usize>>,
            ua: &mut Vec<bool>,
            ub: &mut Vec<bool>,
            sa: &mut BTreeSet<(i64, usize)>,
            sb: &mut BTreeSet<(i64, usize)>,
            ha: &mut Vec<i64>,
            hb: &mut Vec<i64>,
            with: &mut Vec<Option<usize>>,
        ) {
            assert_eq!(ua[va], ub[vb]);
            ua[va] = true;
            ub[vb] = true;
            assert!(sa.remove(&(ha[va], va)));
            assert!(sb.remove(&(hb[vb], vb)));
            with[vb] = Some(va);
            for (&color, &toa) in ga[va].iter() {
                let tob = gb[vb][&color];
                if !ua[toa] {
                    dfs(toa, tob, ga, gb, ua, ub, sa, sb, ha, hb, with);
                }
            }
        }

        dfs(va, vb, &gai, &gbi, &mut ua, &mut ub, &mut sa, &mut sb, &mut ha, &mut hb, &mut with);
    }

    let with = with.into_iter().map(|x| x.unwrap()).collect::<Vec<_>>();

    // eprintln!("with = {:?}", with);
    // eprintln!("row_ind_b = {:?}", row_ind_b);
    // eprintln!("col_ind_b = {:?}", col_ind_b);
    // eprintln!("row_ind_a = {:?}", row_ind_a);
    // eprintln!("col_ind_a = {:?}", col_ind_a);
    // eprintln!("row_ind_a_inv = {:?}", row_ind_a_inv);
    // eprintln!("col_ind_a_inv = {:?}", col_ind_a_inv);

    let row_perm = (0..n).map(|i| row_ind_a_inv[with[row_ind_b[i]]].unwrap()).collect::<Vec<_>>();
    let col_perm = (0..m).map(|i| col_ind_a_inv[with[col_ind_b[i]]].unwrap()).collect::<Vec<_>>();

    // eprintln!("{:?}", row_perm);
    // eprintln!("{:?}", col_perm);

    let get_swaps = |perm: Vec<usize>| -> Vec<(usize, usize)> {
        let mut result = Vec::new();

        let mut pos = (0..perm.len()).collect::<Vec<_>>();
        let mut p = (0..perm.len()).collect::<Vec<_>>();

        for i in 0..perm.len() {
            if p[i] == perm[i] {
                continue;
            }
            let j = pos[perm[i]];
            p.swap(i, j);
            pos.swap(p[i], p[j]);
            result.push((i, j));
        }
        result
    };

    let row_swaps = get_swaps(row_perm);
    let col_swaps = get_swaps(col_perm);
    outln!(row_swaps.len() + col_swaps.len());
    for (i, j) in row_swaps.into_iter() {
        outln!(1, i + 1, j + 1);
    }
    for (i, j) in col_swaps.into_iter() {
        outln!(2, i + 1, j + 1);
    }
}

fn main() {
    make_io!(cin, cout);
    solve(&mut cin, &mut cout, 1);
}

// The following code was expanded by `cargo-equip`.

///  # Bundled libraries
/// 
///  - `rlib_integer 0.1.0 (path+)` published in https://github.com/maksim1744/rlib licensed under `MIT` as `crate::__cargo_equip::crates::rlib_integer`
///  - `rlib_io 0.1.0 (path+)`           published in https://github.com/maksim1744/rlib licensed under `MIT` as `crate::__cargo_equip::crates::rlib_io`
///  - `rlib_tensor 0.1.0 (path+)`   published in https://github.com/maksim1744/rlib licensed under `MIT` as `crate::__cargo_equip::crates::rlib_tensor`
#[cfg_attr(any(), rustfmt::skip)]
#[allow(unused)]
mod __cargo_equip {
    pub(crate) mod crates {
        pub mod rlib_integer {pub trait Integer{type Unsigned;type Signed;const BASE_10_LEN:usize;const ZERO:Self;const ONE:Self;const TWO:Self;fn unsigned_abs(self)->Self::Unsigned;}macro_rules!integer_common{($it:ty,$ut:ty,$len:expr)=>{type Unsigned=$ut;type Signed=$it;const BASE_10_LEN:usize=$len;const ZERO:Self=0;const ONE:Self=1;const TWO:Self=2;};}macro_rules!base_10_len{($ut:ty)=>{{let mut value=<$ut>::MAX;let mut ans:usize=0;while value!=0{value/=10;ans+=1;}ans}};}macro_rules!integer{($it:ty,$ut:ty,$len:expr)=>{impl Integer for$it{integer_common!($it,$ut,$len);fn unsigned_abs(self)->Self::Unsigned{Self::unsigned_abs(self)}}impl Integer for$ut{integer_common!($it,$ut,$len);fn unsigned_abs(self)->Self::Unsigned{self}}};($it:ty,$ut:ty)=>{integer!($it,$ut,base_10_len!($ut));};}integer!(i8,u8);integer!(i16,u16);integer!(i32,u32);integer!(i64,u64);integer!(i128,u128);integer!(isize,usize);}
        pub mod rlib_io {use crate::__cargo_equip::preludes::rlib_io::*;pub use crate::__cargo_equip::macros::rlib_io::*;pub mod output_macro{use crate::__cargo_equip::preludes::rlib_io::*;#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_out_impl{($writer:ident,$x:expr)=>{$writer.write(&$x);};($writer:ident,$x:expr,$($xx:tt)*)=>{$writer.write(&$x);$writer.write_char(' ');rlib_io::out_impl!($writer,$($xx)*);};}macro_rules!out_impl{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_out_impl!{$($tt)*})}#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_make_output_macro_{($writer:ident)=>{make_output_macro_!($writer,$);};($writer:ident,$dol:tt)=>{#[allow(unused_macros)]macro_rules!out{($dol($dol x:tt)*)=>{rlib_io::out_impl!($writer,$dol($dol x)*);};}#[allow(unused_macros)]macro_rules!outln{($dol($dol x:tt)*)=>{rlib_io::out_impl!($writer,$dol($dol x)*);$writer.write_char('\n');};}}}macro_rules!make_output_macro_{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_make_output_macro_!{$($tt)*})}pub use crate::__cargo_equip::crates::rlib_io::make_output_macro_ as make_output_macro;}pub mod reader{use crate::__cargo_equip::preludes::rlib_io::*;use std::io::Read;pub struct Reader{buf:[u8;Reader::BUF_SIZE],begin:usize,end:usize,stdin:Box<dyn Read>,eof:bool,}impl Reader{const BUF_SIZE:usize=1<<16;pub fn new(stdin:Box<dyn Read>)->Self{Self{buf:[0;Reader::BUF_SIZE],begin:0,end:0,stdin,eof:false,}}pub fn read<T:Readable>(&mut self)->T{T::read(self)}pub fn read_vec<T:Readable>(&mut self,n:usize)->Vec<T>{let mut result=Vec::<T>::with_capacity(n);for _ in 0..n{result.push(self.read());}result}fn refill(&mut self){if self.eof{return;}if self.begin!=0{self.buf.copy_within(self.begin..self.end,0);self.end-=self.begin;self.begin=0;}let bytes=self.stdin.read(&mut self.buf[self.end..]).unwrap();if bytes==0{self.eof=true;}self.end+=bytes;}fn skip_whitespace(&mut self){while{if self.begin==self.end{self.refill();}!self.eof&&self.peek().is_ascii_whitespace()}{self.begin+=1;if self.begin==self.end{self.refill();}}}fn peek(&mut self)->u8{if self.begin==self.end{self.refill();}self.buf[self.begin]}}pub trait Readable{fn read(reader:&mut Reader)->Self;}impl Readable for String{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result=String::new();let mut read_something=false;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{result.push(reader.peek()as char);reader.begin+=1;read_something=true;}debug_assert!(read_something);result}}macro_rules!read_signed{($t:ty)=>{impl Readable for$t{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result:$t=0;let mut read_something=false;if reader.peek()==b'-'{reader.begin+=1;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10-(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}}else{while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10+(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}}debug_assert!(read_something);result}}};}macro_rules!read_unsigned{($t:ty)=>{impl Readable for$t{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result:$t=0;let mut read_something=false;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10+(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}debug_assert!(read_something);result}}};}read_signed!(i8);read_signed!(i16);read_signed!(i32);read_signed!(i64);read_signed!(i128);read_signed!(isize);read_unsigned!(u8);read_unsigned!(u16);read_unsigned!(u32);read_unsigned!(u64);read_unsigned!(u128);read_unsigned!(usize);macro_rules!read_tuple{($($t:ident),*)=>{impl<$($t:Readable,)*>Readable for($($t,)*){fn read(reader:&mut Reader)->Self{($($t::read(reader)),*)}}}}read_tuple!(A,B);read_tuple!(A,B,C);read_tuple!(A,B,C,D);read_tuple!(A,B,C,D,E);read_tuple!(A,B,C,D,E,F);read_tuple!(A,B,C,D,E,F,G);read_tuple!(A,B,C,D,E,F,G,H);}pub mod writer{use crate::__cargo_equip::preludes::rlib_io::*;use std::io::Write;use rlib_integer::Integer;pub struct Writer<'a>{buf:[u8;Writer::BUF_SIZE],end:usize,stdout:Box<dyn Write+'a>,}impl<'a>Writer<'a>{const BUF_SIZE:usize=1<<16;pub fn new(stdout:Box<dyn Write+'a>)->Self{Self{buf:[0;Writer::BUF_SIZE],end:0,stdout,}}pub fn write<T:Writable>(&mut self,t:&T){t.write(self);#[cfg(debug_assertions)]self.flush();}pub fn write_char(&mut self,c:char){self.write_bytes(&[c as u8]);#[cfg(debug_assertions)]self.flush();}fn flush(&mut self){if self.end==0{return;}self.stdout.write_all(&self.buf[..self.end]).unwrap();self.end=0;}fn reserve(&mut self,size:usize){if self.end+size>self.buf.len(){self.flush();}}fn write_bytes(&mut self,buf:&[u8]){self.reserve(buf.len());self.buf[self.end..self.end+buf.len()].copy_from_slice(buf);self.end+=buf.len();}}impl Drop for Writer<'_>{fn drop(&mut self){self.flush();}}pub trait Writable{fn write(&self,writer:&mut Writer);}impl Writable for&str{fn write(&self,writer:&mut Writer){for chunk in self.as_bytes().chunks(Writer::BUF_SIZE){writer.write_bytes(chunk);}}}impl Writable for String{fn write(&self,writer:&mut Writer){for chunk in self.as_bytes().chunks(Writer::BUF_SIZE){writer.write_bytes(chunk);}}}impl<T:Writable>Writable for Vec<T>{fn write(&self,writer:&mut Writer){for(i,value)in self.iter().enumerate(){if i!=0{writer.write_char(' ');}writer.write(value);}}}macro_rules!write_unsigned{($t:ty)=>{impl Writable for$t{fn write(&self,writer:&mut Writer){if self==&0{writer.write_char('0');return;}let mut buf=[0;<$t as Integer>::BASE_10_LEN];let mut index=buf.len();let mut value=*self;while value!=0{index-=1;buf[index]=(value%10)as u8+b'0';value/=10;}writer.write_bytes(&buf[index..]);}}};}macro_rules!write_signed{($t:ty)=>{impl Writable for$t{fn write(&self,writer:&mut Writer){if self<&0{writer.write_char('-');}writer.write(&self.unsigned_abs());}}};}write_signed!(i8);write_signed!(i16);write_signed!(i32);write_signed!(i64);write_signed!(i128);write_signed!(isize);write_unsigned!(u8);write_unsigned!(u16);write_unsigned!(u32);write_unsigned!(u64);write_unsigned!(u128);write_unsigned!(usize);macro_rules!write_tuple{($t1:ident,$($t:ident),*)=>{impl<$t1:Writable,$($t:Writable,)*>Writable for($t1,$($t,)*){fn write(&self,writer:&mut Writer){#[allow(non_snake_case)]let($t1,$($t,)*)=self;writer.write($t1);$(writer.write_char(' ');writer.write($t);)*}}}}write_tuple!(A,B);write_tuple!(A,B,C);write_tuple!(A,B,C,D);write_tuple!(A,B,C,D,E);write_tuple!(A,B,C,D,E,F);write_tuple!(A,B,C,D,E,F,G);write_tuple!(A,B,C,D,E,F,G,H);}pub use output_macro::make_output_macro;pub use reader::{Readable,Reader};pub use writer::{Writable,Writer};#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_make_io{($reader:ident,$writer:ident)=>{#[allow(unused_variables)]let mut$reader=rlib_io::reader::Reader::new(Box::new(std::io::stdin().lock()));#[allow(unused_variables)]let mut$writer=rlib_io::writer::Writer::new(Box::new(std::io::stdout().lock()));rlib_io::output_macro::make_output_macro!($writer);};}macro_rules!make_io{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_make_io!{$($tt)*})}}
        pub mod rlib_tensor {use crate::__cargo_equip::preludes::rlib_tensor::*;use std::ops::{Index,IndexMut};use rlib_io::{Readable,Reader,Writable,Writer};#[derive(Clone)]pub struct Tensor<T,const D:usize>{dims:[usize;D],data:Vec<T>,}impl<T,const D:usize>Tensor<T,D>{pub fn from_vec(dims:[usize;D],data:Vec<T>)->Self{assert!(!dims.contains(&0));assert_eq!(dims.iter().product::<usize>(),data.len());Self{dims,data}}pub fn get_index(&self,idx:[usize;D])->usize{let mut result=0;let mut sz=1;for i in(0..D).rev(){assert!(idx[i]<self.dims[i]);result+=sz*idx[i];sz*=self.dims[i];}result}pub fn dims(&self)->&[usize;D]{&self.dims}pub fn dim(&self,i:usize)->usize{self.dims[i]}pub fn iter(&self)->std::slice::Iter<'_,T>{self.data.iter()}pub fn into_iter(self)->std::vec::IntoIter<T>{self.data.into_iter()}pub fn iter_mut(&mut self)->std::slice::IterMut<'_,T>{self.data.iter_mut()}}impl<T:Clone,const D:usize>Tensor<T,D>{pub fn new(dims:[usize;D],value:T)->Self{assert!(!dims.contains(&0));Self{dims,data:vec![value;dims.iter().product()],}}pub fn from_slice(dims:[usize;D],data:&[T])->Self{assert!(!dims.contains(&0));assert_eq!(dims.iter().product::<usize>(),data.len());Self{dims,data:data.iter().cloned().collect(),}}}impl<T,const D:usize>Index<[usize;D]>for Tensor<T,D>{type Output=T;fn index(&self,idx:[usize;D])->&Self::Output{&self.data[self.get_index(idx)]}}impl<T,const D:usize>IndexMut<[usize;D]>for Tensor<T,D>{fn index_mut(&mut self,idx:[usize;D])->&mut Self::Output{let idx=self.get_index(idx);&mut self.data[idx]}}impl<T:PartialEq,const D:usize>PartialEq for Tensor<T,D>{fn eq(&self,other:&Self)->bool{self.data==other.data}}impl<T:Readable,const D:usize>Tensor<T,D>{pub fn read(dims:[usize;D],reader:&mut Reader)->Self{assert!(!dims.contains(&0));Self{dims,data:reader.read_vec(dims.iter().product()),}}}impl<T:Writable,const D:usize>Writable for Tensor<T,D>{fn write(&self,writer:&mut Writer){let mut idx=[0;D];loop{writer.write(&self[idx]);if let Some(pos)=idx.iter().zip(self.dims.iter()).rposition(|(i1,i2)|i1+1!=*i2){if pos+1==D{writer.write_char(' ');}else{for _ in 0..(D-pos-1){writer.write_char('\n');}}idx[pos]+=1;for i in pos+1..D{idx[i]=0;}}else{break;}}}}impl<T:std::fmt::Debug,const D:usize>std::fmt::Debug for Tensor<T,D>{fn fmt(&self,f:&mut std::fmt::Formatter<'_>)->std::fmt::Result{let mut idx=[0;D];write!(f,"{}",(0..D).map(|_|'[').collect::<String>())?;loop{write!(f,"{:?}",self[idx])?;if let Some(pos)=idx.iter().zip(self.dims.iter()).rposition(|(i1,i2)|i1+1!=*i2){if pos+1==D{write!(f,", ")?;}else{for _ in 0..(D-pos-1){write!(f,"]")?;}write!(f,", ")?;for _ in 0..(D-pos-1){write!(f,"[")?;}}idx[pos]+=1;for i in pos+1..D{idx[i]=0;}}else{break;}}write!(f,"{}",(0..D).map(|_|']').collect::<String>())?;Ok(())}}}
    }

    pub(crate) mod macros {
        pub mod rlib_integer {}
        pub mod rlib_io {pub use crate::{__cargo_equip_macro_def_rlib_io_make_io as make_io,__cargo_equip_macro_def_rlib_io_make_output_macro_ as make_output_macro_,__cargo_equip_macro_def_rlib_io_out_impl as out_impl};}
        pub mod rlib_tensor {}
    }

    pub(crate) mod prelude {pub use crate::__cargo_equip::crates::*;}

    mod preludes {
        pub mod rlib_integer {}
        pub mod rlib_io {pub(in crate::__cargo_equip)use crate::__cargo_equip::crates::rlib_integer;}
        pub mod rlib_tensor {pub(in crate::__cargo_equip)use crate::__cargo_equip::crates::rlib_io;}
    }
}