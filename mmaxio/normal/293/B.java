import java.io.*;
import java.util.*;

public class B_mask_fast {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[][] a, init;
	int n, m, k;

	int[] leftOcc;

	static final int MOD = 1_000_000_007;

	int[] map;

	int go(int x, int y, int used) {

		if (x == n) {
			
			Arrays.fill(map, -1);

			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					if (init[i][j] != -1) {
						int real = init[i][j];
						int cur = a[i][j];
						if (map[cur] != -1 && map[cur] != real)
							return 0;
						map[cur] = real;
					}
				}

			int mapped = 0;
			int unmapped = used;
			
			for (int i = 0; i < used; i++)
				if (map[i] != -1) {
					mapped++;
					unmapped--;
					for (int j = i + 1; j < used; j++)
						if (map[j] != -1 && map[j] == map[i]) {
							return 0;
						}
				}
			
			int ret = 1;
			for (int i = 0; i < unmapped; i++)
				ret *= k - mapped - i;
			
			return ret;
			
		}

		int nextX = x;
		int nextY = y + 1;
		if (nextY == m) {
			nextY = 0;
			nextX++;
		}

		int ret = 0;

		for (int put = 0; put <= used && put < k; put++) {
			int prev = leftOcc[put];
			if (prev > y) {
				leftOcc[put] = y;
				a[x][y] = put;
				ret += go(nextX, nextY, used + (put == used ? 1 : 0));
				if (ret >= MOD)
					ret -= MOD;
				leftOcc[put] = prev;
			}
		}
		return ret;
	}

	void solve() throws IOException {
		n = nextInt();
		m = nextInt();
		k = nextInt();

		if (n + m - 1 > k) {
			out.println(0);
			return;
		}

		init = new int[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				init[i][j] = nextInt() - 1;
			}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				for (int i1 = i; i1 < n; i1++)
					for (int j1 = j; j1 < m; j1++) {
						if (i1 != i && j1 != j && init[i][j] != -1
								&& init[i][j] == init[i1][j1]) {
							out.println(0);
							return;
						}
					}

		leftOcc = new int[k];
		Arrays.fill(leftOcc, m);
		a = new int[n][m];
		map = new int[k];
		out.println(go(0, 0, 0));

	}

	B_mask_fast() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B_mask_fast();
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