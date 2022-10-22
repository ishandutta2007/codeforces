import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.util.Set;
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
		DArrayDifferentiation solver = new DArrayDifferentiation();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class DArrayDifferentiation {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			DArrayDifferentiation.sc = sc;
			DArrayDifferentiation.out = out;
			int n = sc.nextInt();
			int[] vals = new int[n];
			for (int i = 0; i < n; i++) {
				vals[i] = Math.abs(sc.nextInt());
			}
			Set<Integer> got = new HashSet<>();
			boolean ok = false;
			for (int mask = 0; mask < 1 << n && !ok; mask++) {
				int sum = 0;
				for (int i = 0; i < n; i++) {
					if ((mask & 1 << i) != 0) sum += vals[i];
				}
				if (got.contains(sum)) {
					ok = true;
					break;
				}
				got.add(sum);
			}
			out.println(ok ? "YES" : "NO");
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