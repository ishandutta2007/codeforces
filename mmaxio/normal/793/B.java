import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int[] DX = { -1, 0, 1, 0 };
	static final int[] DY = { 0, -1, 0, 1 };

	boolean[][][][] was;
	
	int n, m;
	char[][] f;
	
	int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
	
	void solve() throws IOException {
		n = nextInt();
		m = nextInt();
		f = new char[n][];
		for (int i = 0; i < n; i++) {
			f[i] = nextToken().toCharArray();
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (f[i][j] == 'S') {
					x1 = i;
					y1 = j;
					f[i][j] = '.';
				}
				if (f[i][j] == 'T') {
					x2 = i;
					y2 = j;
					f[i][j] = '.';
				}
			}
		}
		
		was = new boolean[4][3][n][m];

		for (int i = 0; i < 4; i++) {
			if (dfs(x1, y1, 0, i)) {
				out.println("YES");
				return;
			}
		}
		
		out.println("NO");
	}
	
	boolean dfs(int x, int y, int turns, int dir) {
		if (x < 0 || x >= n || y < 0 || y >= m || f[x][y] == '*' || turns > 2) {
			return false;
		}
		if (x == x2 && y == y2) {
			return true;
		}
		if (was[dir][turns][x][y]) {
			return false;
		}
		
		for (int d = 0; d < 4; d++) {
			if (dfs(x + DX[d], y + DY[d], turns + (dir == d ? 0 : 1), d))  {
				return true;
			}
		}
		
		was[dir][turns][x][y] = true;
		return false;
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