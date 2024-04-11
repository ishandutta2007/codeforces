import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class C {

	int[] solve(int[] go) {
		int n = go.length;
		if (go[n - 1] == -1) {
			go[n - 1] = n;
		}
		if (go[n - 1] != n) {
			return null;
		}

		for (int i = n - 1; i >= 0; i--) {
			if (go[i] == -1) {
				go[i] = i + 1;
			}
			if (go[i] <= i) {
				return null;
			}
		}

		ArrayList<Integer> gAL = new ArrayList<>();
		for (int i = n - 2; i >= 0; i--) {
			int goal = go[i];
			if (goal != n) {
				gAL.add(goal);
				gAL.add(i);
			}
			int j = i + 1;
			while (goal != j) {
				if (goal < j) {
					return null;
				} else {
					gAL.add(i);
					gAL.add(j);
					j = go[j];
				}
			}
		}

		int[] gArr = new int[gAL.size()];
		for (int i = 0; i < gArr.length; i++) {
			gArr[i] = gAL.get(i);
		}

		g = buildDGraph(gArr, n, gArr.length / 2);
		vis = new boolean[n];

		ptr = 0;
		ans = new int[n];

		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				dfs(i);
			}
		}

		return ans.clone();
	}

	int ptr;
	int[][] g;
	boolean[] vis;
	int[] ans;

	void dfs(int v) {
		vis[v] = true;
		for (int u : g[v]) {
			if (!vis[u]) {
				dfs(u);
			}
		}
		ans[v] = ptr++;
	}

	int[][] buildDGraph(int[] a, int n, int m) {
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
		}

		return g;
	}

	void submit() {
		int t = nextInt();
		while (t-- > 0) {
			int n = nextInt();
			int[] go = new int[n];
			for (int i = 0; i < n; i++) {
				go[i] = nextInt() - 1;
				if (go[i] < 0) {
					go[i] = -1;
				}
			}

			int[] p = solve(go);
			if (p == null) {
				out.println(-1);
			} else {
				for (int x : p) {
					out.print(x + 1 + " ");
				}
				out.println();
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