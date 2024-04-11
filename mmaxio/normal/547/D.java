import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Edge {
		int v1, v2, id;
		Edge rev;
		boolean active = true;

		public Edge(int v1, int v2, int id) {
			this.v1 = v1;
			this.v2 = v2;
			this.id = id;
		}

		@Override
		public String toString() {
			return "Edge [v1=" + v1 + ", v2=" + v2 + ", id=" + id;
		}
	}

	static final int N = 200_000;

	List<Edge>[] g;

	Edge nextEdge(int v) {
		while (!g[v].isEmpty() && !g[v].get(g[v].size() - 1).active) {
			g[v].remove(g[v].size() - 1);
		}
		if (g[v].isEmpty()) {
			return null;
		}
		Edge ret = g[v].remove(g[v].size() - 1);
		ret.active = ret.rev.active = false;
		return ret;
	}

	void addEdge(int v1, int v2, int id) {
		Edge e1 = new Edge(v1, v2, id);
		Edge e2 = new Edge(v2, v1, id);
		e1.rev = e2;
		e2.rev = e1;
		g[v1].add(e1);
		g[v2].add(e2);
	}

	void solve() throws IOException {
		int n = nextInt();
		g = new List[2 * N + 2];
		for (int i = 0; i < 2 * N + 2; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < n; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1 + N;
			addEdge(v1, v2, i);
		}

		for (int i = 0; i < N; i++) {
			if (g[i].size() % 2 == 1) {
				addEdge(i, 2 * N, -1);
			}
		}
		for (int i = N; i < 2 * N; i++) {
			if (g[i].size() % 2 == 1) {
				addEdge(2 * N + 1, i, -1);
			}
		}

		if (g[2 * N].size() % 2 == 1) {
			addEdge(2 * N, 2 * N + 1, -1);
		}

		char[] ret = new char[n];

		char cur = 'b';

		List<Edge> stack = new ArrayList<>();
		for (int i = 0; i < 2 * N + 2; i++) {
			while (true) {
				Edge e = nextEdge(i);
				if (e == null) {
					break;
				}
				stack.add(e);
				while (!stack.isEmpty()) {
					Edge top = stack.get(stack.size() - 1);
//					System.err.println(top + " " + stack.size());
					Edge next = nextEdge(top.v2);
					if (next == null) {
						if (top.id != -1) {
							ret[top.id] = cur;
						}
						cur = (char) ('b' ^ 'r' ^ cur);
						stack.remove(stack.size() - 1);
					} else {
						stack.add(next);
					}
				}
			}
		}

		out.println(new String(ret));
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D().inp();
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