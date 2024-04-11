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
		CMAXMEXCut solver = new CMAXMEXCut();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class CMAXMEXCut {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			CMAXMEXCut.sc = sc;
			CMAXMEXCut.out = out;
			int n = sc.nextInt();
			char[] a = sc.next().toCharArray();
			char[] b = sc.next().toCharArray();
			int[][] next = new int[2][n + 1];
			next[0][n] = next[1][n] = n;
			for (int i = n - 1; i >= 0; i--) {
				next[0][i] = next[0][i + 1];
				next[1][i] = next[1][i + 1];
				if (a[i] == '0' || b[i] == '0') next[0][i] = i;
				if (a[i] == '1' || b[i] == '1') next[1][i] = i;
			}
			int[] ans = new int[n + 1];
			for (int i = n - 1; i >= 0; i--) {
				int vec = next[0][i];
				if (vec < n) {
					ans[i] = Math.max(ans[i], 1 + ans[vec + 1]);
					if (next[1][i] < n) {
						vec = Math.max(vec, next[1][i]);
						ans[i] = Math.max(ans[i], 2 + ans[vec + 1]);
					}
				}
			}
			out.println(ans[0]);
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