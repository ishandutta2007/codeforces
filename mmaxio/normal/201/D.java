import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int n, S;
	HashMap<String, Integer> dict;

	boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	int countSim() throws IOException {
		int m = nextInt();
		int[] s = new int[m];
		for (int i = 0; i < m; i++) {
			String tmp = nextToken();
			Integer cur = dict.get(tmp);
			if (cur == null)
				cur = -1;
			s[i] = cur;
		}
		int[][] next = new int[n][m + 1];
		for (int i = 0; i < n; i++) {
			next[i][m] = m;
			for (int j = m - 1; j >= 0; j--)
				next[i][j] = (s[j] == i ? j : next[i][j + 1]);
		}

		int[][] dp = new int[1 << n][S + 1];
		for (int i = 0; i < 1 << n; i++)
			Arrays.fill(dp[i], m);

		dp[0][0] = -1;
		for (int mask = 0; mask < 1 << n; mask++) {
			for (int prev = 0; prev <= S; prev++)
				if (dp[mask][prev] != m) {
					int cur = dp[mask][prev] + 1;
					for (int i = 0; i < n; i++)
						if (!test(mask, i) && next[i][cur] != m) {
							int newSim = prev;
							for (int k = 0; k < i; k++)
								if (test(mask, k))
									newSim++;
							dp[mask | (1 << i)][newSim] = Math.min(dp[mask
									| (1 << i)][newSim], next[i][cur]);
						}
				}
		}

		for (int i = S; i >= 0; i--)
			if (dp[(1 << n) - 1][i] < m)
				return i + 1;
		return 0;

	}

	void solve() throws IOException {
		n = nextInt();
		S = n * (n - 1) >> 1;
		dict = new HashMap<String, Integer>();
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			dict.put(s, i);
		}

		int maxSim = 0;
		int ansPos = -1;

		int q = nextInt();
		for (int i = 0; i < q; i++) {
			int curSim = countSim();
			if (curSim > maxSim) {
				maxSim = curSim;
				ansPos = i;
			}
		}

		if (ansPos == -1)
			out.println("Brand new problem!");
		else {
			out.println(ansPos + 1);
			out.print("[:");
			for (int i = 0; i < maxSim; i++)
				out.print("|");
			out.println(":]");
		}
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D().inp();
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