import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int P = 1_000_000_007;

	List<Integer>[] g;

	int[] go(int v) {
		int[][][] tmp = new int[2][2][4];
		tmp[0][1][0] = 1;
		for (int i = 0; i < g[v].size(); i++) {
			int[] dp = go(g[v].get(i));
			int[][][] next = new int[2][2][4];

			for (int j0 = 0; j0 < 2; j0++)
				for (int j1 = 0; j1 < 2; j1++)
					for (int has = 0; has < 4; has++) {
						for (int pick = 0; pick < 2; pick++) {
							int ways = (int) ((long) tmp[j0][j1][has]
									* dp[pick] % P);
//							if (ways != 0) {
//								System.err.println(j0 + " " + j1 + " " + has
//										+ " " + pick + " " + ways);
//							}
							next[j0 ^ 1][j1 ^ pick][has | (1 << pick)] += ways;
							next[j0 ^ 1][j1 ^ pick][has | (1 << pick)] %= P;

						}
						next[j0][j1][has] += tmp[j0][j1][has];
						next[j0][j1][has] %= P;
					}
			tmp = next;
		}

//		System.err.println("!");
		int[] ret = new int[2];
		for (int j0 = 0; j0 < 2; j0++)
			for (int j1 = 0; j1 < 2; j1++)
				for (int has = 0; has < 4; has++) {
					if (tmp[j0][j1][has] != 0) {
						// System.err.println(j0 + " " + j1 + " " + has + " "
						// + tmp[j0][j1][has]);
					}
					if ((j0 & 1) == 0) {
						if (has == 2 || has == 3) {
							tmp[j0][j1][has] *= 2;
							tmp[j0][j1][has] %= P;
						}
					} else {
						if (has == 3) {
							tmp[j0][j1][has] *= 2;
							tmp[j0][j1][has] %= P;
						}
					}
					ret[j1] += tmp[j0][j1][has];
					ret[j1] %= P;
				}
		return ret;

	}

	void solve() throws IOException {
		int n = nextInt();
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>(0);
		}
		for (int i = 1; i < n; i++) {
			int p = nextInt() - 1;
			g[p].add(i);
		}

		int[] ans = go(0);
		out.println((ans[0] + ans[1]) % P);
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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