import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
		CPermutationOperations solver = new CPermutationOperations();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class CPermutationOperations {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			CPermutationOperations.sc = sc;
			CPermutationOperations.out = out;
			int n = sc.nextInt();
			int[] perm = sc.nextIntArray(n);
			List<CPermutationOperations.Need> all = new ArrayList<>();
			for (int i = 0; i + 1 < n; i++) {
				int dif = perm[i] - perm[i + 1];
				if (dif > 0) {
					all.add(new CPermutationOperations.Need(i + 2, dif));
				}
			}
			all.sort(Comparator.<CPermutationOperations.Need>comparingInt(p -> p.cant).reversed());
			int idx = 0;
			int[] pos = new int[n];
			for (int i = n - 1; i >= 0; i--) {
				if (idx < all.size()) {
					CPermutationOperations.Need me = all.get(idx);
					int val = Math.min(i + 1, me.cant);
					me.cant -= val;
					if (me.cant <= 0) idx++;
					pos[i] = me.pos;
				} else {
					pos[i] = 1;
				}
			}
			for (int i = 0; i < n; i++) {
				out.print(pos[i] + " ");
			}
			out.println();
		}

		static class Need {
			int pos;
			int cant;

			public Need(int pos, int cant) {
				this.pos = pos;
				this.cant = cant;
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
			return nextIntArray(n, false);
		}

		public int[] nextIntArray(int n, boolean subtractOne) {
			int add = subtractOne ? -1 : 0;
			int[] ret = new int[n];
			for (int i = 0; i < n; i++) {
				ret[i] = nextInt() + add;
			}
			return ret;
		}

	}
}