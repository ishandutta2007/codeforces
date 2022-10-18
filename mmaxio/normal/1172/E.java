import java.io.*;
import java.math.*;
import java.util.*;
import java.util.function.Consumer;
import java.util.function.IntConsumer;
import java.util.function.IntFunction;
import java.util.stream.*;

public class cf564E_lazy {

	/**
	 * For subtree-aggregates, you need 2 values for each node: <br>
	 * 
	 * 1) subtree(v) = {v} + subtree(l/r) + dashed(v) <br>
	 * 2) dashed(v) = sum over {u: LCtree children u of v WITHOUT the "solid edge"
	 * child}
	 */
	static class Node {
		Node l, r, up;

		int subSz;
		int dSubSz;
		long dSubSz2;
		
		boolean rev = false;

		private static boolean banCtor = false;
		static final Node NULL = new Node();

		private Node() {
			if (banCtor) {
				throw new AssertionError("Use static newNode()");
			}
			banCtor = true;
		}

		static Node newNode() {
			banCtor = false;
			Node v = new Node();
			v.l = v.r = v.up = NULL;
			v.update();
			return v;
		}

		void update() {
			subSz = 1 + dSubSz + l.subSz + r.subSz;
		}

		boolean isRoot() {
			return up == NULL || (up.l != this && up.r != this);
		}

		/**
		 * "this" is guaranteed to not be a splay tree root. <br>
		 * 
		 * For optimization reasons doesn't update info for "this". <br>
		 * 
		 * Because of that, "this" and "p"(second rotation during zig-zig) info might be
		 * outdated.
		 */
		private void rotate() {
			Node p = up;
			Node pp = p.up;

			if (p.l == this) {
				// p.setLeft(this.r)
				p.l = r;
				r.up = p;

				// this.setRight(p)
				r = p;
				// p.up = this
			} else {
				// p.setRight(this.l)
				p.r = l;
				l.up = p;

				// this.setLeft(p)
				l = p;
				// p.up = this
			}
			p.up = this;
			p.update();

			// pp could be either
			// 1) p's splay parent
			// 2) p's LC(but not splay!) parent
			// 3) NULL
			// Because of 2) we have to use "else if"
			if (pp.l == p) {
				pp.l = this;
			} else if (pp.r == p) {
				pp.r = this;
			}
			up = pp;
		}

		public void changeSolidRightTo(Node newR) {
			int x = r.subSz;
			int y = newR.subSz;
			dSubSz += x - y;
			dSubSz2 += (long) x * x - (long) y * y;
			r = newR;
			update();
		}
	}

	static final Node NULL = Node.NULL;

	static class LinkCut {

		public static void splay(Node v) {
			internalSplay(v, true);
		}

		private static void internalSplay(Node v, boolean updateAtTheEnd) {
			if (v.isRoot()) {
				return;
			}
			do {
				Node p = v.up;
				Node pp = p.up;
				if (!p.isRoot()) {
					((pp.l == p) == (p.l == v) ? p : v).rotate();
				}
				v.rotate();
			} while (!v.isRoot());
			if (updateAtTheEnd) {
				v.update();
			}
		}

		public static Node expose(Node v) {
			Node rest = NULL;
			for (; v != NULL; rest = v, v = v.up) {
				internalSplay(v, false);
				v.changeSolidRightTo(rest);
			}
			return rest;
		}

	}

