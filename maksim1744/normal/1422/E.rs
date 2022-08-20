/*
    author:  Maksim1744
    created: 08.10.2020 22:53:03
*/

#[allow(unused_imports)]
use std::{
    io::{self, prelude::*},
    collections::*,
    cmp::{min, max},
    time::{Instant},
    fmt::Write,
};

fn shrink(s: &[u8]) -> Vec<u8> {
    if s.len() <= 10 {
        s.to_vec()
    } else {
        [&s[0..5], &vec![b'.'; 3], &s[s.len() - 2..s.len()]].concat()
    }
}

fn test_case(_test: &i32, io: &mut IO) {
    macro_rules! output { ($($args:expr),+) => { write!(&mut io.out_buf, $($args),+).unwrap(); }; }

    let now = Instant::now();
    let s = io.reads();
    io.debugs(&s, "s");
    let d = now.elapsed();
    eprintln!("input: {}", d.as_secs() as f64 + d.subsec_nanos() as f64 * 1e-9);

    let mut next_dif = vec![s.len(); s.len()];
    for i in (0..s.len() - 1).rev() {
        if s[i] == s[i + 1] {
            next_dif[i] = next_dif[i + 1];
        } else {
            next_dif[i] = i + 1;
        }
    }
    io.debug(&next_dif, "next_dif");

    let mut res: Vec<((u8, u8), Vec<u8>)> = vec![((b'$', b'$'), Vec::new()); s.len()];
    let mut res_sz = vec![0; s.len()];

    for i in (0..s.len()).rev() {
        if next_dif[i] == s.len() {
            if (s.len() - i) % 2 == 1 {
                res[i].1.push(s[i]);
                res_sz[i] = 1;
                (res[i].0).0 = s[i];
            }
        } else {
            if (res[next_dif[i]].0).0 < s[i] || ((res[next_dif[i]].0).0 == s[i] && (res[next_dif[i]].0).1 < s[i]) {
                if (next_dif[i] - i) % 2 == 1 {
                    res[i].0 = (s[i], (res[next_dif[i]].0).0);
                    if s[i] == (res[next_dif[i]].0).0 {
                        (res[i].0).1 = (res[next_dif[i]].0).1;
                    }
                    res[i].1 = shrink([&s[i..i+1], res[next_dif[i]].1.as_slice()].concat().as_slice());
                    res_sz[i] = 1 + res_sz[next_dif[i]];
                } else {
                    res[i] = res[next_dif[i]].clone();
                    res_sz[i] = res_sz[next_dif[i]];
                }
            } else {
                res[i].0 = (s[i], s[next_dif[i]]);
                res[i].1 = shrink([&s[i..min(i + 10, next_dif[i])], res[next_dif[i]].1.as_slice()].concat().as_slice());
                res_sz[i] = next_dif[i] - i + res_sz[next_dif[i]];
            }
        }
    }
    let d = now.elapsed();
    eprintln!("calculation: {}", d.as_secs() as f64 + d.subsec_nanos() as f64 * 1e-9);


    let now = Instant::now();
    for i in 0..s.len() {
        output!("{} {}", res_sz[i], std::str::from_utf8(&res[i].1).unwrap());
        output!("\n");
    }
    let d = now.elapsed();
    eprintln!("output: {}", d.as_secs() as f64 + d.subsec_nanos() as f64 * 1e-9);
}

fn main() {
    let now = Instant::now();

    let mut io = IO::new();

    // let t = io.read::<i32>();
    let t = 1;
    for test in 1..t + 1 {
        test_case(&test, &mut io);
    }

    io.flush();

    let d = now.elapsed();
    eprintln!("total: {}", d.as_secs() as f64 + d.subsec_nanos() as f64 * 1e-9);
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