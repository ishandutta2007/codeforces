import java.io.*;
import java.math.*;
import java.util.*;

public class E {

	static class Segment implements Comparable<Segment> {
		int l, r;

		@Override
		public int compareTo(Segment o) {
			if (l != o.l) {
				return l < o.l ? -1 : 1;
			}
			return -Integer.compare(r, o.r);
		}

		public Segment(int l, int r) {
			this.l = l;
			this.r = r;
		}
	}

	void submit() {
		int n = nextInt();
		int m1 = nextInt();
		int m2 = nextInt();
		Segment[][] a = { new Segment[m1], new Segment[m2] };
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < a[i].length; j++) {
				int l = nextInt() - 1;
				int r = nextInt();
				a[i][j] = new Segment(l, r);
			}
			a[i] = unnest(a[i]);
		}

		int[] all = new int[2 * (1 + a[0].length + a[1].length)];
		int ptr = 0;
		all[ptr++] = 0;
		all[ptr++] = n;
		for (Segment[] row : a) {
			for (Segment s : row) {
				all[ptr++] = s.l;
				all[ptr++] = s.r;
			}
		}

		all = unique(all);

		int m = all.length;

		int[][] end = new int[2][all.length];
		Arrays.fill(end[0], -1);
		Arrays.fill(end[1], -1);

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < a[i].length; j++) {
				int l = Arrays.binarySearch(all, a[i][j].l);
				int r = Arrays.binarySearch(all, a[i][j].r);
				end[i][r] = l;
			}
		}

		int[][] dp = new int[2][m];
		int[] last = { 0, 0 };

		int mix = 1;
		int[] sum = { 0, 0 };

		for (int i = 0; i < m - 1; i++) {
			int wasSum = sum[0] + sum[1];
			if (wasSum >= P) {
				wasSum -= P;
			}
			wasSum += mix;
			if (wasSum >= P) {
				wasSum -= P;
			}

			int newMix = (int) ((long) wasSum
					* Math.floorMod(pow(2, all[i + 1] - all[i]) - 2, P) % P);
			int[] delta = { (mix + sum[1]) % P, (mix + sum[0]) % P };
			for (int j = 0; j < 2; j++) {
				dp[j][i] += delta[j];
				if (dp[j][i] >= P) {
					dp[j][i] -= P;
				}
				sum[j] += delta[j];
				if (sum[j] >= P) {
					sum[j] -= P;
				}
			}
			
			mix = newMix;
			for (int j = 0; j < 2; j++) {
				if (end[j][i + 1] == -1) {
					continue;
				}
				while (last[j] <= end[j][i + 1]) {
					sum[j] -= dp[j][last[j]];
					if (sum[j] < 0) {
						sum[j] += P;
					}
					last[j]++;
				}
			}
		}
		long ans = (0L + mix + sum[0] + sum[1]) % P;
		out.println(ans);
	}

	static final int P = 1_000_000_007;

	int pow(int a, int b) {
		int ret = 1;
		for (; b > 0; b >>= 1) {
			if ((b & 1) == 1) {
				ret = (int) ((long) ret * a % P);
			}
			a = (int) ((long) a * a % P);
		}
		return ret;
	}

	int[] unique(int[] a) {
		a = a.clone();
		int sz = 0;
		Arrays.sort(a);
		for (int i = 0; i < a.length; i++) {
			if (sz == 0 || a[i] != a[sz - 1]) {
				a[sz++] = a[i];
			}
		}
		return Arrays.copyOf(a, sz);
	}

	Segment[] unnest(Segment[] a) {
		Arrays.sort(a);
		int sz = 0;
		for (int i = 0; i < a.length; i++) {
			while (sz > 0 && a[sz - 1].r >= a[i].r) {
				sz--;
			}
			a[sz++] = a[i];
		}
		return Arrays.copyOf(a, sz);
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

	E() throws IOException {
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