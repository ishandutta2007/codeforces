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
		FLEGOndaryGrandmaster solver = new FLEGOndaryGrandmaster();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class FLEGOndaryGrandmaster {
		public static MyScanner sc;
		public static PrintWriter out;
		int n;
		int[][] table;
		int[][] aRem;
		int[][] bRem;
		int[][] ways;
		char[] a;
		char[] b;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			FLEGOndaryGrandmaster.sc = sc;
			FLEGOndaryGrandmaster.out = out;

			n = sc.nextInt();
			a = sc.next().toCharArray();
			b = sc.next().toCharArray();
			for (int i = 0; i < n; i += 2) {
				if (a[i] != '?') {
					a[i] = a[i] == '0' ? '1' : '0';
				}
				if (b[i] != '?') {
					b[i] = b[i] == '0' ? '1' : '0';
				}
			}
			MathLib.MOD = 1000000007;
			aRem = new int[n + 1][2];
			bRem = new int[n + 1][2];
			for (int i = n - 1; i >= 0; i--) {
				for (int j = 0; j < 2; j++) {
					aRem[i][j] = aRem[i + 1][j];
					bRem[i][j] = bRem[i + 1][j];
				}
				if (a[i] == '?') {
					aRem[i][0]++;
				}
				if (a[i] == '1') {
					aRem[i][1]++;
				}
				if (b[i] == '?') {
					bRem[i][0]++;
				}
				if (b[i] == '1') {
					bRem[i][1]++;
				}
			}
			table = new int[n + 1][2 * n + 2];
			for (int i = 0; i < table.length; i++) {
				Arrays.fill(table[i], -1);
			}
			ways = new int[n + 1][2 * n + 2];
			for (int i = 0; i < ways.length; i++) {
				Arrays.fill(ways[i], -1);
			}
			out.println(calc(0, 0));
		}

		int calc(int pos, int acum) {
			if (pos == n) {
				if (acum != 0) throw new RuntimeException(acum + "");
				return 0;
			}
			long ans = table[pos][acum + n];
			if (ans != -1) return (int) ans;
			ans = 0;

			for (int i = 0; i < 2; i++)
				if (a[pos] == '?' || a[pos] - '0' == i) {
					for (int j = 0; j < 2; j++)
						if (b[pos] == '?' || b[pos] - '0' == j) {
							int nAcum = acum + i - j;
							int[] aa = aRem[pos + 1];
							int[] bb = bRem[pos + 1];
							if (aa[1] + nAcum <= bb[1] + bb[0] &&
									aa[1] + aa[0] + nAcum >= bb[1]) {
								long tmp = calcW(pos + 1, nAcum);
								tmp *= Math.abs(acum);
								ans += tmp + calc(pos + 1, nAcum);
								ans %= MathLib.MOD;
							}
						}
				}

			return table[pos][acum + n] = (int) ans;
		}

		int calcW(int pos, int acum) {
			if (pos == n) {
				return 1;
			}
			int ans = ways[pos][acum + n];
			if (ans != -1) return ans;
			ans = 0;

			for (int i = 0; i < 2; i++)
				if (a[pos] == '?' || a[pos] - '0' == i) {
					for (int j = 0; j < 2; j++)
						if (b[pos] == '?' || b[pos] - '0' == j) {
							int nAcum = acum + i - j;
							int[] aa = aRem[pos + 1];
							int[] bb = bRem[pos + 1];
							if (aa[1] + nAcum <= bb[1] + bb[0] &&
									aa[1] + aa[0] + nAcum >= bb[1]) {
								ans += calcW(pos + 1, nAcum);
								ans %= MathLib.MOD;
							}
						}
				}

			return ways[pos][acum + n] = ans;
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

	static class MathLib {
		public static long MOD = 1000000007;

	}
}