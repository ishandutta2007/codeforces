import java.io.*;
import java.util.*;

public class C {

	static final int INF = Integer.MAX_VALUE / 2;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int solve3(char[][] f, int n, int m) {
		int[][] left = new int[n][m];
		for (int i = 0; i < n; i++)
			for (int j = m - 1; j >= 0; j--) {
				if (f[i][j] == 'X') {
					left[i][j] = 1 + (j == m - 1 ? 0 : left[i][j + 1]);
				} else {
					left[i][j] = 0;
				}
			}
		int w = left[0][0];
		int i = 0;
		while (i < n && left[i][0] == w) {
			i++;
		}
		if (i == n) {
			return w == m ? m : INF;
		}
		int j = i;
		while (j < n && f[j][0] == 'X') {
			j++;
		}
		int h = j - i;
		
		if (w == 0 || h == 0) {
			return INF;
		}
		
//		System.err.println(h + " " + w);
		
		int[][] was = new int[n][m];

		for (int x = 0, y = 0;;) {
			System.err.println(x + " " + y);
			if (x + h == n && y + w == m) {
				was[x][y] = 1;
				break;
			}
			if (x + h > n || y + w > m) {
				return INF;
			}
			was[x][y] = 1;
			boolean right = (x + h == n || f[x + h][y] == '.');
			boolean down = (y + w == m || f[x][y + w] == '.');
//			System.err.println(right + " " + down);
			if (right == down) {
				return INF;
			}
			if (right) {
				y++;
			} else {
				x++;
			}
		}

		for (int x = 0; x < n; x++)
			for (int y = 0; y < m; y++) {
				if (x > 0) {
					was[x][y] += was[x - 1][y];
				}
				if (y > 0) {
					was[x][y] += was[x][y - 1];
				}
				if (x > 0 && y > 0) {
					was[x][y] -= was[x - 1][y - 1];
				}
			}

		for (int x = 0; x < n; x++)
			for (int y = 0; y < m; y++) {
				int cnt = was[x][y];
				if (x - h >= 0) {
					cnt -= was[x - h][y];
				}
				if (y - w >= 0) {
					cnt -= was[x][y - w];
				}
				if (x - h >= 0 && y - w >= 0) {
					cnt += was[x - h][y - w];
				}
				if ((cnt != 0) != (f[x][y] == 'X')) {
					return INF;
				}
			}
		
		return w * h;

	}

	int solve2(char[][] f, int n, int m) {
		int val = solve3(f, n, m);
		char[][] g = new char[m][n];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				g[i][j] = f[j][i];
			}
		return Math.min(val, solve3(g, m, n));
	}

	int solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		char[][] f = new char[n][];
		for (int i = 0; i < n; i++) {
			f[i] = nextToken().toCharArray();
		}
		int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
		outer: for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (f[i][j] == 'X') {
					x1 = i;
					y1 = j;
					break outer;
				}
			}

		outer2: for (int i = n - 1; i >= 0; i--)
			for (int j = m - 1; j >= 0; j--) {
				if (f[i][j] == 'X') {
					x2 = i;
					y2 = j;
					break outer2;
				}
			}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (f[i][j] == 'X' && (i < x1 || i > x2 || j < y1 || j > y2)) {
					return INF;
				}
			}

		char[][] g = new char[x2 - x1 + 1][y2 - y1 + 1];
		for (int i = x1; i <= x2; i++)
			for (int j = y1; j <= y2; j++) {
				g[i - x1][j - y1] = f[i][j];
			}
		f = g;
		n = f.length;
		m = f[0].length;
		return solve2(f, n, m);
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		int ret = solve();
		if (ret == INF) {
			ret = -1;
		}
		out.println(ret);
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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