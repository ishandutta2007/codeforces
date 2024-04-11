import java.io.*;
import java.util.*;

public class RoadOrientation {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void writeLabels(Node v) {
		if (v == null) {
			return;
		}
		writeLabels(v.l);
		label[v.id] = ptr++;
		writeLabels(v.r);
	}

	static class Node {
		Node l, r, up;

		int size;
		int id;

		void update() {
			size = 1 + getSize(l) + getSize(r);
		}

		static int getSize(Node v) {
			return v == null ? 0 : v.size;
		}

		void push() {
		}

		boolean isRoot() {
			return up == null;
		}

		public Node(int id) {
			this.id = id;
			update();
		}

		static private void relink(Node v, Node u) {
			Node t = u.up;
			if (v != null) {
				v.up = t;
			}
			if (t != null) {
				if (t.l == u) {
					t.l = v;
				} else if (t.r == u) {
					t.r = v;
				}
			}
		}

		private void rotate() {
			Node u = up;

			if (u.l == this) {
				relink(r, this);
				r = u;
			} else {
				relink(l, this);
				l = u;
			}

			relink(this, u);
			u.up = this;
			u.update();
		}
	}

	static void splay(Node v) {
		if (v.isRoot()) {
			v.push();
			return;
		}
		do {
			Node u = v.up;
			Node t = u.up;
			boolean uRoot = u.isRoot();
			if (!uRoot) {
				t.push();
			}
			u.push();
			v.push();
			if (!uRoot) {
				((t.l == u) == (u.l == v) ? u : v).rotate();
			}
			v.rotate();
		} while (!v.isRoot());
		v.update();
	}

	int[] vs, us;
	List<Integer>[] g;

	int[] par;
	int[] depth;

	int[] order;
	int ptr;

	int[] label;

	void dfs(int v, int p, int curD) {
		order[ptr++] = v;
		par[v] = p;
		depth[v] = curD;

		for (int u : g[v]) {
			if (depth[u] == -1) {
				dfs(u, v, curD + 1);
			}
		}
	}

	int getPos(Node v) {
		splay(v);
		return Node.getSize(v.l);
	}

	boolean[] solve(int n, int m, int s, int t, int[] vs, int[] us) {
		this.vs = vs;
		this.us = us;

		// TODO: remove ArrayLists
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			g[vs[i]].add(us[i]);
			g[us[i]].add(vs[i]);
		}

		par = new int[n];
		depth = new int[n];
		order = new int[n];
		ptr = 0;

		Arrays.fill(depth, -1);

		dfs(s, -1, 0);

		Node[] nodes = new Node[n];

		Node root = null;

		for (int v = t; v != -1; v = par[v]) {
			nodes[v] = new Node(v);
			nodes[v].r = root;
			if (root != null) {
				root.up = nodes[v];
			}
			root = nodes[v];
			root.update();
		}

		for (int v : order) {
			if (nodes[v] == null) {
				return null;
			}
			for (int u : g[v]) {
				if (nodes[u] != null || depth[u] <= depth[v] + 1) {
					continue;
				}

				int end = u;
				while (nodes[end] == null) {
					end = par[end];
				}

				if (end == v) {
					return null;
				}

				int posEnd = getPos(nodes[end]);
				int posV = getPos(nodes[v]);

				if (posV < posEnd) {
					// v is root

					Node nxt = nodes[v].r; // should not be null as v is before
											// end
					nxt.up = null;
					nodes[v].r = null;
					nodes[v].update();

					while (nxt.l != null) {
						nxt = nxt.l;
					}

					splay(nxt);

					Node cur = null;

					while (nodes[u] == null) {
						nodes[u] = new Node(u);
						nodes[u].l = cur;
						if (cur != null) {
							cur.up = nodes[u];
						}
						nodes[u].update();
						cur = nodes[u];
						u = par[u];
					}

					nxt.l = cur;
					cur.up = nxt;
					nxt.update();

					nxt.up = nodes[v];
					nodes[v].r = nxt;
					nodes[v].update();

				} else {

					Node nxt = nodes[v].l;
					nxt.up = null;
					nodes[v].l = null;
					nodes[v].update();

					while (nxt.r != null) {
						nxt = nxt.r;
					}

					splay(nxt);

					Node cur = null;

					while (nodes[u] == null) {
						nodes[u] = new Node(u);
						nodes[u].r = cur;
						if (cur != null) {
							cur.up = nodes[u];
						}
						nodes[u].update();
						cur = nodes[u];
						u = par[u];
					}

					nxt.r = cur;
					cur.up = nxt;
					nxt.update();

					nxt.up = nodes[v];
					nodes[v].l = nxt;
					nodes[v].update();
				}

			}
		}

