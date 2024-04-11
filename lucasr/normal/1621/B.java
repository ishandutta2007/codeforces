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
		BIntegersShop solver = new BIntegersShop();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class BIntegersShop {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			BIntegersShop.sc = sc;
			BIntegersShop.out = out;
			int n = sc.nextInt();
			int[] l = new int[n], r = new int[n], c = new int[n];
			for (int i = 0; i < n; i++) {
				l[i] = sc.nextInt();
				r[i] = sc.nextInt();
				c[i] = sc.nextInt();
			}
			int[] min = new int[n], max = new int[n], minC = new int[n], maxC = new int[n], minMaxC = new int[n];
			min[0] = l[0];
			max[0] = r[0];
			minC[0] = maxC[0] = minMaxC[0] = c[0];
			for (int i = 1; i < n; i++) {
				min[i] = Math.min(min[i - 1], l[i]);
				max[i] = Math.max(max[i - 1], r[i]);
				boolean changed = false;
				if (l[i] == min[i - 1]) {
					minC[i] = Math.min(minC[i - 1], c[i]);
				} else if (l[i] < min[i - 1]) {
					changed = true;
					minC[i] = c[i];
				} else {
					minC[i] = minC[i - 1];
				}
				if (r[i] == max[i - 1]) {
					maxC[i] = Math.min(maxC[i - 1], c[i]);
				} else if (r[i] > max[i - 1]) {
					changed = true;
					maxC[i] = c[i];
				} else {
					maxC[i] = maxC[i - 1];
				}
				minMaxC[i] = changed ? Integer.MAX_VALUE : minMaxC[i - 1];
				if (l[i] == min[i] && r[i] == max[i]) {
					minMaxC[i] = Math.min(minMaxC[i], c[i]);
				}
			}
			for (int i = 0; i < n; i++) {
				out.println(Math.min(minC[i] + maxC[i], minMaxC[i]));
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

	}
}