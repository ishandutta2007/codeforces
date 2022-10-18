import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	boolean[][] g;
	int n;

	void dfs(int v, boolean[] vis) {
		vis[v] = true;
		for (int to = 0; to < n; to++) {
			if (g[v][to] && !vis[to]) {
				dfs(to, vis);
			}
		}
	}

	void dfsR(int v, boolean[] visR) {
		visR[v] = true;
		for (int to = 0; to < n; to++) {
			if (g[to][v] && !visR[to]) {
				dfsR(to, visR);
			}
		}
	}

	void solve() throws IOException {
		n = nextInt();
		g = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x = nextInt();
				g[i][j] = x > 0;
			}
		}

		boolean[] vis = new boolean[n];
		dfs(0, vis);

		boolean[] visR = new boolean[n];
		dfsR(0, visR);
		boolean yes = true;
		for (int i = 0; i < n; i++) {
			yes &= vis[i] & visR[i];
		}

		out.println(yes ? "YES" : "NO");
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