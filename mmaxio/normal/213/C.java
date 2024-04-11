import java.io.*;
import java.util.*;

public class C_slow {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[][] row = new int[2 * n - 1][];
		int[] ptr = new int[2 * n - 1];
		for (int i = 0; i < 2 * n - 1; i++) {
			int sz = (i < n - 1 ? i + 1 : 2 * n - 1 - i);
			row[i] = new int[sz];
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				int x = nextInt();
				int curRow = i + j;
				row[curRow][ptr[curRow]++] = x;
			}
		

		int[][] dp = new int[1][1];
		dp[0][0] = row[0][0];

		for (int i = 1; i < row.length; i++) {
			
			
			int fromD = (i <= n - 1 ? 0 : -1);
			int toD = (i <= n - 1 ? 1 : 0);

			int prevSz = row[i - 1].length;
			int nextSz = row[i].length;
			int[][] next = new int[nextSz][];
			for (int j = 0; j < nextSz; j++) {
				next[j] = new int[j + 1];
				Arrays.fill(next[j], Integer.MIN_VALUE);
			}

			for (int prev2 = 0; prev2 < prevSz; prev2++)
				for (int prev1 = 0; prev1 <= prev2; prev1++) {

					for (int d1 = fromD; d1 <= toD; d1++)
						for (int d2 = fromD; d2 <= toD; d2++) {
							int next1 = prev1 + d1;
							int next2 = prev2 + d2;
							if (next1 > next2) {
								int tmp = next1;
								next1 = next2;
								next2 = tmp;
							}
							if (next1 < 0 || next1 >= nextSz || next2 < 0
									|| next2 >= nextSz)
								continue;
							int add = next1 == next2 ? row[i][next1]
									: (row[i][next1] + row[i][next2]);
							next[next2][next1] = Math.max(next[next2][next1],
									dp[prev2][prev1] + add);
						}

				}
			dp = next;
		}

		out.println(dp[0][0]);

	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C_slow().inp();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	String nextString() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken("\n");
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