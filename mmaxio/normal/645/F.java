import java.io.*;
import java.util.*;

public class F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	public class PrimeRoutines {

		int[] lowDiv;
		int[] p = new int[1];

		int N;

		public PrimeRoutines(int N) {
			this.N = N;
			lowDiv = new int[N + 1];
			Arrays.fill(lowDiv, -1);
			int pCnt = 0;
			for (int i = 2; i <= N; i++) {
				if (lowDiv[i] == -1) {
					if (p.length == pCnt) {
						p = Arrays.copyOf(p, 2 * p.length);
					}
					p[pCnt++] = i;
					lowDiv[i] = i;
				}
				for (int j = 0; j < pCnt && p[j] <= lowDiv[i]; j++) {
					int x = i * p[j];
					if (x > N) {
						break;
					}
					lowDiv[x] = p[j];
				}
			}
			p = Arrays.copyOf(p, pCnt);
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
				int j = i / lowDiv[i];
				if (lowDiv[i] != lowDiv[j]) {
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
				if (lowDiv[i] != lowDiv[j]) {
					phi[i] = phi[j] * (p - 1);
				} else {
					phi[i] = phi[j] * p;
				}
			}
			return phi;
		}
	}

	static final int P = 1_000_000_007;
	static final int N = 1_000_000;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		int q = nextInt();

		PrimeRoutines pr = new PrimeRoutines(N);

		int[] phi = pr.eulerFunction();

		int[] cnt = new int[N + 1];

		int[] inv = new int[N + 1];
		inv[1] = 1;
		for (int x = 2; x <= N; x++) {
			inv[x] = P - (int) ((long) (P / x) * inv[P % x] % P);
		}

		int[] ways = new int[n + q + 1];
		if (k < ways.length) {
			ways[k] = 1;
		}

		for (int i = k + 1; i < ways.length; i++) {
			ways[i] = (int) ((long) ways[i - 1] * i % P * inv[i - k] % P);
		}

		int res = 0;

		for (int i = 0; i < n; i++) {
			int x = nextInt();
			List<Integer> divsX = pr.getDivsNotSorted(x);

			for (int d : divsX) {
				cnt[d]++;
				int delta = ways[cnt[d]] - ways[cnt[d] - 1];
				if (delta < 0) {
					delta += P;
				}
				res += (int) ((long) phi[d] * delta % P);
				if (res >= P) {
					res -= P;
				}
			}
		}
		
		for (int i = 0; i < q; i++) {
			int x = nextInt();
			List<Integer> divsX = pr.getDivsNotSorted(x);

			for (int d : divsX) {
				cnt[d]++;
				int delta = ways[cnt[d]] - ways[cnt[d] - 1];
				if (delta < 0) {
					delta += P;
				}
				res += (int) ((long) phi[d] * delta % P);
				if (res >= P) {
					res -= P;
				}
			}
			out.println(res);
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