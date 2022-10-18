import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] sum;

	List<Integer>[] g;
	boolean[] uni;
	int[] par;

	void dfs1(int v, int p) {
		par[v] = p;
		for (int u : g[v]) {
			if (u == p) {
				continue;
			}
			dfs1(u, v);
			sum[v] += sum[u];
		}
	}

	long dfs2(int v, int p, int depth) {
		long ret = uni[v] ? depth : 0;
		for (int u : g[v]) {
			if (u == p) {
				continue;
			}
			ret += dfs2(u, v, depth + 1);
		}
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();

		sum = new int[n];
		uni = new boolean[n];
		par = new int[n];
		for (int i = 0; i < 2 * k; i++) {
			int v = nextInt() - 1;
			sum[v] = 1;
			uni[v] = true;
		}

		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			g[v].add(u);
			g[u].add(v);
		}

		dfs1(0, -1);
		int root = 0;
		outer: while (true) {
			int here = sum[root];
			for (int to : g[root]) {
				if (to == par[root]) {
					continue;
				}
				if (sum[to] > k) {
					root = to;
					continue outer;
				}
			}
			break;
		}
		

		long ans = dfs2(root, -1, 0);
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