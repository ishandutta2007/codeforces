import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class H {

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

	int[] lowDiv;

	static final int N = 5032107;

	void submit() {
		PrimeRoutines pr = new PrimeRoutines(N);
		lowDiv = pr.lowDiv;
		int n = nextInt();
		int qq = nextInt();

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		Query[] qs = new Query[qq];
		for (int i = 0; i < qq; i++) {
			int l = nextInt() - 1;
			int r = nextInt() - 1;
			qs[i] = new Query(l, r, i);
		}

		Arrays.sort(qs);

		int[][] last = new int[9][N];
		for (int[] row : last) {
			Arrays.fill(row, -1);
		}
		
		int[] where = new int[15];
		Arrays.fill(where, -1);
		
		int[] ps = new int[8];
		int pc = 0;
		
		int[] divs = new int[1 << 8];
		int[] btc = new int[1 << 8];
		for (int i = 0; i < btc.length; i++) {
			btc[i] = Integer.bitCount(i);
		}
		
		int ptr = 0;
		
		int[] ans = new int[qq];
		
		for (int i = 0; i < n; i++) {
			int x = a[i];
			
			pc = 0;
			while (x > 1) {
				int px = lowDiv[x];
				boolean odd = false;
				while (x % px == 0) {
					x /= px;
					odd ^= true;
				}
				if (odd) {
					ps[pc++] = px;
				}
			}
			
			divs[0] = 1;
			for (int j = 0; j < pc; j++) {
				int pj = ps[j];
				for (int jj = 0; jj < 1 << j; jj++) {
					divs[jj | (1 << j)] = divs[jj] * pj; 
  				}
			}
			
			for (int j = 0; j < 1 << pc; j++) {
				int diff = pc - btc[j];
				for (int k = 0; k < 8; k++) {
					where[k + diff] = Math.max(where[k + diff], last[k][divs[j]]);
				}
				last[diff][divs[j]] = Math.max(last[diff][divs[j]], i);
			}
			
			while (ptr < qq && qs[ptr].r == i) {
				int l = qs[ptr].l;
				
				for (int j = 0;; j++) {
					if (where[j] >= l) {
						ans[qs[ptr].id] = j;
						break;
					}
				}
				
				ptr++;
			}
 		}
		
		for (int x : ans) {
			out.println(x);
		}
	}

	static class Query implements Comparable<Query> {
		int l, r, id;

		public Query(int l, int r, int id) {
			this.l = l;
			this.r = r;
			this.id = id;
		}

		@Override
		public int compareTo(Query o) {
			return Integer.compare(r, o.r);
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