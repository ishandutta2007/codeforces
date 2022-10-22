import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.ArrayDeque;
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
		DXorMasTree solver = new DXorMasTree();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class DXorMasTree {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			DXorMasTree.sc = sc;
			DXorMasTree.out = out;
			int n = sc.nextInt();
			int m = sc.nextInt();
			IntArray[] adj = new IntArray[n + 1];
			int[] x = new int[n - 1], y = new int[n - 1], v = new int[n - 1];
			for (int i = 1; i <= n; i++) {
				adj[i] = new IntArray();
			}
			for (int i = 0; i < n - 1; i++) {
				x[i] = sc.nextInt();
				y[i] = sc.nextInt();
				v[i] = sc.nextInt();
				if (v[i] != -1) {
					boolean same = (Integer.bitCount(v[i]) & 1) == 0;
					adj[x[i]].add(same ? -y[i] : y[i]);
					adj[y[i]].add(same ? -x[i] : x[i]);
				}
			}
			for (int i = 0; i < m; i++) {
				int a = sc.nextInt();
				int b = sc.nextInt();
				int p = sc.nextInt();
				boolean same = p == 0;
				adj[a].add(same ? -b : b);
				adj[b].add(same ? -a : a);
			}
			int[] color = new int[n + 1];
			Arrays.fill(color, -1);
			boolean can = true;
			for (int i = 1; i <= n && can; i++)
				if (color[i] == -1) {
					color[i] = 0;
					ArrayDeque<Integer> queue = new ArrayDeque<>();
					queue.add(i);
					while (!queue.isEmpty() && can) {
						int cur = queue.pollFirst();
						for (int j = 0; j < adj[cur].size(); j++) {
							int next = adj[cur].get(j);
							boolean same = next < 0;
							next = Math.abs(next);
							if (color[next] == -1) {
								color[next] = same ? color[cur] : 1 - color[cur];
								queue.add(next);
							} else if (color[next] == color[cur] != same) {
								can = false;
							}
						}
					}
				}
			if (!can) {
				out.println("NO");
				return;
			}
			out.println("YES");
			for (int i = 0; i < n - 1; i++) {
				out.println(x[i] + " " + y[i] + " " + (v[i] == -1 ? color[x[i]] == color[y[i]] ? 0 : 1 : v[i]));
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