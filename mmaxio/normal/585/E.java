import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	public class PrimeRoutines {

		int[] lowDiv;
		int[] p = new int[1];

		public PrimeRoutines(int N) {
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

		int[] getMeb() {
			int[] meb = new int[N + 1];
			meb[1] = 1;
			for (int i = 2; i <= N; i++) {
				int ld = lowDiv[i];
				int j = i / ld;
				if (ld == lowDiv[j]) {
					meb[i] = 0;
				} else {
					meb[i] = -meb[j];
				}
			}
			return meb;
		}
	}

	static final int N = 10_000_001;
	static final int P = 1_000_000_007;

	void solve() throws IOException {
		int n = nextInt();

		int[] c = new int[N];
		for (int i = 0; i < n; i++) {
			c[nextInt()]++;
		}

		int[] d = new int[N];
		for (int i = 1; i < N; i++) {
			for (int j = i; j < N; j += i) {
				d[i] += c[j];
			}
		}

		PrimeRoutines pr = new PrimeRoutines(N);
		int[] meb = pr.getMeb();

		int[] p2 = new int[n + 1];
		p2[0] = 1;
		for (int i = 1; i <= n; i++) {
			p2[i] = p2[i - 1] * 2 % P;
		}

		int ret = 0;
		for (int i = 2; i < N; i++) {
			if (meb[i] == 0 || d[i] == 0) {
				continue;
			}
//			System.err.println(i + " " + d[i]);
			int delta = (int) ((long) (n - d[i]) * (p2[d[i]] - 1) % P);
			if (meb[i] == -1) {
				ret += delta;
				if (ret >= P) {
					ret -= P;
				}
			} else {
				ret -= delta;
				if (ret < 0)
					ret += P;
			}
		}

		out.println(ret);
	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
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