use std::io;

pub fn main() {
    let numbers = read_numbers();
    let n = numbers[0];
    let l = numbers[1] - 1;
    let r = numbers[2] - 1;

    let a = read_numbers();
    let b = read_numbers();

    let mut x = vec![0; n as usize];

    for i in 0..n {
    	if i < l || i > r {
    		if a[i as usize] != b[i as usize] {
    			println!("LIE");
    			return;
    		}
    	} else {
    		x[(a[i as usize] - 1) as usize] += 1;
    		x[(b[i as usize] - 1) as usize] -= 1;
    	}
    }

    for i in 0..n {
    	if x[i as usize] != 0 {
    		println!("LIE");
    		return;
    	}
    }
    println!("TRUTH");
}

pub fn read_numbers() -> Vec<u32> {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();

    line.split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect()
}