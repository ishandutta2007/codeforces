import java.io.*;
import java.util.*;

public class D_1d_array {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int N = 320;
	static final int X0 = 160;
	static final int Y0 = 160;

	byte[] dp;

	static final int[] DX = { 1, 1, 0, -1, -1, -1, 0, 1 };
	static final int[] DY = { 0, 1, 1, 1, 0, -1, -1, -1 };

	int total;
	
	byte go(int x, int y, int when, int dir) {
		if (x < 0 || y < 0 || x >= N || y >= N) {
			return -1;
		}
//		if (dp[x][y][when][dir] != 0) {
//			return dp[x][y][when][dir];
//		}
		
		int idx = ((x * N + y) * (total + 1) + when) * 8 + dir;
		
		if (dp[idx] != 0) {
			return dp[idx];
		}

		byte ret;
		if (!change[when]) {
			ret = go(x + DX[dir], y + DY[dir], when - 1, dir);
		} else {
			byte tmp1 = go(x + DX[dir], y + DY[dir], when - 1, (dir - 1) & 7);
			byte tmp2 = go(x + DX[dir], y + DY[dir], when - 1, (dir + 1) & 7);
			ret = (byte) (tmp1 == 1 || tmp2 == 1 ? 1 : -1);
		}

		return dp[idx] = ret;

	}

	boolean[] change;
	int[] parity;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		int sum = 0;

		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			sum += a[i];
		}

		change = new boolean[sum + 1];
		parity = new int[sum + 1];
		total = 0;
		for (int i = 0; i < n; i++) {
			total += a[i];
			if (i != n - 1) {
				change[total + 1] = true;
				parity[total + 1] = 1;
			}
		}
		
		for (int i = 1; i <= total; i++) {
			parity[i] ^= parity[i - 1];
		}

		dp = new byte[N * N * (sum + 1) * 8];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int dir = 0; dir < 8; dir++) {
//					dp[i][j][0][dir] = -1;
					dp[((i * N + j) * (total + 1) + 0) * 8 + dir] = -1;
				}
			}
		}
//		dp[X0][Y0][0][0] = 1;
		dp[((X0 * N + Y0) * (total + 1) + 0) * 8 + 0] = 1;

		int ans = 0;

		for (int i = 0; i < N; i++)
			outer: for (int j = 0; j < N; j++) {
				for (int when = 1; when <= sum; when++) {
					for (int dir = parity[when]; dir < 8; dir += 2) {
						if (go(i, j, when, dir) == 1) {
							ans++;
							continue outer;
						}
					}
				}
			}

		out.println(ans);
	}

	D_1d_array() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D_1d_array();
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