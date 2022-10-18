import java.io.*;
import java.math.*;
import java.util.*;

public class C {

	int[][] go(int[] arr) {
		int n = arr.length;
		int[] aux = new int[n + 1];
		Arrays.fill(aux, Integer.MAX_VALUE);
		aux[0] = Integer.MIN_VALUE;

		int[] justAns = new int[n];
		int[] takeAns = new int[n];
		int ans = 0;

		for (int i = 0; i < n; i++) {
			int x = arr[i];
			int low = 0; // <=
			int high = ans + 1; // >
			while (high - low > 1) {
				int mid = (low + high) >> 1;
				if (aux[mid] > x) {
					high = mid;
				} else {
					low = mid;
				}
			}
			aux[high] = x;
			if (high > ans) {
				ans = high;
			}
			justAns[i] = ans;
			takeAns[i] = high;
		}
		return new int[][] { justAns, takeAns };
	}

	void submit() {
		int n = nextInt();
		int m = nextInt();
		int[] arr = new int[m];
		for (int i = 0; i < n; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			arr[x]++;
			if (y < m - 1) {
				arr[y + 1]--;
			}
		}

		for (int i = 1; i < m; i++) {
			arr[i] += arr[i - 1];
		}

//		System.err.println(Arrays.toString(arr));
		int[][] inc = go(arr);
		int[][] dec = go(reverse(arr));
		dec[0] = reverse(dec[0]);
		dec[1] = reverse(dec[1]);

		// System.err.println(Arrays.toString(inc));
		// System.err.println(Arrays.toString(dec));

		int ans = 0;
		for (int mid = 0; mid < m; mid++) {
			int skipMid = 0;
			skipMid += mid > 0 ? inc[0][mid - 1] : 0;
			skipMid += mid < m - 1 ? dec[0][mid + 1] : 0;
			ans = Math.max(ans, skipMid);

			int takeMid = inc[1][mid] + dec[1][mid] - 1;
			ans = Math.max(ans, takeMid);
		}
		
		out.println(ans);
	}

	int[] reverse(int[] arr) {
		int[] ret = new int[arr.length];
		for (int i = 0, j = arr.length - 1; i < arr.length; i++, j--) {
			ret[j] = arr[i];
		}
		return ret;
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

	C() throws IOException {
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