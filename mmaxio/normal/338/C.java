import java.io.*;
import java.util.*;

public class C {

	static final int INF = Integer.MAX_VALUE / 3;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static int N = 1_000_000;
	static int ROOT = 1_000;
	static boolean[] isPrime = new boolean[N + 1];
	static List<Integer> primes = new ArrayList<>(78498);
	static {
		Arrays.fill(isPrime, true);
		for (int i = 2; i <= N; i++) {
			if (isPrime[i]) {
				primes.add(i);
				if (i <= ROOT) {
					for (int j = i * i; j <= N; j += i) {
						isPrime[j] = false;
					}
				}
			}
		}
	}

	int n;
	long[] a;
	int[] cntPrime;

	void solve() throws IOException {
		n = nextInt();
		a = new long[n];

		for (int i = 0; i < n; i++) {
			a[i] = nextLong();
		}

		Arrays.sort(a);
		cntPrime = new int[n];
		for (int i = 0; i < n; i++) {
			cntPrime[i] = sumPrimePowers(a[i]);
		}

		int ans = go(n - 1, new ArrayList<Long>(), new ArrayList<Integer>(), 0);
		out.println(ans);
	}

	int go(int i, List<Long> vs, List<Integer> sum, int roots) {
		if (i == -1) {
			int ret = 0;

			for (int val : sum) {
				ret += val + 1;
			}

			if (roots > 1)
				ret++;

			return ret;
		}

		int ret = Integer.MAX_VALUE;

		long add = a[i];
		for (int j = 0; j < vs.size(); j++) {
			if (vs.get(j) % add == 0) {
				List<Long> newVs = new ArrayList<>(vs);
				List<Integer> newSum = new ArrayList<Integer>(sum);

				newVs.set(j, vs.get(j) / add);
				newSum.set(j, sum.get(j) - cntPrime[i]);
				if (sumPrimePowers(add) > 1) {
					newVs.add(add);
					newSum.add(cntPrime[i]);
				} else {
					newVs.add(1L);
					newSum.add(0);
				}
				ret = Math.min(ret, go(i - 1, newVs, newSum, roots));
			}
		}
		if (sumPrimePowers(add) == 1) {
			vs.add(1L);
			sum.add(0);
		} else {
			vs.add(add);
			sum.add(cntPrime[i]);
		}
		ret = Math.min(ret, go(i - 1, vs, sum, roots + 1));
		return ret;
	}

	int sumPrimePowers(long x) {
		int ret = 0;
		for (int i = 0; i < primes.size() && x > 1; i++) {
			int p = primes.get(i);
			while (x % p == 0) {
				x /= p;
				ret++;
			}
		}
		if (x != 1)
			ret++;
		return ret;
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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