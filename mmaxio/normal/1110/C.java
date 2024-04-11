import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class C {

	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	int slow(int x) {
		int ret = -1;
		for (int i = 1; i < x; i++) {
			ret = Math.max(ret, gcd(i ^ x, i & x));
		}
		return ret;
	}

	int fast(int n) {
		int x = Integer.highestOneBit(n) * 2 - 1;
		if (n != x) {
			return x;
		}

		int idx = 32 - Integer.numberOfLeadingZeros(n) - 2;
		return ANS[idx];
	}

	void submit() {
//		for (int n = 2; n <= 70000; n++) {
//			System.err.println(n);
//			// System.err.println(n + " " + slow(n));
//			if (slow(n) != fast(n)) {
//				System.err.println(n);
//				System.err.println(slow(n));
//				System.err.println(fast(n));
//				throw new AssertionError();
//			}
//		}
		// for (int n = 3; n <= 1 << 25; n = n * 2 + 1) {
		// System.err.println(n + " " + slow(n) + " " + slow(n) * 3 + " " +
		// n % 3);
		// out.print(slow(n) + ", ");
		// }
		int q = nextInt();
		while (q-- > 0) {
			out.println(fast(nextInt()));
		}
	}

	static final int[] ANS = { 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1,
			5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481,
			5592405, 1082401, };

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

	C() throws IOException {
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
		new C();
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