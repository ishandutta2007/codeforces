import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class H {

	boolean solve() {
		int alph = nextInt();
		int n = nextInt();

		int[][] a = new int[n][];
		int tot = 0;
		for (int i = 0; i < n; i++) {
			int k = nextInt();
			int[] che = a[i] = new int[k];
			for (int j = 0; j < k; j++) {
				che[j] = nextInt() - 1;
			}
			tot += k;
		}

		int r = (int) Math.sqrt(tot * .7);

		for (int i = 0, j = n - 1;;) {
			while (i < j && a[i].length > r) {
				i++;
			}
			while (i < j && a[j].length <= r) {
				j--;
			}
			if (i == j) {
				break;
			}

			int[] tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
		
		ArrayList<Integer>[] d = new ArrayList[alph];
		for (int i = 0; i < alph; i++) {
			d[i] = new ArrayList<>();
		}

		
		for (int i = 0; i < n; i++) {
			int[] b = a[i];
			if (b.length > r) {
				continue;
			}
			for (int j = 0; j < b.length - 1; j++) {
				int idx = b[j];
				d[idx].add(i);
				d[idx].add(j);
			}
		}
		
		int[] map = new int[alph];
		Arrays.fill(map, -1);
		
		for (int i = 0; i < alph; i++) {
			ArrayList<Integer> shit = d[i]; 
			for (int j = 0; j < shit.size(); j += 2) {
				int where = shit.get(j);
				int from = shit.get(j + 1);
				
				int[] aW = a[where];
				int put = aW[from + 1];
				
				for (int k = from + 1; k < aW.length; k++) {
					int val = aW[k];
					if (map[val] != -1 && map[val] != put) {
						return true; 
					}
					map[val] = put;
				}
				
			}
			
			for (int j = 0; j < shit.size(); j += 2) {
				int where = shit.get(j);
				int from = shit.get(j + 1);
				
				int[] aW = a[where];
				
				for (int k = from + 1; k < aW.length; k++) {
					map[aW[k]] = -1;
				}
			}
		}

		int[] id = new int[alph];
		Arrays.fill(id, -2);

		for (int i = 0; i < n; i++) {
			int[] b = a[i];
			if (b.length <= r) {
				break;
			}
			for (int j = 0; j < b.length; j++) {
				id[b[j]] = j;
			}

			for (int j = i + 1; j < n; j++) {
				if (clash(a[j], id)) {
					return true;
				}
				
			}

			for (int j = 0; j < b.length; j++) {
				id[b[j]] = -2;
			}
		}

		return false;
	}

	boolean clash(int[] a, int[] f) {
		int prev = f[a[0]];
		int curMin = prev == -2 ? Integer.MAX_VALUE : prev;
		for (int i = 1; i < a.length; i++) {
			int now = f[a[i]];
			if (now != prev + 1 && now > curMin) {
				return true;
			}
			if (now != -2) {
				curMin = Math.min(curMin, now);
			}

			prev = now;
		}
		return false;
	}

	void submit() {
		int t = nextInt();
		while (t-- > 0) {
			out.println(solve() ? "Human" : "Robot");
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

	H() throws IOException {
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
		new H();
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