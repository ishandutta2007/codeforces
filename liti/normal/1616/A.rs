use std::io::stdin;
use std::str::FromStr;
use std::fmt::Debug;


fn readl<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().split(" ").map(|x| x.parse().unwrap()).collect()
}

use std::collections::HashMap;
use std::cmp::min;

fn solve() {
    let _: u32 = readl()[0];
    let a: Vec<i32> = readl();

    let mut cnt = HashMap::new();

    for item in a {
        *cnt.entry(item.abs()).or_insert(0) += 1;
    }

    let mut ans: u32 = 0;

    for (key, val) in cnt {
        if key == 0 {
            ans += min(val, 1);
        } else {
            ans += min(val, 2);
        }
    }

    println!("{}", ans);
}

fn main() {
    let t: u32 = readl()[0];
    for _ in 0..t {
        solve();
    }
}