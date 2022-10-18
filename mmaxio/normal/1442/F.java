import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class E {

	boolean[] vis;
	ArrayList<Integer> order;
	int[][] g;

	void dfs(int v) {
		vis[v] = true;
		for (int u : g[v]) {
			if (!vis[u]) {
				dfs(u);
			}
		}
		order.add(v);
	}

	static final int K = 20;

	void submit() {
		int n = nextInt();
		int m = nextInt();
		int t = nextInt();
		// int n = 1000;
		// int m = 0;
		// int t = 0;
		int[] es = new int[2 * m];
		for (int i = 0; i < 2 * m; i++) {
			es[i] = nextInt() - 1;
		}

		g = buildDGraph(es, n, m);

		vis = new boolean[n];
		order = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				dfs(i);
			}
		}

		ArrayList<Integer> head = new ArrayList<>();
		ArrayList<Integer> ans = new ArrayList<>();
		int[] who = new int[n];
		Arrays.fill(who, -1);
		for (int i = 0; i < n && i < K; i++) {
			int v = order.get(i);
//			if (m == 100000) {
//				out.print(";" + v);
//			}
			head.add(v);
			who[v] = i;
			ArrayList<Integer> after = new ArrayList<>();
			for (int j = 0; j < i; j++) {
				after.add(order.get(j));
			}
			for (int u : g[v]) {
				after.remove(Integer.valueOf(u));
			}
			for (int u : after) {
				ans.add(v);
				ans.add(u);
			}
		}
//		if (m == 100000) {
//			out.println();
//			out.flush();
//		}

		ArrayList<Integer> rest = new ArrayList<>();
		for (int i = K; i < n; i++) {
			rest.add(order.get(i));
		}
		Collections.shuffle(rest);

		int[] memo = new int[1 << K];
		Arrays.fill(memo, -1);

		ArrayList<Integer> randHead = new ArrayList<>(head);

		for (int v : rest) {
			ans.add(v);
			ans.add(v);
			int curMask = 0;
			for (int u : g[v]) {
				if (who[u] != -1) {
					curMask |= 1 << who[u];
				}
			}
			Collections.shuffle(randHead);
			for (int u : randHead) {
				if (memo[curMask] == -1) {
					break;
				}
//				if (m == 100000 && v == 0) {
//					out.print(test(curMask, who[u]) ? ~u : u + ";");
//				}
				ans.add(v);
				ans.add(test(curMask, who[u]) ? ~u : u);
				curMask ^= 1 << who[u];
			}

			if (memo[curMask] != -1) {
				throw new AssertionError("couldn't make all nodes different");
			}
			memo[curMask] = v;
		}
//		if (m == 100000) {
//			out.println("!" + Arrays.toString(g[0]).replaceAll(" ", ""));
//			out.println("!");
//			out.flush();
//		}

		// System.err.println(ans.size() / 2);
		if (ans.size() > 2 * 4242) {
			throw new AssertionError("too many edges added");
		}

		out.println(ans.size() / 2);
		for (int i = 0; i < ans.size(); i += 2) {
			int v = ans.get(i);
			int u = ans.get(i + 1);
			if (u >= 0) {
				out.println("+ " + (v + 1) + " " + (u + 1));
			} else {
				out.println("- " + (v + 1) + " " + ((~u) + 1));
			}
		}
		out.flush();

		while (t-- > 0) {
			int[] resp = new int[Math.min(n, K)];
			for (int i = 0; i < resp.length; i++) {
				out.println("? 1 " + (head.get(i) + 1));
				out.flush();
				resp[i] = decode(nextToken());
			}

			int winMask = 0;
			boolean fuck = false;
			for (int i = 0; i < resp.length; i++) {
				if (resp[i] == -1) {
					out.println("! " + (head.get(i) + 1));
					out.flush();
					fuck = true;
					break;
				}
				if (resp[i] == 1) {
					winMask |= 1 << i;
				}
			}
			if (!fuck) {
				if (memo[winMask] == -1) {
					throw new AssertionError("no answer for winMask");
				}
				out.println("! " + (memo[winMask] + 1));
				out.flush();
			}

			nextToken();
		}
	}

	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	int decode(String response) {
		switch (response) {
		case "Lose":
			return -1;
		case "Draw":
			return 0;
		case "Win":
			return 1;
		default:
			throw new AssertionError("unknown response");
		}
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

	void test() {

	}

	void stress() {
		for (int tst = 0;; tst++) {
			submit();
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