import java.io.*;
import java.util.*;

public class D {

	static class Edge implements Comparable<Edge> {
		int v, u, cost, idx;

		public Edge(int v, int u, int cost, int idx) {
			this.v = v;
			this.u = u;
			this.cost = cost;
			this.idx = idx;
		}

		@Override
		public int compareTo(Edge o) {
			return Integer.compare(cost, o.cost);
		}
	}

	int[] head;
	int[] next;
	Edge[] to;

	void addEdge(Edge e, int pos) {
		to[2 * pos] = e;
		next[2 * pos] = head[e.v];
		head[e.v] = 2 * pos;

		to[2 * pos + 1] = e;
		next[2 * pos + 1] = head[e.u];
		head[e.u] = 2 * pos + 1;
	}

	int[] p;

	static final int INF = Integer.MAX_VALUE / 2;

	void submit() {
		int n = nextInt();
		int m = nextInt();

		Edge[] es = new Edge[m];

		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			int cost = nextInt();
			es[i] = new Edge(v, u, cost, i);
		}

		Arrays.sort(es);
		p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}

		Arrays.sort(es);

		Edge[] mst = new Edge[n - 1];
		int ptr = 0;

		Edge[] nonMst = new Edge[m - n + 1];
		int ptrNonMst = 0;

		for (Edge e : es) {
			if (unite(e.v, e.u)) {
//				System.err.println(e.v + " " + e.u);
				mst[ptr++] = e;
			} else {
				nonMst[ptrNonMst++] = e;
			}
		}

		head = new int[n];
		Arrays.fill(head, -1);
		next = new int[2 * n - 2];
		to = new Edge[2 * n - 2];

		for (int i = 0; i < n - 1; i++) {
			addEdge(mst[i], i);
		}

		time = 0;
		depth = new int[n];
		tIn = new int[n];
		tOut = new int[n];
		up = new int[LOG][n];
		maxCostUp = new int[LOG][n];

		markMinUp = new int[LOG][n];
		for (int i = 0; i < LOG; i++) {
			Arrays.fill(markMinUp[i], INF);
		}

		dfs1(0, 0, -1);

		ans = new int[m];

		for (Edge e : nonMst) {
			int v = e.v;
			int u = e.u;
			int mid = lca(v, u);

			ans[e.idx] = Math.max(getAnsNoMst(v, mid, e.cost),
					getAnsNoMst(u, mid, e.cost)) - 1;
		}

		dfs2(0, 0, -1);

		for (int x : ans) {
			out.print(x + " ");
		}
		out.println();
	}

	void dfs2(int v, int p, int pEdge) {

		for (int idx = head[v]; idx >= 0; idx = next[idx]) {
			Edge e = to[idx];
			int u = e.v ^ e.u ^ v;
			if (u == p) {
				continue;
			}

			dfs2(u, v, e.idx);
		}

		if (pEdge == -1) {
			return;
		}

		int markSoFar = INF;

		for (int i = LOG - 1; i > 0; i--) {
			markSoFar = Math.min(markSoFar, markMinUp[i][v]);
			int mid = up[i - 1][v];
			markMinUp[i - 1][mid] = Math.min(markMinUp[i - 1][mid], markSoFar);
		}
		markSoFar = Math.min(markSoFar, markMinUp[0][v]);
		ans[pEdge] = markSoFar == INF ? -1 : markSoFar - 1;
	}

	int[] ans;

	int getAnsNoMst(int v, int u, int mark) {
		int ret = -1;
		for (int i = LOG - 1; i >= 0; i--) {
			int to = up[i][v];
			if (isAnc(u, to)) {
				ret = Math.max(ret, maxCostUp[i][v]);

				markMinUp[i][v] = Math.min(markMinUp[i][v], mark);
				v = to;
			}
		}
		return ret;
	}

	static final int LOG = 18;

	int[] tIn, tOut;
	int time;
	int[][] up;
	int[][] maxCostUp;
	int[] depth;
	int[][] markMinUp;

	boolean isAnc(int v, int u) {
		return tIn[v] <= tIn[u] && tOut[u] <= tOut[v];
	}

	int lca(int v, int u) {
		if (isAnc(v, u)) {
			return v;
		}
		if (isAnc(u, v)) {
			return u;
		}
		for (int i = LOG - 1; i >= 0; i--) {
			int to = up[i][v];
			if (!isAnc(to, u)) {
				v = to;
			}
		}
		return up[0][v];
	}

	void dfs1(int v, int p, int costUp) {
		up[0][v] = p;
		maxCostUp[0][v] = costUp;
		for (int i = 1; i < LOG; i++) {
			int mid = up[i - 1][v];
			up[i][v] = up[i - 1][mid];
			maxCostUp[i][v] = Math.max(maxCostUp[i - 1][v],
					maxCostUp[i - 1][mid]);
		}
		tIn[v] = time++;

		for (int idx = head[v]; idx >= 0; idx = next[idx]) {
			Edge e = to[idx];
			int u = e.v ^ e.u ^ v;
			if (u == p) {
				continue;
			}
			depth[u] = depth[v] + 1;
			dfs1(u, v, e.cost);
		}
		tOut[v] = time;
	}

	int get(int v) {
		return p[v] == v ? v : (p[v] = get(p[v]));
	}

	boolean unite(int v, int u) {
		v = get(v);
		u = get(u);
		if (v == u) {
			return false;
		}

		if (rng.nextBoolean()) {
			p[v] = u;
		} else {
			p[u] = v;
		}
		return true;
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {
		int n = 4;
		int m = 6;
		out.println(n + " " + m);
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				out.println(i + " " + j + " " + rand(1, 5));
			}
		}
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		 submit();
		// stress();
//		test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new D();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}