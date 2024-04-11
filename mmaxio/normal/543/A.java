import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int tot = nextInt();
		int maxErr = nextInt();
		int mod = nextInt();

		int[][] dp = new int[tot + 1][maxErr + 1];
		dp[0][0] = 1 % mod;
		for (int zzz = 0; zzz < n; zzz++) {
			int errByLine = nextInt();
			for (int i = 1; i <= tot; i++)
				for (int j = errByLine; j <= maxErr; j++) {
					dp[i][j] += dp[i - 1][j - errByLine];
					if (dp[i][j] >= mod) {
						dp[i][j] -= mod;
					}
				}
		}

		int ret = 0;
		for (int i = 0; i <= maxErr; i++) {
			ret += dp[tot][i];
			if (ret >= mod) {
				ret -= mod;
			}
		}
		out.println(ret);
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
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