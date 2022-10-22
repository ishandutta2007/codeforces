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
		ENotepadexe solver = new ENotepadexe();
		solver.solve(1, in, out);
		out.close();
	}

	static class ENotepadexe {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			ENotepadexe.sc = sc;
			ENotepadexe.out = out;
			int n = sc.nextInt();
			int left = 2 * n - 2, right = 2001 * n - 1;
			while (left + 1 < right) {
				int med = (left + right) / 2;
				if (query(med) == 1) {
					right = med;
				} else {
					left = med;
				}
			}
			int bestArea = right;
			for (int i = 2; i <= n; i++) {
				if (query(bestArea / i) == i) {
					bestArea = (bestArea / i) * i;
				}
			}
			guess(bestArea);
		}

		int query(int w) {
			out.println("? " + w);
			out.flush();
			return sc.nextInt();
		}

		void guess(int area) {
			out.println("! " + area);
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