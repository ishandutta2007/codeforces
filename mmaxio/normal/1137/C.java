import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class C {

	int[][] g;
	int[][] gr;

	int[] mark;

	void submit() {
		int n = nextInt();
		int m = nextInt();

		int d = nextInt();
		int[] deg = new int[n];
		int[] degr = new int[n];

		int[] a = new int[2 * m];

		for (int i = 0; i < m; i++) {
			a[2 * i] = nextInt() - 1;
			a[2 * i + 1] = nextInt() - 1;
			deg[a[2 * i]]++;
			degr[a[2 * i + 1]]++;
		}

		g = new int[n][];
		gr = new int[n][];
		mark = new int[n];

		for (int i = 0; i < n; i++) {
			g[i] = new int[deg[i]];
			gr[i] = new int[degr[i]];
		}

		Arrays.fill(deg, 0);
		Arrays.fill(degr, 0);

		for (int i = 0; i < 2 * m; i += 2) {
			int v = a[i];
			int u = a[i + 1];
			g[v][deg[v]++] = u;
			gr[u][degr[u]++] = v;
		}

		Arrays.fill(mark, -1);
		dfs0(0, 0);

		ptr = n;
		comp = new int[n];
		order = new int[n];
		compSz = new int[n];

		for (int i = 0; i < n; i++) {
			if (comp[i] == 0) {
				dfs1(i);
			}
		}
		ptr = 0;
		for (int v : order) {
			if (comp[v] == -1) {
				dfs2(v);
				ptr++;
			}
		}

		// System.err.println(Arrays.toString(comp));
		// System.err.println(Arrays.toString(compSz));

		int[] pers = new int[ptr];
		Arrays.fill(pers, d);

		for (int v = 0; v < n; v++) {
			for (int u : g[v]) {
				if (comp[v] != comp[u]) {
					continue;
				}
				int delta = Math.abs(mark[v] + 1 - mark[u]);
				pers[comp[v]] = gcd(pers[comp[v]], delta);
			}
		}

		int[][] who = new int[ptr][];
		for (int i = 0; i < ptr; i++) {
			who[i] = new int[compSz[i]];
		}

		for (int i = 0; i < n; i++) {
			int idx = comp[i];
			who[idx][--compSz[idx]] = i;
		}
		
		makeZeroFirst(who[comp[0]]);

		int[][] dp = new int[ptr][d];

		int[][] sch = new int[n][d];
		for (int i = 0; i < n; i++) {
			String s = nextToken();

			for (int j = 0; j < d; j++) {
				sch[i][j] = s.charAt(j) - '0';
			}
		}

		int[] shifts = new int[n];

		for (int v = 0; v < n; v++) {
			int shift = (mark[v] - mark[who[comp[v]][0]]) % pers[comp[v]];
			if (shift < 0) {
				shift += pers[comp[v]];
			}
			shifts[v] = shift;
		}

		for (int i = ptr - 1; i >= 0; i--) {
			int[] vs = who[i];
			int per = pers[i];

			int[] profit = new int[per];

			for (int v : vs) {
				int shift = shifts[v];

//				for (int j = 0; j < d; j++) {
//					if (sch[v][j] == 0) {
//						continue;
//					}
//					int idx = j % per;
//					idx -= shift;
//					if (idx < 0) {
//						idx += per;
//					}
//
//					profit[idx]++;
//				}
				
				for (int idx = 0; idx < per; idx++) {
					int j = (idx + shift) % per;
					int val = 0;
					for (int k = j; k < d; k += per) {
						val |= sch[v][k];
					}
					profit[idx] += val;
				}
			}

			int[] dpRow = dp[i];
			for (int j = 0; j < d; j++) {
				dpRow[j] = profit[j % per];
			}

			for (int v : vs) {
				int shift = shifts[v];

				for (int u : g[v]) {
					if (comp[u] == comp[v]) {
						continue;
					}
					if (comp[u] < comp[v]) {
						throw new AssertionError();
					}

					for (int j = 0; j < d; j++) {
						
						for (int z = 0; z < d / per; z++) {
						
						int jj = (j + shift + z * per + 1 - shifts[u]) % d;
						if (jj < 0) {
							jj += d;
						}
						
						dpRow[j] = Math.max(dpRow[j], profit[j % per]
								+ dp[comp[u]][jj]);
						}
					}
				}
			}
			
//			System.err.println(Arrays.toString(who[i]) + " " + Arrays.toString(dp[i]));
		}
		
		out.println(dp[comp[0]][0]);
	}
	
	void makeZeroFirst(int[] a) {
		int idx = 0;
		while (a[idx] != 0) {
			idx++;
		}
		a[idx] = a[0];
		a[0] = 0;
	}

	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	int[] order;
	int ptr;
	int[] comp;
	int[] compSz;

	void dfs1(int v) {
		comp[v] = -1;
		for (int u : g[v]) {
			if (comp[u] == 0) {
				dfs1(u);
			}
		}
		order[--ptr] = v;
	}

	void dfs2(int v) {
		comp[v] = ptr;
		compSz[ptr]++;
		for (int u : gr[v]) {
			if (comp[u] == -1) {
				dfs2(u);
			}
		}
	}

	void dfs0(int v, int c) {
		mark[v] = c;
		for (int u : g[v]) {
			if (mark[u] == -1) {
				dfs0(u, c + 1);
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

	C() throws IOException {
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
		new C();
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