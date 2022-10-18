import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class C {

	int ask(int x, int y) {
		out.println(x + " " + y);
		out.flush();
		return nextToken().equals("white") ? 0 : 1;
	}

	void go(int x0, int y0, int size, boolean deltaX, int c0, int pts) {

		for (int i = 0; i < pts; i++) {

			size >>= 1;
			int cMid;
			if (deltaX) {
				cMid = ask(x0 + size, y0);
			} else {
				cMid = ask(x0, y0 + size);
			}

			if (cMid == c0) {
				if (deltaX) {
					x0 += size;
				} else {
					y0 += size;
				}
			} else {
				// do nothing
			}

		}

		size >>= 1;

		if (deltaX) {
			int mx = x0 + size;
			int my = y0;
			out.println(mx + " " + my + " " + mx + " " + (my + 1));
		} else {
			int mx = x0;
			int my = y0 + size;
			out.println(mx + " " + my + " " + (mx + 1) + " " + my);
		}
		out.flush();

	}

	void submit() {
		int n = nextInt();

		int base = ask(0, 0);

		int shift = 1 << 29;
		boolean deltaX = true;

		int lastX = 0, lastY = 0;

		for (int i = 1; i < n; i++) {
			int nx = lastX, ny = lastY;
			if (deltaX) {
				nx += shift;
			} else {
				ny += shift;
			}

			int now = ask(nx, ny);
			if (now != base) {
				go(lastX, lastY, shift, deltaX, base, n - i - 1);
				return;
			}

			lastX = nx;
			lastY = ny;
			shift >>= 1;
			deltaX ^= true;
		}

		out.println(S + " " + 0 + " " + S + " " + S);
		out.flush();
		return;
	}

	static final int S = 1_000_000_000;

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

	C() throws IOException {
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
		new C();
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