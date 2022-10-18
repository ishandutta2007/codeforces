import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int[] PS = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
			43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

	int l, r, p;
	List<Integer> goodAL = new ArrayList<>();

	static int[] toIntArray(List<Integer> a) {
		int[] ret = new int[a.size()];
		int i = 0;
		for (Integer x : a) {
			ret[i++] = x;
		}
		return ret;
	}

	void dfs(int x, int i) {
		if (i == PS.length) {
			return;
		}
		dfs(x, i + 1);
		if (x <= r / PS[i]) {
			int next = x * PS[i];
			goodAL.add(next);
			dfs(next, i);
		}
	}

	void solve() throws IOException {
		l = nextInt();
		r = nextInt();
		p = nextInt();
		goodAL.add(1);
		dfs(1, 0);
		int[] good = toIntArray(goodAL);
		Arrays.sort(good);

		int n = good.length;

		int[] dp = new int[n];
		int oo = Integer.MAX_VALUE / 3;
		Arrays.fill(dp, oo);
		dp[0] = 0;
		for (int x = 2; x <= p; x++) {
			for (int i = 0, j = 0; i < n; i++) {
				long needL = (long) good[i] * x;
				if (needL > r) {
					break;
				}
				while (j < n && good[j] < needL) {
					j++;
				}
				if (j == n || good[j] != needL) {
					continue;
				}
				if (dp[i] + x < p && dp[j] > dp[i] + 1) {
					dp[j] = dp[i] + 1;
				}
			}
		}

		int ans = 0;

		for (int i = 0; i < n; i++) {
			if (good[i] >= l && dp[i] != oo) {
				ans++;
			}
		}

		out.println(ans);
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