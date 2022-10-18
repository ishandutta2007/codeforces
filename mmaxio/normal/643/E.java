import java.io.*;
import java.util.*;

public class F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int K = 110;
	static final int N = 500_000;

	double[][] dp = new double[N][K];
	int[] par = new int[N];

	void solve() throws IOException {
		int q = nextInt();

		for (int i = 0; i < N; i++)
			Arrays.fill(dp[i], 1);

		par[0] = -1;

		int curV = 1;

		while (q-- > 0) {
			int type = nextInt();
			int v = nextInt() - 1;
			if (type == 2) {
				double ret = 0;
				double[] ds = dp[v];
				for (int i = 0; i < ds.length; i++) {
					double prob = ds[i];
					ret += 1 - prob;
				}
				out.println(ret);
			} else {
				int u = curV++;
				par[u] = v;

				double old = dp[v][0];
				dp[v][0] *= 0.5;
				v = par[v];
				u = par[u];
				int k = 1;
				while (k < K && v != -1) {
					
					double nextOld = dp[v][k];
					dp[v][k] /= 0.5 * (1 + old);
					dp[v][k] *= 0.5 * (1 + dp[u][k - 1]);
					
					k++;
					v = par[v];
					u = par[u];
					old = nextOld;
				}

			}
		}
	}

	F() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new F();
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