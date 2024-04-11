import java.io.*;
import java.util.*;

public class B {

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

		int[] dp = new int[n + 1];

		for (int i = 0; i < n; i++) {
			dp[i + 1] = dp[i] + 20;

			{
				int pos = Arrays.binarySearch(a, a[i] - 90);

				if (pos >= 0) {
					pos++;
				} else {
					pos = -pos - 1;
				}

				dp[i + 1] = Math.min(dp[i + 1], dp[pos] + 50);
			}

			{
				int pos = Arrays.binarySearch(a, a[i] - 1440);

				if (pos >= 0) {
					pos++;
				} else {
					pos = -pos - 1;
				}

				dp[i + 1] = Math.min(dp[i + 1], dp[pos] + 120);
			}
		}
		
		for (int i = 0; i < n; i++) {
			out.println(dp[i + 1] - dp[i]);
		}
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