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
		EColorsAndIntervals solver = new EColorsAndIntervals();
		solver.solve(1, in, out);
		out.close();
	}

	static class EColorsAndIntervals {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			EColorsAndIntervals.sc = sc;
			EColorsAndIntervals.out = out;
			int n = sc.nextInt();
			int k = sc.nextInt();
			IntArray[] pos = new IntArray[n];
			for (int i = 0; i < n; i++) {
				pos[i] = new IntArray();
			}
			for (int i = 1; i <= n * k; i++) {
				int color = sc.nextInt() - 1;
				pos[color].add(i);
			}
			int from = 0;
			int[] resA = new int[n], resB = new int[n];
			boolean[] used = new boolean[n];
			while (from < n) {
				int to = Math.min(from + k - 1, n);
				int ops = to - from;
				for (int end = 1; end < k && end <= ops; end++) {
					int min = -1;
					for (int i = from; i < to; i++)
						if (!used[i]) {
							if (min == -1 || pos[i].get(end) < pos[min].get(end)) {
								min = i;
							}
						}
					resA[min] = pos[min].get(end - 1);
					resB[min] = pos[min].get(end);
					used[min] = true;
				}
				from += k - 1;
			}
			for (int i = 0; i < n; i++) {
				out.println(resA[i] + " " + resB[i]);
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

		public int[] toArray() {
			return Arrays.copyOf(arr, size);
		}

		public String toString() {
			return "IntArray " + Arrays.toString(toArray());
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