import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class F {

	static final double M = 10.0 / 9;
	static final double[] MP = new double[102];
	{
		MP[0] = 1;
		for (int i = 1; i < MP.length; i++) {
			MP[i] = MP[i - 1] * M;
		}
	}

	static class Task implements Comparable<Task> {
		int diff;
		int bonus;

		public Task(int diff, int bonus) {
			this.diff = diff;
			this.bonus = bonus;
		}

		@Override
		public int compareTo(Task o) {
			return -Integer.compare(diff, o.diff);
		}
	}

	int solve() {
		int n = nextInt();
		double c = nextDouble();
		double time = nextDouble();

		Task[] a = new Task[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Task(nextInt(), nextInt());
		}
		Arrays.sort(a);
		double[][] dp = new double[n + 1][10 * n + 1];
		for (double[] row : dp) {
			Arrays.fill(row, Double.POSITIVE_INFINITY);
		}
		dp[0][0] = 0;

		for (int i = 0; i < n; i++) {
			int diff = a[i].diff;
			int bonus = a[i].bonus;

			for (int take = i; take >= 0; take--) {
				for (int score = 10 * i; score >= 0; score--) {
					if (dp[take][score] == Double.POSITIVE_INFINITY) {
						continue;
					}
					dp[take + 1][score + bonus] = Math.min(dp[take + 1][score
							+ bonus], dp[take][score] + diff * MP[take + 1]);
				}
			}

		}
		
//		System.err.println(dp[2][7]);
		
		int ret = 0;
		for (int k = 1; k <= n; k++) {
//			double left = time - 10 * k;
			
//			if (left < 0) {
//				break;
//			}
//			
//			double low = 0;
//			double high = 1e20;//???
//			
//			for (int i = 0; i < ITERS; i++) {
//				double mid = (low + high) * .5;
//				double optX = (Math.sqrt(mid * c) - 1) / c;
//				if (optX < 0) {
//					optX = 0;
//				}
//				
//				double value = optX + mid / (1 + c * optX);
//				if (value < left) {
//					low = mid;
//				} else {
//					high = mid;
//				}
//			}
			
//			double bound = (low + high) * .5;
			
			for (int score = 10 * k; score > 0; score--) {
				if (dp[k][score] == Double.POSITIVE_INFINITY) {
					continue;
				}
				
				double A = dp[k][score];
				
				double optX = Math.max((Math.sqrt(A * c) - 1) / c, 0);
				if (10 * k + optX + A / (1 + c * optX) <= time) {
					ret = Math.max(ret, score);
					break;
				}
			}
		}
		return ret;
	}
	
	static final double ITERS = 80;

	void submit() {
		int tc = nextInt();
		while (tc-- > 0) {
			out.println(solve());
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

	F() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();
//	static final int C = 5;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new F();
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