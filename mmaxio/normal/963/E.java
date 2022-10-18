import java.io.*;
import java.math.*;
import java.util.*;

public class E {

	static final int[] DX = { -1, 0, 1, 0 };
	static final int[] DY = { 0, -1, 0, 1 };

	static final int P = 1_000_000_007;

	static final int CACHE_SIZE = 1 << 19;
	int[] cacheInv = new int[CACHE_SIZE];
	{
		cacheInv[1] = 1;
		for (int i = 2; i < CACHE_SIZE; i++) {
			cacheInv[i] = P - (int) ((long) (P / i) * cacheInv[P % i] % P);
		}
	}

	int inv(int x) {
		return x < CACHE_SIZE ? cacheInv[x] : P
				- (int) ((long) (P / x) * inv(P % x) % P);
	}

	void submit() {
		// long start = System.currentTimeMillis();
		int r = nextInt();
		int[] byDir = new int[4];
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			byDir[i] = nextInt();
			sum += byDir[i];
		}

		int invSum = inv(sum);

		for (int i = 0; i < 4; i++) {
			byDir[i] = (int) ((long) byDir[i] * invSum % P);
		}

		int s = 2 * r + 3;

		int[][] f = new int[s][s];
		int[] cx = new int[s * s];
		int[] cy = new int[s * s];
		int vars = 0;
		for (int i = 0; i < s; i++) {
			for (int j = 0; j < s; j++) {
				int sum2 = (i - r - 1) * (i - r - 1) + (j - r - 1)
						* (j - r - 1);
				if (sum2 <= r * r) {
					cx[vars] = i;
					cy[vars] = j;
					f[i][j] = vars++;
				} else {
					f[i][j] = -1;
				}
			}
		}

		int band = 0;

		for (int i = 0; i < vars; i++) {
			int x0 = cx[i];
			int y0 = cy[i];
			for (int dir = 0; dir < 4; dir++) {
				int x1 = x0 + DX[dir];
				int y1 = y0 + DY[dir];
				if (f[x1][y1] == -1) {
					continue;
				}
				int j = f[x1][y1];
				band = Math.max(band, Math.abs(i - j));
			}
		}

		int[][] bandM = new int[vars][2 * band + 1];

		for (int i = 0; i < vars; i++) {
			int x0 = cx[i];
			int y0 = cy[i];
			for (int dir = 0; dir < 4; dir++) {
				int x1 = x0 + DX[dir];
				int y1 = y0 + DY[dir];
				if (f[x1][y1] == -1) {
					continue;
				}
				int j = f[x1][y1];

				updateBandedMatrix(i, j, band, bandM, byDir[dir]);

			}
		}

		for (int i = 0; i < vars; i++) {
			for (int d = 0; d <= 2 * band; d++) {
				int j = i + d - band;
				bandM[i][d] = (i == j ? 1 : 0) - bandM[i][d];
				if (bandM[i][d] < 0) {
					bandM[i][d] += P;
				}
			}
		}

		// out.println(System.currentTimeMillis() - start);

		int[] ans = inverseBanded(bandM, band, f[r + 1][r + 1]);

		// out.println(System.currentTimeMillis() - start);

		int ret = 0;
		for (int x : ans) {
			ret += x;
			if (ret >= P) {
				ret -= P;
			}
		}

		out.println(ret);

	}

	void updateBandedMatrix(int row, int col, int width, int[][] m, double delta) {
		if (Math.abs(row - col) > width) {
			throw new AssertionError();
		}
		m[row][col - row + width] += delta;
	}

	int[] inverseBanded(int[][] a, int w, int whatCol) {
		int n = a.length;
		if (whatCol > n) {
			throw new AssertionError();
		}
		int[] b = new int[n];
		b[whatCol] = 1;

		for (int j = 0; j < n; j++) {
			int[] aj = a[j];
			for (int i = j + 1; i <= j + w && i < n; i++) {
				int[] ai = a[i];
				int coef = (int) ((long) ai[j - i + w] * inv(aj[w]) % P);
				
				if (coef == 0) {
					continue;
				}

				int kwiUpTo = Math.min(n, j + w + 1) + w - i;
				
//				for (int k = j + 1, kwi = (j + 1) + w - i; k < kUpTo; k++, kwi++) {
				for (int kwi = (j + 1) + w - i; kwi < kwiUpTo; kwi++) {
					int kek = ai[kwi]
							- (int) ((long) aj[kwi + i - j] * coef % P);
					if (kek < 0) {
						kek += P;
					}
					ai[kwi] = kek;
				}
				b[i] -= (int) ((long) b[j] * coef % P);
				if (b[i] < 0) {
					b[i] += P;
				}
			}
		}

		for (int i = n - 1; i >= 0; i--) {
			long tot = 0;
			for (int j = i + 1; j < n && j <= i + w; j++) {
				tot += (long) b[j] * a[i][j - i + w];
				if (tot >= P2) {
					tot -= P2;
				}
			}
			b[i] -= (int) (tot % P);
			if (b[i] < 0) {
				b[i] += P;
			}
			b[i] = (int) ((long) b[i] * inv(a[i][w]) % P);
		}

		return b;
	}

	static final long P2 = (long) P * P;

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

	E() throws IOException {
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