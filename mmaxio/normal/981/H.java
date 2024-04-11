import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class H {

	int[] next;
	int[] head;
	int[] to;

	int n, k;

	int[] coef;
	int[] sz;

	void submit() {
		n = nextInt();
		if (n == 1) {
			out.println(0);
			return;
		}

		k = nextInt();

		if (k == 1) {
			out.println((long) n * (n - 1) / 2 % P);
			return;
		}

		coef = new int[n + 1];
		coef[0] = 1;
		for (int i = 1; i <= n; i++) {
			coef[i] = (int) ((long) coef[i - 1] * (k - i + 1) % P);
		}

		next = new int[2 * n - 2];
		head = new int[n];
		Arrays.fill(head, -1);
		to = new int[2 * n - 2];

		for (int i = 0; i < n - 1; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			to[2 * i] = u;
			next[2 * i] = head[v];
			head[v] = 2 * i;

			to[2 * i + 1] = v;
			next[2 * i + 1] = head[u];
			head[u] = 2 * i + 1;
		}

		sz = new int[n];
		dfs(0, -1);

		out.println(outp);
	}

	int outp = 0;

	int eval(int[] poly) {
		int ret = 0;
		for (int i = 0; i < poly.length; i++) {
			ret += (int) ((long) coef[i] * poly[i] % P);
			if (ret >= P) {
				ret -= P;
			}
		}
		return ret;
	}

	int[] multQueMagic(ArrayDeque<int[]> que) {
		while (que.size() > 2) {
			int[] f1 = que.poll();
			int[] p1 = que.poll();
			int[] f2 = que.poll();
			int[] p2 = que.poll();

			que.add(plus(mult(f1, p2, P), mult(f2, p1, P)));
			que.add(mult(p1, p2, P));
		}
		return que.poll();
	}

	int[] plus(int[] a, int[] b) {
		int[] c = Arrays.copyOf(a, Math.max(a.length, b.length));
		for (int i = 0; i < b.length; i++) {
			c[i] += b[i];
			if (c[i] >= P) {
				c[i] -= P;
			}
		}
		return c;
	}

	int dfs(int v, int p) {
		sz[v] = 1;
		int ret = 0;

		ArrayDeque<int[]> que = new ArrayDeque<>();

		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			if (u == p) {
				continue;
			}

			int delta = dfs(u, v);
			sz[v] += sz[u];
			outp += (int) ((long) ret * delta % P);
			if (outp >= P) {
				outp -= P;
			}

			ret += delta;
			if (ret >= P) {
				ret -= P;
			}

			que.add(new int[] { delta });
			que.add(new int[] { 1, sz[u] });
		}

		if (que.isEmpty()) {
			return 1;
		}

		while (que.size() > 2) {
			int[] f1 = que.poll();
			int[] p1 = que.poll();
			int[] f2 = que.poll();
			int[] p2 = que.poll();

			que.add(plus(mult(f1, p2, P), mult(f2, p1, P)));
			que.add(mult(p1, p2, P));
		}

		int[] val = mult(new int[] { 1, n - sz[v] }, que.poll(), P);
		for (int i = 0; i < val.length; i++) {
			outp += (int) ((long) val[i] * coef[i] % P);
			if (outp >= P) {
				outp -= P;
			}
		}
		
		int[] prod = que.poll();
		for (int i = 0; i < prod.length; i++) {
			ret += (int)((long)prod[i] * coef[i] % P);
			if (ret >= P) {
				ret -= P;
			}
		}

		return ret;
	}

	static int nextPowerOf2(int x) {
		return x == 1 ? 1 : Integer.highestOneBit(x - 1) << 1;
	}

	static double[][] foo(int[] intV, int len, int L) {
		// pack into one complex vector
		double[] f = new double[len << 1];
		for (int i = 0; i < intV.length; i++) {
			f[i << 1] = intV[i] % L;
			f[i << 1 | 1] = intV[i] / L;
		}

		fft(f, false);

		// unpack
		double[] f1 = new double[len << 1];
		double[] f2 = new double[len << 1];

		// LEN MUST BE A POWER OF 2!!!
		int zzz = (len << 1) - 1;
		for (int i = 0; i < len << 1; i += 2) {
			int j = (-i) & zzz;
			f1[i] = .5 * (f[i] + f[j]);
			f1[i + 1] = .5 * (f[i + 1] - f[j + 1]);
			f2[i] = .5 * (f[i + 1] + f[j + 1]);
			f2[i + 1] = .5 * (f[j] - f[i]);
		}

		return new double[][] { f1, f2 };
	}

	static final int P = 998244353;
	static final int THRESHOLD = 40;

	static int[] trim(int[] poly) {
		int len = poly.length;
		while (len > 0 && poly[len - 1] == 0) {
			len--;
		}
		return Arrays.copyOf(poly, len);
	}

	static int[] naiveMult(int[] a, int[] b, int p) {
		long p2 = (long) p * p;
		long[] c = new long[a.length + b.length - 1];
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < b.length; j++) {
				c[i + j] += (long) a[i] * b[j];
				if (c[i + j] >= p2) {
					c[i + j] -= p2;
				}
			}
		}
		int[] ic = new int[c.length];
		for (int i = 0; i < c.length; i++) {
			ic[i] = (int) (c[i] % p);
		}
		return trim(ic);
	}

	public static int[] mult(int[] a, int[] b, int pMod) {

		if (a.length < THRESHOLD || b.length < THRESHOLD) {
			return naiveMult(a, b, pMod);
		}

		int k = (int) (Math.sqrt(pMod) + 1);
		int k2 = k * k % pMod;

		int len = nextPowerOf2(a.length + b.length - 1);
		int len2 = len << 1;

		double[][] fA = foo(a, len, k);
		double[][] fB = foo(b, len, k);

		double[][] invF = new double[2][len2];

		for (int ia = 0; ia < 2; ia++) {
			for (int ib = 0; ib < 2; ib++) {

				double[] r = invF[(ia + ib) >> 1];
				double[] p = fA[ia];
				double[] q = fB[ib];

				if (((ia + ib) & 1) == 0) {
					for (int i = 0; i < len2; i += 2) {
						r[i] += p[i] * q[i] - p[i + 1] * q[i + 1];
						r[i + 1] += p[i] * q[i + 1] + p[i + 1] * q[i];
					}

				} else {
					for (int i = 0; i < len2; i += 2) {
						r[i] -= p[i] * q[i + 1] + p[i + 1] * q[i];
						r[i + 1] += p[i] * q[i] - p[i + 1] * q[i + 1];
					}
				}

			}
		}

		fft(invF[0], true);
		fft(invF[1], true);

		int[] ret = new int[len];

		for (int i = 0; i < len2; i += 2) {
			long v0 = (long) (invF[0][i] + .5);
			long v1 = ((long) (invF[0][i + 1] + .5)) % pMod * k;
			long v2 = ((long) (invF[1][i] + .5)) % pMod * k2;
			ret[i >> 1] = (int) ((v0 + v1 + v2) % pMod);
		}

		return trim(ret);
	}

	public static void fft(double[] v, boolean invert) {
		int n2 = v.length;
		int n = n2 >> 1;
		int logN = Integer.numberOfTrailingZeros(n);
		prepareArrays(logN);
		int[] rev = rev2D[logN];

		for (int i = 0; i < n2; i += 2) {
			int j = rev[i >> 1] << 1;
			if (i < j) {
				double t = v[i];
				v[i] = v[j];
				v[j] = t;
				t = v[i + 1];
				v[i + 1] = v[j + 1];
				v[j + 1] = t;
			}
		}

		double conj = invert ? -1 : 1;

		for (int len = 2, row = 0; len <= n; len <<= 1, row++) {
			double[] pow = pow2D[row];
			for (int i = 0; i < n; i += len) {
				for (int j1 = i << 1, j2 = j1 + len, k = 0; k < len; j1 += 2, j2 += 2, k += 2) {
					double uA = v[j1];
					double uB = v[j1 + 1];

					double mRe = pow[k];
					double mIm = pow[k + 1] * conj;

					double vA = v[j2] * mRe - v[j2 + 1] * mIm;
					double vB = v[j2] * mIm + v[j2 + 1] * mRe;

					v[j1] = uA + vA;
					v[j1 + 1] = uB + vB;
					v[j2] = uA - vA;
					v[j2 + 1] = uB - vB;
				}
			}
		}
		if (invert) {
			for (int i = 0; i < n2; i++) {
				v[i] /= n;
			}
		}
	}

	static double[][] pow2D = { { 1, 0 } };
	static int[][] rev2D = {};

	static void prepareArrays(int n) {
		if (rev2D.length < n + 1) {
			rev2D = Arrays.copyOf(rev2D, n + 1);
		}

		if (rev2D[n] == null) {
			int[] tmp = rev2D[n] = new int[1 << n];
			for (int i = 0; i < (1 << n); i++) {
				tmp[i] = (tmp[i >> 1] >> 1) | ((i & 1) << (n - 1));
			}
		}

		int oldN = pow2D.length;

		if (oldN >= n) {
			return;
		}

		pow2D = Arrays.copyOf(pow2D, n);

		for (int i = oldN; i < n; i++) {
			double angle = Math.PI / (1 << i);

			double mRe = Math.cos(angle);
			double mIm = Math.sin(angle);

			double[] dst = pow2D[i] = new double[2 << i];
			double[] src = pow2D[i - 1];

			for (int j = 0; j < 1 << i; j += 2) {
				double re = src[j];
				double im = src[j + 1];

				dst[j << 1] = re;
				dst[j << 1 | 1] = im;
				dst[j << 1 | 2] = re * mRe - im * mIm;
				dst[j << 1 | 3] = re * mIm + im * mRe;
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

	H() throws IOException {
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
		new H();
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
//kek