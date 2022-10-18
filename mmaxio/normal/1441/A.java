import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class A {
	
	static final int P = 998244353;
	
	int solve(int[] a, int n) {
		for (int i = 0; i < a.length; i++) {
			a[i]++;
		}
		
		int[] b = a.clone();
		Arrays.sort(b);
		int[] nxt = new int[n + 2];
		int[] prv = new int[n + 2];
		int[] len = new int[n + 2];
		nxt[0] = b[0];
		prv[b[0]] = 0;
		len[0] = b[0] - 0 - 1;
		
		for (int i = 0; i < b.length - 1; i++) {
			nxt[b[i]] = b[i + 1];
			prv[b[i + 1]] = b[i];
			len[b[i]] = b[i + 1] - b[i] - 1;
		}
		
		nxt[b[b.length -1]] = n + 1;
		prv[n + 1] = b[b.length - 1];
		len[b[b.length - 1]] = (n + 1) - (b[b.length - 1]) - 1;
		
		int ret = 1;
		
		for (int v : a) {
			int bef = prv[v];
			int lenBef = len[bef];
			
			int aft = nxt[v];
			int lenAft = len[v];
			
			if (lenBef == 0 && lenAft == 0) {
				return 0;
			}
			
			if (lenBef > 0 && lenAft > 0) {
				ret = ret * 2 % P;
			}
			
			nxt[bef] = aft;
			prv[aft] = bef;
			len[bef] = lenBef + lenAft;
		}
		return ret;
	}

	void submit() {
		int t = nextInt();
		while (t-- > 0) {
			int n = nextInt();
			int k = nextInt();
			int[] p = new int[n];
			int[] inv = new int[n];
			for (int i = 0; i < n; i++) {
				p[i] = nextInt() - 1;
				inv[p[i]] = i;
			}
			int[] a = new int[k];
			for (int i = 0; i < k; i++) {
				a[i] = inv[nextInt() - 1];
			}
			out.println(solve(a, n));
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

	A() throws IOException {
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
		new A();
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