import java.io.*;
import java.util.*;

public class G {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] help(int n) {
		int[] tmp = new int[n];
		for (int mask = 0; mask < (1 << n); mask++) {
			List<Integer> have = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				if (test(mask, i)) {
					have.add(i);
				}
			}
			for (int i = 0, j = have.size() - 1; i < j; i++, j--) {
				// tmp[have.get(i)]--;
				tmp[have.get(j)]++;
			}
		}
		return tmp;
	}

	boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	static final int P = 1_000_000_007;

	void solve() throws IOException {
		int n = nextInt();
		// int n = 300_000;
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			// a[i] = i + 1;
		}

		PrimeRoutines pr = new PrimeRoutines(300_000);
		HashMap<Integer, List<Integer>> map = new HashMap<>();
		for (int x : a) {
			while (x != 1) {
				int p = pr.lowDiv[x];
				int c = 0;
				while (x % p == 0) {
					x /= p;
					c++;
				}
				List<Integer> lst = map.get(p);
				if (lst == null) {
					lst = new ArrayList<>();
					map.put(p, lst);
				}
				lst.add(c);
			}
		}

		int[] inv = new int[n];
		inv[1] = 1;
		for (int x = 2; x < n; x++) {
			inv[x] = P - (int) ((long) (P / x) * inv[P % x] % P);
		}

		int[] ways = new int[n];
		int comb = 1;
		ways[1] = 1;
		for (int i = 1; i < n - 1; i++) {
			comb = (int) ((long) comb * (n - i) % P * inv[i] % P);
			ways[i + 1] = ways[i] + comb;
			if (ways[i + 1] >= P) {
				ways[i + 1] -= P;
			}
		}
		
		int[] mult = new int[n];
		for (int i = 0; i < n; i++) {
			mult[i] = ways[n - 1 - i] - ways[i];
			if (mult[i] < 0) {
				mult[i] += P;
			}
		}

//		System.err.println(Arrays.toString(mult));

		int ret = 0;

		for (Map.Entry<Integer, List<Integer>> e : map.entrySet()) {
			List<Integer> tmp = e.getValue();
			Collections.sort(tmp);
			Collections.reverse(tmp);
			for (int i = 0; i < tmp.size(); i++) {
				ret += (int)((long)tmp.get(i) * mult[i] % P);
				if (ret >= P) {
					ret -= P;
				}
			}
		}
		
		out.println(ret);

	}

	G() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		// for (int n = 1; n <= 10; n++) {
		// System.err.println(Arrays.toString(help(n)));
		// }

//		System.err.println(Arrays.toString(help(5)));

		solve();

		out.close();
	}

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
	}

	public static void main(String[] args) throws IOException {
		new G();
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