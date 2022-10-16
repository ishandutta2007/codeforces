use std::io::*;
use std::str::FromStr;

fn main() {
    let stdin = stdin();
    let mut sc = Scanner::new(stdin.lock());
    let stdout = stdout();
    let mut wr = BufWriter::new(stdout.lock());

    let n = sc.next::<usize>();
    let mut easy = true;

    for _ in 0..n {
        let a = sc.next::<usize>();

        if a == 1 {
            easy = false;
            break;
        }
    }

    if easy{
        writeln!(wr, "EASY").unwrap();
    }
    else {
        writeln!(wr, "HARD").unwrap();
    }
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