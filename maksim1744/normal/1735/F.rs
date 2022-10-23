/*
    author:  Maksim1744
    created: 05.10.2022 02:50:00
*/

pub use __cargo_equip::prelude::*;

use rlib_f80::*;
use rlib_io::*;
use std::cmp::Ordering;
use std::collections::BTreeSet;

#[derive(PartialEq, Clone, Debug)]
struct Segment {
    x: f80,
    y: f80,
    i: usize,
}

impl Eq for Segment {}

impl Ord for Segment {
    fn cmp(&self, other: &Self) -> Ordering {
        self.i.cmp(&other.i)
    }
}

impl PartialOrd for Segment {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

fn solve(cin: &mut Reader, cout: &mut Writer, _test: usize) {
    make_output_macro!(cout);

    let n: usize = cin.read();
    let mut x0 = f80::from(cin.read::<i32>() as f64);
    let mut y0 = f80::from(cin.read::<i32>() as f64);
    let mut totx = f80::ZERO;
    let mut toty = f80::ZERO;

    let p = cin.read_vec::<i32>(n);
    let q = cin.read_vec::<i32>(n);

    if x0 == f80::ZERO && y0 == f80::ZERO {
        for _ in 0..n {
            outln!(0);
        }
        return;
    }

    let mut segs = BTreeSet::<Segment>::new();

    let mut vecs = p
        .iter()
        .cloned()
        .zip(q.iter().cloned())
        .enumerate()
        .collect::<Vec<_>>();
    vecs.sort_by(|&(_i1, (x1, y1)), &(_i2, (x2, y2))| {
        (x1 as i64 * -y2 as i64).cmp(&(x2 as i64 * -y1 as i64))
    });
    // dbg!(&vecs);
    let mut perm = vec![0; n];
    for (ind, val) in vecs.into_iter().enumerate() {
        perm[val.0] = ind as i32;
    }

    let vecs = p
        .into_iter()
        .zip(q.into_iter())
        .enumerate()
        .collect::<Vec<_>>();

    let eps = f80::from(1e-9);

    for &(i, (x, y)) in vecs.iter() {
        let x = f80::from(x as f64);
        let y = f80::from(-y as f64);

        segs.insert(Segment {
            x: x * f80::from(2.),
            y: y * f80::from(2.),
            i: perm[i] as usize,
        });

        totx += x * f80::from(2.);
        toty += y * f80::from(2.);
        x0 -= x;
        y0 -= y;

        while x0 < f80::ZERO && !segs.is_empty() {
            let mut s = segs.iter().next().unwrap().clone();
            assert!(segs.remove(&s));
            if x0 + s.x < f80::ZERO {
                x0 += s.x;
                y0 += s.y;
                totx -= s.x;
                toty -= s.y;
            } else {
                let k = s.y / s.x;
                s.x += x0;
                s.y += x0 * k;
                totx += x0;
                toty += x0 * k;
                y0 -= x0 * k;
                x0 = f80::ZERO;
                if s.y < -eps && s.x > eps {
                    segs.insert(s);
                }
            }
        }

        while y0 + toty < f80::ZERO && !segs.is_empty() {
            let mut s = segs.iter().rev().next().unwrap().clone();
            assert!(segs.remove(&s));
            if y0 + toty - s.y < f80::ZERO {
                totx -= s.x;
                toty -= s.y;
            } else {
                let k = s.x / s.y;
                let dy = y0 + toty;
                let dx = dy * k;
                s.y -= dy;
                s.x -= dx;
                totx -= dx;
                toty = -y0;
                if s.y < -eps && s.x > eps {
                    segs.insert(s);
                }
            }
        }

        outln!(format!("{:.20}", x0 + totx));
    }
}

fn main() {
    f80_init();
    make_io!(cin, cout);
    let tests: usize = cin.read();
    for test in 1..=tests {
        solve(&mut cin, &mut cout, test);
    }
}

// The following code was expanded by `cargo-equip`.

///  # Bundled libraries
/// 
///  - `rlib_f80 0.1.0 (path+)`         published in https://github.com/maksim1744/rlib licensed under `MIT` as `crate::__cargo_equip::crates::rlib_f80`
///  - `rlib_integer 0.1.0 (path+)` published in https://github.com/maksim1744/rlib licensed under `MIT` as `crate::__cargo_equip::crates::rlib_integer`
///  - `rlib_io 0.1.0 (path+)`           published in https://github.com/maksim1744/rlib licensed under `MIT` as `crate::__cargo_equip::crates::rlib_io`
#[cfg_attr(any(), rustfmt::skip)]
#[allow(unused)]
mod __cargo_equip {
    pub(crate) mod crates {
        pub mod rlib_f80 {use crate::__cargo_equip::preludes::rlib_f80::*;use core::ops::{Add,AddAssign,Div,DivAssign,Mul,MulAssign,Neg,Sub,SubAssign};use std::cmp::Ordering;#[derive(Clone,Copy,PartialEq,Eq)]#[repr(align(16))]#[allow(non_camel_case_types)]pub struct f80([u8;10]);pub fn f80_init(){#[cfg(target_family="windows")]unsafe{core::arch::asm!{"finit"}}}macro_rules!define_f80_binary_op{($trait:ident,$fun:ident,$asm:literal)=>{impl$trait for f80{type Output=f80;fn$fun(self,rhs:Self)->Self::Output{let mut res=core::mem::MaybeUninit::<f80>::uninit();unsafe{core::arch::asm!{"fld     TBYTE PTR [{0}]","fld     TBYTE PTR [{1}]",$asm,"fstp    TBYTE PTR [{2}]",in(reg)self.0.as_ptr(),in(reg)rhs.0.as_ptr(),in(reg)res.as_mut_ptr(),options(nostack)}res.assume_init()}}}};}macro_rules!define_f80_unary_op{($trait:ident,$fun:ident,$asm:literal)=>{impl$trait for f80{type Output=f80;fn$fun(self)->Self::Output{let mut res=core::mem::MaybeUninit::<f80>::uninit();unsafe{core::arch::asm!{"fld     TBYTE PTR [{0}]",$asm,"fstp    TBYTE PTR [{1}]",in(reg)self.0.as_ptr(),in(reg)res.as_mut_ptr(),options(nostack)}res.assume_init()}}}};}macro_rules!define_f80_assign_op{($trait:ident,$fun:ident,$no_assign_fun:ident)=>{impl$trait for f80{fn$fun(&mut self,rhs:f80){*self=self.$no_assign_fun(rhs);}}};}define_f80_binary_op!(Add,add,"faddp   st(1), st");define_f80_binary_op!(Sub,sub,"fsubp   st(1), st");define_f80_binary_op!(Mul,mul,"fmulp   st(1), st");define_f80_binary_op!(Div,div,"fdivp   st(1), st");define_f80_assign_op!(AddAssign,add_assign,add);define_f80_assign_op!(SubAssign,sub_assign,sub);define_f80_assign_op!(MulAssign,mul_assign,mul);define_f80_assign_op!(DivAssign,div_assign,div);define_f80_unary_op!(Neg,neg,"fchs");impl PartialOrd<f80>for f80{fn lt(&self,rhs:&f80)->bool{let mut res=std::mem::MaybeUninit::<u32>::uninit();unsafe{let e:u32;core::arch::asm!{"fld     TBYTE PTR [{0}]","fld     TBYTE PTR [{1}]","fcomip  st, st(1)","fstp    st(0)","seta    al",in(reg)self.0.as_ptr(),in(reg)rhs.0.as_ptr(),out("eax")e,options(nostack)}*res.as_mut_ptr()=e;(res.assume_init()&1)>0}}fn gt(&self,rhs:&f80)->bool{rhs.lt(self)}fn le(&self,rhs:&f80)->bool{!self.gt(rhs)}fn ge(&self,rhs:&f80)->bool{!self.lt(rhs)}fn partial_cmp(&self,rhs:&f80)->Option<Ordering>{match(*self<=*rhs,*self>=*rhs){(false,false)=>None,(false,true)=>Some(Ordering::Greater),(true,false)=>Some(Ordering::Less),(true,true)=>Some(Ordering::Equal),}}}impl f80{pub const ZERO:f80=f80([0,0,0,0,0,0,0,0,0,0]);pub const ONE:f80=f80([0,0,0,0,0,0,0,128,255,63]);pub fn abs(self)->f80{if self<f80::from(0.){-self}else{self}}pub fn min(self,rhs:f80)->f80{let mut res=core::mem::MaybeUninit::<f80>::uninit();unsafe{core::arch::asm!{"fld     TBYTE PTR [{0}]","fld     TBYTE PTR [{1}]","fucomi  st, st(1)","fcmovnbe st, st(1)","fstp    st(1)","fstp    TBYTE PTR [{2}]",in(reg)self.0.as_ptr(),in(reg)rhs.0.as_ptr(),in(reg)res.as_mut_ptr(),options(nostack)}res.assume_init()}}pub fn max(self,rhs:f80)->f80{let mut res=core::mem::MaybeUninit::<f80>::uninit();unsafe{core::arch::asm!{"fld     TBYTE PTR [{0}]","fld     TBYTE PTR [{1}]","fucomi  st, st(1)","fcmovbe st, st(1)","fstp    st(1)","fstp    TBYTE PTR [{2}]",in(reg)self.0.as_ptr(),in(reg)rhs.0.as_ptr(),in(reg)res.as_mut_ptr(),options(nostack)}res.assume_init()}}}impl From<f80>for f64{fn from(f:f80)->Self{let mut res=core::mem::MaybeUninit::<f64>::uninit();unsafe{core::arch::asm!{"fld     TBYTE PTR [{0}]","fstp    QWORD PTR [{1}]",in(reg)f.0.as_ptr(),in(reg)res.as_mut_ptr(),options(nostack)}res.assume_init()}}}impl From<f64>for f80{fn from(f:f64)->Self{let mut res=core::mem::MaybeUninit::<f80>::uninit();unsafe{core::arch::asm!{"fld     QWORD PTR [{0}]","fstp    TBYTE PTR [{1}]",in(reg)&f as*const _,in(reg)res.as_mut_ptr(),options(nostack)}res.assume_init()}}}impl Default for f80{fn default()->Self{f80::from(0.)}}impl std::fmt::Display for f80{fn fmt(&self,f:&mut std::fmt::Formatter<'_>)->std::fmt::Result{f64::from(*self).fmt(f)}}impl std::fmt::Debug for f80{fn fmt(&self,f:&mut std::fmt::Formatter<'_>)->std::fmt::Result{f64::from(*self).fmt(f)}}}
        pub mod rlib_integer {pub trait Integer{type Unsigned;type Signed;const BASE_10_LEN:usize;const ZERO:Self;const ONE:Self;const TWO:Self;fn unsigned_abs(self)->Self::Unsigned;}macro_rules!integer_common{($it:ty,$ut:ty,$len:expr)=>{type Unsigned=$ut;type Signed=$it;const BASE_10_LEN:usize=$len;const ZERO:Self=0;const ONE:Self=1;const TWO:Self=2;};}macro_rules!base_10_len{($ut:ty)=>{{let mut value=<$ut>::MAX;let mut ans:usize=0;while value!=0{value/=10;ans+=1;}ans}};}macro_rules!integer{($it:ty,$ut:ty,$len:expr)=>{impl Integer for$it{integer_common!($it,$ut,$len);fn unsigned_abs(self)->Self::Unsigned{Self::unsigned_abs(self)}}impl Integer for$ut{integer_common!($it,$ut,$len);fn unsigned_abs(self)->Self::Unsigned{self}}};($it:ty,$ut:ty)=>{integer!($it,$ut,base_10_len!($ut));};}integer!(i8,u8);integer!(i16,u16);integer!(i32,u32);integer!(i64,u64);integer!(i128,u128);integer!(isize,usize);}
        pub mod rlib_io {use crate::__cargo_equip::preludes::rlib_io::*;pub use crate::__cargo_equip::macros::rlib_io::*;pub mod output_macro{use crate::__cargo_equip::preludes::rlib_io::*;#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_out_impl{($writer:ident,$x:expr)=>{$writer.write(&$x);};($writer:ident,$x:expr,$($xx:tt)*)=>{$writer.write(&$x);$writer.write_char(' ');rlib_io::out_impl!($writer,$($xx)*);};}macro_rules!out_impl{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_out_impl!{$($tt)*})}#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_make_output_macro_{($writer:ident)=>{make_output_macro_!($writer,$);};($writer:ident,$dol:tt)=>{#[allow(unused_macros)]macro_rules!out{($dol($dol x:tt)*)=>{rlib_io::out_impl!($writer,$dol($dol x)*);};}#[allow(unused_macros)]macro_rules!outln{($dol($dol x:tt)*)=>{rlib_io::out_impl!($writer,$dol($dol x)*);$writer.write_char('\n');};}}}macro_rules!make_output_macro_{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_make_output_macro_!{$($tt)*})}pub use crate::__cargo_equip::crates::rlib_io::make_output_macro_ as make_output_macro;}pub mod reader{use crate::__cargo_equip::preludes::rlib_io::*;use std::io::Read;pub struct Reader{buf:[u8;Reader::BUF_SIZE],begin:usize,end:usize,stdin:Box<dyn Read>,eof:bool,}impl Reader{const BUF_SIZE:usize=1<<16;pub fn new(stdin:Box<dyn Read>)->Self{Self{buf:[0;Reader::BUF_SIZE],begin:0,end:0,stdin,eof:false,}}pub fn read<T:Readable>(&mut self)->T{T::read(self)}pub fn read_vec<T:Readable>(&mut self,n:usize)->Vec<T>{let mut result=Vec::<T>::with_capacity(n);for _ in 0..n{result.push(self.read());}result}fn refill(&mut self){if self.eof{return;}if self.begin!=0{self.buf.copy_within(self.begin..self.end,0);self.end-=self.begin;self.begin=0;}let bytes=self.stdin.read(&mut self.buf[self.end..]).unwrap();if bytes==0{self.eof=true;}self.end+=bytes;}fn skip_whitespace(&mut self){while{if self.begin==self.end{self.refill();}!self.eof&&self.peek().is_ascii_whitespace()}{self.begin+=1;if self.begin==self.end{self.refill();}}}fn peek(&mut self)->u8{if self.begin==self.end{self.refill();}self.buf[self.begin]}}pub trait Readable{fn read(reader:&mut Reader)->Self;}impl Readable for String{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result=String::new();let mut read_something=false;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{result.push(reader.peek()as char);reader.begin+=1;read_something=true;}debug_assert!(read_something);result}}macro_rules!read_signed{($t:ty)=>{impl Readable for$t{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result:$t=0;let mut read_something=false;if reader.peek()==b'-'{reader.begin+=1;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10-(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}}else{while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10+(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}}debug_assert!(read_something);result}}};}macro_rules!read_unsigned{($t:ty)=>{impl Readable for$t{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result:$t=0;let mut read_something=false;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10+(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}debug_assert!(read_something);result}}};}read_signed!(i8);read_signed!(i16);read_signed!(i32);read_signed!(i64);read_signed!(i128);read_signed!(isize);read_unsigned!(u8);read_unsigned!(u16);read_unsigned!(u32);read_unsigned!(u64);read_unsigned!(u128);read_unsigned!(usize);macro_rules!read_tuple{($($t:ident),*)=>{impl<$($t:Readable,)*>Readable for($($t,)*){fn read(reader:&mut Reader)->Self{($($t::read(reader)),*)}}}}read_tuple!(A,B);read_tuple!(A,B,C);read_tuple!(A,B,C,D);read_tuple!(A,B,C,D,E);read_tuple!(A,B,C,D,E,F);read_tuple!(A,B,C,D,E,F,G);read_tuple!(A,B,C,D,E,F,G,H);}pub mod writer{use crate::__cargo_equip::preludes::rlib_io::*;use std::io::Write;use rlib_integer::Integer;pub struct Writer<'a>{buf:[u8;Writer::BUF_SIZE],end:usize,stdout:Box<dyn Write+'a>,}impl<'a>Writer<'a>{const BUF_SIZE:usize=1<<16;pub fn new(stdout:Box<dyn Write+'a>)->Self{Self{buf:[0;Writer::BUF_SIZE],end:0,stdout,}}pub fn write<T:Writable>(&mut self,t:&T){t.write(self);#[cfg(debug_assertions)]self.flush();}pub fn write_char(&mut self,c:char){self.write_bytes(&[c as u8]);#[cfg(debug_assertions)]self.flush();}fn flush(&mut self){if self.end==0{return;}self.stdout.write_all(&self.buf[..self.end]).unwrap();self.end=0;}fn reserve(&mut self,size:usize){if self.end+size>self.buf.len(){self.flush();}}fn write_bytes(&mut self,buf:&[u8]){self.reserve(buf.len());self.buf[self.end..self.end+buf.len()].copy_from_slice(buf);self.end+=buf.len();}}impl Drop for Writer<'_>{fn drop(&mut self){self.flush();}}pub trait Writable{fn write(&self,writer:&mut Writer);}impl Writable for&str{fn write(&self,writer:&mut Writer){for chunk in self.as_bytes().chunks(Writer::BUF_SIZE){writer.write_bytes(chunk);}}}impl Writable for String{fn write(&self,writer:&mut Writer){for chunk in self.as_bytes().chunks(Writer::BUF_SIZE){writer.write_bytes(chunk);}}}impl<T:Writable>Writable for Vec<T>{fn write(&self,writer:&mut Writer){for(i,value)in self.iter().enumerate(){if i!=0{writer.write_char(' ');}writer.write(value);}}}macro_rules!write_unsigned{($t:ty)=>{impl Writable for$t{fn write(&self,writer:&mut Writer){if self==&0{writer.write_char('0');return;}let mut buf=[0;<$t as Integer>::BASE_10_LEN];let mut index=buf.len();let mut value=*self;while value!=0{index-=1;buf[index]=(value%10)as u8+b'0';value/=10;}writer.write_bytes(&buf[index..]);}}};}macro_rules!write_signed{($t:ty)=>{impl Writable for$t{fn write(&self,writer:&mut Writer){if self<&0{writer.write_char('-');}writer.write(&self.unsigned_abs());}}};}write_signed!(i8);write_signed!(i16);write_signed!(i32);write_signed!(i64);write_signed!(i128);write_signed!(isize);write_unsigned!(u8);write_unsigned!(u16);write_unsigned!(u32);write_unsigned!(u64);write_unsigned!(u128);write_unsigned!(usize);macro_rules!write_tuple{($t1:ident,$($t:ident),*)=>{impl<$t1:Writable,$($t:Writable,)*>Writable for($t1,$($t,)*){fn write(&self,writer:&mut Writer){#[allow(non_snake_case)]let($t1,$($t,)*)=self;writer.write($t1);$(writer.write_char(' ');writer.write($t);)*}}}}write_tuple!(A,B);write_tuple!(A,B,C);write_tuple!(A,B,C,D);write_tuple!(A,B,C,D,E);write_tuple!(A,B,C,D,E,F);write_tuple!(A,B,C,D,E,F,G);write_tuple!(A,B,C,D,E,F,G,H);}pub use output_macro::make_output_macro;pub use reader::{Readable,Reader};pub use writer::{Writable,Writer};#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_make_io{($reader:ident,$writer:ident)=>{#[allow(unused_variables)]let mut$reader=rlib_io::reader::Reader::new(Box::new(std::io::stdin().lock()));#[allow(unused_variables)]let mut$writer=rlib_io::writer::Writer::new(Box::new(std::io::stdout().lock()));rlib_io::output_macro::make_output_macro!($writer);};}macro_rules!make_io{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_make_io!{$($tt)*})}}
    }

    pub(crate) mod macros {
        pub mod rlib_f80 {}
        pub mod rlib_integer {}
        pub mod rlib_io {pub use crate::{__cargo_equip_macro_def_rlib_io_make_io as make_io,__cargo_equip_macro_def_rlib_io_make_output_macro_ as make_output_macro_,__cargo_equip_macro_def_rlib_io_out_impl as out_impl};}
    }

    pub(crate) mod prelude {pub use crate::__cargo_equip::crates::*;}

    mod preludes {
        pub mod rlib_f80 {pub(in crate::__cargo_equip)use crate::__cargo_equip::crates::rlib_integer;}
        pub mod rlib_integer {}
        pub mod rlib_io {pub(in crate::__cargo_equip)use crate::__cargo_equip::crates::rlib_integer;}
    }
}