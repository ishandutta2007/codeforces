import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class A {

	int[] next;
	int[] to;
	int[] head;

	void submit() {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		int s = nextInt();

		next = new int[2 * m];
		to = new int[2 * m];
		head = new int[n];
		Arrays.fill(head, -1);
		
		
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt() - 1;
		}

		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			to[2 * i] = u;
			next[2 * i] = head[v];
			head[v] = 2 * i;
			
			to[2 * i + 1] = v;
			next[2 * i + 1] = head[u];
			head[u] = 2 * i + 1;
		}
		
		int[][] d = new int[k][];
		int[] que = new int[n];
		for (int i = 0; i < k; i++) {
			d[i] = new int[n];
			Arrays.fill(d[i], INF);
			int qh = 0, qt = 0;
			for (int j = 0; j < n; j++) {
				if (a[j] == i) {
					d[i][j] = 0;
					que[qt++] = j;
				}
			}
			while (qh < qt) {
				int v = que[qh++];
				for (int e = head[v]; e >= 0; e = next[e]) {
					int u = to[e];
					if (d[i][u] > d[i][v] + 1) {
						d[i][u] = d[i][v] + 1;
						que[qt++] = u;
					}
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			int[] arr = new int[k];
			for (int j = 0; j < k; j++) {
				arr[j] = d[j][i];
			}
			Arrays.sort(arr);
			long outp = 0;
			for (int j = 0; j < s; j++) {
				outp += arr[j];
			}
			out.print(outp + " ");
		}
		out.println();
	}
	
	static final int INF = Integer.MAX_VALUE / 3;

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