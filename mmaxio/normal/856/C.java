import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C {

	static final int P = 998244353;

	static final int N = 5000;

	int[] fact;
	int[] invFact;

	int solve(int[][] a) {

		int odd = 0;
		for (int x : a[1]) {
			odd += x;
		}

		int evenSum = 0;
		int evenCnt = 0;
		for (int i = 0; i < 11; i++) {
			evenSum += i * a[0][i];
			evenCnt += a[0][i];
		}

		if (odd == 0) {
			return evenSum % 11 == 0 ? fact[evenCnt] : 0;
		}

		int[] oddRems = new int[odd];
		int ptr = 0;

		for (int rem = 0; rem < 11; rem++) {
			for (int i = 0; i < a[1][rem]; i++) {
				oddRems[ptr++] = rem;
			}
		}

		ptr = 0;
		int[] evenRems = new int[evenCnt];
		for (int rem = 0; rem < 11; rem++) {
			for (int i = 0; i < a[0][rem]; i++) {
				evenRems[ptr++] = rem;
			}
		}

		int pos = (odd + 1) / 2;
		int neg = odd / 2;

		int[][][] dp = new int[pos + 1][neg + 1][11];

		dp[0][0][0] = 1;

		for (int i = 0; i <= pos; i++) {
			for (int j = 0; j <= neg; j++) {
				if (i == pos && j == neg) {
					continue;
				}

				int now = oddRems[i + j];

				if (i < pos) {

					for (int rem = 0; rem < 11; rem++) {
						dp[i + 1][j][(rem + now) % 11] += dp[i][j][rem];
						if (dp[i + 1][j][(rem + now) % 11] >= P) {
							dp[i + 1][j][(rem + now) % 11] -= P;
						}
					}

				}

				if (j < neg) {
					for (int rem = 0; rem < 11; rem++) {
						dp[i][j + 1][(rem + 11 - now) % 11] += dp[i][j][rem];
						if (dp[i][j + 1][(rem + 11 - now) % 11] >= P) {
							dp[i][j + 1][(rem + 11 - now) % 11] -= P;
						}
					}
				}
			}
		}

		int[] dpResult = dp[pos][neg];

		// *pos! * neg!

		dp = new int[evenCnt + 1][evenCnt + 1][11];
		dp[0][0] = dpResult;

		for (int i = 0; i <= evenCnt; i++) {
			for (int j = 0; j <= evenCnt; j++) {
				if (i + j >= evenCnt) {
					continue;
				}

				int now = evenRems[i + j];

				for (int rem = 0; rem < 11; rem++) {
					dp[i + 1][j][(rem + now) % 11] += dp[i][j][rem];
					if (dp[i + 1][j][(rem + now) % 11] >= P) {
						dp[i + 1][j][(rem + now) % 11] -= P;
					}
				}

				for (int rem = 0; rem < 11; rem++) {
					dp[i][j + 1][(rem + 11 - now) % 11] += dp[i][j][rem];
					if (dp[i][j + 1][(rem + 11 - now) % 11] >= P) {
						dp[i][j + 1][(rem + 11 - now) % 11] -= P;
					}
				}
			}
		}

		int posInto, negInto;
		posInto = (odd + 2) / 2;
		negInto = (odd + 1) / 2;

		int ret = 0;
		for (int i = 0; i <= evenCnt; i++) {
			int j = evenCnt - i;

			int ways = dp[i][j][0];
			
			ret += (int) ((long) ways * distr(i, posInto) % P
					* distr(j, negInto) % P);
			if (ret >= P) {
				ret -= P;
			}
		}

		ret = (int) ((long) ret * fact[pos] % P * fact[neg] % P);
		return ret;
	}

	int distr(int x, int y) {
		return (int) ((long) fact[x + y - 1] * invFact[y - 1] % P);
	}

	int solve(int[] a) {
		int[][] c = new int[2][11];
		for (int x : a) {
			c[Integer.toString(x).length() % 2][x % 11]++;
		}
		return solve(c);
	}

	void submit() {
		int t = nextInt();
		while (t-- > 0) {
			int n = nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			out.println(solve(a));
		}
	}

	int slow(int[] a) {
		int n = a.length;
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}

		int ret = 0;

		do {
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < n; i++) {
				sb.append(a[p[i]]);
			}
			if (new BigInteger(sb.toString()).mod(BigInteger.valueOf(11))
					.signum() == 0) {
				ret++;
			}
		} while (nextPermutation(p));
		return ret;
	}

	static boolean nextPermutation(int[] a) {
		int n = a.length;
		int ptr = n - 1;
		while (ptr > 0 && a[ptr - 1] >= a[ptr]) {
			ptr--;
		}

		for (int i = ptr, j = n - 1; i < j; i++, j--) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}

		if (ptr == 0) {
			return false;
		}

		for (int i = ptr;; i++) {
			if (a[ptr - 1] < a[i]) {
				int tmp = a[ptr - 1];
				a[ptr - 1] = a[i];
				a[i] = tmp;
				return true;
			}
		}
	}

	int inv(int x) {
		return x == 1 ? 1 : (P - (int) ((long) (P / x) * inv(P % x) % P));
	}

	void preCalc() {
		fact = new int[N];
		invFact = new int[N];
		fact[0] = invFact[0] = 1;
		for (int i = 1; i < N; i++) {
			fact[i] = (int) ((long) fact[i - 1] * i % P);
			invFact[i] = (int) ((long) invFact[i - 1] * inv(i) % P);
		}
	}

	void stress() {
		int n = 6;
		for (int tst = 0;; tst++) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = rand(1, 100);
			}
			if (solve(a) != slow(a)) {
				System.err.println(Arrays.toString(a));
				System.err.println(solve(a));
				System.err.println(slow(a));
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	void test() {
		System.err.println(solve(new int[] { 10, 10, 9 }));
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		 submit();
//		 stress();
//		test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new C();
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