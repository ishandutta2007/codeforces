import java.io.*;
import java.math.*;
import java.util.*;

public class C {

	void submit() {
		int n = nextInt();
		
		long[] ws = new long[n];
		long[] hs = new long[n];
		long[] cs = new long[n];
		
		for (int i = 0; i < n; i++) {
			ws[i] = nextLong();
			hs[i] = nextLong();
			cs[i] = nextLong();
		}
		
		long[] allW = unique(ws);
		long[] allH = unique(hs);
		
		int r = allW.length;
		int c = allH.length;
		
		if ((long)r * c != n) {
			out.println(0);
			return;
		}
		
		long[][] f = new long[r][c];
		for (int i = 0; i < n; i++) {
			f[Arrays.binarySearch(allW, ws[i])][Arrays.binarySearch(allH, hs[i])] = cs[i];
		}
		
//		System.err.println(Arrays.deepToString(f));
		
		long[] gRow = new long[r];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				gRow[i] = gcd(gRow[i], f[i][j]);
			}
		}
		
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (f[i][j] / gRow[i] != f[0][j] / gRow[0]) {
					out.println(0);
					return;
				}
			}
		}
		
		long all = 0;
		for (long x : gRow) {
			all = gcd(all, x);
		}
		
		int ans = 0;
		for (int i = 1; (long)i * i <= all; i++) {
			if (all % i == 0) {
				ans++;
				if (all / i != i) {
					ans++;
				}
			}
		}
		
		out.println(ans);
	}
	
	long gcd(long x, long y) {
		return y == 0 ? x : gcd(y, x % y);
	}
	
	long[] unique(long[] a) {
		a = a.clone();
		int sz = 0;
		Arrays.sort(a);
		for (int i = 0; i < a.length; i++) {
			if (sz == 0 || a[i] != a[sz - 1]) {
				a[sz++] = a[i];
			}
		}
		return Arrays.copyOf(a, sz);
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