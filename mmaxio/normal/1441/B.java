import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class B {

	static final int P = 998244353;

	void submit() {
		int n = nextInt();
		int m = nextInt();
		int[] es = new int[2 * m];
		int[] esRev = new int[2 * m];
		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			es[2 * i] = esRev[2 * i + 1] = v;
			es[2 * i + 1] = esRev[2 * i] = u;
		}

		int[][][] gs = new int[][][] { buildDGraph(es, n, m), buildDGraph(esRev, n, m) };

		long[] d = new long[n];
		Arrays.fill(d, INF);
		d[0] = 0;

		PriorityQueue<Distance> pq = new PriorityQueue<>();

		long ans = INF;

		for (int it = 0; it < MAGIC; it++) {
			int[][] g = gs[it % 2];
			for (int i = 0; i < n; i++) {
				if (d[i] != INF) {
					pq.add(new Distance(i, d[i]));
				}
			}
			while (!pq.isEmpty()) {
				Distance tmp = pq.poll();
				int v = tmp.node;
				long curD = tmp.dist;
				if (curD != d[v]) {
					continue;
				}

				for (int u : g[v]) {
					if (d[u] > curD + 1) {
						d[u] = curD + 1;
						pq.add(new Distance(u, d[u]));
					}
				}
			}

			ans = Math.min(ans, d[n - 1] + ((1 << it) - 1));
		}

		if (ans != INF) {
			out.println(ans % P);
			return;
		}

		long[] nd = new long[2 * n];
		Arrays.fill(nd, INF);
		for (int i = 0; i < n; i++) {
			if (d[i] == INF) {
				continue;
			}
			nd[2 * i] = getDist(MAGIC, (int) d[i]);
			pq.add(new Distance(2 * i, nd[2 * i]));
		}

		d = null;
		
		while (!pq.isEmpty()) {
			Distance tmp = pq.poll();
			int kek = tmp.node;
			long curD = tmp.dist;
			if (curD != nd[kek]) {
				continue;
			}

			int v = kek / 2;
			int bit = kek % 2;
			int[][] g = gs[bit];

			for (int u : g[v]) {
				if (nd[2 * u + bit] > curD + 1) {
					nd[2 * u + bit] = curD + 1;
					pq.add(new Distance(2 * u + bit, nd[2 * u + bit]));
				}
			}
			
			long kekDist = getDist(getFlips(curD) + 1, getMoves(curD));
			if (nd[kek ^ 1] > kekDist) {
				nd[kek ^ 1] = kekDist;
				pq.add(new Distance(kek ^ 1, nd[kek ^ 1]));
			}
		}
		
		ans = Math.min(nd[2 * (n - 1)], nd[2 * (n - 1) + 1]);
		
		int flips = getFlips(ans);
		int moves = getMoves(ans);
		
		ans = 1;
		for (int i = 0; i < flips; i++) {
			ans = ans * 2 % P;
		}
		ans--;
		if (ans < 0) {
			ans += P;
		}
		
		ans += moves;
		ans %= P;
		
		out.println(ans);


	}

	static final int MAGIC = 20;
	static final long INF = Long.MAX_VALUE / 3;

	static class Distance implements Comparable<Distance> {
		int node;
		long dist; // high bits = flips, low bits = moves

		@Override
		public int compareTo(Distance o) {
			return Long.compare(dist, o.dist);
		}

		public Distance(int node, long dist) {
			this.node = node;
			this.dist = dist;
		}
	}

	int getMoves(long dist) {
		return (int) dist;
	}

	int getFlips(long dist) {
		return (int) (dist >> 32);
	}

	long getDist(int flips, int moves) {
		return (((long) flips) << 32) | moves;
	}

	int[][] buildDGraph(int[] a, int n, int m) {
		if (m == 0) {
			if (a.length == 0) {
				return new int[n][0];
			} else {
				throw new AssertionError();
			}
		}
		if (a.length % m != 0 || a.length < 2 * m) {
			throw new AssertionError("Bad array length");
		}

		int[] deg = new int[n];
		int s = a.length / m;
		for (int i = 0; i < a.length; i += s) {
			deg[a[i]]++;
		}

		int[][] g = new int[n][];
		for (int i = 0; i < n; i++) {
			g[i] = new int[deg[i] * (s - 1)];
		}

		for (int i = s * (m - 1); i >= 0; i -= s) {
			int v = a[i];
			int u = a[i + 1];
			int pv = (--deg[v]) * (s - 1);
			g[v][pv] = u;
			System.arraycopy(a, i + 2, g[v], pv + 1, s - 2);
		}

		return g;
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