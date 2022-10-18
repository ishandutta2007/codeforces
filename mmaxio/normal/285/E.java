import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int MOD = 1_000_000_007;

	boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();

		int[] fact = new int[n + 1];
		fact[0] = 1;
		for (int i = 1; i <= n; i++) {
			fact[i] = (int) ((long) fact[i - 1] * i % MOD);
		}
		
		int[] invFact = new int[n + 1];
		for (int i = 0; i <= n; i++)
			invFact[i] = pow(fact[i], MOD - 2);

		int[][] dp = new int[n + 1][4];
		dp[0][0] = 1;

		for (int pos = 0; pos < n; pos++) {
			int[][] next = new int[n + 1][4];
			for (int good = 0; good < n; good++) {
				for (int mask = 0; mask < 4; mask++) {
					if (dp[good][mask] != 0) {
						// put pos - 1
						if (pos != 0 && !test(mask, 0)) {
							next[good + 1][mask >> 1] += dp[good][mask];
							if (next[good + 1][mask >> 1] >= MOD)
								next[good + 1][mask >> 1] -= MOD;
						}
						// put pos + 1
						if (pos != n - 1) {
							next[good + 1][(mask >> 1) | 2] += dp[good][mask];
							if (next[good + 1][(mask >> 1) | 2] >= MOD)
								next[good + 1][(mask >> 1) | 2] -= MOD;
						}
						// put nothing
						next[good][mask >> 1] += dp[good][mask];
						if (next[good][mask >> 1] >= MOD)
							next[good][mask >> 1] -= MOD;
					}
				}
			}
			dp = next;
		}

		int[] val = new int[n + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < 4; j++) {
				val[i] += dp[i][j];
				if (val[i] >= MOD)
					val[i] -= MOD;
			}
			val[i] = (int) ((long) val[i] * fact[n - i] % MOD);
		}
		
		//System.err.println(Arrays.toString(val));

		for (int i = n; i >= 0; i--)
			for (int j = i + 1; j <= n; j++) {

				int coef = (int) ((long) fact[j] * invFact[i] % MOD
						* invFact[j - i] % MOD);

				val[i] -= (int) ((long) val[j] * coef % MOD);
				if (val[i] < 0)
					val[i] += MOD;
			}
		
		out.println(val[k]);
	}

	int pow(int a, int b) {
		int res = 1;
		while (b != 0) {
			if ((b & 1) == 1)
				res = (int)((long)res * a % MOD);
			a = (int)((long)a * a % MOD);
			b >>= 1;
		}
		return res;
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