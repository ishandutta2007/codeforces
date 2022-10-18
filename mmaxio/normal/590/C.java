import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int n, m;
	char[][] f;

	static final int INF = Integer.MAX_VALUE / 3;
	static final int[] DX = { -1, 0, 1, 0 };
	static final int[] DY = { 0, -1, 0, 1 };

	int[][] bfs(char c) {
		int[][] d = new int[n][m];
		ArrayDeque<Integer> q = new ArrayDeque<>();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (f[i][j] == c) {
					d[i][j] = 0;
					q.add(i);
					q.add(j);
				} else {
					d[i][j] = INF;
				}
			}
		}
		while (!q.isEmpty()) {
			int x = q.poll();
			int y = q.poll();
			for (int dir = 0; dir < 4; dir++) {
				int cx = x + DX[dir];
				int cy = y + DY[dir];
				if (cx >= 0 && cx < n && cy >= 0 && cy < m && f[cx][cy] != '#') {
					boolean back = f[cx][cy] == '.';
					if (back) {
						if (d[cx][cy] > d[x][y] + 1) {
							d[cx][cy] = d[x][y] + 1;
							q.add(cx);
							q.add(cy);
						}
					} else {
						if (d[cx][cy] > d[x][y]) {
							d[cx][cy] = d[x][y];
							q.addFirst(cy);
							q.addFirst(cx);
						}
					}
				}
			}
		}
		return d;
	}

	void solve() throws IOException {
		n = nextInt();
		m = nextInt();
		f = new char[n][];
		for (int i = 0; i < n; i++) {
			f[i] = nextToken().toCharArray();
		}

		int[][][] d = new int[3][][];
		for (char c = '1'; c <= '3'; c++) {
			d[c - '1'] = bfs(c);
		}

		// System.err.println(Arrays.deepToString(d[0]));

		int d01 = INF;
		int d12 = INF;
		int d20 = INF;

		int minSum = INF;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (f[i][j] == '2') {
					d01 = Math.min(d01, d[0][i][j]);
				}
				if (f[i][j] == '3') {
					d12 = Math.min(d12, d[1][i][j]);
				}
				if (f[i][j] == '1') {
					d20 = Math.min(d20, d[2][i][j]);
				}
				if (d[0][i][j] < INF && d[1][i][j] < INF && d[2][i][j] < INF) {
					int tmp = d[0][i][j] + d[1][i][j] + d[2][i][j];
					if (f[i][j] == '.') {
						tmp -= 2;
					}
					minSum = Math.min(minSum, tmp);
				}
			}

		// System.err.println(Arrays.deepToString(d[1]));

		if (Math.max(d01, Math.max(d12, d20)) == INF) {
			out.println(-1);
			return;
		}

		int ret = Math.min(d01 + d20, Math.min(d01 + d12, d12 + d20));
		ret = Math.min(ret, minSum);

		out.println(ret);

	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
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