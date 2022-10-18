import java.io.*;
import java.util.*;

public class cf156E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int MOD = 777777777;

	int[][][] dp;

	int[][] can = new int[3][3];

	int firstBad;

	int[][] aux = new int[3][3];

	void update(int i) {

		if (dp[2 * i + 2] == null) {
			dp[i] = dp[2 * i + 1];
			return;
		}

		int[][] tmp = dp[i];

		for (int s1 = 0; s1 < 3; s1++)
			for (int s2 = 0; s2 < 3; s2++) {
				aux[s1][s2] = 0;
				for (int t1 = 0; t1 < 3; t1++) {
					aux[s1][s2] += dp[2 * i + 1][s1][t1] * can[t1][s2];
					if (aux[s1][s2] >= MOD)
						aux[s1][s2] -= MOD;
				}
			}

		for (int t1 = 0; t1 < 3; t1++)
			for (int t2 = 0; t2 < 3; t2++) {
				tmp[t1][t2] = 0;
				for (int s2 = 0; s2 < 3; s2++) {
					tmp[t1][t2] += (int) ((long) aux[t1][s2]
							* dp[2 * i + 2][s2][t2] % MOD);
					if (tmp[t1][t2] >= MOD)
						tmp[t1][t2] -= MOD;
				}
			}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				can[i][j] = nextInt();
		int down = 1;
		while (down < n)
			down <<= 1;
		dp = new int[(down << 1) - 1][][];
		for (int i = down - 1; i < down - 1 + n; i++)
			dp[i] = new int[][] { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };
		for (int i = down - 2; i >= 0; i--) {
			dp[i] = new int[3][3];
			update(i);
		}

		while (m-- > 0) {
			int pos = nextInt() - 1;
			int newVal = nextInt() - 1;
			int[][] p = dp[down - 1 + pos];
			for (int i = 0; i < 3; i++)
				Arrays.fill(p[i], 0);
			if (newVal >= 0)
				p[newVal][newVal] = 1;
			else
				p[0][0] = p[1][1] = p[2][2] = 1;
			for (int i = down - 1 + pos;;) {
				if (i == 0)
					break;
				i = (i - 1) >> 1;
				update(i);
			}
			int ans = 0;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++) {
					ans += dp[0][i][j];
					if (ans >= MOD)
						ans -= MOD;
				}
			out.println(ans);
		}
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new cf156E().inp();
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