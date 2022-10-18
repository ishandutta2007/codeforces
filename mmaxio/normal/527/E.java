import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Edge {
		int from, to;
		Edge rev;
		boolean thisWay;

		public Edge(int from, int to) {
			this.from = from;
			this.to = to;
		}

		@Override
		public String toString() {
			return "[from=" + from + ", to=" + to + "]";
		}
	}

	List<Edge>[] g;

	void addEdge(int v1, int v2) {
		Edge e1 = new Edge(v1, v2);
		Edge e2 = new Edge(v2, v1);
		e1.rev = e2;
		e2.rev = e1;
		g[v1].add(e1);
		g[v2].add(e2);
	}

	boolean[] bad;
	boolean[] vis;
	List<Edge>[] tree;

	void dfs(int v) {
		vis[v] = true;
		for (Edge e : g[v]) {
			if (!vis[e.to]) {
				tree[v].add(e);
				bad[v] ^= true;
				e.thisWay = true;
				dfs(e.to);
			} else if (e.from != e.to) {
				if (!e.rev.thisWay) {
					e.thisWay = true;
					bad[v] ^= true;
				}
			}
		}
	}

	void dfs2(int v) {
		for (Edge e : tree[v]) {
			dfs2(e.to);
			if (bad[e.to]) {
				e.thisWay ^= true;
				e.rev.thisWay ^= true;
				bad[v] ^= true;
			}
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<Edge>(4);
		}
		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			addEdge(v1, v2);
		}
		int oddPair = -1;
		for (int i = 0; i < n; i++) {
			if (g[i].size() % 2 == 1) {
				if (oddPair == -1) {
					oddPair = i;
				} else {
					addEdge(oddPair, i);
					oddPair = -1;
					m++;
				}
			}
		}
		// System.err.println(m);
		if (m % 2 == 1) {
			m++;
			addEdge(0, 0);
		}
		bad = new boolean[n];
		int[] loops = new int[n];
		for (int i = 0; i < n; i++) {
			for (Edge e : g[i]) {
				if (e.from == e.to) {
					loops[i]++;
				}
			}
			loops[i] /= 2;
			bad[i] = (loops[i] & 1) == 1;
		}
		// System.err.println(Arrays.toString(bad));
		vis = new boolean[n];
		tree = new List[n];
		for (int i = 0; i < n; i++) {
			tree[i] = new ArrayList<Edge>(0);
		}
		dfs(0);
		// for (int i = 0; i < n; i++) {
		// for (Edge e : g[i]) {
		// if (e.thisWay && e.from != e.to) {
		// System.err.println(e.from + " " + e.to);
		// }
		// }
		// }
		// System.err.println(Arrays.toString(bad));
		dfs2(0);
		if (bad[0]) {
			throw new AssertionError();
		}
		out.println(m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < loops[i]; j++) {
				out.println((i + 1) + " " + (i + 1));
			}
			for (Edge e : g[i]) {
				if (e.from != e.to && e.thisWay) {
					out.println((e.from + 1) + " " + (e.to + 1));
				}
			}
		}
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