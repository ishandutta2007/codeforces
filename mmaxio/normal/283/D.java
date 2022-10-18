import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	boolean can(long q1, int pTwo1, long q2, int pTwo2, int dist) {
		if (q1 % q2 != 0)
			return false;
		
		if (pTwo2 == pTwo1 + dist) // don't set to zero
			return true;
		
		return pTwo2 < dist;
		
	}

	void solve() throws IOException {
		int n = nextInt();
		long[] a = new long[n];
		
		for (int i = 0; i < n; i++)
			a[i] = nextLong();
		
		int[] p2 = new int[n];
		
		for (int i = 0; i < n; i++) {
			while ((a[i] & 1) == 0) {
				p2[i]++;
				a[i] >>= 1;
			}
		}
		
		int[] dp = new int[n];
		
		int ans = 0;
		
		for (int i = 0; i < n; i++) {
			dp[i] = 1;
			for (int j = 0; j < i; j++) {
				if (can(a[j], p2[j], a[i], p2[i], i - j))
					dp[i] = Math.max(dp[i], dp[j] + 1);
			}
			ans = Math.max(ans, dp[i]);
		}
		
		out.println(n - ans);
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