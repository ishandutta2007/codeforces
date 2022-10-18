import java.io.*;
import java.math.*;
import java.util.*;

public class C {

	static final int LOG = 30;

	int[][] to;
	int[] cnt;
	int sz;

	int newNode() {
		to[0][sz] = to[1][sz] = -1;
		return sz++;
	}

	void submit() {
		int n = nextInt();
		int[] a = new int[n];
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		for (int i = 0; i < n; i++) {
			p[i] = nextInt();
		}

		to = new int[2][n * (LOG + 1)];
		cnt = new int[n * (LOG + 1)];
		
		int root = newNode();
		
		for (int x : p) {
			insert(x);
		}
		
		for (int x : a) {
			int node = 0;
			int outp = 0;
			for (int bit = LOG - 1; bit >= 0; bit--) {
				cnt[node]--;
				int v = (x >> bit) & 1;
				
				int fst = to[v][node];
				if (fst == -1 || cnt[fst] == 0) {
					node = to[v ^ 1][node];
					outp |= (1 << bit);
				} else {
					node = fst;
				}
				
			}
			cnt[node]--;
			out.print(outp + " ");
		}
		
	}

	void insert(int x) {
		int node = 0;
		for (int bit = LOG - 1; bit >= 0; bit--) {
			cnt[node]++;
			int v = (x >> bit) & 1;
			if (to[v][node] == -1) {
				to[v][node] = newNode();
			}
			node = to[v][node];
		}
		cnt[node]++;
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

	C() throws IOException {
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