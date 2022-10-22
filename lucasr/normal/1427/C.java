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
		CTheHardWorkOfPaparazzi solver = new CTheHardWorkOfPaparazzi();
		solver.solve(1, in, out);
		out.close();
	}

	static class CTheHardWorkOfPaparazzi {
		static final int MAX = 1000;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			int r = sc.nextInt();
			int n = sc.nextInt();
			int[] x = new int[n + 1], y = new int[n + 1], t = new int[n + 1];
			for (int i = 1; i <= n; i++) {
				t[i] = sc.nextInt();
				x[i] = sc.nextInt() - 1;
				y[i] = sc.nextInt() - 1;
			}
			int[] max = new int[n + 1];
			int[] best = new int[n + 1];
			best[n] = max[n] = 1;
			for (int i = n - 1; i >= 0; i--) {
				int meX = x[i];
				int meY = y[i];
				int meT = t[i];
				best[i] = 1;
				for (int j = 1; j < MAX && i + j < n + 1; j++) {
					if (meT + Math.abs(meX - x[i + j]) + Math.abs(meY - y[i + j]) <= t[i + j]) {
						best[i] = Math.max(best[i], 1 + best[i + j]);
					}
				}
				if (i + MAX < n + 1) {
					best[i] = Math.max(best[i], 1 + max[i + MAX]);
				}
				max[i] = Math.max(best[i], max[i + 1]);
			}
			out.println(best[0] - 1);
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