import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int INF = Integer.MAX_VALUE / 3;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		int s = nextInt();
		
		int dim2 = Math.min(n * (n - 1) / 2, k * (k - 1) / 2 + s);
		
		int[][] dp = new int[k + 1][dim2 + 1];
		for (int i = 0; i <= k; i++) {
			Arrays.fill(dp[i], INF);
		}
		dp[0][0] = 0;
		
		for (int pos = 0; pos < n; pos++) {
			int x = nextInt();
			
			for (int i = k - 1; i >= 0; i--)
				for (int j = dim2 - pos; j >= 0; j--) {
					dp[i + 1][j + pos] = Math.min(dp[i + 1][j + pos], dp[i][j] + x);
				}
//			System.err.println(Arrays.deepToString(dp));
		}
		
		int ret = INF;
		for (int i = k * (k - 1) / 2; i <= dim2; i++) {
			ret = Math.min(ret, dp[k][i]);
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