import java.io.*;
import java.util.*;

public class E {

	static final int P = 1_000_000_007;

	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	void fwht(int[] a) {
		for (int bit = 0; (1 << bit) < a.length; bit++) {
			for (int i = 0; i < a.length; i++) {
				int j = i ^ (1 << bit);
				if (i < j) {
					int v = a[i];
					int u = a[j];
					a[i] = v + u;
					if (a[i] >= P) {
						a[i] -= P;
					}

					a[j] = v - u;
					if (a[j] < 0) {
						a[j] += P;
					}
				}
			}
		}
	}

	static final int INV2 = (P + 1) / 2;

	void submit() {
		int n = nextInt();
		int[] a = new int[1 << n];
		int[] b = new int[1 << n];

		String s = nextToken();
		for (int i = 0; i < s.length(); i++) {
			(s.charAt(i) == '0' ? a : b)[i] = 1;
		}

		fwht(a);
		fwht(b);

		int[] c = new int[1 << n];
		for (int i = 0; i < 1 << n; i++) {
			c[i] = (int) ((long) a[i] * b[i] % P);
		}

		fwht(c);

		int inv2n = 1;
		for (int i = 0; i < n; i++) {
			inv2n = (int) ((long) inv2n * INV2 % P);
		}

		for (int i = 0; i < c.length; i++) {
			c[i] = (int) ((long) c[i] * inv2n % P);
		}

		int ret = 0;
		for (int i = 0; i < (1 << n); i++) {
			ret += (int) (((long) c[i] << Integer.bitCount(i)) % P);
			if (ret >= P) {
				ret -= P;
			}
		}
		
		ret = (int)(3L * ret % P);
		out.println(ret);
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	E() throws IOException {
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
		new E();
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