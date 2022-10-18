import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class B {

	static final String ALPH = "ACGT";

	int go(int[][] a, int x, int y, int pars) {
		int r = a.length;
		int c = a[0].length;
		int[][] b = new int[2][2];
		b[0][0] = x;
		b[0][1] = y;
		int ptr = 0;
		for (int i = 0; i < 4; i++) {
			if (x != i && y != i) {
				b[1][ptr++] = i;
			}
		}
		int ret = 0;
		int[] doSwap = new int[a.length];
		for (int i = 0; i < a.length; i++) {
			int keep = 0, swap = 0;
			int[] now = b[i % 2];
			for (int j = 0; j < a[i].length; j++) {
				if (a[i][j] != now[j % 2]) {
					keep++;
				}
				if (a[i][j] != now[(j % 2) ^ 1]) {
					swap++;
				}
			}
			ret += Math.min(keep, swap);
			if (swap < keep) {
				doSwap[i] = 1;
			}
		}
		
		if (pars != 0) {
			int[][] ans = new int[r][c];
			for (int i = 0; i < r; i++) {
				int[] now = b[i % 2];
				for (int j = 0; j < c; j++) {
					ans[i][j] = now[(j % 2) ^ doSwap[i]];
				}
			}
			if (pars == 2) {
				ans = transpose(ans);
			}
			for (int i = 0; i< ans.length; i++) {
				for (int j = 0; j < ans[i].length; j++) {
					out.print(ALPH.charAt(ans[i][j]));
				}
				out.println();
			}
		}
		
		return ret;
	}
	
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
	
	void submit() {
		int r = nextInt();
		int c = nextInt();
		int[][] a = new int[r][c];
		for (int i = 0; i < r; i++) {
			String tmp = nextToken();
			for (int j = 0; j < c; j++) {
				a[i][j] = ALPH.indexOf(tmp.charAt(j));
			}
		}

		int[] pars = null;
		int best = Integer.MAX_VALUE;

		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				int now = go(a, i, j, 0);
				if (now < best) {
					best = now;
					pars = new int[] { i, j, 1};
				}
			}
		}
		
		a = transpose(a);
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				int now = go(a, i, j, 0);
				if (now < best) {
					best = now;
					pars = new int[] { i, j, 2 };
				}
			}
		}
		
//		System.err.println(best);
		
		if (pars[2] == 1) {
			a = transpose(a);
		}
		
		go(a, pars[0], pars[1], pars[2]);
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