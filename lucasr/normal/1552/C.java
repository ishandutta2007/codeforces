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
		CMaximizeTheIntersections solver = new CMaximizeTheIntersections();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class CMaximizeTheIntersections {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			CMaximizeTheIntersections.sc = sc;
			CMaximizeTheIntersections.out = out;
			int n = sc.nextInt();
			int k = sc.nextInt();
			int[] from = new int[n], to = new int[n];
			boolean[] used = new boolean[2 * n];
			for (int i = 0; i < k; i++) {
				from[i] = sc.nextInt() - 1;
				to[i] = sc.nextInt() - 1;
				used[from[i]] = true;
				used[to[i]] = true;
			}
			IntArray rem = new IntArray();
			for (int i = 0; i < 2 * n; i++) {
				if (!used[i]) rem.add(i);
			}
			for (int i = 0; i < n - k; i++) {
				from[i + k] = rem.get(i);
				to[i + k] = rem.get(n - k + i);
			}
			int ans = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < i; j++) {
					int min = Math.min(from[i], to[i]);
					int max = Math.max(from[i], to[i]);
					int tot = 0;
					if (min < from[j] && from[j] < max) tot++;
					if (min < to[j] && to[j] < max) tot++;
					if (tot == 1) ans++;
				}
			}
			out.println(ans);
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