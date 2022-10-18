import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class E {

	static final Random rng = new Random();
	static final long P = BigInteger.probablePrime(61, rng).longValueExact();
	
	void submit() {
		int n = nextInt();
		int qs = nextInt();
		
		List<Integer>[] g = new ArrayList[n + 1];
		for (int i = 0; i <= n; i++) {
			g[i] = new ArrayList<>();
		}
		
		for (int i = 0; i < qs; i++) {
			int l = nextInt() - 1;
			int r = nextInt();
			int x = nextInt();
			
			g[l].add(x);
			g[r].add(~x);
		}
		
		long[] dp = new long[n + 1];
		dp[0] = 1;
		
		boolean[] ans = new boolean[n + 1];
		
		for (int i = 0; i < n; i++) {
			for (int q : g[i]) {
				if (q >= 0) {
					for (int j = n; j >= q; j--) {
						dp[j] += dp[j - q];
						if (dp[j] >= P) {
							dp[j] -= P;
						}
					}
				} else {
					q = ~q;
					for (int j = q; j <= n; j++) {
						dp[j] -= dp[j - q];
						if (dp[j] < 0) {
							dp[j] += P;
						}
					}
				}
			}
			for (int j = 1; j <= n; j++) {
				ans[j] |= dp[j] != 0;
			}
		}
		
		int outp = 0;
		for (boolean b : ans) {
			outp += b ? 1 : 0;
		}
		
		out.println(outp);
		for (int i = 1; i <= n; i++) {
			if (ans[i]) {
				out.print(i + " ");
			}
		}
		out.println();
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

	E() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		submit();
		// stress();
		// test();
		out.close();
	}

	static final int C = 5;

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