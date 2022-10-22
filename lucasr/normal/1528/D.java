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
		DItsABirdNoItsAPlaneNoItsAaParsa solver = new DItsABirdNoItsAPlaneNoItsAaParsa();
		solver.solve(1, in, out);
		out.close();
	}

	static class DItsABirdNoItsAPlaneNoItsAaParsa {
		public static MyScanner sc;
		public static PrintWriter out;
		static final int INF = Integer.MAX_VALUE / 2;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			DItsABirdNoItsAPlaneNoItsAaParsa.sc = sc;
			DItsABirdNoItsAPlaneNoItsAaParsa.out = out;
			int n = sc.nextInt();
			int m = sc.nextInt();
			int[][] minEdge = new int[n][n];
			for (int i = 0; i < n; i++) {
				Arrays.fill(minEdge[i], INF);
			}
			for (int i = 0; i < m; i++) {
				int a = sc.nextInt();
				int b = sc.nextInt();
				int c = sc.nextInt();
				for (int j = 0; j < n; j++) {
					int to = (b + j) % n;
					minEdge[a][to] = Math.min(minEdge[a][to], c + j);
				}
			}
			int[][] ans = new int[n][n];

			for (int i = 0; i < n; i++) {
				int[] dist = ans[i];
				boolean[] vis = new boolean[n];
				Arrays.fill(dist, INF);
				dist[i] = 0;
				for (int j = 0; j < n - 1; j++) {
					int minI = -1;
					for (int k = 0; k < n; k++)
						if (!vis[k]) {
							if (minI == -1 || dist[k] < dist[minI]) {
								minI = k;
							}
						}
					vis[minI] = true;
					int where = dist[minI] % n;
					for (int k = 0; k < n; k++)
						if (!vis[k]) {
							dist[k] = Math.min(dist[k], dist[minI] + minEdge[minI][(k + n - where) % n]);
						}
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					out.print(ans[i][j] + " ");
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