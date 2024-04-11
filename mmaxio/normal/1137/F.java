import java.io.*;
import java.math.*;
import java.util.*;

public class cf545F {

	int[][] g;

	Node1[] nodesLC;

	void splay(Node1 v) {
		if (v.isRoot()) {
			v.push();
			return;
		}

		do {
			Node1 u = v.up;
			Node1 t = u.up;
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

	int get(int idx) {
		Node1 v = nodesLC[idx];
		splay(v);

		return fenGet(v.path - 1) + Node1.getSize(v.r);
	}

	void makeRoot(Node1 v) {
		Node1 initV = v;
		Node1 rest = null;
		for (; v != null; rest = v, v = v.up) {
			splay(v);

			fenAdd(v.path, Node1.getSize(v.r) - v.size);

			v.r = rest;
			v.update();
		}

		splay(initV);
		initV.rev ^= true;
		fenAdd(fenPtr, Node1.getSize(initV));
		initV.path = fenPtr;

		fenPtr++;
	}

	int[] fen;
	int fenPtr;

	void fenAdd(int pos, int delta) {
		for (int i = pos; i < fen.length; i |= i + 1) {
			fen[i] += delta;
		}
	}

	int fenGet(int pos) {
		int ret = 0;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
			ret += fen[i];
		}
		return ret;
	}

	void submit() {
		int n = nextInt();
		int q = nextInt();
		int[] a = new int[2 * n - 2];
		for (int i = 0; i < 2 * n - 2; i++) {
			a[i] = nextInt() - 1;
		}

		g = buildUGraph(a, n, n - 1);

		fen = new int[n + q];
		for (int i = 0; i < n; i++) {
			fenAdd(i, 1);
		}
		fenPtr = n;
		
		getOrder(g);

		while (q-- > 0) {
			String type = nextToken();
			int v = nextInt() - 1;
			if (type.equals("up")) {
				Node1 next = nodesLC[v];
				makeRoot(next);
			} else if (type.equals("when")) {
				out.println(get(v) + 1);
			} else if (type.equals("compare")) {
				int u = nextInt() - 1;
				if (get(v) < get(u)) {
					out.println(v + 1);
				} else {
					out.println(u + 1);
				}
			}
		}
	}

	// we also build initial link/cut tree here since we have parents
	int[] getOrder(int[][] g) {
		int n = g.length;
		if (n == 1) {
			int[] ret = { 0 };
			nodesLC = new Node1[n];
			for (int i = 0; i < n; i++) {
				nodesLC[i] = new Node1();
			}
			return ret;
		}
		int[] deg = new int[n];
		for (int i = 0; i < n; i++) {
			deg[i] = g[i].length;
		}

		int[] q = new int[n];
		int[] par = new int[n];
		par[n - 1] = n - 1;
		int qh = 0, qt = 0;
		q[qt++] = n - 1;

		while (qh < qt) {
			int v = q[qh++];
			for (int u : g[v]) {
				if (u != par[v]) {
					par[u] = v;
					q[qt++] = u;
				}
			}
		}

		int[] ret = new int[n];
		int ptr = n;

		PriorityQueue<Integer> pq = new PriorityQueue<>();

		for (int i = 0; i < n; i++) {
			if (deg[i] == 1) {
				pq.add(i);
			}
		}

		while (ptr > 0) {
			int v = pq.poll();
			ret[--ptr] = v;
			deg[par[v]]--;
			if (deg[par[v]] == 1) {
				pq.add(par[v]);
			}
		}

		nodesLC = new Node1[n];
		for (int i = 0; i < n; i++) {
			nodesLC[i] = new Node1();
		}

		for (int i = 0; i < n; i++) {
			nodesLC[ret[i]].path = n - 1 - i;
		}

		for (int i = 0; i < n - 1; i++) {
			nodesLC[i].up = nodesLC[par[i]];
		}

		return ret;
	}

	int[][] buildUGraph(int[] a, int n, int m) {
		if (m == 0) {
			if (a.length == 0) {
				return new int[n][0];
			} else {
				throw new AssertionError();
			}
		}
		if (a.length % m != 0 || a.length < 2 * m) {
			throw new AssertionError("Bad array length");
		}

		int[] deg = new int[n];
		int s = a.length / m;
		for (int i = 0; i < a.length; i += s) {
			deg[a[i]]++;
			deg[a[i + 1]]++;
		}

		int[][] g = new int[n][];
		for (int i = 0; i < n; i++) {
			g[i] = new int[deg[i] * (s - 1)];
		}

		for (int i = s * (m - 1); i >= 0; i -= s) {
			int v = a[i];
			int u = a[i + 1];
			int pv = (--deg[v]) * (s - 1);
			g[v][pv] = u;
			System.arraycopy(a, i + 2, g[v], pv + 1, s - 2);

			int pu = (--deg[u]) * (s - 1);
			g[u][pu] = v;
			System.arraycopy(a, i + 2, g[u], pu + 1, s - 2);
		}

		return g;
	}

	static class Node1 {

		int path = -1;

		Node1 l, r, up;

		int size;
		boolean rev;

		void update() {
			size = 1 + getSize(l) + getSize(r);
		}

		void push() {
			if (rev) {
				rev = false;
				Node1 tmp = l;
				l = r;
				r = tmp;
				if (l != null) {
					l.rev ^= true;
				}
				if (r != null) {
					r.rev ^= true;
				}
			}
			if (path != -1) {
				if (l != null) {
					l.path = path;
				}
				if (r != null) {
					r.path = path;
				}
			}
		}

		boolean isRoot() {
			return up == null || (up.l != this && up.r != this);
		}

		static int getSize(Node1 v) {
			return v == null ? 0 : v.size;
		}

		public Node1() {
			update();
		}

		static private void relink(Node1 v, Node1 u) {
			Node1 t = u.up;
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
			Node1 u = up;

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

	void test() {

	}

	void stress() {
		for (int tst = 0;; tst++) {
			if (false) {
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	cf545F() throws IOException {
		// if (System.getProperty("ONLINE_JUDGE") != null) {
		is = System.in;
		// } else {
		// is = new FileInputStream("in.txt");
		// }
		out = new PrintWriter(System.out);
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 5;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new cf545F();
	}

	private InputStream is;
	PrintWriter out;

	private byte[] buf = new byte[1 << 14];
	private int bufSz = 0, bufPtr = 0;

	private int readByte() {
		if (bufSz == -1)
			throw new RuntimeException("Reading past EOF");
		if (bufPtr >= bufSz) {
			bufPtr = 0;
			try {
				bufSz = is.read(buf);
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			if (bufSz <= 0)
				return -1;
		}
		return buf[bufPtr++];
	}

	private boolean isTrash(int c) {
		return c < 33 || c > 126;
	}

	private int skip() {
		int b;
		while ((b = readByte()) != -1 && isTrash(b))
			;
		return b;
	}

	String nextToken() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	String nextString() {
		int b = readByte();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b) || b == ' ') {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	char nextChar() {
		return (char) skip();
	}

	int nextInt() {
		int ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}

	long nextLong() {
		long ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}
}