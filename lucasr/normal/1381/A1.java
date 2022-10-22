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
		A2PrefixFlipHardVersion solver = new A2PrefixFlipHardVersion();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class A2PrefixFlipHardVersion {
		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			int n = sc.nextInt();
			char[] a = sc.next().toCharArray();
			char[] b = sc.next().toCharArray();
			char[] copy = a.clone();

			int[] ret = new int[2 * n];
			int size = 0, from = 0, to = n - 1;
			boolean reversed = false;

			for (int i = n - 1; i >= 0; i--) {
				if (!reversed) {
					if (a[to] != b[i]) {
						if (a[from] == b[i]) {
							ret[size++] = 1;
							a[from] = other(a[from]);
						}
						ret[size++] = to - from + 1;
						reversed = true;
						from++;
					} else {
						to--;
					}
				} else {
					if (a[from] == b[i]) {
						if (a[to] != b[i]) {
							ret[size++] = 1;
							a[to] = other(a[to]);
						}
						ret[size++] = to - from + 1;
						reversed = false;
						to--;
					} else {
						from++;
					}
				}
			}

			out.print(size);
			for (int i = 0; i < size; i++) {
				out.print(" " + ret[i]);
			}
			out.println();

		}

		static char other(char c) {
			return c == '0' ? '1' : '0';
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