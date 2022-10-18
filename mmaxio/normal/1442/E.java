import java.io.*;
import java.util.*;
import java.util.stream.*;

public class D {
	
	int dfs(int v, int p, int last, int val, int[] col, int[][] g) {
		if (col[v] != -1) {
			if (last == -1) {
				last = col[v];
				val = 1;
			} else if (last != col[v]) {
				last ^= 1;
				val++;
			}
		}
		int ret = val;
		for (int u : g[v]) {
			if (u == p) {
				continue;
			}
			ret = Math.max(ret, dfs(u, v, last, val, col, g));
		}
		return ret;
	}
	
	int[][] g;
	int[] col;
	
	int ans;
	
	static final int INF = Integer.MAX_VALUE / 4;
	
	int[] dfs(int v, int p) {
		int[] cur = {0, 0};
		int mid = col[v];
		for (int u : g[v]) {
			if (u == p) {
				continue;
			}
			int[] oth = dfs(u, v);
			if (mid == -1) {
				ans = Math.max(cur[0] + oth[1], ans);
				ans = Math.max(cur[1] + oth[0], ans);
			} else {
				ans = Math.max(cur[mid ^ 1] + oth[mid ^ 1] + 1, ans);
			}
			cur[0] = Math.max(cur[0], oth[0]);
			cur[1] = Math.max(cur[1], oth[1]);
		}
		if (mid != -1) {
			cur[mid] = Math.max(cur[mid ^ 1] + 1, cur[mid]);
		}
		return cur;
	}
	
	int fast(int[] es, int[] col) {
		int n = es.length / 2 + 1;
		g = buildUGraph(es, n, n - 1);
		this.col = col;
		
		ans = 0;
		dfs(0, -1);
		return ans /2 + 1;
	}
	
	int naive(int[] es, int[] col) {
		int n = es.length / 2 + 1;
		int[][] g = buildUGraph(es, n, n - 1);
		int ret = 1;
		for (int i = 0; i < n; i++) {
			ret = Math.max(ret, dfs(i, -1, -1, 0, col, g));
		}
		return ret / 2 + 1;
	}
	
	int brute(int[] es, int[] col) {
		int n = es.length / 2 + 1;
		int m0 = 0;
		int m1 = 0;
		for (int i = 0; i < n; i++) {
			if (col[i] == 0) {
				m0 |= 1 << i;
			} else if (col[i] == 1) {
				m1 |= 1 << i;
			}
		}
		
		boolean[] isConn = new boolean[1 << n];
		for (int i = 1; i < isConn.length; i++) {
			isConn[i] |= Integer.bitCount(i) == 1;
			if (!isConn[i]) {
				continue;
			}
			for (int j = 0; j < es.length; j += 2) {
				int v = es[j];
				int u = es[j + 1];
				if (test(i, v) != test(i, u)) {
					isConn[i | (1 << v) | (1 << u)] = true;
				}
			}
		}
		
		int[] dp = new int[1 << n];
		outer: for (int mask = 1; mask < dp.length; mask++) {
			if (!isConn[mask]) {
				for (int sub = mask;; sub = (sub - 1) & mask) {
					if (isConn[sub]) {
						dp[mask] = dp[sub] + dp[mask ^ sub];
						continue outer;
					}
				}
			}
			dp[mask] = Integer.MAX_VALUE / 2;
			for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
				boolean f0 = (sub & m0) != 0;
				boolean f1 = (sub & m1) != 0;
				if (f0 && f1) {
					continue;
				}
				dp[mask] = Math.min(dp[mask], 1 + dp[mask ^ sub]);
			}
		}
		return dp[(1 << n) - 1];
	}
	
	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	void submit() {
		int t = nextInt();
		while (t-- > 0) {
			int n = nextInt();
			int[] col = new int[n];
			for (int i = 0; i < n; i++) {
				col[i] = nextInt() - 1;
			}
			int[] es = new int[2 * n - 2];
			for (int i = 0; i < 2 * n - 2; i++) {
				es[i] = nextInt() - 1;
			}
//			out.println(naive(es, col));
//			out.println(brute(es, col));
			out.println(fast(es, col));
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
		int[] es = {1, 0};
		int[] col = {1, 0};
		System.err.println(fast(es, col));
	}
	
	static final int B = 100;

	void stress() {
		for (int tst = 0;; tst++) {
			int n = rand(1, B);
			int[] es = new int[2 * n - 2];
			for (int i = 1; i < n; i++) {
				es[2 * i - 2] = i;
				es[2 * i - 1] = rand(0, i - 1);
			}
			int[] col = new int[n];
			for (int i = 0; i < n; i++) {
				col[i] = rand(-1, 1);
			}
			int naive = naive(es, col);
//			int brute = brute(es, col);
			int brute = naive;
			int fast = fast(es, col);
			if (naive != brute || naive != fast || fast != brute) {
				System.err.println(Arrays.toString(es));
				System.err.println(Arrays.toString(col));
				System.err.println("naive " + naive);
				System.err.println("brute " + brute);
				System.err.println("fast " + fast);
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	D() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		submit();
//		 stress();
//		 test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 5;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new D();
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