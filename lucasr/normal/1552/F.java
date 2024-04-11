import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.AbstractCollection;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
		FTelepanting solver = new FTelepanting();
		solver.solve(1, in, out);
		out.close();
	}

	static class FTelepanting {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			FTelepanting.sc = sc;
			FTelepanting.out = out;
			int n = sc.nextInt();
			long[] x = new long[n], y = new long[n], s = new long[n];
			for (int i = 0; i < n; i++) {
				x[i] = sc.nextInt();
				y[i] = sc.nextInt();
				s[i] = sc.nextInt();
			}
			MathLib.MOD = 998244353;
//		long[] times = new long[n];
			long constant = 0;
			long ans = x[n - 1] + 1;
			PriorityQueue<FTelepanting.Event> pq = new PriorityQueue<>();
			for (int i = n - 1; i >= 0; i--) {
				while (!pq.isEmpty() && pq.peek().when > x[i]) {
					FTelepanting.Event e = pq.poll();
					constant += MathLib.MOD - e.amount;
				}
				constant %= MathLib.MOD;
//			times[i] = (2 * constant + 1 + s[i]) % MOD;
				long add = (constant + s[i]) % MathLib.MOD;
				constant += add;
				constant %= MathLib.MOD;
				pq.add(new FTelepanting.Event(y[i], add));
				long dif = x[i] - y[i];
				ans += dif * add;
				ans %= MathLib.MOD;
			}
			out.println(ans);
		}

		static class Event implements Comparable<FTelepanting.Event> {
			long when;
			long amount;

			public Event(long when, long amount) {
				this.when = when;
				this.amount = amount;
			}

			public int compareTo(FTelepanting.Event o) {
				return Long.compare(o.when, when);
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

	static class MathLib {
		public static long MOD = 1000000007;

	}
}