import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class C {
	void run() {
		in = new FastIn(System.in);
		out = new FastOut(System.out);

		submit();
		// stress();

		out.close();
		in.close();
	}
	
	ArrayList<Integer> reduce(int[] arr, int k) {
		ArrayList<Integer> ret = new ArrayList<>(arr.length * 2);
		int prv = -1;
		int[] buf = new int[60];
		for (int x : arr) {
			int a = x;
			int b = 0;
			while (a % k == 0) {
				a /= k;
				b++;
			}
			if (prv != a && prv != -1) {
				ret.add(prv);
				int last = -1;
				for (int i = 0; i < 60 - 1; i++) {
					int carry = buf[i] / k;
					buf[i + 1] += carry;
					buf[i] %= k;
					if (buf[i] != 0) {
						last = i;
					}
				}
				for (int i = 0; i <= last; i++) {
					ret.add(buf[i]);
					buf[i] = 0;
				}
			}
			
			prv = a;
			buf[b]++;
		}
		
		ret.add(prv);
		int last = -1;
		for (int i = 0; i < 60 - 1; i++) {
			int carry = buf[i] / k;
			buf[i + 1] += carry;
			buf[i] %= k;
			if (buf[i] != 0) {
				last = i;
			}
		}
		for (int i = 0; i <= last; i++) {
			ret.add(buf[i]);
			buf[i] = 0;
		}
		
		return ret;
	}
	
	void submit() {
		int t = in.nextInt();
		while (t-- > 0) {
			int n = in.nextInt();
			int k = in.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = in.nextInt();
			}
			int m = in.nextInt();
			int[] b = new int[m];
			for (int i = 0; i < m; i++) {
				b[i] = in.nextInt();
			}
			ArrayList<Integer> x = reduce(a, k);
			ArrayList<Integer> y = reduce(b, k);
			out.println(x.equals(y) ? "Yes" : "No");
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
		new C().run();
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