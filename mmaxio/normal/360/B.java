import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		
		if (n == 1 || k >= n - 1) {
			out.println(0);
			return;
		}
		
		int low = -1;
		int high = 2_000_000_000;
		
		int[] dp = new int[n];
		
		while (low + 1 < high) {
			int mid = (int)(((long)low + high) >> 1);
			
			int best = Integer.MAX_VALUE;
		
			for (int i = 0; i < n; i++) {
				// edit all numbers before
				dp[i] = i;
				
				for (int j = 0; j < i; j++) {
					if (Math.abs(a[i] - a[j]) > (long)mid * (i - j)) {
						continue;
					}
					// System.err.println(i + " " + j + " " + (dp[j] + i - j - 1));
					dp[i] = Math.min(dp[i], dp[j] + i - j - 1);
				}
				// edit all after
				best = Math.min(best, dp[i] + (n - i - 1));
			}
			
			if (best <= k) {
				high = mid;
			} else {
				low = mid;
			}
		}
		
		out.println(high);
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