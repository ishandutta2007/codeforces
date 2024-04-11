#[allow(unused_imports)]
use std::{io, mem};

fn main() {
    let mut s : String = String::new();

    io::stdin().read_line(&mut s).expect("Oops");

    let t : u32 = s.trim().parse().expect("Oops");

    eprintln!("t = {}", t);

    for _test in 1..t+1 {
        let mut s : String = String::new();

        io::stdin().read_line(&mut s).expect("Oops");

        let mut s = s.trim().split_whitespace();

        let mut a : i64 = s.next().expect("Oops").parse().expect("Oops");
        let mut b : i64 = s.next().expect("Oops").parse().expect("Oops");
        let mut c : i64 = s.next().expect("Oops").parse().expect("Oops");

        if a > b {
            mem::swap(&mut a, &mut b);
        }
        if a > c {
            mem::swap(&mut a, &mut c);
        }
        if b > c {
            mem::swap(&mut b, &mut c);
        }

        let d = c;
        println!("{}", d);
    }
}