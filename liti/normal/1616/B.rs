use std::io::stdin;
use std::str::FromStr;
use std::fmt::Debug;


fn readl<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().split(" ").map(|x| x.parse().unwrap()).collect()
}

fn pr(s: &str) {
    println!("{}{}", s, s.chars().rev().collect::<String>());
}

fn solve() {
    let n: usize = readl()[0];
    let s: &String = &readl()[0];

    let a: Vec<char> = s.chars().collect();

    let mut changed = false;

    for i in 0..n {
        if i == n-1 {
            pr(&s[..]);
        } else if a[i] < a[i+1] {
            pr(&s[0..i+1]);
            break;
        } else if a[i] == a[i+1] && !changed {
            pr(&s[0..i+1]);
            break;
        } else {
            changed = true;
        }
    }
}

//cbaa
//cbaaaabc
//cbaabc
fn main() {
    let t: u32 = readl()[0];
    for _ in 0..t {
        solve();
    }
}