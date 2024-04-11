import java.io.*;
import java.util.*;

public class C_new {

	static final int INF = Integer.MAX_VALUE / 3;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int getNext(String s, int st, String p) {
		int i = 0;
		while (st < s.length() && i < p.length()) {
			if (s.charAt(st) == p.charAt(i)) {
				i++;
			}
			st++;
		}
		if (i == p.length()) {
			return st;
		}
		return -1;
	}

	void solve() throws IOException {
		String s = nextToken();
		String p = nextToken();
		int[] next = new int[s.length()];
		for (int i = 0; i < s.length(); i++) {
			next[i] = getNext(s, i, p);
		}
		;
		int n = s.length();
		int k = p.length();
		int[][] dp = new int[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			Arrays.fill(dp[i], INF);
		}
		dp[0][0] = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (dp[i][j] != INF) {
					dp[i + 1][j] = Math.min(dp[i + 1][j], dp[i][j]);
					if (next[i] != -1) {
						dp[next[i]][j + 1] = Math.min(dp[next[i]][j + 1],
								dp[i][j] + next[i] - i - k);
					}
				}
			}
		int full = 0;
		int[] info = dp[n];
		for (int i = 0; i <= n; i++) {
			if (info[i] != INF) {
				full = i;
			}
		}
		int[] ans = new int[n + 1];
		for (int i = 0; i <= n; i++) {
			if (info[i] != INF) {
				for (int j = info[i]; j <= n; j++) {
					ans[j] = i;
				}
			}
		}
		for (int i = 0; i < full; i++) {
			for (int j = k * i; j < k * i + k; j++) {
				ans[n - j] = i;
			}
		}
		for (int x  : ans) {
			out.print(x + " ");
		}
		out.println();
	}

	C_new() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C_new();
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