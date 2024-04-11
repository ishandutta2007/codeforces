import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();

		char[][][] f = new char[n][m][];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				f[i][j] = nextToken().toCharArray();
			}
		}

		int ret = 0;

		for (int x = 0; x < n; x++)
			for (int y = 0; y < m; y++)
				outer: for (int z = 0; z < k; z++) {

					if (f[x][y][z] == '0') {
						continue outer;
					}

					for (int i = 0; i < 3; i++)
						for (int j = 0; j < 3; j++) {

							int x1 = x - (i == 0 ? 1 : 0);
							int y1 = y - (i == 1 ? 1 : 0);
							int z1 = z - (i == 2 ? 1 : 0);

							int x2 = x + (j == 0 ? 1 : 0);
							int y2 = y + (j == 1 ? 1 : 0);
							int z2 = z + (j == 2 ? 1 : 0);

							if (x1 < 0 || y1 < 0 || z1 < 0 || x2 >= n
									|| y2 >= m || z2 >= k) {
								continue;
							}

							if (f[x1][y1][z1] == '0' || f[x2][y2][z2] == '0') {
								continue;
							}

							if (i != j) {
								int x3 = x ^ x1 ^ x2;
								int y3 = y ^ y1 ^ y2;
								int z3 = z ^ z1 ^ z2;
								if (f[x3][y3][z3] == '1') {
									continue;
								}
							}
							
							ret++;
							continue outer;

						}
				}

		out.println(ret);
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
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