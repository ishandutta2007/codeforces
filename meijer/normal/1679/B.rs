use std::io;
use std::fmt::Debug;
use std::iter::FromIterator;
use std::convert::TryInto;

macro_rules! read {
    ( $($type: ty ),* ) => {
        {
            let mut line = String::new();
            io::stdin()
                .read_line(&mut line)
                .expect("Failed to read line");

            let words: Vec<String> = line.split(" ")
                .map(|x| x.to_string())
                .collect();

            let mut iter = words.iter();
            ($(
                iter.next()
                .expect("not enough words in line")
                .trim().parse::<$type>().unwrap()
            ),*)
        }
    };
}

fn read_vec<T: std::str::FromStr>() -> Vec<T> where <T as std::str::FromStr>::Err: Debug {
    let mut line = String::new();
    io::stdin()
        .read_line(&mut line)
        .expect("Failed to read line");

    line.split(" ")
        .map(|x| x.trim().parse::<T>().unwrap())
        .collect()
}

// program

fn main() {
    let (n, q) = read!(i64, usize);
    let mut a: Vec<i64> = read_vec();
    let mut changed: Vec<usize> = Vec::from_iter(0..(n.try_into().unwrap()));

    let mut delta: i64 = 0;
    let mut total: i64 = a.iter().sum();

    for _ in 0..q {
        let b: Vec<i64> = read_vec();
        if b[0] == 1 {
            let i: usize = (b[1] - 1).try_into().unwrap();
            total += b[2] - delta - a[i];
            a[i] = b[2] - delta;
            changed.push(i);
        }
        if b[0] == 2 {
            total += n * (b[1] - delta);
            for i in &changed {
                total -= a[*i];
                a[*i] = 0;
            }
            delta = b[1];
            changed.clear();
        }

        println!("{total}");
    }
}