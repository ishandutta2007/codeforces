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
		DCyclicRotation solver = new DCyclicRotation();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class DCyclicRotation {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			DCyclicRotation.sc = sc;
			DCyclicRotation.out = out;
			int n = sc.nextInt();
			int[] a = read(n);
			int[] b = read(n);
			boolean can = can(n, a, b);
			out.println(can ? "YES" : "NO");
		}

		static boolean can(int n, int[] a, int[] b) {
			IntArray[] pos = new IntArray[n];
			for (int i = 0; i < n; i++) {
				if (pos[a[i]] == null) pos[a[i]] = new IntArray();
				pos[a[i]].add(i);
			}
			boolean[] used = new boolean[n];
			int aIdx = n - 1;
			boolean can = true;
			for (int i = n - 1; i >= 0 && can; i--) {
				if (i + 1 < n && b[i] == b[i + 1]) {
					int me = pos[b[i]].last();
					used[me] = true;
					pos[b[i]].removeLast();
				} else {
					while (aIdx >= 0 && a[aIdx] != b[i]) {
						if (used[aIdx]) aIdx--;
						else break;
					}
					if (aIdx >= 0 && a[aIdx] == b[i]) {
						int me = pos[b[i]].last();
						used[me] = true;
						pos[b[i]].removeLast();
						aIdx--;
					} else can = false;
				}
			}
			return can;
		}

		public int[] read(int n) {
			int[] ret = sc.nextIntArray(n);
			for (int i = 0; i < n; i++) {
				ret[i]--;
			}
			return ret;
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

		public int last() {
			return arr[size - 1];
		}

		public void removeLast() {
			size--;
		}

		public int[] toArray() {
			return Arrays.copyOf(arr, size);
		}

		public String toString() {
			return "IntArray " + Arrays.toString(toArray());
		}

	}
}