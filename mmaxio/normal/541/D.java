import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int K = 1_000_001;
	static boolean[] isPrime = new boolean[K];
	static {
		Arrays.fill(isPrime, true);
		for (int i = 2; i * i < K; i++) {
			if (isPrime[i]) {
				for (int j = i * i; j < K; j += i) {
					isPrime[j] = false;
				}
			}
		}
	}
	static final long BOUND = 1_000_000_000_000L;

	static final long INF = 1_000_000_000_000_000L;

	static long mul(long a, long b) {
		if (a > INF / b) {
			return INF;
		}
		return a * b;
	}

	static HashMap<Long, Integer> memo = new HashMap<>();
	static {
		for (int i = 2; i < K; i++) {
			if (isPrime[i]) {
				long p = i;
				while (p <= BOUND) {
					memo.put(p, i);
					p = mul(p, i);
				}
			}
		}
	}

	//
	// static long pow(long a, int b) {
	// long ret = 1;
	// for (; b > 0; b >>= 1) {
	// if ((b & 1) == 1) {
	// ret = mul(ret, a);
	// }
	// a = mul(a, a);
	// }
	// return ret;
	// }

	long getP(long x) {
		if (x <= 1) {
			return -1;
		}
		Integer tmp = memo.get(x);
		if (tmp != null) {
			return tmp;
		}
		if (BigInteger.valueOf(x).isProbablePrime(10)) {
			return x;
		}
		return -1;
	}

	long f(long x) {
		List<Long> divs = new ArrayList<>();
		for (int i = 1; (long) i * i <= x; i++) {
			// System.err.println(i);
			if (x % i == 0) {
				divs.add((long) i);
				if (i * i != x) {
					divs.add(x / i);
				}
			}
		}
		Collections.sort(divs);
//		System.err.println(divs);
		long[] corrP = new long[divs.size()];
		List<Long> allCorrP = new ArrayList<>();
		for (int i = 0; i < divs.size(); i++) {
			corrP[i] = getP(divs.get(i) - 1);
			if (corrP[i] != -1) {
				allCorrP.add(corrP[i]);
			}
		}
//		System.err.println(Arrays.toString(corrP));
		unique(allCorrP);
		for (int i = 0; i < divs.size(); i++) {
			if (corrP[i] != -1) {
				corrP[i] = Collections.binarySearch(allCorrP, corrP[i]);
			}
		}

		int n = divs.size();
		int m = allCorrP.size();

		List<Long>[] byP = new List[allCorrP.size()];
		for (int i = 0; i < m; i++) {
			byP[i] = new ArrayList<>();
		}

		for (int i = 0; i < n; i++) {
			if (corrP[i] != -1) {
				byP[(int) corrP[i]].add(divs.get(i));
			}
		}

		long[][] dp = new long[n][m + 1];
		dp[n - 1][0] = 1;

		for (int i = n - 1; i >= 0; i--) {
			long cur = divs.get(i);
			for (int j = 0; j < m; j++) {
				if (dp[i][j] == 0) {
					continue;
				}
				dp[i][j + 1] += dp[i][j];
				for (int k = 0; k < byP[j].size(); k++) {
					long d = byP[j].get(k);
					if (cur % d != 0) {
						continue;
					}
					int to = Collections.binarySearch(divs, cur / d);
					dp[to][j + 1] += dp[i][j];
				}
			}
		}

		return dp[0][m];
	}

	void unique(List<Long> a) {
		Collections.sort(a);
		int sz = 1;
		for (int i = 1; i < a.size(); i++) {
			if (!a.get(i).equals(a.get(sz - 1))) {
				a.set(sz, a.get(i));
				sz++;
			}
		}
		while (a.size() > sz) {
			a.remove(a.size() - 1);
		}
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		// System.err.println(memo.size());
		out.println(f(nextLong()));
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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