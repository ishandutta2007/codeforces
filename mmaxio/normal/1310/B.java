import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class B {

	void submit() {
		int n = nextInt();
		int k = nextInt();
		int[] a = new int[1 << n];
		for (int i = 0; i < k; i++) {
			a[nextInt() - 1] = 1;
		}

		if (k == 0) {
			out.println(0);
			return;
		}

		int ans = 1;
		int[] kek = go(a, 0, 1 << n);
		int delta = Math.max(Math.max(kek[0], kek[1]), Math.max(kek[2], kek[3]));
		if (delta != BAD) {
			ans += delta;
		}
		out.println(ans);
	}

	static final int BAD = -1000000;

	int[] go(int[] a, int l, int r) {
		if (r - l == 2) {
			int ret = a[l] + a[l + 1];
			if (ret == 0) {
				return new int[] { 0, BAD, BAD, BAD };
			}
			if (ret == 1) {
				return new int[] { BAD, 1, 1, BAD };
			}
			return new int[] { BAD, BAD, BAD, 1 };
		}

		int m = (l + r) >> 1;
		int[] x = go(a, l, m);
		int[] y = go(a, m, r);

		int[] ret = { BAD, BAD, BAD, BAD };

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (x[i] == BAD || y[j] == BAD) {
					continue;
				}
				
				if (i == 3 || j == 3) {
					ret[3] = Math.max(ret[3], x[i] + y[j] + 3);
					continue;
				} 
				
				if (i == 0 || j == 0) {
					if (i + j == 0) {
						ret[0] = Math.max(ret[0], x[i] + y[j]);
						continue;
					}
					if (i + j == 1) {
						ret[1] = Math.max(ret[1], x[i] + y[j] + 2);
						continue;
					}
					if (i + j == 2) {
						ret[1] = Math.max(ret[1], x[i] + y[j] + 2);
						ret[2] = Math.max(ret[2], x[i] + y[j] + 1);
						continue;
					}
				}
				
				if (i == 1 && j == 1) {
					ret[1] = Math.max(ret[1], x[i] + y[j] + 2);
					continue;
				}
				if (i + j == 3) {
					ret[3] = Math.max(ret[3], x[i] + y[j] + 3);
					continue;
				}
				ret[3] = Math.max(ret[3], x[i] + y[j] + 2);
			}
		}
		
		return ret;
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

	B() throws IOException {
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
		new B();
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