import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	PrimeRoutines pr = new PrimeRoutines(1_000_000);

	static final int P = 1_000_000_007;

	static int[] inv = new int[1_000_001];
	static {
		inv[0] = 0;
		inv[1] = 1;
		for (int i = 2; i < inv.length; i++) {
			inv[i] = P - (int) ((long) (P / i) * inv[P % i] % P);
		}
	}

	int f(int r, int n) {
		int[] arr = pr.getSignature(n);
		if (r == 0) {
			return (1 << arr.length) % P;
		}

		if (n == 1) {
			return 1 % P;
		}

		int max = 0;
		for (int x : arr) {
			max = Math.max(max, x);
		}

		int[] ways = new int[max + 1];
		ways[0] = 1;
		for (int i = 1; i <= max; i++) {
			ways[i] = (int) ((long) ways[i - 1] * (r - 1 + i) % P * inv[i] % P);
		}

		int[] pref = new int[max + 2];
		for (int i = 0; i <= max; i++) {
			pref[i + 1] = pref[i] + ways[i];
			if (pref[i + 1] >= P) {
				pref[i + 1] -= P;
			}
		}

		int ret = 1;
		for (int x : arr) {
			long mult = (ways[x] + 2L * pref[x]) % P;
			ret = (int) ((long) ret * mult % P);
		}

		return ret;

	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		int q = nextInt();
		while (q-- > 0) {
			int r = nextInt();
			int n = nextInt();
			out.println(f(r, n));
		}
		
//		for (int i = 0; i < 1_000_000; i++) {
//			out.println(f(1_000_000, 2 * 3 * 5 * 7 * 11 * 13 * 17));
//		}
		
		out.close();
	}

	public class PrimeRoutines {

		int[] lowDivIdx;
		int[] lowDiv;
		int[] p;
		int N;

		int[] getSignature(int x) {
			int[] ret = new int[10];
			int ptr = 0;
			while (x > 1) {
				int ld = lowDiv[x];
				while (lowDiv[x] == ld) {
					ret[ptr]++;
					x /= ld;
				}
				ptr++;
			}
			return Arrays.copyOf(ret, ptr);
		}

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

	public static void main(String[] args) throws IOException {
		new E();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}