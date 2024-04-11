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
		EPhoenixAndComputers solver = new EPhoenixAndComputers();
		solver.solve(1, in, out);
		out.close();
	}

	static class EPhoenixAndComputers {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			EPhoenixAndComputers.sc = sc;
			EPhoenixAndComputers.out = out;
			int n = sc.nextInt();
			long M = sc.nextLong();
			MathLib.MOD = M;
			long[][] comb = MathLib.getComb(n + 5);
			long[] pots2 = MathLib.getPots(2, n + 2);
			long[] inv = new long[n + 5];
			for (int i = 1; i < inv.length; i++) {
				inv[i] = MathLib.inverse(i);
			}
			long[][] ret = new long[n + 1][n + 1]; // size, cant
			for (int size = 0; size <= n; size++) {
				if (size <= 1) {
					ret[size][size] = 1;
				} else if (size == 2) {
					ret[size][2] = 2;
				} else {
					long[] me = ret[size];
					me[size] = pots2[size - 1];
					for (int i = 1; i + 1 < size; i++) {
						int prev = i, next = size - i - 1;
						long tmp = pots2[i - 1];
						for (int c = 0; c <= next; c++) {
							long tot = (ret[next][c] * comb[c][c + prev]) % MathLib.MOD;
							tot = (tot * tmp) % MathLib.MOD;
							me[prev + c] += tot;
							me[prev + c] %= MathLib.MOD;
						}
					}
				}
			}
			long ans = 0;
			for (int i = 0; i <= n; i++) {
				ans += ret[n][i];
			}
			ans %= MathLib.MOD;
			out.println(ans);
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

		public static long[] getPots(long base, int max) {
			long[] ret = new long[max + 1];
			ret[0] = 1;
			for (int i = 1; i <= max; i++) {
				ret[i] = mult(ret[i - 1], base);
			}
			return ret;
		}

		public static long[][] getComb(int max) {
			long[][] ret = new long[max + 1][max + 1];
			for (int n = 0; n <= max; n++) {
				ret[0][n] = ret[n][n] = 1;
				for (int k = 1; k < n; k++) {
					ret[k][n] = (ret[k - 1][n - 1] + ret[k][n - 1]) % MOD;
				}
			}

			return ret;
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

		public long nextLong() {
			return Long.parseLong(next());
		}

	}
}