import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class A {

	static class Diff implements Comparable<Diff> {
		int id;
		int val;
		int idx;

		public Diff(int id, int val, int idx) {
			this.id = id;
			this.val = val;
			this.idx = idx;
		}

		@Override
		public int compareTo(Diff o) {
			if (val != o.val) {
				return Integer.compare(val, o.val);
			}
			return Integer.compare(id, o.id);
		}
	}

	void submit() {
		int[] a = new int[6];
		for (int i = 0; i < 6; i++) {
			a[i] = nextInt();
		}
		Arrays.sort(a);
		int n = nextInt();
		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			b[i] = nextInt();
		}
		if (n == 1) {
			out.println(0);
			return;
		}
		TreeSet<Diff> best = new TreeSet<>();
		for (int i = 0; i < n; i++) {
					best.add(new Diff(i, b[i] - a[5], 5));
		}
		int ans = Integer.MAX_VALUE;
		while (true) {
			Diff pop = best.pollFirst();
			ans = Math.min(ans, best.last().val - pop.val);
			if (pop.idx == 0) {
				break;
			}
			Diff push = new Diff(pop.id, b[pop.id] - a[pop.idx - 1], pop.idx - 1);
			best.add(push);
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