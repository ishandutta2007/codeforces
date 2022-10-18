import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class D {
	void run() {
		in = new FastIn(System.in);
		out = new FastOut(System.out);

		submit();
		// stress();

		out.close();
		in.close();
	}

	void solve(int[] a) {
		int n = a.length;
		int[] atMost = new int[n + 2];
		for (int x : a) {
			atMost[x]++;
		}
		for (int k = 0; k <= n; k++) {
			if (k > 0) {
				atMost[k] += atMost[k - 1];
			}
			if (atMost[k] == n - k) {
				out.nprint(k);
				
				if (k == 0 || k == n) {
					for (int i = 1; i <= n; i++) {
						out.sprint(i);
					}
					out.nprint();
					return;
				}

				boolean[] seen = new boolean[n + 2];
				for (int x : a) {
					if (x != 0 && x != n + 1) {
						seen[x - 1] = true;
					}
				}

				ArrayList<Integer>[] who = new ArrayList[n];
				for (int i = 0; i < n; i++) {
					who[i] = new ArrayList<>();
				}
				for (int i = 0; i < n; i++) {
					if (a[i] != 0 && a[i] != n + 1) {
						who[a[i] - 1].add(i);
					}
				}
				
				boolean[] checkedA = new boolean[n];

				int init = -1;
				findInit: for (int i = 0; i < n; i++) {
					if (seen[i] || a[i] == 0 || a[i] == n + 1) {
						continue;
					}
					int kek = a[i] - 1;
					if (checkedA[kek]) {
						continue;
					}
					checkedA[kek] = true;
					for (int v : who[kek]) {
						if (seen[v]) {
							continue findInit;
						}
					}
					init = i;
					break;
				}

				ArrayList<Integer> ans = new ArrayList<>();

				while (true) {
					ans.add(init);
					int before = a[init];
					if (before == 0 || before == n + 1) {
						break;
					}
					before--;
					for (int v : who[before]) {
						if (v != init) {
							ans.add(v);
						}
					}
					init = before;
				}
				
//				System.err.println(init);
//				System.err.println(ans);
				
				for (int i = 0; i < n; i++) {
					if (init != i && (a[i] == 0 || a[i] == n + 1)) {
						ans.add(i);
					}
				}

				Collections.reverse(ans);
				for (int x : ans) {
					out.sprint(x + 1);
				}
				out.nprint();

			}
		}
	}

	void submit() {
		int t = in.intt();
		while (t-- > 0) {
			int n = in.intt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = in.intt();
			}
			solve(a);
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
		new D().run();
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