	void submit() {
		int n = nextInt();
		int qq = nextInt();
		int[] colors = new int[n];
		for (int i = 0; i < n; i++) {
			colors[i] = nextInt() - 1;
		}

		int[] es = new int[2 * n - 2];

		for (int i = 0; i < n - 1; i++) {
			es[2 * i] = nextInt() - 1;
			es[2 * i + 1] = nextInt() - 1;
		}

		int[][] g = buildUGraph(es, n, n - 1);
		int[] par = new int[n];
		par[0] = n;
		int[] stack = new int[n];
		int ptr = 0;
		stack[ptr++] = 0;

		while (ptr > 0) {
			int v = stack[--ptr];
			for (int u : g[v]) {
				if (par[v] == u) {
					continue;
				}
				par[u] = v;
				stack[ptr++] = u;
			}
		}

		Node[] a = new Node[n + 1];
		for (int i = 0; i < n + 1; i++) {
			a[i] = Node.newNode();
		}

		IntFunction<Long> turnOn = (int idx) -> {
			Node c = a[idx];
			Node p = a[par[idx]];
			LinkCut.splay(c);
			int linkedSon = c.r.subSz;
			long delta = -c.dSubSz2 - (long)linkedSon * linkedSon;
			int sumBelow = c.dSubSz + linkedSon;

			LinkCut.expose(p);
			LinkCut.splay(p);

			c.up = p;

			p.dSubSz += c.subSz;
			p.dSubSz2 += (long) c.subSz * c.subSz;
			p.update();

			// ugly stuff below :(
			// we need to find the second node on root to "p" path
			int newSize;
			if (p.l == NULL) {
				newSize = c.subSz;
			} else {
				Node root = p;
				while (root.l != NULL) {
					root = root.l;
				}
				LinkCut.splay(root);
				newSize = root.r.subSz;
			}
			int upSize = newSize - 1 - sumBelow;
			delta += (long) newSize * newSize - (long) upSize * upSize;
			return delta;
		};

		IntFunction<Long> turnOff = (int idx) -> {
			Node c = a[idx];

			// first find out what was our size
			Node root = LinkCut.expose(c); // not really root yet!
			while (root.l != NULL) {
				root = root.l;
			}
			LinkCut.splay(root);
			int oldSize = root.r.subSz;
			long delta = -(long) oldSize * oldSize;
			LinkCut.splay(c);

			c.l.up = c.up;
			c.l = NULL;
			c.update();

			delta += c.dSubSz2;
			int oldSizeUp = oldSize - 1 - c.dSubSz;
			delta += (long) oldSizeUp * oldSizeUp;
			return delta;
		};

		long[] deltas = new long[qq + 2];
		for (int i = 0; i < n; i++) {
			turnOn.apply(i);
		}

		ArrayList<Query> qs = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			qs.add(new Query(i, 0, colors[i], turnOff));
		}

		for (int i = 0; i < qq; i++) {
			int node = nextInt() - 1;
			int newColor = nextInt() - 1;
			if (colors[node] == newColor) {
				continue;
			}
			qs.add(new Query(node, i + 1, colors[node], turnOn));
			colors[node] = newColor;
			qs.add(new Query(node, i + 1, colors[node], turnOff));
		}

		for (int i = 0; i < n; i++) {
			qs.add(new Query(i, qq + 1, colors[i], turnOn));
		}

		Collections.sort(qs);

		for (Query q : qs) {
			// System.err.println(q.node + " " + q.time + " " + tmp);
			deltas[q.time] -= q.action.apply(q.node);
		}

		for (int i = 0; i <= qq; i++) {
			if (i > 0) {
				deltas[i] += deltas[i - 1];
			}
		}

		for (int i = 0; i <= qq; i++) {
			out.println(deltas[i]);
		}
	}

	static class Query implements Comparable<Query> {
		int node;
		int time;
		int color;
		IntFunction<Long> action;

		public Query(int node, int time, int color, IntFunction<Long> action) {
			this.node = node;
			this.time = time;
			this.color = color;
			this.action = action;
		}

		@Override
		public int compareTo(Query o) {
			if (color != o.color) {
				return color < o.color ? -1 : 1;
			}
			return Integer.compare(time, o.time);
		}
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

	cf564E_lazy() throws IOException {
		if (!"true".equals(System.getProperty("ONLINE_JUDGE"))) {
			is = new FileInputStream("in.txt");
		} else {
			is = System.in;
		}
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
		new cf564E_lazy();
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