		splay(nodes[s]);

		ptr = 0;
		label = new int[n];

		writeLabels(nodes[s]);

		boolean[] ret = new boolean[m];
		for (int i = 0; i < m; i++) {
			ret[i] = label[vs[i]] < label[us[i]];
		}

		return ret;
	}

	void checkAnswer(int n, int m, int s, int t, int[] vs, int[] us,
			boolean[] ans) {
		if (ans == null) {
			return;
		}

		boolean[] hasIn = new boolean[n];
		boolean[] hasOut = new boolean[n];

		for (int i = 0; i < m; i++) {
			if (ans[i]) {
				hasOut[vs[i]] = true;
				hasIn[us[i]] = true;
			} else {
				hasOut[us[i]] = true;
				hasIn[vs[i]] = true;
			}
		}

		for (int i = 0; i < n; i++) {
			if (i == s) {
				if (hasIn[i]) {
					throw new AssertionError();
				}
			} else if (i == t) {
				if (hasOut[i]) {
					throw new AssertionError();
				}
			} else if (!hasIn[i] || !hasOut[i]) {
				throw new AssertionError();
			}
		}
	}

	void run() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);

//		for (int i = 0; i < Integer.MAX_VALUE; i++) {
//			randomTest(4, 4);
//		}

		int q = nextInt();
		while (q-- > 0) {

			int n = nextInt();
			int m = nextInt();

			int s = nextInt() - 1;
			int t = nextInt() - 1;

			int[] vs = new int[m];
			int[] us = new int[m];
			for (int i = 0; i < m; i++) {
				vs[i] = nextInt() - 1;
				us[i] = nextInt() - 1;
			}

			boolean[] ans = solve(n, m, s, t, vs, us);
			if (ans == null) {
				out.println("No");
			} else {
				
				out.println("Yes");
				for (int i = 0; i < m; i++) {
					if (ans[i]) {
						out.println((vs[i] + 1) + " " + (us[i] + 1));
					} else {
						out.println((us[i] + 1) + " " + (vs[i] + 1));
					}
				}
			}
		}

		out.close();
	}

	Random rng = new Random();

	void randomTest(int n, int m) {
		boolean[][] g = new boolean[n][n];
		for (int i = 0; i < m; i++) {
			int v = -1, u = -1;
			do {
				v = rng.nextInt(n);
				u = rng.nextInt(n);
			} while (v == u || g[v][u]);
			g[v][u] = g[u][v] = true;
		}

		int ptr = 0;
		int[] vs = new int[m];
		int[] us = new int[m];
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				if (g[i][j]) {
					vs[ptr] = i;
					us[ptr] = j;
					ptr++;
				}
			}

		for (int i = 0; i < n; i++) {
			g[i][i] = true;
		}

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					g[i][j] |= g[i][k] && g[k][j];
				}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (!g[i][j]) {
					System.err.println("not-connected");
					return;
				}
			}

		System.err.println(n + " " + Arrays.toString(vs) + " "
				+ Arrays.toString(us));

		boolean[] ans = solve(n, m, 0, 1, vs, us);
		System.err.println(Arrays.toString(ans));
		checkAnswer(n, m, 0, 1, vs, us, ans);
	}

	public static void main(String[] args) throws IOException {

		new RoadOrientation().run();
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