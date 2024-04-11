import java.io.*;
import java.util.*;

public class B {

	static final int INF = Integer.MAX_VALUE / 3;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		
		int[][] dp = new int[n + 1][n];
		
		for (int len = 1; len <= n; len++) {
			for (int l = 0; l + len <= n; l++) {
				int r = l + len - 1;
				
				dp[l][r] = 1 + dp[l + 1][r]; // remove first
				for (int mid = l + 1; mid <= r; mid++) {
					if (a[l] == a[mid]) {
						
						int val = dp[mid + 1][r];
						if (l + 1 == mid) {
							val++;
						} else {
							val += dp[l + 1][mid - 1];
						}
						
						dp[l][r] = Math.min(dp[l][r], val);
					}
				}
				
			}
		}
		
		out.println(dp[0][n - 1]);
		
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