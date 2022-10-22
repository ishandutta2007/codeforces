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
		F2CheckerForArrayShuffling solver = new F2CheckerForArrayShuffling();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class F2CheckerForArrayShuffling {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			F2CheckerForArrayShuffling.sc = sc;
			F2CheckerForArrayShuffling.out = out;
			int n = sc.nextInt();
			int[] a = sc.nextIntArray(n, true);
			int[] b = sc.nextIntArray(n, true);
			int big = mostCommon(a);
			IntArray[] adj = new IntArray[n];
			for (int i = 0; i < n; i++) {
				adj[i] = new IntArray();
			}
			for (int i = 0; i < n; i++) {
				if (a[i] != big && b[i] != big) {
					adj[a[i]].add(b[i]);
				}
			}

			out.println(new GraphLib.DirectedGraphCycleFinder(adj).findCycleIfExists() == null ? "AC" : "WA");
		}

		static int mostCommon(int[] a) {
			int[] freq = new int[a.length];
			for (int i : a) {
				freq[i]++;
			}
			int ret = 0;
			for (int i = 1; i < freq.length; i++) {
				if (freq[i] >= freq[ret]) ret = i;
			}
			return ret;
		}

	}

	static class GraphLib {
		public static class DirectedGraphCycleFinder {
			int n;
			IntArray[] adj;
			int[] color;
			int[] parent;
			int cycleStart;
			int cycleEnd;

			public DirectedGraphCycleFinder(IntArray[] adj) {
				this.adj = adj;
				this.n = adj.length;
			}

			private boolean dfs(int v) {
				color[v] = 1;
				for (int i = 0; i < adj[v].size(); i++) {
					int u = adj[v].get(i);
					if (color[u] == 0) {
						parent[u] = v;
						if (dfs(u)) return true;
					} else if (color[u] == 1) {
						cycleEnd = v;
						cycleStart = u;
						return true;
					}
				}
				color[v] = 2;
				return false;
			}

			public IntArray findCycleIfExists() {
				color = new int[n];
				parent = new int[n];
				Arrays.fill(parent, -1);
				cycleStart = -1;

				for (int v = 0; v < n; v++)
					if (color[v] == 0 && dfs(v)) {
						break;
					}

				if (cycleStart == -1) {
					return null;
				}
				IntArray cycle = new IntArray();
				cycle.add(cycleStart);
				for (int v = cycleEnd; v != cycleStart; v = parent[v]) {
					cycle.add(v);
				}
				cycle.add(cycleStart);
				cycle.reverse();
				return cycle;
			}

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

		public int[] nextIntArray(int n, boolean subtractOne) {
			int add = subtractOne ? -1 : 0;
			int[] ret = new int[n];
			for (int i = 0; i < n; i++) {
				ret[i] = nextInt() + add;
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

		public int get(int pos) {
			return arr[pos];
		}

		public int size() {
			return size;
		}

		public void reverse() {
			ArrayUtils.reverse(arr, 0, size - 1);
		}

		public int[] toArray() {
			return Arrays.copyOf(arr, size);
		}

		public String toString() {
			return "IntArray " + Arrays.toString(toArray());
		}

	}
}