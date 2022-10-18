import java.io.*;
import java.util.*;

public class C_FUCK {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void gen(int cur, int a, int b, List<Integer> good, int maxSum) {
		if (cur > maxSum)
			return;
		if (cur != 0)
			good.add(cur);
		gen(cur * 10 + a, a, b, good, maxSum);
		gen(cur * 10 + b, a, b, good, maxSum);
	}

	static final int MOD = 1000000007;

	int solve(int len, int sum, int a, int b) {
		int cntA = b * len - sum;
		int denom = b - a;
		if (cntA % denom != 0)
			return 0;
		cntA /= denom;
//		System.err.println(len + " " + cntA);
		return c(len, cntA);
	}

	int[] fact;
	int[] invFact;

	static int pow(int a, int b) {
		int res = 1;
		while (b != 0) {
			if ((b & 1) == 1)
				res = (int) ((long) res * a % MOD);
			a = (int) ((long) a * a % MOD);
			b >>= 1;
		}
		return res;
	}

	int c(int n, int k) {
		if (n < 0 || k < 0 || k > n)
			return 0;
		return (int) ((long) fact[n] * invFact[k] % MOD * invFact[n - k] % MOD);
	}

	void solve() throws IOException {
		int a = nextInt();
		int b = nextInt();
		int len = nextInt();

		fact = new int[len + 1];
		invFact = new int[len + 1];

		fact[0] = invFact[0] = 1;
		for (int i = 1; i < fact.length; i++) {
			fact[i] = (int) ((long) fact[i - 1] * i % MOD);
			invFact[i] = pow(fact[i], MOD - 2);
		}

		int maxSum = b * len;
		List<Integer> good = new ArrayList<>();
		gen(0, a, b, good, maxSum);

		int ans = 0;
		for (int sum : good) {
			ans += solve(len, sum, a, b);
			if (ans >= MOD)
				ans -= MOD;
		}

		out.println(ans);
	}

	C_FUCK() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C_FUCK();
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