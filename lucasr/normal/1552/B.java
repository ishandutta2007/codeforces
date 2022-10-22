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
		BRunningForGold solver = new BRunningForGold();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class BRunningForGold {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			BRunningForGold.sc = sc;
			BRunningForGold.out = out;
			int n = sc.nextInt();
			int[][] vals = new int[n][5];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < 5; j++) {
					vals[i][j] = sc.nextInt();
				}
			}
			int best = 0;
			for (int i = 1; i < n; i++) {
				int count = 0;
				for (int j = 0; j < 5; j++) {
					if (vals[best][j] < vals[i][j]) count++;
				}
				if (count <= 2) {
					best = i;
				}
			}
			boolean can = true;
			for (int i = 0; i < n; i++)
				if (i != best) {
					int count = 0;
					for (int j = 0; j < 5; j++) {
						if (vals[best][j] < vals[i][j]) count++;
					}
					if (count <= 2) {
						can = false;
						break;
					}
				}
			out.println(can ? (best + 1) : -1);
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