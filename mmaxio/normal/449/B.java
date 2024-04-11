import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Edge {
		int to, cost, id;

		public Edge(int to, int cost, int id) {
			this.to = to;
			this.cost = cost;
			this.id = id;
		}

	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();

		List<Edge>[] g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>(0);
		}
		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			int cost = nextInt();
			g[v1].add(new Edge(v2, cost, i));
			g[v2].add(new Edge(v1, cost, i));
		}

		for (int i = 0; i < k; i++) {
			int to = nextInt() - 1;
			int cost = nextInt();
			g[0].add(new Edge(to, cost, i + m));
		}

		final long[] d = new long[n];
		Arrays.fill(d, Long.MAX_VALUE / 3);
		d[0] = 0;

		TreeSet<Integer> q = new TreeSet<>(new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				if (d[o1] != d[o2]) {
					return d[o1] < d[o2] ? -1 : 1;
				}
				return o1.compareTo(o2);
			}

		});
		
		int[] from = new int[n];
		Arrays.fill(from, m + k);

		q.add(0);
		while (!q.isEmpty()) {
			int v = q.pollFirst();
			for (int i = 0; i < g[v].size(); i++) {
				Edge e = g[v].get(i);
				if ((d[e.to] > d[v] + e.cost) || (d[e.to] == d[v] + e.cost && from[e.to] > e.id)) {
					q.remove(e.to);
					d[e.to] = d[v] + e.cost;
					from[e.to] = e.id;
					q.add(e.to);
				}
			}
		}

		int ans = k;
		for (int i = 1; i < n; i++) {
			if (from[i] >= m) {
				ans--;
			}
		}
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