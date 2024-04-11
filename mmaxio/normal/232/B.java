import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int MOD = 1000000007;

	int pow(int a, int b) {
		int res = 1;
		while (b != 0) {
			if ((b & 1) == 1)
				res = (int) ((long) res * a % MOD);
			a = (int) ((long) a * a % MOD);
			b >>= 1;
		}
		return res;
	}

	void solve() throws IOException {
		int n = nextInt();
		long m = nextLong();

		int[][] c = new int[n + 1][];
		for (int i = 0; i <= n; i++) {
			c[i] = new int[i + 1];
			c[i][0] = c[i][i] = 1;
			for (int j = 1; j < i; j++) {
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
				if (c[i][j] >= MOD) {
					c[i][j] -= MOD;
				}
			}
		}

		int k = nextInt();

		int[] dp = new int[k + 1];
		dp[0] = 1;

		long colsMax = (m + n - 1) / n;
		long colsMin = m / n;

		colsMax %= MOD - 1;
		colsMin %= MOD - 1;

		int[] waysMax = new int[n + 1];
		for (int i = 0; i <= n; i++)
			waysMax[i] = pow(c[n][i], (int) colsMax);

		int[] waysMin = new int[n + 1];
		for (int i = 0; i <= n; i++)
			waysMin[i] = pow(c[n][i], (int) colsMin);

		int zz = (int) (m % n);

		for (int col = 0; col < n; col++) {
			int[] ways = (col < zz ? waysMax : waysMin);
			
			//System.err.println(Arrays.toString(ways));

			for (int i = k; i >= 0; i--) {
				for (int put = 1; put <= n; put++) {
					if (i + put <= k) {
						dp[i + put] += (int) ((long) dp[i] * ways[put] % MOD);
						if (dp[i + put] >= MOD) {
							dp[i + put] -= MOD;
						}
					}
				}
			}
			
			//System.err.println(Arrays.toString(dp));

		}
		
		out.println(dp[k]);
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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