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
		DPhoenixAndSocks solver = new DPhoenixAndSocks();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class DPhoenixAndSocks {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			DPhoenixAndSocks.sc = sc;
			DPhoenixAndSocks.out = out;
			int n = sc.nextInt();
			int l = sc.nextInt();
			int r = sc.nextInt();
			boolean rightBig = r > l;
			int changeType = Math.abs(r - l) / 2;
			int[] type = new int[n];
			for (int i = 0; i < l; i++) {
				int cur = sc.nextInt() - 1;
				if (rightBig) type[cur]--;
				else type[cur]++;
			}
			for (int i = 0; i < r; i++) {
				int cur = sc.nextInt() - 1;
				if (rightBig) type[cur]++;
				else type[cur]--;
			}
			int ans = changeType, bag = 0;
			for (int i = 0; i < n; i++) {
				if (type[i] > 0) {
					bag += type[i] % 2;

					type[i] /= 2;
					int min = Math.min(type[i], changeType);
					changeType -= min;
					type[i] -= min;
					bag += type[i] * 2;
				} else {
					bag += Math.abs(type[i]);
				}
			}
			ans += bag / 2;
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

		public int nextInt() {
			return Integer.parseInt(next());
		}

	}
}