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
		ACircleColoring solver = new ACircleColoring();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class ACircleColoring {
		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			int n = sc.nextInt();
			int[] a = sc.nextIntArray(n);
			int[] b = sc.nextIntArray(n);
			int[] c = sc.nextIntArray(n);
			int[] ret = new int[n];
			ret[0] = a[0];
			for (int i = 1; i < n - 1; i++) {
				if (a[i] != ret[i - 1]) ret[i] = a[i];
				else ret[i] = b[i];
			}
			int last = n - 1;
			if (a[last] != ret[last - 1] && a[last] != ret[0]) {
				ret[last] = a[last];
			} else if (b[last] != ret[last - 1] && b[last] != ret[0]) {
				ret[last] = b[last];
			} else ret[last] = c[last];
			for (int i = 0; i < n; i++) {
				out.print(ret[i] + " ");
			}
			out.println();
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