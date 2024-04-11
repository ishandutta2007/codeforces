import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class G {

	static final int P = 998244353;

	static class Point implements Comparable<Point> {
		int x;
		boolean start;

		@Override
		public int compareTo(Point o) {
			return Integer.compare(x, o.x);
		}

		public Point(int x, boolean start) {
			this.x = x;
			this.start = start;
		}
	}

	static class Node {
		Node left, right;
		int l, r;

		int sum;

		public Node(int l, int r) {
			this.l = l;
			this.r = r;
			if (r - l > 1) {
				a = 1;
				int m = (l + r) >> 1;
				left = new Node(l, m);
				right = new Node(m, r);
			}
		}

		int a, b;

		// x -> ax + b

		int getSum() {
			int ret = (int) ((long) sum * a % P);
			ret += (int) ((long) b * (r - l) % P);
			if (ret >= P) {
				ret -= P;
			}
			return ret;
		}
		
		void pushDown() {
			left.b = (int) (((long) left.b * a + b) % P);
			left.a = (int) ((long) left.a * a % P);
			
			right.b = (int) (((long) right.b * a + b) % P);
			right.a = (int) ((long) right.a * a % P);
			
			a = 1;
			b = 0;
		}

		void modify(int mult, int add, int ql, int qr) {
			
//			if (r - l == 4) {
//				System.err.println(mult + " " + add + " " + ql + " " + qr);
//			}
			
			if (ql == qr) {
				return;
			}
			if (l >= qr || ql >= r) {
				return;
			}
			if (ql <= l && r <= qr) {
				b = (int) (((long) b * mult + add) % P);
				a = (int) ((long) a * mult % P);
				return;
			}
			pushDown();
			
			left.modify(mult, add, ql, qr);
			right.modify(mult, add, ql, qr);
			
			sum = left.getSum() + right.getSum();
			if (sum >= P) {
				sum -= P;
			}
		}
		
		int get(int ql, int qr) {
			if (l >= qr || ql >= r) {
				return 0;
			}
			if (ql <= l && r <= qr) {
				return getSum();
			}
			pushDown();

			int ret = (left.get(ql, qr) + right.get(ql, qr));
			if (ret >= P) {
				ret -= P;
			}
			
			sum = left.getSum() + right.getSum();
			if (sum >= P) {
				sum -= P;
			}
			
			return ret;
		}
	}

	static class Segments {
		TreeSet<Point> set = new TreeSet<>();

		void add(int l, int r, Node root) {
			Point seeker = new Point(l, true);
			ArrayList<Point> shit = new ArrayList<>();

			while (true) {
				Point kek = set.ceiling(seeker);
				if (kek == null || (kek.x > r)) {
					break;
				}
				shit.add(kek);
				set.remove(kek);
			}

			if (shit.isEmpty()) {

				Point kek = set.ceiling(seeker);
				if (kek == null || kek.start) {
					root.modify(1, 1, l, r);
					set.add(new Point(l, true));
					set.add(new Point(r, false));
				} else {
					root.modify(2, 0, l, r);
				}
				return;
			}

			// shit not empty

			if (shit.get(0).start) {
				root.modify(1, 1, l, shit.get(0).x);
				set.add(new Point(l, true));
			} else {
				root.modify(2, 0, l, shit.get(0).x);
			}

			if (shit.get(shit.size() - 1).start) {
				root.modify(2, 0, shit.get(shit.size() - 1).x, r);
			} else {
				root.modify(1, 1, shit.get(shit.size() - 1).x, r);
				set.add(new Point(r, false));
			}

			for (int i = 0; i < shit.size() - 1; i++) {
				Point p = shit.get(i);
				Point q = shit.get(i + 1);
				if (p.start && !q.start) {
					root.modify(2, 0, p.x, q.x);
				} else if (!p.start && q.start) {
					root.modify(1, 1, p.x, q.x);
				} else {
					throw new AssertionError();
				}
			}
			//
			//
		}
	}

	void submit() {
		int n = nextInt();
		int qs = nextInt();
		
		Node root = new Node(0, n);
		
		Segments[] arr = new Segments[n];
		for (int i = 0; i < n; i++) {
			arr[i] = new Segments();
		}

		while (qs-- > 0) {
			int t = nextInt();
			int l = nextInt() - 1;
			int r = nextInt();

			if (t == 1) {
				int x = nextInt() - 1;
				arr[x].add(l, r, root);
			} else {
				out.println(root.get(l, r));
			}
		}
	}

	void test() {

	}

	void stress() {
		for (int tst = 0;; tst++) {
			if (false) {
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	G() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 5;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new G();
	}

	private InputStream is;
	PrintWriter out;

	private byte[] buf = new byte[1 << 14];
	private int bufSz = 0, bufPtr = 0;

	private int readByte() {
		if (bufSz == -1)
			throw new RuntimeException("Reading past EOF");
		if (bufPtr >= bufSz) {
			bufPtr = 0;
			try {
				bufSz = is.read(buf);
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			if (bufSz <= 0)
				return -1;
		}
		return buf[bufPtr++];
	}

	private boolean isTrash(int c) {
		return c < 33 || c > 126;
	}

	private int skip() {
		int b;
		while ((b = readByte()) != -1 && isTrash(b))
			;
		return b;
	}

	String nextToken() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	String nextString() {
		int b = readByte();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b) || b == ' ') {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	char nextChar() {
		return (char) skip();
	}

	int nextInt() {
		int ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}

	long nextLong() {
		long ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}
}