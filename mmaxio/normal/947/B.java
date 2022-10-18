import java.io.*;
import java.math.*;
import java.util.*;

public class B {

	void submit() {
		int n = nextInt();
		long[] vs = new long[n];
		long[] ts = new long[n];
		for (int i = 0; i < n; i++) {
			vs[i] = nextInt();
		}
		for (int i = 0; i < n; i++) {
			ts[i] = nextInt();
		}
		
		long[] v1 = new long[n];
		long pref = 0;
		for (int i = 0; i < n; i++) {
			v1[i] = vs[i] + pref;
			pref += ts[i];
		}
		
		Arrays.sort(v1);
		
		long[] sz = new long[n];
		
		long[] suffV1 = new long[n + 1];
		for (int i = n - 1; i >= 0; i--) {
			suffV1[i] = suffV1[i + 1] + v1[i];
		}
		
		int j = 0;
		long melted = 0;
		for (int i = 0; i < n; i++) {
			melted += ts[i];
			while (j < n && v1[j] <= melted) {
				j++;
			}
			sz[i] = suffV1[j] - (long)(n - j) * melted;
		}
		
		long[] ans = new long[n];
		
		long szInit = 0;
		for (long v : v1) {
			szInit += v;
		}
		
		for (int i = 0; i < n; i++) {
			long diff = (i == 0 ? szInit : sz[i - 1]) - sz[i];
			ans[i] = diff - (long)ts[i] * (n - 1 - i);
		}
		
		for (long x : ans) {
			out.print(x + " ");
		}
	}

	void preCalc() {

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