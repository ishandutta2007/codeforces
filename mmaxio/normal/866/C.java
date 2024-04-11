import java.io.*;
import java.util.*;

public class C {

	static final int ITERS = 80;

	double[][] dp;

	int[] low, high;
	double[] pLow;
	int n, r;

	double calc(int idx, int time, double x) {
		if (time > r) {
			return x;
		}
		if (idx == n) {
			return 0;
		}

		if (dp[idx][time] > -.5) {
			return dp[idx][time];
		}

		dp[idx][time] = Math.min(
				x,
				pLow[idx] * (low[idx] + calc(idx + 1, time + low[idx], x))
						+ (1 - pLow[idx])
						* (high[idx] + calc(idx + 1, time + high[idx], x)));

		return dp[idx][time];
	}

	void submit() {
		n = nextInt();
		r = nextInt();
		low = new int[n];
		high = new int[n];
		pLow = new double[n];
		for (int i = 0; i < n; i++) {
			low[i] = nextInt();
			high[i] = nextInt();
			pLow[i] = nextInt() * 0.01;
		}

		double lowAns = 0;
		double highAns = 1e9;

		dp = new double[n + 1][r + 1];

		for (int it = 0; it < ITERS; it++) {
			double mid = (lowAns + highAns) * .5;
			for (int i = 0; i <= n; i++) {
				Arrays.fill(dp[i], -1);
			}

			double get = calc(0, 0, mid);

//			System.err.println(mid + " " + get);
			if (get >= mid) {
				lowAns = mid;
			} else {
				highAns = mid;
			}
		}

		out.println((lowAns + highAns) * 0.5);
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
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