import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class F {

	static final int K = 550;
	static final int MAX_VAL = 300_001;

	void add(long[] fen, int pos, long delta) {
		for (int i = pos; i < fen.length; i |= i + 1) {
			fen[i] += delta;
		}
	}

	long get(long[] fen, int pos) {
		long ret = 0;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
			ret += fen[i];
		}
		return ret;
	}

	long[] bigOrSmall(int[] a) {
		int n = a.length;
		long[] ret = new long[n];
		boolean[] seen = new boolean[K + 1];
		long[] sumForSmall = new long[K + 1];

		long[] f0 = new long[MAX_VAL];
		long[] f1 = new long[MAX_VAL];

		for (int i = 0; i < n; i++) {
			if (i > 0) {
				ret[i] = ret[i - 1];
			}

			int x = a[i];

			// x is big

			for (int j = 1; j <= K && x > j; j++) {
				if (seen[j]) {
					ret[i] += x % j;
				}
			}

			int prevCnt = -1;
			long prevSum = -1;

			for (int r = 1; r <= x / K; r++) {
				int high = x / r;
				int low = x / (r + 1);

				int cntHigh = r == 1 ? (int) get(f0, high) : prevCnt;
				long sumHigh = r == 1 ? get(f1, high) : prevSum;

				int cntLow = prevCnt = (int) get(f0, low);
				long sumLow = prevSum = get(f1, low);

				ret[i] += (long) x * (cntHigh - cntLow) - r * (sumHigh - sumLow);
			}

			// x is small

			if (x <= K) {
				ret[i] += sumForSmall[x];
			} else {

				prevCnt = -1;
				prevSum = -1;

				for (int low = x; low < MAX_VAL; low += x) {
					int high = Math.min(MAX_VAL, low + x);

					int cntLow = low == x ? (int) get(f0, low - 1) : prevCnt;
					long sumLow = low == x ? get(f1, low - 1) : prevSum;

					int cntHigh = prevCnt = (int) get(f0, high - 1);
					long sumHigh = prevSum = get(f1, high - 1);

					ret[i] += (sumHigh - sumLow) - (long) low * (cntHigh - cntLow);
				}
			}

			// updating stuff

			if (x <= K) {
				seen[x] = true;
			} else {
				add(f0, x, 1);
				add(f1, x, x);
			}
			for (int z = 1; z <= K && z < x; z++) {
				sumForSmall[z] += x % z;
			}
		}

		return ret;
	}

	long[] stupid(int[] a) {
		long[] f0 = new long[MAX_VAL];
		long[] f1 = new long[MAX_VAL];

		int n = a.length;
		long[] ret = new long[n];

		for (int i = 0; i < n; i++) {
			int x = a[i];
			if (i > 0) {
				ret[i] = ret[i - 1];
			}

			long sumLess = get(f1, x);
			int cntLess = (int) get(f0, x);

			ret[i] += sumLess;
			ret[i] += (i - cntLess) * (long) x;

			add(f0, x, 1);
			add(f1, x, x);
		}

		return ret;
	}

	long[] solve(int[] a) {
		long[] p1 = bigOrSmall(a);
		long[] p2 = stupid(a);

		long[] ans = new long[a.length];
		for (int i = 0; i < a.length; i++) {
			ans[i] = p1[i] + p2[i];
		}
		return ans;
	}

	void submit() {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		long[] ans = solve(a);
		for (long x : ans) {
			out.print(x + " ");
		}
		out.println();
	}

	void test() {
		int n = 200000;
		int[] a = IntStream.range(1, MAX_VAL).toArray();
		for (int i = 0; i < a.length; i++) {
			int j = rand(0, i);
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
		int[] inp = Arrays.copyOf(a, n);
		long start = System.currentTimeMillis();
		out.println(solve(inp)[n - 1]);
		out.println(System.currentTimeMillis() - start + " ms");
	}

	long[] brute(int[] a) {
		int n = a.length;
		long[] ret = new long[n];
		for (int i = 1; i < n; i++) {
			ret[i] = ret[i - 1];
			for (int j = 0; j < i; j++) {
				ret[i] += a[i] % a[j] + a[j] % a[i];
			}
		}
		return ret;
	}
	
	void stress() {
		for (int tst = 0;; tst++) {
			int n = 10000;
			int[] a = IntStream.range(1, MAX_VAL).toArray();
			for (int i = 0; i < a.length; i++) {
				int j = rand(0, i);
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			int[] inp = Arrays.copyOf(a, n);
			
			long[] fast = solve(inp);
			long[] slow = brute(inp);
			
			if (!Arrays.equals(fast, slow)) {
				System.err.println(Arrays.toString(inp));
				System.err.println(Arrays.toString(fast));
				System.err.println(Arrays.toString(slow));
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	F() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		submit();
//		 stress();
//		 test();
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