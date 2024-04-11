/*
    author:  Maksim1744
    created: 08.10.2022 16:40:55
*/

pub use __cargo_equip::prelude::*;

use rlib_io::*;
use std::collections::{BTreeSet, BinaryHeap};

fn solve(cin: &mut Reader, cout: &mut Writer, _test: usize) {
    make_output_macro!(cout);

    let (n, q): (usize, usize) = cin.read();
    let p = cin.read_vec::<i32>(n);
    let a = cin
        .read_vec::<i32>(n)
        .into_iter()
        .map(|i| if i == 0 { None } else { Some(i) })
        .collect::<Vec<_>>();
    let k = a.iter().filter(|x| x.is_none()).count() - 1;
    let mut s = cin.read_vec::<i32>(k);
    s.sort();
    let d = cin.read_vec::<i32>(q);
    // if _test != 2 {
    //     return;
    // }

    let mut lgt: Vec<Option<usize>> = vec![None; n];
    let mut rgt: Vec<Option<usize>> = vec![None; n];

    {
        let mut s: Vec<usize> = Vec::new();
        for i in 0..n {
            while !s.is_empty() && p[*s.last().unwrap()] < p[i] {
                s.pop();
            }
            lgt[i] = s.last().cloned();
            s.push(i);
        }
    }
    {
        let mut s: Vec<usize> = Vec::new();
        for i in (0..n).rev() {
            while !s.is_empty() && p[*s.last().unwrap()] < p[i] {
                s.pop();
            }
            rgt[i] = s.last().cloned();
            s.push(i);
        }
    }

    let mut ord = (0..n).collect::<Vec<usize>>();
    ord.sort_by_key(|&i| p[i]);

    let mut l = vec![i32::MIN; n];
    let mut r = vec![i32::MAX; n];

    for &i in ord.iter() {
        if let Some(x) = a[i] {
            l[i] = l[i].max(x);
            r[i] = r[i].min(x);
        }
        if let Some(x) = lgt[i] {
            l[x] = l[x].max(l[i] + 1);
        }
        if let Some(x) = rgt[i] {
            l[x] = l[x].max(l[i] + 1);
        }
    }

    for &i in ord.iter().rev() {
        if let Some(x) = lgt[i] {
            r[i] = r[i].min(r[x] - 1);
        }
        if let Some(x) = rgt[i] {
            r[i] = r[i].min(r[x] - 1);
        }
    }

    for (l, r) in std::iter::zip(l.iter(), r.iter()) {
        if l > r {
            for _ in 0..q {
                outln!("NO");
            }
            return;
        }
    }
    // eprintln!("lgt = {:?}", lgt);
    // eprintln!("rgt = {:?}", rgt);
    // eprintln!("l = {:?}", l);
    // eprintln!("r = {:?}", r);

    let segs = (0..n).filter(|&i| a[i].is_none()).map(|i| (l[i], r[i])).collect::<Vec<_>>();
    // eprintln!("segs = {:?}", segs);

    let mut byl = segs.iter().cloned().enumerate().map(|(i, (l, _))| (l, i)).collect::<BTreeSet<_>>();
    let mut byr = segs.iter().cloned().enumerate().map(|(i, (_, r))| (r, i)).collect::<BTreeSet<_>>();

    let mut allowed_segments = Vec::new();

    fn calc(
        l: isize,
        r: isize,
        byl: &mut BTreeSet<(i32, usize)>,
        byr: &mut BTreeSet<(i32, usize)>,
        segs: &Vec<(i32, i32)>,
        s: &Vec<i32>,
        allowed_segments: &mut Vec<(i32, i32)>,
    ) {
        // eprintln!("l, r = {} {}", l, r);
        // eprintln!("byl = {:?}", byl);
        // eprintln!("byr = {:?}", byr);
        assert_eq!(byl.len() as isize, r - l + 2);
        assert_eq!(byr.len() as isize, r - l + 2);
        if l > r {
            let ind = byl.iter().next().unwrap().1;
            allowed_segments.push(segs[ind]);
            return;
        }
        if byl.iter().rev().next().unwrap().0 <= s[l as usize] && byr.iter().next().unwrap().0 >= s[r as usize] {
            allowed_segments.push((byl.iter().next().unwrap().0, byr.iter().rev().next().unwrap().0));
            return;
        }

        let m = (l + r) / 2;
        let mut removed: Vec<usize> = Vec::new();
        {
            let mut byr_local: BinaryHeap<(i32, usize)> = BinaryHeap::new();
            let mut ok = true;
            let mut byl_iter = byl.iter().peekable();
            for i in l..=m {
                while let Some((_, ind)) = byl_iter.next_if(|&(l, _)| l <= &s[i as usize]).cloned() {
                    byr_local.push((-segs[ind].1, ind));
                }
                if let Some((r, ind)) = byr_local.peek().cloned() {
                    if -r >= s[i as usize] {
                        removed.push(ind);
                        byr_local.pop();
                        continue;
                    }
                }
                ok = false;
                break;
            }
            for &ind in removed.iter() {
                assert!(byl.remove(&(segs[ind].0, ind)));
                assert!(byr.remove(&(segs[ind].1, ind)));
            }
            if ok {
                calc(m + 1, r, byl, byr, segs, s, allowed_segments);
            }
            for &ind in removed.iter() {
                byl.insert((segs[ind].0, ind));
                byr.insert((segs[ind].1, ind));
            }
            removed.clear();
        }
        {
            let mut byl_local: BinaryHeap<(i32, usize)> = BinaryHeap::new();
            let mut ok = true;
            let mut byr_iter = byr.iter().rev().peekable();
            for i in (m..=r).rev() {
                while let Some((_r, ind)) = byr_iter.next_if(|&(r, _)| r >= &s[i as usize]).cloned() {
                    byl_local.push((segs[ind].0, ind));
                }
                if let Some((l, ind)) = byl_local.peek().cloned() {
                    if l <= s[i as usize] {
                        removed.push(ind);
                        byl_local.pop();
                        continue;
                    }
                }
                ok = false;
                break;
            }
            for &ind in removed.iter() {
                assert!(byl.remove(&(segs[ind].0, ind)));
                assert!(byr.remove(&(segs[ind].1, ind)));
            }
            if ok {
                calc(l, m - 1, byl, byr, segs, s, allowed_segments);
            }
            for ind in removed.into_iter() {
                byl.insert((segs[ind].0, ind));
                byr.insert((segs[ind].1, ind));
            }
        }
    }

    calc(0, (k - 1) as isize, &mut byl, &mut byr, &segs, &s, &mut allowed_segments);

    // eprintln!("allowed_segments = {:?}", allowed_segments);

    allowed_segments.sort();
    {
        let mut tmp: Vec<(i32, i32)> = Vec::new();
        for &(l, r) in allowed_segments.iter() {
            if let Some(x) = tmp.last_mut() {
                if l <= x.0 {
                    x.1 = x.1.max(r);
                    continue;
                }
            }
            tmp.push((l, r));
        }
        std::mem::swap(&mut tmp, &mut allowed_segments);
    }

    for x in d.into_iter() {
        let ind = allowed_segments.partition_point(|&(_l, r)| r < x);

        if ind < allowed_segments.len() && allowed_segments[ind].0 <= x {
            outln!("YES");
        } else {
            outln!("NO");
        }
    }
}

