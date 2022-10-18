import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class cf745F_new {
	void run() throws IOException {
		in = new FastIn(System.in);
		out = new FastOut(System.out);

		submit();
//		stress();

		out.close();
		in.close();
	}

	static final int P = 998_244_353;
	static final int PRIM_ROOT = 3;
	static final long P_SQ = (long) P * P;

	static int[] inv = new int[100_010];
	static {
		inv[1] = 1;
		for (int x = 2; x < inv.length; x++) {
			inv[x] = P - (int) ((long) (P / x) * inv[P % x] % P);
		}
	}

	static int[] piePoly(int n, int m) {
		int[] p = new int[n + 1];
		p[0] = P - 1;
		for (int i = 1; i <= n; i++) {
			// can multiply by negative shit but only if it's already 0
			p[i] = (int) ((long) p[i - 1] * (m + i) % P * (m + 1 - i) % P * inv[2 * i] % P * inv[2 * i - 1] % P);
		}
		p[0] = 0;
		return p;
	}

	void submit() {
		int n = in.nextInt();
		int m = in.nextInt();

		if (n % 2 == 0) {
			int[] p = piePoly(n / 2, m);

			int[] first = p.clone();
			for (int i = 1; i <= n / 2; i++) {
				first[i] = (int) ((long) first[i] * i % P);
			}

			p[0] = 1;
			for (int i = 1; i < p.length; i++) {
				p[i] = p[i] == 0 ? 0 : P - p[i];
			}

			int[] ans = mult(first, invert(p));
			int ret = n / 2 < ans.length ? ans[n / 2] : 0;
			if (n / 2 % 2 == 1 && ret > 0) {
				ret = P - ret;
			}

			out.println(ret);
			return;
		}

		int[] p = piePoly(n / 2, m / 2);

		int[] first = new int[n / 2 + 2];
		int s = m / 2;
		first[1] = s == 0 ? 0 : P - s;
		for (int i = 2; i <= n / 2 + 1; i++) {
			first[i] = (int) ((long) first[i - 1] * (s - 1 + i) % P * (s + 1 - i) % P * inv[2 * i - 1] % P
					* inv[2 * i - 2] % P);
		}

		p[0] = 1;
		for (int i = 1; i < p.length; i++) {
			p[i] = p[i] == 0 ? 0 : P - p[i];
		}

		int[] oddChains = mult(first, invert(p));
		if (oddChains.length < 2) {
			oddChains = Arrays.copyOf(oddChains, 2);
		}
		if (m % 2 == 1) {
			oddChains[1] = P - (m / 2 + 1);
		}

		int[] q = new int[n + 1];
		for (int i = 1; i <= n && i / 2 + 1 < oddChains.length; i += 2) {
			q[i] = oddChains[i / 2 + 1];
			if (i / 2 % 2 == 0 && q[i] != 0) {
				q[i] = P - q[i];
			}
		}

		int[] fq = q.clone();
		for (int i = 1; i <= n; i++) {
			fq[i] = (int) ((long) fq[i] * i % P);
		}

		q[0] = 1;
		for (int i = 1; i <= n; i++) {
			if (q[i] != 0) {
				q[i] = P - q[i];
			}
		}

		int[] ans = mult(fq, invert(q));
		out.println(ans[n]);
	}

	static final int POWER_OF_2_THRESHOLD = 1 << 7;

	static int[] mult(int[] a, int[] b) {
		return Math.min(a.length, b.length) <= POWER_OF_2_THRESHOLD ? multNaive(a, b) : multFFT(a, b);
	}

	static int[] multNaive(int[] a, int[] b) {
		int[] c = new int[a.length + b.length - 1];
		for (int i = 0; i < c.length; i++) {
			long tmp = 0;
			for (int k = Math.max(0, i + 1 - b.length); k <= Math.min(a.length - 1, i); k++) {
				tmp += (long) a[k] * b[i - k];
				if (tmp >= P_SQ) {
					tmp -= P_SQ;
				}
			}
			c[i] = (int) (tmp % P);
		}
		return c;
	}

	static int[] multFFT(int[] a, int[] b) {
		int k = nextPowerOf2(a.length + b.length - 1);
		long[] fA = new long[k];
		long[] fB = new long[k];
		for (int i = 0; i < a.length; i++) {
			fA[i] = a[i];
		}
		for (int i = 0; i < b.length; i++) {
			fB[i] = b[i];
		}

		FFT(fA, false);
		FFT(fB, false);

		for (int i = 0; i < k; i++) {
			fA[i] = fA[i] * fB[i] % P;
		}

		FFT(fA, true);

		int[] c = new int[a.length + b.length - 1];
		for (int i = 0; i < c.length; i++) {
			c[i] = (int) fA[i];
		}
		return c;
	}

	static int[] invert(int[] p) {
		int[] q = new int[p.length];
		q[0] = pow(p[0], P - 2);
		int k = 1;

		for (; k < Math.min(POWER_OF_2_THRESHOLD, p.length); k++) {
			long sum = 0;
			for (int i = 0; i < k; i++) {
				sum += (long) q[i] * p[k - i];
				if (sum >= P_SQ) {
					sum -= P_SQ;
				}
			}
			sum = sum % P * q[0] % P;
			if (sum != 0) {
				q[k] = P - (int) sum;
			}
		}

		for (; k < p.length; k *= 2) {
			invertStep(q, p, k);
		}

		return q;
	}

	// q -= q(pq-1)
	static void invertStep(int[] q, int[] p, int k) {
		int n = Math.min(2 * k, p.length); // ignore p's x^n and above terms

		long[] fP = new long[2 * k];
		long[] fQ = new long[2 * k];
		for (int i = 0; i < k; i++) {
			fQ[i] = q[i];
		}
		for (int i = 0; i < n; i++) {
			fP[i] = p[i];
		}

		FFT(fQ, false);
		FFT(fP, false);

		for (int i = 0; i < 2 * k; i++) {
			fP[i] = fP[i] * fQ[i] % P;
		}

		FFT(fP, true);
		// The first k terms are now actually (PQ)'s x^(2k) and above terms, we must
		// ignore/clear them.

		System.arraycopy(fP, k, fP, 0, n - k);
		Arrays.fill(fP, n - k, 2 * k, 0);

		FFT(fP, false);
		for (int i = 0; i < 2 * k; i++) {
			fP[i] = fP[i] * fQ[i] % P;
		}

		FFT(fP, true);

		for (int i = k; i < n; i++) {
			int c = (int) fP[i - k];
			if (c != 0) {
				q[i] = P - c;
			}
		}
	}

	static int nextPowerOf2(int x) {
		return x == 1 ? 1 : Integer.highestOneBit(x - 1) << 1;
	}

	static int pow(int a, int b) {
		long ret = 1;
		for (; b > 0; b >>= 1) {
			if ((b & 1) == 1) {
				ret = ret * a % P;
			}
			a = (int) ((long) a * a % P);
		}
		return (int) ret;
	}

	static private void bitReverseShuffle(long[] a) {
		for (int i = 0, j = 0, n = a.length; i < n; ++i) {
			if (i > j) {
				long tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			for (int bit = n >> 1; (j ^= bit) < bit; bit >>= 1)
				;
		}
	}

	static private void FFT(long[] a, boolean inverse) {
		long[] magic;
		if (!inverse) {
			magic = magicForw;
		} else {
			magic = magicInv;
			bitReverseShuffle(a);
		}
		int n = a.length;
		int log = Integer.numberOfTrailingZeros(n);

		for (int lvl = 0; lvl < log; lvl++) {
			int blockCnt = 1 << lvl, halfBlock = 1 << (log - lvl - 1);
			long now = 1;
			if (lvl % 8 == 7) {
				for (int s = 0; s < blockCnt; s++) {
					int blockStart = s << (log - lvl);
					for (int i = blockStart; i < blockStart + halfBlock; i++) {
						long l = a[i];
						long r = a[i + halfBlock] * now % P;
						a[i] = (l + r) % P;
						a[i + halfBlock] = (l - r + P) % P;
					}
					now = now * magic[Integer.numberOfTrailingZeros(~s)] % P;
				}
			} else {
				for (int s = 0; s < blockCnt; s++) {
					int blockStart = s << (log - lvl);
					for (int i = blockStart; i < blockStart + halfBlock; i++) {
						long l = a[i];
						long r = a[i + halfBlock] * now % P;
						a[i] = l + r;
						a[i + halfBlock] = l - r + P;
					}
					now = now * magic[Integer.numberOfTrailingZeros(~s)] % P;
				}
			}
		}

		if (!inverse) {
			for (int i = 0; i < n; i++) {
				a[i] %= P;
			}
		} else {
			int invN = pow(n, P - 2);
			for (int i = 0; i < n; i++) {
				a[i] = a[i] % P * invN % P;
			}
			bitReverseShuffle(a);
		}
	}

	static long[] sumE(int mod, int g) {
		long[] sum_e = new long[30];
		long[] es = new long[30];
		long[] ies = new long[30];
		int cnt2 = Integer.numberOfTrailingZeros(mod - 1);
		long e = pow(g, (mod - 1) >> cnt2);
		long ie = pow((int) e, P - 2);
		for (int i = cnt2; i >= 2; i--) {
			es[i - 2] = e;
			ies[i - 2] = ie;
			e = e * e % mod;
			ie = ie * ie % mod;
		}
		long now = 1;
		for (int i = 0; i < cnt2 - 2; i++) {
			sum_e[i] = es[i] * now % mod;
			now = now * ies[i] % mod;
		}
		return sum_e;
	}

	static long[] magicForw = sumE(P, PRIM_ROOT);
	static long[] magicInv = sumE(P, pow(PRIM_ROOT, P - 2));

	void stress() {
		for (int tst = 0;; tst++) {
			if (false) {
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new cf745F_new().run();
	}

	FastIn in;
	FastOut out;

	static final int BUF_SZ = 1 << 14;

	static class FastIn {

		private InputStream is;

		public FastIn(InputStream is) {
			this.is = is;
		}

		private byte[] buf = new byte[BUF_SZ];
		private int sz = 0, ptr = 0;
		private ByteArrayOutputStream tokBuf = new ByteArrayOutputStream(BUF_SZ);

		int nextInt() {
			return (int) nextLong();
		}

		long nextLong() {
			long ret = 0;
			int b = scanNonTrash();
			if (b != '-' && !isDigit(b - '0')) {
				throw new InputMismatchException();
			}
			boolean neg = false;
			if (b == '-') {
				neg = true;
				b = scanByte();
			}
			for (;; b = scanByte()) {
				int d = b - '0';
				if (isDigit(d)) {
					ret = ret * 10 + d;
				} else {
					if (b != -1 && !isTrash(b)) {
						throw new InputMismatchException();
					}
					return neg ? -ret : ret;
				}
			}
		}

		String nextToken() {
			tokBuf.reset();
			for (int b = scanNonTrash(); !isTrash(b); b = scanByte()) {
				tokBuf.write(b);
			}
			return tokBuf.toString();
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		char nextChar() {
			return (char) scanNonTrash();
		}

		boolean sawEoF() {
			return sz < 0;
		}

		void close() {
			try {
				is.close();
			} catch (IOException e) {
				throw new UncheckedIOException(e);
			}
		}

		private boolean isDigit(int d) {
			return d >= 0 && d < 10;
		}

		private int scanByte() {
			if (ptr < sz) {
				return buf[ptr++];
			}
			if (sawEoF()) {
				throw new UncheckedIOException("Reading past EoF", new EOFException());
			}
			ptr = 0;
			try {
				sz = is.read(buf);
			} catch (IOException e) {
				throw new UncheckedIOException(e);
			}
			return sz > 0 ? buf[ptr++] : -1;
		}

		private boolean isTrash(int c) {
			return c < 33 || c > 126;
		}

		private int scanNonTrash() {
			int b;
			while ((b = scanByte()) != -1 && isTrash(b))
				;
			return b;
		}
	}

	static class FastOut {

		private OutputStream os;

		public FastOut(OutputStream os) {
			this.os = os;
			try {
				strField = String.class.getDeclaredField("value");
				strField.setAccessible(true);
				Object strValue = strField.get("");
				if (strValue instanceof byte[]) {
					j9Plus = true;
				} else if (strValue instanceof char[]) {
					j9Plus = false;
				} else {
					throw new RuntimeException("Weird string");
				}
			} catch (NoSuchFieldException | SecurityException | IllegalArgumentException | IllegalAccessException e) {
				throw new RuntimeException("String reflection problem", e);
			}
		}

		private final java.lang.reflect.Field strField;
		private final boolean j9Plus;

		private byte[] buf = new byte[2 * BUF_SZ];
		private int ptr = 0;

		FastOut print(long x) {
			int d;
			if (x < 0) {
				if (x == Long.MIN_VALUE) {
					return print(x / 10).print('8');
				}
				d = strLen(x = -x);
				buf[ptr++] = '-';
			} else {
				d = strLen(x);
			}
			for (int i = ptr += d; d > 0; x /= 10, --d) {
				buf[--i] = (byte) ('0' + (x % 10));
			}
			return maybeBufFlush();
		}

		FastOut print(char c) {
			buf[ptr++] = (byte) c;
			return maybeBufFlush();
		}

		FastOut print(String s) {
			Object value;
			try {
				value = strField.get(s);
				if (j9Plus) {
					print((byte[]) value);
				} else {
					print((char[]) value);
				}
			} catch (IllegalArgumentException | IllegalAccessException e) {
				throw new RuntimeException("String reflection problem", e);
			}
			return this;
		}

		FastOut println(long x) {
			return print(x).println();
		}

		FastOut println(String s) {
			return print(s).println();
		}

		FastOut println() {
			return print('\n');
		}

		void flush() {
			bufFlush();
			try {
				os.flush();
			} catch (IOException e) {
				throw new UncheckedIOException(e);
			}
		}

		void close() {
			flush();
			try {
				os.close();
			} catch (IOException e) {
				throw new UncheckedIOException(e);
			}
		}

		private FastOut maybeBufFlush() {
			if (ptr >= BUF_SZ) {
				bufFlush();
			}
			return this;
		}

		private void bufFlush() {
			try {
				os.write(buf, 0, ptr);
				ptr = 0;
			} catch (IOException e) {
				throw new UncheckedIOException(e);
			}
		}

		private void print(byte[] bytes) {
			int n = bytes.length;
			if (ptr + n >= BUF_SZ) {
				bufFlush();
				try {
					os.write(bytes);
				} catch (java.io.IOException e) {
					throw new java.io.UncheckedIOException(e);
				}
			} else {
				System.arraycopy(bytes, 0, buf, ptr, n);
				ptr += n;
			}
		}

		private void print(char[] chars) {
			int i = 0, s;
			while ((s = Math.min(chars.length - i, BUF_SZ)) > 0) {
				while (s-- > 0) {
					buf[ptr++] = (byte) chars[i++];
				}
				maybeBufFlush();
			}
		}

		private static final int strLen(long x) {
			long p = 10;
			for (int i = 1; i < 19; i++) {
				if (x < p)
					return i;
				p *= 10;
			}
			return 19;
		}

	}

}