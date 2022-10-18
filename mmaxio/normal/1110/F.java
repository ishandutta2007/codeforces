import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class F {

	int[] par;
	int[] wgh;

	int[] low, high;
	int[] leaves;
	int lSz = 0;

	int[][] g;

	long[] depth;

	void dfs(int v) {
		if (g[v].length == 0) {
			leaves[lSz] = v;
			low[v] = high[v] = lSz;
			lSz++;
			return;
		}
		for (int u : g[v]) {
			depth[u] = depth[v] + wgh[u];
			dfs(u);
		}
		low[v] = low[g[v][0]];
		high[v] = high[g[v][g[v].length - 1]];
	}

	static final long INF = Long.MAX_VALUE / 3;

	static class Node {
		int l, r;
		Node left, right;

		long min;
		long add;

		public Node(int l, int r, long[] a) {
			this.l = l;
			this.r = r;
			if (r - l > 1) {
				int m = (l + r) >> 1;
				left = new Node(l, m, a);
				right = new Node(m, r, a);
				min = Math.min(left.min, right.min);
			} else {
				min = a[l];
			}
		}

		long getMin() {
			return min + add;
		}

		long get(int ql, int qr) {
			if (l >= qr || ql >= r) {
				return INF;
			}
			if (ql <= l && r <= qr) {
				return getMin();
			}
			return Math.min(left.get(ql, qr), right.get(ql, qr)) + add;
		}

		void add(int ql, int qr, long delta) {
			if (l >= qr || ql >= r) {
				return;
			}
			if (ql <= l && r <= qr) {
				add += delta;
				return;
			}
			left.add(ql, qr, delta);
			right.add(ql, qr, delta);
			min = Math.min(left.getMin(), right.getMin());
		}

	}

	void submit() {
		int n = nextInt();
		int qq = nextInt();

		par = new int[n];
		wgh = new int[n];
		int[] deg = new int[n];
		for (int i = 1; i < n; i++) {
			par[i] = nextInt() - 1;
			deg[par[i]]++;
			wgh[i] = nextInt();
		}

		g = new int[n][];
		for (int i = 0; i < n; i++) {
			g[i] = new int[deg[i]];
			deg[i] = 0;
		}

		for (int i = 1; i < n; i++) {
			int v = par[i];
			g[v][deg[v]++] = i;
		}

		low = new int[n];
		high = new int[n];
		leaves = new int[n];
		depth = new long[n];

		dfs(0);

		leaves = Arrays.copyOf(leaves, lSz);

		long[] leavesDepth = new long[lSz];
		for (int i = 0; i < lSz; i++) {
			leavesDepth[i] = depth[leaves[i]];
		}

		root = new Node(0, lSz, leavesDepth);

		Query[] qs = new Query[qq];
		for (int i = 0; i < qq; i++) {
			int v = nextInt() - 1;
			int l = nextInt() - 1;
			int r = nextInt() - 1;
			l = Arrays.binarySearch(leaves, l);
			if (l < 0) {
				l = -l - 1;
			}
			r = Arrays.binarySearch(leaves, r);
			if (r < 0) {
				r = -r - 2;
			}
			r++;
			qs[i] = new Query(v, l, r, i);
		}

		Arrays.sort(qs);
		nowV = 0;

		ptr = new int[n];

		long[] outp = new long[qq];
		
		for (Query q : qs) {
			while (nowV < q.v) {
				moveV();
			}
			outp[q.idx] = depth[q.v] + root.get(q.l, q.r);
			
//			System.err.println("!!!");
//			System.err.println(root.get(0, 1));
//			System.err.println(root.get(1, 2));
//			System.err.println(root.get(2, 3));
			
		}

		for (long x : outp) {
			out.println(x);
		}
	}

	void moveV() {
		while (true) {
			if (ptr[nowV] < g[nowV].length) {
				int newNowV = g[nowV][ptr[nowV]];
				ptr[nowV]++;
				moveDown(newNowV);
				break;
			}
			moveUp();
		}
	}

	void moveDown(int to) {
		nowV = to;
//		System.err.println(low[to] + " " + high[to] + " " + -2 * wgh[to]);
		root.add(low[to], high[to] + 1, -2 * wgh[to]);
	}

	void moveUp() {
//		System.err.println(low[nowV] + " " + high[nowV] + " " + 2 * wgh[nowV]);
		root.add(low[nowV], high[nowV] + 1, 2 * wgh[nowV]);
		nowV = par[nowV];
	}

	int nowV;
	int[] ptr;
	Node root;

	static class Query implements Comparable<Query> {
		int v, l, r, idx;

		public Query(int v, int l, int r, int idx) {
			this.v = v;
			this.l = l;
			this.r = r;
			this.idx = idx;
		}

		@Override
		public int compareTo(Query o) {
			return Integer.compare(v, o.v);
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

	F() throws IOException {
		is = System.in;
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
		new F();
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