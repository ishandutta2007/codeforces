import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class D {

	static class Point {
		int x, y, id;

		public Point(int x, int y, int id) {
			this.x = x;
			this.y = y;
			this.id = id;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Point other = (Point) obj;
			if (id != other.id)
				return false;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

		@Override
		public String toString() {
			return "(" + x + ", " + y + ")";
		}
	}

	int turn(Point a, Point b, Point c) {
		long x1 = b.x - a.x;
		long y1 = b.y - a.y;
		long x2 = c.x - a.x;
		long y2 = c.y - a.y;
		return Long.signum(x1 * y2 - x2 * y1);
	}

	void submit() {
		int n = nextInt();
		ArrayList<Point> a = new ArrayList<>(n);
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			int y = nextInt();
			a.add(new Point(x, y, i + 1));
		}

		String s = nextToken();

		Point p = a.get(0);
		for (Point q : a) {
			if (q.x < p.x || (q.x == p.x && q.y < p.y)) {
				p = q;
			}
		}
		
		for (int i = 0; i < n - 2; i++) {
			char c = s.charAt(i);
			a.remove(p);
			out.print(p.id + " ");
			
			Point q = a.get(0);
			
			for (Point r : a) {
				int t = turn(p, q, r);
				if ((t > 0 && c == 'R') || (t < 0 && c == 'L')) {
					q = r;
				}
			}
			
			p = q;
		}
		
		out.print(p.id + " ");
		a.remove(p);
		out.println(a.get(0).id);
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

	D() throws IOException {
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
		new D();
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