import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		char[][] f = new char[n][];
		for (int i = 0; i < n; i++) {
			f[i] = nextToken().toCharArray();
		}
		int[][] cost = new int[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cost[i][j] = nextInt();
			}

		int[][] costAll = new int[n][m];
		int[][] maskAll = new int[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				maskAll[i][j] = 1 << i;
				for (int k = 0; k < n; k++) {
					if (f[i][j] == f[k][j] && i != k) {
						maskAll[i][j] |= 1 << k;
						costAll[i][j] += cost[k][j];
					}
				}
			}

		int[] cheap = new int[n];
		for (int i = 0; i < n; i++) {
			cheap[i] = Integer.MAX_VALUE;
			for (int j = 0; j < m; j++) {
				cheap[i] = Math.min(cheap[i], cost[i][j]);
			}
		}
		int[] cheapSub = new int[1 << n];
		for (int i = 0; i < n; i++) {
			cheapSub[1 << i] = cheap[i];
		}

		for (int i = 1; i < (1 << n); i++) {
			int prev = i & (i - 1);
			cheapSub[i] = cheapSub[prev] + cheapSub[i ^ prev];
		}

		int[] dp = new int[1 << n];
		for (int i = 0; i < (1 << n); i++) {
			dp[i] = cheapSub[i];
			for (int j = 0; j < n; j++) {
				if (test(i, j)) {

					for (int k = 0; k < m; k++) {
						int to = i & (~maskAll[j][k]);
						if (to != i) {
							dp[i] = Math.min(dp[i], dp[to] + costAll[j][k]);
						}
					}

				}
			}
		}
		out.println(dp[(1 << n) - 1]);
	}

	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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