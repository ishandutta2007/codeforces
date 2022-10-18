import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int n;
	int[][] d;

	List<Edge>[] g;

	static class Edge {
		int to, len;

		public Edge(int to, int len) {
			this.to = to;
			this.len = len;
		}
	}

	boolean go(List<Integer> vs) {
		if (vs.size() < 2) {
			return true;
		}
		int close = -1;
		int diff = Integer.MAX_VALUE;
		int root = vs.get(0);
		for (int i = 1; i < vs.size(); i++) {
			if (d[root][vs.get(i)] < diff) {
				diff = d[root][vs.get(i)];
				close = vs.get(i);
			}
		}
		List<Integer> vs1 = new ArrayList<>();
		List<Integer> vs2 = new ArrayList<>();
		vs1.add(root);
		vs2.add(close);
		for (int i = 1; i < vs.size(); i++) {
			int v = vs.get(i);
			if (v == root || v == close) {
				continue;
			}
			if (d[close][v] + diff == d[root][v]) {
				vs2.add(v);
			} else if (d[root][v] + diff == d[close][v]) {
				vs1.add(v);
			} else {
				return false;
			}
		}
		g[root].add(new Edge(close, diff));
		g[close].add(new Edge(root, diff));
//		System.err.println(root + " " + close + " " + diff);
		return go(vs1) && go(vs2);
	}

	void solve() throws IOException {
		n = nextInt();
		d = new int[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				d[i][j] = nextInt();
			}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (i == j) {
					if (d[i][j] != 0) {
						out.println("NO");
						return;
					}
				} else {
					if (d[i][j] == 0 || d[i][j] != d[j][i]) {
						out.println("NO");
						return;
					}
				}
			}

		List<Integer> a = new ArrayList<>(n);
		for (int i = 0; i < n; i++) {
			a.add(i);
		}
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>(0);
		}

		if (!go(a)) {
			out.println("NO");
			return;
		}
		
		for (int i = 0; i < n; i++) {
			if (!dfs(i, -1, 0, i)) {
				out.println("NO");
				return;
			}
		}
		out.println("YES");
	}

	boolean dfs(int v, int p, long curD, int st) {
		if (d[v][st] != curD) {
			return false;
		}
		for (int i = 0; i < g[v].size(); i++) {
			Edge e = g[v].get(i);
			if (e.to == p) {
				continue;
			}
			if (!dfs(e.to, v, curD + e.len, st)) {
				return false;
			}
		}
		return true;
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