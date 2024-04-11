import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();

		int[] coins = new int[n];
		for (int i = 0; i < n; i++) {
			coins[i] = nextInt();
		}

		boolean[][] dp = new boolean[k + 1][k + 1];
		dp[0][0] = true;

		for (int x : coins) {
			for (int s1 = k; s1 >= 0; s1--)
				for (int s2 = k - x; s2 >= 0; s2--) {
					if (!dp[s1][s2]) {
						continue;
					}
					if (s1 + x <= k) {
						dp[s1 + x][s2 + x] = true;
					}
					dp[s1][s2 + x] = true;
				}
		}
		
		int cnt = 0;
		for (int i = 0; i <= k; i++) {
			if (dp[i][k]) {
				cnt++;
			}
		}
		
		out.println(cnt);
		for (int i = 0; i <= k; i++) {
			if (dp[i][k]) {
				out.print(i + " ");
			}
		}
		out.println();
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