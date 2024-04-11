import java.io.*;
import java.util.*;

public class E_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int P = 1_000_000_007;
	static final long P2 = (long) P * P;

	int[] oneCol(int[] dp, int h, int prevH) {

		for (int j = 0; j < h; j++) {
			int[] next = new int[1 << h];
			boolean canDown = j != 0;
			boolean canLeft = j < prevH;
			for (int was = 0; was < (1 << h); was++) {
				if (dp[was] == 0) {
					continue;
				}
				boolean needLeft = (was & 1) == 1;
				if (needLeft && !canLeft) {
					throw new AssertionError();
				}
				// down and left
				if (canDown && canLeft) {
					int tmp = clear(was, h - 1) >> 1;
					next[tmp] += dp[was];
					if (next[tmp] >= P) {
						next[tmp] -= P;
					}
				}
				// down
				if (canDown && !needLeft) {
					int tmp = clear(was, h - 1) >> 1;
					next[tmp] += dp[was];
					if (next[tmp] >= P) {
						next[tmp] -= P;
					}
				}
				// left
				if (canLeft) {
					int tmp = was >> 1;
					next[tmp] += dp[was];
					if (next[tmp] >= P) {
						next[tmp] -= P;
					}
				}
				// nothing
				if (!needLeft) {
					int tmp = set(was >> 1, h - 1);
					next[tmp] += dp[was];
					if (next[tmp] >= P) {
						next[tmp] -= P;
					}
				}

			}
			dp = next;
		}
		return dp;
	}

	void solve() throws IOException {
		int[] ws = new int[7];
		for (int i = 0; i < 7; i++) {
			ws[i] = nextInt();
		}

		int[] dp = new int[1];
		dp[0] = 1;
		int prevH = 0;

		for (int h = 1; h <= 7; h++) {
			int w = ws[h - 1];
			if (w == 0) {
				continue;
			}
			dp = Arrays.copyOf(dp, 1 << h);
			dp = oneCol(dp, h, prevH);
			prevH = h;
			int[][] m = new int[1 << h][];
			int[] tmp = new int[1 << h];
			for (int i = 0; i < 1 << h; i++) {
				tmp[i] = 1;
				if (i > 0) {
					tmp[i - 1] = 0;
				}
				m[i] = oneCol(tmp, h, h);
			}
//			System.err.println(Arrays.toString(dp));
//			System.err.println(Arrays.deepToString(m));
			m = pow(m, w - 1);

			int[] next = new int[1 << h];
			for (int i = 0; i < (1 << h); i++) {
				for (int j = 0; j < (1 << h); j++) {
					next[j] += (int) ((long) dp[i] * m[i][j] % P);
					next[j] %= P;
				}
			}
			dp = next;

		}

		out.println(dp[0]);
	}

	static int[][] mul(int[][] a, int[][] b) {
		int n = a.length;
		int[][] c = new int[n][n];
		for (int i = 0; i < n; i++) {
			int[] A = a[i];
			for (int j = 0; j < n; j++) {
				long tmp = 0;
				for (int k = 0; k < n; k++) {
					tmp += (long) A[k] * b[k][j];
					if (tmp >= P2) {
						tmp -= P2;
					}
				}
				c[i][j] = (int) (tmp % P);
			}
		}
		return c;
	}

	static int[][] pow(int[][] a, int b) {
		int[][] ret = new int[a.length][a.length];
		for (int i = 0; i < a.length; i++) {
			ret[i][i] = 1;
		}
		for (; b > 0; b >>= 1) {
			if ((b & 1) == 1) {
				ret = mul(ret, a);
			}
			a = mul(a, a);
		}
		return ret;
	}

	int clear(int mask, int i) {
		return mask & ~(1 << i);
	}

	int set(int mask, int i) {
		return mask | (1 << i);
	}

	E_new() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E_new();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}