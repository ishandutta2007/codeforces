import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		if (k > n + m - 2) {
			out.println(-1);
			return;
		}

		long ans = 0;

		for (int a = 0; a < 10000; a++) {
			long b = k - a;
			if (a < 0 || a >= n || b < 0 || b >= m) {
				continue;
			}
			ans = Math.max(ans, (long) (n / (a + 1)) * (long) (m / (b + 1)));
		}

		for (int a = n - 10000; a < n; a++) {
			long b = k - a;
			if (a < 0 || a >= n || b < 0 || b >= m) {
				continue;
			}
			ans = Math.max(ans, (long) (n / (a + 1)) * (long) (m / (b + 1)));
		}

		for (int b = 0; b < 10000; b++) {
			int a = k - b;
			if (a < 0 || a >= n || b < 0 || b >= m) {
				continue;
			}
			ans = Math.max(ans, (long) (n / (a + 1)) * (long) (m / (b + 1)));
		}

		for (int b = m - 10000; b < m; b++) {
			long a = k - b;
			if (a < 0 || a >= n || b < 0 || b >= m) {
				continue;
			}
			ans = Math.max(ans, (long) (n / (a + 1)) * (long) (m / (b + 1)));
		}

		out.println(ans);
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
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