import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.stream.LongStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.OptionalLong;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
		ABinaryDecimal solver = new ABinaryDecimal();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class ABinaryDecimal {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			ABinaryDecimal.sc = sc;
			ABinaryDecimal.out = out;
			int n = sc.nextInt();
			out.println(Arrays.stream(MathLib.getDigits(n)).asLongStream().max().getAsLong());
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

		public int nextInt() {
			return Integer.parseInt(next());
		}

	}
}