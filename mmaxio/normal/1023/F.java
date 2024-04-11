import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class F {

	int[] p;
	int[] rank;

	int get(int v) {
		return p[v] == v ? v : (p[v] = get(p[v]));
	}

	boolean unite(int v, int u) {
		v = get(v);
		u = get(u);
		if (v == u) {
			return false;
		}
		if (rank[v] < rank[u]) {
			int tmp = v;
			v = u;
			u = tmp;
		}
		if (rank[v] == rank[u]) {
			rank[v]++;
		}
		p[u] = v;
		return true;
	}

	int[] order;
	
	int oPtr = 0;
	
	void submit() {
		int n = nextInt();
		k = nextInt();
		int m = nextInt();

		p = IntStream.range(0, n).toArray();
		rank = new int[n];

		int[] vs = new int[n - 1];
		int[] us = new int[n - 1];

		for (int i = 0; i < k; i++) {
			vs[i] = nextInt() - 1;
			us[i] = nextInt() - 1;
			unite(vs[i], us[i]);
		}

		int ptr = k;

		Edge[] es = new Edge[m];
		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			int cost = nextInt();
			es[i] = new Edge(v, u, cost);
		}

		Arrays.sort(es);

		for (Edge e : es) {
			if (unite(e.v, e.u)) {
				vs[ptr] = e.v;
				us[ptr] = e.u;
				ptr++;
				e.tree = true;
			}
		}

		next = new int[2 * n - 2];
		to = new int[2 * n - 2];
		head = new int[n];

		Arrays.fill(head, -1);

		for (int i = 0; i < n - 1; i++) {
			to[2 * i] = us[i];
			next[2 * i] = head[vs[i]];
			head[vs[i]] = 2 * i;

			to[2 * i + 1] = vs[i];
			next[2 * i + 1] = head[us[i]];
			head[us[i]] = 2 * i + 1;
		}

		tIn = new int[n];
		tOut = new int[n];
		up = new int[LOG][n];
		max = new int[LOG][n];
		for (int i = 0; i < LOG; i++) {
			Arrays.fill(max[i], INF);
		}
		parEdge = new int[n];
		Arrays.fill(parEdge, -1);
		
		order = new int[n];
		
		dfs(0, 0);

		for (Edge e : es) {
			if (!e.tree) {
				int v = e.v;
				int u = e.u;
				int t = lca(v, u);
				
				mark(v, t, e.cost);
				mark(u, t, e.cost);
			}
		}
		
		ans = 0;
		isInf = false;
		
		for (int zzz = n - 1; zzz >= 0; zzz--) {
			int v = order[zzz];
			
			for (int i = LOG - 1; i > 0; i--) {
				int val = max[i][v];
				int whoUp = up[i - 1][v];
				int[] max1 = max[i - 1];
				max1[v] = Math.min(max1[v], val);
				max1[whoUp] = Math.min(max1[whoUp], val);
			}
			
			int pe = parEdge[v];
			if (pe != -1 && pe < k) {
				if (max[0][v] == INF) {
					isInf = true;
				} else {
					ans += max[0][v];
				}
			}
			
		}

		if (isInf) {
			out.println(-1);
		} else {
			out.println(ans);
		}
	}

	int k;
	
	void dfs2(int v, int p) {

		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			if (u == p) {
				continue;
			}
			dfs2(u, v);
		}
		
		
	}

	long ans;
	boolean isInf;

	static final int LOG = 19;
	static final int INF = Integer.MAX_VALUE;

	int time = 0;
	int[] tIn, tOut;
	int[][] up;
	int[][] max;

	int[] parEdge;

//	boolean isAnc(int v, int u) {
//		return tIn[v] <= tIn[u] && tOut[u] <= tOut[v];
//	}

	void mark(int from, int to, int what) {
		for (int i = LOG - 1; i >= 0; i--) {
			if (from == 0) {
				return;
			}
			int next = up[i][from];
			if (next == to || !(tIn[next] <= tIn[to] && tOut[to] <= tOut[next])) {
				int[] maxI = max[i];
				maxI[from] = Math.min(maxI[from], what);
				from = next;
			}
		}
	}

	int lca(int v, int u) {
		if (tIn[v] <= tIn[u] && tOut[u] <= tOut[v]) {
			return v;
		}
		if (tIn[u] <= tIn[v] && tOut[v] <= tOut[u]) {
			return u;
		}
		for (int i = LOG - 1; i >= 0; i--) {
			int next = up[i][u];
			if (!(tIn[next] <= tIn[v] && tOut[v] <= tOut[next])) {
				u = next;
			}
		}
		return up[0][u];
	}

	void dfs(int v, int p) {

		order[oPtr++] = v;
		
		up[0][v] = p;
		for (int i = 1; i < LOG; i++) {
			up[i][v] = up[i - 1][up[i - 1][v]];
		}

		tIn[v] = time++;
		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			if (u == p) {
				continue;
			}
			parEdge[u] = e / 2;
			dfs(u, v);
		}
		tOut[v] = time++;
	}

	int[] next;
	int[] to;
	int[] head;

	static class Edge implements Comparable<Edge> {
		int v, u, cost;
		boolean tree;

		public Edge(int v, int u, int cost) {
			this.v = v;
			this.u = u;
			this.cost = cost;
		}

		@Override
		public int compareTo(Edge o) {
			return Integer.compare(cost, o.cost);
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