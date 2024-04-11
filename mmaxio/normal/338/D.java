import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	static long boundedLCM(long[] a, long bound) {
		long ret = a[0];
		if (ret > bound) {
			return bound + 1;
		}
		for (int i = 1; i < a.length; i++) {
			long gcd = gcd(ret, a[i]);
			ret /= gcd;
			if (a[i] > bound / ret)
				return bound + 1;
			ret *= a[i];
		}

		return ret;
	}

	boolean solve() throws IOException {
		long n = nextLong();
		long m = nextLong();
		int k = nextInt();
		long[] a = new long[k];
		for (int i = 0; i < k; i++) {
			a[i] = nextLong();
		}

		long row = boundedLCM(a, n);
		if (row > n) {
			return false;
		}

		long[] rems = new long[k];
		for (int i = 0; i < k; i++) {
			rems[i] = (k - 1 - i) % a[i];
		}

		long[] ret = solveCRT(a, rems);
		
		if (ret == null) {
			return false;
		}
		
		long last = ret[1];
		while (last < k)
			last += row;
		
		if (last > m) {
			return false;
		}

		for (int i = 0; i < k; i++) {
			long val = last - k + i + 1;
			if (gcd(row, val) != a[i])
				return false;
		}
		return true;
	}

	static long[] solveCRT(long[] a, long[] rems) {
		long retMod = a[0];
		long retRem = rems[0];
		for (int i = 1; i < a.length; i++) {
			long newMod = a[i];
			long newRem = rems[i];
			long[] res = solveCRT(retMod, retRem, newMod, newRem);
			if (res == null) {
				return null;
			}
			retMod = res[0];
			retRem = res[1];
		}

		return new long[] { retMod, retRem };
	}

	static long[] extEuclid(long a, long b, long c) {
		// solve Ax + By = C
		if (b == 0) {
			// a = 1
			return new long[] { c, 0 };
		}
		long[] ret = extEuclid(b, a % b, c);
		return new long[] { ret[1], ret[0] - (a / b) * ret[1] };
	}

	static long[] solveCRT(long mod1, long rem1, long mod2, long rem2) {
		long a = mod1;
		long b = mod2;
		long c = rem2 - rem1;
		
		// System.err.println(a + " " + b + " " + c);

		long gcd = gcd(a, b);
		if (c % gcd != 0)
			return null;

		a /= gcd;
		b /= gcd;
		c /= gcd;

		long[] sol = extEuclid(a, b, c);
		// System.err.println(Arrays.toString(sol));
		sol[0] = fix(sol[0], b);
		return new long[] { a * mod2, rem1 + sol[0] * mod1};
	}
	
	static long fix(long x, long mod) {
		x %= mod;
		return x < 0 ? x + mod : x;
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		out.println(solve() ? "YES" : "NO");
		// System.err.println(Arrays.toString(solveCRT(4, 3, 6, 1)));
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