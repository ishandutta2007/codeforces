import java.io.*;
import java.math.*;
import java.util.*;

public class D {
	
	static class Frac implements Comparable<Frac> {
		long x, y;

		public Frac(long x, long y) {
			if (y == 0) {
				throw new AssertionError();
			}
			if (y < 0) {
				x = -x;
				y = -y;
			}
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Frac o) {
			return Long.compare((long)x * o.y, (long)y * o.x);
		}
	}

	void submit() {
		int n = nextInt();
		int w = nextInt();
		int[] xs = new int[n];
		int[] vs = new int[n];
//		double[] ts = new double[n];
		for (int i = 0; i < n; i++) {
			xs[i] = -nextInt();
			vs[i] = nextInt();
//			ts[i] = 1.0 * xs[i] / vs[i];
		}
//		
//		for (int i = 0; i < n; i++) {
//			for (int j = i + 1; j < n; j++) {
//				if (xs[i] == xs[j]) {
//					continue;
//				}
//				
//				double tmp = (1 / ts[i] - 1 / ts[j]) / (1.0 / xs[i] - 1.0 / xs[j]);
//				if (Math.abs(tmp) <= w + 1e-9) {
//					System.err.println(i + " " + j);
//				}
//			}
//		}
		
		Frac[] one = new Frac[n];
		Frac[] two = new Frac[n];
		
		for (int i = 0; i < n; i++) {
			one[i] = new Frac(vs[i] - w, xs[i]);
			two[i] = new Frac(vs[i] + w, xs[i]);
		}
		
		Frac[] uOne = unique(one);
		Frac[] uTwo = unique(two);
		
		Pair[] ps = new Pair[n];
		for (int i = 0; i < n; i++) {
			ps[i] = new Pair(Arrays.binarySearch(uOne, one[i]), Arrays.binarySearch(uTwo, two[i]));
		}
		
		Arrays.sort(ps);
		
		int[] fen = new int[n];
		long ans = 0;
		for (Pair p : ps) {
//			System.err.println(p.x + " " + p.y);
			ans += get(fen, p.x);
//			System.err.println(ans);
			add(fen, p.x);
		}
		
//		ans = (long)n * (n - 1) / 2 - ans;
		
		out.println(ans);
	}
	
	void add(int[] fen, int idx) {
		for (int i = idx; i < fen.length; i |= i + 1) {
			fen[i]++;
		}
	}
	
	int get(int[] fen, int idx) {
		int ret = 0;
		for (int i = idx; i >= 0; i = (i & (i + 1)) - 1) {
			ret += fen[i];
		}
		return ret;
	}
	
	
	static class Pair implements Comparable<Pair> {
		int x, y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Pair o) {
			if (y != o.y) {
				return y > o.y ? -1 : 1;
			}
			return Integer.compare(x, o.x);
		}
		
	}
	
	Frac[] unique(Frac[] a) {
		a = a.clone();
		int sz = 0;
		Arrays.sort(a);
		for (int i = 0; i < a.length; i++) {
			if (sz == 0 || a[i].compareTo(a[sz - 1]) != 0) {
				a[sz++] = a[i];
			}
		}
		return Arrays.copyOf(a, sz);
	}

	void preCalc() {

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

	D() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		preCalc();
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