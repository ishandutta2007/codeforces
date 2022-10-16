use std::io;

pub fn main() {
    let numbers = read_numbers();
    let n = numbers[0];

    let a = read_numbers();

    let mut lc = 1000000000;
    let mut cc = 1000000000;
    let mut ci = 1000000000;
    for i in 0..n {
        if a[i as usize] == ci {
            cc += 1;
        } else {
            ci = a[i as usize];
            if lc != 1000000000 && cc != lc {
                println!("NO");
                return;
            }
            lc = cc;
            cc = 1;
        }
    }
    if lc != 1000000000 && cc != lc {
        println!("NO");
        return;
    }
    println!("YES");
}

pub fn read_numbers() -> Vec<u32> {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();

    line.split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect()
}