import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int P = 1_000_000_007;

	String s;
	int[][] lcp;

	int compare(int p1, int p2, int len) {
		// System.err.println(p1 + " " + p2 + " " + len);
		int same = lcp[p1][p2];
		if (same >= len) {
			return 0;
		}
		return s.charAt(p1 + same) < s.charAt(p2 + same) ? -1 : 1;
	}

	void solve() throws IOException {
		int n = nextInt();
		s = nextToken();

		lcp = new int[n + 1][n + 1];
		for (int i = n - 1; i >= 0; i--)
			for (int j = n - 1; j >= 0; j--) {
				if (s.charAt(i) == s.charAt(j)) {
					lcp[i][j] = 1 + lcp[i + 1][j + 1];
				} else {
					lcp[i][j] = 0;
				}
			}

		int[][] dp = new int[n + 1][n + 1];
		dp[0][1] = 1;
		
//		System.err.println(Arrays.toString(dp[0]));

		int ret = 0;

		for (int l = 0; l < n; l++) {
			for (int mid = l + 1; mid <= n; mid++) {
				dp[l][mid] += dp[l][mid - 1];
				if (dp[l][mid] >= P) {
					dp[l][mid] -= P;
				}
			}
			
//			System.err.println(Arrays.toString(dp[l]));

			for (int mid = l + 1; mid < n; mid++) {
				if (s.charAt(mid) == '0') {
					continue;
				}
				int firstR = 2 * mid - l;
				if (firstR > n) {
					break;
				}
				if (compare(l, mid, mid - l) >= 0) {
					firstR++;
				}
//				System.err.println(l + " " + mid + " " + firstR);
				if (firstR <= n) {
					dp[mid][firstR] += dp[l][mid];
					if (dp[mid][firstR] >= P) {
						dp[mid][firstR] -= P;
					}
				}
			}

			ret += dp[l][n];
			if (ret >= P) {
				ret -= P;
			}
		}

		out.println(ret);
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
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