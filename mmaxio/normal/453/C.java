import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;
	boolean[] vis;
	int[] odd;
	int[] curOdd;

	int dfs1(int v) {
		vis[v] = true;
		int ret = odd[v];
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (!vis[to]) {
				ret += dfs1(to);
			}
		}
		return ret;
	}

	List<Integer> ans;

	void dfs2(int v, int p) {
		ans.add(v);
		curOdd[v] ^= 1;
		vis[v] = true;
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (!vis[to]) {
				dfs2(to, v);
				ans.add(v);
				curOdd[v] ^= 1;
			}
		}
		if (curOdd[v] != odd[v] && p != -1) {
			ans.add(p);
			curOdd[p] ^= 1;
			ans.add(v);
			curOdd[v] ^= 1;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>(0);
		}

		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}

		odd = new int[n];
		for (int i = 0; i < n; i++) {
			odd[i] = nextInt();
		}

		int comps = 0;
		int where = -1;
		vis = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				int tmp = dfs1(i);
				if (tmp != 0) {
					comps++;
					where = i;
				}
			}
		}
		if (comps == 0) {
			out.println(0);
			return;
		}

		if (comps > 1) {
			out.println(-1);
			return;
		}

		ans = new ArrayList<Integer>(4 * n);
		Arrays.fill(vis, false);
		curOdd = new int[n];
		dfs2(where, -1);
		if (curOdd[where] != odd[where]) {
			ans.remove(ans.size() - 1);
		}
		out.println(ans.size());
		for (int i = 0; i < ans.size(); i++) {
			out.print(ans.get(i) + 1 + " ");
		}
		out.println();
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