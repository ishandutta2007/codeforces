/*
    author:  Maksim1744
    created: 18.10.2022 15:44:36
*/

pub use __cargo_equip::prelude::*;

use rlib_io::*;
use rlib_segtree::*;

#[derive(Clone, Eq, PartialEq)]
struct Item {
    l: usize,
    r: usize,
}

impl SegtreeItem for Item {
    fn merge(left: &Self, right: &Self) -> Self {
        Self {
            l: left.l.min(right.l),
            r: left.r.max(right.r),
        }
    }
}

const B: usize = 20;

fn solve(cin: &mut Reader, cout: &mut Writer, _test: usize) {
    make_output_macro!(cout);

    let (n, q): (usize, usize) = cin.read();
    let a = cin.read_vec::<usize>(n).into_iter().map(|x| x - 1).collect::<Vec<_>>();

    if n == 1 {
        for _ in 0..q {
            outln!(0);
        }
        return;
    }

    let mut trees = Vec::new();
    trees.push(Segtree::<Item>::from_slice(
        &a.windows(2)
            .map(|ar| Item {
                l: ar[0].min(ar[1]),
                r: ar[0].max(ar[1]),
            })
            .collect::<Vec<_>>(),
    ));

    let mut ones = Vec::new();
    ones.push(a.clone());

    for _ in 1..B {
        let tree = trees.last().unwrap();
        let one = ones.last().unwrap();
        let new_tree = Segtree::<Item>::from_slice(
            &(0..n - 1)
                .map(|i| {
                    let Item { l, r } = tree.ask(i, i);
                    if l == r {
                        Item { l: one[l], r: one[r] }
                    } else {
                        tree.ask(l, r - 1)
                    }
                })
                .collect::<Vec<_>>(),
        );
        let new_ones = one.iter().map(|&x| one[x]).collect();
        trees.push(new_tree);
        ones.push(new_ones);
    }

    let final_item = Item { l: 0, r: n - 1 };

    for _ in 0..q {
        let (mut l, mut r): (usize, usize) = cin.read();
        l -= 1;
        r -= 1;
        if l == r {
            outln!(-1);
            continue;
        }
        if (Item { l, r } == final_item) {
            outln!(0);
            continue;
        }
        if trees.last().unwrap().ask(l, r - 1) != final_item {
            outln!(-1);
            continue;
        }
        let mut ans = 0;
        for b in (0..B).rev() {
            let it = trees[b].ask(l, r - 1);
            if it != final_item {
                ans += 1 << b;
                l = it.l;
                r = it.r;
            }
        }
        outln!(ans + 1);
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
///  - `rlib_rand 0.1.0 (path+)`       published in https://github.com/maksim1744/rlib licensed under `MIT` as `crate::__cargo_equip::crates::__rlib_rand_0_1_0`
///  - `rlib_segtree 0.1.0 (path+)` published in https://github.com/maksim1744/rlib licensed under `MIT` as `crate::__cargo_equip::crates::rlib_segtree`
#[cfg_attr(any(), rustfmt::skip)]
#[allow(unused)]
mod __cargo_equip {
    pub(crate) mod crates {
        pub mod rlib_integer {use std::cmp::*;use std::ops::*;pub trait Integer:Add<Output=Self>+AddAssign+Sub<Output=Self>+SubAssign+Div<Output=Self>+DivAssign+Rem<Output=Self>+RemAssign+Mul<Output=Self>+MulAssign+PartialEq+Copy+Clone+Sized{type Unsigned:Integer;type Signed:Integer;const BASE_10_LEN:usize;const ZERO:Self;const ONE:Self;const TWO:Self;fn unsigned_abs(self)->Self::Unsigned;fn abs(self)->Self;}macro_rules!integer_common{($it:ty,$ut:ty,$len:expr)=>{type Unsigned=$ut;type Signed=$it;const BASE_10_LEN:usize=$len;const ZERO:Self=0;const ONE:Self=1;const TWO:Self=2;};}macro_rules!base_10_len{($ut:ty)=>{{let mut value=<$ut>::MAX;let mut ans:usize=0;while value!=0{value/=10;ans+=1;}ans}};}macro_rules!integer{($it:ty,$ut:ty,$len:expr)=>{impl Integer for$it{integer_common!($it,$ut,$len);fn unsigned_abs(self)->Self::Unsigned{Self::unsigned_abs(self)}fn abs(self)->Self{self.abs()}}impl Integer for$ut{integer_common!($it,$ut,$len);fn unsigned_abs(self)->Self::Unsigned{self}fn abs(self)->Self{self}}};($it:ty,$ut:ty)=>{integer!($it,$ut,base_10_len!($ut));};}integer!(i8,u8);integer!(i16,u16);integer!(i32,u32);integer!(i64,u64);integer!(i128,u128);integer!(isize,usize);}
        pub mod rlib_io {use crate::__cargo_equip::preludes::rlib_io::*;pub use crate::__cargo_equip::macros::rlib_io::*;pub mod output_macro{use crate::__cargo_equip::preludes::rlib_io::*;#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_out_impl{($writer:ident,$x:expr)=>{$writer.write(&$x);};($writer:ident,$x:expr,$($xx:tt)*)=>{$writer.write(&$x);$writer.write_char(' ');rlib_io::out_impl!($writer,$($xx)*);};}macro_rules!out_impl{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_out_impl!{$($tt)*})}#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_make_output_macro_{($writer:ident)=>{make_output_macro_!($writer,$);};($writer:ident,$dol:tt)=>{#[allow(unused_macros)]macro_rules!out{($dol($dol x:tt)*)=>{rlib_io::out_impl!($writer,$dol($dol x)*);};}#[allow(unused_macros)]macro_rules!outln{($dol($dol x:tt)*)=>{rlib_io::out_impl!($writer,$dol($dol x)*);$writer.write_char('\n');};}}}macro_rules!make_output_macro_{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_make_output_macro_!{$($tt)*})}pub use crate::__cargo_equip::crates::rlib_io::make_output_macro_ as make_output_macro;}pub mod reader{use crate::__cargo_equip::preludes::rlib_io::*;use std::io::Read;pub struct Reader{buf:[u8;Reader::BUF_SIZE],begin:usize,end:usize,stdin:Box<dyn Read>,eof:bool,}impl Reader{const BUF_SIZE:usize=1<<16;pub fn new(stdin:Box<dyn Read>)->Self{Self{buf:[0;Reader::BUF_SIZE],begin:0,end:0,stdin,eof:false,}}pub fn read<T:Readable>(&mut self)->T{T::read(self)}pub fn read_vec<T:Readable>(&mut self,n:usize)->Vec<T>{let mut result=Vec::<T>::with_capacity(n);for _ in 0..n{result.push(self.read());}result}fn refill(&mut self){if self.eof{return;}if self.begin!=0{self.buf.copy_within(self.begin..self.end,0);self.end-=self.begin;self.begin=0;}let bytes=self.stdin.read(&mut self.buf[self.end..]).unwrap();if bytes==0{self.eof=true;}self.end+=bytes;}fn skip_whitespace(&mut self){while{if self.begin==self.end{self.refill();}!self.eof&&self.peek().is_ascii_whitespace()}{self.begin+=1;if self.begin==self.end{self.refill();}}}fn peek(&mut self)->u8{if self.begin==self.end{self.refill();}self.buf[self.begin]}}pub trait Readable{fn read(reader:&mut Reader)->Self;}impl Readable for String{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result=String::new();let mut read_something=false;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{result.push(reader.peek()as char);reader.begin+=1;read_something=true;}debug_assert!(read_something);result}}macro_rules!read_signed{($t:ty)=>{impl Readable for$t{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result:$t=0;let mut read_something=false;if reader.peek()==b'-'{reader.begin+=1;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10-(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}}else{while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10+(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}}debug_assert!(read_something);result}}};}macro_rules!read_unsigned{($t:ty)=>{impl Readable for$t{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result:$t=0;let mut read_something=false;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10+(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}debug_assert!(read_something);result}}};}read_signed!(i8);read_signed!(i16);read_signed!(i32);read_signed!(i64);read_signed!(i128);read_signed!(isize);read_unsigned!(u8);read_unsigned!(u16);read_unsigned!(u32);read_unsigned!(u64);read_unsigned!(u128);read_unsigned!(usize);macro_rules!read_tuple{($($t:ident),*)=>{impl<$($t:Readable,)*>Readable for($($t,)*){fn read(reader:&mut Reader)->Self{($($t::read(reader)),*)}}}}read_tuple!(A,B);read_tuple!(A,B,C);read_tuple!(A,B,C,D);read_tuple!(A,B,C,D,E);read_tuple!(A,B,C,D,E,F);read_tuple!(A,B,C,D,E,F,G);read_tuple!(A,B,C,D,E,F,G,H);}pub mod writer{use crate::__cargo_equip::preludes::rlib_io::*;use std::io::Write;use rlib_integer::Integer;pub struct Writer<'a>{buf:[u8;Writer::BUF_SIZE],end:usize,stdout:Box<dyn Write+'a>,}impl<'a>Writer<'a>{const BUF_SIZE:usize=1<<16;pub fn new(stdout:Box<dyn Write+'a>)->Self{Self{buf:[0;Writer::BUF_SIZE],end:0,stdout,}}pub fn write<T:Writable>(&mut self,t:&T){t.write(self);#[cfg(debug_assertions)]self.flush();}pub fn write_char(&mut self,c:char){self.write_bytes(&[c as u8]);#[cfg(debug_assertions)]self.flush();}fn flush(&mut self){if self.end==0{return;}self.stdout.write_all(&self.buf[..self.end]).unwrap();self.end=0;}fn reserve(&mut self,size:usize){if self.end+size>self.buf.len(){self.flush();}}fn write_bytes(&mut self,buf:&[u8]){self.reserve(buf.len());self.buf[self.end..self.end+buf.len()].copy_from_slice(buf);self.end+=buf.len();}}impl Drop for Writer<'_>{fn drop(&mut self){self.flush();}}pub trait Writable{fn write(&self,writer:&mut Writer);}impl Writable for&str{fn write(&self,writer:&mut Writer){for chunk in self.as_bytes().chunks(Writer::BUF_SIZE){writer.write_bytes(chunk);}}}impl Writable for String{fn write(&self,writer:&mut Writer){for chunk in self.as_bytes().chunks(Writer::BUF_SIZE){writer.write_bytes(chunk);}}}impl<T:Writable>Writable for Vec<T>{fn write(&self,writer:&mut Writer){for(i,value)in self.iter().enumerate(){if i!=0{writer.write_char(' ');}writer.write(value);}}}macro_rules!write_unsigned{($t:ty)=>{impl Writable for$t{fn write(&self,writer:&mut Writer){if self==&0{writer.write_char('0');return;}let mut buf=[0;<$t as Integer>::BASE_10_LEN];let mut index=buf.len();let mut value=*self;while value!=0{index-=1;buf[index]=(value%10)as u8+b'0';value/=10;}writer.write_bytes(&buf[index..]);}}};}macro_rules!write_signed{($t:ty)=>{impl Writable for$t{fn write(&self,writer:&mut Writer){if self<&0{writer.write_char('-');}writer.write(&self.unsigned_abs());}}};}write_signed!(i8);write_signed!(i16);write_signed!(i32);write_signed!(i64);write_signed!(i128);write_signed!(isize);write_unsigned!(u8);write_unsigned!(u16);write_unsigned!(u32);write_unsigned!(u64);write_unsigned!(u128);write_unsigned!(usize);macro_rules!write_tuple{($t1:ident,$($t:ident),*)=>{impl<$t1:Writable,$($t:Writable,)*>Writable for($t1,$($t,)*){fn write(&self,writer:&mut Writer){#[allow(non_snake_case)]let($t1,$($t,)*)=self;writer.write($t1);$(writer.write_char(' ');writer.write($t);)*}}}}write_tuple!(A,B);write_tuple!(A,B,C);write_tuple!(A,B,C,D);write_tuple!(A,B,C,D,E);write_tuple!(A,B,C,D,E,F);write_tuple!(A,B,C,D,E,F,G);write_tuple!(A,B,C,D,E,F,G,H);}pub use output_macro::make_output_macro;pub use reader::{Readable,Reader};pub use writer::{Writable,Writer};#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_make_io{($reader:ident,$writer:ident)=>{#[allow(unused_variables)]let mut$reader=rlib_io::reader::Reader::new(Box::new(std::io::stdin().lock()));#[allow(unused_variables)]let mut$writer=rlib_io::writer::Writer::new(Box::new(std::io::stdout().lock()));rlib_io::output_macro::make_output_macro!($writer);};}macro_rules!make_io{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_make_io!{$($tt)*})}}
        pub mod __rlib_rand_0_1_0 {pub mod lcg{use std::time::SystemTime;use crate::__cargo_equip::crates::__rlib_rand_0_1_0::randomable::*;#[derive(Copy,Clone)]pub struct LinearCongruentialGenerator64<const A:u64,const C:u64>{state:u64,}impl<const A:u64,const C:u64>LinearCongruentialGenerator64<A,C>{pub const fn from_seed(seed:u64)->Self{Self{state:seed}}pub fn from_time()->Self{Self{state:SystemTime::now().duration_since(SystemTime::UNIX_EPOCH).unwrap().as_nanos()as u64,}}pub fn next_raw(&mut self)->u64{self.state=self.state.wrapping_mul(A).wrapping_add(C);self.state}pub fn next<T,R>(&mut self,range:R)->T where R:Randomable<T>,{range.gen_from_u64(self.next_raw())}}}pub mod randomable{use std::ops::*;pub trait Randomable<T:Sized>{fn gen_from_u64(self,rng:u64)->T;}macro_rules!implement_ranges{($t:ty)=>{impl Randomable<$t>for RangeTo<$t>{fn gen_from_u64(self,rng:u64)->$t{(0..self.end).gen_from_u64(rng)}}impl Randomable<$t>for RangeInclusive<$t>{fn gen_from_u64(self,rng:u64)->$t{if*self.start()!=<$t>::MIN{(*self.start()-1..*self.end()).gen_from_u64(rng)+1}else if*self.end()!=<$t>::MAX{(*self.start()..*self.end()+1).gen_from_u64(rng)}else{rng as$t}}}impl Randomable<$t>for RangeToInclusive<$t>{fn gen_from_u64(self,rng:u64)->$t{(0..=self.end).gen_from_u64(rng)}}};}macro_rules!make_randomable{($it:ty,$ut:ty)=>{impl Randomable<$it>for Range<$it>{fn gen_from_u64(self,rng:u64)->$it{assert!(!self.is_empty());let len=(self.end as$ut).wrapping_sub(self.start as$ut);((rng%len as u64)as$ut).wrapping_add(self.start as$ut)as$it}}impl Randomable<$ut>for Range<$ut>{fn gen_from_u64(self,rng:u64)->$ut{assert!(!self.is_empty());let len=self.end-self.start;(rng%len as u64)as$ut+self.start}}implement_ranges!($it);implement_ranges!($ut);};}make_randomable!(i8,u8);make_randomable!(i16,u16);make_randomable!(i32,u32);make_randomable!(i64,u64);make_randomable!(isize,usize);impl Randomable<f64>for Range<f64>{fn gen_from_u64(self,rng:u64)->f64{assert!(!self.is_empty());let len=self.end-self.start;(rng as f64/u64::MAX as f64)*len+self.start}}}pub type Rng=lcg::LinearCongruentialGenerator64<6364136223846793005,1442695040888963407>;}
        pub mod rlib_segtree {use crate::__cargo_equip::preludes::rlib_segtree::*;pub mod segtree{use crate::__cargo_equip::preludes::rlib_segtree::*;pub trait SegtreeItem:Sized{fn merge(left:&Self,right:&Self)->Self;fn update(&mut self,left:&Self,right:&Self){*self=Self::merge(left,right);}}pub struct Segtree<T:SegtreeItem>{n:usize,data:Vec<T>,}impl<T:Clone+SegtreeItem>Segtree<T>{pub fn new_raw(n:usize,value:T)->Self{assert!(n!=0);let mut p2:usize=1;while p2<n{p2*=2;}Self{n,data:vec![value;p2*2],}}pub fn new(n:usize,value:T)->Self{let mut res=Self::new_raw(n,value);res.rebuild(0,0,res.n-1,None);res}pub fn from_slice(data:&[T])->Self{let mut res=Self::new_raw(data.len(),data[0].clone());res.rebuild(0,0,res.n-1,Some(data));res}fn rebuild(&mut self,i:usize,l:usize,r:usize,data:Option<&[T]>){if l==r{if let Some(data)=data{self.data[i]=data[l].clone();}return;}let m=(l+r)/2;self.rebuild(i*2+1,l,m,data);self.rebuild(i*2+2,m+1,r,data);let(left,right)=self.data.split_at_mut(i*2+1);left[i].update(&right[0],&right[1]);}pub fn set(&mut self,ind:usize,value:T){assert!(ind<self.n);self.set_internal(ind,value,0,0,self.n-1);}fn set_internal(&mut self,ind:usize,value:T,i:usize,vl:usize,vr:usize){if vl==vr{self.data[i]=value;return;}let m=(vl+vr)/2;if ind<=m{self.set_internal(ind,value,i*2+1,vl,m);}else{self.set_internal(ind,value,i*2+2,m+1,vr);}let(left,right)=self.data.split_at_mut(i*2+1);left[i].update(&right[0],&right[1]);}pub fn ask(&self,l:usize,r:usize)->T{assert!(l<=r);assert!(r<self.n);self.ask_internal(l,r,0,0,self.n-1)}fn ask_internal(&self,l:usize,r:usize,i:usize,vl:usize,vr:usize)->T{if l==vl&&r==vr{return self.data[i].clone();}let m=(vl+vr)/2;if r<=m{self.ask_internal(l,r,i*2+1,vl,m)}else if l>m{self.ask_internal(l,r,i*2+2,m+1,vr)}else{T::merge(&self.ask_internal(l,m,i*2+1,vl,m),&self.ask_internal(m+1,r,i*2+2,m+1,vr),)}}}}pub mod segtree_items{use crate::__cargo_equip::preludes::rlib_segtree::*;use crate::__cargo_equip::crates::rlib_segtree::segtree::SegtreeItem;#[derive(Clone,Debug)]pub struct Min<T:std::cmp::PartialOrd+Clone>{pub v:T,}impl<T:std::cmp::PartialOrd+Clone>Min<T>{pub fn new(v:T)->Self{Self{v}}}impl<T:std::cmp::PartialOrd+Clone>SegtreeItem for Min<T>{fn merge(left:&Self,right:&Self)->Self{if left.v<right.v{left.clone()}else{right.clone()}}}#[derive(Clone,Debug)]pub struct Max<T:std::cmp::PartialOrd+Clone>{pub v:T,}impl<T:std::cmp::PartialOrd+Clone>Max<T>{pub fn new(v:T)->Self{Self{v}}}impl<T:std::cmp::PartialOrd+Clone>SegtreeItem for Max<T>{fn merge(left:&Self,right:&Self)->Self{if left.v>right.v{left.clone()}else{right.clone()}}}#[derive(Clone,Debug)]pub struct Sum<T:Clone>{pub v:T,}impl<T:std::cmp::PartialOrd+Clone>Sum<T>{pub fn new(v:T)->Self{Self{v}}}impl<T:std::ops::Add<Output=T>+Clone>SegtreeItem for Sum<T>{fn merge(left:&Self,right:&Self)->Self{Self{v:left.v.clone()+right.v.clone(),}}}}pub use segtree::{Segtree,SegtreeItem};}
    }

    pub(crate) mod macros {
        pub mod rlib_integer {}
        pub mod rlib_io {pub use crate::{__cargo_equip_macro_def_rlib_io_make_io as make_io,__cargo_equip_macro_def_rlib_io_make_output_macro_ as make_output_macro_,__cargo_equip_macro_def_rlib_io_out_impl as out_impl};}
        pub mod __rlib_rand_0_1_0 {}
        pub mod rlib_segtree {}
    }

    pub(crate) mod prelude {pub use crate::__cargo_equip::crates::*;}

    mod preludes {
        pub mod rlib_integer {}
        pub mod rlib_io {pub(in crate::__cargo_equip)use crate::__cargo_equip::crates::rlib_integer;}
        pub mod __rlib_rand_0_1_0 {}
        pub mod rlib_segtree {pub(in crate::__cargo_equip)use crate::__cargo_equip::crates::__rlib_rand_0_1_0 as rlib_rand;}
    }
}