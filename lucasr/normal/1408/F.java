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
		FTwoDifferent solver = new FTwoDifferent();
		solver.solve(1, in, out);
		out.close();
	}

	static class FTwoDifferent {
		int[] ret;
		int size;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			int n = sc.nextInt();
			ret = new int[1000000];
			size = 0;
			if (n >= 2) {
				int pot = 1;
				while (2 * pot <= n) {
					pot *= 2;
				}
				print(pot, 1);
				if (n > pot) {
					print(pot, n - pot + 1);
				}
			}
			out.println(size / 2);
			for (int i = 0; i < size; i += 2) {
				out.println(ret[i] + " " + ret[i + 1]);
			}
		}

		void print(int tot, int from) {
			if (tot == 2) {
				ret[size++] = from;
				ret[size++] = from + 1;
				return;
			}
			int half = tot / 2;
			print(half, from);
			print(half, from + half);
			for (int i = 0; i < half; i++) {
				ret[size++] = from + i;
				ret[size++] = from + half + i;
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