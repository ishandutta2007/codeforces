import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class G {

	static final int B = 1_000_001;

	int[] color;
	int n;

	int[][] g1, g2;

	void dfs(int v, int c) {
		color[v] = c;
		if (v < n) {
			for (int u : g1[v]) {
				if (color[u + n] == -1) {
					dfs(u + n, c);
				}
			}
		} else {
			for (int u : g2[v - n]) {
				if (color[u] == -1) {
					dfs(u, c);
				}
			}
		}
	}

	void submit() {
		n = nextInt();
		int q = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
//			if (!(2 <= a[i] && a[i] <= 1000000)) {
//				throw new AssertionError(String.format("a[%d]=%d", i, a[i]));
//			}
		}

//		boolean tst15 = a[0] == 958404;

		PrimeRoutines pr = new PrimeRoutines(B);

		int[] tmp = new int[10];

		int[] lowDivIdx = pr.lowDivIdx;
		int[] ps = pr.p;

		g1 = new int[n][];

		int[] cnt = new int[ps.length];

		for (int i = 0; i < n; i++) {
			int x = a[i];

			int sz = 0;
			while (x > 1) {
				int pIdx = lowDivIdx[x];
				if (sz == 0 || pIdx != tmp[sz - 1]) {
					tmp[sz++] = pIdx;
					cnt[pIdx]++;
				}
				x /= ps[pIdx];
			}
			g1[i] = Arrays.copyOf(tmp, sz);
		}

		g2 = new int[ps.length][];
		for (int i = 0; i < ps.length; i++) {
			g2[i] = new int[cnt[i]];
		}

		for (int i = 0; i < n; i++) {
			for (int j : g1[i]) {
				g2[j][--cnt[j]] = i;
			}
		}

		color = new int[n + ps.length];
		Arrays.fill(color, -1);

		int cols = 0;

		for (int i = 0; i < n; i++) {
			if (color[i] == -1) {
				dfs(i, cols++);
			}
		}

		HashSet<Long> goodPair = new HashSet<>();

//		System.err.println(Arrays.deepToString(g1));
//		System.err.println(Arrays.toString(Arrays.copyOf(color, n)));

		for (int i = 0; i < n; i++) {
			int x = a[i] + 1;

			int sz = 0;
			while (x > 1) {
				int pIdx = lowDivIdx[x];
				if (sz == 0 || pIdx != tmp[sz - 1]) {
					tmp[sz++] = pIdx;
				}
				x /= ps[pIdx];
			}

//			System.err.println(a[i] + " " + (a[i] + 1));
//			System.err.println(Arrays.toString(g1[i]));
//			System.err.println(Arrays.toString(Arrays.copyOf(tmp, sz)));

			for (int v : g1[i]) {
				for (int j = 0; j < sz; j++) {
					int u = tmp[j];
					if (color[n + u] != -1 && color[n + v] != color[n + u]) {

						int min = Math.min(color[n + v], color[n + u]);
						int max = Math.max(color[n + v], color[n + u]);

//						System.err.println(min + " <-> " + max);

						goodPair.add((long) min * cols + max);
					}
				}
			}
			
			for (int j1 = 0; j1 < sz; j1++) {
				for (int j2 = j1 + 1; j2 < sz; j2++) {
					int v = tmp[j1];
					int u = tmp[j2];
					if (color[n + u] != -1 && color[n + v] != color[n + u]) {

						int min = Math.min(color[n + v], color[n + u]);
						int max = Math.max(color[n + v], color[n + u]);

//						System.err.println(min + " <-> " + max);

						goodPair.add((long) min * cols + max);
					}
				}
			}

		}

		for (int tstN = 1; tstN <= q; tstN++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
//			if (tst15 && tstN == 2088) {
//				out.printf("v=%d,u=%d,a[v]=%d,a[u]=%d;;;", v, u, a[v], a[u]);
//			}

			// "v=90075,u=4529,a[v]=425431,a[u]=132971;;;2"
			// a[v] = 23*53*439
			// a[v]+1 = 2*7*71*107
			
			// a[u] = 132971
			// a[u]+1 = 2*3*7*1583
			
			// i = 147143
			// a[i] = 664854 = 2 * 3 * 29 * 3821 should unite
			// a[i]+1 = 5 * 132791
			// by uniting 5 and 132791
			if (color[v] == color[u]) {
				out.println(0);
			} else {
				int min = Math.min(color[v], color[u]);
				int max = Math.max(color[v], color[u]);

				long key = (long) min * cols + max;
				out.println(goodPair.contains(key) ? 1 : 2);
			}
		}

	}

	public class PrimeRoutines {

		int[] lowDivIdx;
		int[] lowDiv;
		int[] p;
		int N;

		public PrimeRoutines(int N) {
			this.N = N;
			p = new int[(int) (N / Math.log(N))];
			lowDivIdx = new int[N + 1];
			lowDiv = new int[N + 1];
			Arrays.fill(lowDivIdx, -1);
			int pCnt = 0;
			for (int i = 2; i <= N; i++) {
				if (lowDivIdx[i] == -1) {
					if (p.length == pCnt) {
						p = Arrays.copyOf(p, 2 * p.length);
					}
					lowDivIdx[i] = pCnt;
					lowDiv[i] = i;
					p[pCnt++] = i;
				}
				int toJ = Math.min(pCnt, lowDivIdx[i] + 1);
				for (int j = 0; j < toJ; j++) {
					int x = i * p[j];
					if (x > N) {
						break;
					}
					lowDivIdx[x] = j;
					lowDiv[x] = p[j];
				}
			}
			p = Arrays.copyOf(p, pCnt);
		}

		int[] divCount() {
			int[] ret = new int[N + 1];
			int[] tmp = new int[N + 1];
			ret[1] = 1;
			for (int i = 2; i <= N; i++) {
				int p = lowDiv[i];
				int j = i / p;
				if (p == lowDiv[j]) {
					int k = tmp[j];
					ret[i] = ret[j] / k * (k + 1);
					tmp[i] = k + 1;
				} else {
					ret[i] = ret[j] * 2;
					tmp[i] = 2;
				}
			}
			return ret;
		}

		List<Integer> getDivsNotSorted(int x) {
			List<Integer> ret = new ArrayList<Integer>(0);
			ret.add(1);
			while (x > 1) {
				int sz = ret.size();
				int pr = lowDiv[x];
				while (lowDiv[x] == pr) {
					int to = ret.size();
					for (int i = ret.size() - sz; i < to; i++) {
						ret.add(ret.get(i) * pr);
					}
					x /= pr;
				}
			}
			return ret;
		}

		int[] moebiusFunction() {
			int[] mu = new int[N + 1];
			mu[1] = 1;
			for (int i = 2; i <= N; i++) {
				int p = lowDiv[i];
				int j = i / p;
				if (p != lowDiv[j]) {
					mu[i] = -mu[j];
				}
			}
			return mu;
		}

		int[] eulerFunction() {
			int[] phi = new int[N + 1];
			phi[1] = 1;
			for (int i = 2; i <= N; i++) {
				int p = lowDiv[i];
				int j = i / p;
				phi[i] = phi[j] * (p != lowDiv[j] ? p - 1 : p);
			}
			return phi;
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

	G() throws IOException {
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
		new G();
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