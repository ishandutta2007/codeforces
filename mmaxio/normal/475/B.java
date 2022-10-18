import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	boolean[][] vis;
	int cnt;
	String row;
	String col;
	private int n;
	private int m;

	void solve() throws IOException {
		n = nextInt();
		m = nextInt();
		row = nextToken();
		col = nextToken();

		vis = new boolean[n][m];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cnt = 0;
				for (int i1 = 0; i1 < n; i1++) {
					Arrays.fill(vis[i1], false);
				}
				dfs(i, j);
				if (cnt != n * m) {
					out.println("NO");
					return;
				}
			}
		out.println("YES");
	}

	void dfs(int i, int j) {
		vis[i][j] = true;
		cnt++;
		if (row.charAt(i) == '<') {
			if (j > 0 && !vis[i][j - 1]) {
				dfs(i, j - 1);
			}
		} else {
			if (j < m - 1 && !vis[i][j + 1]) {
				dfs(i, j + 1);
			}
		}

		if (col.charAt(j) == '^') {
			if (i > 0 && !vis[i - 1][j]) {
				dfs(i - 1, j);
			}
		} else {
			if (i < n - 1 && !vis[i + 1][j]) {
				dfs(i + 1, j);
			}
		}
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