use std::io::*;
use std::str::FromStr;
use std::cmp::max;

#[derive(Debug)]
struct Node{
    a : i64,
    b : i64,
    c : i64
}

impl Node {
    fn clone(&self) -> Node {
        Node {..*self}
    }
}

fn merge(A : &Node, B : &Node) -> Node {
    let ans : Node;
    if A.c < 0 {
        ans = B.clone();
    }
    else{
        ans = Node {
            a : max(A.a, B.a),
            b : max(A.b, B.b),
            c : max(max(A.c, B.c), A.b + B.a)
        };
    }

    // println!("{:?}", A);
    // println!("{:?}", B);
    // println!("{:?}", ans);

    ans
}

#[derive(Debug)]
struct SegmentTree{
    st: Vec<Node>
}

impl SegmentTree {
    fn new(n: i32) -> SegmentTree{
        let mut s = SegmentTree {
            st : Vec::new()
        };

        for i in 0..4 * n {
            s.st.push(Node {a : 0, b : 0, c : 0});
        }

        s
    }

    fn build(&mut self, p: usize, b: usize, e: usize, H: &Vec<i64>, D: &Vec<i64>){
        if b + 1 == e {
            self.st[p] = Node {a : H[b] + D[b], b : H[b] - D[b], c : 0};
        }
        else {
            let m = (b + e) >> 1;
            let l = p << 1;
            let r = l | 1;

            self.build(l, b, m, H, D);
            self.build(r, m, e, H, D);

            self.st[p] = merge(&self.st[l], &self.st[r]);
        }
    }

    fn query(&mut self, p: usize, b: usize, e: usize, x: usize, y: usize) -> Node {
        let mut answer = Node {a: 0, b: 0, c: -1};

        if x <= b && e <= y {
            answer = self.st[p].clone();
        }
        else {
            let m = (b + e) >> 1;
            let l = p << 1;
            let r = l | 1;

            if x < m {
                answer = merge(&answer, &self.query(l, b, m, x, y));
            }

            if m < y {
                answer = merge(&answer, &self.query(r, m, e, x, y));
            }

        }

        // println!("{} [{}, {}] [{}-{}]: {:?}", p, b, e, x, y, answer);

        answer
    }

    fn debug(&mut self, p: usize, b: usize, e: usize){
        if b + 1 == e {
            let tmp = &self.st[p];
            let h = (tmp.a + tmp.b) / 2;
            let d = tmp.a - h;
            // println!("{}:: a:{} b:{}", b, tmp.a, tmp.b);

        }
        else {
            let m = (b + e) >> 1;
            let l = p << 1;
            let r = l | 1;

            self.debug(l, b, m);
            self.debug(r, m, e);
        }
    }
}


fn main() {
    let stdin = stdin();
    let mut sc = Scanner::new(stdin.lock());
    let stdout = stdout();

    let n = sc.next::<i32>();
    let m = sc.next::<i32>();

    let N = 2 * n + 1;

    let mut H = vec![0; N as usize];
    let mut D = vec![0; N as usize];

    for i in 1..n+1 {
        D[i as usize] = sc.next::<i64>();
        D[(i + n) as usize] = D[i as usize];
    }

    for i in 1..N {
        D[i as usize] += D[(i - 1) as usize];
    }

    for i in 0..n {
        H[i as usize] = 2 * sc.next::<i64>();
        H[(i + n) as usize] = H[i as usize];
    }

    H[(2 * n) as usize] = H[0usize];

    // for u in D.iter() {
    //     print!("{} ", u);
    // }
    // println!("");

    // for u in H.iter() {
    //     print!("{} ", u);
    // }
    // println!("");

    let mut ST = SegmentTree::new(N);

    ST.build(1usize, 0usize, N as usize, &H, &D);

    // for u in ST.st.iter() {
    //     println!("{:?}", u);
    // }

    ST.debug(1usize, 0usize, N as usize);

    for _ in 0..m {
        let a = sc.next::<i32>() - 1;
        let b = sc.next::<i32>() - 1;

        // println!("{} {}", a, b);

        let mut answer : Node;

        if a <= b {
            answer = ST.query(1usize, 0usize, N as usize, (b + 1) as usize, (a + n) as usize);
        }
        else {
            answer = ST.query(1usize, 0usize, N as usize, (b + 1) as usize, a as usize);
        }

        println!("{}", answer.c);
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