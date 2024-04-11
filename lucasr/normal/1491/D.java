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
		DZookeeperAndTheInfiniteZoo solver = new DZookeeperAndTheInfiniteZoo();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class DZookeeperAndTheInfiniteZoo {
		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			int from = sc.nextInt();
			int to = sc.nextInt();

			boolean can = from <= to;
			int rem = 0;
			for (int i = 29; i >= 0; i--) {
				if (bit(from, i)) rem--;
				if (bit(to, i)) rem++;
				rem = Math.max(rem, 0);
			}
			if (rem > 0) can = false;
			out.println(can ? "YES" : "NO");
		}

		static boolean bit(int n, int pos) {
			return (n & (1 << pos)) != 0;
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