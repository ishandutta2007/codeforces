import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class E {

	interface Interactor {
		int getN();

		boolean ask(int x1, int y1, int x2, int y2);

		void answer(String s);
	}

	class SubmitInteractor implements Interactor {

		@Override
		public int getN() {
			return nextInt();
		}

		@Override
		public boolean ask(int x1, int y1, int x2, int y2) {
			out.println("? " + (x1 + 1) + " " + (y1 + 1) + " " + (x2 + 1) + " "
					+ (y2 + 1));
			out.flush();
			String ret = nextToken();
			return ret.equals("YES");
		}

		@Override
		public void answer(String s) {
			out.println("! " + s);
			out.flush();
		}

	}

	void solve(Interactor it) {
		int n = it.getN();
		int[] x1 = new int[n];
		int[] y1 = new int[n];

		for (int i = 0; i < n - 1; i++) {
			boolean can = it.ask(x1[i] + 1, y1[i], n - 1, n - 1);
			if (can) {
				x1[i + 1] = x1[i] + 1;
				y1[i + 1] = y1[i];
			} else {
				x1[i + 1] = x1[i];
				y1[i + 1] = y1[i] + 1;
			}
		}

		int[] x2 = new int[n];
		int[] y2 = new int[n];

		x2[n - 1] = n - 1;
		y2[n - 1] = n - 1;

		for (int i = n - 1; i >= 0; i--) {
			if (x1[i] == x2[i] || y1[i] == y2[i]) {
				StringBuilder ans = new StringBuilder();
				for (int j = 0; j < i; j++) {
					if (x1[j + 1] > x1[j]) {
						ans.append('D');
					} else {
						ans.append('R');
					}
				}
				char move = x1[i] == x2[i] ? 'R' : 'D';
				for (int j = 0; j < x2[i] + y2[i] - x1[i] - y1[i]; j++) {
					ans.append(move);
				}

				for (int j = i; j + 1 < n; j++) {
					if (x2[j + 1] > x2[j]) {
						ans.append('D');
					} else {
						ans.append('R');
					}
				}

				it.answer(ans.toString());
				return;
			}
			if (i == 0) {
				break;
			}

			boolean can = it.ask(x1[i - 1], y1[i - 1], x2[i], y2[i] - 1);
			if (!can) {
				x2[i - 1] = x2[i] - 1;
				y2[i - 1] = y2[i];
			} else {
				x2[i - 1] = x2[i];
				y2[i - 1] = y2[i] - 1;
			}
		}

		if (x1[n - 1] != x2[0] || y1[n - 1] != y2[0]) {
			throw new AssertionError();
		}
		
		StringBuilder ans = new StringBuilder();
		for (int j = 0; j < n - 1; j++) {
			if (x1[j + 1] > x1[j]) {
				ans.append('D');
			} else {
				ans.append('R');
			}
		}

		for (int j = 0; j < n - 1; j++) {
			if (x2[j + 1] > x2[j]) {
				ans.append('D');
			} else {
				ans.append('R');
			}
		}

		it.answer(ans.toString());
		return;
	}

	void submit() {
		solve(new SubmitInteractor());
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