import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class G {
	void run() {
		in = new FastIn(System.in);
		out = new FastOut(System.out);

		submit();
		// stress();

		out.close();
		in.close();
	}

	long[] makeF(long[] a) {
		long[] b = new long[a.length - 2];
		for (int i = 0; i < b.length; i++) {
			b[i] = a[i] + 2 * a[i + 1] + a[i + 2];
		}
		return b;
	}

	long[] unique(long[] a) {
		Arrays.sort(a);
		int sz = 0;
		for (int i = 0; i < a.length; i++) {
			if (sz == 0 || a[i] != a[i - 1]) {
				a[sz++] = a[i];
			}
		}
		return Arrays.copyOf(a, sz);
	}

	int[][] buildG(long[] arr, HashMap<Long, Integer> map, int sz) {
		int[] b = new int[arr.length];
		int[] deg = new int[sz];
		for (int i = 0; i < arr.length; i++) {
			deg[b[i] = map.get(arr[i])]++;
		}
		int[][] g = new int[sz][];
		for (int i = 0; i < sz; i++) {
			g[i] = new int[deg[i]];
		}
		for (int i = arr.length - 1; i >= 0; i--) {
			int c = b[i];
			g[c][--deg[c]] = i;
		}
		return g;
	}

	void clearBS(long[] bs, int[] arr) {
		for (int x : arr) {
			bs[x >> LOG] = 0;
		}
	}

	void setBS(long[] bs, int[] arr) {
		for (int x : arr) {
			bs[x >> LOG] |= 1L << (x & MASK);
		}
	}

	long sum(long low, long cnt) {
		return cnt * (low + low + cnt - 1) / 2;
	}

	ArrayList<Integer> goPair(long d0, long d1, int pos) {
		long diff = d1 + d0;
		int totPos = (pos + 3) / 2;
		int totNeg = (pos + 2) / 2;
		if (!(-totNeg <= diff && diff <= totPos)) {
			return null;
		}
		int take = (int) (totPos - diff);
		long base = -(long) totPos * (totPos - 1);
		long low = base + sum(0, take);
		long high = base + sum(pos + 2 - take, take);
		if (!(low <= d0 && d0 <= high)) {
			return null;
		}

		long left = d0 - low;
		int deltaOne = pos + 2 - take;
		boolean[] ok = new boolean[pos + 2];
		for (int i = take - 1; i >= 0; i--) {
			int delta = (int) Math.max(Math.min(left, deltaOne), 0);
			ok[i + delta] = true;
			left -= delta;
		}

		ArrayList<Integer> ret = new ArrayList<>();

		for (int i = 0; i < pos + 2; i++) {
			if ((i % 2 == 0) != ok[i]) {
				ret.add(pos + 1 - i);
			}
		}
		return ret;
	}

	void solve(long[] t, long[] p, int tstCase) {
//		if (tstCase == 2278) {
//			for (int i = 0; i < p.length; i++) {
//				out.print(p[i]).print("_");
//			}
//			out.println();
////			throw new AssertionError(Arrays.toString(t));
////			out.println("-1");
////			return;
//		}
		long[] ft = makeF(t);
		long[] fp = makeF(p);
//		System.err.println(Arrays.toString(ft));
//		System.err.println(Arrays.toString(fp));
		for (int i = 0; i < ft.length; i++) {
			ft[i] *= -1;
		}
		for (int i = 0; i < fp.length; i++) {
			fp[i] *= -1;
		}
		long[] all = Arrays.copyOf(ft, ft.length + fp.length);
		System.arraycopy(fp, 0, all, ft.length, fp.length);
		all = unique(all);
		HashMap<Long, Integer> map = new HashMap<>();
		int last = -1;
		for (int i = 0; i < all.length; i++) {
			if (i != 0 && all[i] > all[i - 1] + 1) {
				last += 2;
			} else {
				last++;
			}
			map.put(all[i], last);
		}

		int[][] gt = buildG(ft, map, last + 2);
		int[][] gp = buildG(fp, map, last + 2);

		long[] bs = new long[(t.length >> LOG) + 2];
		long[] ans = new long[bs.length];
		Arrays.fill(ans, -1);

		for (int i = 0; i <= last; i++) {
			if (gp[i].length == 0) {
				continue;
			}
			for (int x : gt[i]) {
				bs[x >> LOG] |= 1L << (x & MASK);
			}
			for (int x : gt[i + 1]) {
				bs[x >> LOG] |= 1L << (x & MASK);
			}

			for (int pos : gp[i]) {
				int rem = pos & MASK;
				if (rem == 0) {
					for (int j = 0; (j << LOG) + pos < ft.length; j++) {
						int idx = ((j << LOG) + pos) >> LOG;
						ans[j] &= bs[idx] >>> rem;
					}
				} else {
					for (int j = 0; (j << LOG) + pos < ft.length; j++) {
						int idx = ((j << LOG) + pos) >> LOG;
						ans[j] &= (bs[idx] >>> rem) | (bs[idx + 1] << (SIZE - rem));
					}
				}
			}

			for (int x : gt[i]) {
				bs[x >> LOG] = 0;
			}
			for (int x : gt[i + 1]) {
				bs[x >> LOG] = 0;
			}
		}

//		for (int i = 0; i < ft.length; i++) {
//			ft[i] *= -1;
//		}
//		for (int i = 0; i < fp.length; i++) {
//			fp[i] *= -1;
//		}

		for (int i = 0; i < t.length - p.length + 1; i++) {
			if (!isSet(ans, i)) {
				continue;
			}
			ArrayList<Integer> outp = goPair(p[0] - t[i], p[1] - t[i + 1], i);
			if (outp != null) {
				for (int j = i + 2; j < i + p.length; j++) {
					long diff = ft[j - 2] - fp[j - i - 2];
					if (diff < 0 || diff > 1) {
						throw new AssertionError();
					}
					if (diff == 1) {
						outp.add(j);
					}
				}
				out.println(outp.size());
				for (int x : outp) {
					out.print(x + 1).print(' ');
				}
				out.println();
				return;
			}
		}
		out.println(-1);
	}

	boolean isSet(long[] bs, int i) {
		return ((bs[i >> LOG] >> (i & MASK)) & 1) == 1;
	}

	long getWord(long[] bs, int i) {
		int rem = i & MASK;
		int idx = i >> LOG;

		return (bs[idx] >>> rem) | (rem == 0 ? 0 : (bs[idx + 1] << (SIZE - rem)));
	}

	static final int LOG = 6;
	static final int MASK = (1 << LOG) - 1;
	static final int SIZE = 1 << LOG;

	void submit() {
		int t = in.nextInt();
		for (int j = 1; j <= t; j++) {
			int n = in.nextInt();
			long[] a = new long[n];
			for (int i = 0; i < n; i++) {
				a[i] = in.nextLong();
			}
			int m = in.nextInt();
			long[] b = new long[m];
			for (int i = 0; i < m; i++) {
				b[i] = in.nextLong();
			}
			solve(a, b, j);
		}
	}

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
		new G().run();
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