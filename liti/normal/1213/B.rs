use std::io::stdin;

fn readl() ->  Vec<i32> { 
	let mut buf = String::new();
	stdin().read_line(&mut buf).unwrap();
	buf.trim().split(" ").map(|x| x.parse().unwrap()).collect()
}

fn main() {
	let tests = readl()[0];

	for _ in 0..tests {
		let _ = readl()[0];
		let a = readl();

		let mut mn: i32 = 1e9 as i32;
		let mut ans = 0;
		for &x in a.iter().rev() {
			if x > mn { 
				ans += 1;
			} else { 
				mn = x;
			}
		}
		println!("{}", ans);
	}
}