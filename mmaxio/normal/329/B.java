import java.io.*;
import java.util.*;

public class B {

	static final int INF = Integer.MAX_VALUE / 3;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int[] DX = {-1, 0, 1, 0};
	static final int[] DY = {0, -1, 0, 1};
	
	static boolean valid(int x, int y, int n, int m) {
		return x >= 0 && x < n && y >= 0 && y < m;
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		char[][] f = new char[n][];
		
		int sx = -1;
		int sy = -1;
		int ex = -1;
		int ey = -1;
		
		for (int i = 0; i < n; i++) {
			f[i] = nextToken().toCharArray();
			for (int j = 0; j < m; j++) {
				if (f[i][j] == 'S') {
					sx = i;
					sy = j;
					f[i][j] = '0';
				}
				if (f[i][j] == 'E') {
					ex = i;
					ey = j;
					f[i][j] = '0';
				}
			}
		}
		
		Deque<Integer> q = new ArrayDeque<>();
		int[][] dEn = new int[n][m];
		for (int i = 0; i < n; i++) {
			Arrays.fill(dEn[i], INF);
		}
		
		q.add(ex);
		q.add(ey);
		dEn[ex][ey] = 0;
		
		while (!q.isEmpty()) {
			int cx = q.poll();
			int cy = q.poll();
			
			//System.err.println(cx + " " + cy + " " +dEn[cx][cy]);
			
			for (int dir = 0; dir < 4; dir++) {
				int nx = cx + DX[dir];
				int ny = cy + DY[dir];
				if (!valid(nx, ny, n, m))
					continue;
				if (f[nx][ny] == 'T')
					continue;
				if (dEn[nx][ny] > dEn[cx][cy] + 1) {
					dEn[nx][ny] = dEn[cx][cy] + 1;
					q.add(nx);
					q.add(ny);
				}
			}
		}
		
		int ans = 0;
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (f[i][j] != 'T' && f[i][j] != '0' && dEn[i][j] <= dEn[sx][sy]) {
					ans += f[i][j] - '0';
				}
			}
		
		out.println(ans);
		
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