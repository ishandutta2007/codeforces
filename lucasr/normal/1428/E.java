import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.InputStreamReader;
import java.util.TreeSet;
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
		ECarrotsForRabbits solver = new ECarrotsForRabbits();
		solver.solve(1, in, out);
		out.close();
	}

	static class ECarrotsForRabbits {
		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			int n = sc.nextInt();
			int k = sc.nextInt();
			long[] vals = sc.nextLongArray(n);
			long[] cur = new long[n];
			for (int i = 0; i < n; i++) {
				cur[i] = 1;
			}
			long cost = 0;
			for (int i = 0; i < n; i++) {
				cost += vals[i] * vals[i];
			}
			TreeSet<Integer> all = new TreeSet<>(Comparator.comparingLong((Integer i) -> increment(vals[i], cur[i])).thenComparingInt(i -> i));
			for (int i = 0; i < n; i++) {
				all.add(i);
			}
			for (int i = n; i < k; i++) {
				int idx = all.pollFirst();
				cost += increment(vals[idx], cur[idx]);
				cur[idx]++;
				all.add(idx);
			}
			out.println(cost);
		}

		static long increment(long tot, long parts) {
			return cost(tot, parts + 1) - cost(tot, parts);
		}

		static long cost(long tot, long parts) {
			if (parts >= tot) return tot;
			long min = tot / parts;
			long max = min + 1;
			long cantMax = tot % parts;
			long cantMin = parts - cantMax;
			return min * min * cantMin + max * max * cantMax;
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

		public long nextLong() {
			return Long.parseLong(next());
		}

		public long[] nextLongArray(int n) {
			long[] ret = new long[n];
			for (int i = 0; i < n; i++) {
				ret[i] = nextLong();
			}
			return ret;
		}

	}
}