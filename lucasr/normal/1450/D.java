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
		DRatingCompression solver = new DRatingCompression();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class DRatingCompression {
		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			int n = sc.nextInt();
			int[] vals = sc.nextIntArray(n);
			int[] count = new int[n + 1];
			boolean[] ret = new boolean[n];
			ret[0] = true;
			for (int i = 0; i < n; i++) {
				count[vals[i]]++;
				if (count[vals[i]] > 1) ret[0] = false;
			}
			int from = 0, to = n - 1;
			for (int i = n; i >= 2; i--) {
				int cur = n - i + 1;
				if (count[cur] > 0) {
					ret[i - 1] = true;
				}
				if (!ret[i - 1]) break;
				if (count[cur] > 1) break;
				if (vals[from] != cur && vals[to] != cur) break;
				if (vals[from] == cur) {
					from++;
				} else {
					to--;
				}
			}
			for (int i = 0; i < n; i++) {
				out.print(ret[i] ? '1' : '0');
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