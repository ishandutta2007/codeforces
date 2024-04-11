import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class F {
	
	static final int LEN = 110;
	static final int B = 7001;

	static final int LOG = 6;
	static final int SIZE = 1 << LOG;
	static final int MASK = (1 << LOG) - 1;
	
	void set(long[] b, int i) {
		b[i >> LOG] |= 1L << (i & MASK);
	}

	void submit() {
		int n = nextInt();
		int q = nextInt();

		boolean[] sqf = new boolean[B];
		Arrays.fill(sqf, true);
		
		for (int x = 2; x * x < B; x++) {
			for (int y = x * x; y < B; y += x * x) {
				sqf[y] = false;
			}
		}
		
		long[][] ans = new long[B][LEN];
		for (int i = 1; i < B; i++) {
			for (int j = 1; i * j < B; j++) {
				if (sqf[j]) {
					set(ans[i], i * j);
				}
			}
		}
		
		long[][] base = new long[B][LEN];
		for (int i = 1; i < B; i++) {
			for (int j = i; j < B; j += i) {
				set(base[j], i);
			}
		}
		
		long[][] a = new long[n][LEN];
		
		while (q-- > 0) {
			int type = nextInt();
			int x = nextInt() - 1;
			if (type == 1) {
				int v = nextInt();
				a[x] = base[v].clone();
			} else if (type == 2) {
				int y = nextInt() - 1;
				int z = nextInt() - 1;
				long[] ret = new long[LEN];
				long[] arg1 = a[y];
				long[] arg2 = a[z];
				for (int i = 0; i < LEN; i++) {
					ret[i] = arg1[i] ^ arg2[i];
				}
				a[x] = ret;
			} else if (type == 3) {
				int y = nextInt() - 1;
				int z = nextInt() - 1;
				long[] ret = new long[LEN];
				long[] arg1 = a[y];
				long[] arg2 = a[z];
				for (int i = 0; i < LEN; i++) {
					ret[i] = arg1[i] & arg2[i];
				}
				a[x] = ret;
			} else if (type == 4) {
				int v = nextInt();
				int ret = 0;
				long[] arg1 = a[x];
				long[] arg2 = ans[v];
				for (int i = 0; i < LEN; i++) {
					ret ^= Long.bitCount(arg1[i] & arg2[i]);
				}
				out.print(ret & 1);
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

	F() throws IOException {
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
		new F();
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