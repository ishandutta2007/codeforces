import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int LOG = 17;
	static final int P = 1_000_000_007;

	static class Edge {
		int to, cost;

		public Edge(int to, int cost) {
			this.to = to;
			this.cost = cost;
		}

	}

	List<Edge>[] g;

	int n;

	int[][] up;
	int[] tIn, tOut;
	int[] depth;
	int[] sz;
	int time = 0;

	int[] sDown, sAll;
	int[] s2Down, s2All;

	void dfs1(int v, int p) {
		sz[v] = 1;
		tIn[v] = time++;
		up[v][0] = p == -1 ? 0 : p;
		for (Edge e : g[v]) {
			if (e.to == p) {
				continue;
			}
			depth[e.to] = (depth[v] + e.cost) % P;
			dfs1(e.to, v);
			sz[v] += sz[e.to];

			sDown[v] += (int) (((long) e.cost * sz[e.to] + sDown[e.to]) % P);
			sDown[v] %= P;

			s2Down[v] += (int) (((long) e.cost * e.cost % P * sz[e.to] % P + 2L
					* e.cost * sDown[e.to] % P + s2Down[e.to]) % P);
			s2Down[v] %= P;

		}
		tOut[v] = time;
	}

	void dfs2(int v, int p) {
		for (Edge e : g[v]) {
			if (e.to == p) {
				continue;
			}
			int mult = ((n - 2 * sz[e.to]) % P + P) % P;
			sAll[e.to] = (int) (((long) mult * e.cost % P + sAll[v]) % P);

			s2All[e.to] = s2All[v];
			long mult2 = sAll[v] - 2L
					* (sDown[e.to] + (long) sz[e.to] * e.cost % P) % P;
			if (mult2 < 0) {
				mult2 += P;
			}
			s2All[e.to] += (int) (2L * e.cost * mult2 % P);
			s2All[e.to] %= P;

			s2All[e.to] += (int) ((long) n * e.cost % P * e.cost % P);
			s2All[e.to] %= P;
			dfs2(e.to, v);

		}
	}

	boolean isAnc(int v1, int v2) {
		return tIn[v1] <= tIn[v2] && tOut[v2] <= tOut[v1];
	}

	int lca(int v1, int v2) {
		if (isAnc(v1, v2)) {
			return v1;
		}
		if (isAnc(v2, v1)) {
			return v2;
		}
		for (int i = LOG - 1; i >= 0; i--) {
			int to = up[v2][i];
			if (!isAnc(to, v1)) {
				v2 = to;
			}
		}
		return up[v2][0];
	}

	void solve() throws IOException {
		n = nextInt();
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			int len = nextInt();
			g[v1].add(new Edge(v2, len));
			g[v2].add(new Edge(v1, len));
		}

		up = new int[n][LOG];
		tIn = new int[n];
		tOut = new int[n];
		depth = new int[n];

		sDown = new int[n];
		sAll = new int[n];
		s2Down = new int[n];
		s2All = new int[n];
		sz = new int[n];
		dfs1(0, -1);

		sAll[0] = sDown[0];
		s2All[0] = s2Down[0];

		dfs2(0, -1);

		// System.err.println(Arrays.toString(sDown));
		// System.err.println(Arrays.toString(sAll));
		// System.err.println(Arrays.toString(s2Down));
		// System.err.println(Arrays.toString(s2All));

		for (int i = 1; i < LOG; i++)
			for (int j = 0; j < n; j++) {
				up[j][i] = up[up[j][i - 1]][i - 1];
			}

		int q = nextInt();
		while (q-- > 0) {
			int u = nextInt() - 1;
			int v = nextInt() - 1;
			long ret;
			if (isAnc(v, u)) {

				long dvu = depth[u] - depth[v];
				if (dvu < 0) {
					dvu += P;
				}
				ret = dvu * dvu % P * (n - sz[v]) % P;
				int sDv = (sAll[v] - sDown[v]);
				if (sDv < 0) {
					sDv += P;
				}
				ret += 2L * dvu % P * sDv % P;
				ret %= P;

				long s2Dv = s2All[v] - s2Down[v];
				if (s2Dv < 0) {
					s2Dv += P;
				}
				ret += s2Dv;
				ret %= P;
				ret = s2All[u] - 2L * ret % P;
				if (ret < 0) {
					ret += P;
				}

			} else {
				int l = lca(v, u);
				long dvu = (long) depth[v] + depth[u] - 2L * depth[l];
				dvu = (dvu % P + P) % P;

				ret = dvu * dvu % P * sz[v] % P;
				if (ret < 0) {
					ret += P;
				}

				int sDv = sDown[v];
				ret += 2L * dvu % P * sDv % P;
				ret %= P;

				long s2Dv = s2Down[v];
				ret += s2Dv;
				ret %= P;

				// System.err.println(ret);

				ret = 2L * ret % P - s2All[u];

				if (ret < 0) {
					ret += P;
				}
			}
			out.println(ret);
		}
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