import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int MOD = 1000000007;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();

		if (k == 0) {
			out.println(1);
			return;
		}

		int[] pow2 = new int[501];
		pow2[0] = 1;
		for (int i = 1; i <= 500; i++) {
			pow2[i] = 2 * pow2[i - 1] % MOD;
		}

		int[][] dp = new int[k + 1][n + 1];
		dp[0][0] = 1;
		for (int r = 1; r <= n; r++) {
			int[][] next = new int[k + 1][n + 1];
			for (int prevK = 0; prevK <= k; prevK++)
				for (int prevMaxR = 0; prevMaxR < r; prevMaxR++) {
					if (dp[prevK][prevMaxR] == 0) {
						continue;
					}
					// don't take any of these
					next[prevK][prevMaxR] += (int) ((long) dp[prevK][prevMaxR]
							* pow2[prevMaxR] % MOD);
					next[prevK][prevMaxR] %= MOD;
					// take some...
					if (prevK != k) {
						int mult = pow2[r] - pow2[prevMaxR];
						// if (r == 1) {
						// System.err.println(r + " " + prevMaxR + " " + mult);
						// }
						if (mult < 0) {
							mult += MOD;
						}
						next[prevK + 1][r] += (int) ((long) dp[prevK][prevMaxR]
								* mult % MOD);
						next[prevK + 1][r] %= MOD;
					}
				}
			dp = next;
//			System.err.println(Arrays.deepToString(dp));
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += dp[k][i];
			ans %= MOD;
		}

		out.println(ans);
	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E();
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