/*
    author:  Maksim1744
    created: 08.10.2020 18:20:38
*/

#[allow(unused_imports)]
use std::{io, collections::*};

fn test_case(_test: &i32, io: &mut IO) {
    let n: usize = io.read();
    let m: usize = io.read();

    let v: Vec<Vec<i64>> = io.readv2(n, m);
    let mut total: i64 = 0;

    for i in 0..n as usize {
        if i > n - i - 1 {
            break;
        }
        for j in 0..m as usize {
            if j > m - j - 1 {
                break;
            }
            let mut coords = vec![(i, j)];
            coords.push((n - i - 1, j));
            coords.push((i, m - j - 1));
            coords.push((n - i - 1, m - j - 1));
            coords.sort();
            coords.dedup();

            let mut vals: Vec<i64> = Vec::new();

            for &(x, y) in coords.iter() {
                vals.push(v[x][y]);
            }

            vals.sort();
            let mid = vals[vals.len() / 2];
            for item in vals {
                total += (item - mid).abs();
            }
        }
    }
    io.debugv2(&v, Some("v"));
    io.debugv(&v[0], Some("v[0]"));

    println!("{}", total);
}

fn main() {
    let mut io = IO::new();
    let t = io.read::<i32>();
    // let t = 1;
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