import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class A {
	
	int[][] transpose(int[][] a) {
		int r = a.length;
		int c = a[0].length;
		
		int[][] b = new int[c][r];
		
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				b[j][i] = a[i][j];
			}
		}
		
		return b;
	}
	
	int[] unique(int[] a) {
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
	
	void go(int[][] a, int[] tot, int[][] pos) {
		int r = a.length;
		int c = a[0].length;
		
		for (int i = 0; i < r; i++) {
			int[] tmp = unique(a[i]);
			tot[i] = tmp.length;
			for (int j = 0; j < c; j++) {
				pos[i][j] = Arrays.binarySearch(tmp, a[i][j]);
			}
		}
	}

	void submit() {
		int r = nextInt();
		int c = nextInt();
		
		int[][] a = new int[r][c];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				a[i][j] = nextInt();
			}
		}
		
		int[][] b = transpose(a);
		
		int[] totR = new int[r];
		
		int[][] posR = new int[r][c];
		
		go(a, totR, posR);
		
		int[] totC = new int[c];
		int[][] posC = new int[c][r];
		
		go(b, totC, posC);
		
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				int p = posR[i][j];
				int q = posC[j][i];
				int x = totR[i];
				int y = totC[j];
				out.print(f(p, q, x, y) + " ");
			}
			out.println();
		}
	}
	
	int f(int p, int q, int x, int y) {
		return Math.max(p, q) + Math.max(x - p - 1, y - q - 1) + 1;
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

	A() throws IOException {
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
		new A();
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