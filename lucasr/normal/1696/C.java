import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
		CFishingprincePlaysWithArray solver = new CFishingprincePlaysWithArray();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class CFishingprincePlaysWithArray {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			CFishingprincePlaysWithArray.sc = sc;
			CFishingprincePlaysWithArray.out = out;
			int n = sc.nextInt();
			int m = sc.nextInt();
			int[] a = sc.nextIntArray(n);
			int k = sc.nextInt();
			int[] b = sc.nextIntArray(k);

			out.println(Arrays.equals(get(a, m), get(b, m)) ? "Yes" : "No");
		}

		static long[] get(int[] vals, int m) {
			LongArray ret = new LongArray();
			long cur = -1;
			long cant = 0;
			for (int i = 0; i < vals.length; i++) {
				long me = vals[i];
				long meCant = 1;
				while (me % m == 0) {
					me /= m;
					meCant *= m;
				}
				if (me != cur) {
					if (cant > 0) {
						ret.add(cur);
						ret.add(cant);
					}
					cant = 0;
				}
				cur = me;
				cant += meCant;
			}
			if (cant > 0) {
				ret.add(cur);
				ret.add(cant);
			}

			return ret.toArray();
		}

	}

	static class LongArray {
		long[] arr;
		int size;

		public LongArray() {
			arr = new long[4];
		}

		public void add(long val) {
			if (size == arr.length) {
				arr = Arrays.copyOf(arr, 2 * arr.length);
			}
			arr[size++] = val;
		}

		public long[] toArray() {
			return Arrays.copyOf(arr, size);
		}

		public String toString() {
			return "LongArray " + Arrays.toString(toArray());
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

		public int[] nextIntArray(int n) {
			return nextIntArray(n, false);
		}

		public int[] nextIntArray(int n, boolean subtractOne) {
			int add = subtractOne ? -1 : 0;
			int[] ret = new int[n];
			for (int i = 0; i < n; i++) {
				ret[i] = nextInt() + add;
			}
			return ret;
		}

	}
}