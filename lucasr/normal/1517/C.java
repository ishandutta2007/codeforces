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
		CFillomino2 solver = new CFillomino2();
		solver.solve(1, in, out);
		out.close();
	}

	static class CFillomino2 {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			CFillomino2.sc = sc;
			CFillomino2.out = out;
			int n = sc.nextInt();
			int[] vals = sc.nextIntArray(n);
			int[][] ret = new int[n][n];
			for (int add = 0; add < n; add++) {
				int idx = 0;
				for (int i = 0; i < n - add; i++) {
					while (vals[idx] < add + 1) idx++;
					ret[i + add][i] = vals[idx];
					idx++;
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j <= i; j++) {
					out.print(ret[i][j] + " ");
				}
				out.println();
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

		public int[] nextIntArray(int n) {
			int[] ret = new int[n];
			for (int i = 0; i < n; i++) {
				ret[i] = nextInt();
			}
			return ret;
		}

	}
}