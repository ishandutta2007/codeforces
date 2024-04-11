import java.io.*;
import java.util.*;

public class D {

	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	static final int INF = Integer.MAX_VALUE / 3;
	static final int C = 31;

	int fast(int[] a) {
		int n = a.length;
		int[] pref = new int[n + 1];
		for (int i = 0; i < n; i++) {
			pref[i + 1] = pref[i] + a[i];
		}

		int res = INF;
		int last1 = -1;

		int[] nxt1 = new int[n + 1];
		nxt1[n] = -1;
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] == 1) {
				nxt1[i] = i;
			} else {
				nxt1[i] = nxt1[i + 1];
			}
		}

		for (int i = 0; i <= n; i++) {
			res = Math.min(res, go(pref[i], pref[n] - pref[i]));
			if (last1 != -1) {
				res = Math.min(
						res,
						go(pref[last1], 1, pref[i] - pref[last1 + 1], pref[n]
								- pref[i]));
			}
			if (nxt1[i] != -1) {
				res = Math.min(
						res,
						go(pref[i], pref[nxt1[i]] - pref[i], 1, pref[n]
								- pref[nxt1[i] + 1]));
			}
			if (i != n && a[i] == 1) {
				last1 = i;
			}
		}
		return res;
	}

	int go(int a, int b) {
		int spent = 10 * a;
		int card = a;
		return spent + 10 * b - Math.min(10 * b, card);
	}

	int go(int a, int b, int c, int d) {
		int spent = 10 * a;
		int card = a;

		int use = Math.min(card, 10 * b);
		card -= use;
		spent += 10 * b - use;

		spent += 10 * c;
		card += c;

		use = Math.min(card, 10 * d);
		card -= use;
		spent += 10 * d - use;
		return spent;
	}

	int fastPoly(int[] a) {
		int[] dp = new int[C];
		Arrays.fill(dp, INF);
		dp[0] = 0;

		for (int x : a) {
			int[] nxt = new int[C];
			Arrays.fill(nxt, INF);
			for (int was = 0; was < C; was++) {
				if (dp[was] == INF) {
					continue;
				}
				// full
				if (was + x < C) {
					nxt[was + x] = Math.min(nxt[was + x], dp[was] + x * 10);
				}

				// ez
				int use = Math.min(was, x * 10);
				nxt[was - use] = Math.min(nxt[was - use], dp[was] + x * 10
						- use);
			}
			dp = nxt;
		}
		int ret = INF;
		for (int x : dp) {
			ret = Math.min(ret, x);
		}
		return ret;
	}
	
	int slowPoly(int[] a) {
		int sz = a.length * 2 + 1;
		int[] dp = new int[sz];
		Arrays.fill(dp, INF);
		dp[0] = 0;

		for (int x : a) {
			int[] nxt = new int[sz];
			Arrays.fill(nxt, INF);
			for (int was = 0; was < sz; was++) {
				if (dp[was] == INF) {
					continue;
				}
				// full
				if (was + x < sz) {
					nxt[was + x] = Math.min(nxt[was + x], dp[was] + x * 10);
				}

				// ez
				int use = Math.min(was, x * 10);
				nxt[was - use] = Math.min(nxt[was - use], dp[was] + x * 10
						- use);
			}
			dp = nxt;
		}
		int ret = INF;
		for (int x : dp) {
			ret = Math.min(ret, x);
		}
		return ret;
	}

	int slow(int[] a) {
		int n = a.length;
		int res = Integer.MAX_VALUE;

		int bestMask = -1;

		int bestFast = Integer.MAX_VALUE;

		for (int mask = 0; mask < (1 << n); mask++) {
			int card = 0;
			int spent = 0;

			boolean ez1 = false;
			boolean ez2 = false;

			boolean goodMask = true;

			for (int i = 0; i < n; i++) {
				if (test(mask, i)) {
					spent += a[i] * 10;
					card += a[i];
					if ((a[i] == 1) && ez1) {
						goodMask = false;
					}
					if ((a[i] == 2) && ez2) {
						goodMask = false;
					}
				} else {
					if (a[i] == 1) {
						ez1 = true;
					} else {
						ez2 = true;
					}
					int use = Math.min(card, a[i] * 10);
					card -= use;
					spent += a[i] * 10 - use;
				}
			}
			if (spent < res) {
				bestMask = mask;
			}
			if (goodMask) {
				bestFast = Math.min(bestFast, spent);
			}
			res = Math.min(res, spent);
		}
		// if (bestFast != res) {
		// System.err.println(Arrays.toString(a));
		// System.err.println(res);
		// System.err.println(bestFast);
		// System.err.println(bestMask);
		// throw new AssertionError();
		// }
		System.err.println(Integer.toBinaryString(bestMask));
		return res;
	}

	void submit() {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt() / 1000;
		}
//		out.println(fast(a) * 100);
		out.println(fastPoly(a) * 100);
	}

	void preCalc() {

	}

	void stressExp() {
		for (int n = 1;; n++) {
			System.err.println(n);
			int[] a = new int[n];
			for (int mask = 0; mask < 1 << n; mask++) {
				for (int i = 0; i < n; i++) {
					a[i] = test(mask, i) ? 1 : 2;
				}
				if (fastPoly(a) != fast(a)) {
					System.err.println(Arrays.toString(a));
					System.err.println(slowPoly(a));
					System.err.println(fast(a));
					System.err.println(slow(a));
					throw new AssertionError();
				}
				// slow(a);
			}
		}
	}

	void stressPoly() {
		for (int tst = 1;; tst++) {
			int n = rand(1, 50);
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = rand(1, 2);
			}
			if (slowPoly(a) != fast(a)) {
				System.err.println(Arrays.toString(a));
				System.err.println(slowPoly(a));
				System.err.println(fast(a));
				System.err.println(slow(a));
				throw new AssertionError();
			}
			// slow(a);
			System.err.println(tst);
		}
	}

	void test() {
		fast(new int[] { 2, 2 });
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		 submit();
//		 stressExp();
//		 stressPoly();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new D();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}