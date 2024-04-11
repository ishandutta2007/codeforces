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
		DExplorerSpace solver = new DExplorerSpace();
		solver.solve(1, in, out);
		out.close();
	}

	static class DExplorerSpace {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			DExplorerSpace.sc = sc;
			DExplorerSpace.out = out;

			int n = sc.nextInt();
			int m = sc.nextInt();
			int k = sc.nextInt();
			int[][] distJ = new int[n][m - 1];
			int[][] distI = new int[n - 1][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m - 1; j++) {
					distJ[i][j] = sc.nextInt();
				}
			}
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < m; j++) {
					distI[i][j] = sc.nextInt();
				}
			}
			if (k % 2 == 1) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						out.print("-1 ");
					}
					out.println();
				}
				return;
			}
			k /= 2;
			int[][][] table = new int[k + 1][n][m];
			for (int kk = 1; kk <= k; kk++) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						table[kk][i][j] = Integer.MAX_VALUE;
						if (i + 1 < n) {
							table[kk][i][j] = Math.min(table[kk][i][j], table[kk - 1][i + 1][j] + distI[i][j]);
						}
						if (i - 1 >= 0) {
							table[kk][i][j] = Math.min(table[kk][i][j], table[kk - 1][i - 1][j] + distI[i - 1][j]);
						}
						if (j + 1 < m) {
							table[kk][i][j] = Math.min(table[kk][i][j], table[kk - 1][i][j + 1] + distJ[i][j]);
						}
						if (j - 1 >= 0) {
							table[kk][i][j] = Math.min(table[kk][i][j], table[kk - 1][i][j - 1] + distJ[i][j - 1]);
						}
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					out.print(2 * table[k][i][j] + " ");
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

	}
}