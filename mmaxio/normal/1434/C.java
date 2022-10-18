import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class C {

	long sumInterval(long a, long b) {
		if (a <= 0 || a > b) {
			throw new AssertionError();
		}
		return (a + b) * (b - a + 1) / 2;
	}

	long lenInterval(long a, long b) {
		if (a <= 0 || a > b) {
			throw new AssertionError();
		}
		return b - a + 1;
	}
	
	long goSlow(int dmg, int healVal, int healDur, int cd, long tick) {
		long ret = dmg * (tick + 1);
		long time = tick * cd;
		for (int i = 0; i <= tick; i++) {
			for (long j = i * cd + 1; j <= i * cd + healDur; j++) {
				if (j > time) {
					break;
				}
				ret -= healVal;
			}
		}
		return ret;
	}

	long go(int dmg, int healVal, int healDur, int cd, long tick) {
//		System.err.println(tick);
		long totalDmg = (dmg + healVal) * tick + dmg;

		// Heals [0..healDur], [cd..cd+healDur], [2*cd..2*cd+healDur], ...
		// [(tick-1)*cd..(tick-1)*cd+healDur]
		// but only those values <= tick * cd

		// So reversing these we get: [cd-healDur, cd], [2 * cd - healDur, 2 * cd]
		// , ..., [(tick - 1) * cd - healDur, (tick - 1) * cd],  [tick*cd-healDur, tick*cd]
		// (or [i*cd-healDur, i*cd] for i = 1..tick and tick can be 0!)
		// But only those >= 0
		// yeah closed intervals suck, add + 1 for each

		long rhsHeal = tick * (tick + 1) / 2 * cd;
		rhsHeal += tick;
		long minNzI = healDur / cd + 1;
		long lhsHeal = 0;
		if (minNzI <= tick) {
			lhsHeal += sumInterval(minNzI, tick) * cd - lenInterval(minNzI, tick) * healDur;
		}
		long healTicks = rhsHeal - lhsHeal;
		
		if (healTicks > INF / healVal) {
			return -1;
		}
		
		return totalDmg - healTicks * healVal;
	}
	
	static final long INF = Long.MAX_VALUE / 3;

	long solve(int dmg, int healVal, int healDur, int cd) {
		if (dmg > (long) healVal * healDur) {
			return -1;
		}
		long ret = dmg;
		for (int kek = 0; kek <= 2; kek++) {
			ret = Math.max(ret, go(dmg, healVal, healDur, cd, kek));
		}

		long tmp = healDur / cd;
		for (long kek = Math.max(tmp - 2, 0); kek <= tmp + 2; kek++) {
			ret = Math.max(ret, go(dmg, healVal, healDur, cd, kek));
		}
		
		tmp = dmg / ((long)healVal * cd);
		for (long kek = Math.max(tmp - 2, 0); kek <= tmp + 2; kek++) {
			ret = Math.max(ret, go(dmg, healVal, healDur, cd, kek));
		}

		return ret;
	}
	
	long badSolve(int dmg, int healVal, int healDur, int cd, int B) {
		long[] a = new long[B + 1];
		for (int i = 0; i * cd <= B; i++) {
			a[i * cd] += dmg;
			for (int j = i * cd + 1; j <= i * cd + healDur && j <= B; j++) {
				a[j] -= healVal;
			}
		}
		long ret = a[0];
		for (int i = 1; i < B; i++) {
			a[i] += a[i - 1];
			ret = Math.max(ret, a[i]);
		}
		return ret;
	}

	void submit() {
		int t = nextInt();
		while (t-- > 0) {
			int a = nextInt();
			int b = nextInt();
			int c = nextInt();
			int d = nextInt();
			out.println(solve(a, b, c, d));
//			out.println(badSolve(a, b, c, d, 10000));
		}
	}

	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}
	
	void test() {
		int a = 9;
		int b = 2;
		int c = 9;
		int d = 1;
		System.err.println(solve(a, b, c, d));
		System.err.println(badSolve(a, b, c, d, 10000));
//		System.err.println(badSolve(a, b, c, d, 1000000));
	}

	void stress() {
		int B = 1000;
		for (int tst = 0;; tst++) {
			int a = rand(1, B);
			int b = rand(1, B);
			int c = rand(1, B);
			int d = rand(1, B);
			long fast = solve(a, b, c, d);
			long bad = badSolve(a, b, c, d, 10000);
			if (fast != -1 && fast != bad) {
				System.err.println(fast);
				System.err.println(bad);
				System.err.println(a + " " + b + " " + c + " " + d);
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	C() throws IOException {
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