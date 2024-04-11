import java.io.*;
import java.util.*;

public class E {

	int[] a;

	static class STMin {

		private int getLog(int len) {
			return len <= 2 ? 0 : 31 - Integer.numberOfLeadingZeros(len - 1);
		}

		private/* 1 */int[][] d;

		public STMin(/* 1 */int[] a) {
			int n = getLog(a.length);
			d = new /* 1 */int[n + 1][];
			d[0] = a.clone();
			for (int i = 1; i <= n; i++) {
				d[i] = new /* 1 */int[a.length - (1 << i) + 1];
				for (int j = 0; j < d[i].length; j++) {
					d[i][j] = /* 2 */Math.min(d[i - 1][j], d[i - 1][j
							+ (1 << (i - 1))]);
				}
			}
		}

		public/* 1 */int get(int l, int r) {
			int i = getLog(r - l);
			return /* 2 */Math.min(d[i][l], d[i][r - (1 << i)]);
		}

	}

	static class STMax {

		private int getLog(int len) {
			return len <= 2 ? 0 : 31 - Integer.numberOfLeadingZeros(len - 1);
		}

		private/* 1 */int[][] d;

		public STMax(/* 1 */int[] a) {
			int n = getLog(a.length);
			d = new /* 1 */int[n + 1][];
			d[0] = a.clone();
			for (int i = 1; i <= n; i++) {
				d[i] = new /* 1 */int[a.length - (1 << i) + 1];
				for (int j = 0; j < d[i].length; j++) {
					d[i][j] = /* 2 */Math.max(d[i - 1][j], d[i - 1][j
							+ (1 << (i - 1))]);
				}
			}
		}

		public/* 1 */int get(int l, int r) {
			int i = getLog(r - l);
			return /* 2 */Math.max(d[i][l], d[i][r - (1 << i)]);
		}

	}

	STMin smin;
	STMax smax;

	boolean can(int mid) {
		int reach = 0;
		for (int i = 0; i < a.length - 1; i++) {
			if (reach < i) {
				return false;
			}
			if (Math.abs(a[i + 1] - a[i]) > mid) {
				continue;
			}
			if (i == a.length - 2) {
				return true;
			}
			int br1 = firstOutOf(a[i] - mid, a[i] + mid, i + 2);
			int br2 = firstOutOf(a[i + 1] - mid, a[i + 1] + mid, i + 2);
			if (br1 == a.length || br2 == a.length) {
				return true;
			}
			reach = Math.max(reach, br1 - 1);
			reach = Math.max(reach, br2 - 1);
		}
		return false;
	}

	int firstOutOf(int low, int high, int from) {
		int l = from - 1; // in
		int r = a.length; // out
		while (r - l > 1) {
			int mid = (l + r) >> 1;
			if (smin.get(from, mid + 1) >= low
					&& smax.get(from, mid + 1) <= high) {
				l = mid;
			} else {
				r = mid;
			}
		}
		return r;
	}

	int fast() {
		int low = Math.abs(a[1] - a[0]) - 1; // can't
		int high = 1_000_000_000;

		smin = new STMin(a);
		smax = new STMax(a);
		
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			if (can(mid)) {
				high = mid;
			} else {
				low = mid;
			}
		}

		return high;
	}

	static final int INF = Integer.MAX_VALUE / 3;

	int slow() {
		int n = a.length;
		int[][] dp = new int[n][n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(dp[i], INF);
		}
		dp[0][1] = Math.abs(a[1] - a[0]);
		for (int j = 1; j < n - 1; j++) {
			for (int i = 0; i < j; i++) {
				dp[i][j + 1] = Math.min(dp[i][j + 1],
						Math.max(dp[i][j], Math.abs(a[j + 1] - a[i])));
				dp[j][j + 1] = Math.min(dp[j][j + 1],
						Math.max(dp[i][j], Math.abs(a[j + 1] - a[j])));
			}
		}
		int ret = INF;
		for (int i = 0; i < n - 1; i++) {
			ret = Math.min(ret, dp[i][n - 1]);
		}
		return ret;
	}

	void submit() {
		int n = nextInt();
		a = new int[n + 2];
		a[0] = nextInt();
		a[1] = nextInt();
		for (int i = 0; i < n; i++) {
			a[i + 2] = nextInt();
		}
		out.println(fast());
//		out.println(slow());
	}

	void preCalc() {

	}

	static final int C = 50;

	void stress() {
		for (int tst = 0;; tst++) {
			int n = rand(3, C);
			a = new int[n];
			for (int i = 0; i < n; i++) {
				outer: while (true) {
					a[i] = rand(-C, C);
					for (int j = 0; j < i; j++) {
						if (a[j] == a[i]) {
							continue outer;
						}
					}
					break;
				}
			}
			int fast = fast();
			int slow = slow();
			if (fast != slow) {
				System.err.println(fast);
				System.err.println(slow);
				System.err.println(Arrays.toString(a));
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	void test() {

	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
//		 stress();
//		 test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new E();
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