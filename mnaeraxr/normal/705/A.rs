use std::io::*;
use std::str::FromStr;

fn main() {
    let stdin = stdin();
    let mut sc = Scanner::new(stdin.lock());
    let stdout = stdout();

    // Code here...

    let p = sc.next::<i32>();

    for i in 0..p{
        let mut pron = String::new();
        let mut action = String::new();

        if i + 1 == p {
            pron = "it\n".to_string();
        }
        else{
            pron = "that ".to_string();
        }

        if i % 2 == 0 {
            action = "hate".to_string();
        }
        else{
            action = "love".to_string();
        }

        print!("I {} {}", action, pron);
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