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
		BMorningJogging solver = new BMorningJogging();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class BMorningJogging {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			BMorningJogging.sc = sc;
			BMorningJogging.out = out;
			int n = sc.nextInt();
			int m = sc.nextInt();
			int[][] vals = new int[n][];
			for (int i = 0; i < n; i++) {
				vals[i] = sc.nextIntArray(m);
				Arrays.sort(vals[i]);
			}
			int[] from = new int[n], to = new int[n];
			int[][] ret = new int[n][m];
			Arrays.fill(to, m - 1);
			for (int i = 0; i < m; i++) {
				int bestJ = -1;
				for (int j = 0; j < n; j++) {
					if (bestJ == -1 || vals[j][from[j]] < vals[bestJ][from[bestJ]]) {
						bestJ = j;
					}
				}
				for (int j = 0; j < n; j++) {
					if (j == bestJ) {
						ret[j][i] = vals[j][from[j]];
						from[j]++;
					} else {
						ret[j][i] = vals[j][to[j]];
						to[j]--;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
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