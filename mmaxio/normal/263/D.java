import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	ArrayList<Integer>[] g;
	ArrayList<Integer> path = new ArrayList<>();
	
	boolean[] vis;
	int[] depth;
	
	int[] dfs(int v, int curD) {
		path.add(v);
		vis[v] = true;
		depth[v] = curD;
		
		int highD = curD;
		
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (!vis[to]) {
				return dfs(to, curD + 1);
			} else if (depth[to] < highD) {
				highD = depth[to];
			}
		}
		
		int[] res = new int[curD - highD + 1];
		for (int i = highD; i <= curD; i++) {
			res[i - highD] = path.get(i);
		}
		return res;
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		
		depth = new int[n];

		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<>();

		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}
		
		vis = new boolean[n];
		
		int[] ans = dfs(0, 0);
		out.println(ans.length);
		for (int i = 0; i < ans.length; i++) {
			out.print((ans[i] + 1) + " ");
		}
		out.println();
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