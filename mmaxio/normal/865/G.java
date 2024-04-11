import java.io.*;
import java.util.*;

public class G {

	static final int P = 1_000_000_007;

	void submit() {
		int n = nextInt();
		int m = nextInt();
		long exp = nextLong();
		int[] a = new int[n];
		int[] b = new int[m];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		int maxCoef = 0;
		for (int i = 0; i < m; i++) {
			b[i] = nextInt();
			maxCoef = Math.max(maxCoef, b[i]);
		}

		int[] bPoly = new int[maxCoef + 1];
		bPoly[maxCoef] = 1;
		for (int pow : b) {
			bPoly[maxCoef - pow]--;
			if (bPoly[maxCoef - pow] < 0) {
				bPoly[maxCoef - pow] += P;
			}
		}
		
		int[] aPoly = {};
		for (int pow : a) {
			aPoly = sum(aPoly, quotPow(new int[] { 0, 1 }, bPoly, pow));
		}
		int[] ans = quotPow(aPoly, bPoly, exp);

		ans = prod(ans, quotPow(new int[] { 0, 1 }, bPoly, maxCoef));
		ans = quot(ans, bPoly);

		out.println((long)ans[0] * inv(P - bPoly[0]) % P);
	}
	
	int inv(int x) {
		return x == 1 ? 1 : P - (int)((long)(P / x) * inv(P % x) % P);
	}

	int[] quotPow(int[] a, int[] b, long n) {
		a = quot(a, b);
		int[] ret = { 1 };
		for (; n > 0; n >>= 1) {
			if ((n & 1) == 1) {
				ret = quot(prod(ret, a), b);
			}
			a = quot(prod(a, a), b);
		}
		return ret;
	}

	int[] sum(int[] a, int[] b) {
		int[] c = Arrays.copyOf(a, Math.max(a.length, b.length));
		for (int i = 0; i < b.length; i++) {
			c[i] += b[i];
			if (c[i] >= P) {
				c[i] -= P;
			}
		}
		return c;
	}

	int[] prod(int[] a, int[] b) {
		int[] c = new int[a.length + b.length - 1];
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < b.length; j++) {
				c[i + j] += (int) ((long) a[i] * b[j] % P);
				if (c[i + j] >= P) {
					c[i + j] -= P;
				}
			}
		}
		return c;
	}

	int[] quot(int[] a, int[] b) {
		a = a.clone();
		// leading coef of b is 1
		if (a.length < b.length) {
			return a;
		}
		int degB = b.length - 1;
		for (int ptr = a.length - 1; ptr >= degB; ptr--) {
			long coef = a[ptr];
			for (int i = 0, j = ptr - degB; i < degB; i++, j++) {
				a[j] -= (int) (coef * b[i] % P);
				if (a[j] < 0) {
					a[j] += P;
				}
			}
		}
		return Arrays.copyOf(a, degB);
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	G() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new G();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}