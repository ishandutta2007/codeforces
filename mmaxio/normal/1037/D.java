import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class D {

	int[] next;
	int[] head;
	int[] to;
	
	void submit() {
		int n = nextInt();
		
		int[] vs = new int[n - 1];
		int[] us = new int[n - 1];
		int[] deg = new int[n];
		
		for (int i = 0; i < n - 1; i++) {
			vs[i] = nextInt() - 1;
			us[i] = nextInt() - 1;
			deg[vs[i]]++;
			deg[us[i]]++;
		}
		
		Integer[][] g = new Integer[n][];
		for (int i = 0; i < n; i++) {
			g[i] = new Integer[deg[i]];
		}
		
		
		for (int i = 0; i < n - 1; i++) {
			int v = vs[i];
			int u = us[i];
			g[v][--deg[v]] = u;
			g[u][--deg[u]] = v;
		}
		
		int[] order = new int[n];
		int[] pos = new int[n];
		
		for (int i = 0; i < n; i++) {
			order[i] = nextInt() - 1;
			pos[order[i]] = i;
		}
		
		if (order[0] != 0) {
			out.println("No");
			return;
		}
		
		Comparator<Integer> cmp = (Integer x, Integer y) -> Integer.compare(pos[x], pos[y]);
		
		for (int i = 0; i < n; i++) {
			Arrays.sort(g[i], cmp);
		}
		
		boolean[] vis = new boolean[n];
		int[] que = new int[n];
		int qh = 0, qt = 0;
		que[qt++] = 0;
		vis[0] = true;
		
		while (qh < qt) {
			int v = que[qh++];
			
			for (int u : g[v]) {
				if (!vis[u]) {
					que[qt++] = u;
					vis[u] = true;
				}
			}
		}
		
		out.println(Arrays.equals(order, que) ? "Yes" : "No");
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