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
		BAndItsNonZero solver = new BAndItsNonZero();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class BAndItsNonZero {
		static final int MAX = 18;
		static final int[][] ones = new int[1 << MAX][MAX];
		public static MyScanner sc;
		public static PrintWriter out;

		static {
			for (int i = 0; i < MAX; i++) {
				for (int mask = 0; mask < 1 << MAX; mask++) {
					ones[mask][i] = mask > 0 ? ones[mask - 1][i] : 0;
					if ((mask & (1 << i)) != 0) {
						ones[mask][i]++;
					}
				}
			}
		}

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			BAndItsNonZero.sc = sc;
			BAndItsNonZero.out = out;
			int l = sc.nextInt();
			int r = sc.nextInt();
			int tot = r - l + 1;
			int best = 0;
			for (int i = 0; i < MAX; i++) {
				best = Math.max(best, ones[r][i] - ones[l - 1][i]);
			}
			out.println(tot - best);
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