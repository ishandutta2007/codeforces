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
		BKaviOnPairingDuty solver = new BKaviOnPairingDuty();
		solver.solve(1, in, out);
		out.close();
	}

	static class BKaviOnPairingDuty {
		public static MyScanner sc;
		public static PrintWriter out;
		static int MOD = 998244353;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			BKaviOnPairingDuty.sc = sc;
			BKaviOnPairingDuty.out = out;
			int n = sc.nextInt();
			int[] divs = new int[n + 2];
			divs[2] = 1;
			for (int i = 2; i <= n; i++) {
				divs[i] = 1;
				for (int d = 2; d * d <= i; d++)
					if (divs[d] == 1 && i % d == 0) {
						int tmp = i;
						while (tmp % d == 0) {
							tmp /= d;
							divs[i]++;
						}
						divs[i] *= divs[tmp] + 1;
						divs[i]--;
						break;
					}
			}
			int acum = 2;
			int res = 1;
			for (int i = 2; i <= n; i++) {
				res = (acum + divs[i]) % MOD;
				acum += res;
				acum %= MOD;
			}
			out.println(res);
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