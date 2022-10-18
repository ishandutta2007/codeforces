import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class E {
	void run() {
		in = new FastIn(System.in);
		out = new FastOut(System.out);

		submit();
		// stress();

		out.close();
		in.close();
	}

	int[][] buildDGraph(int[] a, int n, int m) {
		if (m == 0) {
			if (a.length == 0) {
				return new int[n][0];
			} else {
				throw new AssertionError();
			}
		}
		if (a.length % m != 0 || a.length < 2 * m) {
			throw new AssertionError("Bad array length");
		}

		int[] deg = new int[n];
		int s = a.length / m;
		for (int i = 0; i < a.length; i += s) {
			deg[a[i]]++;
		}

		int[][] g = new int[n][];
		for (int i = 0; i < n; i++) {
			g[i] = new int[deg[i] * (s - 1)];
		}

		for (int i = s * (m - 1); i >= 0; i -= s) {
			int v = a[i];
			int u = a[i + 1];
			int pv = (--deg[v]) * (s - 1);
			g[v][pv] = u;
			System.arraycopy(a, i + 2, g[v], pv + 1, s - 2);
		}

		return g;
	}

	static final int P = 998244353;

	static class Segm implements Comparable<Segm> {
		int start;
		int len;
		boolean infLen;

		public Segm(int start, int len, boolean infLen) {
			this.start = start;
			this.len = len;
			this.infLen = infLen;
		}

		@Override
		public int compareTo(Segm o) {
			return Integer.compare(start, o.start);
		}

		@Override
		public String toString() {
			return "Segm [start=" + start + ", len=" + len + ", infLen=" + infLen + "]";
		}
	}

	ArrayList<Segm> dfs(int v, int[][] g, int[] a) {
		if (cache[v] != null) {
			return cache[v];
		}
		ArrayList<Segm> tmp = new ArrayList<>();
		if (a[v] > 0) {
			tmp.add(new Segm(0, a[v], false));
		}
		for (int u : g[v]) {
			ArrayList<Segm> add = dfs(u, g, a);
			for (Segm s : add) {
//				s.start++;
				tmp.add(new Segm(s.start + 1, s.len, s.infLen));
			}
		}
		Collections.sort(tmp);
		ArrayList<Segm> ret = new ArrayList<>(tmp.size());
		Segm last = null;
		for (Segm s : tmp) {
			if (last == null) {
				last = new Segm(s.start, s.len, s.infLen);
				continue;
			}
			if (last.infLen || last.start + last.len >= s.start) {
				last.len += s.len;
				last.infLen |= s.infLen;
				last.infLen |= last.len > 1_000_000;
				last.len %= P;
			} else {
				ret.add(last);
				last = new Segm(s.start, s.len, s.infLen);
			}
		}
		if (last != null) {
			ret.add(last);
		}
		return cache[v] = ret;
	}
	
	void dfsOrder(int v, ArrayList<Integer> order, boolean[] vis, int[][] g) {
		vis[v] = true;
		for (int u : g[v]) {
			if (!vis[u]) {
				dfsOrder(u, order, vis, g);
			}
		}
		order.add(v);
	}
	
	ArrayList<Segm>[] cache;

	int solve(int n, int m, int[] a, int[] es) {
		int[] outg = new int[n];
		for (int i = 0; i < 2 * m; i += 2) {
			outg[es[i]]++;
			int tmp = es[i];
			es[i] = es[i + 1];
			es[i + 1] = tmp;
		}
		int[][] g = buildDGraph(es, n, m);
		int root = -1;
		for (int i = 0; i < n; i++) {
			if (outg[i] == 0) {
				root = i;
			}
		}
		
		ArrayList<Integer> order = new ArrayList<>(n);
		boolean[] vis = new boolean[n];
		dfsOrder(root, order, vis, g);
		
		cache = new ArrayList[n];
		for (int v : order) {
			dfs(v, g, a);
//			System.err.println(v + " " + cache[v]);
		}
		ArrayList<Segm> ans = dfs(root, g, a);
		if (ans.isEmpty()) {
			return 0;
		}
		Segm last = ans.get(ans.size() - 1);
		return (last.start + last.len) % P;
	}

	void submit() {
		int t = in.nextInt();
		while (t-- > 0) {
			int n = in.nextInt();
			int m = in.nextInt();

			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = in.nextInt();
			}
			int[] es = new int[2 * m];
			for (int i = 0; i < 2 * m; i++) {
				es[i] = in.nextInt() - 1;
			}
			out.println(solve(n, m, a, es));
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
		new E().run();
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