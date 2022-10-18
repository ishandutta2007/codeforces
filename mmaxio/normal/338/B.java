import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;

	int[] max1, to1;
	int[] max2, to2;

	boolean[] seen;
	int d;

	int ans = 0;

	void dfs1(int v, int p) {
		max1[v] = max2[v] = to1[v] = to2[v] = -1;
		if (seen[v]) {
			max1[v] = 0;
		}

		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to == p)
				continue;
			dfs1(to, v);
			if (max1[to] != -1) {
				if (max1[to] + 1 > max1[v]) {
					max2[v] = max1[v];
					to2[v] = to1[v];
					max1[v] = max1[to] + 1;
					to1[v] = to;
				} else if (max1[to] + 1 > max2[v]) {
					max2[v] = max1[to] + 1;
					to2[v] = to;
				}
			}
		}
	}

	void dfs2(int v, int p, int maxUp) {
		//System.err.println(v + " " + maxUp + " " + max1[v]);
		if (maxUp > d)
			return;
		if (max1[v] <= d) {
			ans++;
		}

		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to == p)
				continue;
			int newMaxUp;
			if (to == to1[v]) {
				newMaxUp = Math.max(maxUp, max2[v]);
			} else {
				newMaxUp = Math.max(maxUp, max1[v]);
			}
			if (newMaxUp != -1)
				newMaxUp++;
			dfs2(to, v, newMaxUp);
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		d = nextInt();

		seen = new boolean[n];
		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			seen[v] = true;
		}

		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>(2);
		}

		for (int i = 0; i < n - 1; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}

		max1 = new int[n];
		to1 = new int[n];
		max2 = new int[n];
		to2 = new int[n];

		dfs1(0, -1);

		dfs2(0, -1, -1);
		out.println(ans);
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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