import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;

	static final int P = 1_000_000_007;

	int[][][] dp;

	int n, k;

	void dfs(int v, int p) {

		int thisBlack = 1;

		dp[v][2 * k + 1][1] = 1;

		for (int u : g[v]) {
			if (u == p) {
				continue;
			}

			dfs(u, v);

			int allWaysU = 0;

			for (int black = 0; black <= 2 * k + 1; black++) {
				for (int white = 0; white <= k; white++) {
					allWaysU += dp[u][black][white];
					if (allWaysU >= P) {
						allWaysU -= P;
					}
				}
			}

			thisBlack = (int) ((long) thisBlack * allWaysU % P);

			int[][] nxtDp = new int[2 * k + 2][k + 1];

			for (int oldBlack = 0; oldBlack <= 2 * k + 1; oldBlack++) {
				for (int oldWhite = 0; oldWhite <= k; oldWhite++) {
					for (int addBlack = 0; addBlack <= 2 * k + 1; addBlack++) {
						for (int addWhite = 0; addWhite <= k; addWhite++) {

							int newBlack = Math.min(oldBlack, addBlack + 1);
							int newWhite = 0; // no bad white

							if (oldWhite - 1 + addBlack + 1 > k) {
								newWhite = Math.max(newWhite, oldWhite);
							}

							if (addWhite != 0 && addWhite + oldBlack > k) {
								newWhite = Math.max(newWhite, addWhite + 1);
							}

							if (newWhite == k + 1) {
								continue;
							}

							int delta = (int) ((long) dp[v][oldBlack][oldWhite]
									* dp[u][addBlack][addWhite] % P);

							nxtDp[newBlack][newWhite] += delta;

							if (nxtDp[newBlack][newWhite] >= P) {
								nxtDp[newBlack][newWhite] -= P;
							}

						}
					}
				}
			}

			dp[v] = nxtDp;

		}

		dp[v][0][0] += thisBlack;
		if (dp[v][0][0] >= P) {
			dp[v][0][0] -= P;
		}

	}

	void solve() throws IOException {
		n = nextInt();
		k = nextInt();

		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}

		for (int i = 0; i < n - 1; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			g[v].add(u);
			g[u].add(v);
		}

		if (k == 0) {
			out.println(1);
			return;
		}

		dp = new int[n][2 * k + 2][k + 1]; // v, closest black, farthest bad

		dfs(0, 0);

		int ans = 0;

		for (int black = 0; black <= 2 * k + 1; black++) {
			ans += dp[0][black][0];
			if (ans >= P) {
				ans -= P;
			}
		}

		out.println(ans);
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