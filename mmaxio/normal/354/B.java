import java.io.*;
import java.util.*;

public class B {

	static final int UNDEF = Integer.MAX_VALUE / 3;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static int decode(char c) {
		if (c == 'a')
			return 1;
		if (c == 'b')
			return -1;
		return 0;
	}

	int[][] dp;

	int n;
	char[][] f;
	int[][] a;

	void solve() throws IOException {
		n = nextInt();
		f = new char[n][];
		for (int i = 0; i < n; i++) {
			f[i] = nextToken().toCharArray();
		}

		a = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = decode(f[i][j]);
			}
		}

		dp = new int[2 * n - 1][];
		for (int i = 0; i < 2 * n - 1; i++) {
			dp[i] = new int[1 << n];
			Arrays.fill(dp[i], UNDEF);
		}

		int res = a[0][0] + go(0, 1);
		String outp = null;
		if (res > 0) {
			outp = "FIRST";
		}
		if (res < 0) {
			outp = "SECOND";
		}
		if (res == 0) {
			outp = "DRAW";
		}

		out.println(outp);
	}

	int go(int sum, int mask) {
		if (dp[sum][mask] != UNDEF)
			return dp[sum][mask];
		if (sum == 2 * n - 2)
			return 0;
		int move = (sum & 1) ^ 1;

		int[] nextMask = new int[26];

		for (int nextRow = 0; nextRow < n; nextRow++) {
			if ((nextRow != 0 && test(mask, nextRow - 1))
					|| test(mask, nextRow)) {
				int nextCol = (sum + 1) - nextRow;
				if (nextCol >= 0 && nextCol < n) {
					char nextChar = f[nextRow][nextCol];
					nextMask[nextChar - 'a'] |= 1 << nextRow;
				}
			}
		}

		int ret = (move == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE);

		for (int i = 0; i < 26; i++) {
			if (nextMask[i] != 0) {
				int nextVal = go(sum + 1, nextMask[i]);
				if (i == 0)
					nextVal++;
				if (i == 1)
					nextVal--;
				if (move == 1) {
					ret = Math.min(ret, nextVal);
				} else {
					ret = Math.max(ret, nextVal);
				}
			}
		}

		return dp[sum][mask] = ret;
	}

	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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