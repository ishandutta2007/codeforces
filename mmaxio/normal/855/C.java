import java.io.*;
import java.util.*;

public class C {

	static final int P = 1_000_000_007;

	int[] next;
	int[] head;
	int[] to;

	int ptr = 0;

	void addEdge(int v, int u) {
		next[ptr] = head[v];
		head[v] = ptr;
		to[ptr] = u;
		ptr++;
	}

	int k, cnt, total;

	void submit() {
		int n = nextInt();
		total = nextInt() - 1;

		next = new int[2 * n - 2];
		head = new int[n];
		to = new int[2 * n - 2];
		Arrays.fill(head, -1);

		for (int i = 0; i < n - 1; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			addEdge(v, u);
			addEdge(u, v);
		}

		k = nextInt() - 1;
		cnt = nextInt();

		dp = new int[n][3][cnt + 1];

		dfs(0, -1);
		
		int ans = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j <= cnt; j++) {
				int delta = dp[0][i][j];
				if (i == 0) {
					delta = (int)((long)delta * total % P);
				}
				
				ans += delta;
				if (ans >= P) {
					ans -= P;
				}
			}
		}
		
		out.println(ans);
	}

	int[][][] dp;

	void dfs(int v, int p) {
		int[][] here = dp[v];


		int[] onlyNo = new int[cnt + 1];
		int[] noOrYes = new int[cnt + 1];
		
		int[] paint = new int[cnt + 1];
		
		onlyNo[0] = 1;
		noOrYes[0] = 1;
		paint[1] = 1;
		
		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			if (u == p) {
				continue;
			}
			
			dfs(u, v);

			int[][] there = dp[u];

			for (int i = cnt; i >= 0; i--) {
				for (int j = cnt - i; j >= 0; j--) {
					{
						int delta = (int) ((long) onlyNo[i] * there[0][j] % P
								* total % P);
						delta += (int) ((long) onlyNo[i] * there[1][j] % P);
						if (delta >= P) {
							delta -= P;
						}

						if (j > 0) {
							onlyNo[i + j] += delta;
							if (onlyNo[i + j] >= P) {
								onlyNo[i + j] -= P;
							}
						} else {
							onlyNo[i + j] = delta;
						}
					}
					
					{
						int delta = (int) ((long) noOrYes[i] * there[0][j] % P
								* total % P);
						delta += (int) ((long) noOrYes[i] * there[1][j] % P);
						if (delta >= P) {
							delta -= P;
						}
						delta += (int) ((long)noOrYes[i] * there[2][j] % P);
						if (delta >= P) {
							delta -= P;
						}

						if (j > 0) {
							noOrYes[i + j] += delta;
							if (noOrYes[i + j] >= P) {
								noOrYes[i + j] -= P;
							}
						} else {
							noOrYes[i + j] = delta;
						}
					}
					
					{
						int delta = (int) ((long) paint[i] * there[0][j] % P
								* k % P);
						delta += (int) ((long) paint[i] * there[1][j] % P);
						if (delta >= P) {
							delta -= P;
						}

						if (j > 0) {
							paint[i + j] += delta;
							if (paint[i + j] >= P) {
								paint[i + j] -= P;
							}
						} else {
							paint[i + j] = delta;
						}
					}

				}
			}

		}
		
		for (int i = 0; i <= cnt; i++) {
			here[0][i] = onlyNo[i];
			
			here[1][i] = noOrYes[i] - onlyNo[i];
			if (here[1][i] < 0) {
				here[1][i] += P;
			}
			here[1][i] = (int)((long)here[1][i] * k % P);
			
			here[2][i] = paint[i];
			
		}
		
//		System.err.println(v + " " + Arrays.deepToString(dp[v]));
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new C();
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