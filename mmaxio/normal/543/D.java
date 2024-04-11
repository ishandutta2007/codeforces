import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int P = 1_000_000_007;

	List<Integer>[] g;
	int[] dpDown;
	int[] par;

	int[] dp;
	int[] aux;

	void dfs(int v) {
		dpDown[v] = 1;
		int[] pref = new int[g[v].size() + 1];
		int[] suff = new int[g[v].size() + 1];
		for (int i = 0; i < g[v].size(); i++) {
			int u = g[v].get(i);
			dfs(u);
			int tmp = 1 + dpDown[u];
			if (tmp == P) {
				tmp = 0;
			}
			suff[i] = pref[i + 1] = tmp;
		}
		pref[0] = 1;
		for (int i = 1; i < pref.length; i++) {
			pref[i] = (int) ((long) pref[i - 1] * pref[i] % P);
		}
		suff[suff.length - 1] = 1;
		for (int i = suff.length - 2; i >= 0; i--) {
			suff[i] = (int) ((long) suff[i + 1] * suff[i] % P);
		}
		for (int i = 0; i < g[v].size(); i++) {
			int u = g[v].get(i);
			aux[u] = (int) ((long) pref[i] * suff[i + 1] % P);
		}
		dpDown[v] = pref[pref.length - 1];
	}

	void dfs2(int v, int dpParUp) {
		dpParUp++;
		if (dpParUp == P) {
			dpParUp = 0;
		}
		dp[v] = (int) ((long) dpDown[v] * dpParUp % P);
		for (int i = 0; i < g[v].size(); i++) {
			int u = g[v].get(i);
			dfs2(u, (int) ((long) aux[u] * dpParUp % P));
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>(2);
		}

		for (int i = 1; i < n; i++) {
			// par[i] = nextInt() - 1;
			int p = nextInt() - 1;
			g[p].add(i);
		}
		dpDown = new int[n];
		aux = new int[n];
		dfs(0);

		dp = new int[n];
		dfs2(0, 0);

		for (int i = 0; i < n; i++) {
			out.print(dp[i] + " ");
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