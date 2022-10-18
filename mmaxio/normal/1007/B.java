import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class B {

	int[] g = new int[8];
	long[] divs;

	int[][] PERMS = { { 0, 1, 2 }, { 0, 2, 1 }, { 1, 0, 2 }, { 1, 2, 0 },
			{ 2, 0, 1 }, { 2, 1, 0 } };
	
	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}
	
	long solveAAB() {
		long ret = 0;
		for (int mask = 1; mask < 64; mask++) {
			int maskA = 0, maskB = 0;
			for (int i = 0; i < 6; i++) {
				if (!test(mask, i)) {
					continue;
				}
				maskA |= 1 << PERMS[i][0];
				maskA |= 1 << PERMS[i][1];
				maskB |= 1 << PERMS[i][2];
			}
			ret += (Integer.bitCount(mask) % 2 == 1 ? 1 : -1) * divs[g[maskA]] * divs[g[maskB]];
		}
		return ret;
	}
	
	long solveABC() {
		long ret = 0;
		for (int mask = 1; mask < 64; mask++) {
			int maskA = 0, maskB = 0, maskC = 0;
			for (int i = 0; i < 6; i++) {
				if (!test(mask, i)) {
					continue;
				}
				maskA |= 1 << PERMS[i][0];
				maskB |= 1 << PERMS[i][1];
				maskC |= 1 << PERMS[i][2];
			}
			ret += (Integer.bitCount(mask) % 2 == 1 ? 1 : -1) * divs[g[maskA]] * divs[g[maskB]] * divs[g[maskC]];
		}
		return ret;
	}

	long solve() {
		
		long aaa = divs[g[7]];
		
		long aab = solveAAB();
		aab -= aaa;
		
		long abc = solveABC();
		abc -= aaa;
		abc -= 3 * aab;
		
		if (abc % 6 != 0) {
			throw new AssertionError();
		}
		
		return aaa + aab + abc / 6;
	}
	
	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	void submit() {
		int t = nextInt();
		while (t-- > 0) {
			g[1] = nextInt();
			g[2] = nextInt();
			g[4] = nextInt();
			g[3] = gcd(g[1], g[2]);
			g[5] = gcd(g[1], g[4]);
			g[6] = gcd(g[2], g[4]);
			g[7] = gcd(g[1], g[6]);
			out.println(solve());
		}
	}

	void preCalc() {
		divs = new long[100_001];
		for (int i = 1; i < divs.length; i++) {
			for (int j = i; j < divs.length; j += i) {
				divs[j]++;
			}
		}
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

	B() throws IOException {
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
		new B();
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