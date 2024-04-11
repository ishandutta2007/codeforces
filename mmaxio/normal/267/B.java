import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	class Edge {
		int from, to;

		int id;
		boolean isRev;

		public Edge(int from, int to, int id, boolean isRev) {
			this.from = from;
			this.to = to;
			this.id = id;
			this.isRev = isRev;
		}

	}

	ArrayList<Edge>[] g;

	static final int N = 7;

	boolean[] isEdgeAlive;

	Edge getAdjEdge(int v) {
		while (!g[v].isEmpty()) {
			Edge res = g[v].remove(g[v].size() - 1);
			if (isEdgeAlive[res.id]) {
				isEdgeAlive[res.id] = false;
				return res;
			}
		}
		return null;
	}

	void solve() throws IOException {
		g = new ArrayList[N];

		for (int i = 0; i < N; i++) {
			g[i] = new ArrayList<>();
		}

		int n = nextInt();
		for (int i = 0; i < n; i++) {
			int v1 = nextInt();
			int v2 = nextInt();
			g[v1].add(new Edge(v1, v2, i, false));
			g[v2].add(new Edge(v2, v1, i, true));
		}

		int st = -1;
		int en = -1;

		int[] deg = new int[N];
		for (int i = 0; i < N; i++)
			deg[i] = g[i].size();

		for (int i = 0; i < N; i++) {
			if (deg[i] % 2 == 1) {
				if (st == -1)
					st = i;
				else if (en == -1)
					en = i;
				else {
					out.println("No solution");
					return;
				}
			}
		}

		if (st == -1) {
			for (int i = 0; i < N; i++)
				if (deg[i] != 0) {
					st = i;
					break;
				}
		}

		isEdgeAlive = new boolean[n];
		Arrays.fill(isEdgeAlive, true);
		ArrayList<Edge> edgeStack = new ArrayList<>();
		ArrayList<Integer> vertStack = new ArrayList<>();
		vertStack.add(st);

		ArrayList<Edge> ans = new ArrayList<>();

		while (true) {
			int v = vertStack.get(vertStack.size() - 1);
			//System.err.println(v);
			Edge next = getAdjEdge(v);
			if (next == null) {
				vertStack.remove(vertStack.size() - 1);
				if (vertStack.isEmpty())
					break;
				ans.add(edgeStack.remove(edgeStack.size() - 1));
			} else {
				edgeStack.add(next);
				vertStack.add(next.to);
			}
		}

		if (ans.size() != n) {
			out.println("No solution");
			return;
		}

		for (int i = ans.size() - 1; i >= 0; i--) {
			Edge e = ans.get(i);
			out.println(e.id + 1 + " " + (e.isRev ? "-" : "+"));
		}

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