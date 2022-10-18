import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class E {

	void submit() {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		int[] vs = new int[m];
		int[] us = new int[m];
		int[] deg = new int[n];
		
		for (int i = 0; i < m; i++) {
			vs[i] = nextInt() - 1;
			us[i] = nextInt() - 1;
			deg[vs[i]]++;
			deg[us[i]]++;
		}
		
		int[][] g = new int[n][];
		for (int i = 0; i < n; i++) {
			g[i] = new int[deg[i]];
		}
		
		int[] ptr = deg.clone();
		
		for (int i = 0; i < m; i++) {
			int v = vs[i];
			int u = us[i];
			g[v][--ptr[v]] = i;
			g[u][--ptr[u]] = i;
		}
		
		boolean[] dead = new boolean[n];
		int[] que = new int[n];
		int qh = 0, qt = 0;
		
		for (int i = 0; i < n; i++) {
			if (deg[i] < k) {
				dead[i] = true;
				que[qt++] = i;
			}
		}
		
		while (qh < qt) {
			int v = que[qh++];
			for (int e : g[v]) {
				int u = vs[e] ^ us[e] ^ v;
				if (!dead[u]) {
					deg[u]--;
					if (deg[u] < k) {
						dead[u] = true;
						que[qt++] = u;
					}
				}
			}
		}
		
		int[] ans = new int[m];
		
		for (int i = m - 1; i >= 0; i--) {
			ans[i] = n - qt;
			
			int p = vs[i];
			int q = us[i];
			
			if (!dead[p] && !dead[q]) {
				deg[p]--;
				deg[q]--;
				if (deg[p] < k) {
					que[qt++] = p;
					dead[p] = true;
				}
				if (deg[q] < k) {
					que[qt++] = q;
					dead[q] = true;
				}
			}
			
			while (qh < qt) {
				int v = que[qh++];
				for (int e : g[v]) {
					int u = vs[e] ^ us[e] ^ v;
					if (!dead[u]) {
						
						if (e >= i) {
							continue;
						}
						
						deg[u]--;
						if (deg[u] < k) {
							dead[u] = true;
							que[qt++] = u;
						}
					}
				}
			}
		}
		
		for (int x : ans) {
			out.println(x);
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

	E() throws IOException {
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
		new E();
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