import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class G {

	static final int K = 10000;
	static final int Q = 5;

	static final long M = 10004205361450475L;
	
	long[][] dp = new long[Q + 1][K + 1];
	{
		for (long[] row : dp) {
			Arrays.fill(row, -1);
		}
	}
	
	long go(long low, int qs) {
		if (qs == 0) {
			return 0;
		}
//		if (qs == 1) {
//			return Math.min(low, K);
//		}
		int now = (int) Math.min(low, K);
		if (dp[qs][now] != -1) {
			return dp[qs][now];
		}
		long cur = now;
		
		long ret = 0;
		
		for (int i = 0; i < now + 1; i++) {
			long add = go(cur, qs - 1);
			ret += add;
			if (i != now) {
				ret++;
			}
			cur = Math.min(K, cur + add + 1);
		}
		
		return dp[qs][now] = ret;
	}
	
	void go(long l, long r, int qs) {
		ArrayList<Long> ask = new ArrayList<>();
		
		long cur = l;
		
		for (int i = 0; i < Math.min(l, K); i++) {
			long advance = go(cur, qs - 1);
			cur += advance;
			if (cur >= r) {
				break;
			}
			ask.add(cur);
			cur++;
		}
		
		out.print(ask.size() + " ");
		for (long x : ask) {
			out.print(x + " ");
		}
		out.println();
		out.flush();
		
		int ret = nextInt();
		if (ret == -1) {
			return;
		}
		
		if (ret == 0) {
			go(l, ask.get(0), qs - 1);
		} else if (ret == ask.size()) {
			go(ask.get(ask.size() - 1) + 1, r, qs - 1);
		} else {
			go(ask.get(ret - 1) + 1, ask.get(ret), qs - 1);
		}
	}

	void submit() {
//		System.err.println(go(7, 2));
//		System.err.println(go(7, 1));
		go(1, M, 5);
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

	G() throws IOException {
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
		new G();
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