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
		ACharmedByTheGame solver = new ACharmedByTheGame();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class ACharmedByTheGame {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			ACharmedByTheGame.sc = sc;
			ACharmedByTheGame.out = out;
			int a = sc.nextInt();
			int b = sc.nextInt();
			int dif = Math.abs(a - b);
			int from = dif / 2;
			int min = Math.min(a, b);
			int ans = 1 + min;
			if (dif % 2 == 1) ans *= 2;
			out.println(ans);
			for (int i = 0; i <= min; i++) {
				out.print(from + 2 * i + " ");
				if (dif % 2 == 1) {
					out.print(from + 1 + 2 * i + " ");
				}
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