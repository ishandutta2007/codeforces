import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Edge {
		public Edge(int to, int id) {
			this.to = to;
			this.id = id;
		}

		int to, id;
	}

	List<Edge>[] g;
	
	int[] vis;
	int visVer = 0;
	int n;
	
	List<Integer> order;
	
	void dfs(int v, int mid) {
		vis[v] = visVer;
		for (Edge e : g[v]) {
			if (vis[e.to] != visVer && e.id < mid) {
				dfs(e.to, mid);
			}
		}
		order.add(v);
	}
	
	boolean can(int mid) {
		order.clear();
		visVer++;
		for (int i = 0; i < n; i++) {
			if (vis[i] != visVer) {
				dfs(i, mid);
			}
		}
		outer: for (int i = n - 1; i > 0; i--) {
			int v = order.get(i);
			int u = order.get(i - 1);
			for (Edge e : g[v]) {
				if (e.id < mid && e.to == u) {
					continue outer;
				}
			}
			return false;
		}
		return true;
	}

	void solve() throws IOException {
		n = nextInt();
		int m = nextInt();

		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		
		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(new Edge(v2, i));
		}
		
		int low = 0;
		int high = m + 1;
		vis = new int[n];
		
		order = new ArrayList<>(n);
		
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			if (can(mid)) {
				high = mid;
			} else {
				low = mid;
			}
		}
		
		out.println(high == m + 1 ? -1 : high);
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