import java.io.*;
import java.util.*;

public class B {

	static final int INF = Integer.MAX_VALUE;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		int[] a = new int[n];
		Random rng = new Random();
		for (int i = 0; i < n; i++) {
			int j = rng.nextInt(i + 1);
			a[i] = a[j];
			a[j] = nextInt();
		}
		Arrays.sort(a);

		int sz2 = n / k;
		int sz1 = sz2 + 1;
		int cnt1 = n % k;
		int cnt2 = k - cnt1;

		int[][] dp = new int[cnt1 + 1][cnt2 + 1];
		for (int i = 0; i <= cnt1; i++) {
			Arrays.fill(dp[i], INF);
		}

		dp[0][0] = 0;
		for (int i1 = 0; i1 <= cnt1; i1++)
			for (int i2 = 0; i2 <= cnt2; i2++) {
				int cnt = i1 * sz1 + i2 * sz2;
				if (i1 < cnt1) {
					dp[i1 + 1][i2] = Math.min(dp[i1 + 1][i2], dp[i1][i2]
							+ a[cnt + sz1 - 1] - a[cnt]);
				}
				if (i2 < cnt2) {
					dp[i1][i2 + 1] = Math.min(dp[i1][i2 + 1], dp[i1][i2]
							+ a[cnt + sz2 - 1] - a[cnt]);
				}
			}

		out.println(dp[cnt1][cnt2]);

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