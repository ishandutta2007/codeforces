import java.io.*;
import java.util.*;

public class F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int pow(int a, int b) {
		int ret = 1;
		for (; b > 0; b >>= 1) {
			if ((b & 1) == 1) {
				ret = (int) ((long) ret * a % p);
			}
			a = (int) ((long) a * a % p);
		}
		return ret;
	}

	int inv(int x) {
		return pow(x, p - 2);
	}

	int det(int[][] a) {
		int n = a.length;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = Math.floorMod(a[i][j], p);
			}
		}

//		System.err.println(Arrays.deepToString(a));

		int ret = 1;

		for (int i = 0; i < n; i++) {
			int row = -1;
			for (int j = i; j < n; j++) {
				if (a[j][i] != 0) {
					row = j;
					break;
				}
			}
			if (row == -1) {
				return 0;
			}

			int[] tmp = a[i];
			a[i] = a[row];
			a[row] = tmp;

			if (i != row) {
				ret = p - ret;
			}

			for (int j = i + 1; j < n; j++) {
				int coef = (int) ((long) a[j][i] * inv(a[i][i]) % p);
				for (int k = i + 1; k < n; k++) {
					a[j][k] -= (int) ((long) a[i][k] * coef % p);
					if (a[j][k] < 0) {
						a[j][k] += p;
					}
				}
			}

//			System.err
//					.println("after row " + i + ": " + Arrays.deepToString(a));

			ret = (int) ((long) ret * a[i][i] % p);
		}

//		System.err.println(ret);

		return ret;
	}

	int n, m, p;
	char[][] f;

	static class DSU {

		private int[] p;

		public DSU(int n) {
			p = new int[n];
			Arrays.fill(p, -1);
		}

		int get(int v) {
			return p[v] < 0 ? v : (p[v] = get(p[v]));
		}

		boolean unite(int v, int u) {
			v = get(v);
			u = get(u);
			if (v == u) {
				return false;
			}
			if (p[v] > p[u]) {
				int tmp = v;
				v = u;
				u = tmp;

			}
			p[v] += p[u];
			p[u] = v;
			return true;
		}
	}

	int solve(DSU d, int par) {
		int[] map = new int[(n + 1) * (m + 1)];
		Arrays.fill(map, -1);

		int sz = 0;

		for (int i = 0; i < n + 1; i++)
			for (int j = 0; j < m + 1; j++) {
				if (((i ^ j ^ par) & 1) == 1) {
					continue;
				}

				int v = d.get(i * (m + 1) + j);

				// System.err.println(i + " " + j + " > " + v);

				if (map[v] == -1) {
					map[v] = sz++;
				}

			}

		int[][] km = new int[sz][sz];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (f[i][j] != '*') {
					continue;
				}
				int v1, v2;
				if (((i ^ j ^ par) & 1) == 0) {
					v1 = map[d.get(i * (m + 1) + j)];
					v2 = map[d.get((i + 1) * (m + 1) + (j + 1))];
				} else {
					v1 = map[d.get((i + 1) * (m + 1) + j)];
					v2 = map[d.get(i * (m + 1) + (j + 1))];
				}
				km[v1][v1]++;
				km[v2][v2]++;
				km[v1][v2]--;
				km[v2][v1]--;
			}

		// System.err.println(Arrays.deepToString(km));

		int[][] comp = new int[sz - 1][];
		for (int i = 0; i < sz - 1; i++) {
			comp[i] = Arrays.copyOf(km[i], sz - 1);
		}

		return det(comp);

	}

	void solve() throws IOException {
		n = nextInt();
		m = nextInt();
		p = nextInt();

		f = new char[n][];
		for (int i = 0; i < n; i++) {
			f[i] = nextToken().toCharArray();
		}

		DSU d = new DSU((n + 1) * (m + 1));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (f[i][j] == '\\') {
					if (!d.unite(i * (m + 1) + j, (i + 1) * (m + 1) + (j + 1))) {
						out.println(0);
						return;
					}
				}
				if (f[i][j] == '/') {
					if (!d.unite((i + 1) * (m + 1) + j, i * (m + 1) + (j + 1))) {
						out.println(0);
						return;
					}
				}
			}
		}

		int ret = solve(d, 0) + solve(d, 1);
		if (ret >= p) {
			ret -= p;
		}

		out.println(ret);

	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new F().inp();
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