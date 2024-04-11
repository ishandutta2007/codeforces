import java.io.*;
import java.util.*;

public class B {

	static final int INF = Integer.MAX_VALUE;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static int[] prefixFunction(char[] s) {
		int[] pi = new int[s.length];
		for (int i = 1; i < s.length; i++) {
			int q = pi[i - 1];
			while (q > 0 && s[i] != s[q])
				q = pi[q - 1];
			if (s[i] == s[q])
				q++;
			pi[i] = q;
		}
		return pi;
	}

	void solve() throws IOException {
		char[] a = nextToken().toCharArray();
		char[] b = nextToken().toCharArray();

		char[] v = nextToken().toCharArray();
		int[] pi = prefixFunction(v);

		int[][] to = new int[v.length][26];
		for (int i = 0; i < v.length; i++) {
			int curCh = v[i] - 'A';
			for (int ch = 0; ch < 26; ch++) {
				if (i > 0 && ch != curCh) {
					to[i][ch] = to[pi[i - 1]][ch];
				} else {
					to[i][ch] = i + (ch == curCh ? 1 : 0);
				}
			}
		}

		int[][][] dp = new int[a.length + 1][b.length + 1][v.length];
		int[][][] prevState = new int[a.length + 1][b.length + 1][v.length]; // -1
		// >= 0 if letter appending
		// -1 go to (i - 1, j)
		// -2 go to (i, j - 1)

		for (int i = 0; i <= a.length; i++)
			for (int j = 0; j <= b.length; j++) {
				Arrays.fill(dp[i][j], -1);
			}

		dp[0][0][0] = 0;
		for (int i = 0; i <= a.length; i++)
			for (int j = 0; j <= b.length; j++)
				for (int k = 0; k < v.length; k++) {
					int val = dp[i][j][k];
					if (val == -1)
						continue;
					// System.err.println(i + " " + j + " " + k + " " + val);
					if (i < a.length && dp[i + 1][j][k] < val) {
						dp[i + 1][j][k] = val;
						prevState[i + 1][j][k] = -1;
					}
					if (j < b.length && dp[i][j + 1][k] < val) {
						dp[i][j + 1][k] = val;
						prevState[i][j + 1][k] = -2;
					}
					if (i < a.length && j < b.length && a[i] == b[j]) {
						int newK = to[k][a[i] - 'A'];
						if (newK != v.length) {
							if (dp[i + 1][j + 1][newK] < val + 1) {
								dp[i + 1][j + 1][newK] = val + 1;
								prevState[i + 1][j + 1][newK] = k;
							}
						}
					}
				}

		int ans = -1;
		int lastState = -1;
		for (int i = 0; i < v.length; i++) {
			if (dp[a.length][b.length][i] > ans) {
				ans = dp[a.length][b.length][i];
				lastState = i;
			}
		}

		if (ans <= 0) {
			out.println(0);
			return;
		}

		StringBuilder sb = new StringBuilder();
		int curI = a.length;
		int curJ = b.length;
		int curSt = lastState;

		while (curI > 0 || curJ > 0) {
			int tmp = prevState[curI][curJ][curSt];
			if (tmp >= 0) {
				sb.append(a[curI - 1]);
				curSt = prevState[curI][curJ][curSt];
				curI--;
				curJ--;
			} else if (tmp == -1) {
				curI--;
			} else if (tmp == -2) {
				curJ--;
			} else
				throw new AssertionError();
		}

		out.println(sb.reverse().toString());
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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