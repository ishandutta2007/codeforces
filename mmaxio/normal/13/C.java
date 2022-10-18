import java.io.*;
import java.util.*;

public class cf13C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	int[] unique(int[] a) {
		a = a.clone();
		Arrays.sort(a);
		int sz = 1;
		for (int i = 1; i < a.length; i++) {
			if (a[i] != a[sz - 1]) {
				a[sz++] = a[i];
			}
		}
		return Arrays.copyOf(a, sz);
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		int[] b = unique(a);
		int m = b.length;
		long[] dp = new long[m];
		for (int i = 0; i < n; i++) {
			long[] next = new long[m];
			for (int j = 0; j < m; j++) {
				next[j] = Math.min(j == 0 ? Long.MAX_VALUE : next[j - 1], dp[j] + Math.abs(a[i] - b[j]));
			}
			dp = next;
		}
		long ret = Long.MAX_VALUE;
		for (long x : dp) {
			ret = Math.min(ret, x);
		}
		out.println(ret);
	}

	cf13C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new cf13C();
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