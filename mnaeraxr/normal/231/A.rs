use std::io::*;
use std::str::FromStr;

fn main() {
    let stdin = stdin();
    let mut sc = Scanner::new(stdin.lock());
    let stdout = stdout();

    let n = sc.next::<i32>();

    let mut answer = 0;

    for i in 0..n{
        let mut cur = 0;

        for _ in 0..3{
            let s = sc.next::<i32>();
            cur = cur + s;
        }

        if cur >= 2 {
            answer += 1;
        }
    }

    println!("{}", answer);
}

pub struct Scanner<B> {
    reader: B,
    buffer: Vec<String>,
}

impl<B: BufRead> Scanner<B> {
    pub fn new(reader: B) -> Self {
        Self {
            reader,
            buffer: Vec::new(),
        }
    }

    pub fn next<T: FromStr>(&mut self) -> T
    where
        T::Err: ::std::fmt::Debug,
    {
        if let Some(front) = self.buffer.pop() {
            front.parse::<T>().expect(&front)
        } else {
            let mut input = String::new();
            self.reader.read_line(&mut input).expect("Line not read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
            self.next()
        }
    }
}