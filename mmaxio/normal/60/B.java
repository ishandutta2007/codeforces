import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int k, n, m;
	char[][][] f;
	boolean[][][] use;

	final int[] dx = { -1, 1, 0, 0, 0, 0 };
	final int[] dy = { 0, 0, -1, 1, 0, 0 };
	final int[] dz = { 0, 0, 0, 0, 1, -1 };

	int vis = 0;

	boolean isValid(int x, int y, int z) {
		return x >= 0 && x < k && y >= 0 && y < n && z >= 0 && z < m
				&& f[x][y][z] == '.';
	}

	void dfs(int x, int y, int z) {
		vis++;
		use[x][y][z] = true;
		for (int i = 0; i < 6; i++) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			int cz = z + dz[i];
			//System.err.println(cx + " " + cy + " " + cz);
			//System.err.println(isValid(cx, cy, cz));
			//System.err.println(use[cx][cy][cz]);
			if (isValid(cx, cy, cz) && !use[cx][cy][cz])
				dfs(cx, cy, cz);
		}
	}

	void solve() throws IOException {
		k = nextInt();
		n = nextInt();
		m = nextInt();

		f = new char[k][n][];
		use = new boolean[k][n][m];

		for (int i = 0; i < k; i++) {
			for (int j = 0; j < n; j++) {
				f[i][j] = nextToken().toCharArray();
				//System.err.println(f[i][j]);
			}
			
		}

		int y0 = nextInt() - 1;
		int z0 = nextInt() - 1;

		dfs(0, y0, z0);

		out.print(vis);

	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B().inp();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	String nextString() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken("\n");
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