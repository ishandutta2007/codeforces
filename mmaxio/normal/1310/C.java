import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class C {
	
	char[] s;
	
	class Sub implements Comparable<Sub> {
		int l, len;

		public Sub(int l, int len) {
			this.l = l;
			this.len = len;
		}

		@Override
		public int compareTo(Sub o) {
			int same = lcp[l][o.l];
			if (same >= len || same >= o.len) {
				return Integer.compare(len, o.len);
			}
			return Character.compare(s[l + same], s[o.l + same]);
		}
	}
	
	int[][] lcp;

	void submit() {
		int n = nextInt();
		int m = nextInt();
		long k = nextLong();
		
		s = (nextToken() + "$").toCharArray();
		lcp = new int[n + 1][n + 1];
		for (int i = n - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				if (s[i] == s[j]) {
					lcp[i][j] = lcp[i + 1][j + 1] + 1;
				} else {
					lcp[i][j] = 0;
				}
			}
		}
		
		Sub[] all = new Sub[n * (n + 1) / 2];
		int ptr = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				all[ptr++] = new Sub(i, j - i);
			}
		}
		
		Arrays.sort(all);

		int l = 0;
		int r = all.length;
		
		while (r - l > 1) {
			int mid = (l + r) >> 1;
			int mFrom = all[mid].l;
			int mLen = all[mid].len;
			
			int[] goodFrom = new int[n];
			for (int i = 0; i < n; i++) {
				int same = lcp[i][mFrom];
				if (same >= mLen) {
					goodFrom[i] = i + mLen;
				} else if (s[i + same] > s[mFrom + same]) {
					goodFrom[i] = i + same + 1;
				} else {
					goodFrom[i] = n + 1;
				}
			}
			
			long[] dp = new long[n + 1];
			dp[n] = 1;
			long[] nxt = new long[n + 1];
			
			for (int qwe = 0; qwe < m; qwe++) {
				for (int i = n - 1; i >= 0; i--) {
					dp[i] = safeSum(dp[i], dp[i + 1]);
				}
				for (int i = n - 1; i >= 0; i--) {
					nxt[i] = goodFrom[i] == n + 1 ? 0 : dp[goodFrom[i]];
				}
				dp = nxt.clone();
			}
			
//			System.err.println(mFrom + " " + mLen + " " + dp[0]);
			
			if (dp[0] >= k) {
				l = mid;
			} else {
				r = mid;
			}
		}
		
		Sub ans = all[l];
		
		for (int i = ans.l; i < ans.l + ans.len; i++) {
			out.print(s[i]);
		}
		out.println();
	}
	
	static long safeSum(long x, long y) {
		return Math.min(x + y, INF);
	}
	
	static final long INF = 2_100_000_000_000_000_000L;

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