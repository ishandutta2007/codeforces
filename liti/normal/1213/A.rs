use std::io::stdin;
use std::cmp::min;

fn readl() -> Vec<String> {
    let mut s = String::new();
    stdin().read_line(&mut s).expect("");
    s.trim().split(" ").map(|x| x.to_string()).collect()
}

fn main() {
    let n: u32 = readl()[0].parse().expect("");
    let ans: u32 = readl()
        .iter()
        .map(|x| x.parse().expect(""))
        .map(|x: u32| x % 2)
        .sum();

    println!("{}", min(ans, n - ans));
}