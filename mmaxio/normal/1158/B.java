import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class B {

	int f(String s) {
		for (int ans = 1;; ans++) {
			HashSet<String> once = new HashSet<>();
			HashSet<String> twice = new HashSet<>();
			for (int i = 0; i + ans <= s.length(); i++) {
				String t = s.substring(i, i + ans);
				if (twice.contains(t)) {

				} else if (once.contains(t)) {
					once.remove(t);
					twice.add(t);
				} else {
					once.add(t);
				}
			}
			if (!once.isEmpty()) {
				return ans;
			}
		}
	}

	int get(int mask, int i) {
		return ((mask >> i) & 1);
	}

	String slow(int n, int k) {
		for (int ans = 0;; ans++) {
			StringBuilder sb = new StringBuilder();
			for (int i = n - 1; i >= 0; i--) {
				sb.append(get(ans, i));
			}
			if (f(sb.toString()) == k) {
				return sb.toString();
			}
		}
	}

	String solve(int n, int k) {
		char[] s = new char[n];
		Arrays.fill(s, '0');
		if (k == n) {
			return new String(s);
		}
		if (k == 1) {
			s[n - 1] = '1';
			return new String(s);
		}

		if (2 * (k - 1) + k - 1 >= n) {
			int step = (n - k) / 2 + 1;
			for (int i = step - 1; i < n; i += step) {
				s[i] = '1';
			}
		} else {
			int step = k - 1;
			s[n - step] = '1';
			s[n - 2 * step] = '1';
		}

		return new String(s);
	}

	void submit() {
		int n = nextInt();
		int k = nextInt();
		out.println(solve(n, k));
	}

	void test() {

		// System.err.println(solve(6, 4));

		// for (int n = 14; n <= 16; n++) {
		// for (int k = 2 - n % 2; k <= n; k += 2) {
		// System.err.println(n + " " + k + " " + slow(n, k));
		// }
		// }

		for (int n = 1;; n++) {
			// System.err.println(n);
			for (int k = 2 - n % 2; k <= n; k += 2) {
				String tst = solve(n, k);
				if (f(tst) != k) {
					System.err.println(n + " " + k);
					System.err.println(tst);
					System.err.println(f(tst));
					throw new AssertionError();
				}
			}
		}
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