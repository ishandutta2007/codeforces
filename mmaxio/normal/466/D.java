import java.io.*;
import java.util.*;

public class D {

	static final int P = 1_000_000_007;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int h = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		int[] d = new int[n + 1];
		d[0] = a[0];
		d[n] = -a[n - 1];
		for (int i = 1; i < n; i++) {
			d[i] = a[i] - a[i - 1];
		}
		int[] need = new int[n + 1];
		need[0] = h;
		need[n] = -h;
		for (int i = 0; i <= n; i++) {
			if (Math.abs(d[i] - need[i]) > 1) {
				out.println(0);
				return;
			}
			d[i] -= need[i];
		}
		int[] dp = new int[n + 1];
		dp[0] = 1;
		for (int i = 0; i <= n; i++) {
			int[] next = new int[n + 1];
			// System.err.println(d[i]);
			if (d[i] == -1) {
				for (int j = 1; j <= n; j++) {
					next[j] = dp[j - 1];
				}
			} else if (d[i] == 1) {
				for (int j = 0; j < n; j++) {
					next[j] = (int) ((long) dp[j + 1] * (j + 1) % P);
				}
			} else {
				// nothing
				System.arraycopy(dp, 0, next, 0, n + 1);
				for (int j = 1; j <= n; j++) {
					next[j] += (int) ((long) j * dp[j] % P);
					next[j] %= P;
				}
			}
			dp = next;
			// System.err.println(Arrays.toString(dp));
		}
		out.println(dp[0]);
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