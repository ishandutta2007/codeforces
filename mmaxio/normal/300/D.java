import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int MOD = 7340033;
	
	int[][] dp;
	
	int[] sqr(int[] a) {
		int[] res = new int[a.length];
		for (int i = 0; i < a.length; i++)
			for (int j = 0; j <= i; j++) {
				res[i] += (int)((long)a[j] * a[i - j] % MOD);
				if (res[i] >= MOD)
					res[i] -= MOD;
			}
		return res;
	}

	void preCalc() {
		dp = new int[30][1001];
		dp[0][0] = 1;
		for (int i = 1; i < 30; i++) {
			int[] tmp = sqr(sqr(dp[i - 1]));
			dp[i][0] = 1;
			for (int j = 1; j <= 1000; j++)
				dp[i][j] = tmp[j - 1];
		}
	}

	int solve(int n, int k) {
		int tmp = 0;
		while ((n & 1) == 1 && n > 1) {
			tmp++;
			n = (n - 1) >> 1;
		}
//		System.err.println(n + " " + k);
		return dp[tmp][k];
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		int q = nextInt();
		while (q-- > 0) {
			out.println(solve(nextInt(), nextInt()));
		}
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