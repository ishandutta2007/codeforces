import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int MOD = 1000000007;

	void solve() throws IOException {
		char[] s = nextToken().toCharArray();
		int n = s.length;

		int ans = 0;

		for (int pref = 0; pref < n; pref++) {
			if (s[pref] == '1') {
				int suff = n - pref - 1;
				ans += pow(2, pref + 2 * suff);
				if (ans >= MOD)
					ans -= MOD;
			}
		}

		out.println(ans);
	}

	static final int pow(int a, int b) {
		int ret = 1;
		while (b != 0) {
			if ((b & 1) == 1)
				ret = (int) ((long) ret * a % MOD);
			a = (int) ((long) a * a % MOD);
			b >>= 1;
		}
		return ret;
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