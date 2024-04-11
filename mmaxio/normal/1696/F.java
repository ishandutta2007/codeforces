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
	
	static class DSU {
		
		private int[] p; // p[v] >= 0 is a parent of v
						 // p[v] < 0 means v is a root with size of (-p[v])
		
		public DSU(int n) {
			p = new int[n];
			Arrays.fill(p, -1);
		}
		
		int get(int v) {
			return p[v] < 0 ? v : (p[v] = get(p[v]));
		}
		
		int getSize(int v) {
			v = get(v);
			return -p[v];
		}
		
		boolean union(int v, int u) {
			v = get(v);
			u = get(u);
			if (v == u) {
				return false;
			}
			if (p[v] > p[u]) {
				int tmp = v;
				v = u;
				u = tmp;				
			}
			p[v] += p[u];
			p[u] = v;
			return true;
		}
	}

	int pair(int i, int j) {
		if (i > j) {
			int tmp = i;
			i = j;
			j = tmp;
		}
		return j * (j - 1) / 2 + i;
	}
	
	boolean valid(ArrayList<Integer> tree, boolean[][][] g) {
		int n = g.length;
		int[][] d = new int[n][n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(d[i], INF);
			d[i][i] = 0;
		}
		
		for (int i = 0; i < n - 1; i++) {
			int v = tree.get(2 * i);
			int u = tree.get(2 * i + 1);
			d[v][u] = d[u][v] = 1;
		}
		
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][j] == INF) {
					return false;
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (g[i][j][k] != (d[i][k] == d[j][k])) {
						return false;
					}
				}
			}
		}
		return true;
	}
	
	static final int INF = 100000000;
	
	ArrayList<Integer> solve(boolean[][][] g) {
		int n = g.length;
		DSU dsu = new DSU(n * n);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (g[i][j][k]) {
						dsu.union(pair(i, k), pair(j, k));
					}
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int p = pair(i, j);
				if (dsu.get(p) != p) {
					continue;
				}
				if (dsu.getSize(p) != n - 1) {
					continue;
				}
				
				ArrayList<Integer> tree = new ArrayList<>(2 * n - 2);
				
				for (int x = 0; x < n; x++) {
					for (int y = x + 1; y < n; y++) {
						if (dsu.get(pair(x, y)) == p) {
							tree.add(x);
							tree.add(y);
						}
					}
				}
				
				if (tree.size() != 2 * n - 2) {
					throw new AssertionError();
				}
				
				if (valid(tree, g)) {
					return tree;
				}
			}
		}
		return null;
	}

	void submit() {
		int t = in.nextInt();
		while (t-- > 0) {
			int n = in.nextInt();
			boolean[][][] g = new boolean[n][n][n];
			for (int i = 0; i < n - 1; i++) {
				for (int j = i + 1; j < n; j++) {
					String s = in.nextToken();
					for (int k = 0; k < n; k++) {
						g[i][j][k] = g[j][i][k] = s.charAt(k) == '1';
					}
				}
			}
			ArrayList<Integer> ans = solve(g);
			if (ans == null) {
				out.println("No");
			} else {
				out.println("Yes");
				for (int i = 0; i < n - 1; i++) {
					out.print(ans.get(2 * i) + 1).print(' ').println(ans.get(2 * i + 1) + 1);
				}
			}
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