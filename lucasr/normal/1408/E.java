import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
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
		EAvoidRainbowCycles solver = new EAvoidRainbowCycles();
		solver.solve(1, in, out);
		out.close();
	}

	static class EAvoidRainbowCycles {
		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			int m = sc.nextInt();
			int n = sc.nextInt();
			long[] setCost = sc.nextLongArray(m);
			long[] elemCost = sc.nextLongArray(n);
			long total = 0;
			List<EAvoidRainbowCycles.Edge> edges = new ArrayList<>();
			for (int i = 0; i < m; i++) {
				int size = sc.nextInt();
				for (int j = 0; j < size; j++) {
					int elem = sc.nextInt() - 1;
					long cost = setCost[i] + elemCost[elem];
					total += cost;
					edges.add(new EAvoidRainbowCycles.Edge(i, elem, cost));
				}
			}
			UnionFind uf = new UnionFind(m + n);
			edges.sort((e1, e2) -> Long.compare(e2.cost, e1.cost));
			for (EAvoidRainbowCycles.Edge edge : edges) {
				int a = uf.find(edge.set);
				int b = uf.find(edge.elem + m);
				if (a != b) {
					uf.union(a, b);
					total -= edge.cost;
				}
			}
			out.println(total);
		}

		static class Edge {
			int set;
			int elem;
			long cost;

			public Edge(int set, int elem, long cost) {
				this.set = set;
				this.elem = elem;
				this.cost = cost;
			}

		}

	}

	static class UnionFind {
		int[] rep;

		public UnionFind(int size) {
			rep = new int[size];
			for (int i = 0; i < size; i++) {
				rep[i] = i;
			}
		}

		public int find(int val) {
			if (rep[val] != val) {
				return rep[val] = find(rep[val]);
			}
			return val;
		}

		public boolean union(int a, int b) {
			int aRep = find(a);
			int bRep = find(b);
			if (aRep == bRep) return false;
			rep[aRep] = bRep;
			return true;
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