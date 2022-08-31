/*
    author:  Maksim1744
    created: 08.10.2020 20:35:29
*/

#[allow(unused_imports)]
use std::{
    io,
    collections::*,
    cmp::{min, max},
};

const INF: i64 = 1_000_000_000_000_000_000;

fn test_case(_test: &i32, io: &mut IO) {
    let _n: i32 = io.read();
    let m: i32 = io.read();
    let s: (i64, i64) = (io.read(), io.read());
    let f: (i64, i64) = (io.read(), io.read());
    let mut v: Vec<(i64, i64)> = (0..m).map(|_| (io.read::<i64>(), io.read::<i64>())).collect();
    v.push(s);
    v.sort();
    v.dedup();

    // let mut mxx: HashMap<i64, i64> = HashMap::new();
    // let mut mxy: HashMap<i64, i64> = HashMap::new();
    // let mut mnx: HashMap<i64, i64> = HashMap::new();
    // let mut mny: HashMap<i64, i64> = HashMap::new();

    // for p in v.iter() {
    //     let val = mxx.entry(p.0).or_insert(-INF);
    //     *val = max(*val, p.1);
    //     let val = mnx.entry(p.0).or_insert(INF);
    //     *val = min(*val, p.1);
    //     let val = mxy.entry(p.1).or_insert(-INF);
    //     *val = max(*val, p.0);
    //     let val = mny.entry(p.1).or_insert(INF);
    //     *val = min(*val, p.0);
    // }

    // io.debug(&v, Some("v"));
    // io.debug(&mxx, Some("mxx"));

    let mut g: HashMap<(i64, i64), Vec<(i64, i64)>> = HashMap::new();
    for &p in v.iter() {
        g.insert(p, Vec::new());
    }
    for i in 0..v.len()-1 {
        g.get_mut(&v[i]).unwrap().push(v[i + 1]);
        g.get_mut(&v[i + 1]).unwrap().push(v[i]);
    }
    v.sort_by(|x, y| x.1.cmp(&y.1));
    for i in 0..v.len()-1 {
        g.get_mut(&v[i]).unwrap().push(v[i + 1]);
        g.get_mut(&v[i + 1]).unwrap().push(v[i]);
    }

    // for (pt, v) in g {
    //     eprint!("({}, {}): ", pt.0, pt.1);
    //     for p in v {
    //         eprint!("({}, {}) ", p.0, p.1);
    //     }
    //     eprintln!("")
    // }

    let mut d: HashMap<(i64, i64), i64> = HashMap::new();
    for &p in v.iter() {
        d.insert(p, INF);
    }
    d.insert(s, 0);

    let mut q: VecDeque<(i64, i64)> = VecDeque::new();
    q.push_back(s);
    while !q.is_empty() {
        let v = q.pop_front().unwrap();
        for &p in g.get(&v).unwrap().iter() {
            let dist: i64 = std::cmp::min((p.0 - v.0).abs(), (p.1 - v.1).abs()) as i64;
            if d.get(&p).unwrap() > &(d.get(&v).unwrap() + dist) {
                d.insert(p, d.get(&v).unwrap() + dist);
                q.push_back(p);
            }
        }
    }
    let mut ans: i64 = INF;
    for (p, dist) in d {
        ans = std::cmp::min(ans, dist + ((f.0 - p.0).abs() as i64) + ((f.1 - p.1).abs()) as i64);
    }
    println!("{}", ans);
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
    fn debug<T: std::fmt::Debug>(&mut self, _val: &T, _name: Option<&str>) {
        #[cfg(HOME)]
        {
            eprint!("    ");
            eprint!("{}", match _name {
                Some(x) => x,
                None => "<val>"
            });
            eprintln!(" = {:?}", _val);
        }
    }
}