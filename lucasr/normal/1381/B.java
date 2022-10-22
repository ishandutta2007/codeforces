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
		BUnmerge solver = new BUnmerge();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class BUnmerge {
		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			int n = sc.nextInt();
			int[] p = sc.nextIntArray(2 * n);
			int[] got = new int[2 * n];
			int size = 0, first = 0, cur = 0;
			for (int i = 0; i < p.length; i++) {
				if (p[i] < first) {
					cur++;
				} else {
					if (cur > 0) {
						got[size++] = cur;
					}
					cur = 1;
					first = p[i];
				}
			}
			if (cur > 0) {
				got[size++] = cur;
			}

			boolean[] can = new boolean[2 * n + 1];
			can[0] = true;
			for (int i = 0; i < size; i++) {
				for (int j = 2 * n; j >= got[i]; j--) {
					if (can[j - got[i]]) can[j] = true;
				}
			}
			out.println(can[n] ? "YES" : "NO");
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