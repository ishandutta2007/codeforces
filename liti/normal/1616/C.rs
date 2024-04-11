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

    let mut ans = n-1;

    for i in 0..n {
        for j in i+1..n {
            let mut good = 2;
            let dis: i32 = j as i32 - i as i32;
            for k in j+1..n {
                if (k-i) as i32 * (a[j] - a[i]).abs() % dis == 0 {
                    if a[k] == a[i] + (k-i) as i32 * (a[j] - a[i]) / dis {
                        good += 1;
                    }
                }
            }
            ans = ans.min(n - good);
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