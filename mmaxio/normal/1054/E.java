import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class E {

	static final boolean DEBUG = false;

	int[] ans;
	int sz;

	String[][] board;

	void move(int r1, int c1, int r2, int c2) {
		if (r1 == r2 && c1 == c2) {
			throw new AssertionError();
		}
		if (r1 != r2 && c1 != c2) {
			throw new AssertionError();
		}

		if (DEBUG) {
			if (board[r1][c1].isEmpty()) {
				throw new AssertionError();
			}
			String from = board[r1][c1];
			board[r2][c2] = from.charAt(from.length() - 1) + board[r2][c2];
			board[r1][c1] = from.substring(0, from.length() - 1);
		}

		ans[sz++] = r1;
		ans[sz++] = c1;
		ans[sz++] = r2;
		ans[sz++] = c2;

		// System.err.println((r1 + 1) + " " + (c1 + 1) + " " + (r2 + 1) + " " +
		// (c2 + 1));
	}

	void go2(String[][] f, int r, int c) {
		{
			String s = f[0][0];
			for (int k = s.length() - 1; k >= 0; k--) {
				if (s.charAt(k) == '0') {
					move(0, 0, 0, 1);
					move(0, 1, 0, 0);
				} else {
					move(r - 1, c - 1, r - 1, 0);
					move(r - 1, 0, 0, 0);
				}
			}
		}

		{
			String s = f[r - 1][c - 1];
			for (int k = s.length() - 1; k >= 0; k--) {
				if (s.charAt(k) == '1') {
					move(r - 1, c - 1, r - 2, c - 1);
					move(r - 2, c - 1, r - 1, c - 1);
				} else {
					move(0, 0, r - 1, 0);
					move(r - 1, 0, r - 1, c - 1);
				}
			}
		}

		for (int i = 1; i < r - 1; i++) {
			for (int j = 0; j < c; j++) {
				String s = f[i][j];
				for (int k = s.length() - 1; k >= 0; k--) {
					if (s.charAt(k) == '0') {
						safeMove(0, i, j);
					} else {
						safeMove(1, i, j);
					}
				}
			}
		}

		for (int j = 1; j < c - 1; j++) {
			String s = f[0][j];
			for (int k = s.length() - 1; k >= 0; k--) {
				if (s.charAt(k) == '0') {
					move(0, 0, 0, j);
				} else {
					move(r - 1, c - 1, 0, c - 1);
					move(0, c - 1, 0, j);
				}
			}
		}

		for (int j = 1; j < c - 1; j++) {
			String s = f[r - 1][j];
			for (int k = s.length() - 1; k >= 0; k--) {
				if (s.charAt(k) == '0') {
					move(0, 0, r - 1, 0);
					move(r - 1, 0, r - 1, j);
				} else {
					move(r - 1, c - 1, r - 1, j);
				}
			}
		}

		{
			String s = f[0][c - 1];
			for (int k = s.length() - 1; k >= 0; k--) {
				if (s.charAt(k) == '0') {
					move(0, 0, 0, c - 1);
				} else {
					move(r - 1, c - 1, 0, c - 1);
				}
			}
		}

		{
			String s = f[r - 1][0];
			for (int k = s.length() - 1; k >= 0; k--) {
				if (s.charAt(k) == '0') {
					move(0, 0, r - 1, 0);
				} else {
					move(r - 1, c - 1, r - 1, 0);
				}
			}
		}
	}

	int r, c;

	void safeMove(int what, int x, int y) {
		if (what == 0) {
			if (y == 0) {
				move(0, 0, x, 0);
			} else {
				move(0, 0, 0, y);
				move(0, y, x, y);
			}
		} else {
			if (y == c - 1) {
				move(r - 1, c - 1, x, c - 1);
			} else {
				move(r - 1, c - 1, r - 1, y);
				move(r - 1, y, x, y);
			}
		}
	}

	void go1(String[][] f, int r, int c) {
		for (int i = 0; i < f[0][0].length(); i++) {
			move(0, 0, 0, 1);
		}
		f[0][1] = f[0][0] + f[0][1];
		f[0][0] = "";
		for (int i = 0; i < f[r - 1][c - 1].length(); i++) {
			move(r - 1, c - 1, r - 1, c - 2);
		}
		f[r - 1][c - 2] = f[r - 1][c - 1] + f[r - 1][c - 2];
		f[r - 1][c - 1] = "";

		int[] c0 = new int[c];
		int[] c1 = new int[c];

		for (int i = 1; i < r - 1; i++) {
			for (int j = 0; j < c; j++) {
				String s = f[i][j];

				for (int k = s.length() - 1; k >= 0; k--) {
					if (s.charAt(k) == '0') {
						move(i, j, 0, j);
						c0[j]++;
					} else {
						move(i, j, r - 1, j);
						c1[j]++;
					}
				}
			}
		}

		// -----------------

		int bad1 = 0;

		for (int j = 1; j < c - 1; j++) {
			String s = f[0][j];

			for (int k = s.length() - 1; k >= 0; k--) {
				if (s.charAt(k) == '0') {
					move(0, j, 0, 0);
				} else {
					move(0, j, 0, c - 1);
					bad1++;
				}
			}
			for (int k = 0; k < c0[j]; k++) {
				move(0, j, 0, 0);
			}
		}

		{
			String s = f[0][c - 1];

			for (int k = s.length() - 1; k >= 0; k--) {
				if (s.charAt(k) == '0') {
					move(0, c - 1, 0, 0);
				} else {
					move(0, c - 1, r - 1, c - 1);
				}
			}
			for (int k = 0; k < c0[c - 1]; k++) {
				move(0, c - 1, 0, 0);
			}
			for (int k = 0; k < bad1; k++) {
				move(0, c - 1, r - 1, c - 1);
			}
		}

		// -----------------

		int bad0 = 0;

		for (int j = 1; j < c - 1; j++) {
			String s = f[r - 1][j];

			for (int k = s.length() - 1; k >= 0; k--) {
				if (s.charAt(k) == '1') {
					move(r - 1, j, r - 1, c - 1);
				} else {
					move(r - 1, j, r - 1, 0);
					bad0++;
				}
			}
			for (int k = 0; k < c1[j]; k++) {
				move(r - 1, j, r - 1, c - 1);
			}
		}

		{
			String s = f[r - 1][0];

			for (int k = s.length() - 1; k >= 0; k--) {
				if (s.charAt(k) == '1') {
					move(r - 1, 0, r - 1, c - 1);
				} else {
					move(r - 1, 0, 0, 0);
				}
			}
			for (int k = 0; k < c1[0]; k++) {
				move(r - 1, 0, r - 1, c - 1);
			}
			for (int k = 0; k < bad0; k++) {
				move(r - 1, 0, 0, 0);
			}
		}
	}

	void submit() {
		r = nextInt();
		c = nextInt();
		String[][] a = new String[r][c];
		String[][] b = new String[r][c];

		int tot = 0;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				a[i][j] = nextToken();
				tot += a[i][j].length();
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				b[i][j] = nextToken();
			}
		}

		if (DEBUG) {
			board = new String[r][c];
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					board[i][j] = a[i][j];
				}
			}
		}

		ans = new int[16 * tot];

		go1(a, r, c);

		if (DEBUG)
			System.err.println(Arrays.deepToString(board));
		// System.err.println(sz / 4);
		go2(b, r, c);
		if (DEBUG)
			System.err.println(Arrays.deepToString(board));

		out.println(sz / 4);
		for (int i = 0; i < sz; i++) {
			out.print(ans[i] + 1);
			if (i % 4 == 3) {
				out.println();
			} else {
				out.print(" ");
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