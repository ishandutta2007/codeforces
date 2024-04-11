/*
    author:  Maksim1744
    created: 08.10.2020 20:04:35
*/

#[allow(unused_imports)]
use std::{io, collections::*};

const MOD: i64 = 1_000_000_007;

fn mpow(mut a: i64, mut p: i64) -> i64 {
    let mut res: i64 = 1;
    while p != 0 {
        if p % 2 == 1 {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        p /= 2;
    }
    res
}

fn test_case(_test: &i32, io: &mut IO) {
    let s = io.reads();

    let mut total: i64 = 0;
    let mut sth: i64 = 0;
    for i in (0..s.len()).rev() {
        let num = (s[i] as i32 - 48) as i64;
        let l = i as i64;
        let r = (s.len() - i - 1) as i64;
        total += l * (l + 1) / 2 % MOD * mpow(10, r) % MOD * num;
        total += sth * num;
        sth = (sth + mpow(10, r) * (r + 1)) % MOD;
    }

    io.debugv(&s, None);
    println!("{}", total % MOD);
}

fn main() {
    let mut io = IO::new();
    // let t = io.read::<i32>();
    let t = 1;
    for test in 1..t + 1 {
        test_case(&test, &mut io);
    }
}

// ********************************************************************************

#[allow(dead_code)]
struct IO {
    buf: std::collections::VecDeque<String>
}
#[allow(dead_code)]
impl IO {
    fn new() -> IO {
        IO {
            buf: std::collections::VecDeque::new()
        }
    }
    fn read<T: std::str::FromStr>(&mut self) -> T {
        while self.buf.is_empty() {
            let mut s = String::new();
            io::stdin().read_line(&mut s).expect("Can't read a line");
            self.buf.extend(s.trim().split(" ").map(|x| String::from(x)));
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
    fn reads(&mut self) -> Vec<char> {
        self.read::<String>().chars().collect()
    }

    fn debug<T: std::string::ToString>(&mut self, _val: &T, _name: Option<&str>) {
        #[cfg(HOME)]
        {
            eprint!("    ");
            eprint!("{}", match _name {
                Some(x) => x,
                None => "<val>"
            });
            eprintln!(" = {}", _val.to_string());
        }
    }
    fn debugv<T: std::string::ToString>(&mut self, _val: &Vec<T>, _name: Option<&str>) {
        #[cfg(HOME)]
        {
            eprint!("    ");
            eprint!("{}", match _name {
                Some(x) => x,
                None => "<val>"
            });
            eprint!(" = [");
            for (i, item) in _val.iter().enumerate() {
                if i != 0 {
                    eprint!(", ");
                }
                eprint!("{}", item.to_string());
            }
            eprintln!("]");
        }
    }
    fn debugv2<T: std::string::ToString>(&mut self, _val: &Vec<Vec<T>>, _name: Option<&str>) {
        #[cfg(HOME)]
        {
            eprint!("    ");
            eprint!("{}", match _name {
                Some(x) => x,
                None => "<val>"
            });
            eprint!(" = [");
            for (i, item) in _val.iter().enumerate() {
                if i != 0 {
                    eprint!(",   ");
                }
                eprint!("[");
                for (j, x) in item.iter().enumerate() {
                    if j != 0 {
                        eprint!(", ");
                    }
                    eprint!("{}", x.to_string());
                }
                eprint!("]");
            }
            eprintln!("]");
        }
    }
}