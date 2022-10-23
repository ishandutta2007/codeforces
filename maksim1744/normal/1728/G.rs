/*
    author:  Maksim1744
    created: 14.10.2022 18:10:50
*/

pub use __cargo_equip::prelude::*;

use rlib_io::*;
use rlib_mint::*;

type Mint = Mint998;

const M: usize = 16;

fn solve(cin: &mut Reader, cout: &mut Writer, _test: usize) {
    make_output_macro!(cout);

    let d: i32 = cin.read();
    let n: usize = cin.read();
    let m: usize = cin.read();

    let mut x: Vec<i32> = cin.read_vec(n);
    x.sort();
    let mut p: Vec<i32> = cin.read_vec(m);
    p.sort();

    let q: usize = cin.read();

    let mut buckets = vec![Vec::new(); m + 1];
    for &x in x.iter() {
        buckets[p.partition_point(|&y| y < x)].push(x);
    }

    eprintln!("{:?}", p);
    eprintln!("{:?}", buckets);
    let mut bucket_cnts = Vec::new();
    let mut bucket_cnts_raw = Vec::new();
    for (i, bucket) in buckets.iter().enumerate() {
        let mut cnts = [[Mint::ZERO; M + 1]; M + 1];
        for l in 0..=m {
            for r in 0..=m {
                let lpos = if l >= i { -d - 20 } else { p[i - l - 1] };
                let rpos = if i + r >= m { d * 2 + 20 } else { p[i + r] };
                let mut cnt = Mint::ONE;
                for &x in bucket.iter() {
                    cnt *= Mint::new((x - lpos).min(rpos - x).min(d + 1) as i64);
                }
                cnts[l][r] = cnt;
            }
        }

        bucket_cnts_raw.push(cnts);

        for i in (0..=m).rev() {
            for j in (0..=m).rev() {
                if i != 0 {
                    cnts[i][j] -= cnts[i - 1][j];
                }
                if j != 0 {
                    cnts[i][j] -= cnts[i][j - 1];
                }
                if i != 0 && j != 0 {
                    cnts[i][j] += cnts[i - 1][j - 1];
                }
            }
        }

        bucket_cnts.push(cnts);
    }

    let get_dpls = |bucket_cnts: &Vec<[[Mint; M + 1]; M + 1]>, rev: bool| -> Vec<[[Mint; M + 1]; M + 1]> {
        let get_cnts = |cnts: &[[Mint; M + 1]; M + 1], l: usize, r: usize| -> Mint {
            if rev {
                cnts[r][l]
            } else {
                cnts[l][r]
            }
        };

        let mut dp = [[Mint::ZERO; M + 1]; M + 1];
        for r in 0..=m {
            dp[r][r] = get_cnts(&bucket_cnts[0], 0, r);
        }

        let mut dpls = vec![dp];

        for (i, cnts) in bucket_cnts.iter().enumerate().skip(1) {
            let mut nx = [[Mint::ZERO; M + 1]; M + 1];

            for first_bad in 0..=m {
                for cnt_good in 0..=m {
                    if dp[first_bad][cnt_good] == Mint::ZERO {
                        continue;
                    }
                    for l in 0..=i {
                        for r in 0..=m - i {
                            if l == 0 && r == 0 {
                                nx[first_bad][cnt_good] += dp[first_bad][cnt_good] * cnts[0][0];
                            } else {
                                let ll = i - l;
                                let rr = i + r - 1;
                                if first_bad >= ll {
                                    nx[cnt_good.max(rr + 1)][cnt_good.max(rr + 1)] += dp[first_bad][cnt_good] * get_cnts(cnts, l, r);
                                } else {
                                    nx[first_bad][cnt_good.max(rr + 1)] += dp[first_bad][cnt_good] * get_cnts(cnts, l, r);
                                }
                            }
                        }
                    }
                }
            }

            std::mem::swap(&mut dp, &mut nx);

            dpls.push(dp);
        }

        dpls
    };

    let dpls = get_dpls(&bucket_cnts, false);
    bucket_cnts.reverse();
    let mut dprs = get_dpls(&bucket_cnts, true);
    bucket_cnts.reverse();
    dprs.reverse();

    let mut precs = Vec::new();
    for i in 0..=m {
        if i == 0 {
            let mut prec = [[Mint::ZERO; M + 1]; M + 1];
            for first_bad in 0..=m {
                for cnt_good in 0..=m {
                    prec[0][m - first_bad] += dprs[i + 1][first_bad][cnt_good];
                }
            }
            precs.push(prec);
        } else if i == m {
            let mut prec = [[Mint::ZERO; M + 1]; M + 1];
            for first_bad in 0..=m {
                for cnt_good in 0..=m {
                    prec[m - first_bad][0] += dpls[i - 1][first_bad][cnt_good];
                }
            }
            precs.push(prec);
        } else {
            let mut prec = [[Mint::ZERO; M + 1]; M + 1];
            for first_bad_l in 0..=m {
                for cnt_good_l in 0..=m {
                    if dpls[i - 1][first_bad_l][cnt_good_l] == Mint::ZERO {
                        continue;
                    }
                    for first_bad_r in 0..=m {
                        for cnt_good_r in 0..=m {
                            if dprs[i + 1][first_bad_r][cnt_good_r] == Mint::ZERO {
                                continue;
                            }
                            let needl = if first_bad_l + cnt_good_r >= m {
                                0
                            } else {
                                i.checked_sub(first_bad_l).unwrap_or(0)
                            };
                            let needr = if first_bad_r + cnt_good_l >= m {
                                0
                            } else {
                                (m - i).checked_sub(first_bad_r).unwrap_or(0)
                            };
                            prec[needl][needr] += dpls[i - 1][first_bad_l][cnt_good_l] * dprs[i + 1][first_bad_r][cnt_good_r];
                        }
                    }
                }
            }
            precs.push(prec);
        }
    }

    for _ in 0..q {
        let x0: i32 = cin.read();
        let i = p.partition_point(|&y| y < x0);

        let mut cnts = bucket_cnts_raw[i].clone();

        for l in 0..=m {
            for r in 0..=m {
                let lpos = if l >= i { -d - 20 } else { p[i - l - 1] };
                let rpos = if i + r >= m { d * 2 + 20 } else { p[i + r] };
                cnts[l][r] *= Mint::new((x0 - lpos).min(rpos - x0).min(d + 1) as i64);
            }
        }

        let mut ans = Mint::ZERO;

        for needl in 0..=m {
            for needr in 0..=m {
                let mut c = cnts[m][m];
                if needl != 0 {
                    c -= cnts[needl - 1][m];
                }
                if needr != 0 {
                    c -= cnts[m][needr - 1];
                }
                if needl != 0 && needr != 0 {
                    c += cnts[needl - 1][needr - 1];
                }
                ans += precs[i][needl][needr] * c;
            }
        }

        outln!(ans);
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
///  - `rlib_mint 0.1.0 (path+)`       published in https://github.com/maksim1744/rlib licensed under `MIT` as `crate::__cargo_equip::crates::rlib_mint`
#[cfg_attr(any(), rustfmt::skip)]
#[allow(unused)]
mod __cargo_equip {
    pub(crate) mod crates {
        pub mod rlib_integer {pub trait Integer{type Unsigned;type Signed;const BASE_10_LEN:usize;const ZERO:Self;const ONE:Self;const TWO:Self;fn unsigned_abs(self)->Self::Unsigned;}macro_rules!integer_common{($it:ty,$ut:ty,$len:expr)=>{type Unsigned=$ut;type Signed=$it;const BASE_10_LEN:usize=$len;const ZERO:Self=0;const ONE:Self=1;const TWO:Self=2;};}macro_rules!base_10_len{($ut:ty)=>{{let mut value=<$ut>::MAX;let mut ans:usize=0;while value!=0{value/=10;ans+=1;}ans}};}macro_rules!integer{($it:ty,$ut:ty,$len:expr)=>{impl Integer for$it{integer_common!($it,$ut,$len);fn unsigned_abs(self)->Self::Unsigned{Self::unsigned_abs(self)}}impl Integer for$ut{integer_common!($it,$ut,$len);fn unsigned_abs(self)->Self::Unsigned{self}}};($it:ty,$ut:ty)=>{integer!($it,$ut,base_10_len!($ut));};}integer!(i8,u8);integer!(i16,u16);integer!(i32,u32);integer!(i64,u64);integer!(i128,u128);integer!(isize,usize);}
        pub mod rlib_io {use crate::__cargo_equip::preludes::rlib_io::*;pub use crate::__cargo_equip::macros::rlib_io::*;pub mod output_macro{use crate::__cargo_equip::preludes::rlib_io::*;#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_out_impl{($writer:ident,$x:expr)=>{$writer.write(&$x);};($writer:ident,$x:expr,$($xx:tt)*)=>{$writer.write(&$x);$writer.write_char(' ');rlib_io::out_impl!($writer,$($xx)*);};}macro_rules!out_impl{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_out_impl!{$($tt)*})}#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_make_output_macro_{($writer:ident)=>{make_output_macro_!($writer,$);};($writer:ident,$dol:tt)=>{#[allow(unused_macros)]macro_rules!out{($dol($dol x:tt)*)=>{rlib_io::out_impl!($writer,$dol($dol x)*);};}#[allow(unused_macros)]macro_rules!outln{($dol($dol x:tt)*)=>{rlib_io::out_impl!($writer,$dol($dol x)*);$writer.write_char('\n');};}}}macro_rules!make_output_macro_{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_make_output_macro_!{$($tt)*})}pub use crate::__cargo_equip::crates::rlib_io::make_output_macro_ as make_output_macro;}pub mod reader{use crate::__cargo_equip::preludes::rlib_io::*;use std::io::Read;pub struct Reader{buf:[u8;Reader::BUF_SIZE],begin:usize,end:usize,stdin:Box<dyn Read>,eof:bool,}impl Reader{const BUF_SIZE:usize=1<<16;pub fn new(stdin:Box<dyn Read>)->Self{Self{buf:[0;Reader::BUF_SIZE],begin:0,end:0,stdin,eof:false,}}pub fn read<T:Readable>(&mut self)->T{T::read(self)}pub fn read_vec<T:Readable>(&mut self,n:usize)->Vec<T>{let mut result=Vec::<T>::with_capacity(n);for _ in 0..n{result.push(self.read());}result}fn refill(&mut self){if self.eof{return;}if self.begin!=0{self.buf.copy_within(self.begin..self.end,0);self.end-=self.begin;self.begin=0;}let bytes=self.stdin.read(&mut self.buf[self.end..]).unwrap();if bytes==0{self.eof=true;}self.end+=bytes;}fn skip_whitespace(&mut self){while{if self.begin==self.end{self.refill();}!self.eof&&self.peek().is_ascii_whitespace()}{self.begin+=1;if self.begin==self.end{self.refill();}}}fn peek(&mut self)->u8{if self.begin==self.end{self.refill();}self.buf[self.begin]}}pub trait Readable{fn read(reader:&mut Reader)->Self;}impl Readable for String{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result=String::new();let mut read_something=false;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{result.push(reader.peek()as char);reader.begin+=1;read_something=true;}debug_assert!(read_something);result}}macro_rules!read_signed{($t:ty)=>{impl Readable for$t{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result:$t=0;let mut read_something=false;if reader.peek()==b'-'{reader.begin+=1;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10-(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}}else{while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10+(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}}debug_assert!(read_something);result}}};}macro_rules!read_unsigned{($t:ty)=>{impl Readable for$t{fn read(reader:&mut Reader)->Self{reader.skip_whitespace();let mut result:$t=0;let mut read_something=false;while{if reader.begin==reader.end{reader.refill();}!reader.eof&&!reader.peek().is_ascii_whitespace()}{debug_assert!(reader.buf[reader.begin].is_ascii_digit());result=result*10+(reader.buf[reader.begin]-('0' as u8))as$t;reader.begin+=1;read_something=true;}debug_assert!(read_something);result}}};}read_signed!(i8);read_signed!(i16);read_signed!(i32);read_signed!(i64);read_signed!(i128);read_signed!(isize);read_unsigned!(u8);read_unsigned!(u16);read_unsigned!(u32);read_unsigned!(u64);read_unsigned!(u128);read_unsigned!(usize);macro_rules!read_tuple{($($t:ident),*)=>{impl<$($t:Readable,)*>Readable for($($t,)*){fn read(reader:&mut Reader)->Self{($($t::read(reader)),*)}}}}read_tuple!(A,B);read_tuple!(A,B,C);read_tuple!(A,B,C,D);read_tuple!(A,B,C,D,E);read_tuple!(A,B,C,D,E,F);read_tuple!(A,B,C,D,E,F,G);read_tuple!(A,B,C,D,E,F,G,H);}pub mod writer{use crate::__cargo_equip::preludes::rlib_io::*;use std::io::Write;use rlib_integer::Integer;pub struct Writer<'a>{buf:[u8;Writer::BUF_SIZE],end:usize,stdout:Box<dyn Write+'a>,}impl<'a>Writer<'a>{const BUF_SIZE:usize=1<<16;pub fn new(stdout:Box<dyn Write+'a>)->Self{Self{buf:[0;Writer::BUF_SIZE],end:0,stdout,}}pub fn write<T:Writable>(&mut self,t:&T){t.write(self);#[cfg(debug_assertions)]self.flush();}pub fn write_char(&mut self,c:char){self.write_bytes(&[c as u8]);#[cfg(debug_assertions)]self.flush();}fn flush(&mut self){if self.end==0{return;}self.stdout.write_all(&self.buf[..self.end]).unwrap();self.end=0;}fn reserve(&mut self,size:usize){if self.end+size>self.buf.len(){self.flush();}}fn write_bytes(&mut self,buf:&[u8]){self.reserve(buf.len());self.buf[self.end..self.end+buf.len()].copy_from_slice(buf);self.end+=buf.len();}}impl Drop for Writer<'_>{fn drop(&mut self){self.flush();}}pub trait Writable{fn write(&self,writer:&mut Writer);}impl Writable for&str{fn write(&self,writer:&mut Writer){for chunk in self.as_bytes().chunks(Writer::BUF_SIZE){writer.write_bytes(chunk);}}}impl Writable for String{fn write(&self,writer:&mut Writer){for chunk in self.as_bytes().chunks(Writer::BUF_SIZE){writer.write_bytes(chunk);}}}impl<T:Writable>Writable for Vec<T>{fn write(&self,writer:&mut Writer){for(i,value)in self.iter().enumerate(){if i!=0{writer.write_char(' ');}writer.write(value);}}}macro_rules!write_unsigned{($t:ty)=>{impl Writable for$t{fn write(&self,writer:&mut Writer){if self==&0{writer.write_char('0');return;}let mut buf=[0;<$t as Integer>::BASE_10_LEN];let mut index=buf.len();let mut value=*self;while value!=0{index-=1;buf[index]=(value%10)as u8+b'0';value/=10;}writer.write_bytes(&buf[index..]);}}};}macro_rules!write_signed{($t:ty)=>{impl Writable for$t{fn write(&self,writer:&mut Writer){if self<&0{writer.write_char('-');}writer.write(&self.unsigned_abs());}}};}write_signed!(i8);write_signed!(i16);write_signed!(i32);write_signed!(i64);write_signed!(i128);write_signed!(isize);write_unsigned!(u8);write_unsigned!(u16);write_unsigned!(u32);write_unsigned!(u64);write_unsigned!(u128);write_unsigned!(usize);macro_rules!write_tuple{($t1:ident,$($t:ident),*)=>{impl<$t1:Writable,$($t:Writable,)*>Writable for($t1,$($t,)*){fn write(&self,writer:&mut Writer){#[allow(non_snake_case)]let($t1,$($t,)*)=self;writer.write($t1);$(writer.write_char(' ');writer.write($t);)*}}}}write_tuple!(A,B);write_tuple!(A,B,C);write_tuple!(A,B,C,D);write_tuple!(A,B,C,D,E);write_tuple!(A,B,C,D,E,F);write_tuple!(A,B,C,D,E,F,G);write_tuple!(A,B,C,D,E,F,G,H);}pub use output_macro::make_output_macro;pub use reader::{Readable,Reader};pub use writer::{Writable,Writer};#[macro_export]macro_rules!__cargo_equip_macro_def_rlib_io_make_io{($reader:ident,$writer:ident)=>{#[allow(unused_variables)]let mut$reader=rlib_io::reader::Reader::new(Box::new(std::io::stdin().lock()));#[allow(unused_variables)]let mut$writer=rlib_io::writer::Writer::new(Box::new(std::io::stdout().lock()));rlib_io::output_macro::make_output_macro!($writer);};}macro_rules!make_io{($($tt:tt)*)=>(crate::__cargo_equip_macro_def_rlib_io_make_io!{$($tt)*})}}
        pub mod rlib_mint {use crate::__cargo_equip::preludes::rlib_mint::*;use std::ops::*;use rlib_io::*;#[derive(Copy,Clone,PartialEq,Eq)]pub struct Modular<const M:i32>{v:i32,}impl<const M:i32>Modular<M>{pub const ZERO:Self=Self{v:0};pub const ONE:Self=Self{v:1};pub fn new(v:i64)->Self{let mut v=(v%M as i64)as i32;if v<0{v+=M;}Self{v}}pub fn inv(&self)->Self{let mut a=self.v;let mut b=M;let mut x=0;let mut y=1;while a!=0{let k=b/a;b-=k*a;x-=k*y;std::mem::swap(&mut a,&mut b);std::mem::swap(&mut x,&mut y);}Self::new(x as i64)}pub fn md()->i32{M}}impl<const M:i32>Add for Modular<M>{type Output=Self;fn add(self,rhs:Self)->Self{let mut v=self.v+rhs.v;if v>=M{v-=M;}Self{v}}}impl<const M:i32>AddAssign for Modular<M>{fn add_assign(&mut self,rhs:Self){*self=*self+rhs;}}impl<const M:i32>Sub for Modular<M>{type Output=Self;fn sub(self,rhs:Self)->Self{let mut v=self.v-rhs.v;if v<0{v+=M;}Self{v}}}impl<const M:i32>SubAssign for Modular<M>{fn sub_assign(&mut self,rhs:Self){*self=*self-rhs;}}impl<const M:i32>Mul for Modular<M>{type Output=Self;fn mul(self,rhs:Self)->Self{Self::new(self.v as i64*rhs.v as i64)}}impl<const M:i32>MulAssign for Modular<M>{fn mul_assign(&mut self,rhs:Self){*self=*self*rhs;}}impl<const M:i32>Div for Modular<M>{type Output=Self;fn div(self,rhs:Self)->Self{self*rhs.inv()}}impl<const M:i32>DivAssign for Modular<M>{fn div_assign(&mut self,rhs:Self){*self=*self/rhs;}}impl<const M:i32>Neg for Modular<M>{type Output=Self;fn neg(self)->Self{let mut v=-self.v;if v<0{v+=M;}Self{v}}}impl<const M:i32>Readable for Modular<M>{fn read(reader:&mut Reader)->Self{Self::new(reader.read())}}impl<const M:i32>Writable for Modular<M>{fn write(&self,writer:&mut Writer){self.v.write(writer)}}impl<const M:i32>std::fmt::Display for Modular<M>{fn fmt(&self,f:&mut std::fmt::Formatter)->std::fmt::Result{self.v.fmt(f)}}impl<const M:i32>std::fmt::Debug for Modular<M>{fn fmt(&self,f:&mut std::fmt::Formatter)->std::fmt::Result{self.v.fmt(f)}}pub type Mint998=Modular<998244353>;pub type Mint107=Modular<1000000007>;}
    }

    pub(crate) mod macros {
        pub mod rlib_integer {}
        pub mod rlib_io {pub use crate::{__cargo_equip_macro_def_rlib_io_make_io as make_io,__cargo_equip_macro_def_rlib_io_make_output_macro_ as make_output_macro_,__cargo_equip_macro_def_rlib_io_out_impl as out_impl};}
        pub mod rlib_mint {}
    }

    pub(crate) mod prelude {pub use crate::__cargo_equip::crates::*;}

    mod preludes {
        pub mod rlib_integer {}
        pub mod rlib_io {pub(in crate::__cargo_equip)use crate::__cargo_equip::crates::rlib_integer;}
        pub mod rlib_mint {pub(in crate::__cargo_equip)use crate::__cargo_equip::crates::rlib_io;}
    }
}