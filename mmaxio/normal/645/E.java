import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int P = 1_000_000_007;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		char[] s = nextToken().toCharArray();

		int[] dp = new int[n + s.length + 1];

		final int[] prev = new int[k];
		Arrays.fill(prev, -1);

		dp[0] = 1;
		for (int i = 0; i < s.length; i++) {
			int c = s[i] - 'a';
			dp[i + 1] = 2 * dp[i] % P;
			if (prev[c] != -1) {
				dp[i + 1] -= dp[prev[c]];
				if (dp[i + 1] < 0) {
					dp[i + 1] += P;
				}
			}
			prev[c] = i;
		}

		Integer[] order = new Integer[k];
		for (int i = 0; i < k; i++) {
			order[i] = i;
		}
		Arrays.sort(order,
				(Integer a, Integer b) -> Integer.compare(prev[a], prev[b]));

		for (int i = 0; i < n; i++) {
			int c = order[i % k];
			dp[i + s.length + 1] = 2 * dp[i + s.length] % P;
			if (prev[c] != -1) {
				dp[i + s.length + 1] -= dp[prev[c]];
				if (dp[i + s.length + 1] < 0) {
					dp[i + s.length + 1] += P;
				}
			}
			prev[c] = i + s.length;
		}

		out.println(dp[s.length + n]);
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