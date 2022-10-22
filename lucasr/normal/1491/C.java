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
		CPekoraAndTrampoline solver = new CPekoraAndTrampoline();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class CPekoraAndTrampoline {
		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			int n = sc.nextInt();
			int[] vals = sc.nextIntArray(n);
			int[] next = new int[n + 1];
			next[n] = n;
			for (int i = n - 1; i >= 0; i--) {
				if (vals[i] > 1) {
					next[i] = i;
				} else {
					next[i] = next[i + 1];
				}
			}
			long ans = 0;
			for (int i = 0; i < n; i++) {
				if (vals[i] > 1) {
					int max = Math.max(n - i - 1, 1);
					if (vals[i] > max) {
						ans += vals[i] - max;
						vals[i] = max;
					}
					int tot = vals[i] - 1;
					for (int j = 0; j < tot; j++) {
						ans++;
						int cur = i;
						while (cur < n) {
							if (vals[cur] > 1) {
								vals[cur]--;
								if (vals[cur] == 1) update(vals, next, cur);
								cur += vals[cur] + 1;
							} else {
								if (vals[cur] > 1) throw new RuntimeException();
								if (next[cur] == cur) throw new RuntimeException(cur + "");
								cur = next[cur];
							}
						}
					}
				}
			}

			out.println(ans);
		}

		private void update(int[] vals, int[] next, int cur) {
			next[cur] = next[cur + 1];
			for (int i = cur - 1; i >= 0; i--) {
				if (vals[i] > 1) {
					return;
				} else {
					next[i] = next[i + 1];
				}

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