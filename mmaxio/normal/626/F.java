import java.io.*;
import java.util.*;

public class F_ehh {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int P = 1_000_000_007;

	int k;

	void solve() throws IOException {
		 int n = nextInt();
//		int n = 200;
//		Random rng = new Random();

		 k = nextInt();
//		int k = 1000;

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {

			 a[i] = nextInt();
//			a[i] = rng.nextInt(500) + 1;
		}

		Arrays.sort(a);

		int[][] dp = { { 1 } };

		int[] maxBal = new int[n];
		for (int i = 0; i < n; i++) {
			maxBal[i] = Math.min(i + 1, n - i - 1);
		}

		int[][] lowDim = new int[n][];
		int[][] minAfter = new int[n][];
		int[][] highDim = new int[n][];

		for (int i = 0; i < n; i++) {
			lowDim[i] = new int[maxBal[i] + 1];
			minAfter[i] = new int[maxBal[i] + 1];
			highDim[i] = new int[maxBal[i] + 1];
			for (int j = 0; j < maxBal[i]; j++) {
				lowDim[i][j + 1] = lowDim[i][j] + a[i - j];
				minAfter[i][j + 1] = minAfter[i][j] + a[i + 1 + j];
			}

			for (int j = 0; j <= maxBal[i]; j++) {
				lowDim[i][j] = -lowDim[i][j];
				highDim[i][j] = k - minAfter[i][j];
			}

			// System.err.println(i);
			// System.err.println(Arrays.toString(lowDim[i]));
			// System.err.println(Arrays.toString(minAfter[i]));
			// System.err.println(Arrays.toString(highDim[i]));
		}

		for (int i = 0; i < n; i++) {
			// System.err.println(i);
			int[][] next = new int[maxBal[i] + 1][];
			for (int j = 0; j <= maxBal[i]; j++) {
				next[j] = new int[Math.max(highDim[i][j] - lowDim[i][j] + 1, 0)];
			}
			for (int j = 0; j < dp.length; j++) {
				for (int kk = 0; kk < dp[j].length; kk++) {
					int diff = kk + (i == 0 ? 0 : lowDim[i - 1][j]);
					int ways = dp[j][kk];

					// -1 to groups
					if (j - 1 >= 0 && j - 1 <= maxBal[i]) {
						int newDiff = diff + a[i] - lowDim[i][j - 1];
						if (newDiff < next[j - 1].length && newDiff >= 0) {
							next[j - 1][newDiff] += (int) ((long) ways * j % P);
							if (next[j - 1][newDiff] >= P) {
								next[j - 1][newDiff] -= P;
							}
						}
					}

					// 0 to groups
					if (j >= 0 && j <= maxBal[i]) {
						int newDiff = diff - lowDim[i][j];
						if (newDiff < next[j].length && newDiff >= 0) {
							next[j][newDiff] += (int) ((long) ways * (j + 1) % P);
							if (next[j][newDiff] >= P) {
								next[j][newDiff] -= P;
							}
						}
					}

					// +1 to groups
					if (j + 1 >= 0 && j + 1 <= maxBal[i]) {
						int newDiff = diff - a[i] - lowDim[i][j + 1];
						if (newDiff < next[j + 1].length && newDiff >= 0) {
							next[j + 1][newDiff] += ways;
							if (next[j + 1][newDiff] >= P) {
								next[j + 1][newDiff] -= P;
							}
						}
					}
				}
			}
			dp = next;

		}

		int ans = 0;

		for (int i = 0; i < dp[0].length; i++) {
			int diff = i - lowDim[n - 1][0];
			if (diff < 0 || diff > k) {
				throw new AssertionError();
			}
			ans += dp[0][i];
			if (ans >= P) {
				ans -= P;
			}
		}

		out.println(ans);
	}

	F_ehh() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new F_ehh();
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