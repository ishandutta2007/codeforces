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
		EGroupPhoto solver = new EGroupPhoto();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class EGroupPhoto {
		public static MyScanner sc;
		public static PrintWriter out;
		static long MOD = 998244353;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			EGroupPhoto.sc = sc;
			EGroupPhoto.out = out;
			int n = sc.nextInt();
			long[] a = sc.nextLongArray(n);
			long ans = 1, sum = 0;
			for (long l : a) {
				sum += l;
			}
			long min = sum / 2 + 1;
			long acum = 0;
			for (int i = 0; i < n; i++) {
				if (i >= 1 && acum >= min) ans++;
				acum += a[i];
			}
			long[] evenAcum = new long[n];
			for (int i = 0; i < n; i++) {
				evenAcum[i] = a[i];
				if (i >= 2) evenAcum[i] += evenAcum[i - 2];
			}
			for (boolean pBeg : new boolean[]{true, false}) {
				for (boolean cEnd : new boolean[]{true, false}) {
					int from = pBeg ? 1 : 0;
					int to = cEnd ? n - 2 : n - 1;
					long pSum = pBeg ? a[0] : 0;
					for (int fromP = to; fromP > from; fromP--) {
						int lastP = fromP - 2;
						pSum += a[fromP];
						int mx = 0;
						if (lastP > from) {
							mx = lastP / 2 + 1 - (from % 2 == lastP % 2 || from == 1 ? 1 : 0);
						}
						if (cant(evenAcum, lastP, mx) + pSum >= min) {
							int left = -1, right = mx;
							while (left + 1 < right) {
								int med = (left + right) / 2;
								if (cant(evenAcum, lastP, med) + pSum >= min) {
									right = med;
								} else {
									left = med;
								}
							}
							ans += mx - left;
							ans %= MOD;
						}
					}
				}
			}

			out.println(ans);
		}

		static long cant(long[] evenAcum, int lastP, int size) {
			if (lastP < 0) {
				if (size > 0) throw new RuntimeException(size + "");
				return 0;
			}
			long ret = evenAcum[lastP];
			if (lastP - 2 * size >= 0) ret -= evenAcum[lastP - 2 * size];
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

		public long nextLong() {
			return Long.parseLong(next());
		}

		public long[] nextLongArray(int n) {
			long[] ret = new long[n];
			for (int i = 0; i < n; i++) {
				ret[i] = nextLong();
			}
			return ret;
		}

	}
}