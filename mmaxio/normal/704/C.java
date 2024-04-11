import java.io.*;
import java.util.*;

public class C {

	static final int P = 1_000_000_007;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Edge {
		int from, to;

		int signFrom, signTo, id;

		public Edge(int signFrom, int signTo, int id) {
			this.signFrom = signFrom;
			this.signTo = signTo;
			this.id = id;
			from = Math.abs(signFrom);
			to = Math.abs(signTo);
		}

	}

	int eval(int x, int y, int signX, int signY) {
		return ((x == 0) == (signX < 0)) || ((y == 0) == (signY < 0)) ? 1 : 0;
	}

	int solve(int m, int n, int[][] a) {
		int rhs = 1;

		List<Edge>[] g;
		g = new List[n + 1];
		for (int i = 1; i <= n; i++) {
			g[i] = new ArrayList<>(2);
		}

		boolean[] inLhs = new boolean[n + 1];

		for (int i = 0; i < m; i++) {
			int k = a[i].length;
			int[] tmp = a[i];
			if (k == 2 && tmp[0] == tmp[1]) {
				k = 1;
				tmp = new int[] { tmp[0] };
			}
			if (k == 2 && tmp[0] == -tmp[1]) {
				rhs ^= 1;
				continue;
			}

			// System.err.println(tmp[0] + " " + tmp[1]);

			if (k == 2) {
				g[Math.abs(tmp[0])].add(new Edge(tmp[0], tmp[1], i));
				g[Math.abs(tmp[1])].add(new Edge(tmp[1], tmp[0], i));
			} else {
				inLhs[Math.abs(tmp[0])] ^= true;
				if (tmp[0] < 0) {
					rhs ^= 1;
				}
			}
		}

		int[] ret = { 1, 0 };

		boolean[] vis = new boolean[n + 1];
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && g[i].size() == 1) {

				int[][][] dp = new int[2][2][2]; // first, last, value
				dp[0][0][0]++;
				dp[1][1][inLhs[i] ? 1 : 0]++;

				vis[i] = true;
				int v = i;
				Edge e = g[v].get(0);
				while (true) {
					int u = e.to;
					vis[u] = true;

					int signU = e.signTo;
					int signV = e.signFrom;

					int[][][] nxt = new int[2][2][2];

					for (int first = 0; first < 2; first++)
						for (int prev = 0; prev < 2; prev++)
							for (int value = 0; value < 2; value++) {
								for (int now = 0; now < 2; now++) {

									int newValue = value
											^ ((inLhs[u] && now == 1) ? 1 : 0)
											^ eval(prev, now, signV, signU);

									nxt[first][now][newValue] += dp[first][prev][value];
									nxt[first][now][newValue] %= P;
								}
							}

					dp = nxt;

					if (g[u].size() == 1) {
						break;
					}

					Edge newE = g[u].get(g[u].get(0).id == e.id ? 1 : 0);

					v = u;
					e = newE;
				}

				int[] ways = new int[2];
				for (int first = 0; first < 2; first++)
					for (int last = 0; last < 2; last++)
						for (int value = 0; value < 2; value++) {
							ways[value] += dp[first][last][value];
							ways[value] %= P;
						}

				int[] newRet = new int[2];
				for (int was = 0; was < 2; was++)
					for (int now = 0; now < 2; now++) {
						newRet[(was + now) % 2] += (int) ((long) ret[was]
								* ways[now] % P);
						newRet[(was + now) % 2] %= P;
					}

				ret = newRet;
			}
		}
		
