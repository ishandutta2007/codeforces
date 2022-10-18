import java.io.*;
import java.util.*;

public class B_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int[] PRIMES = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
			41, 43, 47, 53 };
	static final int M = PRIMES.length;
	static final int[] MASKS = new int[59];
	static {
		for (int i = 1; i < MASKS.length; i++) {
			for (int j = 0; j < PRIMES.length; j++) {
				if ((i % PRIMES[j] == 0)) {
					MASKS[i] |= 1 << j;
				}
			}
		}
	}
	static final int K = MASKS.length - 1;
	static final int INF = Integer.MAX_VALUE / 3;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		int[][] dp = new int[n][1 << M];
		int[][] from = new int[n][1 << M];
		Arrays.fill(dp[0], INF);
		for (int i = 1; i <= K; i++) {
			if (dp[0][MASKS[i]] > Math.abs(i - a[0])) {
				dp[0][MASKS[i]] = Math.abs(i - a[0]);
				from[0][MASKS[i]] = i;
			}
		}

		for (int i = 1; i < n; i++) {
			Arrays.fill(dp[i], INF);
			// for (int j = 1; j < M; j++) {
			// for (int prev = 1; prev < M; prev++) {
			// if (dp[i][j] > dp[i - 1][prev] + Math.abs(j - a[i])) {
			// dp[i][j] = dp[i - 1][prev] + Math.abs(j - a[i]);
			// from[i][j] = prev;
			// }
			// }
			// }
			for (int prev = 0; prev < (1 << M); prev++) {
				if (dp[i - 1][prev] == INF) {
					continue;
				}
				for (int j = 1; j <= K; j++) {
					if ((MASKS[j] & prev) != 0) {
						continue;
					}
					int newMask = prev ^ MASKS[j];
					if (dp[i][newMask] > dp[i - 1][prev] + Math.abs(a[i] - j)) {
						dp[i][newMask] = dp[i - 1][prev] + Math.abs(a[i] - j);
						from[i][newMask] = j;
					}
				}
			}
		}

		int best = INF;
		int mask = -1;
		for (int i = 0; i < (1 << M); i++) {
			if (dp[n - 1][i] < best) {
				best = dp[n - 1][i];
				mask = i;
			}
		}

		int[] ans = new int[n];
		for (int i = n - 1; i >= 0; i--) {
			ans[i] = from[i][mask];
			mask ^= MASKS[ans[i]];
		}

		for (int i = 0; i < n; i++) {
			out.print(ans[i] + " ");
		}
		out.println();
	}

	B_new() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B_new();
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