import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class C {

	
	boolean[] used;
	
	void pick(int idx) {
		out.println(idx + 1);
		out.flush();
		used[idx] = true;
	}
	
	void submit() {
		int n = nextInt();
		int m = nextInt();
		int[] p = new int[2 * n];
		for (int i = 0; i < 2 * n; i++) {
			p[i] = nextInt();
		}
		int[] pair = new int[2 * n];
		Arrays.fill(pair, -1);
		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			pair[v] = u;
			pair[u] = v;
		}
		
		used = new boolean[2 * n];
		
		int t = nextInt();
		int last = -1;
		
		for (int i = 0; i < n; i++) {
			for (int move = 1; move <= 2; move++) {
				if (move != t) {
					int opp = nextInt() - 1;
					used[opp] = true;
					last = opp;
					continue;
				} 
				
				// t = 2, respond
				if (t == 2 && pair[last] != -1 && !used[pair[last]]) {
					pick(pair[last]);
					continue;
				}
				
				int go = -1;
				int bestDiff = Integer.MIN_VALUE;
				
				for (int j = 0; j < 2 * n; j++) {
					if (pair[j] != -1 && !used[j]) {
						int diff = p[j] - p[pair[j]];
						if (diff > bestDiff) {
							bestDiff = diff;
							go = j;
						}
					}
				}
				
				if (go != -1) {
					pick(go);
					continue;
				}
				
				for (int j = 0; j < 2 * n; j++) {
					if (pair[j] == -1 && !used[j]) {
						if (p[j] > bestDiff) {
							bestDiff = p[j];
							go = j;
						}
					}
				}
				
				pick(go);
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