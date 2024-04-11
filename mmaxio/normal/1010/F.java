import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class F {

	static final int P = 998244353;
	static final long P2 = (long)P * P;

	int[] next;
	int[] to;
	int[] head;

	int[] sz;

	static final int[] POLY_X = { 0, 1 };

	int[] addC(int[] poly, int x) {
		int[] ret = poly.clone();
		ret[0] += x;
		if (ret[0] >= P) {
			ret[0] -= P;
		}
		if (ret[0] < 0) {
			ret[0] += P;
		}
		return ret;
	}

	int[] sum(int[] a, int[] b) {
		int[] c = Arrays.copyOf(a, Math.max(a.length, b.length));
		for (int i = 0; i < b.length; i++) {
			c[i] += b[i];
			if (c[i] >= P) {
				c[i] -= P;
			}
		}
		return c;
	}
	
	int[][] eval(ArrayList<int[]> a, int l, int r) {
		if (r - l == 1) {
			return new int[][] { addC(a.get(l), 1), a.get(l) };
		}
		int m = (l + r) >> 1;
		int[][] p = eval(a, l, m);
		int[][] q = eval(a, m, r);

		int[] prod = l == 0 ? null : mult(p[1], q[1], P);
		p[0][0] -= 1;
		if (p[0][0] < 0) {
			p[0][0] += P;
		}

		int[] val = sum(mult(p[0], q[1], P), q[0]);
		return new int[][] { val, prod };
	}

	int[] eval(ArrayList<int[]> a) {
		return eval(a, 0, a.size())[0];
	}

	ArrayList<int[]> dfs(int v, int p) {
		sz[v] = 1;

		int sz1 = -1, sz2 = -1;
		ArrayList<int[]> res1 = null, res2 = null;

		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			if (u == p) {
				continue;
			}
			ArrayList<int[]> res = dfs(u, v);
			sz[v] += sz[u];
			if (sz1 == -1) {
				sz1 = sz[u];
				res1 = res;
			} else {
				sz2 = sz[u];
				res2 = res;
			}
		}

		if (sz1 == -1) {
			ArrayList<int[]> ret = new ArrayList<>(0);
			ret.add(POLY_X);
			return ret;
		}

		if (sz2 == -1) {
			res1.add(POLY_X);
			return res1;
		}

		if (sz1 < sz2) {
			ArrayList<int[]> tmp = res1;
			res1 = res2;
			res2 = tmp;
		}

		int[] poly2 = timesX(eval(res2));
		res1.add(poly2);
		return res1;
	}
	
	int[] timesX(int[] poly) {
		int[] ret = new int[poly.length + 1];
		System.arraycopy(poly, 0, ret, 1, poly.length);
		return ret;
	}

	void submit() {
		int n = nextInt();
		long x = nextLong();

		next = new int[2 * n - 2];
		to = new int[2 * n - 2];
		head = new int[n];
		Arrays.fill(head, -1);

		for (int i = 0; i < n - 1; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			next[2 * i] = head[v];
			to[2 * i] = u;
			head[v] = 2 * i;

			next[2 * i + 1] = head[u];
			to[2 * i + 1] = v;
			head[u] = 2 * i + 1;
		}

		sz = new int[n];

		int[] res = eval(dfs(0, -1));

		int[] inv = new int[n + 1];
		inv[1] = 1;
		for (int i = 2; i < inv.length; i++) {
			inv[i] = P - (int) ((long) (P / i) * inv[P % i] % P);
		}
		
		int coef = 1;
		int outp = 0;
		for (int i = 1; i <= n; i++) {
			outp += (int)((long)res[i] * coef % P);
			if (outp >= P) {
				outp -= P;
			}
			coef = (int)((x + i) % P * coef % P * inv[i] % P);
		}
		
		out.println(outp);
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

	public static int[] naiveMult(int[] a, int[] b, int m) {
		int[] c = new int[a.length + b.length - 1];
		for (int k = 0; k < c.length; k++) {
			int lowI = Math.max(0, k - b.length + 1);
			int highI = Math.min(a.length - 1, k);
			long tmp = 0;
			for (int i = lowI; i <= highI; i++) {
				tmp += (long) a[i] * b[k - i];
				if (tmp >= P2) {
					tmp -= P2;
				}
			}
			c[k] = (int) (tmp % m);
		}
		return c;
	}

	public static int[] mult(int[] a, int[] b, int pMod) {

		if (a.length < C || b.length < C) {
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
			// long v0 = Math.round(invF[0][i]) % P;
			// long v1 = Math.round(invF[0][i + 1]) % P * L % P;
			// long v2 = Math.round(invF[1][i]) % P * L2 % P;
			long v0 = (long) (invF[0][i] + .5);
			long v1 = ((long) (invF[0][i + 1] + .5)) % pMod * k;
			long v2 = ((long) (invF[1][i] + .5)) % pMod * k2;
			ret[i >> 1] = (int) ((v0 + v1 + v2) % pMod);
		}

		int sz = ret.length;
		while (sz > 1 && ret[sz - 1] == 0) {
			sz--;
		}
		
		return Arrays.copyOf(ret, sz);
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

	F() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 40;

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