//		System.err.println(Arrays.toString(ret));
//		System.err.println(rhs);
//		System.err.println(Arrays.toString(inLhs));

		for (int i = 1; i <= n; i++) {
			if (!vis[i] && g[i].size() == 2) {

				int[][][] dp = new int[2][2][2]; // first, last, value
				dp[0][0][0]++;
				dp[1][1][inLhs[i] ? 1 : 0]++;

				vis[i] = true;
				int v = i;
				Edge e = g[v].get(0);
				while (true) {
					int u = e.to;
					if (u == i) {
						break;
					}
					vis[u] = true;

					int signU = e.signTo;
					int signV = e.signFrom;

					int[][][] nxt = new int[2][2][2];

					for (int first = 0; first < 2; first++)
						for (int prev = 0; prev < 2; prev++)
							for (int value = 0; value < 2; value++) {
								for (int now = 0; now < 2; now++) {

									int newValue = value
											^ (inLhs[u] && now == 1 ? 1 : 0)
											^ eval(prev, now, signV, signU);

									nxt[first][now][newValue] += dp[first][prev][value];
									nxt[first][now][newValue] %= P;
								}
							}

					dp = nxt;

					if (g[u].size() == 1) {
						throw new AssertionError();
					}

					Edge newE = g[u].get(g[u].get(0).id == e.id ? 1 : 0);

					v = u;
					e = newE;
				}

				int[][][] nxt = new int[2][2][2];

				for (int first = 0; first < 2; first++)
					for (int last = 0; last < 2; last++)
						for (int value = 0; value < 2; value++) {

							int newValue = value
									^ eval(last, first, e.signFrom, e.signTo);

							nxt[first][last][newValue] += dp[first][last][value];
							nxt[first][last][newValue] %= P;
						}

				dp = nxt;

				int[] ways = new int[2];
				for (int first = 0; first < 2; first++)
					for (int last = 0; last < 2; last++)
						for (int value = 0; value < 2; value++) {
							ways[value] += dp[first][last][value];
							ways[value] %= P;
						}

				int[] newRet = new int[2];
				for (int was = 0; was < 2; was++)
					for (int now = 0; now < 2; now++) {
						newRet[(was + now) % 2] += (int) ((long) ret[was]
								* ways[now] % P);
						newRet[(was + now) % 2] %= P;
					}

				ret = newRet;
			}
		}

		for (int i = 1; i <= n; i++) {
			if (g[i].isEmpty()) {
				int[] newRet = new int[2];
				for (int was = 0; was < 2; was++)
					for (int now = 0; now < 2; now++) {

						int newIdx = (was + ((now == 1 && inLhs[i]) ? 1 : 0)) % 2;
						newRet[newIdx] += ret[was];
						newRet[newIdx] %= P;
					}

				ret = newRet;
			}
		}

		return ret[rhs];
	}

	int brute(int m, int n, int[][] a) {
		int ret = 0;
		for (int mask = 0; mask < 1 << n; mask++) {
			int cur = 0;
			outer: for (int i = 0; i < m; i++) {
				for (int j = 0; j < a[i].length; j++) {
					int have = get(mask, Math.abs(a[i][j]) - 1);
					int need = a[i][j] < 0 ? 0 : 1;
					if (have == need) {
						cur ^= 1;
						continue outer;
					}
				}
			}
			if (cur == 1) {
				ret++;
			}
		}
		return ret;
	}
	
	int get(int mask, int i) {
		return (mask >> i) & 1;
	}
	
	Random rng = new Random();
	
	void oneTest(int n) throws IOException {
		int m = rng.nextInt(n);
		int[] cnt = new int[n];
		int[][] a = new int[m][];
		for (int i = 0; i < m; i++) {
			int k = rng.nextInt(2) + 1;
			a[i] = new int[k];
			for (int j = 0; j < k; j++) {
				int idx;
				do {
					idx = rng.nextInt(n);
				} while (cnt[idx] == 2);
				cnt[idx]++;
				a[i][j] = (idx + 1) * (rng.nextBoolean() ? -1 : 1);
			}
		}
		
		System.err.println(m + " " + n + " " + Arrays.deepToString(a));
		
		int wrong = solve(m, n, a);
		int slow = brute(m, n, a);
		if (wrong != slow) {
			throw new AssertionError(m + " " + n + " " + Arrays.deepToString(a));
		}
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		int m = nextInt();
		int n = nextInt();
		int[][] a = new int[m][];
		for (int i = 0; i < m; i++) {
			int k = nextInt();
			a[i] = new int[k];
			for (int j = 0; j < k; j++) {
				a[i][j] = nextInt();
			}
		}
		out.println(solve(m, n, a));
//		out.println(brute(m, n, a));
		out.close();
		
//		while (true) {
//			oneTest(4);
//		}
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