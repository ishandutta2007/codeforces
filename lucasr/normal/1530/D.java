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
		DSecretSanta solver = new DSecretSanta();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class DSecretSanta {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			DSecretSanta.sc = sc;
			DSecretSanta.out = out;
			int n = sc.nextInt();
			int[] target = sc.nextIntArray(n);
			for (int i = 0; i < n; i++) {
				target[i]--;
			}
			boolean[] used = new boolean[n];
			IntArray _rem = new IntArray();
			int[] to = new int[n];
			Arrays.fill(to, -1);
			int ans = 0;
			for (int i = 0; i < n; i++) {
				if (!used[target[i]]) {
					used[target[i]] = true;
					to[i] = target[i];
					ans++;
				} else {
					_rem.add(i);
				}
			}
			IntArray _remTo = new IntArray();
			for (int i = 0; i < n; i++) {
				if (!used[i]) _remTo.add(i);
			}
			int[] rem = _rem.toArray();
			int[] remTo = _remTo.toArray();
			IntArray same = new IntArray();
			for (int i = 0; i < rem.length; i++) {
				if (rem[i] == remTo[i]) {
					same.add(i);
				}
			}
			int ignore = -1;
			if (same.size() == 1) {
				ignore = same.get(0);
				int who = rem[ignore];
				for (int i = 0; i < n; i++) {
					if (to[i] == target[who]) {
						to[who] = target[who];
						to[i] = who;
						break;
					}
				}
			} else {
				for (int i = 0; i + 1 < same.size(); i++) {
					int me = same.get(i);
					int next = same.get(i + 1);
					ArrayUtils.swap(remTo, me, next);
				}
			}
			for (int i = 0; i < rem.length; i++)
				if (i != ignore) {
					to[rem[i]] = remTo[i];
				}
			out.println(ans);
			for (int i = 0; i < n; i++) {
				out.print(to[i] + 1 + " ");
			}
			out.println();
		}

	}

	static class ArrayUtils {
		public static void swap(int[] array, int i, int j) {
			int tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
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
}