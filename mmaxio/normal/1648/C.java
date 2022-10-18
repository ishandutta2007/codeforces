import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class C {

	static final int P = 998244353;
	static final int B = 200_000;

	static int[] inv = new int[B + 1];
	static int[] fact = new int[B + 1];
	static int[] invFact = new int[B + 1];
	static {
		inv[1] = 1;
		for (int x = 2; x < inv.length; x++) {
			inv[x] = P - (int) ((long) (P / x) * inv[P % x] % P);
		}
		
		fact[0] = 1;
		for (int i = 1; i <= B; i++) {
			fact[i] = (int) ((long) i * fact[i - 1] % P);
		}

		invFact[0] = 1;
		for (int i = 1; i <= B; i++) {
			invFact[i] = (int) ((long) invFact[i - 1] * inv[i] % P);
		}
	}

	void add(int[] fen, int where, int delta) {
		for (int i = where; i < fen.length; i |= i + 1) {
			fen[i] += delta;
		}
	}

	int get(int[] fen, int where) {
		int ret = 0;
		for (int i = where; i >= 0; i = (i & (i + 1)) - 1) {
			ret += fen[i];
		}
		return ret;
	}

	void submit() {
		int n = nextInt();
		int m = nextInt();

		int[] f = new int[B];
		int[] b = new int[m];

		for (int i = 0; i < n; i++) {
			f[nextInt() - 1]++;
		}
		for (int i = 0; i < m; i++) {
			b[i] = nextInt() - 1;
		}

		long tot = 0;
		long curP = 1;
		long multWays = fact[n];

		int[] fen = new int[B];
		for (int i = 0; i < B; i++) {
			add(fen, i, f[i]);
			multWays = multWays * invFact[f[i]] % P;
		}

		for (int i = 0; i < m && i < n; i++) {
			int cntLess = get(fen, b[i] - 1);
			tot += curP * cntLess % P * inv[n - i] % P;
			if (tot >= P) {
				tot -= P;
			}
			
			if (f[b[i]] > 0) {
				curP = curP * f[b[i]] % P * inv[n - i] % P;
				f[b[i]]--;
				add(fen, b[i], -1);
			} else {
				out.println(tot * multWays % P);
				return;
			}
		}
		
		tot = tot * multWays % P;
		
		// we are prefix of b, add 1
		if (n < m) {
			tot++;
			if (tot >= P) {
				tot -= P;
			}
		}
		out.println(tot);
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