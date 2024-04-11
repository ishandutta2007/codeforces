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
		CPursuit solver = new CPursuit();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class CPursuit {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			CPursuit.sc = sc;
			CPursuit.out = out;
			int n = sc.nextInt();
			int[] me = sc.nextIntArray(n);
			int[] other = sc.nextIntArray(n);
			Arrays.sort(me);
			Arrays.sort(other);
			long meSum = 0, otherSum = 0;
			int remove = n / 4;
			for (int i = remove; i < n; i++) {
				meSum += me[i];
				otherSum += other[i];
			}
			int oIdx = remove - 1;
			while (meSum < otherSum) {
				n++;
				if (n / 4 > remove) {
					if (remove < me.length) {
						meSum += 100 - me[remove];
					}
					remove = n / 4;
				} else {
					meSum += 100;
					if (oIdx >= 0) {
						otherSum += other[oIdx];
						oIdx--;
					}
				}
			}
			out.println(n - me.length);
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