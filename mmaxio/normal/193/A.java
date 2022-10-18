import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	char[][] f;
	int n, m;

	int cnt;

	static final int[] dx = { 1, 0, -1, 0 };
	static final int[] dy = { 0, 1, 0, -1 };

	boolean isConnected() {
		int x = -1, y = -1;
		outer: for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (f[i][j] == '#') {
					x = i;
					y = j;
					break outer;
				}
		boolean[][] vis = new boolean[n][m];
		int cur = 1;
		ArrayDeque<Integer> q = new ArrayDeque<Integer>();
		q.add(x);
		q.add(y);
		vis[x][y] = true;
		while (!q.isEmpty()) {
			x = q.poll();
			y = q.poll();
			for (int i = 0; i < 4; i++) {
				int cx = x + dx[i];
				int cy = y + dy[i];
				if (cx < 0 || cx >= n || cy < 0 || cy >= m || f[cx][cy] == '.')
					continue;
				if (!vis[cx][cy]) {
					vis[cx][cy] = true;
					q.add(cx);
					q.add(cy);
					cur++;
				}
			}
		}

		return cur == cnt - 1;

	}

	void solve() throws IOException {
		n = nextInt();
		m = nextInt();
		f = new char[n][];
		for (int i = 0; i < n; i++)
			f[i] = nextToken().toCharArray();

		cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (f[i][j] == '#')
					cnt++;

		if (cnt <= 2) {
			out.println(-1);
			return;
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (f[i][j] == '#') {
					f[i][j] = '.';
					if (!isConnected()) {
						out.println(1);
						return;
					}
					f[i][j] = '#';
				}

		out.println(2);
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A().inp();
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