
/*
    author:  Maksim1744
    created: 18.10.2020 12:22:55
*/

#[allow(unused_imports)]
use std::{
    io,
    collections::*,
    cmp::{min, max},
    time::{Instant},
    fmt::Write,
};

fn test_case(_test: &i32, io: &mut IO) {
    macro_rules! output { ($($args:expr),+) => { write!(&mut io.out_buf, $($args),+).unwrap(); }; }

    let x: i64 = io.read();
    let y: i64 = io.read();
    let mut c: Vec<i64> = io.readv(6);
    for _j in 0..6 {
        for i in 0..6 {
            c[i] = min(c[i], c[(i + 1) % 6] + c[(i + 5) % 6]);
        }
    }
    let c1 = c[0];
    let c2 = c[1];
    let c3 = c[2];
    let c4 = c[3];
    let c5 = c[4];
    let c6 = c[5];
    let ans: i64;
    if x >= 0 && y >= x {
        ans = c1 * x + c2 * (y - x);
    } else if x >= 0 && y >= 0 {
        ans = c1 * y + c6 * (x - y);
    } else if x >= 0 {
        ans = c6 * x + c5 * -y;
    } else if y >= 0 {
        ans = c3 * -x + c2 * y;
    } else if y >= x {
        ans = c4 * -y + c3 * (-x - (-y));
    } else {
        ans = c4 * -x + c5 * (-y - (-x));
    }
    output!("{}\n", ans);
}

fn main() {
    #[cfg(HOME)]
    let now = Instant::now();

    let mut io = IO::new();

    let t = io.read::<i32>();
    // let t = 1;
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