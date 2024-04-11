import java.io.*;
import java.util.*;

public class C {

	static final int INF = Integer.MAX_VALUE / 3;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int calcDist(char[][] a, char[][] b) {
		int ret = 0;
		for (int i = 0; i < a.length; i++)
			for (int j = 0; j < a[i].length; j++) {
				if (a[i][j] != b[i][j]) {
					ret++;
				}
			}
		return ret;
	}

	int[][] g;
	int[] p;
	boolean[] outp;
	int n, m;

	void solve() throws IOException {
		n = nextInt();
		m = nextInt();
		int k = nextInt();
		int w = nextInt();

		char[][][] f = new char[k][n][];

		for (int i = 0; i < k; i++) {
			for (int j = 0; j < n; j++) {
				f[i][j] = nextToken().toCharArray();
			}
		}

		g = new int[k][k];
		for (int i = 0; i < k; i++)
			for (int j = i + 1; j < k; j++) {
				int tmp = calcDist(f[i], f[j]);
				g[i][j] = g[j][i] = Math.min(tmp * w, n * m);
			}

		int[] d = new int[k];
		boolean[] used = new boolean[k];
		Arrays.fill(d, INF);
		d[0] = 0;

		p = new int[k];
		Arrays.fill(p, -1);

		for (int i = 0; i < k; i++) {
//			System.err.println(i + " " + Arrays.toString(d));
			int best = INF;
			int v = -1;
			for (int j = 0; j < k; j++) {
				if (!used[j] && d[j] < best) {
					best = d[j];
					v = j;
				}
			}
			used[v] = true;
			if (v == -1) {
				throw new AssertionError();
			}
			for (int j = 0; j < k; j++) {
				if (!used[j]) {
					if (d[j] > g[v][j]) {
						d[j] = g[v][j];
						p[j] = v;
					}
				}
			}
		}

		int ans = n * m;
		for (int i = 1; i < k; i++) {
			ans += g[i][p[i]];
		}
		out.println(ans);

		outp = new boolean[k];
		for (int i = 0; i < k; i++) {
			if (!outp[i]) {
				output(i);
			}
		}

	}

	void output(int v) {
		outp[v] = true;
		if (p[v] != -1 && !outp[p[v]]) {
			output(p[v]);
		}
		if (p[v] == -1 || g[v][p[v]] >= n * m) {
			out.println((v + 1) + " " + 0);
		} else {
			out.println((v + 1) + " " + (p[v] + 1));
		}
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