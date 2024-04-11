import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
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
		FMagnets solver = new FMagnets();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class FMagnets {
		static PrintWriter out;
		static MyScanner sc;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			FMagnets.out = out;
			FMagnets.sc = sc;
			int n = sc.nextInt();
			List<Integer> ans = new ArrayList<>();
			for (int i = 2; i <= n; i++) {
				int[] me = {i};
				if (check(range(1, i - 1), me)) {
					int left = 1, right = i - 1;
					while (left < right) {
						int med = (left + right) / 2;
						if (check(range(left, med), me)) {
							right = med;
						} else left = med + 1;
					}
					for (int j = 1; j < i; j++)
						if (j != left) {
							ans.add(j);
						}
					for (int j = i + 1; j <= n; j++) {
						if (!check(me, new int[]{j})) {
							ans.add(j);
						}
					}
					break;
				}
			}
			out.print("! " + ans.size());
			for (Integer an : ans) {
				out.print(" " + an);
			}
			out.println();
			out.flush();
		}

		static int[] range(int from, int to) {
			int[] ret = new int[to - from + 1];

			for (int i = 0; i < ret.length; i++) {
				ret[i] = i + from;
			}

			return ret;
		}

		static boolean check(int[] left, int[] right) {
			out.println("? " + left.length + " " + right.length);
			for (int i : left) {
				out.print(i + " ");
			}
			out.println();
			for (int i : right) {
				out.print(i + " ");
			}
			out.println();
			out.flush();
			return sc.nextInt() != 0;
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