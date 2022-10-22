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
		EMinimax solver = new EMinimax();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class EMinimax {
		static int MAX = 26;
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			EMinimax.sc = sc;
			EMinimax.out = out;
			char[] vals = sc.next().toCharArray();
			int[] count = new int[MAX];
			for (char val : vals) {
				count[val - 'a']++;
			}
			int n = vals.length;
			int firstOne = -1, first = -1, second = -1, third = -1;
			for (int i = 0; i < MAX; i++) {
				if (count[i] == 1 && firstOne == -1) firstOne = i;
				if (count[i] > 0) {
					if (first == -1) first = i;
					else if (second == -1) second = i;
					else if (third == -1) third = i;
				}
			}
			char[] ret = new char[n];
			int idx = 0;
			if (firstOne != -1) {
				ret[idx++] = c(firstOne);
				count[firstOne]--;
			} else {
				if (second != -1) {
					if (count[first] - 2 <= n - count[first]) {
						ret[0] = ret[1] = c(first);
						count[first] -= 2;
						idx = 2;
						int oIdx = first + 1;
						while (idx < n) {
							while (oIdx < MAX && count[oIdx] == 0) oIdx++;
							count[oIdx]--;
							ret[idx++] = c(oIdx);
							if (count[first] > 0) {
								ret[idx++] = c(first);
								count[first]--;
							}
						}
					} else if (third != -1) {
						ret[0] = c(first);
						ret[1] = c(second);
						idx = 2;
						for (int i = 0; i + 1 < count[first]; i++) {
							ret[idx++] = c(first);
						}
						ret[idx++] = c(third);
						count[first] = 0;
						count[second]--;
						count[third]--;
					} else {
						ret[idx++] = c(first);
						for (int i = 0; i < count[second]; i++) {
							ret[idx++] = c(second);
						}
						count[second] = 0;
						count[first]--;
					}
				}
			}
			for (int i = 0; i < MAX; i++) {
				while (count[i] > 0) {
					ret[idx++] = c(i);
					count[i]--;
				}
			}
			out.println(new String(ret));
		}

		static char c(int val) {
			return (char) (val + 'a');
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

	}
}