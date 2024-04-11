import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lucasr
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		MyScanner in = new MyScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		EPlacingJinas solver = new EPlacingJinas();
		solver.solve(1, in, out);
		out.close();
	}

	static class EPlacingJinas {
		static int[] di = {-1, 0};
		static int[] dj = {0, -1};
		static int MAX = 400005;
		public static MyScanner sc;
		public static PrintWriter out;
		long[] fact;
		long[] invFact;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			EPlacingJinas.sc = sc;
			EPlacingJinas.out = out;
			MathLib.MOD = 1000000007;
			int n = sc.nextInt();
			int[] a = new int[n + 2];
			for (int i = 0; i < n + 1; i++) {
				a[i] = sc.nextInt();
			}
			if (a[0] == 0) {
				out.println(0);
				return;
			}
			fact = MathLib.getFactorials(MAX);
			invFact = MathLib.getInverseFactorials(MAX);
			long ans = 0;
			for (int i = 0; i <= n + 1; i++) {
				int upTo = i > 0 ? a[i - 1] : a[i];
				for (int pos = a[i]; pos <= upTo; pos++) {
					for (int k = 0; k < 2; k++) {
						int ni = i + di[k];
						int nj = pos + dj[k];
						if (ni >= 0 && nj >= 0 && nj < a[ni]) {
							ans += comb(ni, nj);
						}
					}
				}
			}
			ans += MathLib.MOD - 1;
			ans %= MathLib.MOD;
			out.println(ans);
		}

		long comb(int i, int j) {
			return ((fact[i + j] * invFact[i]) % MathLib.MOD * invFact[j]) % MathLib.MOD;
		}

	}

	static class MyScanner {
		private BufferedReader br;
		private StringTokenizer tokenizer;

		public MyScanner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

	}

	static class MathLib {
		public static long MOD = 1000000007;

		public static long mult(long x, long y) {
			return (x * y) % MOD;
		}

		public static long pow(long base, long exp) {
			if (exp == 0) return 1;
			if ((exp & 1) == 1) return mult(base, pow(base, exp - 1));
			return pow(mult(base, base), exp / 2);
		}

		public static long inverse(long x) {
			return pow(x, MOD - 2);
		}

		public static long[] getFactorials(int max) {
			long[] ret = new long[max + 1];
			ret[0] = 1;
			for (int i = 1; i <= max; i++) {
				ret[i] = mult(ret[i - 1], i);
			}
			return ret;
		}

		public static long[] getInverseFactorials(int max) {
			long[] ret = new long[max + 1];
			ret[max] = 1;
			for (int i = 1; i <= max; i++) {
				ret[max] = mult(ret[max], i);
			}
			ret[max] = inverse(ret[max]);
			for (int i = max - 1; i >= 0; i--) {
				ret[i] = mult(ret[i + 1], i + 1);
			}
			return ret;
		}

	}
}