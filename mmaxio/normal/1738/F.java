import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class F {
	void run() {
		in = new FastIn(System.in);
		out = new FastOut(System.out);

		submit();
		// stress();

		out.close();
		in.close();
	}
	
	static class Node implements Comparable<Node> {
		int id, deg;

		public Node(int id, int deg) {
			this.id = id;
			this.deg = deg;
		}

		@Override
		public int compareTo(Node o) {
			if (deg != o.deg) {
				return deg < o.deg ? -1 : 1;
			}
			return Integer.compare(id, o.id);
		}
	}
	
	void solve() {
		int n = in.intt();
		TreeSet<Node> nodes = new TreeSet<>();
		Node[] arr = new Node[n];
		for (int i = 0; i < n; i++) {
			int d = in.intt();
			arr[i] = new Node(i, d);
			nodes.add(arr[i]);
		}
		
		ArrayList<Node>[] comps = new ArrayList[n];
		int[] who = new int[n];
		Arrays.fill(who, -1);
		
		while (!nodes.isEmpty()) {
			Node v = nodes.pollLast();
			comps[v.id] = new ArrayList<>();
			comps[v.id].add(v);
			who[v.id] = v.id;
			for (int i = 0; i < v.deg; i++) {
				out.sprint('?').nprint(v.id + 1).flush();
				int u = in.intt() - 1;
				if (nodes.remove(arr[u])) {
					comps[v.id].add(arr[u]);
					who[u] = v.id;
				} else {
					int merge = who[u];
					for (Node member : comps[v.id]) {
						who[member.id] = merge;
					}
					comps[merge].addAll(comps[v.id]);
					comps[v.id] = null;
					break;
				}
			}
		}
		
		int[] cols = new int[n];
		int last = 1;
		for (int i = 0; i < n; i++) {
			if (comps[i] == null) {
				continue;
			}
			for (Node v : comps[i]) {
				cols[v.id] = last;
			}
			last++;
		}
		out.sprint('!');
		for (int i = 0; i < n; i++) {
			out.sprint(cols[i]);
		}
		out.nprint().flush();
	}

	void submit() {
		int t = in.intt();
		while (t-- > 0) {
			solve();
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
		new F().run();
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
		
		FastOut sprint(char c) {
			return print(c).sprint();
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