use std::io;
use std::fmt::Debug;

fn get_line<T: std::str::FromStr>() -> T where <T as std::str::FromStr>::Err: Debug {
    let mut s = String::new();
    io::stdin()
        .read_line(&mut s)
        .expect("Failed to read line");
    let x: T = s.trim().parse().unwrap();
    x
}

fn main() {
    let t: i32 = get_line();

    for _t in 0..t {
        let n: i64 = get_line();

        if n < 4 || n % 2 == 1 {
            println!("-1");
            continue;
        }

        println!("{} {}", (n+4)/6, n/4);
    }
}