import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		double[] a = new double[n];
		for (int i = 0; i < n; i++) {
			a[i] = 1 - nextDouble();
		}
		Arrays.sort(a);
		
		double ans = 0;
		
		for (int i = 0; i <= n; i++)
			for (int j = i; j <= n; j++) {
				// [0; i) and [j; n)
				if (i == 0 && j == n) {
					continue;
				}
				double p0 = 1;
				double p1 = 0;
				for (int k = 0; k < i; k++) {
					p1 = p0 * (1 - a[k]) + p1 * a[k];
					p0 *= a[k];
				}
				for (int k = j; k < n; k++) {
					p1 = p0 * (1 - a[k]) + p1 * a[k];
					p0 *= a[k];
				}
				ans = Math.max(ans, p1);
			}
		out.printf(Locale.US, "%.12f\n", ans);
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