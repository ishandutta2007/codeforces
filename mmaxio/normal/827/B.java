import java.io.*;
import java.util.*;

public class B {

	void submit() {
		int n = nextInt();
		int k = nextInt();
		solve(n, k);
	}

	static final int INF = Integer.MAX_VALUE / 3;

	void slowSolve(int n, int k) {
		System.err.println(n + " " + k);
		int rest = n - k;

		if (rest == 1) {
			return;
		}

		int[][] g = new int[n][n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(g[i], INF);
			g[i][i] = 0;
		}

		for (int ans = 2;; ans++) {

			int lowRest = ans - 1;
			long highRest;
			if (ans % 2 == 0) {
				highRest = 1 + (long) k * (ans / 2 - 1);
			} else {
				highRest = 2 + (long) k * (ans / 2 - 1);
			}

			if (lowRest <= rest && rest <= highRest) {
				// out.println(ans);

				int len = ans / 2 - 1;

				int[] deg = new int[rest];

				if (ans % 2 == 0) {

					for (int i = 1; i < rest; i++) {

						if (i % len == 1 % len) {
							// out.println("1 " + (i + 1));
							deg[0]++;
							deg[i]++;
							g[0][i] = g[i][0] = 1;
						} else {
							// out.println(i + " " + (i + 1));
							deg[i - 1]++;
							deg[i]++;
							g[i][i - 1] = g[i - 1][i] = 1;
						}

					}

				} else {
					// out.println("1 2");
					deg[0]++;
					deg[1]++;
					g[0][1] = g[1][0] = 1;
					for (int i = 2; i < rest; i++) {
						if (i == 2) {
							// out.println("1 " + (i + 1));
							deg[0]++;
							deg[i]++;
							g[0][i] = g[i][0] = 1;
						} else if (i % len == 2 % len) {
							// out.println("2 " + (i + 1));
							deg[1]++;
							deg[i]++;
							g[1][i] = g[i][1] = 1;
						} else {
							// out.println(i + " " + (i + 1));
							deg[i]++;
							deg[i - 1]++;
							g[i][i - 1] = g[i - 1][i] = 1;
						}
					}
				}

				// System.err.println(ans);

				List<Integer> leaves = new ArrayList<>();
				for (int i = 0; i < rest; i++) {
					if (deg[i] == 0) {
						throw new AssertionError();
					}
					if (deg[i] == 1) {
						leaves.add(i);
					}
				}

				if (leaves.size() > k) {
					throw new AssertionError();
				}

				for (int i = rest; i < n; i++) {
					// out.println((i + 1) + " "
					// + (leaves.get((i - rest) % leaves.size()) + 1));
					int ii = leaves.get((i - rest) % leaves.size());
					g[i][ii] = g[ii][i] = 1;
				}
				
//				System.err.println(Arrays.deepToString(g));

				for (int kk = 0; kk < n; kk++) {
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < n; j++) {
							g[i][j] = Math.min(g[i][j], g[i][kk] + g[kk][j]);
						}
					}
				}

				int diam = -1;
				for (int[] row : g) {
					for (int x : row) {
						diam = Math.max(diam, x);
					}
				}
				
//				System.err.println(diam + " " + ans);
				
				if (diam != ans) {
					throw new AssertionError(n + " " + k);
				}
				return;
			}

		}
	}

	void solve(int n, int k) {
		int rest = n - k;

		if (rest == 1) {
			out.println(2);
			for (int i = 1; i < n; i++) {
				out.println("1 " + (i + 1));
			}
			return;
		}

		for (int ans = 2;; ans++) {

			int lowRest = ans - 1;
			long highRest;
			if (ans % 2 == 0) {
				highRest = 1 + (long) k * (ans / 2 - 1);
			} else {
				highRest = 2 + (long) k * (ans / 2 - 1);
			}

			if (lowRest <= rest && rest <= highRest) {
				out.println(ans);

				int len = ans / 2 - 1;

				int[] deg = new int[rest];

				if (ans % 2 == 0) {

					for (int i = 1; i < rest; i++) {

						if (i % len == 1 % len) {
							out.println("1 " + (i + 1));
							deg[0]++;
							deg[i]++;
						} else {
							out.println(i + " " + (i + 1));
							deg[i - 1]++;
							deg[i]++;
						}

					}

				} else {
					out.println("1 2");
					deg[0]++;
					deg[1]++;
					for (int i = 2; i < rest; i++) {
						if (i == 2) {
							out.println("1 " + (i + 1));
							deg[0]++;
							deg[i]++;
						} else if (i % len == 2 % len) {
							out.println("2 " + (i + 1));
							deg[1]++;
							deg[i]++;
						} else {
							out.println(i + " " + (i + 1));
							deg[i]++;
							deg[i - 1]++;
						}
					}
				}

				// System.err.println(ans);

				List<Integer> leaves = new ArrayList<>();
				for (int i = 0; i < rest; i++) {
					if (deg[i] == 0) {
						throw new AssertionError();
					}
					if (deg[i] == 1) {
						leaves.add(i);
					}
				}

				if (leaves.size() > k) {
					throw new AssertionError();
				}

				for (int i = rest; i < n; i++) {
					out.println((i + 1) + " "
							+ (leaves.get((i - rest) % leaves.size()) + 1));
				}

				return;
			}

		}
	}

	void preCalc() {

	}

	void stress() {
		for (int n = 2; n <= 10; n++) {
			for (int k = 2; k < n; k++) {
				slowSolve(n, k);
			}
		}
	}

	void test() {

	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
//		 stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new B();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}