/*
    author:  Maksim1744
    created: 11.10.2022 20:06:48
*/

pub use __cargo_equip::prelude::*;

use rlib_io::*;
use rlib_treap::*;

#[derive(Debug)]
struct Item {
    x: i64,
    sz: usize,
    md: i64,
}

impl Item {
    fn new(x: i64) -> Self {
        Item { x, sz: 1, md: 0 }
    }

    fn modify(&mut self, md: i64) {
        self.x += md;
        self.md += md;
    }
}

impl TreapItem for Item {
    fn update(&mut self, left: Option<&Self>, right: Option<&Self>) {
        self.sz = left.map(|i| i.sz).unwrap_or(0) + right.map(|i| i.sz).unwrap_or(0) + 1;
    }
    fn push(&mut self, left: Option<&mut Self>, right: Option<&mut Self>) {
        if let Some(left) = left {
            left.modify(self.md);
        }
        if let Some(right) = right {
            right.modify(self.md);
        }
        self.md = 0;
    }
}

impl TreapItemSized for Item {
    fn size(&self) -> usize {
        self.sz
    }
}

fn get_kth_log(node: &mut Option<Box<TreapNode<Item>>>, a: &[i64], k: usize) -> i64 {
    if node.is_none() {
        return a[k];
    }
    node.as_mut().unwrap().push();
    let x = node.as_ref().unwrap().item.x;
    let left_size = node.as_ref().unwrap().left.as_ref().map(|i| i.item.sz).unwrap_or(0);
    if k < left_size {
        get_kth_log(&mut node.as_mut().unwrap().left, a, k)
    } else if k == left_size {
        if *a.get(0).unwrap_or(&i64::MAX) >= x {
            x
        } else {
            get_kth_log(&mut node.as_mut().unwrap().left, a, k)
        }
    } else {
        let ia = k - left_size;
        let next_a = *a.get(ia).unwrap_or(&i64::MAX);
        if next_a < x {
            get_kth_log(&mut node.as_mut().unwrap().left, a, k)
        } else if next_a == x || *a.get(ia - 1).unwrap_or(&i64::MAX) <= x {
            x
        } else {
            get_kth_log(&mut node.as_mut().unwrap().right, a, k - left_size - 1)
        }
    }
}

