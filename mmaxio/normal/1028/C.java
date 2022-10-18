import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class C {

	static final int INF = Integer.MAX_VALUE / 2;

	void submit() {
		int n = nextInt();
		int[] x1 = new int[n];
		int[] y1 = new int[n];
		int[] x2 = new int[n];
		int[] y2 = new int[n];
		
		for (int i = 0; i < n; i++) {
			x1[i] = nextInt();
			y1[i] = nextInt();
			x2[i] = nextInt();
			y2[i] = nextInt();
		}
		
		int[] x1p = prefMax(x1);
		int[] x1s = suffMax(x1);
		int[] x2p = prefMin(x2);
		int[] x2s = suffMin(x2);
		
		int[] y1p = prefMax(y1);
		int[] y1s = suffMax(y1);
		int[] y2p = prefMin(y2);
		int[] y2s = suffMin(y2);
		
		for (int i = 0; i < n; i++) {
			
			int lowX = Math.max(x1p[i], x1s[i + 1]);
			int highX = Math.min(x2p[i], x2s[i + 1]);
			
			int lowY = Math.max(y1p[i], y1s[i + 1]);
			int highY = Math.min(y2p[i], y2s[i + 1]);
			
			if (lowX <= highX && lowY <= highY) {
				out.println(lowX + " " + lowY);
				return;
			}
			
		}
		
		throw new AssertionError();
	}
	
	int[] prefMin(int[] a) {
		return negate(prefMax(negate(a)));
	}
	
	int[] suffMin(int[] a) {
		return negate(suffMax(negate(a)));
	}

	int[] prefMax(int[] a) {
		int[] b = new int[a.length + 1];
		b[0] = -INF;
		for (int i = 0; i < a.length; i++) {
			b[i + 1] = Math.max(b[i], a[i]);
		}
		return b;
	}

	int[] suffMax(int[] a) {
		int[] b = new int[a.length + 1];
		b[a.length] = -INF;
		for (int i = a.length - 1; i >= 0; i--) {
			b[i] = Math.max(b[i + 1], a[i]);
		}
		return b;
	}

	int[] negate(int[] a) {
		int[] b = new int[a.length];
		for (int i = 0; i < a.length; i++) {
			b[i] = -a[i];
		}
		return b;
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