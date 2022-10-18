import java.io.*;
import java.util.*;

import javax.swing.plaf.basic.BasicInternalFrameTitlePane.MaximizeAction;

public class cf199E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		List<Integer>[] g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}
		Node[] a = new Node[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Node();
		}

		int[] p = new int[n];
		p[0] = -1;
		ArrayDeque<Integer> q = new ArrayDeque<>();
		q.add(0);
		a[0].depth = 0;
		while (!q.isEmpty()) {
			int v = q.poll();
			for (int u : g[v]) {
				if (u == p[v]) {
					continue;
				}
				p[u] = v;
				a[u].up = a[v];
				a[u].depth = a[v].depth + 1;
				a[u].update();
				q.add(u);
			}
		}
		a[0].applyAll = 0;

		// for (int j = 0; j < n; j++) {
		// System.err.println(a[j]);
		// }
		// System.err.println("--------------");

		for (int i = 0; i < m; i++) {
			int type = nextInt();
			int v = nextInt() - 1;
			LinkCut.expose(a[v]);

			// if (i == 1) {
			// for (int j = 0; j < n; j++) {
			// System.err.println(a[j]);
			// }
			// System.err.println("--------------");
			// }

			LinkCut.splay(a[v]);
			if (type == 1) {
				a[v].applyAll = Math.min(a[v].applyAll, a[v].depth);
			} else {
				out.println(a[v].depth + Node.getMin(a[v]));
			}

//			for (int j = 0; j < n; j++) {
//				System.err.println(a[j]);
//			}
//			System.err.println("--------------");

		}
	}

	static final int INF = Integer.MAX_VALUE;

	static class Node {
		Node l, r, up;

		int applyAll = INF;
		int depth;
		int maxDepth;
		int here = INF; // not considering applyAll
		int minAll = INF; // not considering applyAll

		void update() {
			maxDepth = r != null ? r.maxDepth : depth;
			minAll = Math.min(Math.min(getMin(l), getMin(r)), here);
		}

		static int getMin(Node v) {
			return v == null ? INF : Math.min(v.minAll, v.applyAll - 2 * v.maxDepth);
		}

		void push() {
			if (l != null) {
				l.applyAll = Math.min(l.applyAll, applyAll);
			}
			if (r != null) {
				r.applyAll = Math.min(r.applyAll, applyAll);
			}
			minAll = Math.min(minAll, applyAll - 2 * maxDepth);
			here = Math.min(here, applyAll - 2 * depth);
			applyAll = INF;
		}
		
		boolean isRoot() {
			return up == null || (up.l != this && up.r != this);
		}

		public Node() {
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

//		@Override
//		public String toString() {
//			return id + "[" + (l == null ? "" : "l=" + l.id + ", ")
//					+ (r == null ? "" : "r=" + r.id + ", ")
//					+ (up == null ? "" : "up=" + up.id + ", ") + "size = "
//					+ size + ", applyAll = " + applyAll + ", minAll = "
//					+ minAll + ", here = " + here;
//		}
	}

	static class LinkCut {

		public static void splay(Node v) {
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

		public static void expose(Node v) {
			for (Node rest = null; v != null; rest = v, v = v.up) {
				splay(v);
				v.r = rest;
				v.update();
			}
		}

	}

	cf199E() throws IOException {
		if (System.getProperty("ONLINE_JUDGE") != null) {
			br = new BufferedReader(new InputStreamReader(System.in));
		} else {
			br = new BufferedReader(new FileReader("in.txt"));
		}
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new cf199E();
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