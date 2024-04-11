import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
		F1ArrayShuffling solver = new F1ArrayShuffling();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class F1ArrayShuffling {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			F1ArrayShuffling.sc = sc;
			F1ArrayShuffling.out = out;
			int n = sc.nextInt();
			int[] vals = sc.nextIntArray(n);
			IntArray[] pos = new IntArray[n + 1];
			for (int i = 0; i < n; i++) {
				if (pos[vals[i]] == null) pos[vals[i]] = new IntArray();
				pos[vals[i]].add(i);
			}
			List<Group> all = new ArrayList<>();
			for (int i = 1; i <= n; i++) {
				if (pos[i] != null) {
					all.add(new Group(i, pos[i]));
				}
			}
			all.sort(Comparator.comparingInt(g -> g.positions.size()));
			Group[] sorted = all.toArray(new Group[0]);
			int size = sorted.length;
			int from = 0;
			int[] ret = new int[n];
			while (from < size) {
				for (int i = from; i < size; i++) {
					IntArray cur = sorted[i].positions;
					ret[cur.last()] = sorted[i + 1 == size ? from : i + 1].val;
					cur.removeLast();
				}
				while (from < size && sorted[from].positions.isEmpty()) from++;
			}
			for (int i = 0; i < n; i++) {
				out.print(ret[i] + " ");
			}
			out.println();
		}

		class Group {
			int val;
			IntArray positions;

			public Group(int val, IntArray positions) {
				this.val = val;
				this.positions = positions;
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

		public int size() {
			return size;
		}

		public boolean isEmpty() {
			return size() == 0;
		}

		public int[] toArray() {
			return Arrays.copyOf(arr, size);
		}

		public String toString() {
			return "IntArray " + Arrays.toString(toArray());
		}

	}
}