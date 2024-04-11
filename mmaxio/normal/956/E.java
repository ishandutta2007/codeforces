import java.io.*;
import java.math.*;
import java.util.*;

public class E {

	static long start = System.currentTimeMillis();

	static boolean nextPermutation(int[] a) {
		int n = a.length;
		int ptr = n - 1;
		while (ptr > 0 && a[ptr - 1] >= a[ptr]) {
			ptr--;
		}

		for (int i = ptr, j = n - 1; i < j; i++, j--) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}

		if (ptr == 0) {
			return false;
		}

		for (int i = ptr;; i++) {
			if (a[ptr - 1] < a[i]) {
				int tmp = a[ptr - 1];
				a[ptr - 1] = a[i];
				a[i] = tmp;
				return true;
			}
		}
	}

	int slow(int[] a, boolean[] good, int l, int r) {
		int n = a.length;
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}

		int ret = 0;
		do {
			int sum = 0;
			int cur = 0;
			for (int i : p) {
				if (sum >= l && sum <= r && good[i]) {
					cur++;
				}
				sum += a[i];
			}
			ret = Math.max(ret, cur);
		} while (nextPermutation(p));
		return ret;
	}

	int slowBad(int[] a, boolean[] good, int l, int r) {
		int n = a.length;
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}

		int ret = 0;
		do {
			int sum = 0;
			int cur = 0;
			int shortPref = Integer.MAX_VALUE;
			int longMid = Integer.MIN_VALUE;
			for (int i : p) {
				if (sum < l && good[i]) {
					shortPref = Math.min(shortPref, a[i]);
				}
				if (sum >= l && sum <= r && good[i]) {
					longMid = Math.max(longMid, a[i]);
				}
				if (sum >= l && sum <= r && good[i]) {
					cur++;
				}
				sum += a[i];
			}
			if (shortPref < longMid) {
				continue;
			}
			ret = Math.max(ret, cur);
		} while (nextPermutation(p));
		return ret;
	}

	static final int LOG = 6;
	static final int SIZE = 1 << LOG;
	static final int MASK = SIZE - 1;

	static class Knapsack {
		long[] data;
		int curSize = 0;

		long getWord(int i) {
			if (i <= -SIZE || (i >> LOG) + 1 >= data.length) {
				return 0;
			}
			int rem = i & MASK;
			int idx = i >> LOG;

			if (rem == 0) {
				return data[idx];
			}

			long head = idx < 0 ? 0 : (data[idx] >>> rem);
			long tail = data[idx + 1] << (SIZE - rem);

			return head | tail;
		}

		public Knapsack(int maxSize) {
			data = new long[(maxSize >> LOG) + 3];
			data[0] |= 1;
		}

		void add(int item) {
			curSize += item;
			for (int block = curSize >> LOG; block >= 0; block--) {
				data[block] |= getWord((block << LOG) - item);
			}
		}

		int getAfter(int l) {
			// -1 if not present
			if (curSize < l) {
				return -1;
			}
			long tmp = getWord(l);
			if (tmp != 0) {
				return l + Long.numberOfTrailingZeros(tmp);
			}
			for (int i = (l >> LOG) + 1;; i++) {
				if (data[i] != 0) {
					return (i << LOG) + Long.numberOfTrailingZeros(data[i]);
				}
			}
		}
	}

	static final int INF = Integer.MAX_VALUE / 3;

	int fast(int[] a, boolean[] good, int l, int r) {
		int sum = Arrays.stream(a).sum();
		int n = a.length;
		int tmp = sum - r;
		r = sum - l;
		l = tmp;

		int[] dp = new int[sum + 1];
		Arrays.fill(dp, -INF);
		dp[0] = 0;

		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			if (good[i]) {
				arr[i] = -a[i];
			} else {
				arr[i] = -2 * sum - a[i];
			}
		}

		Arrays.sort(arr);
		for (int x : arr) {
			int cost;
			if (x < -2 * sum) {
				cost = 0;
				x = -x - 2 * sum;
			} else {
				cost = 1;
				x = -x;
			}
			
			for (int i = sum; i >= x; i--) {
				dp[i] = Math.max(dp[i], dp[i - x] + cost * (i >= l && i <= r ? 1 : 0));
			}
		}
		
		return Arrays.stream(dp).max().getAsInt();
	}

	void submit() {
		int n = nextInt();
		int l = nextInt();
		int r = nextInt();
		int[] a = new int[n];
		boolean[] good = new boolean[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		for (int i = 0; i < n; i++) {
			good[i] = nextInt() == 1;
		}
		out.println(fast(a, good, l, r));
		// out.println(slow(a, good, l, r));
		// out.println(slowBad(a, good, l, r));
	}

	void preCalc() {

	}

	void test() {

	}

	void stress() {
		for (int tst = 0;; tst++) {
			int n = rand(1, C);
			int sum = 0;
			int[] a = new int[n];
			boolean[] good = new boolean[n];
			for (int i = 0; i < n; i++) {
				a[i] = rand(1, C);
				good[i] = rng.nextBoolean();
				sum += a[i];
			}

			int l = rand(0, sum);
			int r = rand(0, sum);
			if (l > r) {
				int tmp = l;
				l = r;
				r = tmp;
			}

			if (slow(a, good, l, r) != slowBad(a, good, l, r)) {
				System.err.println(Arrays.toString(a));
				System.err.println(Arrays.toString(good));
				System.err.println(l + " " + r);
				System.err.println(slow(a, good, l, r));
				System.err.println(slowBad(a, good, l, r));
				throw new AssertionError();
			}
			System.err.println(tst + " OK");
		}
	}

	E() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 4;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new E();
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