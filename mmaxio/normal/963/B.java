import java.io.*;
import java.math.*;
import java.util.*;

public class B {

	int[] next;
	int[] head;
	int[] to;

	int[] evens;
	int[] sz;
	int n;
	
	int[] par;

	void dfs(int v, int p) {
		par[v] = p;
		sz[v] = 1;
		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			if (u == p) {
				continue;
			}
			dfs(u, v);
			int tmp = sz[u];
			evens[v] += (tmp % 2 == 1) ? 0 : 1;
			sz[v] += tmp;
		}
		if (p != -1) {
			evens[v] += ((n - sz[v]) % 2 == 1) ? 0 : 1;
		}
	}

	void submit() {
		n = nextInt();
		if (n % 2 == 0) {
			out.println("NO");
			return;
		}

		int ptr = 0;
		
		next = new int[2 * n];
		head = new int[n];
		Arrays.fill(head, -1);
		to = new int[2 * n];
		par = new int[n];
		sz = new int[n];

		for (int v = 0; v < n; v++) {
			int u = nextInt() - 1;
			if (u == -1) {
				continue;
			}

			to[ptr] = u;
			next[ptr] = head[v];
			head[v] = ptr++;

			to[ptr] = v;
			next[ptr] = head[u];
			head[u] = ptr++;
		}

		evens = new int[n];
		dfs(0, -1);
		
		int[] que = new int[n];
		int qh = 0, qt = 0;
		boolean[] inQ = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (evens[i] == 0) {
				que[qt++] = i;
				inQ[i] = true;
			}
		}
		
		ArrayList<Integer> ans = new ArrayList<>();
		
		while (qh < qt) {
			int v = que[qh++];
			ans.add(v + 1);
			
			for (int e = head[v]; e >= 0; e = next[e]) {
				int u = to[e];
				if (inQ[u]) {
					continue;
				}
				
				int szVFromU;
				if (par[u] == v) {
					szVFromU = n - sz[u];
				} else {
					szVFromU = sz[v];
				}
				
				if (szVFromU % 2 == 0) {
					evens[u]--;
				}
				if (evens[u] == 0) {
					inQ[u] = true;
					que[qt++] = u;
				}
				
			}
		}
		
		if (qh != n) {
			out.println("NO");
			return;
		}
		
		out.println("YES");
		for (int v : ans) {
			out.println(v);
		}
	}

	void preCalc() {

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

	B() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		preCalc();
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
		new B();
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