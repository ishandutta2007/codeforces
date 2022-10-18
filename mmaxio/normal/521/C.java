import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final long P = 1_000_000_007;

	long[] fact, invFact;

	long comb(int n, int k) {
		if (n < 0 || k < 0 || k > n) {
			return 0;
		}
		return fact[n] * invFact[k] % P * invFact[n - k] % P;
	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		String s = new StringBuilder(nextToken()).reverse().toString();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = s.charAt(i) - '0';
		}

		long ret = 0;
		if (k == 0) {
			for (int i = n - 1; i >= 0; i--) {
				ret = (ret * 10 + a[i]) % P;
			}
			out.println(ret);
			return;
		}

		long[] inv = new long[n + 10];
		inv[0] = 0;
		inv[1] = 1;
		for (int x = 2; x < inv.length; x++)
			inv[x] = P - (P / x) * inv[(int) (P % x)] % P;

		fact = new long[n + 10];
		invFact = new long[fact.length];
		fact[0] = invFact[0] = 1;
		for (int i = 1; i < fact.length; i++) {
			fact[i] = fact[i - 1] * i % P;
			invFact[i] = invFact[i - 1] * inv[i] % P;
		}

		long[] p10 = new long[n + 10];
		p10[0] = 1;
		for (int i = 1; i < p10.length; i++) {
			p10[i] = p10[i - 1] * 10 % P;
		}

		ret = a[0] * comb(n - 1, k) % P;
		long pref = 0;
		for (int i = 1; i < n; i++) {
			pref += comb(n - i - 1, k - 1) * p10[i - 1] % P;
			if (pref >= P) {
				pref -= P;
			}
			long here = pref + comb(n - i - 1, k) * p10[i] % P;
			if (here >= P) {
				here -= P;
			}
			ret += here * a[i] % P;
			if (ret >= P) {
				ret -= P;
			}
		}
		out.println(ret);
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