import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class D {

	long myDiv(long a, long b) {
		return Math.floorDiv(a + b - 1, b);
	}

	long go2(long n, long s, long k) {
		long ans1 = -1;
		for (long c2 = n; c2 >= 0; c2--) {
			long full = n + c2;

			long x = (k - 1) / full;

			long high = c2;
			long low = -1;
			while (high - low > 1) {
				long mid = (low + high) >> 1;
				if ((k - 1) / (n + mid) == x) {
					high = mid;
				} else {
					low = mid;
				}
			}

			long cLow = high;
			long cHigh = c2;

			// c = c2, c2 - 1, ..., c3

			// last = k - x * (n + c)
			// last2 = k - x * (n + c) - s
			// rest2 = c - k + x * (n + c) + s

			// 0 <= k - x * (n + c) - s <= s
			// 0 <= c - k + x * (n + c) + s <= n - s

			if (x == 0) {
				if (!(0 <= k - s && k - s <= s)) {
					cLow = Long.MAX_VALUE;
				}
				cLow = Math.max(cLow, k - s);
				cHigh = Math.min(cHigh, n + k - s - s);
			} else {

				// c2 <= c <= c3
				// (k - nx - 2s) / x <= c <= (k - nx - s) / x
				// (k - nx - s) / (x + 1) <= c <= (k - nx + n - 2s) / (x + 1)

				cLow = Math.max(cLow, myDiv(k - n * x - 2 * s, x));
				cLow = Math.max(cLow, myDiv(k - n * x - s, x + 1));

				cHigh = Math.min(cHigh, Math.floorDiv(k - n * x - s, x));
				cHigh = Math.min(cHigh,
						Math.floorDiv(k - n * x + n - 2 * s, x + 1));
			}
			if (cLow <= cHigh) {
				ans1 = cHigh;
				break;
			}
			c2 = high;
		}

		k++;
		long ans2 = -1;

		for (long c2 = n; c2 >= 0; c2--) {
			long full = n + c2;

			long x = (k - 1) / full;

			long high = c2;
			long low = -1;
			while (high - low > 1) {
				long mid = (low + high) >> 1;
				if ((k - 1) / (n + mid) == x) {
					high = mid;
				} else {
					low = mid;
				}
			}

			long cLow = high;
			long cHigh = c2;

			// c = c2, c2 - 1, ..., c3

			// last = k - x * (n + c)
			// last2 = k - x * (n + c) - s
			// rest2 = c - k + x * (n + c) + s

			// 1 <= k - x * (n + c) - s <= s
			// 0 <= c - k + x * (n + c) + s <= n - s

			if (x == 0) {
				if (!(1 <= k - s && k - s <= s)) {
					cLow = Long.MAX_VALUE;
				}
				cLow = Math.max(cLow, k - s);
				cHigh = Math.min(cHigh, n + k - s - s);
			} else {
				// c2 <= c <= c3
				// (k - nx - 2s) / x <= c <= (k - nx - s - 1) / x
				// (k - nx - s) / (x + 1) <= c <= (k - nx + n - 2s) / (x + 1)

				cLow = Math.max(cLow, myDiv(k - n * x - 2 * s, x));
				cLow = Math.max(cLow, myDiv(k - n * x - s, x + 1));

				cHigh = Math.min(cHigh, Math.floorDiv(k - n * x - s - 1, x));
				cHigh = Math.min(cHigh,
						Math.floorDiv(k - n * x + n - 2 * s, x + 1));
			}
			if (cLow <= cHigh) {
				ans2 = cHigh;
				break;
			}
			c2 = high;
		}

		return Math.max(ans1, ans2);
	}

	long go1(long n, long s, long k) {

		// no overeating
		long ans1 = -1;
		for (long c2 = n; c2 >= 0; c2--) {
			long full = n + c2;

			long last = k % full;
			if (last == 0) {
				last = full;
			}

			long last2 = last - s;
			long rest2 = c2 - last2;

			if (!(0 <= last2 && last2 <= s && 0 <= rest2 && rest2 <= n - s)) {
				continue;
			}

			ans1 = c2;
			break;
		}

		long ans2 = -1;
		// overeating!
		for (long c2 = n; c2 > 0; c2--) {
			long full = n + c2;

			long last = (k + 1) % full;
			if (last == 0) {
				last = full;
			}

			long last2 = last - s;
			long rest2 = c2 - last2;

			if (!(1 <= last2 && last2 <= s && 0 <= rest2 && rest2 <= n - s)) {
				continue;
			}

			ans2 = c2;
			break;
		}

		return Math.max(ans1, ans2);
	}

	void submit() {
		long n = nextLong();
		long l = nextLong();
		long r = nextLong();
		long k = nextLong();

		long s;
		if (l <= r) {
			s = r - l + 1;
		} else {
			s = r - l + 1 + n;
		}

		// out.println(go2(n, s, k));

		if (n <= C) {
			out.println(go1(n, s, k));
		} else {
			out.println(go2(n, s, k));
		}
	}

	void test() {
		long big = BigInteger.TEN.pow(11).longValue();
		go2(big / 134, big / 2, big / 23);
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
	static final int C = 10_000_000;

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