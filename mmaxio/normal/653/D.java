import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int x = nextInt();
		
		FlowEdge[] es = new FlowEdge[m];
		int[] caps = new int[m];

		FlowGraph g = new FlowGraph(n, 0, n - 1);
		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			caps[i] = nextInt();
			es[i] = g.addDirectedEdge(v1, v2, 0);
		}
		
		double low = 0;
		double high = 1_000_000;
		
		for (int it = 0; it < 65; it++) {
			
			double mid = (low + high) * 0.5;
			for (int i = 0; i < m; i++) {
				es[i].flow = es[i].rev.flow = 0;
				es[i].cap = (int) (caps[i] / mid);
			}
			
			if (g.maxFlow() >= x) {
				low = mid;
			} else {
				high = mid;
			}
		}
		
		out.println((low + high) * 0.5 * x);
	}

	static class FlowGraph {
		int N, S, T;
		static final int INF = Integer.MAX_VALUE / 3;

		List<FlowEdge>[] g;

		private int[] dist;
		private Deque<Integer> q;
		private int[] ptr;

		public FlowGraph(int n, int s, int t) {
			N = n;
			S = s;
			T = t;
			g = new List[N];
			for (int i = 0; i < N; i++) {
				g[i] = new ArrayList<>();
			}
			dist = new int[N];
			q = new ArrayDeque<>();
			ptr = new int[N];
		}

		public FlowEdge addDirectedEdge(int v1, int v2, int cap) {
			FlowEdge e1 = new FlowEdge(v2, cap);
			FlowEdge e2 = new FlowEdge(v1, 0);
			e1.rev = e2;
			e2.rev = e1;
			g[v1].add(e1);
			g[v2].add(e2);
			return e1;
		}

		public void addUndirectedEdge(int v1, int v2, int cap) {
			FlowEdge e1 = new FlowEdge(v2, cap);
			FlowEdge e2 = new FlowEdge(v1, cap);
			e1.rev = e2;
			e2.rev = e1;
			g[v1].add(e1);
			g[v2].add(e2);
		}

		private boolean bfs() {
			Arrays.fill(dist, INF);
			dist[S] = 0;
			q.clear();
			q.add(S);

			while (!q.isEmpty()) {
				int v = q.poll();
				List<FlowEdge> adj = g[v];
				for (int i = 0; i < adj.size(); i++) {
					FlowEdge e = adj.get(i);
					if (e.flow < e.cap && dist[e.to] > dist[v] + 1) {
						dist[e.to] = dist[v] + 1;
						q.add(e.to);
					}
				}
			}
			return dist[T] != INF;
		}

		private int dfs(int v, int curFlow) {
			if (v == T)
				return curFlow;
			List<FlowEdge> adj = g[v];
			for (; ptr[v] < adj.size(); ptr[v]++) {
				FlowEdge e = adj.get(ptr[v]);
				if (dist[e.to] == dist[v] + 1 && e.flow != e.cap) {
					int go = dfs(e.to, Math.min(curFlow, e.cap - e.flow));
					if (go != 0) {
						e.flow += go;
						e.rev.flow -= go;
						return go;
					}
				}
			}
			return 0;
		}

		public int maxFlow() {
			int flow = 0;

			while (bfs()) {
				Arrays.fill(ptr, 0);
				int addFlow;
				do {
					addFlow = dfs(S, INF);
					flow += addFlow;
				} while (addFlow > 0);
			}

			return flow;
		}

	}

	static class FlowEdge {
		int to;
		int flow, cap;

		FlowEdge rev;

		public FlowEdge(int to, int cap) {
			this.to = to;
			this.cap = cap;
		}
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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