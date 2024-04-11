import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class C {

	static final int INF = Integer.MAX_VALUE / 3;

	int[] fast(int[] a) {
		int n = a.length;

		int[][] dp = new int[3][2];

		for (int[] row : dp) {
			Arrays.fill(row, INF);
		}

		// 0 - last, 1 - prelast, 2 - far

		dp[0][1] = 0;
		dp[2][0] = 0;

		for (int idx = 1; idx < n; idx++) {
			int max = idx / 2 + 1;
			int[][] nxt = new int[3][max + 1];
			for (int[] row : nxt) {
				Arrays.fill(row, INF);
			}

			for (int pS = 0; pS < 3; pS++) {
				for (int pB = 0; pB < dp[0].length; pB++) {
					if (dp[pS][pB] == INF) {
						continue;
					}

					// build
					if (pS != 0) {
						int cost;
						if (pS == 1) {
							int already = Math.min(a[idx - 2] - 1, a[idx - 1]);
							cost = Math.max(already - (a[idx] - 1), 0);
						} else {
							cost = Math.max(a[idx - 1] - (a[idx] - 1), 0);
						}
						nxt[0][pB + 1] = Math.min(nxt[0][pB + 1], dp[pS][pB]
								+ cost);
					}

					// skip
					{
						int cost;
						if (pS == 0) {
							cost = Math.max(a[idx] - (a[idx - 1] - 1), 0);
						} else {
							cost = 0;
						}
						int nS = Math.min(pS + 1, 2);
						nxt[nS][pB] = Math.min(nxt[nS][pB], dp[pS][pB] + cost);
					}

				}
			}

			dp = nxt;
			// System.err.println(Arrays.deepToString(dp));
		}

		int[] ret = new int[(n + 1) / 2 + 1];
		Arrays.fill(ret, INF);

		for (int i = 0; i < ret.length; i++) {
			for (int j = 0; j < 3; j++) {
				ret[i] = Math.min(ret[i], dp[j][i]);
			}
		}

		return ret;
	}

	void submit() {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		int[] ret = fast(a);

		for (int i = 1; i < ret.length; i++) {
			out.print(ret[i] + " ");
		}
		out.println();
	}

	void test() {
		int n = 5000;
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = rand(1, 100000);
		}
		out.println(Arrays.toString(fast(a)));
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
//		test();
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