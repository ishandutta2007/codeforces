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
		BPuttingPlates solver = new BPuttingPlates();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class BPuttingPlates {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			BPuttingPlates.sc = sc;
			BPuttingPlates.out = out;
			int f = sc.nextInt();
			int s = sc.nextInt();
			char[][] ret = new char[f][s];
			for (int i = 0; i < ret.length; i++) {
				Arrays.fill(ret[i], '0');
			}
			for (int i = 0; i < s; i += 2) {
				ret[0][i] = '1';
				ret[f - 1][i] = '1';
			}
			for (int i = 2; i + 2 < f; i += 2) {
				ret[i][0] = '1';
				ret[i][s - 1] = '1';
			}
			for (int i = 0; i < f; i++) {
				out.println(new String(ret[i]));
			}
			out.println();
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