fn main() {
    make_io!(cin, cout);
    let tests: usize = cin.read();
    for test in 1..=tests {
        solve(&mut cin, &mut cout, test);
    }
}

// The following code was expanded by `cargo-equip`.

///  # Bundled libraries
/// 
///  - `rlib_integer 0.1.0 (path+)` published in https://github.com/maksim1744/rlib licensed under `MIT` as `crate::__cargo_equip::crates::rlib_integer`
///  - `rlib_io 0.1.0 (path+)`           published in https://github.com/maksim1744/rlib licensed under `MIT` as `crate::__cargo_equip::crates::rlib_io`
#[cfg_attr(any(), rustfmt::skip)]
#[allow(unused)]
mod __cargo_equip {
    pub(crate) mod crates {
        pub mod rlib_integer {pub trait Integer{type Unsigned;type Signed;const BASE_10_LEN:usize;const ZERO:Self;const ONE:Self;const TWO:Self;fn unsigned_abs(self)->Self::Unsigned;}macro_rules!integer_common{($it:ty,$ut:ty,$len:expr)=>{type Unsigned=$ut;type Signed=$it;const BASE_10_LEN:usize=$len;const ZERO:Self=0;const ONE:Self=1;const TWO:Self=2;};}macro_rules!base_10_len{($ut:ty)=>{{let mut value=<$ut>::MAX;let mut ans:usize=0;while value!=0{value/=10;ans+=1;}ans}};}macro_rules!integer{($it:ty,$ut:ty,$len:expr)=>{impl Integer for$it{integer_common!($it,$ut,$len);fn unsigned_abs(self)->Self::Unsigned{Self::unsigned_abs(self)}}impl Integer for$ut{integer_common!($it,$ut,$len);fn unsigned_abs(self)->Self::Unsigned{self}}};($it:ty,$ut:ty)=>{integer!($it,$ut,base_10_len!($ut));};}integer!(i8,u8);integer!(i16,u16);integer!(i32,u32);integer!(i64,u64);integer!(i128,u128);integer!(isize,usize);}
        pub mod rlib_io {use crate::__cargo_equip::preludes::rlib_io::*;pub use crate::__cargo_equip::macros::rlib_io::*;pub mod output_macro{use crate::__cargo_equip::preludes::rlib_io::*;#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_out_impl{($writer:ident,$x:expr)=>{$writer.write(&$x);};($writer:ident,$x:expr,$($xx:tt)*)=>{$writer.write(&$x);$writer.write_char(' ');rlib_io::out_impl!($writer,$($xx)*);};}macro_rules!out_impl{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_out_impl!{$($tt)*})}#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_make_output_macro_{($writer:ident)=>{make_output_macro_!($writer,$);};($writer:ident,$dol:tt)=>{#[allow(unused_macros)]macro_rules!out{($dol($dol x:tt)*)=>{rlib_io::out_impl!($writer,$dol($dol x)*);};}#[allow(unused_macros)]macro_rules!outln{($dol($dol x:tt)*)=>{rlib_io::out_impl!($writer,$dol($dol x)*);$writer.write_char('\n');};}}}macro_rules!make_output_macro_{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_make_output_macro_!{$($tt)*})}pub use crate::__cargo_equip::crates::rlib_io::make_output_macro_ as make_output_macro;}pub mod reader{use crate::__cargo_equip::preludes::rlib_io::*;use std::io::Read;pub struct Reader{buf:[u8;Reader::BUF_SIZE],begin:usize,end:usize,stdin:Box<dyn Read>,eof:bool,}impl Reader{const BUF_SIZE:usize=1<<16;pub fn new(stdin:Box<dyn Read>)->Self{Self{buf:[0;Reader::BUF_SIZE],begin:0,end:0,stdin,eof:false,}}pub fn read<T:Readable>(&mut self)->T{T::read(self)}pub fn read_vec<T:Readable>(&mut self,n:usize)->Vec<T>{let mut result=Vec::<T>::with_capacity(n);for _ in 0..n{result.push(self.read());}result}fn refill(&mut self){if self.eof{return;}if self.begin!=0{self.buf.copy_within(self.begin..self.end,0);self.end-=self.begin;self.begin=0;}let bytes=self.stdin.read(&mut self.buf[self.end..]).unwrap();if bytes==0{self.eof=true;}self.end+=bytes;}fn skip_whitespace(&mut self){while{if self.begin==self.end{self.refill();}!self.eof&&self.peek().is_ascii_whitespace()}{self.begin+=1;if self.begin==self.end{self.refill();}}}fn peek(&mut self)->u8{if self.begin==self.end{self.refill();}self.buf[self.begin]}}pub trait Readable{fn read(reader:&mut Reader)->Self;}impl Readable for String{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result=String::new();let mut read_something=false;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{result.push(reader.peek()as char);reader.begin+=1;read_something=true;}debug_assert!(read_something);result}}macro_rules!read_signed{($t:ty)=>{impl Readable for$t{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result:$t=0;let mut read_something=false;if reader.peek()==b'-'{reader.begin+=1;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10-(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}}else{while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10+(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}}debug_assert!(read_something);result}}};}macro_rules!read_unsigned{($t:ty)=>{impl Readable for$t{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result:$t=0;let mut read_something=false;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10+(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}debug_assert!(read_something);result}}};}read_signed!(i8);read_signed!(i16);read_signed!(i32);read_signed!(i64);read_signed!(i128);read_signed!(isize);read_unsigned!(u8);read_unsigned!(u16);read_unsigned!(u32);read_unsigned!(u64);read_unsigned!(u128);read_unsigned!(usize);macro_rules!read_tuple{($($t:ident),*)=>{impl<$($t:Readable,)*>Readable for($($t,)*){fn read(reader:&mut Reader)->Self{($($t::read(reader)),*)}}}}read_tuple!(A,B);read_tuple!(A,B,C);read_tuple!(A,B,C,D);read_tuple!(A,B,C,D,E);read_tuple!(A,B,C,D,E,F);read_tuple!(A,B,C,D,E,F,G);read_tuple!(A,B,C,D,E,F,G,H);}pub mod writer{use crate::__cargo_equip::preludes::rlib_io::*;use std::io::Write;use rlib_integer::Integer;pub struct Writer<'a>{buf:[u8;Writer::BUF_SIZE],end:usize,stdout:Box<dyn Write+'a>,}impl<'a>Writer<'a>{const BUF_SIZE:usize=1<<16;pub fn new(stdout:Box<dyn Write+'a>)->Self{Self{buf:[0;Writer::BUF_SIZE],end:0,stdout,}}pub fn write<T:Writable>(&mut self,t:&T){t.write(self);#[cfg(debug_assertions)]self.flush();}pub fn write_char(&mut self,c:char){self.write_bytes(&[c as u8]);#[cfg(debug_assertions)]self.flush();}fn flush(&mut self){if self.end==0{return;}self.stdout.write_all(&self.buf[..self.end]).unwrap();self.end=0;}fn reserve(&mut self,size:usize){if self.end+size>self.buf.len(){self.flush();}}fn write_bytes(&mut self,buf:&[u8]){self.reserve(buf.len());self.buf[self.end..self.end+buf.len()].copy_from_slice(buf);self.end+=buf.len();}}impl Drop for Writer<'_>{fn drop(&mut self){self.flush();}}pub trait Writable{fn write(&self,writer:&mut Writer);}impl Writable for&str{fn write(&self,writer:&mut Writer){for chunk in self.as_bytes().chunks(Writer::BUF_SIZE){writer.write_bytes(chunk);}}}impl Writable for String{fn write(&self,writer:&mut Writer){for chunk in self.as_bytes().chunks(Writer::BUF_SIZE){writer.write_bytes(chunk);}}}impl<T:Writable>Writable for Vec<T>{fn write(&self,writer:&mut Writer){for(i,value)in self.iter().enumerate(){if i!=0{writer.write_char(' ');}writer.write(value);}}}macro_rules!write_unsigned{($t:ty)=>{impl Writable for$t{fn write(&self,writer:&mut Writer){if self==&0{writer.write_char('0');return;}let mut buf=[0;<$t as Integer>::BASE_10_LEN];let mut index=buf.len();let mut value=*self;while value!=0{index-=1;buf[index]=(value%10)as u8+b'0';value/=10;}writer.write_bytes(&buf[index..]);}}};}macro_rules!write_signed{($t:ty)=>{impl Writable for$t{fn write(&self,writer:&mut Writer){if self<&0{writer.write_char('-');}writer.write(&self.unsigned_abs());}}};}write_signed!(i8);write_signed!(i16);write_signed!(i32);write_signed!(i64);write_signed!(i128);write_signed!(isize);write_unsigned!(u8);write_unsigned!(u16);write_unsigned!(u32);write_unsigned!(u64);write_unsigned!(u128);write_unsigned!(usize);macro_rules!write_tuple{($t1:ident,$($t:ident),*)=>{impl<$t1:Writable,$($t:Writable,)*>Writable for($t1,$($t,)*){fn write(&self,writer:&mut Writer){#[allow(non_snake_case)]let($t1,$($t,)*)=self;writer.write($t1);$(writer.write_char(' ');writer.write($t);)*}}}}write_tuple!(A,B);write_tuple!(A,B,C);write_tuple!(A,B,C,D);write_tuple!(A,B,C,D,E);write_tuple!(A,B,C,D,E,F);write_tuple!(A,B,C,D,E,F,G);write_tuple!(A,B,C,D,E,F,G,H);}pub use output_macro::make_output_macro;pub use reader::{Readable,Reader};pub use writer::{Writable,Writer};#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_make_io{($reader:ident,$writer:ident)=>{#[allow(unused_variables)]let mut$reader=rlib_io::reader::Reader::new(Box::new(std::io::stdin().lock()));#[allow(unused_variables)]let mut$writer=rlib_io::writer::Writer::new(Box::new(std::io::stdout().lock()));rlib_io::output_macro::make_output_macro!($writer);};}macro_rules!make_io{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_make_io!{$($tt)*})}}
    }

    pub(crate) mod macros {
        pub mod rlib_integer {}
        pub mod rlib_io {pub use crate::{__cargo_equip_macro_def_rlib_io_make_io as make_io,__cargo_equip_macro_def_rlib_io_make_output_macro_ as make_output_macro_,__cargo_equip_macro_def_rlib_io_out_impl as out_impl};}
    }

    pub(crate) mod prelude {pub use crate::__cargo_equip::crates::*;}

    mod preludes {
        pub mod rlib_integer {}
        pub mod rlib_io {pub(in crate::__cargo_equip)use crate::__cargo_equip::crates::rlib_integer;}
    }
}