import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		List<Integer>[] nums = new List[2];
		for (int i = 0; i < 2; i++) {
			nums[i] = new ArrayList<>();
		}
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			nums[a[i] % 2].add(i);
		}

		if (nums[0].size() != nums[1].size()) {
			out.println("Impossible");
			return;
		}

		boolean[] isPrime = new boolean[21000];
		Arrays.fill(isPrime, true);
		for (int i = 2; i * i < isPrime.length; i++) {
			if (isPrime[i]) {
				for (int j = i * i; j < isPrime.length; j += i) {
					isPrime[j] = false;
				}
			}
		}

		FlowGraph g = new FlowGraph(n + 2, n, n + 1);
		for (int i = 0; i < nums[0].size(); i++) {
			g.addDirectedEdge(g.S, nums[0].get(i), 2);
		}
		for (int i = 0; i < nums[1].size(); i++) {
			g.addDirectedEdge(nums[1].get(i), g.T, 2);
		}
		for (int i = 0; i < nums[0].size(); i++)
			for (int j = 0; j < nums[1].size(); j++) {
				if (isPrime[a[nums[0].get(i)] + a[nums[1].get(j)]]) {
					g.addDirectedEdge(nums[0].get(i), nums[1].get(j), 1);
				}
			}
		int f = g.maxFlow();
		if (f != n) {
			out.println("Impossible");
			return;
		}
		
		List<List<Integer>> ans = g.getCycles();
		out.println(ans.size());
		for (List<Integer> table : ans) {
			out.print(table.size() + " ");
			for (int x : table) {
				out.print(x + 1 + " ");
			}
			out.println();
		}
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

		List<List<Integer>> getCycles() {
			boolean[] vis = new boolean[N];
			List<List<Integer>> ret = new ArrayList<>();
			for (int i = 0; i < N - 2; i++) {
				if (!vis[i]) {
					List<Integer> addL = new ArrayList<>();
					dfsC(i, -1, vis, addL);
					ret.add(addL);
				}
			}
			return ret;
		}
		
		void dfsC(int v, int prev, boolean[] vis, List<Integer> cycle) {
			vis[v] = true;
			cycle.add(v);
			for (FlowEdge e : g[v]) {
//				System.err.println(v + " " + e.to + " " + e.flow);
				if ((e.flow == 1 || e.flow == -1) && e.to != prev && !vis[e.to]) {
					dfsC(e.to, v, vis, cycle);
				}
			}
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