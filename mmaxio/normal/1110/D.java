import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class D {
	
	static final int INF = Integer.MAX_VALUE / 4;

	void submit() {
		int n = nextInt();
		int m = nextInt();
		int[] a = new int[m + 4];
		for (int i = 0; i < n; i++) {
			a[nextInt() + 1]++;
		}
		
		int[][] dp = new int[4][4];
		for (int[] row : dp) {
			Arrays.fill(row, -INF);
		}
		dp[0][0] = 0;
		
		for (int i = 4; i < a.length; i++) {
			int[][] nxt = new int[4][4];
			for (int[] row : nxt) {
				Arrays.fill(row, -INF);
			}
			for (int x = 0; x <= 3; x++) {
				for (int y = 0; y <= 3; y++) {
					if (dp[x][y] < 0) {
						continue;
					}
					for (int z = 0; z <= 3; z++) {
						if (x + y + z > a[i - 2] || y + z > a[i - 1] || z > a[i]) {
							continue;
						}
						nxt[y][z] = Math.max(nxt[y][z], dp[x][y] + z + (a[i - 2] - x - y - z) / 3);
					}
				}
			}
			dp = nxt;
		}
		
		int ans = 0;
		for (int[] row : dp) {
			for (int val : row) {
				ans = Math.max(ans, val);
			}
		}
		
		out.println(ans);
		
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