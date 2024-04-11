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
		ELostArray solver = new ELostArray();
		solver.solve(1, in, out);
		out.close();
	}

	static class ELostArray {
		public static MyScanner sc;
		public static PrintWriter out;
		int n;
		int k;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			ELostArray.sc = sc;
			ELostArray.out = out;
			n = sc.nextInt();
			k = sc.nextInt();
			if (n % 2 == 1 && k % 2 == 0) {
				answer(-1);
				return;
			}
			int need = (n + k - 1) / k;
			int extra = need * k - n;
			if (extra > 0) {
				need = Math.max(3, need);
				extra = need * k - n;
			}
			int extraPair = (need - 1) / 2 * 2;
			while (extra % 2 == 1 || extraPair * n < extra) {
				need++;
				extra += k;
				extraPair = (need - 1) / 2 * 2;
			}
			if (extra % 2 != 0) throw new RuntimeException();
			int[][] q = new int[need][k];
			int[] from = new int[need];

			int cur = 0;
			for (int i = 0; i < n; i++) {
				q[cur][from[cur]++] = i;
				cur = (cur + 1) % need;
				if (extra > 0) {
					int tot = Math.min(extraPair, extra / 2 * 2);
					for (int j = 0; j < tot; j++) {
						q[cur][from[cur]++] = i;
						cur = (cur + 1) % need;
						extra--;
					}

				}
			}
			if (extra > 0) {
				throw new RuntimeException();
			}
			int ans = 0;
			for (int i = 0; i < need; i++) {
				ans ^= query(q[i]);
			}
			answer(ans);

		}

		int query(int[] arr) {
			out.print("?");
			for (int i : arr) {
				out.print(" " + (i + 1));
			}
			out.println();
			out.flush();
			return sc.nextInt();
		}

		void answer(int xor) {
			out.println(xor == -1 ? xor : ("! " + xor));
			out.flush();
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