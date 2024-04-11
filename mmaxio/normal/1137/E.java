import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class E {

	static class Line {
		long k, b;

		public Line(long k, long b) {
			this.k = k;
			this.b = b;
		}

		long at(long x) {
			return k * x + b;
		}
	}

	void submit() {
		int tot = nextInt();
		int qs = nextInt();

		Line[] h = new Line[qs + 1];
		int sz = 0;
		h[sz++] = new Line(0, 0);

		long base = 0;

		long x = 0;

		int lastType = 1;

		while (qs-- > 0) {
			int type = nextInt();
			if (type == 1) {
				int k = nextInt();
				tot += k;
				sz = 0;
				h[sz++] = new Line(0, 0);
				x = 0;
				base = 0;

				out.println("1 0");
				lastType = 1;

				continue;
			}

			if (type == 2) {
				int k = nextInt();
				Line q = new Line(tot, -base - tot * x);

				tot += k;

				if (lastType == 1) {
					out.println("1 0");
					lastType = 2;
					continue;
				}
				if (lastType == 2) {
					out.println((h[sz - 1].k + 1) + " " + (h[sz - 1].at(x) + base));
					lastType = 2;
					continue;
				}

				while (sz > 1 && bad(h[sz - 2], h[sz - 1], q)) {
					// kicking sz - 1 out
//					System.err.println("YEP");
					sz--;
				}
				h[sz++] = q;
				out.println((h[sz - 1].k + 1) + " " + (h[sz - 1].at(x) + base));
				lastType = 2;
				continue;
			}

			if (type != 3) {
				throw new AssertionError();
			}

			base += nextLong();
			long deltaX = nextLong();

			x += deltaX;
			while (sz > 1 && h[sz - 1].at(x) >= h[sz - 2].at(x)) {
				sz--;
			}

			lastType = 3;
			out.println((h[sz - 1].k + 1) +  " " + (h[sz - 1].at(x) + base));
		}
	}

	boolean bad(Line p, Line q, Line r) {
		return p.k * (q.b - r.b) + q.k * (r.b - p.b) + r.k * (p.b - q.b) <= 0;
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

	E() throws IOException {
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
		new E();
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