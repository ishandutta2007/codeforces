import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.ArrayDeque;
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
		DBouncingBoomerangs solver = new DBouncingBoomerangs();
		solver.solve(1, in, out);
		out.close();
	}

	static class DBouncingBoomerangs {
		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			int n = sc.nextInt();
			int[] vals = sc.nextIntArray(n);
			List<int[]> ret = new ArrayList<>();
			ArrayDeque<Integer> ones = new ArrayDeque<>();
			int last3 = -1, last2 = -1;
			boolean can = true;
			int first = n;
			for (int me = n; me >= 1; me--) {
				int curCant = vals[me - 1];
				if (curCant == 1) {
					ones.addLast(me);
				} else if (curCant > 0) {
					if (curCant == 2) {
						if (ones.isEmpty()) {
							can = false;
							break;
						}
						int one = ones.removeLast();
						ret.add(new int[]{first, one});
						ret.add(new int[]{first, me});
						last2 = me;
						first--;
					} else {
						int other = -1;
						if (last3 != -1) {
							other = last3;
						} else if (last2 != -1) {
							other = last2;
						}
						if (other == -1 && ones.isEmpty()) {
							can = false;
							break;
						}
						if (other != -1) {
							ret.add(new int[]{first, me});
							ret.add(new int[]{first, other});
						} else {
							int one = ones.removeLast();
							ret.add(new int[]{first, one});
							first--;
							ret.add(new int[]{first, me});
							ret.add(new int[]{first, one});
						}
						last3 = me;
						first--;
					}
				}
			}
			if (!can) {
				out.println(-1);
				return;
			}
			while (!ones.isEmpty()) {
				int one = ones.removeLast();
				ret.add(new int[]{first, one});
				first--;
			}
			out.println(ret.size());
			for (int[] pair : ret) {
				out.println(pair[0] + " " + pair[1]);
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