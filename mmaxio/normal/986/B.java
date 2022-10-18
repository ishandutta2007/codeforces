import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class B {

	void submit() {
		int n = nextInt();
		// if (n == 5) {
		// out.println("Petr");
		// return;
		// }

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt() - 1;
		}

		int cycles = eval(a);

		out.println(cycles % 2 == 0 ? "Petr" : "Um_nik");
	}

	int eval(int[] p) {
		int n = p.length;
		boolean[] vis = new boolean[n];
		int ret = 0;
		for (int i = 0; i < n; i++) {
			if (vis[i]) {
				continue;
			}
			ret++;
			for (int j = i; !vis[j]; j = p[j]) {
				vis[j] = true;
			}
		}
		return ret;
	}

	int[] gen(int n, int m) {
		int[] p = IntStream.range(0, n).toArray();
		for (int i = 0; i < m; i++) {
			int v = rand(0, n - 1);
			int u = (v + rand(1, n - 1)) % n;
			int tmp = p[v];
			p[v] = p[u];
			p[u] = tmp;
		}
		return p;
	}

	void test() {
		int n = 1003;

		TreeSet<Integer> set1 = new TreeSet<>();
		TreeSet<Integer> set2 = new TreeSet<>();

		for (int it = 0; it < 100; it++) {
			int[] p1 = gen(n, 3 * n);
			int[] p2 = gen(n, 7 * n + 1);

			int val1 = eval(p1);
			int val2 = eval(p2);

			set1.add(val1);
			set2.add(val2);
		}

		System.err.println(set1);
		System.err.println(set2);
	}

	void stress() {
		for (int tst = 0;; tst++) {
			if (false) {
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	B() throws IOException {
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
		new B();
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