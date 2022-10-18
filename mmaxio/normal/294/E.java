import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	class Edge {
		int to, len;

		public Edge(int to, int len) {
			this.to = to;
			this.len = len;
		}

	}

	int[] sz;
	long[] sumDist;
	int[] color;
	Edge[] par;

	Edge[][] g;
	ArrayList<Integer> order = new ArrayList<>();

	int n;

	void dfs(int v, int p, int col) {
		order.add(v);
		color[v] = col;
		sz[v] = 1;
		sumDist[v] = 0;

		for (int i = 0; i < g[v].length; i++) {
			Edge e = g[v][i];
			if (e.to == p) {
				par[v] = e;
				continue;
			}
			dfs(e.to, v, col);
			sz[v] += sz[e.to];
			sumDist[v] += sumDist[e.to] + (long) e.len * sz[e.to];
		}
	}

	long go(int r1, int r2, int len) {
		order.clear();
		dfs(r1, r2, 0);
		dfs(r2, r1, 1);

		// make real sum of distances

		// System.err.println(r1 + " " + r2 + " " + order);

		for (int i = 0; i < n; i++) {
			int v = order.get(i);
			if (v == r1 || v == r2)
				continue;
			Edge edgePar = par[v];

			int thisSz = color[v] == 0 ? sz[r1] : sz[r2];

			sumDist[v] = sumDist[edgePar.to] + (long) edgePar.len
					* (thisSz - 2 * sz[v]);
		}

		long res = 0;
		for (int i = 0; i < n; i++)
			res += sumDist[i];

		res /= 2;

		long bestSum1 = Long.MAX_VALUE;
		long bestSum2 = Long.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			if (color[i] == 0)
				bestSum1 = Math.min(bestSum1, sumDist[i]);
			else
				bestSum2 = Math.min(bestSum2, sumDist[i]);
		}

		res += (long) sz[r1] * sz[r2] * len;

		res += bestSum1 * sz[r2] + bestSum2 * sz[r1];

		return res;
	}

	void solve() throws IOException {
		n = nextInt();
		g = new Edge[n][];

		int[] v1 = new int[n - 1];
		int[] v2 = new int[n - 1];
		int[] cost = new int[n - 1];
		int[] deg = new int[n];

		for (int i = 0; i < n - 1; i++) {
			int vv1 = v1[i] = nextInt() - 1;
			int vv2 = v2[i] = nextInt() - 1;
			deg[vv1]++;
			deg[vv2]++;
			cost[i] = nextInt();
		}

		for (int i = 0; i < n; i++) {
			g[i] = new Edge[deg[i]];
		}

		for (int i = 0; i < n - 1; i++) {
			int vv1 = v1[i];
			int vv2 = v2[i];
			g[vv1][--deg[vv1]] = new Edge(vv2, cost[i]);
			g[vv2][--deg[vv2]] = new Edge(vv1, cost[i]);
		}

		long ans = Long.MAX_VALUE;

		sz = new int[n];
		sumDist = new long[n];
		color = new int[n];
		par = new Edge[n];

		for (int i = 0; i < n - 1; i++) {
			ans = Math.min(ans, go(v1[i], v2[i], cost[i]));
		}

		out.println(ans);
	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E();
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