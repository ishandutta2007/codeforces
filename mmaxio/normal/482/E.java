import java.io.*;
import java.util.*;

public class cf275E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;
	long outp;

	void dbg(Node[] a) {
		for (Node v : a) {
			System.err.println(v.val + (v.l == null ? "" : ": l = " + v.l.val)
					+ (v.r == null ? "" : ": r = " + v.r.val)
					+ (!v.isRoot() || v.up == null ? "" : ": up = " + v.up.val)
					+ ", here = " + v.lcaHere + ", delta = " + v.delta + ", sizeOther = " + v.sizeNotLC);
		}
		System.err.println();
	}

	void solve() throws IOException {
		int n = nextInt();

		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}

		int[] par = new int[n];

		for (int i = 1; i < n; i++) {
			par[i] = nextInt() - 1;
		}

		int[] vals = new int[n];

		Node[] a = new Node[n];

		outp = 0;

		for (int i = 0; i < n; i++) {
			vals[i] = nextInt();
			a[i] = new Node(vals[i]);
			outp += vals[i];
		}

		for (int i = 1; i < n; i++) {
			Node v = a[par[i]];
			Node u = a[i];
			link(v, u);
		}
		out.println(1.0 * outp / n / n);

//		dbg(a);
		
		int q = nextInt();
		while (q-- > 0) {
			char type = nextToken().charAt(0);
			int vId = nextInt() - 1;
			Node v = a[vId];
			if (type == 'P') {
				int uId = nextInt() - 1;
				Node u = a[uId];
				LinkCut.expose(u);
				LinkCut.splay(v);
				if (v.up == null) { // v is above u
					makeParent(v, u);
				} else {
					makeParent(u, v);
				}
			} else {
				int newVal = nextInt();
				LinkCut.splay(v);
				outp += (newVal - v.val)
						* (v.lcaHere + 2L * v.delta * v.sizeNotLC);
				v.val = newVal;
				v.update();
			}
			out.println(1.0 * outp / n / n);
//			dbg(a);
		}
	}

	void makeParent(Node v, Node u) { // make v parent of u
		LinkCut.expose(u);
		LinkCut.splay(u);

		Node t = u.l;
		if (t == null) {
			throw new AssertionError();
		}

		u.l = null;
		t.up = null;
		u.update();
		outp -= 2L * t.sum * u.size;
		t.applyDelta(-u.size);

		link(v, u);
	}

	void link(Node v, Node u) {
		LinkCut.expose(v);
		LinkCut.splay(v);
		LinkCut.splay(u); // is root, so no need to expose

		outp += 2 * v.sum * u.size;
		v.applyDelta(u.size);
		v.sizeNotLC += u.size;
		u.up = v;
		v.update();
	}

	static class Node {
		Node l, r, up;
		int val, size, sizeNotLC;
		long sum, lcaHere; // lcaHere without delta

		int delta;

		void update() {
			sum = getSum(l) + getSum(r) + 1L * sizeNotLC * val;
			size = getSize(l) + getSize(r) + sizeNotLC;
		}

		void push() {
			if (l != null) {
				l.applyDelta(delta);
			}
			if (r != null) {
				r.applyDelta(delta);
			}
			delta = 0;
		}
		
		void applyDelta(int delta) {
			lcaHere += 2L * delta * sizeNotLC;
			this.delta += delta;
		}

		static long getSum(Node v) {
			return v == null ? 0 : v.sum;
		}

		static int getSize(Node v) {
			return v == null ? 0 : v.size;
		}

		boolean isRoot() {
			return up == null || (up.l != this && up.r != this);
		}

		public Node(int val) {
			this.val = val;
			sizeNotLC = 1;
			lcaHere = 1;

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
			// TODO: return rest? might help to find lca and whatnot, see
			// http://codeforces.com/contest/482/submission/8750934
			for (Node rest = null; v != null; rest = v, v = v.up) {
				splay(v);
				if (v.r != null) {
					v.sizeNotLC += v.r.size;
				}
				if (rest != null) {
					v.sizeNotLC -= rest.size;
				}
				v.r = rest;
				v.update();
			}
		}

	}

	cf275E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new cf275E();
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

/*

5
1 2 2 1
1 2 3 4 5
4
P 3 4
P 4 5
P 5 2
P 1 4
 */