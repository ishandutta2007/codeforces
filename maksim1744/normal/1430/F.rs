/*
    author:  Maksim1744
    created: 11.10.2020 13:20:30
*/

#[allow(unused_imports)]
use std::{
    io,
    collections::*,
    cmp::{min, max},
    time::{Instant},
    fmt::Write,
};


const INF: i64 = 4_000_000_000_000_000_000;

fn test_case(_test: &i32, io: &mut IO) {
    macro_rules! output { ($($args:expr),+) => { write!(&mut io.out_buf, $($args),+).unwrap(); }; }

    let mut n: usize = io.read();
    let m: i64 = io.read();
    let mut ls: Vec<i64> = Vec::new();
    let mut rs: Vec<i64> = Vec::new();
    let mut a: Vec<i64> = Vec::new();
    for _i in 0..n {
        ls.push(io.read());
        rs.push(io.read());
        a.push(io.read());
    }

    ls.push(1_000_000_100);
    rs.push(1_000_000_120);
    a.push(1);
    n += 1;

    let mut ans = INF;

    let mut dp: Vec<i64> = vec![INF; n];
    dp[0] = 0;
    for i in 0..n {
        let mut cur: i64 = m;
        let mut curdp: i64 = dp[i];
        for j in i..n - 1 {
            let have1 = rs[j] - ls[j] + 1;
            let have2 = ls[j + 1] - ls[j] + 1;
            let mut need: i64 = 0;
            if cur >= a[j] {
                cur -= a[j];
                need += 1;
            } else {
                let aa = a[j] - cur;
                need += 1;
                need += (aa + m - 1) / m;
                cur = (m - aa % m) % m;
            }
            if need > have1 {
                break;
            }
            curdp += a[j];
            if need < have2 {
                dp[j + 1] = min(dp[j + 1], curdp + cur);
                if j + 2 == dp.len() {
                    ans = min(ans, curdp);
                }
            }
        }
    }
    io.debug(&dp, "dp");

    if ans >= INF {
        ans = -1;
    }
    output!("{}\n", ans);
}

fn main() {
    #[cfg(HOME)]
    let now = Instant::now();

    let mut io = IO::new();

    // let t = io.read::<i32>();
    let t = 1;
    for test in 1..t + 1 {
        test_case(&test, &mut io);
    }

    io.flush();

    #[cfg(HOME)] {
        let d = now.elapsed();
        eprintln!("total: {}", d.as_secs() as f64 + d.subsec_nanos() as f64 * 1e-9);
    }
}

// ********************************************************************************

#[allow(dead_code)]
struct IO {
    buf: std::collections::VecDeque<String>,
    out_buf: String,
}
#[allow(dead_code)]
impl IO {
    fn new() -> IO {
        IO {
            buf: std::collections::VecDeque::new(),
            out_buf: String::new(),
        }
    }

    fn flush(&mut self) {
        print!("{}", self.out_buf);
        self.out_buf.clear();
    }

    fn read<T: std::str::FromStr>(&mut self) -> T {
        while self.buf.is_empty() {
            let mut s = String::new();
            io::stdin().read_line(&mut s).expect("Can't read a line");
            self.buf.extend(s.trim().split(" ").map(|x| x.to_string()));
        }
        self.buf.pop_front().unwrap().parse().ok().unwrap()
    }
    fn readv<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T> {
        let mut res = Vec::new();
        for _i in 0..n {
            res.push(self.read());
        }
        res
    }
    fn readv2<T: std::str::FromStr>(&mut self, n: usize, m: usize) -> Vec<Vec<T>> {
        let mut res = Vec::new();
        for _i in 0..n {
            res.push(self.readv(m));
        }
        res
    }
    fn reads(&mut self) -> Vec<u8> {
        self.read::<String>().as_bytes().to_vec()
    }

    fn debug<T: std::fmt::Debug>(&mut self, _val: &T, _name: &str) {
        #[cfg(HOME)]
        {
            eprint!("    ");
            eprint!("{}", match _name {
                "" => "<val>",
                x => x
            });
            eprintln!(" = {:?}", _val);
        }
    }
    fn debugs(&mut self, _val: &Vec<u8>, _name: &str) {
        #[cfg(HOME)]
        {
            eprint!("    ");
            eprint!("{}", match _name {
                "" => "<val>",
                x => x
            });
            eprintln!(" = {:?}", std::str::from_utf8(_val).unwrap());
        }
    }
}