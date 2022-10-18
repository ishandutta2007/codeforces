import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[][] go(int[] preArg, int[] cycleArg, int n, int maxJustPre,
			int whatCycle) {

		int[] pre = preArg.clone();
		int[] cycle = cycleArg.clone();

		List<Integer>[] justCycle = new List[n + 1];
		List<Integer>[] justPre = new List[n];
		List<Integer> none = new ArrayList<>();

		for (int i = 0; i <= n; i++) {
			justCycle[i] = new ArrayList<>();
		}

		for (int i = 0; i < n; i++) {
			justPre[i] = new ArrayList<>();
		}

		int unknown = 0;

		int[][] have = new int[n + 1][n];
		for (int i = 0; i < n; i++) {
			if (pre[i] != -1 && cycle[i] != -1) {
				have[cycle[i]][pre[i]]++;
			} else {
				unknown++;
			}
			if (pre[i] != -1 && cycle[i] == -1) {
				justPre[pre[i]].add(i);
			}
			if (pre[i] == -1 && cycle[i] != -1) {
				justCycle[cycle[i]].add(i);
			}
			if (pre[i] == -1 && cycle[i] == -1) {
				none.add(i);
			}
		}

		// System.err.println(Arrays.toString(have[4]));
		// System.err.println(Arrays.toString(have[6]));

		int[][] need = new int[n + 1][];
		for (int i = 0; i <= n; i++) {
			need[i] = have[i].clone();
		}

		for (int i = 0; i < n; i++) {
			if (pre[i] == -1 && cycle[i] != -1) {
				if (need[cycle[i]][0] == 0) {
					need[cycle[i]][0] = 1;
				}
			}
		}

		for (int j = 0; j <= maxJustPre; j++) {
			if (need[whatCycle][j] == 0) {
				need[whatCycle][j] = 1;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = n - 2; j >= 0; j--) {
				if (need[i][j + 1] != 0 && need[i][j] == 0) {
					need[i][j] = 1;
				}
			}

			need[i][0] = (need[i][0] + i - 1) / i * i;
		}

		int N = n + (n + 1) + n * (n + 1) + 2;
		int S = N - 2;
		int T = N - 1;

		g = new List[N];
		for (int i = 0; i < N; i++) {
			g[i] = new ArrayList<>();
		}

		for (int i = 0; i < n + 1; i++) {
			addEdge(S, i, justCycle[i].size());
		}
		for (int i = 0; i < n; i++) {
			addEdge(S, i + (n + 1), justPre[i].size());
		}

		for (int i = 0; i < n + 1; i++) {
			for (int col = 0; col < n; col++) {
				addEdge(i, n + (n + 1) + i * n + col, INF);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int row = 0; row < n + 1; row++) {
				addEdge(i + (n + 1), n + (n + 1) + i + row * n, INF);
			}
		}

		int needFlow = 0;

		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < n; j++) {
				addEdge(n + (n + 1) + i * n + j, T, need[i][j] - have[i][j]);
				needFlow += need[i][j] - have[i][j];
			}
		}

		if (needFlow > unknown) {
			return null;
		}

		int haveFlow = 0;

		dist = new int[N];
		int[] que = new int[N];
		ptr = new int[N];

		while (true) {

			Arrays.fill(dist, INF);
			dist[S] = 0;
			int head = 0, tail = 0;
			que[tail++] = S;

			while (head < tail) {
				int v = que[head++];
				List<Edge> adj = g[v];

				for (int i = 0; i < adj.size(); i++) {
					Edge e = adj.get(i);
					if (e.flow < e.cap && dist[e.to] > dist[v] + 1) {
						dist[e.to] = dist[v] + 1;
						que[tail++] = e.to;
					}
				}

			}

			if (dist[T] == INF) {
				break;
			}

			Arrays.fill(ptr, 0);

			int addFlow;
			do {
				addFlow = dfs(S, T, INF);
				haveFlow += addFlow;
			} while (addFlow > 0);
		}

		if (haveFlow + none.size() < needFlow) {
			return null;
		}

		for (int i = 0; i < haveFlow; i++) {
			decompose(S, T, 0);

			int lhs = path[1];
			int rhs = path[2] - n - (n + 1);

			int row = rhs / n;
			int col = rhs % n;

			have[row][col]++;

			if (lhs < n + 1) {
				int what = justCycle[lhs].remove(justCycle[lhs].size() - 1);
				if (cycle[what] != row || pre[what] != -1) {
					throw new AssertionError();
				}
				pre[what] = col;
			} else {
				lhs -= n + 1;
				int what = justPre[lhs].remove(justPre[lhs].size() - 1);
				if (cycle[what] != -1 || pre[what] != col) {
					throw new AssertionError();
				}
				cycle[what] = row;
			}
		}

		for (int row = 0; row < n + 1; row++)
			for (int col = 0; col < n; col++) {

				for (int i = 0; i < need[row][col] - have[row][col]; i++) {

					int what = none.remove(none.size() - 1);

					cycle[what] = row;
					pre[what] = col;
				}
			}

		for (int j = 0; j < n; j++) {
			for (int what : justPre[j]) {
				cycle[what] = (j == 0 ? 1 : whatCycle); // lul, not intended
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int what : justCycle[i]) {
				pre[what] = 1;
			}
		}

		for (int what : none) {
			cycle[what] = 1;
			pre[what] = 0;
		}

		return new int[][] { pre, cycle };
	}

	int[] ptr;
	int[] dist;

	int[] path = new int[4];

	void decompose(int v, int to, int depth) {
		path[depth] = v;
		if (v == to) {
			return;
		}
		for (Edge e : g[v]) {
			if (e.flow > 0) {
				e.flow--;
				e.rev.flow++;
				decompose(e.to, to, depth + 1);
				return;
			}
		}
	}

	int dfs(int v, int to, int curFlow) {
		if (v == to)
			return curFlow;
		List<Edge> adj = g[v];
		for (; ptr[v] < adj.size(); ptr[v]++) {
			Edge e = adj.get(ptr[v]);
			if (dist[e.to] == dist[v] + 1 && e.flow != e.cap) {
				int go = dfs(e.to, to, Math.min(curFlow, e.cap - e.flow));
				if (go != 0) {
					e.flow += go;
					e.rev.flow -= go;
					return go;
				}
			}
		}
		return 0;
	}

	List<Edge>[] g;
	int[] vis;
	int visVer;

	static final int INF = Integer.MAX_VALUE / 3;

	void addEdge(int from, int to, int cap) {
		if (cap == 0) {
			return;
		}
		Edge e1 = new Edge(to, cap);
		Edge e2 = new Edge(from, 0);
		e1.rev = e2;
		e2.rev = e1;
		g[from].add(e1);
		g[to].add(e2);
	}

	static class Edge {
		int to, flow, cap;
		Edge rev;

		public Edge(int to, int cap) {
			this.to = to;
			this.cap = cap;
		}
	}

	void outputGraph(int[] pre, int[] cycle, int n) {
		// System.err.println(Arrays.toString(pre));
		// System.err.println(Arrays.toString(cycle));
		List<Integer>[][] all = new List[n + 1][n];
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < n; j++) {
				all[i][j] = new ArrayList<>();
			}
		}

		for (int i = 0; i < n; i++) {
			all[cycle[i]][pre[i]].add(i);
		}

		int[] nxt = new int[n];
		for (int i = 1; i <= n; i++) {
			List<Integer> who = all[i][0];

			if (who.size() % i != 0) {
				throw new AssertionError();
			}

			for (int j = 0; j < who.size(); j += i) {

				nxt[who.get(j)] = who.get(j + i - 1);

				for (int k = j; k < j + i - 1; k++) {
					nxt[who.get(k + 1)] = who.get(k);
				}
			}

			for (int j = 1; j < n; j++) {
				who = all[i][j];
				if (who.isEmpty()) {
					break;
				}

				for (int v : who) {
					nxt[v] = all[i][j - 1].get(0);
				}

			}

		}

		for (int x : nxt) {
			out.print((x + 1) + " ");
		}
		out.println();
	}

	void solve() throws IOException {
		int n = nextInt();

		int maxJustPre = -1;

		int whichCycle = -1;

		int[] pre = new int[n];
		int[] cycle = new int[n];

		int[] justCycle = new int[n + 1];
		
		boolean[] atLeastOne = new boolean[n + 1];

		for (int i = 0; i < n; i++) {
			pre[i] = myNextInt();
			cycle[i] = myNextInt();
			
			if (cycle[i] != -1) {
				atLeastOne[cycle[i]] = true;
			}

			if (pre[i] == -1 && cycle[i] != -1) {
				justCycle[cycle[i]]++;
			}

			if (cycle[i] == -1) {
				maxJustPre = Math.max(maxJustPre, pre[i]);
			}
		}

		for (int i = 0; i < n; i++) {
			if (pre[i] >= maxJustPre && cycle[i] != -1) {
				whichCycle = cycle[i];
				break;
			}
		}

		if (whichCycle == -1) {

			boolean[][] used = new boolean[n + 1][n];

			for (int i = 0; i < n; i++) {
				if (pre[i] != -1 && cycle[i] != -1) {
					used[cycle[i]][pre[i]] = true;
				}
			}

			int minUnused = maxJustPre + 2;

			for (int i = 1; i <= n; i++) {
				int cntUnused = 0;
				for (int j = 0; j <= maxJustPre; j++) {
					if (!used[i][j]) {
						cntUnused++;
					}
				}
				cntUnused = Math.max(cntUnused - justCycle[i], 0);
				if (cntUnused < minUnused) {
					minUnused = cntUnused;
					whichCycle = i;
				}
			}
		}

		if (whichCycle == -1) {
			whichCycle = 1;
		}

		// System.err.println(whichCycle);

		// for (int cyc = 1; cyc <= n; cyc++) {
		// while (true) {
		// int cyc = rng.nextInt(n) + 1;
		// if (System.currentTimeMillis() - startTime > 1750) {
		// break;
		// }
//		int cyc = whichCycle;
		int cyc = 1;
		{
			int[][] tmp = go(pre, cycle, n, maxJustPre, cyc);
			if (tmp != null) {
				// System.err.println(cyc);
				outputGraph(tmp[0], tmp[1], n);
				return;
			}
		}

		for (cyc = 1; cyc <= n; cyc++) {
			// while (true) {
			// int cyc = rng.nextInt(n) + 1;
			if (!atLeastOne[cyc]) {
				continue;
			}
//			if (System.currentTimeMillis() - startTime > 1750) {
//				break;
//			}
			// int cyc = whichCycle;
			// {
			int[][] tmp = go(pre, cycle, n, maxJustPre, cyc);
			if (tmp != null) {
				// System.err.println(cyc);
				outputGraph(tmp[0], tmp[1], n);
				return;
			}
		}

		out.println(-1);
	}

	int myNextInt() {
		String s = nextToken();
		if (s.equals("?")) {
			return -1;
		}
		return Integer.parseInt(s);
	}

	static long startTime = System.currentTimeMillis();

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