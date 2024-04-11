import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
		DSearchlights solver = new DSearchlights();
		solver.solve(1, in, out);
		out.close();
	}

	static class DSearchlights {
		static final long MASK = (1L << 25) - 1;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			int[] a = new int[n], b = new int[n], c = new int[m], d = new int[m];
			for (int i = 0; i < n; i++) {
				a[i] = sc.nextInt();
				b[i] = sc.nextInt();
			}
			for (int i = 0; i < m; i++) {
				c[i] = sc.nextInt();
				d[i] = sc.nextInt();
			}
			long[] all = new long[n * m];
			int idx = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					all[idx++] = encode(c[j] - a[i] + 1, d[j] - b[i] + 1);
				}
			}
			Arrays.sort(all);
			Utils.reverse(all);
			int ans = 100000000;
			int maxB = 0;
			for (int i = 0; i < all.length; i++) {
				long cur = all[i];
				int val = Math.max(0, getAs(cur)) + maxB;
				ans = Math.min(ans, val);
				maxB = Math.max(maxB, getBs(cur));
			}
			ans = Math.min(ans, maxB);
			out.println(ans);
		}

		static long encode(long as, int bs) {
			return (as << 25) | bs;
		}

		static int getAs(long code) {
			return (int) (code >> 25);
		}

		static int getBs(long code) {
			return (int) (code & MASK);
		}

	}

	static class Utils {
		public static void reverse(long[] array) {
			int from = 0, to = array.length - 1;
			while (from < to) {
				long tmp = array[from];
				array[from] = array[to];
				array[to] = tmp;
				from++;
				to--;
			}
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