use std::io;
use std::str;
use std::cmp::{min, max};

pub struct Scanner<R> {
    reader: R,
    buffer: Vec<String>,
}

impl<R: io::BufRead> Scanner<R> {
    pub fn new(reader: R) -> Self {
        Self {
            reader,
            buffer: vec![],
        }
    }

    pub fn read<T: str::FromStr>(&mut self) -> T {
        loop {
            if let Some(x) = self.buffer.pop() {
                return x.parse().ok().unwrap();
            }
            let mut input = String::new();
            self.reader.read_line(&mut input).unwrap();
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

macro_rules! input_internal {
    ($in: ident, $x: ident) => {
        let $x: i64 = $in.read();
    };

    ($in: ident, $x: ident, $($y: ident),+) => {
        let $x: i64 = $in.read();
        input_internal!($in, $($y),+)
    }
}

macro_rules! input {
    ($($xs: ident) +) => {
        let stdin = io::stdin();
        let mut scanner = Scanner::new(stdin.lock());
        input_internal!(scanner, $($xs),+);
        drop(scanner);
    }
}

fn main() {
    input!(t);
    for _ in 0..t {
        input!(n m);
        println!(
            "{}",
            match (n, m) {
                (1, 1) => 0,
                _ => (n + m - 1)*2 - max(n, m),
            }
        );
    }
}