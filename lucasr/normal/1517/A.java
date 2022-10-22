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
		ASumOf2050 solver = new ASumOf2050();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class ASumOf2050 {
		public static MyScanner sc;
		public static PrintWriter out;
		static long MOD = 2050;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			ASumOf2050.sc = sc;
			ASumOf2050.out = out;

			long n = sc.nextLong();
			if (n % MOD != 0) {
				out.println(-1);
				return;
			}
			n /= MOD;
			int ans = 0;
			for (int d : MathLib.getDigits(n)) {
				ans += d;
			}
			out.println(ans);
		}

	}

	static class MathLib {
		public static int digits(long val) {
			int ret = 0;
			while (val > 0) {
				ret++;
				val /= 10;
			}
			return Math.max(1, ret);
		}

		public static int[] getDigits(long val) {
			int[] ret = new int[digits(val)];
			int idx = 0;
			while (val > 0) {
				ret[idx++] = (int) (val % 10);
				val /= 10;
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

		public long nextLong() {
			return Long.parseLong(next());
		}

	}
}