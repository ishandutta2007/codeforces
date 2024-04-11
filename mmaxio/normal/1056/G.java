import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class G {

	void submit() {
		int n = nextInt();
		int k = nextInt();
		int s = nextInt() - 1;
		long t = nextLong();
		out.println(solve(n, k, s, t) + 1);
	}

	int solve(int n, int k, int s, long t) {
		// int n = nextInt();
		// int k = nextInt();
		// int s = nextInt() - 1;
		// long t = nextLong();
		while (t % n != 0) {
			int delta = (int) ((s < k ? 1 : -1) * (t % n));
			s = (s + n + delta) % n;
			t--;
		}

		t /= n;

		long[] when = new long[n];
		Arrays.fill(when, -1);

		for (long left = t; left > 0; left--) {
			if (when[s] != -1) {
				long period = when[s] - left;

				for (int i = 0; i < n; i++) {
					if (when[i] != -1 && when[i] <= when[s]
							&& when[i] % period == 0) {
						// out.println(i + 1);
						return i;
					}
				}

				throw new AssertionError();

			}
			when[s] = left;

			for (int i = n - 1; i > 0; i--) {
				if (s < k) {
					s += i;
					if (s >= n) {
						s -= n;
					}
				} else {
					s -= i;
					if (s < 0) {
						s += n;
					}
				}
			}

		}

		// out.println(s + 1);
		return s;

	}

	int go(int n, int m) {
		int[] a = IntStream.range(0, n).toArray();
		for (int i = n - 1; i > 0; i--) {
			for (int j = 0; j < n; j++) {
				int delta = a[j] < m ? 1 : -1;
				a[j] = (a[j] + n + i * delta) % n;
			}
		}
		// System.err.println(Arrays.toString(a));
		// out.println("digraph G {");
		// for (int i = 0; i < n; i++) {
		// out.println(i + " -> " + a[i] + ";");
		// }
		// out.println("}");

		return maxDepth(a);
	}

	int maxDepth(int[] p) {
		int n = p.length;
		int[] used = new int[n];
		int ret = 0;
		Arrays.fill(used, -1);
		for (int i = 0; i < n; i++) {
			int cur = 0;
			int v = i;
			while (used[v] != i) {
				used[v] = i;
				cur++;
				v = p[v];
			}
			ret = Math.max(ret, cur);
		}
		return ret;
	}

	void test() {
		/*
		 * int max = -1; for (int n = 1;; n <<= 1) { // if (n % 40 == 0) {
		 * System.err.println(n); // } for (int k = 1; k < Math.min(n, 20); k++)
		 * { int tmp = go(n, k); if (tmp > max) { max = tmp;
		 * System.err.println(max + " @ " + n + " " + k); } } }
		 */
		for (int s = 0; s < 65536; s++) {
			System.err.println(solve(65536, 1, s, 1_000_000_000_000L));
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