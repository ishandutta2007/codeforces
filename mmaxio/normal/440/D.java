import java.io.*;
import java.util.*;

public class D {

	static final int INF = Integer.MAX_VALUE / 3;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Edge>[] g;

	static class Edge {
		int from, to, id;

		public Edge(int from, int to, int id) {
			this.from = from;
			this.to = to;
			this.id = id;
		}
	}

	int n, k;

	int[][] dp;
	int[] par;
	Edge[] parEdge;

	int dfs(int v, int p) {
		par[v] = p;
		int size = 1;
		int[] curDp = dp[v] = new int[k + 1];
		Arrays.fill(curDp, INF);
		curDp[1] = 0;
		for (Edge e : g[v]) {
			if (e.to == p) {
				continue;
			}
			parEdge[e.to] = e;
			int toSize = dfs(e.to, v);
			size += toSize;
			int[] toDp = dp[e.to];
			for (int old = k; old >= 1; old--) {
				for (int pick = 1; old + pick <= k; pick++) {
					curDp[old + pick] = Math.min(curDp[old + pick], curDp[old]
							+ toDp[pick]);
				}
				curDp[old]++; // pick nothing
			}
		}
		return size;
	}

	void restore(int v, int hereK, int p) {
		
		int m = g[v].size();
		if (p != -1) {
			m--;
		}

		int[][] localDp = new int[m + 1][hereK + 1];
		int[][] memoPick = new int[m + 1][hereK + 1];
		Edge[] child = new Edge[m];
		for (int i = 0; i <= m; i++) {
			Arrays.fill(localDp[i], INF);
			Arrays.fill(memoPick[i], -1);
		}

		localDp[0][1] = 0;

		int kk = 0;

		for (Edge e : g[v]) {
			if (e.to == p) {
				continue;
			}
			child[kk] = e;
			int[] toDp = dp[e.to];
			for (int old = hereK; old >= 1; old--) {
				for (int pick = 1; old + pick <= hereK; pick++) {
					if (localDp[kk + 1][old + pick] > localDp[kk][old] + toDp[pick]) {
						localDp[kk + 1][old + pick] = localDp[kk][old] + toDp[pick];
						memoPick[kk + 1][old + pick] = pick;
					}
				}
				if (localDp[kk + 1][old] > localDp[kk][old] + 1) {
					localDp[kk + 1][old] = localDp[kk][old] + 1;
					memoPick[kk + 1][old] = 0;
				}
			}
			kk++;
		}
		
//		System.err.println(localDp[]);

		for (int ii = m, jj = hereK; ii > 0; ii--) {
			int herePick = memoPick[ii][jj];
//			System.err.println(ii + " " + jj + " " + herePick);
			if (herePick == 0) {
				out.print(child[ii - 1].id + " ");
			} else {
				restore(child[ii - 1].to, herePick, v);
				jj -= herePick;
			}
		}

	}

	void solve() throws IOException {
		n = nextInt();
		k = nextInt();

		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		par = new int[n];
		parEdge = new Edge[n];

		for (int i = 0; i < n - 1; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(new Edge(v1, v2, i + 1));
			g[v2].add(new Edge(v2, v1, i + 1));
		}

		dp = new int[n][];
		dfs(0, -1);

		int ans = INF;
		int where = -1;
		for (int i = 0; i < n; i++) {
			int val = dp[i][k];
			if (i != 0)
				val++;
			if (val < ans) {
				ans = val;
				where = i;
			}
		}

		out.println(ans);
		if (where != 0) {
			out.println(parEdge[where].id);
		}
		restore(where, k, par[where]);
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