import java.io.*;
import java.util.*;
import java.util.stream.*;

import static java.lang.Math.max;

public class cfCEOI2019Day1B_noHLD {

	int time = 0;

	int[][] g;
	int[] lft, rgh;

	void dfs(int v, int p) {
		lft[v] = time++;
		for (int u : g[v]) {
			if (u != p) {
				dfs(u, v);
			}
		}
		rgh[v] = time++;
	}

	void submit() {
		int n = nextInt();
		int q = nextInt();
		long w = nextLong();
		int[] vs = new int[n - 1];
		int[] us = new int[n - 1];
		long[] ws = new long[n - 1];
		int[] all = new int[2 * n - 2];
		for (int i = 0; i < n - 1; i++) {
			vs[i] = nextInt() - 1;
			us[i] = nextInt() - 1;
			ws[i] = nextLong();
			all[2 * i] = vs[i];
			all[2 * i + 1] = us[i];
		}

		g = buildUGraph(all, n, n - 1);
		lft = new int[n];
		rgh = new int[n];
		dfs(0, -1);
		
		SegTree ds = new SegTree(2 * n - 1);
		for (int i = 0; i < n - 1; i++) {
			int v = vs[i];
			int u = us[i];
			if (lft[v] > lft[u]) {
				vs[i] = u;
				us[i] = v;
			}
			ds.addSegment(lft[us[i]], rgh[us[i]], ws[i]);
		}

		long last = 0;
		while (q-- > 0) {
			int edgeIdx = nextInt();
			long newW = nextLong();
			edgeIdx = (int) ((edgeIdx + last) % (n - 1));
			newW = (newW + last) % w;

			long oldW = ws[edgeIdx];
			long deltaW = newW - oldW;
			ws[edgeIdx] = newW;
			
			ds.addSegment(lft[us[edgeIdx]], rgh[us[edgeIdx]], deltaW);
			
			long ans = ds.getAns();

			out.println(ans);
			last = ans;
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

	// TODO: check with local parameters/without SegTree class at all?
	static class SegTree {
		Node root;
		int n;

		public SegTree(int n) {
			root = new Node(0, n);
			this.n = n;
		}

		public void addSegment(int ql, int qr, long delta) {
			if (ql == qr) {
				return;
			}
			if (ql > qr) {
				throw new AssertionError("ql > qr");
			}
			Node.ql = ql;
			Node.qr = qr;
			Node.delta = delta;
			root.add();
		}

		long getAns() {
			return root.getAll();
		}

		static class Node {
			static int ql, qr;
			static long delta;

			Node left, right;
			int l, r;
			long add;
			long side, mid, sideMid, midSide, all;

			long getSide() {
				return side + add;
			}

			long getMid() {
				return mid - 2 * add;
			}

			long getSideMid() {
				return sideMid - add;
			}

			long getMidSide() {
				return midSide - add;
			}

			long getAll() {
				return all;
			}

			public Node(int l, int r) {
				this.l = l;
				this.r = r;
				if (r - l > 1) {
					int m = (l + r) >> 1;
					left = new Node(l, m);
					right = new Node(m, r);
				}
			}

			void add() {
				if (l >= qr || ql >= r) {
					return;
				}
				if (ql <= l && r <= qr) {
					add += delta;
					return;
				}
				left.add();
				right.add();
				combine();
			}

			void combine() {
				long lSide = left.getSide();
				long lMid = left.getMid();
				long lSideMid = left.getSideMid();
				long lMidSide = left.getMidSide();

				long rSide = right.getSide();
				long rMid = right.getMid();
				long rSideMid = right.getSideMid();
				long rMidSide = right.getMidSide();

				side = max(lSide, rSide);
				mid = max(lMid, rMid);
				sideMid = max(max(lSideMid, rSideMid), lSide + rMid);
				midSide = max(max(lMidSide, rMidSide), lMid + rSide);
				all = max(max(max(left.getAll(), right.getAll()), lSideMid + rSide), lSide + rMidSide);
			}
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

	cfCEOI2019Day1B_noHLD() throws IOException {
		if (System.getProperty("ONLINE_JUDGE") == null) {
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
		new cfCEOI2019Day1B_noHLD();
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