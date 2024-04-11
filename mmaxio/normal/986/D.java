import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class D {

	static final int LOG = 1;
	static final int BASE = BigInteger.TEN.pow(LOG).intValue();

	void submit() {

		String s = nextToken();

		if (s.length() < 3) {
			int x = Integer.parseInt(s);
			if (x == 1) {
				out.println(1);
				return;
			}
			int ans = Integer.MAX_VALUE;
			int cur2 = 1;
			for (int b2 = 0; b2 < 3; b2++) {

				int val = cur2;
				int cur = 2 * b2;
				while (val < x) {
					val *= 3;
					cur += 3;
				}

				ans = Math.min(ans, cur);

				cur2 *= 2;
			}
			out.println(ans);
			return;
		}

		int len = (s.length() + LOG - 1) / LOG;

		int[] a = new int[len];
		for (int i = 0; i < len; i++) {
			int from = Math.max(s.length() - i * LOG - LOG, 0);
			int to = s.length() - i * LOG;
			a[i] = Integer.parseInt(s.substring(from, to));
		}

		int[] a2 = divide(a, 2);
		int[] a4 = divide(a2, 2);

		double apprLog = (a4.length - 1) * Math.log(BASE) / Math.log(3);
		apprLog -= 5;

		int pow = (int) Math.max(apprLog, 0);

		int[] base = go(pow);

		int ans = Integer.MAX_VALUE;

		while (less(base, a4)) {
			pow++;
			base = mulShort(base, 3);
		}

		ans = Math.min(ans, pow * 3 + 4);

		while (less(base, a2)) {
			pow++;
			base = mulShort(base, 3);
		}

		ans = Math.min(ans, pow * 3 + 2);
		
//		System.err.println(Arrays.toString(base));
//		System.err.println(pow);

		while (less(base, a)) {
			pow++;
			base = mulShort(base, 3);
		}

		ans = Math.min(ans, pow * 3);

		out.println(ans);
	}

	int[] mulShort(int[] a, int x) {
		int[] b = Arrays.copyOf(a, a.length + 1);
		int over = 0;
		for (int i = 0; i < b.length; i++) {
			b[i] = b[i] * x + over;
			over = b[i] / BASE;
			b[i] %= BASE;
		}
		if (over > 0) {
			throw new AssertionError();
		}
		return trim(b);
	}

	boolean less(int[] a, int[] b) {
		if (a.length != b.length) {
			return a.length < b.length;
		}
		int idx = a.length - 1;
		while (idx >= 0 && a[idx] == b[idx]) {
			idx--;
		}
		if (idx == -1) {
			return false;
		}
		return a[idx] < b[idx];
	}

	int[] go(int b) {
		int[] a = { 3 };
		int[] ret = { 1 };
		for (; b > 0; b >>= 1) {
			if ((b & 1) == 1) {
				ret = mult(ret, a);
			}
			a = mult(a, a);
		}
		return ret;
	}

	int[] add(int[] a, int x) {
		int[] b = Arrays.copyOf(a, a.length + 1);
		b[0] += x;
		int carry = 0;
		for (int i = 0; i < b.length; i++) {
			b[i] += carry;
			carry = b[i] / BASE;
			b[i] %= BASE;
		}
		if (carry != 0) {
			throw new AssertionError();
		}
		return trim(b);
	}
	
	int[] divide(int[] a, int x) {
		
		a = add(a, x - 1);
		
		int[] b = new int[a.length];
		int rem = 0;
		for (int i = a.length - 1; i >= 0; i--) {
			int num = a[i] + rem * BASE;
			b[i] = num / x;
			rem = num % x;
		}
		return trim(b);
	}

	static int[] trim(int[] a) {
		int len = a.length;
		if (a[len - 1] != 0) {
			return a;
		}
		while (len > 0 && a[len - 1] == 0) {
			len--;
		}
		return Arrays.copyOf(a, len);
	}

	static int nextPowerOf2(int x) {
		return x == 1 ? 1 : Integer.highestOneBit(x - 1) << 1;
	}

	public static int[] mult(int[] a, int[] b) {

		int len = nextPowerOf2(a.length + b.length - 1);
		int len2 = len * 2;

		double[] f = new double[len2];
		for (int i = 0; i < a.length; i++) {
			f[i << 1] = a[i];
		}
		for (int i = 0; i < b.length; i++) {
			f[i << 1 | 1] = b[i];
		}

		fft(f, false);

		// unpack
		double[] p = new double[len << 1];
		double[] q = new double[len << 1];

		// LEN MUST BE A POWER OF 2!!!
		int zzz = len2 - 1;
		for (int i = 0; i < len2; i += 2) {
			int j = (-i) & zzz;
			p[i] = .5 * (f[i] + f[j]);
			p[i + 1] = .5 * (f[i + 1] - f[j + 1]);
			q[i] = .5 * (f[i + 1] + f[j + 1]);
			q[i + 1] = .5 * (f[j] - f[i]);
		}

		double[] r = new double[len2];

		for (int i = 0; i < len2; i += 2) {
			r[i] += p[i] * q[i] - p[i + 1] * q[i + 1];
			r[i + 1] += p[i] * q[i + 1] + p[i + 1] * q[i];
		}

		fft(r, true);

		long[] ret = new long[len];

		for (int i = 0; i < len2; i += 2) {
			// long v0 = (long) (invF[0][i] + .5);
			// long v1 = ((long) (invF[0][i + 1] + .5)) % pMod * k;
			// long v2 = ((long) (invF[1][i] + .5)) % pMod * k2;
			// ret[i >> 1] = (int) ((v0 + v1 + v2) % pMod);
			ret[i >> 1] = (long) (r[i] + .5);
		}

		return trim(carry(ret));
	}

	static int[] carry(long[] ret) {
		long over = 0;
		int[] ir = new int[ret.length + 3];
		for (int i = 0; i < ir.length; i++) {
			// ret[i] += over;
			long cur = (i < ret.length ? ret[i] : 0);
			cur += over;
			over = cur / BASE;
			ir[i] = (int) (cur % BASE);
		}
		if (over > 0) {
			throw new AssertionError();
		}
		return ir;
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
		go(16);
	}

	void stress() {
		for (int tst = 0;; tst++) {
			if (false) {
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	D() throws IOException {
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
		new D();
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