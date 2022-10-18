import java.io.*;
import java.util.*;

public class D {

	static final double EPS = 1e-7;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		int[][] c = new int[n][n];
		for (int i = 0; i < n; i++) {
			c[i][i] = -1;
			for (int j = i + 1; j < n; j++) {
				c[j][i] = c[i][j] = nextInt();
			}
		}

		double ans = 0;

		for (int i = 0; i < n; i++) {
			long sum = 0;
			int sz = 0;
			for (int j = 0; j < n; j++) {
				if (c[i][j] != -1) {
					sum += c[i][j];
					sz++;
				}
			}
			if (sz < k)
				continue;
			double prob = 1;
			if (k < n - sz) {
				for (int j = 0; j < k; j++)
					prob = prob * (sz - j) / (n - j);
			} else {
				for (int j = sz + 1; j <= n; j++)
					prob = prob * (j - k) / j;
			}
			ans += prob * sum / sz;
		}

		ans *= k;

		double round = Math.round(ans);
		if (Math.abs(round - ans) < EPS) {
			ans = round;
		}

		long longAns = (long) Math.floor(ans);
		out.println(longAns);
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