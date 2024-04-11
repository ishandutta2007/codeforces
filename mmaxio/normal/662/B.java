import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Edge {
		int to;
		char c;

		public Edge(int to, char c) {
			this.to = to;
			this.c = c;
		}
	}

	List<Edge>[] g;
	int n, m;

	int[] color;

	boolean dfs(int v, int cur, char zero, List<Integer> one, List<Integer> two) {
		color[v] = cur;
		(cur == 0 ? one : two).add(v);

		for (Edge e : g[v]) {
			int expected = cur ^ (e.c == zero ? 0 : 1);
			if (color[e.to] == -1) {
				if (!dfs(e.to, expected, zero, one, two))
					return false;
			} else if (color[e.to] != expected) {
				return false;
			}
		}

		return true;
	}

	List<Integer> go(char zero) {
		color = new int[n];
		Arrays.fill(color, -1);
		List<Integer> ret = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			if (color[i] == -1) {
				List<Integer> one = new ArrayList<>();
				List<Integer> two = new ArrayList<>();
				if (!dfs(i, 0, zero, one, two)) {
					return null;
				}
				List<Integer> tmp = one.size() < two.size() ? one : two;
				ret.addAll(tmp);
			}
		}
		return ret;
	}

	void solve() throws IOException {
		n = nextInt();
		m = nextInt();

		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}

		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			char c = nextToken().charAt(0);
			g[v1].add(new Edge(v2, c));
			g[v2].add(new Edge(v1, c));
		}

		List<Integer> a = go('R');
		List<Integer> b = go('B');
		if (a == null) {
			List<Integer> tmp = a;
			a = b;
			b = tmp;
		}

		if (a == null) {
			out.println(-1);
			return;
		}

		List<Integer> ret;
		if (b == null || a.size() < b.size()) {
			ret = a;
		} else {
			ret = b;
		}

		out.println(ret.size());
		for (int x : ret) {
			out.print(x + 1 + " ");
		}
		out.println();
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