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
		GASeriousReferee solver = new GASeriousReferee();
		solver.solve(1, in, out);
		out.close();
	}

	static class GASeriousReferee {
		public static MyScanner sc;
		public static PrintWriter out;
		int n;
		int k;
		long[] toSort;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			GASeriousReferee.sc = sc;
			GASeriousReferee.out = out;
			n = sc.nextInt();
			k = sc.nextInt();
			toSort = new long[k];
			for (int i = 0; i < k; i++) {
				int tot = sc.nextInt();
				for (int j = 0; j < tot; j++) {
					toSort[i] |= 1L << (sc.nextInt() - 1);
				}
			}
			out.println(ok(0, 0, 0) ? "ACCEPTED" : "REJECTED");
		}

		boolean ok(int pos, long setMask, long setValues) {
			if (pos == k) {
				if (n > 1 && setMask + 1 != 1L << n) return false;
				if (setValues == 0) return true;
				return Long.numberOfTrailingZeros(setValues) + Long.bitCount(setValues) == n;
			}
			long nSetMask = setMask | toSort[pos];
			int toSet = Long.bitCount(nSetMask & ~setMask);
			int oldZeroes = Long.bitCount(setMask & toSort[pos] & ~setValues);
			long sortValues = toSort[pos];
			for (int i = 0; i < oldZeroes; i++) {
				sortValues &= ~Long.lowestOneBit(sortValues);
			}
			if (!ok(pos + 1, nSetMask, write(setValues, toSort[pos], sortValues))) return false;
			for (int cant = 1; cant <= toSet; cant++) {
				sortValues &= ~Long.lowestOneBit(sortValues);
				if (!ok(pos + 1, nSetMask, write(setValues, toSort[pos], sortValues))) return false;
			}
			return true;
		}

		static long write(long old, long mask, long maskVal) {
			return old & ~mask | maskVal;
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