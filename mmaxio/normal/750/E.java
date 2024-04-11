import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int INF = 1_00_000_000;
	
	static int[][][] cache = new int[10][6][6];
	{
		for (char c = '0'; c <= '9'; c++) {
			int[][] dp = cache[c - '0'];
			for (int i = 0; i < 6; i++)
				for (int j = i; j < 6; j++) {
					dp[i][j] = i == j ? 0 : -INF;
				}
			
			if (c == '2') {
				dp[0][1] = 1;
			} else {
				dp[0][0] = 1;
			}
			
			if (c == '0') {
				dp[1][2] = 1;
			} else {
				dp[1][1] = 1;
			}
			
			if (c == '1') {
				dp[2][3] = 1;
			} else {
				dp[2][2] = 1;
			}
			
			if (c == '6') {
				dp[3][5] = 1;
			} else if (c == '7') {
				dp[3][4] = 1;
			} else {
				dp[3][3] = 1;
			}
			
			if (c == '6') {
				dp[4][5] = 1; 
			} else {
				dp[4][4] = 1;
			}
		}
	}
	
	
	static class Node {
		int l, r;
		Node left, right;
		
		int[][] dp;

		public Node(int l, int r, String s) {
			this.l = l;
			this.r = r;
			if (r - l > 1) {
				int mid = (l + r) >> 1;
				left = new Node(l, mid, s);
				right = new Node(mid, r, s);
				
				dp = combine(left.dp, right.dp);
			} else {
				dp = cache[s.charAt(l) - '0'];
			}
		}
		
		static int[][] combine(int[][] a, int[][] b) {
			if (a == null) {
				return b;
			}
			if (b == null) {
				return a;
			}
			int[][] c = new int[6][6];
			for (int i = 0; i < 6; i++) {
				for (int j = i; j < 6; j++) {
					c[i][j] = -INF;
					for (int k = i; k <= j; k++) {
						c[i][j] = Math.max(c[i][j], a[i][k] + b[k][j]);
					}
				}
			}
			
			return c;
		}
		
		int[][] go(int ql, int qr) {
			if (l >= qr || ql >= r) {
				return null;
			}
			if (ql <= l && r <= qr) {
				return dp;
			}
			return combine(left.go(ql, qr), right.go(ql, qr));	
		}
		
	}

	void solve() throws IOException {
		int n = nextInt();
		int q = nextInt();
		
		String s = nextToken();
		
		Node root = new Node(0, n, s);
		
		while (q-- > 0) {
			int l = nextInt() - 1;
			int r = nextInt();
			
			int[][] dp = root.go(l, r);
			
//			System.err.println(Arrays.deepToString(dp));
			
			if (dp[0][4] < 0) {
				out.println(-1);
			} else {
				out.println(r - l - dp[0][4]);
			}
		}
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