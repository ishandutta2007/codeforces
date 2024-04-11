use std::io;

fn readl() -> Vec<i64> {
	let mut buf = String::new();
	io::stdin().read_line(&mut buf).unwrap();
	buf.trim().split(" ").map(|x| x.parse().unwrap()).collect()
}

fn main() { 
	let t = readl()[0];
	for _ in 0..t {
		let n = readl();
		let (n, m) = (n[0], n[1]);

		let step = n / m;

		let mut sum: i64 = 0;

		let mut k = 0;
		let mut cnt = 0; 

		loop { 
			cnt += 1;
			sum += k;
			k = (k + m) % 10;

			if k == 0 {
				break;
			}
		}

		let mut ans = sum * (step / cnt);

		let step = step % cnt;
		for _ in 0..step {
			k = (k + m) % 10;
			ans += k;
		}

		println!("{}", ans);
	}
}