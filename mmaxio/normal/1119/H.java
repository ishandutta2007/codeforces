import java.io.*;
import java.math.*;
import java.util.*;

public class cfGlobal2H {

	static final int P = 998244353;
	static final int INV2 = (P + 1) / 2;

	void fwhtMod(int[] a) {
		int n = a.length;
		for (int s = 1; s < n; s <<= 1) {
			for (int i = 0; i < n; i += s << 1) {
				for (int j = i; j < i + s; j++) {
					int k = j + s;

					int v = a[j];
					int u = a[k];

					a[j] += u;
					if (a[j] >= P) {
						a[j] -= P;
					}

					a[k] = v - u;
					if (a[k] < 0) {
						a[k] += P;
					}

				}
			}
		}
	}

	static final int M = 3;

	static final boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	void submit() {
		int n = nextInt();
		int k = nextInt();

		int[] xs = new int[M];
		for (int i = 0; i < M; i++) {
			xs[i] = nextInt();
		}

		int[] arr = new int[1 << (k + M)];

		for (int i = 0; i < n; i++) {
			int[] tmp = new int[M];
			for (int j = 0; j < M; j++) {
				tmp[j] = nextInt();
			}

			for (int mask = 0; mask < 1 << M; mask++) {
				int idx = mask << k;
				for (int j = 0; j < M; j++) {
					if (test(mask, j)) {
						idx ^= tmp[j];
					}
				}
				// System.err.println(mask + " " + idx);
				arr[idx]++;
			}
		}

		fwhtMod(arr);

		int[][] ps = new int[1 << M][];

		for (int i = 0; i < 1 << M; i++) {
			int sum = 0;
			for (int j = 0; j < M; j++) {
				if (test(i, j)) {
					sum -= xs[j];
					if (sum < 0) {
						sum += P;
					}
				} else {
					sum += xs[j];
					if (sum >= P) {
						sum -= P;
					}
				}

			}
			ps[i] = pows(sum, n);
		}

		int i2m = 1;
		for (int i = 0; i < M; i++) {
			i2m = (int) ((long) i2m * INV2 % P);
		}

		for (int i = 0; i < arr.length; i++) {
			arr[i] = (int) ((long) arr[i] * i2m % P);
		}

		int[] ans = new int[1 << k];
		for (int i = 0; i < 1 << k; i++) {
			ans[i] = 1;
			for (int j = 0; j < 1 << M; j++) {
				ans[i] = (int) ((long) ans[i] * ps[j][arr[i | (j << k)]] % P);
			}
		}

		fwhtMod(ans);

		long inv2k = 1;
		for (int i = 0; i < k; i++) {
			inv2k = inv2k * INV2 % P;
		}

		for (int i = 0; i < ans.length; i++) {
			out.print(ans[i] * inv2k % P + " ");
		}
		out.println();
	}

	int[] pows(int x, int b) {
		int[] ret = new int[b + 1];
		ret[0] = 1;
		for (int i = 1; i < ret.length; i++) {
			ret[i] = (int) ((long) ret[i - 1] * x % P);
		}
		return ret;
	}

	int f(long x) {
		// return (int) Math.floorMod(x, P);
		x %= P;
		return (int) (x < 0 ? x + P : x);
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

	cfGlobal2H() throws IOException {
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
		new cfGlobal2H();
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