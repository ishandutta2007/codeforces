import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class D {

	static final int B = 100;
	static final int P = 1_000_000_007;

	int[][] dp = new int[B][];
	int[] inv = new int[B];
	{
		inv[1] = 1;
		for (int i = 2; i < inv.length; i++) {
			inv[i] = P - (int) ((long) (P / i) * inv[P % i] % P);
		}
	}

	void submit() {
		long n = nextLong();
//		long n = 1L << 49;
		int k = nextInt();

		long[] ps = new long[B];
		int[] qs = new int[B];
		int sz = 0;

		for (long i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				ps[sz] = i;
				while (n % i == 0) {
					qs[sz]++;
					n /= i;
				}
				sz++;
			}
		}

		if (n != 1) {
			ps[sz] = n;
			qs[sz] = 1;
			sz++;
		}

		ps = Arrays.copyOf(ps, sz);
		qs = Arrays.copyOf(qs, sz);

		// System.err.println(Arrays.toString(ps));
		// System.err.println(Arrays.toString(qs));

		int ret = 1;
		for (int i = 0; i < sz; i++) {
			int[] prob = getDp(qs[i], k);
			int here = 0;
			long curP = 1;
			int mult = (int) (ps[i] % P);
			for (int j = 0; j <= qs[i]; j++) {
				here += (int) (curP * prob[j] % P);
				if (here >= P) {
					here -= P;
				}
				curP = curP * mult % P;
			}
			ret = (int) ((long) ret * here % P);
		}

		out.println(ret);
	}

	int[] getDp(int size, int k) {
		if (dp[size] != null) {
			return dp[size];
		}
		int[] tmp = new int[size + 1];
		tmp[size] = 1;
		while (k-- > 0) {
			for (int i = 0; i <= size; i++) {
				tmp[i] = (int)((long)tmp[i] * inv[i + 1] % P);
			}
			for (int i = size - 1; i >= 0; i--) {
				tmp[i] += tmp[i + 1];
				if (tmp[i] >= P) {
					tmp[i] -= P;
				}
			}
		}
		return dp[size] = tmp;
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