fn solve(cin: &mut Reader, cout: &mut Writer, _test: usize) {
    make_output_macro!(cout);

    let (n, d, q): (usize, i64, usize) = cin.read();
    let a: Vec<i64> = cin.read_vec(n);
    let s = cin.read::<String>();
    let si = s.chars().map(|c| c as i64 - '0' as i64).map(|i| 1 - i).scan(0i64, |sum, x| {
        *sum += x;
        Some(*sum - x)
    });
    let a = std::iter::zip(a, si).map(|(a, b)| a - b).collect::<Vec<i64>>();

    let (zeros, ones): (Vec<_>, Vec<_>) = std::iter::zip(a, s.chars()).partition(|&(_, c)| c == '0');
    let zeros = zeros.into_iter().map(|(x, _)| x).collect::<Vec<i64>>();
    let ones = ones.into_iter().map(|(x, _)| x).collect::<Vec<i64>>();

    assert!(ones.len() >= 1);

    let mut left: Treap<Item> = Treap::from_item(Item::new(ones[0]));
    let mut right: Treap<Item> = ones[1..]
        .iter()
        .fold(Treap::new(), |t, &x| Treap::merge(t, Treap::from_item(Item::new(x))));

    let mut queries = (0..q).map(|i| (cin.read::<i64>(), cin.read::<usize>() - 1, i)).collect::<Vec<_>>();
    queries.sort();

    let mut ans = vec![-1; q];

    let mut cur_time = 0i64;

    let scroll = |mut t: Treap<Item>, steps: i64| -> Treap<Item> {
        assert!(steps >= 0);
        let sz = t.size() as i64;
        let jump = d + sz - 1;
        t.root_mut().unwrap().modify((steps / sz) * jump);
        let (mut l, r) = t.split_at((steps % sz) as usize);
        if let Some(l) = l.root_mut() {
            l.modify(jump);
        }
        Treap::merge(r, l)
    };

    for (tm, pos, ind) in queries {
        while let Some(xnext) = right.first().map(|i| i.x) {
            let jump = d + left.size() as i64 - 1;
            let x0: i64 = left.first().unwrap().x;
            let xrem = (xnext - x0) % jump;
            #[allow(non_snake_case)]
            let (L, R) = left.split_by(|it| (it.x - x0) % jump < xrem);
            let mut time_left = 0i64;
            if let Some(it) = L.root() {
                time_left += (xnext - it.x - 1) / jump * L.size() as i64;
            }
            if let Some(it) = R.root() {
                time_left += (xnext - it.x - 1) / jump * R.size() as i64;
            }
            left = Treap::merge(L, R);
            if cur_time + time_left <= tm {
                left = scroll(left, time_left);
                cur_time += time_left;
                let (r1, r2) = right.split_at(1);
                left = Treap::merge(left, r1);
                right = r2;
            } else {
                break;
            }
        }
        left = scroll(left, tm - cur_time);
        cur_time = tm;

        let sz = left.size();
        let mut ones = Treap::merge(left, right);

        let x = get_kth_log(&mut ones.root, &zeros[..], pos);
        let (o1, o2) = Treap::split_by(ones, |it| it.x < x);
        ans[ind] = x + pos as i64 - o1.size() as i64;

        (left, right) = Treap::split_at(Treap::merge(o1, o2), sz);
    }

    for x in ans {
        outln!(x);
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
///  - `rlib_rand 0.1.0 (path+)`       published in https://github.com/maksim1744/rlib licensed under `MIT` as `crate::__cargo_equip::crates::rlib_rand`
///  - `rlib_treap 0.1.0 (path+)`     published in https://github.com/maksim1744/rlib licensed under `MIT` as `crate::__cargo_equip::crates::rlib_treap`
#[cfg_attr(any(), rustfmt::skip)]
#[allow(unused)]
mod __cargo_equip {
    pub(crate) mod crates {
        pub mod rlib_integer {pub trait Integer{type Unsigned;type Signed;const BASE_10_LEN:usize;const ZERO:Self;const ONE:Self;const TWO:Self;fn unsigned_abs(self)->Self::Unsigned;}macro_rules!integer_common{($it:ty,$ut:ty,$len:expr)=>{type Unsigned=$ut;type Signed=$it;const BASE_10_LEN:usize=$len;const ZERO:Self=0;const ONE:Self=1;const TWO:Self=2;};}macro_rules!base_10_len{($ut:ty)=>{{let mut value=<$ut>::MAX;let mut ans:usize=0;while value!=0{value/=10;ans+=1;}ans}};}macro_rules!integer{($it:ty,$ut:ty,$len:expr)=>{impl Integer for$it{integer_common!($it,$ut,$len);fn unsigned_abs(self)->Self::Unsigned{Self::unsigned_abs(self)}}impl Integer for$ut{integer_common!($it,$ut,$len);fn unsigned_abs(self)->Self::Unsigned{self}}};($it:ty,$ut:ty)=>{integer!($it,$ut,base_10_len!($ut));};}integer!(i8,u8);integer!(i16,u16);integer!(i32,u32);integer!(i64,u64);integer!(i128,u128);integer!(isize,usize);}
        pub mod rlib_io {use crate::__cargo_equip::preludes::rlib_io::*;pub use crate::__cargo_equip::macros::rlib_io::*;pub mod output_macro{use crate::__cargo_equip::preludes::rlib_io::*;#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_out_impl{($writer:ident,$x:expr)=>{$writer.write(&$x);};($writer:ident,$x:expr,$($xx:tt)*)=>{$writer.write(&$x);$writer.write_char(' ');rlib_io::out_impl!($writer,$($xx)*);};}macro_rules!out_impl{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_out_impl!{$($tt)*})}#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_make_output_macro_{($writer:ident)=>{make_output_macro_!($writer,$);};($writer:ident,$dol:tt)=>{#[allow(unused_macros)]macro_rules!out{($dol($dol x:tt)*)=>{rlib_io::out_impl!($writer,$dol($dol x)*);};}#[allow(unused_macros)]macro_rules!outln{($dol($dol x:tt)*)=>{rlib_io::out_impl!($writer,$dol($dol x)*);$writer.write_char('\n');};}}}macro_rules!make_output_macro_{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_make_output_macro_!{$($tt)*})}pub use crate::__cargo_equip::crates::rlib_io::make_output_macro_ as make_output_macro;}pub mod reader{use crate::__cargo_equip::preludes::rlib_io::*;use std::io::Read;pub struct Reader{buf:[u8;Reader::BUF_SIZE],begin:usize,end:usize,stdin:Box<dyn Read>,eof:bool,}impl Reader{const BUF_SIZE:usize=1<<16;pub fn new(stdin:Box<dyn Read>)->Self{Self{buf:[0;Reader::BUF_SIZE],begin:0,end:0,stdin,eof:false,}}pub fn read<T:Readable>(&mut self)->T{T::read(self)}pub fn read_vec<T:Readable>(&mut self,n:usize)->Vec<T>{let mut result=Vec::<T>::with_capacity(n);for _ in 0..n{result.push(self.read());}result}fn refill(&mut self){if self.eof{return;}if self.begin!=0{self.buf.copy_within(self.begin..self.end,0);self.end-=self.begin;self.begin=0;}let bytes=self.stdin.read(&mut self.buf[self.end..]).unwrap();if bytes==0{self.eof=true;}self.end+=bytes;}fn skip_whitespace(&mut self){while{if self.begin==self.end{self.refill();}!self.eof&&self.peek().is_ascii_whitespace()}{self.begin+=1;if self.begin==self.end{self.refill();}}}fn peek(&mut self)->u8{if self.begin==self.end{self.refill();}self.buf[self.begin]}}pub trait Readable{fn read(reader:&mut Reader)->Self;}impl Readable for String{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result=String::new();let mut read_something=false;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{result.push(reader.peek()as char);reader.begin+=1;read_something=true;}debug_assert!(read_something);result}}macro_rules!read_signed{($t:ty)=>{impl Readable for$t{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result:$t=0;let mut read_something=false;if reader.peek()==b'-'{reader.begin+=1;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10-(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}}else{while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10+(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}}debug_assert!(read_something);result}}};}macro_rules!read_unsigned{($t:ty)=>{impl Readable for$t{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result:$t=0;let mut read_something=false;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10+(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}debug_assert!(read_something);result}}};}read_signed!(i8);read_signed!(i16);read_signed!(i32);read_signed!(i64);read_signed!(i128);read_signed!(isize);read_unsigned!(u8);read_unsigned!(u16);read_unsigned!(u32);read_unsigned!(u64);read_unsigned!(u128);read_unsigned!(usize);macro_rules!read_tuple{($($t:ident),*)=>{impl<$($t:Readable,)*>Readable for($($t,)*){fn read(reader:&mut Reader)->Self{($($t::read(reader)),*)}}}}read_tuple!(A,B);read_tuple!(A,B,C);read_tuple!(A,B,C,D);read_tuple!(A,B,C,D,E);read_tuple!(A,B,C,D,E,F);read_tuple!(A,B,C,D,E,F,G);read_tuple!(A,B,C,D,E,F,G,H);}pub mod writer{use crate::__cargo_equip::preludes::rlib_io::*;use std::io::Write;use rlib_integer::Integer;pub struct Writer<'a>{buf:[u8;Writer::BUF_SIZE],end:usize,stdout:Box<dyn Write+'a>,}impl<'a>Writer<'a>{const BUF_SIZE:usize=1<<16;pub fn new(stdout:Box<dyn Write+'a>)->Self{Self{buf:[0;Writer::BUF_SIZE],end:0,stdout,}}pub fn write<T:Writable>(&mut self,t:&T){t.write(self);#[cfg(debug_assertions)]self.flush();}pub fn write_char(&mut self,c:char){self.write_bytes(&[c as u8]);#[cfg(debug_assertions)]self.flush();}fn flush(&mut self){if self.end==0{return;}self.stdout.write_all(&self.buf[..self.end]).unwrap();self.end=0;}fn reserve(&mut self,size:usize){if self.end+size>self.buf.len(){self.flush();}}fn write_bytes(&mut self,buf:&[u8]){self.reserve(buf.len());self.buf[self.end..self.end+buf.len()].copy_from_slice(buf);self.end+=buf.len();}}impl Drop for Writer<'_>{fn drop(&mut self){self.flush();}}pub trait Writable{fn write(&self,writer:&mut Writer);}impl Writable for&str{fn write(&self,writer:&mut Writer){for chunk in self.as_bytes().chunks(Writer::BUF_SIZE){writer.write_bytes(chunk);}}}impl Writable for String{fn write(&self,writer:&mut Writer){for chunk in self.as_bytes().chunks(Writer::BUF_SIZE){writer.write_bytes(chunk);}}}impl<T:Writable>Writable for Vec<T>{fn write(&self,writer:&mut Writer){for(i,value)in self.iter().enumerate(){if i!=0{writer.write_char(' ');}writer.write(value);}}}macro_rules!write_unsigned{($t:ty)=>{impl Writable for$t{fn write(&self,writer:&mut Writer){if self==&0{writer.write_char('0');return;}let mut buf=[0;<$t as Integer>::BASE_10_LEN];let mut index=buf.len();let mut value=*self;while value!=0{index-=1;buf[index]=(value%10)as u8+b'0';value/=10;}writer.write_bytes(&buf[index..]);}}};}macro_rules!write_signed{($t:ty)=>{impl Writable for$t{fn write(&self,writer:&mut Writer){if self<&0{writer.write_char('-');}writer.write(&self.unsigned_abs());}}};}write_signed!(i8);write_signed!(i16);write_signed!(i32);write_signed!(i64);write_signed!(i128);write_signed!(isize);write_unsigned!(u8);write_unsigned!(u16);write_unsigned!(u32);write_unsigned!(u64);write_unsigned!(u128);write_unsigned!(usize);macro_rules!write_tuple{($t1:ident,$($t:ident),*)=>{impl<$t1:Writable,$($t:Writable,)*>Writable for($t1,$($t,)*){fn write(&self,writer:&mut Writer){#[allow(non_snake_case)]let($t1,$($t,)*)=self;writer.write($t1);$(writer.write_char(' ');writer.write($t);)*}}}}write_tuple!(A,B);write_tuple!(A,B,C);write_tuple!(A,B,C,D);write_tuple!(A,B,C,D,E);write_tuple!(A,B,C,D,E,F);write_tuple!(A,B,C,D,E,F,G);write_tuple!(A,B,C,D,E,F,G,H);}pub use output_macro::make_output_macro;pub use reader::{Readable,Reader};pub use writer::{Writable,Writer};#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_make_io{($reader:ident,$writer:ident)=>{#[allow(unused_variables)]let mut$reader=rlib_io::reader::Reader::new(Box::new(std::io::stdin().lock()));#[allow(unused_variables)]let mut$writer=rlib_io::writer::Writer::new(Box::new(std::io::stdout().lock()));rlib_io::output_macro::make_output_macro!($writer);};}macro_rules!make_io{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_make_io!{$($tt)*})}}
        pub mod rlib_rand {pub mod lcg{use std::time::SystemTime;use crate::__cargo_equip::crates::rlib_rand::randomable::*;#[derive(Copy,Clone)]pub struct LinearCongruentialGenerator64<const A:u64,const C:u64>{state:u64,}impl<const A:u64,const C:u64>LinearCongruentialGenerator64<A,C>{pub const fn from_seed(seed:u64)->Self{Self{state:seed}}pub fn from_time()->Self{Self{state:SystemTime::now().duration_since(SystemTime::UNIX_EPOCH).unwrap().as_nanos()as u64,}}pub fn next_raw(&mut self)->u64{self.state=self.state.wrapping_mul(A).wrapping_add(C);self.state}pub fn next<T,R>(&mut self,range:R)->T where R:Randomable<T>,{range.gen_from_u64(self.next_raw())}}}pub mod randomable{use std::ops::*;pub trait Randomable<T:Sized>{fn gen_from_u64(self,rng:u64)->T;}macro_rules!implement_ranges{($t:ty)=>{impl Randomable<$t>for RangeTo<$t>{fn gen_from_u64(self,rng:u64)->$t{(0..self.end).gen_from_u64(rng)}}impl Randomable<$t>for RangeInclusive<$t>{fn gen_from_u64(self,rng:u64)->$t{if*self.start()!=<$t>::MIN{(*self.start()-1..*self.end()).gen_from_u64(rng)+1}else if*self.end()!=<$t>::MAX{(*self.start()..*self.end()+1).gen_from_u64(rng)}else{rng as$t}}}impl Randomable<$t>for RangeToInclusive<$t>{fn gen_from_u64(self,rng:u64)->$t{(0..=self.end).gen_from_u64(rng)}}};}macro_rules!make_randomable{($it:ty,$ut:ty)=>{impl Randomable<$it>for Range<$it>{fn gen_from_u64(self,rng:u64)->$it{assert!(!self.is_empty());let len=(self.end as$ut).wrapping_sub(self.start as$ut);((rng%len as u64)as$ut).wrapping_add(self.start as$ut)as$it}}impl Randomable<$ut>for Range<$ut>{fn gen_from_u64(self,rng:u64)->$ut{assert!(!self.is_empty());let len=self.end-self.start;(rng%len as u64)as$ut+self.start}}implement_ranges!($it);implement_ranges!($ut);};}make_randomable!(i8,u8);make_randomable!(i16,u16);make_randomable!(i32,u32);make_randomable!(i64,u64);make_randomable!(isize,usize);impl Randomable<f64>for Range<f64>{fn gen_from_u64(self,rng:u64)->f64{assert!(!self.is_empty());let len=self.end-self.start;(rng as f64/u64::MAX as f64)*len+self.start}}}pub type Rng=lcg::LinearCongruentialGenerator64<6364136223846793005,1442695040888963407>;}
        pub mod rlib_treap {use crate::__cargo_equip::preludes::rlib_treap::*;mod print{use crate::__cargo_equip::preludes::rlib_treap::*;use std::fmt;use crate::__cargo_equip::crates::rlib_treap::treap::Treap;use crate::__cargo_equip::crates::rlib_treap::treap_node::{TreapItem,TreapNode};}mod treap{use crate::__cargo_equip::preludes::rlib_treap::*;use crate::__cargo_equip::crates::rlib_treap::treap_node::{TreapItem,TreapItemSized,TreapNode};pub struct Treap<T>{pub root:Option<Box<TreapNode<T>>>,}impl<T>Treap<T>where T:TreapItem+TreapItemSized,{pub fn new()->Self{Self{root:None}}pub fn from_item(item:T)->Self{Self{root:Some(Box::new(TreapNode::new(item))),}}pub fn is_empty(&self)->bool{self.root.is_none()}pub fn merge(left:Self,right:Self)->Self{Self{root:TreapNode::merge(left.root,right.root),}}pub fn split_by<P>(self,pred:P)->(Self,Self)where P:FnMut(&T)->bool,{let(left,right)=TreapNode::split_by(self.root,pred);(Treap{root:left},Treap{root:right})}pub fn first(&mut self)->Option<&T>{if self.root.is_none(){return None;}let mut node=self.root.as_mut().unwrap();while node.left.is_some(){node.push();node=node.left.as_mut().unwrap();}Some(&node.item)}pub fn last(&mut self)->Option<&T>{if self.root.is_none(){return None;}let mut node=self.root.as_mut().unwrap();while node.right.is_some(){node.push();node=node.right.as_mut().unwrap();}Some(&node.item)}pub fn root(&self)->Option<&T>{self.root.as_ref().map(|i|&i.item)}pub fn root_mut(&mut self)->Option<&mut T>{self.root.as_mut().map(|i|&mut i.item)}pub fn collect(&mut self)->Vec<&T>{match&mut self.root{Some(root)=>{let mut v=Vec::new();root.collect_into(&mut v);v}None=>Vec::new(),}}}impl<T>Treap<T>where T:TreapItem+TreapItemSized,{pub fn split_at(self,pos:usize)->(Self,Self){let(left,right)=TreapNode::split_at(self.root,pos);(Treap{root:left},Treap{root:right})}pub fn insert_at(&mut self,pos:usize,item:T){let(left,right)=TreapNode::split_at(self.root.take(),pos);self.root=TreapNode::merge(TreapNode::merge(left,Some(Box::new(TreapNode::new(item)))),right);}pub fn remove_at(&mut self,pos:usize)->T{let(t1,t23)=TreapNode::split_at(self.root.take(),pos);let(t2,t3)=TreapNode::split_at(t23,1);self.root=TreapNode::merge(t1,t3);t2.unwrap().item}pub fn size(&self)->usize{self.root().map(|i|i.size()).unwrap_or(0)}}}mod treap_node{use crate::__cargo_equip::preludes::rlib_treap::*;use rlib_rand::Rng;pub trait TreapItem{fn update(&mut self,_left:Option<&Self>,_right:Option<&Self>){}fn push(&mut self,_left:Option<&mut Self>,_right:Option<&mut Self>){}}pub trait TreapItemSized{fn size(&self)->usize;}static mut RNG:Rng=Rng::from_seed(42);type Priority=u64;fn gen_priority()->Priority{unsafe{RNG.next_raw()as Priority}}fn with_probability(a:usize,b:usize)->bool{unsafe{RNG.next(0..a+b)<a}}pub struct TreapNode<T>{pub item:T,pub left:Option<Box<TreapNode<T>>>,pub right:Option<Box<TreapNode<T>>>,}impl<T>TreapNode<T>{pub fn new(item:T)->Self{Self{item,left:None,right:None,}}}impl<T>TreapNode<T>where T:TreapItem+TreapItemSized,{pub fn update(&mut self){self.item.update(self.left.as_ref().map(|x|&x.item),self.right.as_ref().map(|x|&x.item),);}pub fn merge(mut left:Option<Box<Self>>,mut right:Option<Box<Self>>)->Option<Box<Self>>{if left.is_none(){right}else if right.is_none(){left}else{if with_probability(left.as_ref().unwrap().item.size(),right.as_ref().unwrap().item.size()){left.as_mut().unwrap().push();let m=left.as_mut().unwrap().right.take();left.as_mut().unwrap().right=Self::merge(m,right);left.as_mut().unwrap().update();left}else{right.as_mut().unwrap().push();let m=right.as_mut().unwrap().left.take();right.as_mut().unwrap().left=Self::merge(left,m);right.as_mut().unwrap().update();right}}}pub fn split_by<P>(mut root:Option<Box<Self>>,mut pred:P)->(Option<Box<Self>>,Option<Box<Self>>)where P:FnMut(&T)->bool,{if root.is_none(){return(None,None);}root.as_mut().unwrap().push();if pred(&root.as_ref().unwrap().item){let(a,b)=Self::split_by(root.as_mut().unwrap().right.take(),pred);root.as_mut().unwrap().right=a;root.as_mut().unwrap().update();(root,b)}else{let(a,b)=Self::split_by(root.as_mut().unwrap().left.take(),pred);root.as_mut().unwrap().left=b;root.as_mut().unwrap().update();(a,root)}}pub fn push(&mut self){self.item.push(self.left.as_mut().map(|i|&mut i.item),self.right.as_mut().map(|i|&mut i.item),);}pub fn collect_into<'a>(&'a mut self,res:&mut Vec<&'a T>){self.push();if let Some(left)=&mut self.left{left.collect_into(res);}res.push(&self.item);if let Some(right)=&mut self.right{right.collect_into(res);}}}impl<T>TreapNode<T>where T:TreapItem+TreapItemSized,{pub fn split_at(mut root:Option<Box<Self>>,pos:usize)->(Option<Box<Self>>,Option<Box<Self>>){if root.is_none(){return(None,None);}root.as_mut().unwrap().push();if pos>=root.as_ref().unwrap().left.as_ref().map(|i|i.item.size()).unwrap_or(0)+1{let(a,b)=Self::split_at(root.as_mut().unwrap().right.take(),pos-root.as_ref().unwrap().left.as_ref().map(|i|i.item.size()).unwrap_or(0)-1,);root.as_mut().unwrap().right=a;root.as_mut().unwrap().update();(root,b)}else{let(a,b)=Self::split_at(root.as_mut().unwrap().left.take(),pos);root.as_mut().unwrap().left=b;root.as_mut().unwrap().update();(a,root)}}}}pub use treap::Treap;pub use treap_node::{TreapItem,TreapItemSized,TreapNode};}
    }

    pub(crate) mod macros {
        pub mod rlib_integer {}
        pub mod rlib_io {pub use crate::{__cargo_equip_macro_def_rlib_io_make_io as make_io,__cargo_equip_macro_def_rlib_io_make_output_macro_ as make_output_macro_,__cargo_equip_macro_def_rlib_io_out_impl as out_impl};}
        pub mod rlib_rand {}
        pub mod rlib_treap {}
    }

    pub(crate) mod prelude {pub use crate::__cargo_equip::crates::*;}

    mod preludes {
        pub mod rlib_integer {}
        pub mod rlib_io {pub(in crate::__cargo_equip)use crate::__cargo_equip::crates::rlib_integer;}
        pub mod rlib_rand {}
        pub mod rlib_treap {pub(in crate::__cargo_equip)use crate::__cargo_equip::crates::rlib_rand;}
    }
}