import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	// int n;
	//
	// boolean[] b;
	// boolean[] c;
	//
	// int go(int pos) {
	// if (pos == n)
	// return 1;
	// int ret = 0;
	// for (int bVal = 0; bVal < n; bVal++)
	// if (!b[bVal]) {
	// int cVal = pos + bVal;
	// if (cVal >= n)
	// cVal -= n;
	// if (!c[cVal]) {
	// b[bVal] = c[cVal] = true;
	// ret += go(pos + 1);
	// b[bVal] = c[cVal] = false;
	// }
	// }
	// return ret;
	// }

	static final int[] ANS = { 1, 3, 15, 133, 2025, 37851, 1030367, 36362925 };
	static final int MOD = 1_000_000_007;

	void solve() throws IOException {
		// this.n = n;
		// b = new boolean[n];
		// c = new boolean[n];
		//
		// int ans = go(0);
		// System.err.println(n + " -> " + ans);

		int n = nextInt();
		if (n % 2 == 0) {
			out.println(0);
		} else {
			int ans = ANS[n / 2];
			for (int i = 1; i <= n; i++)
				ans = (int)((long)ans * i % MOD);
			out.println(ans);
		}
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		// for (int n = 1; n <= 16; n++)
		// solve(n);
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