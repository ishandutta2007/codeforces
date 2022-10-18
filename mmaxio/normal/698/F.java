import java.io.*;
import java.util.*;

public class F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int P = 1_000_000_007;

	void solve() throws IOException {
		int n = nextInt();
		int[] p = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			p[i] = nextInt();
		}

		PrimeRoutines pr = new PrimeRoutines(n);

		int[] to = new int[n + 1];
		int[] from = new int[n + 1];
		
		Arrays.fill(to, -1);
		Arrays.fill(from, -1);

		for (int i = 1; i <= n; i++) {
			if (p[i] == 0) {
				continue;
			}

			List<Integer> one = pr.go(i);
			List<Integer> two = pr.go(p[i]);

			if (one.size() != two.size()) {
				out.println(0);
				return;
			}
			
			int bigOne = one.get(one.size() - 1);
			int bigTwo = two.get(two.size() - 1);
			
			int c1 = f(bigOne, n);
			int c2 = f(bigTwo, n);
			
			if (c1 != c2) {
				out.println(0);
				return;
			}
			
			if (c1 != -1) {
				if ((to[bigOne] != -1 && to[bigOne] != bigTwo) || (from[bigTwo] != -1 && from[bigTwo] != bigOne)) {
					out.println(0);
					return;
				}
				to[bigOne] = bigTwo;
				from[bigTwo] = bigOne;
				
				one.remove(one.size() - 1);
				two.remove(two.size() - 1);
			}
			
			for (int j = 0; j < one.size(); j++) {
				if (!one.get(j).equals(two.get(j))) {
					out.println(0);
					return;
				}
			}
			
		}
		
		int[] sqFree = pr.squareFree();
		
		int[] cnt = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			if (p[i] == 0) {
				cnt[sqFree[i]]++;
			}
		}
		
//		System.err.println(Arrays.toString(cnt));
		
		int[] cnt2 = new int[n + 1]; // actually sqrt(n)
		for (int i = 1; i <= n; i++) {
			int c = f(i, n);
			if ((i == 1 || pr.lowDiv[i] == i) && c != -1 && to[i] == -1) {
				cnt2[f(i, n)]++;
			}
		}
		
		int[] fact = new int[n + 1];
		fact[0] = 1;
		for (int i = 1; i <= n; i++) {
			fact[i] = (int)((long)i * fact[i - 1] % P);
		}
		
		int ret = 1;
		for (int x : cnt) {
			ret = (int)((long)ret * fact[x] % P);
		}
		
		for (int x : cnt2) {
			ret = (int)((long)ret * fact[x] % P);
		}
		
		out.println(ret);
		
		// System.err.println(Arrays.toString(pr.p));
		// System.err.println(Arrays.toString(pr.lowDiv));
		// System.err.println(Arrays.toString(pr.lowDivIdx));
		// System.err.println(pr.divCount()[30]);
		// System.err.println(Arrays.toString(pr.eulerFunction()));
		// System.err.println(Arrays.toString(pr.moebiusFunction()));
	}
	
	int f(int x, int n) {
		return x == 1 ? 1 : ((long)x * x <= n ? -1 : n / x);
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
		
		int[] squareFree() {
			int[] ret = new int[N + 1];
			ret[1] = 1;
			for (int i = 2; i <= N; i++) {
				int p = lowDiv[i];
				int j = i / p;
				ret[i] = ret[j] * (p == lowDiv[j] ? 1 : p);
			}
			return ret;
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

		List<Integer> go(int x) {
			List<Integer> ret = new ArrayList<>(7);
			while (x > 1) {
				int y = lowDiv[x];
				ret.add(y);
				while (x % y == 0) {
					x /= y;
				}
			}
			if (ret.isEmpty()) {
				ret.add(1);
			}
			return ret;
		}
	}

	F() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new F();
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