/*
    author:  Maksim1744
    created: 11.10.2020 12:29:12
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

    let n: usize = io.read();
    let mut s = io.reads();
    let mut wh: Vec<Vec<usize>> = vec![Vec::new(); 26];
    for i in 0..n {
        s[i] -= b'a';
        wh[s[i] as usize].push(i);
    }
    for i in 0..26 {
        wh[i].reverse();
    }
    let mut total: i64 = 0;

    let mut fenw: Vec<usize> = vec![0; n];
    let gets_int = |r: usize, f: &mut Vec<usize>| -> usize {
        let mut r = r as i32;
        let mut res: usize = 0;
        while r >= 0 {
            res += f[r as usize];
            r = (r & (r + 1)) - 1;
        }
        res
    };
    let gets = |l: usize, r: usize, f: &mut Vec<usize>| -> usize {
        if l > r {
            return 0;
        }
        let mut res = gets_int(r, f);
        if l != 0 {
            res -= gets_int(l - 1, f);
        }
        res
    };
    let inc = |mut i: usize, f: &mut Vec<usize>| {
        while i < n {
            f[i] += 1;
            i = i | (i + 1);
        }
    };

    s.reverse();
    for i in 0..n {
        let b = s[i] as usize;
        let pos = wh[b].pop().unwrap();
        total += (pos + gets(pos + 1, n - 1, &mut fenw) - i) as i64;
        inc(pos, &mut fenw);
    }
    output!("{}\n", total);
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