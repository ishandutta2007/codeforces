import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int n, m;

	double[][] pr;

	double[] calcNext(double[] dp, double[] pr) {
		double[] next = new double[n + 1];
		next[0] = 0;
		for (int j = 0; j < n; j++)
			next[j + 1] = dp[j] * pr[j] + next[j] * (1 - pr[j]);
		return next;
	}

	void solve() throws IOException {
		n = nextInt(); // men
		m = nextInt(); // sizes

		pr = new double[m][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				pr[j][i] = nextInt() * 0.001;

		double[][] dp = new double[m][n + 1];
		for (int i = 0; i < m; i++) {
			Arrays.fill(dp[i], 1);
			dp[i] = calcNext(dp[i], pr[i]);
		}

		double ans = 0;
		for (int i = 0; i < n; i++) {
			double best = -1;
			int pos = -1;
			for (int j = 0; j < m; j++)
				if (dp[j][n] > best) {
					best = dp[j][n];
					pos = j;
				}
			ans += best;
			dp[pos] = calcNext(dp[pos], pr[pos]);
		}
		
		out.printf(Locale.US, "%.12f\n", ans);
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D().inp();
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