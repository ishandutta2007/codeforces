import java.io.*;
import java.util.*;

public class B {

	static final int P = 1_000_000_007;

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;

	void solve() throws IOException {
		int n = nextInt();
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>(0);
		}
		for (int i = 1; i < n; i++) {
			g[nextInt()].add(i);
		}
		int[] col = new int[n];

		for (int i = 0; i < n; i++) {
			col[i] = nextInt();
		}

		int[][] dp = new int[n][2];
		for (int i = n - 1; i >= 0; i--) {
			dp[i][col[i]] = 1;
			for (int to : g[i]) {
				int new1 = 0;
				int new0 = 0;
				// take
				new1 = (int) ((long) dp[i][1] * dp[to][0] % P + (long) dp[i][0]
						* dp[to][1] % P)
						% P;
				new0 = (int) ((long) dp[i][0] * dp[to][0] % P);
				// skip
				new1 += (int) ((long) dp[i][1] * dp[to][1] % P);
				new1 %= P;
				new0 += (int) ((long) dp[i][0] * dp[to][1] % P);
				new0 %= P;
				dp[i][0] = new0;
				dp[i][1] = new1;
			}
		}

		out.println(dp[0][1]);
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