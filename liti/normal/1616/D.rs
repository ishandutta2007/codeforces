use std::io::stdin;
use std::str::FromStr;
use std::fmt::Debug;


fn readl<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().split(" ").map(|x| x.parse().unwrap()).collect()
}

fn solve() {
    let n: usize = readl()[0];
    let a: Vec<i32> = readl();
    let x: i32 = readl()[0];

    let mut ans = 0;

    let mut cur = vec![];

    for i in 0..n {
        if a[i] >= x {
            if cur.len() > 0 && cur[cur.len()-1] + a[i] < 2*x {
                ans += cur.len();
                cur.clear();
            } else {
                cur.push(a[i]);
            }
        } else {
            if cur.len() == 0 || (cur[cur.len()-1] + a[i] >= 2*x && (cur.len() == 1 || cur[cur.len()-1] + cur[cur.len()-2] + a[i] >= 3*x)) {
                cur.push(a[i]);
            } else {
                ans += cur.len();
                cur.clear();
            }
        }
    }

    ans += cur.len();


    println!("{}", ans);
}

fn main() {
    let t: u32 = readl()[0];
    for _ in 0..t {
        solve();
    }
}