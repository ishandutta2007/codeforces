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
		CLittleAlawnsPuzzle solver = new CLittleAlawnsPuzzle();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class CLittleAlawnsPuzzle {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			CLittleAlawnsPuzzle.sc = sc;
			CLittleAlawnsPuzzle.out = out;
			int n = sc.nextInt();
			int[] a = sc.nextIntArray(n);
			int[] b = sc.nextIntArray(n);
			for (int i = 0; i < n; i++) {
				a[i]--;
				b[i]--;
			}
			int[] invb = new int[n];
			for (int i = 0; i < n; i++) {
				invb[b[i]] = i;
			}
			long ans = 1;
			long MOD = 1000000007;
			boolean[] vis = new boolean[n];
			for (int i = 0; i < n; i++) {
				if (!vis[i]) {
					ans *= 2;
					ans %= MOD;
					int cur = i;
					while (!vis[cur]) {
						vis[cur] = true;
						cur = invb[a[cur]];
					}
				}
			}
			out.println(ans);
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