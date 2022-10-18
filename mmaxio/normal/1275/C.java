import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class _507E {
	static final int C = 60;
	static final int MAX = 1_000_000_000;

	static class Pair implements Comparable<Pair> {
		int x, y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Pair o) {
			return Integer.compare(x, o.x);
		}
	}

	void advanceFrom(int pos) {
		int curTo = toFrom[pos];
		maxFrom[pos] = Math.max(maxFrom[pos], arr[curTo]);
		minFrom[pos] = Math.min(minFrom[pos], arr[curTo]);
		splay.cut(pos);
		while (++curTo < n && curTo < pos + C) {
			if (arr[curTo] > maxFrom[pos] || arr[curTo] < minFrom[pos]) {
				break;
			}
		}
		if (curTo < n && curTo < pos + C) {
			splay.link(pos, curTo);
		}
		toFrom[pos] = curTo;
	}

	SplayHolder splay;

	static class SplayHolder {

		// interface
		public SplayHolder(int n) {
			nodes = new Node[n];
			for (int i = 0; i < n; i++) {
				nodes[i] = new Node(i);
			}
			for (int i = 0; i < n - 1; i++) {
				nodes[i].up = nodes[i + 1];
			}
		}

		/**
		 * v must not be root
		 */
		public void cut(int v) {
			Node nv = nodes[v];
			LinkCut.expose(nv);
			LinkCut.splay(nv);
			// nv.l == null means v was a root before
			nv.l.up = nv.up;
			nv.l = null;
			nv.update();
		}

		/**
		 * v must be root <br/>
		 * u obviously should not be in v's tree
		 */
		public void link(int v, int u) {
			// no need to expose since v is root and hence
			// already belongs to a "root path"

			// if called immediately after cut(v)
			// splaying is also not needed here since
			// v ends up being the splay-tree-root of
			// "root path" after cut(v)
			// but splay works very fast in this case
			// anyways
			LinkCut.splay(nodes[v]);
			nodes[v].up = nodes[u];
		}

		public Node getRootAndSplay(int v) {
			Node nu = LinkCut.expose(nodes[v]);
			while (nu.l != null) {
				nu = nu.l;
			}
			LinkCut.splay(nu);
			return nu;
		}

		// implementation
		Node[] nodes;

		static class Node {
			Node l, r, up;

			/**
			 * this is just the splay tree size, ignoring all the LinkCut magic
			 */
			int size;
			int id;

			void update() {
				size = 1 + getSize(l) + getSize(r);
			}

			boolean isRoot() {
				return up == null || (up.l != this && up.r != this);
			}

			static int getSize(Node v) {
				return v == null ? 0 : v.size;
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

		static class LinkCut {

			public static void splay(Node v) {
				while (!v.isRoot()) {
					Node u = v.up;
					Node t = u.up;
					if (!u.isRoot()) {
						((t.l == u) == (u.l == v) ? u : v).rotate();
					}
					v.rotate();
				}
				v.update();
			}

			public static Node expose(Node v) {
				Node rest = null;
				for (; v != null; rest = v, v = v.up) {
					splay(v);
					v.r = rest;
					v.update();
				}
				return rest;
			}
		}
	}

	int go(int bound) {
		int ret = 0;
		int v = 0;

		while (v < n) {
			SplayHolder.Node jumpTo = splay.getRootAndSplay(v);
			ret += jumpTo.size - 1;
			v = jumpTo.id;

			if (v == n - 1) {
				break;
			}
			
			if (toFrom[v] == n) {
				break;
			}

			v = jump(v, bound);
			if (v == n) {
				break;
			}
			ret++;
		}

		return ret;
	}

	int jump(int v, int bound) {
		int u = toFrom[v];
		for (int i = log(n - toFrom[v]); i >= 0; i--) {
			if (u + (1 << i) > n) {
				continue;
			}
			int newMin = Math.min(minFrom[v], sp[i][2 * u]);
			int newMax = Math.max(maxFrom[v], sp[i][2 * u + 1]);
			if (newMax - newMin < bound) { // < or <= ???
				u += 1 << i;
				minFrom[v] = newMin;
				maxFrom[v] = newMax;
			}
		}
		return u;
	}

	int log(int x) {
		return 31 - Integer.numberOfLeadingZeros(x);
	}

	int[][] sp;

	void prepareJumps() {
		int len = arr.length;
		int n = log(len);
		sp = new int[n + 1][];
		sp[0] = new int[2 * len];
		for (int i = 0; i < len; i++) {
			sp[0][2 * i] = sp[0][2 * i + 1] = arr[i];
		}
		for (int i = 1; i <= n; i++) {
			sp[i] = new int[2 * (len - (1 << i) + 1)];
			for (int j = 0, k = 1 << (i - 1); j < sp[i].length / 2; j++, k++) {
				sp[i][2 * j] = Math.min(sp[i - 1][2 * j], sp[i - 1][2 * k]);
				sp[i][2 * j + 1] = Math.max(sp[i - 1][2 * j + 1], sp[i - 1][2 * k + 1]);
			}
		}
	}

	int n;

	int[] minFrom, maxFrom, toFrom;
	int[] arr;

	void submit() {
		n = nextInt();
		int w = nextInt();
		int q = nextInt();

		arr = new int[n];
		int badN = 0;
		for (int i = 0; i < n; i++) {
			int tmp = nextInt();
			if (badN == 0 || tmp != arr[badN - 1]) {
				arr[badN++] = tmp;
			}
		}
		n = badN;
		arr = Arrays.copyOf(arr, badN);

		Pair[] qs = new Pair[q];
		for (int i = 0; i < q; i++) {
			qs[i] = new Pair(w - nextInt() + 1, i);
		}

		Pair[] chgs = new Pair[n * C];
		int cPtr = 0;
		for (int i = 0; i < n; i++) {
			int min = arr[i];
			int max = arr[i];
			int diff = max - min;
			for (int j = i + 1; j < i + C && j < n; j++) {
				min = Math.min(min, arr[j]);
				max = Math.max(max, arr[j]);
				int nDiff = max - min;
				if (nDiff != diff) {
					chgs[cPtr++] = new Pair(nDiff, i);
					diff = nDiff;
				}
			}
		}
		
		prepareJumps();

		chgs = Arrays.copyOf(chgs, cPtr);
		cPtr = 0;

		Arrays.sort(chgs);
		Arrays.sort(qs);

		minFrom = new int[n];
		maxFrom = new int[n];
		toFrom = new int[n];

		for (int i = 0; i < n; i++) {
			toFrom[i] = i + 1;
			minFrom[i] = maxFrom[i] = arr[i];
		}

		int[] ans = new int[q];

		splay = new SplayHolder(n);

		for (Pair qry : qs) {
			int val = qry.x;
			while (cPtr < chgs.length && chgs[cPtr].x < val) {
				advanceFrom(chgs[cPtr].y);
				cPtr++;
			}
			ans[qry.y] = go(qry.x);
		}
		for (int x : ans) {
			out.println(x);
		}
	}

	_507E() throws IOException {
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

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new _507E();
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
}