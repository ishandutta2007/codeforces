import java.io.*;
import java.math.*;
import java.util.*;

public class D {

	void submit() {
		int n = nextInt();
		int m1 = nextInt();
		int m2 = nextInt();
		int t = nextInt();

		int[] allX = new int[2 + 2 * (m1 + m2)];
		int allPtr = 0;

		int[][] a = { new int[m1], new int[m2] };
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < a[i].length; j++) {
				a[i][j] = nextInt() - 1;
				allX[allPtr++] = a[i][j];
				allX[allPtr++] = a[i][j] + 1;
			}
		}
		allX[allPtr++] = 0;
		allX[allPtr++] = n;

		allX = unique(allX);

		int sz = allX.length - 1;
		boolean[][] f = new boolean[2][sz];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < a[i].length; j++) {
				int pos = Arrays.binarySearch(allX, a[i][j]);
				f[i][pos] = true;
			}
		}

		int[] last = { INF, INF };
		boolean[][] swap = new boolean[2][sz];

		for (int i = sz - 1; i >= 0; i--) {
			for (int j = 0; j < 2; j++) {
				if (f[j][i]) {
					last[j] = Math.min(last[j] - t, allX[i] - 1);
				}
			}

			int[] newLast = new int[2];

			for (int j = 0; j < 2; j++) {
				if (f[j ^ 1][i]) {
					continue;
				}
				if (last[j ^ 1] < allX[i]) {
					continue;
				}
				
				int tmp = f[j][i] ? Math.min(last[j ^ 1] - t, allX[i] - 1) : last[j ^ 1];
				if (tmp > last[j]) { 
					swap[j][i] = true;
					newLast[j] = tmp;
				}
			}

//			last = newLast;
			for (int j = 0; j < 2; j++) {
				if (swap[j][i]) {
					last[j] = newLast[j];
				}
			}
		}
		
//		System.err.println(last[0] + " " + last[1]);

		if (Math.max(last[0], last[1]) >= t - 1) {
			out.println("Yes");
		} else {
			out.println("No");
			return;
		}
		
		int lane = last[0] > last[1] ? 0 : 1;
		ArrayList<Integer> flips = new ArrayList<>();
		if (lane == 1) {
			flips.add(0);
		}
		
		ArrayList<Integer> shoot = new ArrayList<>();
		int shot = -1;
		int lastSwap = -1;
		
		for (int i = 0; i < sz; i++) {
			if (f[lane][i]) {
				shot = Math.max(shot + t, lastSwap);
				if (shot >= allX[i]) {
					throw new AssertionError();
				}
				shoot.add(shot + 1);
				shoot.add(lane + 1);
			}
			if (swap[lane][i]) {
				lastSwap = allX[i];
				flips.add(allX[i] + 1);
				lane ^= 1;
			}
		}
		out.println(flips.size());
		for (int x : flips) {
			out.print(x + " ");
		}
		out.println();
		out.println(shoot.size() / 2);
		for (int i = 0; i < shoot.size(); i += 2) {
			int x = shoot.get(i);
			int y = shoot.get(i + 1);
//			if (!(1 <= x && x <= n && 1 <= y && y <= 2)) {
//				throw new AssertionError();
//			}
			out.println(x + " " + y);
		}
		out.println();
	}
	

	static final int INF = Integer.MAX_VALUE / 2;

	int[] unique(int[] a) {
		Arrays.sort(a);
		int sz = 1;
		for (int i = 1; i < a.length; i++) {
			if (a[i] != a[sz - 1]) {
				a[sz++] = a[i];
			}
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

	D() throws IOException {
//		is = new FileInputStream("66");
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