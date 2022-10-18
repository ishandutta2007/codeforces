import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int n, m;
	char[][] f;
	boolean[][] vis;

	List<Integer> ans;

	static final int[] DX = { -1, 0, 1, 0 };
	static final int[] DY = { 0, -1, 0, 1 };
	
	int ansLen = 0;

	void dfs(int x, int y) {
		vis[x][y] = true;
		for (int d = 0; d < 4; d++) {
			int cx = x + DX[d];
			int cy = y + DY[d];
			if (cx < 0 || cy < 0 || cx >= n || cy >= m)
				continue;
			if (!vis[cx][cy] && f[cx][cy] == '.') {
				dfs(cx, cy);
				ansLen += 2;
				ans.add(1);
				ans.add(cx);
				ans.add(cy);
			}
		}
	}

	void solve() {

		ans = new ArrayList<>(3 * n * m * 2);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (f[i][j] == '.') {
					ansLen++;
					ans.add(0);
					ans.add(i);
					ans.add(j);
				}
			}

		vis = new boolean[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!vis[i][j] && f[i][j] == '.') {
					dfs(i, j);
					
				}
		
		out.println(ansLen);
		for (int i = 0; i < ans.size(); i += 3) {
			int type = ans.get(i);
			int x = ans.get(i + 1);
			int y = ans.get(i + 2);
			if (type == 0) {
				out.println("B " + (x + 1) + " " + (y + 1));
			} else {
				out.println("D " + (x + 1) + " " + (y + 1));
				out.println("R " + (x + 1) + " " + (y + 1));
			}
		}
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		n = nextInt();
		m = nextInt();
		f = new char[n][];
		 for (int i = 0; i < n; i++)
		 f[i] = nextToken().toCharArray();
//		n = 500;
//		m = 500;
//		f = new char[n][m];
//		for (int i = 0; i < n; i++)
//			Arrays.fill(f[i], '.');
		
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