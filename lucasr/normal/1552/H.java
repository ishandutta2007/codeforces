import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Map;
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
		HGuessThePerimeter solver = new HGuessThePerimeter();
		solver.solve(1, in, out);
		out.close();
	}

	static class HGuessThePerimeter {
		static final int MAX = 200;
		public static MyScanner sc;
		public static PrintWriter out;
		static int tot;
		static int[] a;
		static int[] b;
		static Map<Long, Integer> best;
		static Map<Long, Integer> choose;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			HGuessThePerimeter.sc = sc;
			HGuessThePerimeter.out = out;
			int VALUE = query(1);
			a = new int[63];
			b = new int[63];
			int idx = 0;
			for (int aa = 2; aa <= MAX; aa++) {
				for (int bb = 2; bb <= MAX; bb++) {
					int val = aa * bb;
					if (val == VALUE) {
						a[idx] = aa;
						b[idx] = bb;
						idx++;
					}
				}
			}
			tot = idx;
			best = new HashMap<>();
			choose = new HashMap<>();
			long curMask = (1L << tot) - 1;
			int steps = steps(curMask);
			while (steps >= 1) {
				int me = choose.get(curMask);
				int ans = query(me);
				for (int j = 0; j < tot; j++)
					if ((curMask & (1L << j)) != 0) {
						if (ans != (a[j] / me) * b[j] && ans != ((a[j] + me - 1) / me) * b[j]) {
							curMask &= ~(1L << j);
						}
					}
				steps = steps(curMask);
			}
			int id = Long.numberOfTrailingZeros(curMask);
			guess(2 * (a[id] + b[id] - 2));
		}

		static int steps(long mask) {
			if (Long.bitCount(mask) <= 1) return 0;
			Integer ret = best.get(mask);
			if (ret != null) return ret;
			ret = 100;
			for (int i = 0; i < tot; i++)
				if ((mask & (1L << i)) != 0) {
					int me = a[i];
					Map<Integer, Long> masks = new HashMap<>();
					for (int j = 0; j < tot; j++)
						if ((mask & (1L << j)) != 0) {
							for (int val : new int[]{(a[j] / me) * b[j], ((a[j] + me - 1) / me) * b[j]}) {
								masks.put(val, masks.getOrDefault(val, 0L) | (1L << j));
							}
						}
					int ans = 0;
					for (Long nMask : masks.values()) {
						if (nMask == mask) {
							ans = 100;
							break;
						}
						ans = Math.max(ans, 1 + steps(nMask));
					}
					if (ans < ret) {
						ret = ans;
						choose.put(mask, me);
					}
				}
			best.put(mask, ret);
			return ret;
		}

		static int query(int multiples) {
			int tot = MAX * (MAX / multiples);
			out.println("? " + tot);
			for (int i = multiples; i <= MAX; i += multiples) {
				for (int j = 1; j <= MAX; j++) {
					out.print(i + " " + j + " ");
				}
			}
			out.println();
			out.flush();
			return sc.nextInt();
		}

		static void guess(int perimeter) {
			out.println("! " + perimeter);
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