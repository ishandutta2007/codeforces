import java.io.*;
import java.util.*;

public class F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int LOG = 20;

	static class Edge {
		int to, id;

		public Edge(int to, int id) {
			this.to = to;
			this.id = id;
		}

		@Override
		public String toString() {
			return "" + to;
		}
	}

	static class Graph {
		List<Edge>[] g;
		int N;
		int m;

		public Graph(int n) {
			N = n;
			g = new List[N];
			for (int i = 0; i < N; i++) {
				g[i] = new ArrayList<>();
			}
		}

		void addEdge(int v1, int v2) {
			g[v1].add(new Edge(v2, m));
			g[v2].add(new Edge(v1, m));
			m++;
		}

		int[] depth;
		int[] high;
		int[] biconn;
		int[] order;
		int[] par;
		int[][] up;
		int orderSz;

		void dfs1(int v, int pEdge) {
			high[v] = depth[v];
			for (Edge e : g[v]) {
				if (e.id == pEdge) {
					continue;
				}
				if (depth[e.to] == -1) {
					depth[e.to] = depth[v] + 1;
					par[e.to] = v;
					dfs1(e.to, e.id);
					high[v] = Math.min(high[v], high[e.to]);
				} else {
					high[v] = Math.min(high[v], depth[e.to]);
				}
			}
			order[orderSz++] = v;
		}

		int biComps = 0;

		int[] getBiconn() {
			depth = new int[N];
			high = new int[N];
			Arrays.fill(depth, -1);
			order = new int[N];
			orderSz = 0;
			par = new int[N];
			for (int i = 0; i < N; i++) {
				if (depth[i] == -1) {
					par[i] = -1;
					depth[i] = 0;
					dfs1(i, -1);
				}
			}

			biconn = new int[N];
			for (int i = N - 1; i >= 0; i--) {
				int v = order[i];
				if (high[v] == depth[v]) {
					biconn[v] = biComps++;
				} else {
					biconn[v] = biconn[par[v]];
				}
			}
			return biconn;
		}

		void dfs2(int v, int pEdge) {
			for (int i = 1; i < LOG; i++) {
				up[v][i] = up[up[v][i - 1]][i - 1];
			}
			for (Edge e : g[v]) {
				if (e.id == pEdge) {
					continue;
				}
				depth[e.to] = depth[v] + 1;
				up[e.to][0] = v;
				dfs2(e.to, e.id);
			}
		}

		int lca(int v1, int v2) {
			if (up[v1][LOG - 1] != up[v2][LOG - 1]) {
				return -1;
			}
			if (depth[v1] > depth[v2]) {
				int tmp = v1;
				v1 = v2;
				v2 = tmp;
			}
			for (int i = LOG - 1; i >= 0; i--) {
				if (depth[v2] - depth[v1] >= 1 << i) {
					v2 = up[v2][i];
				}
			}
			
			if (v1 == v2) {
				return v1;
			}

			for (int i = LOG - 1; i >= 0; i--) {
				int u1 = up[v1][i];
				int u2 = up[v2][i];
				if (u1 != u2) {
					v1 = u1;
					v2 = u2;
				}
			}

			return up[v1][0];
		}

		void prepareLCA() {
			depth = new int[N];
			up = new int[N][LOG];
			for (int i = 0; i < N; i++) {
				if (depth[i] == 0) {
					up[i][0] = i;
					dfs2(i, -1);
				}
			}
		}
	}

	static class Compressor {

		int N;
		int ver;

		int[] newNumber;
		int[] lastVer;
		int size;

		public Compressor(int n) {
			N = n;
			newNumber = new int[N];
			lastVer = new int[N];
			clear();
		}

		void clear() {
			ver++;
			size = 0;
		}

		int get(int v) {
			if (lastVer[v] != ver) {
				lastVer[v] = ver;
				newNumber[v] = size++;
			}

			return newNumber[v];
		}
	}

	int rotate(int x, long R, int n) {
		long y = (x + R) % n;
		if (y == 0) {
			y = n;
		}
		return (int) y;
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int q = nextInt();

		Graph g = new Graph(n);
		int[] v1 = new int[m];
		int[] v2 = new int[m];
		for (int i = 0; i < m; i++) {
			v1[i] = nextInt() - 1;
			v2[i] = nextInt() - 1;
			g.addEdge(v1[i], v2[i]);
		}

		int[] biconn = g.getBiconn();
		int N = g.biComps;

		Graph g2 = new Graph(N);
		for (int i = 0; i < m; i++) {
			int v = biconn[v1[i]];
			int u = biconn[v2[i]];
			if (v != u) {
				g2.addEdge(v, u);
			}
		}

		g2.prepareLCA();

		long R = 0;

		List<Integer> stack = new ArrayList<>(300_000);

		Compressor comp = new Compressor(N);
		List<Integer> newEdges = new ArrayList<>(1_200_000);

		for (int qId = 1; qId <= q; qId++) {
			int n1 = nextInt(); // ???
			int m1 = nextInt(); // ???
			int[] nodes = new int[n1];
			int[] v1s = new int[m1];
			int[] v2s = new int[m1];

			int[] all = new int[n1 + 2 * m1];

			for (int i = 0; i < n1; i++) {
				nodes[i] = biconn[rotate(nextInt(), R, n) - 1];
			}

			for (int i = 0; i < m1; i++) {
				v1s[i] = biconn[rotate(nextInt(), R, n) - 1];
				v2s[i] = biconn[rotate(nextInt(), R, n) - 1];
			}

			System.arraycopy(nodes, 0, all, 0, n1);
			System.arraycopy(v1s, 0, all, n1, m1);
			System.arraycopy(v2s, 0, all, n1 + m1, m1);

			Arrays.sort(all);

			stack.add(all[0]);
			newEdges.clear();

			for (int i = 1; i < all.length; i++) {
				if (all[i] == all[i - 1]) {
					continue;
				}
				int prev = all[i - 1];
				int v = all[i];

				int r = g2.lca(prev, v);

				if (r == -1) {
					for (int j = 0; j < stack.size() - 1; j++) {
						newEdges.add(stack.get(j));
						newEdges.add(stack.get(j + 1));
					}
					stack.clear();
				} else if (r != prev) {
					int depthR = g2.depth[r];
					int last = stack.remove(stack.size() - 1);
					while (true) {
						if (stack.isEmpty()) {
							stack.add(r);
						}
						int next = stack.get(stack.size() - 1);
						if (g2.depth[next] < depthR) {
							newEdges.add(r);
							newEdges.add(last);
							stack.add(r);
							break;
						}

						if (next == r) {
							newEdges.add(r);
							newEdges.add(last);
							break;
						}

						stack.remove(stack.size() - 1);
						newEdges.add(last);
						newEdges.add(next);
						last = next;
					}
				}
				stack.add(v);
			}
			
			for (int j = 0; j < stack.size() - 1; j++) {
				newEdges.add(stack.get(j));
				newEdges.add(stack.get(j + 1));
			}
			stack.clear();

			comp.clear();
			for (int x : newEdges) {
				comp.get(x);
			}
			for (int x : nodes) {
				comp.get(x);
			}
			for (int x : v1s) {
				comp.get(x);
			}
			for (int x : v2s) {
				comp.get(x);
			}
			
			Graph g3 = new Graph(comp.size);
			for (int i = 0; i < newEdges.size(); i += 2) {
				g3.addEdge(comp.get(newEdges.get(i)),
						comp.get(newEdges.get(i + 1)));
			}

			for (int i = 0; i < m1; i++) {
				g3.addEdge(comp.get(v1s[i]), comp.get(v2s[i]));
			}

			int[] smallBiconn = g3.getBiconn();
			boolean good = true;
			for (int i = 1; i < n1; i++) {
				if (smallBiconn[comp.get(nodes[i])] != smallBiconn[comp
						.get(nodes[0])]) {
					good = false;
				}
			}

			out.println(good ? "YES" : "NO");
			if (good) {
				R += qId;
			}
		}

	}

	F() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new F();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}