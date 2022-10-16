mod fastio {
    use core::fmt;
    use std::io;
    use std::io::{BufRead, StdoutLock, Write};

    pub trait TokenStream<T> {
        fn token(&mut self) -> T;
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
           fn token(&mut self) -> $t {
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

//pub struct FastIO<'o, R> {
//    fast_input: FastInput<R>,
//    fast_output: io::BufWriter<StdoutLock<'o>>,
//}
//
//impl<'o, R> FastIO<'o, R> {
//    fn token(&mut self) -> R {
//        self.fast_input.token()
//    }
//
//    fn write(&mut self, word: fmt::Arguments<'_>) {
//        self.fast_output.write_fmt(word).unwrap()
//    }
//}
}
mod solution {
    use core::fmt;
    use std::io;
    use std::io::{stdin, BufRead, StdoutLock, Write};
    use std::ops::{AddAssign, SubAssign};

    use super::fastio::{FastInput, TokenStream};
    use super::znum::ZNum;

    fn solve<R: BufRead, W: Write>(mut input: FastInput<R>, mut w: W) {
        let n = input.token();
        let q = input.token();

        let mut a = ZNum::new(0, n);
        let mut b = ZNum::new(1, n);

        for _ in 0..q {
            let m: usize = input.token();

            if m == 1 {
                let x = input.token();
                a += x;
                b += x;
            } else {
                if a.value % 2 == 0 {
                    a += 1;
                    b -= 1;
                } else {
                    a -= 1;
                    b += 1;
                }
            }
        }

        let mut positions = vec![0; n as usize];

        for (u, v) in (0..n / 2).map(|i| (2 * i, 2 * i + 1)) {
            positions[a.value as usize] = u;
            positions[b.value as usize] = v;
            a += 2;
            b += 2;
        }

        for p in positions.into_iter() {
            write!(w, "{} ", p + 1);
        }
        write!(w, "\n");
    }

    pub fn main() {
        let stdin = io::stdin();
        let stdout = io::stdout();
        let input = FastInput::from(stdin.lock());
        let writer = io::BufWriter::new(stdout.lock());
        solve(input, writer);
    }
}
mod znum {
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
fn main() { solution::main(); }