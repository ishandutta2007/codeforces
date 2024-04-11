import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class F {

	void submit() {
		int q = nextInt();

		int[] ts = new int[q];
		int[] xs = new int[q];
		int[] ys = new int[q];

		long[] ls = new long[q];

		for (int i = 0; i < q; i++) {
			ts[i] = nextInt();
			xs[i] = nextInt();
			ys[i] = nextInt();

			ls[i] = sqr(xs[i]) + sqr(ys[i]);
		}

		HashMap<Long, Integer> map = new HashMap<>();
		int[] cnt = new int[q];

		for (int i = 0; i < q; i++) {
			if (ts[i] == 1) {
				if (!map.containsKey(ls[i])) {
					map.put(ls[i], map.size());
				}

				cnt[map.get(ls[i])]++;
			}
		}

		int[][] a = new int[q][];
		int[] sz = new int[q];
		for (int i = 0; i < q; i++) {
			a[i] = new int[2 * cnt[i]];
		}

		HashMap<Pair, Integer> ans = new HashMap<>();

		int total = 0;

		for (int i = 0; i < q; i++) {
			int x = xs[i];
			int y = ys[i];
			if (ts[i] == 3) {
				int g = gcd(x, y);
				out.println(total - ans.getOrDefault(new Pair(x / g, y / g), 0));
				continue;
			}

			int idx = map.get(ls[i]);

			if (ts[i] == 1) {
				total++;
				int s = sz[idx];
				int[] cc = a[idx];
				cc[s] = x;
				cc[s + 1] = y;
				sz[idx] += 2;
				s += 2;

				for (int j = 0; j < s; j += 2) {

					int sx = x + cc[j];
					int sy = y + cc[j + 1];

					int g = gcd(sx, sy);

					Pair p = new Pair(sx / g, sy / g);
					ans.merge(p, j == s - 2 ? 1 : 2, Integer::sum);
				}
			} else {
				total--;
				int s = sz[idx];
				int[] cc = a[idx];

				int swap = -1;
				
				for (int j = 0; j < s; j += 2) {

					int sx = x + cc[j];
					int sy = y + cc[j + 1];

					if (x == cc[j] && y == cc[j + 1]) {
						swap = j;
					}

					int g = gcd(sx, sy);

					Pair p = new Pair(sx / g, sy / g);
					ans.merge(p, swap == j ? -1 : -2, Integer::sum);
				}
				
				int tmp = cc[swap];
				cc[swap] = cc[s - 2];
				cc[s - 2] = tmp;
				
				tmp = cc[swap + 1];
				cc[swap + 1] = cc[s - 1];
				cc[s - 1] = tmp;
				
				sz[idx] -= 2;
			}

//			System.err.println(ans);

		}

	}

	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	static class Pair {
		int x, y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int hashCode() {
			return (int) (100007L * x + y);
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pair other = (Pair) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

		@Override
		public String toString() {
			return "(" + x + ", " + y + ")";
		}
	}

	long sqr(long x) {
		return x * x;
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
	static final int C = 5;

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