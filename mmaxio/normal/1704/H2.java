import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class FasterRelaxed {
	void run() {
		in = new FastIn(System.in);
		out = new FastOut(System.out);

		submit();
		// stress();

		out.close();
		in.close();
	}

	static int P;
	static int PRIM_ROOT;
	static long P_SQ;

//	static final int THRESHOLD_LOG = 1;
	static final int THRESHOLD_LOG = 3;
	static final int THRESHOLD_POWER_OF_2 = 1 << THRESHOLD_LOG;

	abstract static class LazyPS {
		long[] d;
		int ptr = 0;
		int n;

		public LazyPS() {
		}

		public LazyPS(int n) {
			d = new long[n];
			this.n = n;
		}

		long get(int idx) {
			for (; ptr <= idx; ptr++) {
				d[ptr] = emit(ptr);
			}
			return d[idx];
		}

		abstract protected long emit(int idx);
	}

	static class Prod extends LazyPS {
		LazyPS a, b;

		public Prod(LazyPS a, LazyPS b, int n) {
			super(n);
			this.a = a;
			this.b = b;
			aBlocks = new long[21][];
			bBlocks = new long[21][];
		}

		long[][] aBlocks, bBlocks;

		@Override
		protected long emit(int idx) {
			a.get(idx);
			b.get(idx);
			int log = Integer.numberOfTrailingZeros(idx + 2);
			int k = 1 << log;
			if (k == idx + 2) {
				long[] blA = aBlocks[log] = new long[k];
				long[] blB = bBlocks[log] = new long[k];
				System.arraycopy(a.d, 0, blA, 0, k - 1);
				System.arraycopy(b.d, 0, blB, 0, k - 1);
				if (log < THRESHOLD_LOG) {
					smallWrite(blA, blB, 0, k - 1);
				} else {
					FFT(blA, false);
					FFT(blB, false);
					long[] buf = blA.clone();
					for (int i = 0; i < k; i++) {
						buf[i] = buf[i] * blB[i] % P;
					}
					FFT(buf, true);
					int iMax = Math.min(n, 2 * idx + 1);
					for (int i = idx; i < iMax; i++) {
						int bufIdx = i & (k - 1);
						long now = buf[bufIdx] - (i >= k ? d[bufIdx] : 0);
						long tmp = d[i] + (now < 0 ? now + P : now);
						d[i] = tmp >= P ? tmp - P : tmp;
					}
				}
			} else {
				if (log + 1 < THRESHOLD_LOG) {
					smallWrite(aBlocks[log + 1], b.d, idx - k + 1, k);
					smallWrite(bBlocks[log + 1], a.d, idx - k + 1, k);
				} else {
					long[] buf1 = new long[2 * k];
					long[] buf2 = new long[2 * k];
					System.arraycopy(b.d, idx - k + 1, buf1, 0, k);
					System.arraycopy(a.d, idx - k + 1, buf2, 0, k);
					FFT(buf1, false);
					FFT(buf2, false);
					long[] aBl = aBlocks[log + 1];
					long[] bBl = bBlocks[log + 1];
					for (int i = 0; i < 2 * k; i++) {
						buf1[i] = (buf1[i] * aBl[i] + buf2[i] * bBl[i]) % P;
					}
					FFT(buf1, true);
					int iMax = Math.min(2 * k - 1, n - (idx - k + 1));
					for (int i = k - 1; i < iMax; i++) {
						long tmp = d[idx - k + 1 + i] + buf1[i];
						d[idx - k + 1 + i] = tmp >= P ? tmp - P : tmp;
					}
				}
			}
			
			return d[idx];
		}
		
		private void smallWrite(long[] a, long[] b, int bOff, int bLen) {
			long[] d = this.d;
			int iMax = Math.min(n - bOff, 2 * bLen - 1);
			for (int i = bLen - 1; i < iMax; i++) {
				long delta = 0;
				int jMax = Math.min(i + 1, a.length);
				for (int j = Math.max(0, i + 1 - bLen); j < jMax; j++) {
					delta += a[j] * b[bOff + i - j];
					if (delta >= P_SQ) {
						delta -= P_SQ;
					}
				}
				d[i + bOff] = (d[i + bOff] + delta) % P;
			}
		}
	}

	static class Sum extends LazyPS {
		LazyPS a, b;

		public Sum(LazyPS a, LazyPS b, int sz) {
			super(sz);
			this.a = a;
			this.b = b;
		}

		@Override
		protected long emit(int idx) {
			long ret = a.get(idx) + b.get(idx);
			return ret >= P ? ret - P : ret;
		}
	}

	static class TimesZ extends LazyPS {
		LazyPS p;

		public TimesZ(LazyPS p, int sz) {
			super(sz);
			this.p = p;
		}

		@Override
		protected long emit(int idx) {
			return idx == 0 ? 0 : p.get(idx - 1);
		}
	}

	static class Diff extends LazyPS {
		LazyPS p;

		public Diff(LazyPS p, int sz) {
			super(sz);
			this.p = p;
		}

		@Override
		protected long emit(int idx) {
			return p.get(idx + 1) * (idx + 1) % P;
		}
	}

	static class Int extends LazyPS {
		LazyPS p;
		long c0;

		public Int(LazyPS p, int sz, long c0) {
			super(sz);
			this.p = p;
			this.c0 = c0;
		}

		@Override
		protected long emit(int idx) {
			return idx == 0 ? c0 : p.get(idx - 1) * inv[idx] % P;
		}
	}

	static class Eager extends LazyPS {
		public Eager(long[] p) {
			this.d = p.clone();
			n = p.length;
		}

		@Override
		protected long emit(int idx) {
			return d[idx];
		}
	}

	static class DivZ extends LazyPS {
		LazyPS p;

		public DivZ(LazyPS p, int sz) {
			super(sz);
			this.p = p;
		}

		@Override
		protected long emit(int idx) {
			return p.get(idx + 1);
		}
	}

	static class Division extends LazyPS {
		LazyPS p, q;
		long q0Inv;

		private LazyPS aux;

		public Division(LazyPS p, LazyPS q, int sz) {
			super(sz);
			this.p = p;
			this.q = q;
			aux = new Prod(this, new DivZ(q, sz), sz);
		}

		@Override
		protected long emit(int idx) {
			if (idx == 0) {
				q0Inv = pow((int) q.get(0), P - 2);
				return p.get(0) * q0Inv % P;
			}
			long tmp = p.get(idx) - aux.get(idx - 1);
			if (tmp < 0) {
				tmp += P;
			}
			return tmp * q0Inv % P;
		}
	}

	static LazyPS exp(LazyPS p, int n) {
		Int ret = new Int(null, n, 1);
		ret.p = new Prod(new Diff(p, n), ret, n);
		return ret;
	}

	static LazyPS log(LazyPS p, int n) {
		return new Int(new Division(new Diff(p, n), p, n), n, 0);
	}

	static int[] inv;

	void submit() {
		int n = in.intt() + 1;
		P = in.intt();
		P_SQ = (long) P * P;

		ArrayList<Integer> pds = new ArrayList<>();
		int ord = P - 1;
		for (int i = 2; i * i <= ord; i++) {
			if (ord % i == 0) {
				pds.add(i);
				while (ord % i == 0) {
					ord /= i;
				}
			}
		}
		if (ord > 1) {
			pds.add(ord);
		}

		outer: for (PRIM_ROOT = 2;; PRIM_ROOT++) {
			for (int pd : pds) {
				if (pow(PRIM_ROOT, (P - 1) / pd) == 1) {
					continue outer;
				}
			}
			break;
		}
		magicForw = sumE(P, PRIM_ROOT);
		magicInv = sumE(P, pow(PRIM_ROOT, P - 2));

		// calc PRIM_ROOT

		inv = new int[n + 10];
		inv[1] = 1;
		for (int x = 2; x < inv.length; x++) {
			inv[x] = P - (int) ((long) (P / x) * inv[P % x] % P);
		}

		TimesZ p = new TimesZ(null, n);
		TimesZ q = new TimesZ(exp(p, n), n);
		LazyPS pq = new Sum(p, q, n);
		LazyPS expPQ = exp(pq, n);

		p.p = new Prod(expPQ, pq, n);

		// You can cut the lazy crap from now on.

		LazyPS Pbad = new TimesZ(expPQ, n);
		LazyPS Pcycle = new Sum(p, Pbad, n);
		LazyPS Qcycle = new Prod(Pcycle, q, n);

		// i don't wanna make a class just to add a minus sign
		long[] logArg1 = new long[n];
		logArg1[0] = 1;
		for (int i = 1; i < n; i++) {
			long tmp = Pcycle.get(i) + Qcycle.get(i);
			if (tmp >= P) {
				tmp -= P;
			}
			logArg1[i] = tmp == 0 ? 0 : P - tmp;
		}

		LazyPS log1 = log(new Eager(logArg1), n);

		long[] ret1 = new long[n];
		for (int i = 0; i < n; i++) {
			long tmp = log1.get(i) + Pcycle.get(i);
			if (tmp >= P) {
				tmp -= P;
			}
			ret1[i] = tmp == 0 ? 0 : P - tmp;
		}

		long[] logArg2 = new long[n];
		logArg2[0] = 1;
		for (int i = 1; i < n; i++) {
			long tmp = Pbad.get(i);
			logArg2[i] = tmp == 0 ? 0 : P - tmp;
		}

		LazyPS log2 = log(new Eager(logArg2), n);

		long[] ret2 = new long[n];
		for (int i = 0; i < n; i++) {
			long tmp = log2.get(i) + Pbad.get(i);
			if (tmp >= P) {
				tmp -= P;
			}
			ret2[i] = tmp == 0 ? 0 : P - tmp;
		}

		long[] oneComp = new long[n];
		for (int i = 0; i < n; i++) {
			long tmp = ret1[i] - ret2[i];
			oneComp[i] = tmp < 0 ? tmp + P : tmp;
		}
		LazyPS ans = exp(new Eager(oneComp), n);

		long fact = 1;
		for (int i = 1; i < n; i++) {
			fact = fact * i % P;
			out.nprint(ans.get(i) * fact % P);
		}
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

	static long[] magicForw;
	static long[] magicInv;

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

	public static void main(String[] args) {
		new FasterRelaxed().run();
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

		int intt() {
			return (int) longg();
		}

		long longg() {
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

		String tokenn() {
			tokBuf.reset();
			for (int b = scanNonTrash(); !isTrash(b); b = scanByte()) {
				tokBuf.write(b);
			}
			return tokBuf.toString();
		}

		double doublee() {
			return Double.parseDouble(tokenn());
		}

		char charr() {
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
//			try {
//				strField = String.class.getDeclaredField("value");
//				strField.setAccessible(true);
//				Object strValue = strField.get("");
//				if (strValue instanceof byte[]) {
//					j9Plus = true;
//				} else if (strValue instanceof char[]) {
//					j9Plus = false;
//				} else {
//					throw new RuntimeException("Weird string");
//				}
//			} catch (NoSuchFieldException | SecurityException | IllegalArgumentException | IllegalAccessException e) {
//				throw new RuntimeException("String reflection problem", e);
//			}
		}

//		private final java.lang.reflect.Field strField;
//		private final boolean j9Plus;

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
			int i = 0, c;
			while ((c = Math.min(s.length() - i, BUF_SZ)) > 0) {
				while (c-- > 0) {
					buf[ptr++] = (byte) s.charAt(i++);
				}
				maybeBufFlush();
			}
			return this;
		}

		FastOut nprint(long x) {
			return print(x).nprint();
		}

		FastOut nprint(String s) {
			return print(s).nprint();
		}

		FastOut nprint() {
			return print('\n');
		}

		FastOut sprint(long x) {
			return print(x).sprint();
		}

		FastOut sprint(String s) {
			return print(s).sprint();
		}

		FastOut sprint() {
			return print(' ');
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
				} catch (IOException e) {
					throw new UncheckedIOException(e);
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