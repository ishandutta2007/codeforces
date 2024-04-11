import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class D {

	int[][] g;
	int n;
	
	void submit() {
		n = nextInt();
		g = new int[n][];
		int[] deg = new int[n];
		
		int[] vs = new int[n - 1];
		int[] us = new int[n - 1];
		
		for (int i = 0; i < n - 1; i++) {
			vs[i] = nextInt() - 1;
			us[i] = nextInt() - 1;
			deg[vs[i]]++;
			deg[us[i]]++;
		}
	
		for (int i = 0; i < n; i++) {
			g[i] = new int[deg[i]];
		}
		
		for (int i = 0; i < n - 1; i++) {
			int v = vs[i];
			int u = us[i];
			g[v][--deg[v]] = u;
			g[u][--deg[u]] = v;
		}
		
		par = new int[n];
		order = new int[n];
		time = n;
		dfs(0, -1);
		
		for (int i = 1; i < n; i++) {
			int seek = par[i];
			int idx = -1;
			for (int j = 0; j < g[i].length; j++) {
				if (g[i][j] == seek) {
					idx = j;
					break;
				}
			}
			int tmp = g[i][idx];
			g[i][idx] = g[i][g[i].length - 1];
			g[i][g[i].length - 1] = tmp;
			g[i] = Arrays.copyOf(g[i], g[i].length - 1);
		}
		
		path = new int[n];
		ans = new int[n + 1];
		go(0, n, n + 1, 0);
		
		for (int i = 1; i <= n; i++) {
			out.println(ans[i]);
		}
	}
	
	void go(int l, int fL, int r, int fR) {
		if (r - l <= 1) {
			return;
		}
		if (fL == fR) {
			for (int i = l + 1; i < r; i++) {
				ans[i] = fL;
			}
			return;
		}
		int m = (l + r) >> 1;
		ans[m] = f(m);
		go(l, fL, m, ans[m]);
		go(m, ans[m], r, fR);
	}
	
	int[] path;
	int[] ans;
	
	int f(int k) {
		int ret = 0;
		for (int v : order) {
			int m1 = 0, m2 = 0;
			for (int u : g[v]) {
				int val = path[u];
				if (val > m1) {
					m2 = m1;
					m1 = val;
				} else if (val > m2) {
					m2 = val;
				}
			}
			if (m1 + m2 + 1 >= k) {
				ret++;
				path[v] = 0;
			} else {
				path[v] = m1 + 1;
			}
		}
		return ret;
	}
	
	int[] par;
	int[] order;
	int time;
	
	void dfs(int v, int p) {
		order[--time] = v;
		par[v] = p;
		for (int u : g[v]) {
			if (u != p) {
				dfs(u, v);
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

	D() throws IOException {
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