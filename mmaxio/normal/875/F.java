import java.io.*;
import java.util.*;

public class F {

	static class Edge implements Comparable<Edge> {
		public Edge(int v, int u, int cost) {
			this.v = v;
			this.u = u;
			this.cost = cost;
		}

		int v, u, cost;

		@Override
		public int compareTo(Edge o) {
			return -Integer.compare(cost, o.cost);
		}
	}

	int[] p;
	int[] rank;
	boolean[] cycle;

	void submit() {
		int n = nextInt();
		int m = nextInt();
		Edge[] a = new Edge[m];
		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			int c = nextInt();
			a[i] = new Edge(v, u, c);
		}
		Arrays.sort(a);

		p = new int[n];
		rank = new int[n];
		cycle = new boolean[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}

		long ans = 0;

		for (Edge e : a) {
			int v = get(e.v);
			int u = get(e.u);
			if (cycle[v] && cycle[u]) {
				continue;
			}
			if (v == u) {
				cycle[v] = true;
				ans += e.cost;
			} else {
				ans += e.cost;
				if (rank[v] < rank[u]) {
					int tmp = v;
					v = u;
					u = tmp;
				}
				if (rank[v] == rank[u]) {
					rank[v]++;
				}
				p[u] = v;
				cycle[v] |= cycle[u];
			}
		}
		out.println(ans);
	}

	int get(int v) {
		return p[v] == v ? v : (p[v] = get(p[v]));
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	F() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new F();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}