import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class F_faster {

	void submit() {
		int n = nextInt();
		int k = nextInt();

		int[] a = new int[n + 2];
		for (int i = 0; i < n; i++) {
			a[i + 1] = nextInt();
		}

		Integer[] b = new Integer[n];
		for (int i = 0; i < n; i++) {
			b[i] = i + 1;
		}

		Arrays.sort(b, (Integer x, Integer y) -> -Integer.compare(a[x], a[y]));

//		TreeSet<Integer> set = new TreeSet<>();
//		set.add(0);
//		set.add(n + 1);
		
		int[] nxt = new int[n + 2];
		int[] prv = new int[n + 2];
		
		for (int i = 0; i < n + 2; i++) {
			nxt[i] = i + 1;
			prv[i] = i - 1;
		}

		int ret = 0;

//		for (int pos : b) {
		for (int i = b.length - 1; i >= 0; i--) {
			int pos = b[i];
			int mult = a[pos];
			
			int prev = prv[pos];
			int next = nxt[pos];
			
			int lft = pos - prev - 1;
			int rgh = next - pos - 1;
			
			nxt[prev] = next;
			prv[next] = prev;
			
//			int lft = pos - set.lower(pos) - 1;
//			int rgh = set.higher(pos) - pos - 1;
//			set.add(pos);
			ret += (int) ((long) mult * fastF(lft, rgh, k) % P);
			// System.err.println(lft + " " + rgh + " " + f(lft, rgh, k));
			if (ret >= P) {
				ret -= P;
			}
		}

		out.println(ret);
	}

	int fastF(int lft, int rgh, int k) {
		if (k > lft + rgh + 1) {
			return 0;
		}

		if (lft > rgh) {
			int tmp = lft;
			lft = rgh;
			rgh = tmp;
		}

		// x <= (lft + rgh + 1 - k) / (k - 1)

		int maxX = (lft + rgh + 1 - k) / (k - 1);

		// x == [0..maxX]

		// x -> k + x(k - 1)

		// lft <= k + x(k - 1) - 1
		// x >= (lft - k + 1) / (k - 1)
		int low = Math.floorDiv(lft - k + 1 + k - 2, k - 1);
		low = Math.max(low, 0);

		// k + x(k - 1) - 1 - rgh <= 0
		// x <= (rgh + 1 - k) / (k - 1)
		int high = Math.floorDiv(rgh + 1 - k, k - 1);

		high = Math.min(high, maxX);

		int ret = 0;

		if (low <= high) {
			ret = (int) ((long) (high - low + 1) * (lft + 1) % P);
		}

		if (low > 0) {
			int valFirst = getVal(lft, rgh, 0, k);
			int valLast = getVal(lft, rgh, low - 1, k);
			ret += arithm(valFirst, valLast, low);
			if (ret >= P) {
				ret -= P;
			}
		}

		if (high < maxX) {
			int valFirst = getVal(lft, rgh, maxX, k);
			int valLast = getVal(lft, rgh, high + 1, k);
			ret += arithm(valFirst, valLast, maxX - high);
			if (ret >= P) {
				ret -= P;
			}
		}

		return ret;
	}

	int getVal(int lft, int rgh, int x, int k) {
		int z = k + (k - 1) * x;

		int from = Math.max(z - 1 - rgh, 0);
		int to = Math.min(z - 1, lft);
		return Math.max(to - from + 1, 0);
	}

	int arithm(int l, int r, int len) {
		int mid = l + r;
		if (mid >= P) {
			mid -= P;
		}
		return (int) ((long) mid * INV2 % P * len % P);
	}

	int f(int lft, int rgh, int k) {
		int ret = 0;
		for (int z = k;; z += k - 1) {
			if (z > lft + rgh + 1) {
				break;
			}

			int from = Math.max(z - 1 - rgh, 0);
			int to = Math.min(z - 1, lft);
			ret += Math.max(to - from + 1, 0);
		}
		return ret;
	}

	static final int P = 1_000_000_007;
	static final int INV2 = (P + 1) / 2;

	void test() {
		for (int lft = 0; lft < C; lft++) {
			for (int rgh = 0; rgh < C; rgh++) {
				for (int k = 2; k < C; k++) {
					if (f(lft, rgh, k) != fastF(lft, rgh, k)) {
						System.err.println(lft + " " + rgh + " " + k);
						System.err.println(f(lft, rgh, k));
						System.err.println(fastF(lft, rgh, k));
						throw new AssertionError();
					}
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

	F_faster() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 15;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new F_faster();
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