import java.io.*;
import java.math.*;
import java.util.*;

public class D {

	static class Point implements Comparable<Point> {
		int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Point o) {
			return Integer.compare(x, o.x);
		}

		@Override
		public String toString() {
			return "(" + x + ", " + y + ")";
		}
	}

	void submit() {
		int n = nextInt();
		Point[] a = new Point[n];
		Point[] b = new Point[n];
		int szA = 0, szB = 0;
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			int y = nextInt();
			if ((x + y) % 2 == 0) {
				a[szA++] = new Point(x, y);
			} else {
				b[szB++] = new Point(x, y + 1);
			}
		}

		out.println(solve(Arrays.copyOf(a, szA)) + solve(Arrays.copyOf(b, szB)));
	}
	
	static final int INF = 100_000_000;
	
	long solve(Point[] a) {
		if (a.length < 1) {
			return 0;
		}
		for (Point p : a) {
			int sum = p.x + p.y;
			int diff = p.x - p.y;
			p.x = sum;
			p.y = diff;
		}
		
		Arrays.sort(a);
		int decr = a[0].x;
		for (Point p : a) {
			p.x -= decr;
		}
		
		int sz = a[a.length - 1].x + 1;
		
		int[] lowY = new int[sz];
		Arrays.fill(lowY, INF);
		int[] highY = new int[sz];
		Arrays.fill(highY, -INF);
		
		for (Point p : a) {
			lowY[p.x] = Math.min(lowY[p.x], p.y);
			highY[p.x] = Math.max(highY[p.x], p.y);
		}
		
		int[] prefLowY = getPrefMins(lowY);
		int[] suffLowY = reverse(getPrefMins(reverse(lowY)));
		
		int[] prefHighY = negate(getPrefMins(negate(highY)));
		int[] suffHighY = reverse(negate(getPrefMins(reverse(negate(highY)))));
		
		long ans = 0;
		
		for (int i = 1; i < sz; i += 2) {
			int from = Math.max(prefLowY[i], suffLowY[i]);
			int to = Math.min(prefHighY[i], suffHighY[i]);
			if ((from & 1) == 0) {
				from++;
			}
			if ((to & 1) == 0) {
				to--;
			}
			if (from <= to){
				ans += (to - from) / 2 + 1;
			}
		}
		
		return ans;
	}
	
	int[] negate(int[] arr) {
		int[] ret = new int[arr.length];
		for (int i = 0; i < arr.length; i++) {
			ret[i] = -arr[i];
		}
		return ret;
	}

	int[] getPrefMins(int[] arr) {
		int[] ret = new int[arr.length];
		ret[0] = arr[0];
		for (int i = 1; i < arr.length; i++) {
			ret[i] = Math.min(arr[i], ret[i - 1]);
		}
		return ret;
	}
	
	int[] reverse(int[] arr) {
		int[] ret = new int[arr.length];
		for (int i = 0, j = arr.length - 1; i < arr.length; i++, j--) {
			ret[i] = arr[j];
		}
		return ret;
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