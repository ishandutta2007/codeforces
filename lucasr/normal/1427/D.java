import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
		DUnshufflingADeck solver = new DUnshufflingADeck();
		solver.solve(1, in, out);
		out.close();
	}

	static class DUnshufflingADeck {
		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			int n = sc.nextInt();
			int[] elems = sc.nextIntArray(n);
			List<int[]> ret = new ArrayList<>();
			int[] tmp;
			while ((tmp = process(elems)) != null) {
				ret.add(tmp);
				elems = transform(elems, tmp);
			}
			out.println(ret.size());
			for (int[] ints : ret) {
				out.print(ints.length + " ");
				for (int val : ints) {
					out.print(val + " ");
				}
				out.println();
			}
		}

		static int[] process(int[] elems) {
			int n = elems.length;
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++)
					if (elems[i] == elems[j] + 1) {
						for (int k = i; k < j; k++) {
							if (elems[k] + 1 != elems[k + 1]) {
								int[] ret = new int[4];
								int size = 0;
								if (i > 0) {
									ret[size++] = i;
								}
								ret[size++] = k - i + 1;
								ret[size++] = j - k;
								if (n > j + 1) {
									ret[size++] = n - j - 1;
								}
								return Arrays.copyOf(ret, size);
							}
						}

					}
			}
			return null;
		}

		static int[] transform(int[] elems, int[] parts) {
			int n = elems.length;
			int[] fArr = new int[parts.length];
			for (int i = 1; i < fArr.length; i++) {
				fArr[i] = fArr[i - 1] + parts[i - 1];
			}
			int[] ret = new int[n];
			int from = 0;
			for (int i = parts.length - 1; i >= 0; i--) {
				for (int j = 0; j < parts[i]; j++) {
					ret[from + j] = elems[fArr[i] + j];
				}
				from += parts[i];
			}
			return ret;
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