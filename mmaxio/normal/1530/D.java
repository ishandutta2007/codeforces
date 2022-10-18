import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class D {

//	void go(int v) {
//		depth[v] = -2;
//		if (depth[to[v]] == -2) {
//			depth[v] = 0;
//			repr[v] = v;
//			for (int i = to[v]; i != v; i = to[i]) {
//				depth[i] = 0;
//				repr[i] = v;
//			}
//			return;
//		}
//		if (depth[to[v]] == -1) {
//			go(to[v]);
//			if (depth[v] != 0) {
//				depth[v] = 1 + depth[to[v]];
//				repr[v] = repr[to[v]];
//			}
//			return;
//		}
//
//		depth[v] = 1 + depth[to[v]];
//		repr[v] = repr[to[v]];
//	}

//	void solve(int[] a) {
//		to = a;
//		int n = a.length;
//
//		depth = new int[n];
//		repr = new int[n];
//
//		Arrays.fill(depth, -1);
//		for (int i = 0; i < n; i++) {
//			if (depth[i] == -1) {
//				go(i);
//			}
//		}
//
//		int[] maxDepth = new int[n];
//		int[] who = new int[n];
//
//		Arrays.fill(maxDepth, -1);
//		for (int i = 0; i < n; i++) {
//			int key = repr[i];
//			if (depth[i] > maxDepth[key]) {
//				maxDepth[key] = depth[i];
//				who[key] = i;
//			}
//		}
//
//		int[] ans = new int[n];
//		Arrays.fill(ans, -1);
//		boolean[] usedInc = new boolean[n];
//
//		ArrayList<Integer> rest = new ArrayList<>();
//
//		boolean[] mark = new boolean[n];
//
//		for (int i = 0; i < n; i++) {
//			if (maxDepth[i] >= 0) {
//				int v = who[i];
//				while (ans[v] == -1 && !usedInc[to[v]]) {
//					mark[v] = true;
//					ans[v] = to[v];
//					usedInc[to[v]] = true;
//					v = to[v];
//				}
//				mark[v] = true;
//				if (ans[v] == -1) {
//					rest.add(who[i]);
//					rest.add(v);
//				}
//			}
//		}
//		for (int i = 0; i < n; i++) {
//			if (!mark[i]) {
//				rest.add(i);
//				rest.add(i);
//			}
//		}
//
//		for (int i = 1; i < rest.size(); i += 2) {
//			ans[rest.get(i)] = rest.get((i + 1) % rest.size());
//		}
//
//		int cnt = 0;
//		for (int i = 0; i < n; i++) {
//			cnt += ans[i] == to[i] ? 1 : 0;
//		}
//
//		out.println(cnt);
//		for (int x : ans) {
//			out.print((x + 1) + " ");
//		}
//		out.println();
//
//	}
	
	void solve(int[] g) {
		int n = g.length;

		boolean[] in = new boolean[n];
		for (int i = 0; i < n; i++) {
			in[g[i]] = true;
		}

		int[] ans = new int[n];
		Arrays.fill(ans, -1);
		
		ArrayList<Integer> rest = new ArrayList<>();
		boolean[] mark = new boolean[n];
		
		for (int i = 0; i < n; i++) {
			if (in[i]) {
				continue;
			}
			int v = i;
			while (!mark[g[v]]) {
				mark[v] = true;
				ans[v] = g[v];
				v = g[v];
			}
			mark[v] = true;
			rest.add(i);
			rest.add(v);
		}

		for (int i = 0; i < n; i++) {
			if (mark[i]) {
				continue;
			}
			int v = i;
			while (!mark[v]) {
				mark[v] = true;
				ans[v] = g[v];
				v = g[v];
			}
		}
		
//		System.err.println(rest);

		for (int i = 1; i < rest.size(); i += 2) {
			ans[rest.get(i)] = rest.get((i + 1) % rest.size());
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += ans[i] == g[i] ? 1 : 0;
		}

		out.println(cnt);
		for (int x : ans) {
			out.print((x + 1) + " ");
		}
		out.println();

	}

	void submit() {
		int t = nextInt();
		while (t-- > 0) {
			int n = nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt() - 1;
			}
			solve(a);
		}
	}

	void test() {

	}

	void stress() {
		for (int tst = 0; tst < 2; tst++) {
			int n = rand(2, C);
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				do {
					a[i] = rand(0, n - 1);
				} while (a[i] == i);
			}
			out.println("in ");
			for (int x : a) {
				out.print((x + 1) + " ");
			}
			out.println();
			solve(a);
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
//		 stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 10;

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