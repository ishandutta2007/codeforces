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

		MinCostFlowGraph g = new MinCostFlowGraph(n + 2, n, n + 1);

		long ans = 0;

		long[] bal = new long[n];
		
		for (int i = 0; i < m; i++) {
			int from = nextInt() - 1;
			int to = nextInt() - 1;
			int cap = nextInt();
			int flow = nextInt();

			bal[from] -= flow;
			bal[to] += flow;

			if (flow <= cap) {
				g.addEdge(from, to, cap - flow, 1);
				g.addEdge(from, to, g.INF, 2);
				g.addEdge(to, from, flow, 1);
			} else {
				ans += flow - cap;
				g.addEdge(from, to, g.INF, 2);
				g.addEdge(to, from, flow - cap, 0);
				g.addEdge(to, from, cap, 1);
			}
		}
		
		g.addEdge(n - 1, 0, g.INF, 0);

		for (int i = 0; i < n; i++) {
			if (bal[i] < 0) {
				g.addEdge(i, g.T, (int) -bal[i], 0);
			} else if (bal[i] > 0) {
				g.addEdge(g.S, i, (int) bal[i], 0);
			}
		}
		
		out.println(ans + g.maxFlowMinCost()[1]);
	}

	static class MinCostFlowGraph {
		int N, S, T;
		static final int INF = Integer.MAX_VALUE / 3;

		List<MinCostFlowEdge>[] g;
		private long[] phi;
		final private long[] d;
		private boolean[] vis;
		private MinCostFlowEdge[] from;

		public MinCostFlowGraph(int n, int s, int t) {
			N = n;
			S = s;
			T = t;
			g = new List[N];
			for (int i = 0; i < N; i++) {
				g[i] = new ArrayList<>();
			}
			phi = new long[N];
			vis = new boolean[N];
			d = new long[N];
			from = new MinCostFlowEdge[N];

			cache = new Integer[N];
			for (int i = 0; i < N; i++) {
				cache[i] = i;
			}
		}

		void addEdge(int v1, int v2, int cap, int cost) {
			
//			System.err.println(v1 + " " + v2 + " " + cap + " " + cost);
			
			MinCostFlowEdge e1 = new MinCostFlowEdge(v2, cap, cost);
			MinCostFlowEdge e2 = new MinCostFlowEdge(v1, 0, -cost);
			e1.rev = e2;
			e2.rev = e1;
			g[v1].add(e1);
			g[v2].add(e2);
		}

		int curFlow = 0;
		int curCost = 0;

		Integer[] cache;
		TreeSet<Integer> set = new TreeSet<>();

		Comparator<Integer> byDist = new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				return Long.compare(d[o1], d[o2]);
			}
		};

		void findPathELogV() {
			set.clear();
			set.add(cache[S]);
			Arrays.fill(d, INF);
			Arrays.fill(vis, false);
			d[S] = 0;
			while (!set.isEmpty()) {
				int v = set.pollFirst();
				vis[v] = true;
				if (v == T)
					break;
				List<MinCostFlowEdge> adj = g[v];
				for (int i = 0; i < adj.size(); i++) {
					MinCostFlowEdge e = adj.get(i);
					if (e.flow == e.cap)
						continue;
					if (d[e.to] > d[v] + e.cost + phi[v] - phi[e.to]) {
						set.remove(cache[e.to]);
						d[e.to] = d[v] + e.cost + phi[v] - phi[e.to];
						set.add(cache[e.to]);
						from[e.to] = e;
					}
				}
			}
		}

		void findPathV2() {
			Arrays.fill(d, INF);
			Arrays.fill(vis, false);
			d[S] = 0;
			while (true) {
				int v = -1;
				for (int i = 0; i < N; i++) {
					if (!vis[i] && (v == -1 || d[i] < d[v])) {
						v = i;
					}
				}
				vis[v] = true;
				if (v == T)
					break;
				List<MinCostFlowEdge> adj = g[v];
				for (int i = 0; i < adj.size(); i++) {
					MinCostFlowEdge e = adj.get(i);
					if (e.flow == e.cap)
						continue;
					if (d[e.to] > d[v] + e.cost + phi[v] - phi[e.to]) {
						d[e.to] = d[v] + e.cost + phi[v] - phi[e.to];
						from[e.to] = e;
					}
				}
			}
		}

		int[] augmentFlow(int flowLeft) {
			// returns null if it can't be augmented
//			findPathELogV();
			 findPathV2();
			if (d[T] == INF) {
				return null;
			}
			for (int i = 0; i < N; i++) {
				if (vis[i]) {
					phi[i] += d[i] - d[T];
				}
			}

			int addFlow = flowLeft;
			int costPerFlowUnit = 0;

			for (int v = T; v != S; v = from[v].rev.to) {
				MinCostFlowEdge e = from[v];
				addFlow = Math.min(addFlow, e.cap - e.flow);
				costPerFlowUnit += e.cost;
			}
			
//			System.err.println("pushing flow " + addFlow);
//			System.err.println("cost of 1 = " + costPerFlowUnit);

			for (int v = T; v != S; v = from[v].rev.to) {
				MinCostFlowEdge e = from[v];
				e.flow += addFlow;
				e.rev.flow -= addFlow;
			}

			return new int[] { addFlow, costPerFlowUnit };
		}

		int[] maxFlowMinCost() {
			int[] ret = new int[2];
			while (true) {
				int[] delta = augmentFlow(INF);
				
//				System.err.println(Arrays.toString(delta));
				
				if (delta == null)
					break;
				
				ret[0] += delta[0];
				ret[1] += delta[0] * delta[1];
			}
			return ret;
		}
	}

	static class MinCostFlowEdge {
		int to;
		int flow, cap;

		int cost;

		MinCostFlowEdge rev;

		public MinCostFlowEdge(int to, int cap, int cost) {
			this.to = to;
			this.cap = cap;
			this.cost = cost;
		}
	}

	D() throws IOException {
//		br = new BufferedReader(new FileReader("D.in"));
//		out = new PrintWriter("D_wa.out");
		
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