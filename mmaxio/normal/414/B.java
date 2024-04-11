import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int MOD = 1000000007;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		int[] dp = new int[n + 1];
		int[] next = new int[n + 1];
		Arrays.fill(dp, 1);
		for (int i = 2; i <= k; i++) {
			Arrays.fill(next, 0);
			for (int j = 1; j <= n; j++) {
				for (int jj = j; jj <= n; jj += j) {
					next[jj] += dp[j];
					if (next[jj] >= MOD) {
						next[jj] -= MOD;
					}
				}
			}
			int[] tmp = dp;
			dp = next;
			next = tmp;
		}
		
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = (ans + dp[i]) % MOD;
		}
		
		out.println(ans);
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