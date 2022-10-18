import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Edge {
		int to, w;

		public Edge(int to, int w) {
			this.to = to;
			this.w = w;
		}
	}

	List<Edge>[] g;

	int[] col;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();

		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}

		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			int w = 1 - nextInt();
			g[v1].add(new Edge(v2, w));
			g[v2].add(new Edge(v1, w));
		}

		int comps = 0;
		col = new int[n];
		Arrays.fill(col, -1);
		for (int i = 0; i < n; i++) {
			if (col[i] == -1) {
				if (!dfs(i, 0)) {
					out.println(0);
					return;
				}
				comps++;
			}
		}

		int P = 1_000_000_007;
		int ret = 1;
		for (int i = 0; i < comps - 1; i++) {
			ret = ret * 2 % P;
		}
		out.println(ret);
	}

	boolean dfs(int v, int cur) {
		col[v] = cur;
		for (Edge e : g[v]) {
			if (col[e.to] != -1) {
				if (col[e.to] != (col[v] ^ e.w)) {
					return false;
				}
			} else {
				if (!dfs(e.to, cur ^ e.w)) {
					return false;
				}
			}
		}
		return true;
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