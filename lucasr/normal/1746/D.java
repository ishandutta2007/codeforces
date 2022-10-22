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
		DPathsOnTheTree solver = new DPathsOnTheTree();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class DPathsOnTheTree {
		public static MyScanner sc;
		public static PrintWriter out;
		int[][] adj;
		long[] base;
		long[] s;
		long[] score;
		long[] scoreExtra;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			DPathsOnTheTree.sc = sc;
			DPathsOnTheTree.out = out;
			int n = sc.nextInt();
			long k = sc.nextLong();
			int[] parent = new int[n];
			parent[0] = -1;
			for (int i = 0; i + 1 < n; i++) {
				parent[i + 1] = sc.nextInt() - 1;
			}
			s = sc.nextLongArray(n);
			adj = TreeUtils.parentToAdj(parent);
			base = new long[n];
			fillBase(0, -1, k);
			score = new long[n];
			scoreExtra = new long[n];
			Arrays.fill(score, -1);
			Arrays.fill(scoreExtra, -1);
			out.println(getScore(0, -1, false));
		}

		void fillBase(int node, int parent, long b) {
			base[node] = b;
			long children = adj[node].length - 1;
			if (parent == -1) children++;
			for (int i = 0; i < adj[node].length; i++) {
				int cur = adj[node][i];
				if (cur != parent) {
					fillBase(cur, node, b / children);
				}
			}
		}

		long getScore(int node, int parent, boolean extra) {
			long[] curScore = extra ? scoreExtra : score;
			if (curScore[node] != -1) return curScore[node];
			long cc = base[node] + (extra ? 1 : 0);
			curScore[node] = cc * s[node];
			LongArray childrenExtra = new LongArray();
			for (int i = 0; i < adj[node].length; i++) {
				int cur = adj[node][i];
				if (cur != parent) {
					cc -= base[cur];
					long tmp = getScore(cur, node, false);
					childrenExtra.add(getScore(cur, node, true) - tmp);
					curScore[node] += tmp;
				}
			}
			childrenExtra.sort();
			childrenExtra.reverse();
			for (int i = 0; i < childrenExtra.size() && i < cc; i++) {
				curScore[node] += childrenExtra.get(i);
			}
			return curScore[node];
		}

	}

	static class TreeUtils {
		public static int[][] parentToAdj(int[] parent) {
			int n = parent.length;
			int[] size = new int[n];
			for (int i = 0; i < n; i++) {
				if (parent[i] >= 0) {
					size[i]++;
					size[parent[i]]++;
				}
			}
			int[][] adj = new int[n][];
			for (int i = 0; i < n; i++) {
				adj[i] = new int[size[i]];
			}
			for (int i = 0; i < n; i++) {
				int par = parent[i];
				if (par >= 0) {
					adj[par][--size[par]] = i;
					adj[i][--size[i]] = par;
				}
			}
			return adj;
		}

	}

	static class ArrayUtils {
		public static void reverse(long[] array, int from, int to) {
			while (from < to) {
				long tmp = array[from];
				array[from] = array[to];
				array[to] = tmp;
				from++;
				to--;
			}
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

		public long get(int pos) {
			return arr[pos];
		}

		public int size() {
			return size;
		}

		public void sort() {
			Arrays.sort(arr, 0, size);
		}

		public void reverse() {
			ArrayUtils.reverse(arr, 0, size - 1);
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

		public long nextLong() {
			return Long.parseLong(next());
		}

		public long[] nextLongArray(int n) {
			long[] ret = new long[n];
			for (int i = 0; i < n; i++) {
				ret[i] = nextLong();
			}
			return ret;
		}

	}
}