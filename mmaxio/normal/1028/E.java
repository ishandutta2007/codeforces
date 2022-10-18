import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class E {

	void submit() {
		int n = nextInt();
		long[] b = new long[n];
		for (int i = 0; i < n; i++) {
			b[i] = nextLong();
		}
		long[] a = solve(b);
		if (a == null) {
			out.println("NO");
		} else {
			out.println("YES");
			for (long x : a) {
				out.print(x + " ");
			}
			out.println();
		}
	}

	long[] solve(long[] b) {
		int n = b.length;

		boolean all0 = true;

		for (int i = 0; i < n; i++) {
			all0 &= b[i] == 0;
		}

		if (all0) {
			long[] a = new long[n];
			Arrays.fill(a, 1);
			return a;
		}

		for (int i = 0; i < n; i++) {
			if (b[i] >= b[(i + 1) % n]) {
				continue;
			}

			long[] a = new long[n];
			a[(i + 1) % n] = b[(i + 1) % n];

			for (int jj = i; jj > i - n + 1; jj--) {
				int j = jj < 0 ? jj + n : jj;
				int afterJ = (j + 1) % n;
				int befJ = (j + n - 1) % n;

				long mod = a[afterJ];
				long rem = b[j];

				if (!(rem < mod)) {
					throw new AssertionError();
				}

				long atLeast = b[befJ];

				// mod * x + rem > atLeast
				// x > (atLeast - rem) / mod

				long x = Math.floorDiv(atLeast - rem, mod) + 1;

				a[j] = mod * x + rem;
			}

			return a;
		}

		return null;
	}

	void test() {

	}

	void stress() {
		for (int tst = 0;; tst++) {
			int n = rand(2, C);
			long[] b = new long[n];
			for (int i = 0; i < n; i++) {
				b[i] = rand(0, C);
			}
			solve(b);
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