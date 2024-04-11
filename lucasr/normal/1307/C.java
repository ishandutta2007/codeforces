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
		CCowAndMessage solver = new CCowAndMessage();
		solver.solve(1, in, out);
		out.close();
	}

	static class CCowAndMessage {
		static int MAX = 26;
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			CCowAndMessage.sc = sc;
			CCowAndMessage.out = out;

			char[] s = sc.next().toCharArray();
			long[][] count = new long[MAX][MAX];
			long[] acum = new long[MAX];
			for (int i = 0; i < s.length; i++) {
				int c = s[i] - 'a';
				for (int j = 0; j < MAX; j++) {
					count[j][c] += acum[j];
				}
				acum[c]++;
			}
			long ans = 0;
			for (int i = 0; i < MAX; i++) {
				ans = Math.max(ans, acum[i]);
				for (int j = 0; j < MAX; j++) {
					ans = Math.max(ans, count[i][j]);
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

	}
}