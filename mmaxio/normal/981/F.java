import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class F {

	void OMEGALUL(int[] a) {
		for (int i = 0; i < a.length; i++) {
			int j = rand(0, i);
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
		Arrays.sort(a);
	}
	
	int n, len;
	
	int[] a;
	int[] bigB;
	
	boolean can(int dist) {
		int pL = 0, pR = 0;
		int[] delta = new int[n];
		for (int i = 0; i < n; i++) {
			while (a[i] - dist > bigB[pL]) {
				pL++;
			}
			while (a[i] + dist >= bigB[pR]) {
				pR++;
			}
			
			if (pL == pR) {
				return false;
			}
			
			// [pL .. pR)
			
			int from = pL % n;
			int to = pR % n;
			
			if (from == to) {
				delta[0]++;
				continue;
			}
			
//			System.err.println(from + " " + to);
			
			from = (from + n - i) % n;
			to = (to + n - i) % n;
			
			
			
			if (from < to) {
				delta[from]++;
				delta[to]--;
			} else {
				delta[0]++;
				delta[to]--;
				delta[from]++;
			}
		}
		
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				delta[i] += delta[i - 1];
			}
			if (delta[i] == n) {
				return true;
			}
		}
		
		return false;
	}
	
	int dist(int x, int y) {
		int ret = Math.abs(x - y);
		return Math.min(ret, len - ret);
	}
	
	void submit() {
		n = nextInt();
		len = nextInt();
		a = new int[n];
		int[] b = new int[n];
		
		
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		for (int i = 0; i < n; i++) {
			b[i] = nextInt();
		}
		
		OMEGALUL(a);
		OMEGALUL(b);
		
//		for (int shift = 0; shift < n; shift++) {
//			int val = 0; 
//			for (int i = 0; i < n; i++) {
//				val = Math.max(val, dist(a[i], b[(i + shift) % n]));
//			}
//		}
		
		bigB = new int[3 * n + 1];
		
		for (int i = 0; i < n; i++) {
			bigB[i] = b[i] - len;
			bigB[i + n] = b[i];
			bigB[i + 2 * n] = b[i] + len;
		}
		bigB[3 * n] = Integer.MAX_VALUE;

//		System.err.println(Arrays.toString(a));
//		System.err.println(Arrays.toString(b));
		
//		System.err.println(can(27));
		
		
		int low = -1;
		int high = len / 2;
		
		while (high - low > 1) {	
			int mid = (low + high) >> 1;
			if (can(mid)) {
				high = mid;
			} else {
				low = mid;
			}
		}
		
		out.println(high);
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

	F() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
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
		new F();
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