import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	ArrayList<Edge>[] g;

	static class Edge {
		int to, dig;

		public Edge(int to, int dig) {
			this.to = to;
			this.dig = dig;
		}
	}

	int m, inv10;
	long ans = 0;

	int[] sz;
	int[] par;

	void dfs1(int v, int p) {
		sz[v] = 1;
		par[v] = p;
		for (Edge e : g[v]) {
			if (e.to != p) {
				dfs1(e.to, v);
				sz[v] += sz[e.to];
			}
		}
	}

	void removeAdj(ArrayList<Edge> adj, int v) {
		for (int i = 0; i < adj.size(); i++) {
			if (v == adj.get(i).to) {
				adj.set(i, adj.get(adj.size() - 1));
				adj.remove(adj.size() - 1);
				return;
			}
		}
		throw new AssertionError();
	}

	void dfs2(int v, int p, int depth, int downRem, int upRem,
			HashMap<Integer, Integer> map, ArrayList<Integer> lst, boolean countRoot) {

		if (countRoot) {
			if (downRem == 0) {
				ans++;
			}
			if (upRem == 0) {
				ans++;
			}
		}
		
		lst.add(upRem);

		int seek = downRem == 0 ? 0 : m - downRem;
		seek = (int) ((long) seek * inv10Pow[depth] % m);

		Integer delta = map.get(seek);
		if (delta != null) {
			ans += delta;
		}

		for (Edge e : g[v]) {
			if (e.to == p) {
				continue;
			}
			dfs2(e.to, v, depth + 1, (int) ((10L * downRem + e.dig) % m),
					(int) (((long) just10Pow[depth] * e.dig + upRem) % m), map,
					lst, countRoot);
		}
	}

	void go2(int v) {
		{
			HashMap<Integer, Integer> map = new HashMap<>();
			for (int j = 0; j < g[v].size(); j++) {
				Edge e = g[v].get(j);
				ArrayList<Integer> lst = new ArrayList<>();
				dfs2(e.to, v, 1, e.dig, e.dig, map, lst, true);

				for (int i = 0; i < lst.size(); i++) {
					int key = lst.get(i);
					Integer prev = map.get(key);
					if (prev == null) {
						prev = 0;
					}
					map.put(key, prev + 1);
				}
			}
		}
		{
			HashMap<Integer, Integer> map = new HashMap<>();
			for (int j = g[v].size() - 1; j >= 0; j--) {
				Edge e = g[v].get(j);
				ArrayList<Integer> lst = new ArrayList<>();
				dfs2(e.to, v, 1, e.dig, e.dig, map, lst, false);

				for (int i = 0; i < lst.size(); i++) {
					int key = lst.get(i);
					Integer prev = map.get(key);
					if (prev == null) {
						prev = 0;
					}
					map.put(key, prev + 1);
				}
			}
		}
	}

	void go(int v) {
		dfs1(v, -1);

		int center = v;
		outer: while (true) {
			for (Edge e : g[center]) {
				int to = e.to;
				if (to != par[center] && 2 * sz[to] >= sz[v]) {
					center = to;
					continue outer;
				}
			}
			break;
		}

		go2(center);
		for (Edge e : g[center]) {
			removeAdj(g[e.to], center);
			go(e.to);
		}
	}

	int[] inv10Pow;
	int[] just10Pow;

	void solve() throws IOException {
		int n = nextInt();
		m = nextInt();

		if (m == 1) {
			out.println((long) n * (n - 1));
			return;
		}

		inv10 = BigInteger.TEN.modInverse(BigInteger.valueOf(m)).intValue();

		inv10Pow = new int[n + 1];
		inv10Pow[0] = 1;
		for (int i = 1; i < inv10Pow.length; i++) {
			inv10Pow[i] = (int) ((long) inv10Pow[i - 1] * inv10 % m);
		}

		just10Pow = new int[n + 1];
		just10Pow[0] = 1;
		for (int i = 1; i < just10Pow.length; i++) {
			just10Pow[i] = (int) ((long) just10Pow[i - 1] * 10 % m);
		}

		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}

		for (int i = 0; i < n - 1; i++) {
			int v = nextInt();
			int u = nextInt();
			int dig = nextInt() % m;
			g[v].add(new Edge(u, dig));
			g[u].add(new Edge(v, dig));
		}

		par = new int[n];
		sz = new int[n];
		go(0);
		out.println(ans);
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