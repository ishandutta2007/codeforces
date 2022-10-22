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
		APhoenixAndGold solver = new APhoenixAndGold();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class APhoenixAndGold {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			APhoenixAndGold.sc = sc;
			APhoenixAndGold.out = out;
			int n = sc.nextInt();
			int x = sc.nextInt();
			int[] w = sc.nextIntArray(n);
			Arrays.sort(w);
			boolean can = true;
			int acum = 0;
			for (int i = 0; i < n; i++) {
				if (acum + w[i] == x) {
					if (acum + w[n - 1] == x) can = false;
					else {
						int tmp = w[i];
						w[i] = w[n - 1];
						w[n - 1] = tmp;
					}
					break;
				}
				acum += w[i];
			}
			out.println(can ? "YES" : "NO");
			if (can) {
				for (int i = 0; i < n; i++) {
					out.print(w[i] + " ");
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