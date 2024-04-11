import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] head;
	int[] next;
	int[] to;
	int[] cost;
	
	void add(int v, int u, int c, int idx) {
		to[idx] = u;
		cost[idx] = c;
		next[idx] = head[v];
		head[v] = idx;
	}
	
	int[][][][] dp;
	
	static final int INF = Integer.MAX_VALUE / 3;
	
	int go(int side, int l, int r, int left) {
		if (dp[side][l][r][left] != -1) {
			return dp[side][l][r][left];
		}
		
		if (left == 0) {
			return dp[side][l][r][left] = 0;
		}
		
		int nowAt = side == 0 ? l : r;
		
		int ret = INF;
		
		for (int e = head[nowAt]; e >= 0; e = next[e]) {
			int toAt = to[e];
			int c = cost[e];
			
			if (toAt < l) {
				ret = Math.min(ret, go(0, toAt, r, left - 1) + c);
			} else if (toAt > r) {
				ret = Math.min(ret, go(1, l, toAt, left - 1) + c);
			}
		}
		
		return dp[side][l][r][left] = ret;
	}
	
	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		int m = nextInt();
		
		head = new int[n];
		Arrays.fill(head, -1);
		next = new int[m];
		to = new int[m];
		cost = new int[m];
		
		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			int c = nextInt();
//			add(v, u, c, i);
			add(u, v, c, i);
		}
		
		dp = new int[2][n][n][k + 1];
		for (int i1 = 0; i1 < 2; i1++) {
			for (int i2 = 0; i2 < n; i2++) {
				for (int i3 = 0; i3 < n; i3++) {
					Arrays.fill(dp[i1][i2][i3], -1);
				}
			}
		}
		
		int ret = INF;
		for (int i = 0; i < n; i++) {
			ret = Math.min(ret, go(0, i, i, k - 1));
		}
		
		if (ret == INF) {
			out.println(-1);
		} else {
			out.println(ret);
		}
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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