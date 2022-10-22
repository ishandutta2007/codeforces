import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
		EFibTree solver = new EFibTree();
		solver.solve(1, in, out);
		out.close();
	}

	static class EFibTree {
		static int MAX = 35;
		int n;
		int[][] cant;
		EFibTree.Edge[] edges;
		List<Integer>[] adj2;
		int[][] adj;
		int[] fibo;
		int[] edgeIds;
		static int counter;
		int subtract;
		int id;
		int newId;
		int index;
		int[] next;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			fibo = new int[MAX];
			fibo[0] = fibo[1] = 1;
			for (int i = 2; i < MAX; i++) {
				fibo[i] = fibo[i - 1] + fibo[i - 2];
			}
			n = sc.nextInt();
			edges = new EFibTree.Edge[n - 1];
			adj2 = new List[n];
			for (int i = 0; i < n; i++) {
				adj2[i] = new ArrayList<>();
			}
			for (int i = 0; i < n - 1; i++) {
				int a = sc.nextInt() - 1;
				int b = sc.nextInt() - 1;
				edges[i] = new EFibTree.Edge(a, b);
				adj2[a].add(i);
				adj2[b].add(i);
			}
			adj = new int[n][];
			for (int i = 0; i < n; i++) {
				adj[i] = toIntArray(adj2[i]);
			}

			cant = new int[2][n - 1];
			Arrays.fill(cant[0], -1);
			Arrays.fill(cant[1], -1);
			for (int i = 0; i < n - 1; i++) {
				calc(0, i);
				calc(1, i);
			}
			int[] all = new int[n - 1];
			edgeIds = new int[n - 1];
			for (int i = 0; i < n - 1; i++) {
				all[i] = i;
			}
			out.println(ok(all, 0) ? "YES" : "NO");

		}

		static int count() {
			return ++counter;
		}

		static int[] toIntArray(List<Integer> list) {
			int[] ret = new int[list.size()];

			int idx = 0;
			for (int val : list) {
				ret[idx++] = val;
			}

			return ret;
		}

		int calc(int dir, int e) {
			int ret = cant[dir][e];
			if (ret != -1) return ret;
			int me = dir == 0 ? edges[e].to : edges[e].from;
			ret = 1;
			for (int e2 : adj[me]) {
				if (e2 != e) {
					int d = edges[e2].from == me ? 0 : 1;
					ret += calc(d, e2);
				}
			}
			return cant[dir][e] = ret;
		}

		boolean ok(int[] tree, int id) {
			if (tree.length <= 2) return true;
			int nodes = tree.length + 1;
			for (int i = 2; i < fibo.length; i++) {
				if (nodes == fibo[i]) {
					int target1 = fibo[i - 1];
					int target2 = fibo[i - 2];
					for (int j = 0; j < tree.length; j++) {
						int eIdx = tree[j];
						if (cant[0][eIdx] == target1 || cant[0][eIdx] == target2) {
							int first = cant[0][eIdx];
							int second = cant[1][eIdx];
							int[] t1 = new int[first - 1];
							int newId = count();
							set(second, t1, id, newId);
							reduce(0, eIdx);
							if (!ok(t1, newId)) return false;
							int[] t2 = new int[second - 1];
							newId = count();
							set(first, t2, id, newId);
							reduce(1, eIdx);
							if (!ok(t2, newId)) return false;
							return true;
						}
					}
					return false;
				} else if (nodes < fibo[i]) {
					return false;
				}
			}
			return false;
		}

		void set(int subtract, int[] next, int id, int newId) {
			this.subtract = subtract;
			this.next = next;
			this.id = id;
			this.newId = newId;
			this.index = 0;
		}

		private void reduce(int dir, int e) {
			cant[1 - dir][e] -= subtract;
			int me = dir == 0 ? edges[e].to : edges[e].from;
			for (int e2 : adj[me]) {
				if (e2 != e && edgeIds[e2] == id) {
					next[index++] = e2;
					edgeIds[e2] = newId;
					int d = edges[e2].from == me ? 0 : 1;
					reduce(d, e2);
				}
			}
		}

		static class Edge {
			int from;
			int to;

			public Edge(int from, int to) {
				this.from = from;
				this.to = to;
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

	}
}