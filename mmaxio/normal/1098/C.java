import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class C {

	int safeMul(long a, long b, int n) {
		return (int) Math.min(a * b, n);
	}

	int[] solve(int n, long s) {
		if (s < 2 * n - 1 || s > (long) n * (n + 1) / 2) {
			// out.println(-1);
			return null;
		}

		for (int ans = 1;; ans++) {
			long minHere = 0;
			for (int lvl = 1, size = 1, left = n; left > 0; lvl++) {
				int useHere = Math.min(size, left);
				minHere += (long) lvl * useHere;
				left -= useHere;
				size = safeMul(size, ans, n);
			}
			// System.err.println(ans + " " + minHere);
			if (minHere <= s) {
				int[] cnt = new int[n + 1];
				int lastLvl = 0;
				for (int lvl = 1, size = 1, left = n; left > 0; lvl++) {
					int useHere = Math.min(size, left);
					left -= useHere;
					size = safeMul(size, ans, n);
					cnt[lvl] = useHere;
					lastLvl = lvl;
				}

				outer: for (int nowLvl = lastLvl;; nowLvl--) {
					if (minHere == s) {
						break outer;
					}
					int here = cnt[nowLvl] - 1;
					for (int i = 0; i < here; i++) {
						int maxDelta = lastLvl + 1 - nowLvl;
						int realDelta = (int) Math.min(s - minHere, maxDelta);
						minHere += realDelta;
						cnt[nowLvl]--;
						cnt[nowLvl + realDelta]++;
						if (minHere == s) {
							break outer;
						}
						lastLvl++;
					}
				}

				// System.err.println(ans);
				// System.err.println(Arrays.toString(cnt));

				int[] ret = new int[n];
				int from = 0, to = 1;
				int ptr = 1;
				for (int i = 2; i < cnt.length; i++) {
					int newFrom = ptr;
					for (int j = 0; j < cnt[i]; j++) {
						int v = ptr++;
						ret[v] = from + j / ans;
					}
					from = newFrom;
					to = ptr;
				}

				return ret;
			}
		}
		// System.err.println("done");
	}

	void submit() {
		int n = nextInt();
		long s = nextLong();
		int[] ans = solve(n, s);
		if (ans == null) {
			out.println("No");
		} else {
			out.println("Yes");
			for (int i = 1; i < n; i++) {
				out.print(ans[i] + 1 + " ");
			}
			out.println();
		}
	}

	void test() {
		for (int n = 2; n < 10; n++) {
			for (int s = 2 * n - 1; s < 20; s++) {
				System.err.println(n + " " + s);
				solve(n, s);
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