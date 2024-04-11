import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer> primeFactors(int x) {
		List<Integer> ret = new ArrayList<>(9);
		for (int i = 2; i * i <= x; i++) {
			if (x % i == 0) {
				ret.add(i);
				while (x % i == 0) {
					x /= i;
				}
			}
		}
		if (x != 1) {
			ret.add(x);
		}
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		Set<Integer> all = new HashSet<>();
		for (int x : a) {
			all.addAll(primeFactors(x));
		}

		FlowGraph g = new FlowGraph(n + 2, n, n + 1);
		for (int i = 0; i < n; i += 2) {
			g.addDirectedEdge(g.S, i, 0);
		}
		for (int i = 1; i < n; i += 2) {
			g.addDirectedEdge(i, g.T, 0);
		}
		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			if (v1 % 2 == 0) {
				g.addDirectedEdge(v1, v2, Integer.MAX_VALUE / 5);
			} else {
				g.addDirectedEdge(v2, v1, Integer.MAX_VALUE / 5);
			}
		}
		int ans = 0;
		for (int x : all) {
			g.clear();
			for (FlowEdge e : g.g[g.S]) {
				e.cap = getCap(a[e.to], x);
			}
			for (FlowEdge e : g.g[g.T]){
				e.rev.cap = getCap(a[e.to], x);
			}
			ans += g.maxFlow();
		}
		out.println(ans);
	}

	int getCap(int x, int p) {
		int ret = 0;
		while (x % p == 0) {
			ret++;
			x /= p;
		}
		return ret;
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

		public void addDirectedEdge(int v1, int v2, int cap) {
			FlowEdge e1 = new FlowEdge(v2, cap);
			FlowEdge e2 = new FlowEdge(v1, 0);
			e1.rev = e2;
			e2.rev = e1;
			g[v1].add(e1);
			g[v2].add(e2);
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
		
		public void clear() {
			for (int i = 0; i < N; i++) 
				for (FlowEdge e : g[i]) {
					e.flow = 0;
				}
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

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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