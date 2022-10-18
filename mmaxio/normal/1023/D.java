import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class D {

	void submit() {
		int n = nextInt();
		int q = nextInt();
		
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		
		List<Integer>[] base = new List[q + 1];

		TreeSet<Integer> zs = new TreeSet<>();
		TreeSet<Integer> less = new TreeSet<>();
		
		for (int i = 1; i <= q; i++) {
			base[i] = new ArrayList<>();
		}
		for (int i = 0; i < n; i++) {
			if (a[i] != 0) {
				base[a[i]].add(i);
				less.add(i);
			} else {
				zs.add(i);
			}
		}
		
		if (base[q].isEmpty()) {
			if (zs.isEmpty()) {
				out.println("NO");
				return;
			}
			int v = zs.pollFirst();
			a[v] = q;
		}
		
		
		for (int v = q; v >= 1; v--) {
			for (int idx : base[v]) {
				less.remove(idx);
			}
			if (base[v].isEmpty()) {
				continue;
			}
			
			int low = base[v].get(0);
			int high = base[v].get(base[v].size() - 1);
			
			Integer tmp = less.higher(low);
			if (tmp != null && tmp < high) {
				out.println("NO");
				return;
			}
			
			while (true) {
				tmp = zs.higher(low);
				if (tmp != null && tmp < high) {
					a[tmp] = v;
					zs.remove(tmp);
				} else {
					break;
				}
			}
		}
		
		int idx = 0;
		while (a[idx] == 0) {
			idx++;
		}
		
		for (int i = 0; i < idx; i++) {
			a[i] = a[idx];
		}
		
		for (int i = idx, last = -1; i < n; i++) {
			if (a[i] != 0) {
				last = a[i];
			} else {
				a[i] = last;
			}
		}
		
		out.println("YES");
		for (int x : a) {
			out.print(x + " ");
		}
		out.println();
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