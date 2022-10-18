import java.io.*;
import java.util.*;

public class F_new {

	static final int INF = Integer.MAX_VALUE / 3;
	static final int[] dx = { -1, 0, 1, 0 };
	static final int[] dy = { 0, -1, 0, 1 };
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Item {
		int x, y, t;

		public Item(int x, int y, int t) {
			this.x = x;
			this.y = y;
			this.t = t;
		}
	}

	Item nextItem() throws IOException {
		int x = nextInt() - 1;
		int y = nextInt() - 1;
		int t = nextInt();
		return new Item(x, y, t);
	}

	int[] getDist(int x0, int y0) {
		int[] d = new int[sz];
		Arrays.fill(d, INF);
		d[cellNum[x0][y0]] = 0;
		ArrayDeque<Integer> q = new ArrayDeque<>();
		q.add(x0);
		q.add(y0);
		while (!q.isEmpty()) {
			int x = q.poll();
			int y = q.poll();
			int v = cellNum[x][y];
			for (int i = 0; i < 4; i++) {
				int cx = x + dx[i];
				int cy = y + dy[i];
				if (!(cx >= 0 && cx < r && cy >= 0 && cy < c)) {
					continue;
				}
				int cv = cellNum[cx][cy];
				if (cv == -1) {
					continue;
				}
				if (d[cv] > d[v] + 1) {
					d[cv] = d[v] + 1;
					q.add(cx);
					q.add(cy);
				}
			}
		}
		return d;
	}

	int sz;
	int[][] cellNum;
	int r, c;

	static class Edge implements Comparable<Edge> {
		int v1, v2;
		long when;

		public Edge(int v1, int v2, long when) {
			this.v1 = v1;
			this.v2 = v2;
			this.when = when;
		}

		@Override
		public int compareTo(Edge o) {
			return Long.compare(when, o.when);
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

	public void addEdge(int v1, int v2) {
		FlowEdge e1 = new FlowEdge(v2, 1);
		FlowEdge e2 = new FlowEdge(v1, 0);
		e1.rev = e2;
		e2.rev = e1;
		g[v1].add(e1);
		g[v2].add(e2);
	}

	List<FlowEdge>[] g;

	void solve() throws IOException {
		r = nextInt();
		c = nextInt();
		int n1 = nextInt();
		int n2 = nextInt();
		char[][] f = new char[r][];
		for (int i = 0; i < r; i++) {
			f[i] = nextToken().toCharArray();
		}
		Item we = nextItem();
		List<Item> v1 = new ArrayList<>();
		List<Item> v2 = new ArrayList<>();
		for (int i = 0; i < n1; i++) {
			v1.add(nextItem());
		}
		for (int i = 0; i < n2; i++) {
			v2.add(nextItem());
		}
		if (n1 + 1 == n2) {
			v1.add(we);
		} else if (n2 + 1 == n1) {
			v2.add(we);
		} else {
			out.println(-1);
			return;
		}
		if (v1.size() != v2.size()) {
			throw new AssertionError();
		}
		int n = v1.size();
		cellNum = new int[r][c];
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				if (f[i][j] == '.') {
					cellNum[i][j] = sz++;
				} else {
					cellNum[i][j] = -1;
				}
			}
		int[][] d = new int[sz][];
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				if (cellNum[i][j] != -1) {
					d[cellNum[i][j]] = getDist(i, j);
				}
			}
		
		g = new List[2 * n + 2 * sz + 2];
		for (int i = 0; i < g.length; i++) {
			g[i] = new ArrayList<>();
		}
		int S = g.length - 2;
		int T = g.length - 1;

		for (int i = 0; i < n; i++) {
			addEdge(S, i);
			addEdge(i + n, T);
		}
		for (int i = 0; i < sz; i++) {
			addEdge(2 * n + i, 2 * n + sz + i);
		}

		List<Edge> es = new ArrayList<>(2 * n * sz);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < sz; j++) {
				Item i1 = v1.get(i);
				int node1 = cellNum[i1.x][i1.y];
				if (d[node1][j] != INF) {
					es.add(new Edge(i, 2 * n + j, (long) d[node1][j] * i1.t));
				}

				Item i2 = v2.get(i);
				int node2 = cellNum[i2.x][i2.y];
				if (d[node2][j] != INF) {
					es.add(new Edge(2 * n + sz + j, n + i, (long) d[node2][j]
							* i2.t));
				}
			}
		Collections.sort(es);
		vis = new boolean[g.length];
		dfs1(S, T);
		int flow = 0;
		for (Edge e : es) {
			addEdge(e.v1, e.v2);
			if (vis[e.v1] && !vis[e.v2]) {
				if (dfs1(e.v2, T)) {
					flow++;
					Arrays.fill(vis, false);
					if (!dfs2(S, T)) {
						throw new AssertionError();
					}
					Arrays.fill(vis, false);
					dfs1(S, T);
				}
			}
			if (flow == n) {
				out.println(e.when);
				return;
			}
		}
		out.println(-1);
	}

	boolean[] vis;

	boolean dfs1(int v, int T) {
		vis[v] = true;
		if (v == T) {
			return true;
		}
		for (FlowEdge e : g[v]) {
			if (!vis[e.to] && e.flow < e.cap) {
				if (dfs1(e.to, T)) {
					return true;
				}
			}
		}
		return false;
	}
	
	boolean dfs2(int v, int T) {
		vis[v] = true;
		if (v == T) {
			return true;
		}
		for (FlowEdge e : g[v]) {
			if (!vis[e.to] && e.flow < e.cap) {
				if (dfs2(e.to, T)) {
					e.flow++;
					e.rev.flow--;
					return true;
				}
			}
		}
		return false;
	}

	F_new() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new F_new();
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