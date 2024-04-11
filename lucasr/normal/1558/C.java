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
		CBottomTierReversals solver = new CBottomTierReversals();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class CBottomTierReversals {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			CBottomTierReversals.sc = sc;
			CBottomTierReversals.out = out;
			int n = sc.nextInt();
			int[] perm = sc.nextIntArray(n);
			for (int i = 0; i < n; i++) {
				perm[i]--;
			}
			boolean ok = true;
			for (int i = 0; i < n; i++) {
				if (i % 2 != perm[i] % 2) ok = false;
			}
			if (!ok) {
				out.println(-1);
				return;
			}
			IntArray ans = new IntArray();

			for (int i = n - 1; i > 0; i -= 2) {
				toFirst(perm, ans, i);
				firstToMatch(perm, ans);
			}

			out.println(ans.size());
			for (int i = 0; i < ans.size(); i++) {
				out.print(ans.get(i) + " ");
			}
			out.println();
		}

		static void rev(int[] p, IntArray op, int cant) {
			if (cant > 1) {
				op.add(cant);
				ArrayUtils.reverse(p, 0, cant - 1);
			}
		}

		static void toFirst(int[] perm, IntArray ops, int val) {
			if (perm[0] == val) return;
			for (int i = 0; i < perm.length; i++) {
				if (perm[i] == val) {
					rev(perm, ops, i + 1);
					return;
				}
			}
		}

		static void firstToMatch(int[] perm, IntArray ops) {
			for (int i = 1; i < perm.length; i += 2) {
				if (perm[0] - 1 == perm[i]) {
					int me = perm[0];
					rev(perm, ops, i);
					rev(perm, ops, i + 2);
					rev(perm, ops, 3);
					rev(perm, ops, me + 1);
					return;
				}
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

		public int[] nextIntArray(int n) {
			int[] ret = new int[n];
			for (int i = 0; i < n; i++) {
				ret[i] = nextInt();
			}
			return ret;
		}

	}

	static class ArrayUtils {
		public static void reverse(int[] array, int from, int to) {
			while (from < to) {
				int tmp = array[from];
				array[from] = array[to];
				array[to] = tmp;
				from++;
				to--;
			}
		}

	}

	static class IntArray {
		int[] arr;
		int size;

		public IntArray() {
			arr = new int[4];
		}

		public void add(int val) {
			if (size == arr.length) {
				arr = Arrays.copyOf(arr, 2 * arr.length);
			}
			arr[size++] = val;
		}

		public int get(int pos) {
			return arr[pos];
		}

		public int size() {
			return size;
		}

		public int[] toArray() {
			return Arrays.copyOf(arr, size);
		}

		public String toString() {
			return "IntArray " + Arrays.toString(toArray());
		}

	}
}