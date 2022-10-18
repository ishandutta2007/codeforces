import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int MOD = 1000000007;
	
	int f(int n, int k) {
		int[] dp = new int[n + 1];
		dp[0] = 1;
		int ret = 0;
		for (int it = 0; it < n; it++) {
			for (int i = n; i >= 0; i--) {
				dp[i] = 0;
				for (int j = 1; j <= k; j++) {
					if (i >= j) {
						dp[i] = (dp[i] + dp[i - j]) % MOD;
					}
				}
			}
			ret = (ret + dp[n]) % MOD;
		}
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		int d = nextInt();
		int res = f(n, k) - f(n, d - 1);
		if (res < 0) {
			res += MOD;
		}
		out.println(res);
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