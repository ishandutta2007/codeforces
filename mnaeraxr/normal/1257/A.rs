pub mod algorithms {
    pub mod znum {
        use std::ops::{AddAssign, SubAssign};

        #[derive(Debug)]
        pub struct ZNum {
            z: u64,
            pub value: u64,
        }

        impl ZNum {
            pub fn new(value: u64, z: u64) -> Self {
                Self { z, value }
            }

            fn base_add(&mut self, mut rhs: u64) {
                if rhs >= self.z {
                    rhs %= self.z;
                }

                self.value += rhs;
                if self.value >= self.z {
                    self.value -= self.z;
                }
            }
        }

        impl AddAssign<i64> for ZNum {
            fn add_assign(&mut self, mut rhs: i64) {
                if rhs < 0 {
                    if rhs <= -(self.z as i64) {
                        rhs %= self.z as i64;
                    }
                    rhs += self.z as i64;
                }
                self.base_add(rhs as u64);
            }
        }

        impl SubAssign<i64> for ZNum {
            fn sub_assign(&mut self, rhs: i64) {
                self.add_assign(-rhs);
            }
        }
    }

    pub mod fastio {
        use std::io::{BufRead, BufWriter, StdinLock, StdoutLock};

        pub trait TokenStream<T> {
            fn next(&mut self) -> T;
        }

        pub struct FastInput<R> {
            stdin: R,
            pos: usize,
        }

        impl<R: BufRead> From<R> for FastInput<R> {
            fn from(r: R) -> Self {
                FastInput { stdin: r, pos: 0 }
            }
        }

        macro_rules! impl_token_stream {
    ($($t:ident),+) => {$(
        impl<R: BufRead> TokenStream<$t> for FastInput<R> {
           fn next(&mut self) -> $t {
                let mut ans = 0;
                let mut sign = 1;
                let mut parse_token = false;
                loop {
                    if let Ok(buf) = self.stdin.fill_buf() {
                        if !parse_token {
                            // Ignore invalid characters
                            while self.pos < buf.len() && buf[self.pos] <= 32 {
                                self.pos += 1;
                            }
                        }
                        while self.pos < buf.len() && buf[self.pos] > 32 {
                            parse_token = true;
                            if buf[self.pos] == 45 {
                                sign = 0 as $t - 1 as $t;
                            } else {
                                ans = ans * 10 + (buf[self.pos] - b'0') as $t;
                            }
                            self.pos += 1;
                        }
                        if self.pos != buf.len() || self.pos == 0 {
                            return ans * sign;
                        }
                    }
                    self.stdin.consume(self.pos);
                    self.pos = 0;
                }
           }
        }
    )+}
}

        impl_token_stream!(usize);
        impl_token_stream!(i64);
        impl_token_stream!(u64);
        impl_token_stream!(i32);

        pub type Cin<'a> = FastInput<StdinLock<'a>>;
        pub type Cout<'a> = BufWriter<StdoutLock<'a>>;
    }

    pub mod nt {
        /// Return list sieve
        /// sieve[p] iff p is prime
        pub fn sieve(n: usize) -> Vec<bool> {
            let mut is_prime = vec![true; n];
            is_prime[0] = false;
            is_prime[1] = false;

            for u in 2.. {
                if !is_prime[u] {
                    continue;
                }

                let mut v = u * u;

                if v >= n {
                    break;
                }

                while v < n {
                    is_prime[v] = false;
                    v += u;
                }
            }

            is_prime
        }

        pub fn linear_sieve(n: usize) -> Vec<bool> {
            let mut is_prime = vec![true; n];
            is_prime[0] = false;
            is_prime[1] = false;

            let mut primes = vec![];

            for u in 2..n {
                if is_prime[u] {
                    primes.push(u);
                }

                for &p in primes.iter() {
                    let t = p * u;
                    if t >= n {
                        break;
                    }

                    is_prime[t] = false;

                    if u % p == 0 {
                        break;
                    }
                }
            }

            is_prime
        }

        /// Find list of prime number among natural numbers between [0, n)
        pub fn primes(n: usize) -> Vec<usize> {
            sieve(n)
                .iter()
                .enumerate()
                .filter_map(|(num, &prime)| if prime { Some(num) } else { None })
                .collect()
        }

        pub fn is_prime(n: usize) -> bool {
            !(2usize..).take_while(|&u| u * u <= n).any(|u| n % u == 0)
        }

        #[cfg(test)]
        mod test {
            use super::{linear_sieve, sieve};

            #[test]
            fn simple() {
                let res_0 = sieve(10000);
                let res_1 = linear_sieve(10000);
                assert_eq!(res_0, res_1);
            }
        }
    }
}

pub mod solution {
    use std::io;
    use std::io::Write;

    use crate::algorithms::fastio::{Cin, Cout, FastInput, TokenStream};
    use std::cmp::{max, min};

    fn abs(u: i32) -> i32 {
        max(u, -u)
    }

    ///
    /// ```
    ///    let n: usize = cin.next();
    ///    let m: usize = cin.next();
    ///
    ///    writeln!(cout, "{:?}", primes(n));
    /// ```
    fn solve(mut cin: Cin, mut cout: Cout) {
        let t: usize = cin.next();

        for _ in 0..t {
            let n: i32 = cin.next();
            let x: i32 = cin.next();
            let a: i32 = cin.next();
            let b: i32 = cin.next();

            let ans = min(n - 1, abs(b - a) + x);
            writeln!(cout, "{}", ans);
        }
    }

    pub fn main() {
        let stdin = io::stdin();
        let stdout = io::stdout();
        let cin: Cin = FastInput::from(stdin.lock());
        let cout: Cout = io::BufWriter::new(stdout.lock());
        solve(cin, cout);
    }
}

fn main() {
    solution::main();
}