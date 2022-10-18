import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	class Edge {
		int to;
		boolean rev;
		
		public Edge(int to, boolean rev) {
			this.to = to;
			this.rev = rev;
		}
		
	}
	
	ArrayList<Edge>[] g;
	
	int ans;
	int[] dp;
	int[] depth;
	
	void dfs1(int v, int curD, int p) {
		depth[v] = curD;
		for (int i = 0; i < g[v].size(); i++) {
			Edge e = g[v].get(i);
			if (e.to == p)
				continue;
			dfs1(e.to, curD + 1, v);
			dp[v] += dp[e.to];
			if (e.rev)
				dp[v]++;
		}
	}
	
	void dfs2(int v, int revEdges, int bestForPath, int addDp, int p) {
		ans = Math.min(ans, bestForPath + addDp + dp[v]);
		for (int i = 0; i < g[v].size(); i++) {
			Edge e = g[v].get(i);
			if (e.to == p)
				continue;
			
			int thisBranch = dp[e.to] + (e.rev ? 1 : 0);
			int newAddDp = addDp + dp[v] - thisBranch;
			int newRevEdges = revEdges + (e.rev ? 1 : 0);
			int newBestForPath = Math.min(bestForPath + (e.rev ? 0 : 1), newRevEdges);
			dfs2(e.to, newRevEdges, newBestForPath, newAddDp, v);
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<>();
		for (int i = 0; i < n - 1; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			
			g[v1].add(new Edge(v2, false));
			g[v2].add(new Edge(v1, true));
		}
		
		ans = n;
		dp = new int[n];
		depth = new int[n];
		
		for (int i = 0; i < n; i++) {
			Arrays.fill(dp, 0);
			Arrays.fill(depth, 0);
			dfs1(i, 0, -1);
			dfs2(i, 0, 0, 0, -1);
		}
		
		out.println(ans);
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