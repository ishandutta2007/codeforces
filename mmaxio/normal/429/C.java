import java.io.*;
import java.util.*;

public class GuessTheTree {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	boolean solve() throws IOException {
		int n = nextInt();
		int initN = n;
		List<Integer> szList = new ArrayList<>();
		int leaves = 0;

		for (int i = 0; i < n; i++) {
			int x = nextInt();
			if (x == 1) {
				leaves++;
			} else {
				szList.add(x);
			}
		}

		n = szList.size();

		if (leaves <= n) {
			return false;
		}
		
		if (n == 0) {
			return true;
		}

		Collections.sort(szList);
		Collections.reverse(szList);

		int[] sz = new int[n];
		for (int i = 0; i < sz.length; i++) {
			sz[i] = szList.get(i);
		}

		if (sz[0] != initN) {
			return false;
		}

		int[] maskCnt = new int[1 << n];
		int[] maskSum = new int[1 << n];
		for (int i = 0; i < n; i++) {
			maskCnt[1 << i] = 1;
			maskSum[1 << i] = sz[i];
		}

		for (int mask = 1; mask < (1 << n); mask++) {
			int low = Integer.lowestOneBit(mask);
			maskCnt[mask] = maskCnt[low] + maskCnt[mask ^ low];
			maskSum[mask] = maskSum[low] + maskSum[mask ^ low];
		}

		boolean[][][] dp = new boolean[n + 1][leaves + 1][1 << n];
		// current node, unassigned leaves, unassigned nodes

		final int ALL = (1 << n) - 1;

		dp[0][leaves][ALL ^ 1] = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= leaves; j++) {
				for (int mask = 0; mask < (1 << n); mask++) {
					if (!dp[i][j][mask] || test(mask, i)) {
						continue;
					}
					for (int sub = mask; ; sub = (sub - 1) & mask) {
						int leavesHere = sz[i] - 1 - maskSum[sub];
						if (leavesHere >= 0 && leavesHere <= j
								&& leavesHere + maskCnt[sub] >= 2) {
							dp[i + 1][j - leavesHere][mask ^ sub] = true;
						}
						if (sub == 0) {
							break;
						}
					}
				}
			}
		}

		return dp[n][0][0];

	}

	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		out.println(solve() ? "YES" : "NO");
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new GuessTheTree().inp();
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