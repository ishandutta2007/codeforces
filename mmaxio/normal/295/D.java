import java.io.*;
import java.util.*;

public class D_fast {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int MOD = 1_000_000_007;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		if (m < 2) {
			out.println(0);
			return;
		}

		int[][] dp = new int[n + 1][m + 1];
		for (int len = 2; len <= m; len++) {
			dp[1][len] = 1;
		}

		int[] tmp = new int[m + 1];

		for (int height = 2; height <= n; height++) {
			int[] dpPrev = dp[height - 1];
			tmp[2] = dpPrev[2];
			for (int i = 3; i <= m; i++) {
				tmp[i] = tmp[i - 1] + dpPrev[i];
				if (tmp[i] >= MOD)
					tmp[i] -= MOD;
			}

			int[] dpCur = dp[height];
			dpCur[2] = tmp[2];
			for (int i = 3; i <= m; i++) {
				dpCur[i] = dpCur[i - 1] + tmp[i];
				if (dpCur[i] >= MOD)
					dpCur[i] -= MOD;
			}
		}

		int[] fixedHeight = new int[n + 1];
		int[] up = new int[n + 1];
		int[] down = new int[n + 1];

		int ans = 0;
		for (int len = 2; len <= m; len++) {

			int val = 0;

			for (int h = 1; h <= n; h++) {
				up[h] = down[h] = dp[h][len];
				if (h != 1) {
					up[h] -= dp[h - 1][len];
					if (up[h] < 0)
						up[h] += MOD;
				}
				if (h != 1) {
					up[h] += up[h - 1];
					if (up[h] >= MOD)
						up[h] -= MOD;
					down[h] += down[h - 1];
					if (down[h] >= MOD)
						down[h] -= MOD;
				}
			}
			
			for (int mid = 0; mid < n; mid++) {
				int maxUp = mid + 1;
				int maxDown = n - mid;
				val += (int)((long)up[maxUp] * down[maxDown] % MOD);
				if (val >= MOD)
					val -= MOD;
			}

			ans += (int) ((long) val * (m - len + 1) % MOD);
			if (ans >= MOD)
				ans -= MOD;
		}

		out.println(ans);

	}

	D_fast() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D_fast();
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