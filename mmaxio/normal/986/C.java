import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class C {

	void submit() {
		int n = nextInt();
		int m = nextInt();

		int[] a = new int[1 << n];
		for (int i = 0; i < m; i++) {
			int x = nextInt();
			a[x]++;
		}

		if (a[0] == 1) {
			out.println(1);
			return;
		}

		int[] b = a.clone();
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < 1 << n; i++) {
				if (test(i, j)) {
					b[i] += b[i ^ (1 << j)];
				}
			}
		}

		int all = (1 << n) - 1;

		boolean[] mark = new boolean[1 << n];
		
		p = IntStream.range(0, 1 << n).toArray();
		rank = new int[1 << n];

		for (int i = 1; i < 1 << (n - 1); i++) {
			if (b[i] > 0 && b[all ^ i] > 0) {
				mark[i] = mark[all ^ i] = true;
				unite(i, all ^ i);
			}
		}
		
		for (int i = all; i > 0; i--) {
			
			if (!mark[i]) {
				continue;
			}
			
			if (b[i] == 0) {
				continue;
			}

			for (int j = 0; j < n; j++) {
				if (test(i, j)) {
					int into = i ^ (1 << j);
					if (b[into] == 0) {
						continue;
					}
					mark[into] = true;
					unite(i, into);
				}
			}
		}
		
		boolean[] seen = new boolean[1 << n];
		for (int i = 0; i < 1 << n; i++) {
			if (a[i] > 0) {
				seen[get(i)] = true;
			}
		}
		
		int ans = 0;
		for (boolean flag : seen) {
			ans += flag ? 1 : 0;
		}
		
		out.println(ans);
	}
	
	int[] p;
	int[] rank;
	
	int get(int v) {
		return p[v] == v ? v : (p[v] = get(p[v]));
	}
	
	void unite(int v, int u) {
		v = get(v);
		u = get(u);
		if (v == u) {
			return;
		}
		
		if (rank[v] < rank[u]) {
			int tmp = v;
			v = u;
			u = tmp;
		}
		
		p[u] = v;
		if (rank[v] == rank[u]) {
			rank[v]++;
		}
	}

	static final boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
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