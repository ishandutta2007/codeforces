import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int MOD = 1000000007;
	static final int MAX = 100;
	static final int[][] c = new int[MAX + 1][];
	{
		for (int i = 0; i <= MAX; i++) {
			c[i] = new int[i + 1];
			c[i][0] = c[i][i] = 1;
			for (int j = 1; j < i; j++) {
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
				if (c[i][j] >= MOD)
					c[i][j] -= MOD;
			}
		}
	}

	int C(int n, int k) {
		if (n > MAX)
			throw new AssertionError();
		if (k < 0 || k > n || n < 0)
			return 0;
		return c[n][k];
	}

	int f(int[] cnt, int len) {
		int[] dp = new int[len + 1];
		dp[0] = 1;
		for (int i = 0; i < 10; i++) {
			int[] next = new int[len + 1];
			for (int j = cnt[i]; j <= len; j++)
				for (int prev = 0; prev + j <= len; prev++)
					if (dp[prev] != 0) {
						// (len - prev) places, j digits
						if (i == 0)
							next[prev + j] += (int) ((long) dp[prev]
									* C(len - prev - 1, j) % MOD);
						else
							next[prev + j] += (int) ((long) dp[prev]
									* C(len - prev, j) % MOD);
						if (next[prev + j] >= MOD)
							next[prev + j] -= MOD;
					}
			dp = next;
		}
		return dp[len];
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] atLeast = new int[10];
		int tot = 0;
		for (int i = 0; i < 10; i++) {
			atLeast[i] = nextInt();
			tot += atLeast[i];
		}
		int res = 0;
		for (int i = Math.max(1, tot); i <= n; i++) {
			res += f(atLeast, i);
			if (res >= MOD)
				res -= MOD;
		}
		out.println(res);
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B().inp();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	String nextString() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken("\n");
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