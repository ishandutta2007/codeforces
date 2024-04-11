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
		HZiguZagu solver = new HZiguZagu();
		solver.solve(1, in, out);
		out.close();
	}

	static class HZiguZagu {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			HZiguZagu.sc = sc;
			HZiguZagu.out = out;
			int n = sc.nextInt();
			int q = sc.nextInt();
			char[] vals = sc.next().toCharArray();
			int[][] acum = new int[2][n];
			for (int i = 0; i < 2; i++) {
				for (int j = 1; j < n; j++) {
					acum[i][j] = acum[i][j - 1];
					if (vals[j] == '0' + i && vals[j] == vals[j - 1]) {
						acum[i][j]++;
					}
				}
			}
			for (int i = 0; i < q; i++) {
				int l = sc.nextInt() - 1;
				int r = sc.nextInt() - 1;
				int zeroes = acum[0][r] - acum[0][l];
				int ones = acum[1][r] - acum[1][l];
				out.println(Math.max(zeroes, ones) + 1);
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