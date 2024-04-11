import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int MOD = 1_000_000_007;

	int[] fact, invFact;

	static final int pow(int a, int b) {
		int ret = 1;
		while (b > 0) {
			if ((b & 1) == 1) {
				ret = (int) ((long) ret * a % MOD);
			}
			a = (int) ((long) a * a % MOD);
			b >>= 1;
		}
		return ret;
	}

	int C(int n, int k) {
		return (int) ((long) fact[n] * invFact[k] % MOD * invFact[n - k] % MOD);
	}

	void solve() throws IOException {
		int n = nextInt();

		fact = new int[n + 1];
		invFact = new int[n + 1];
		fact[0] = invFact[0] = 1;
		for (int i = 1; i <= n; i++) {
			fact[i] = (int) ((long) fact[i - 1] * i % MOD);
			invFact[i] = pow(fact[i], MOD - 2);
		}

		int[] a = new int[n];
		boolean[] used = new boolean[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt() - 1;
			if (a[i] >= 0)
				used[a[i]] = true;
		}

		int m = 0; // totally free
		int k = 0;

		for (int i = 0; i < n; i++) {
			if (a[i] < 0 && !used[i]) {
				m++;
			} else if (a[i] >= 0 && !used[i]) {
				k++;
			}
		}

		int ans = 0;
		for (int bad = 0; bad <= m; bad++) {
			int cnt = (int) ((long) C(m, bad) * fact[k + m - bad] % MOD);
			if ((bad % 2) == 0) {
				ans += cnt;
				if (ans >= MOD)
					ans -= MOD;
			} else {
				ans -= cnt;
				if (ans < 0)
					ans += MOD;
			}
		}
		
		out.println(ans);

	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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