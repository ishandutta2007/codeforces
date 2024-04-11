import java.io.*;
import java.util.*;

public class F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	int n;
	int root;
	List<Edge>[] g;
	
	static class Edge {
		int to, cost;

		public Edge(int to, int cost) {
			this.to = to;
			this.cost = cost;
		}

		@Override
		public String toString() {
			return "(" + to + ", " + cost + ")";
		}
	}
	
	static class Distance implements Comparable<Distance> {
		int v;
		long dist;
		
		public Distance(int v, long dist) {
			this.v = v;
			this.dist = dist;
		}

		@Override
		public int compareTo(Distance o) {
			return Long.compare(dist, o.dist);
		}
		
	}
	
	static final long INF = Long.MAX_VALUE / 10;
	
	long[] shortestPaths(int from, int killed) {
		long[] d = new long[n];
		Arrays.fill(d, INF);
		d[from] = 0;
		
		PriorityQueue<Distance> pq = new PriorityQueue<>();
		pq.add(new Distance(from, 0));
		
		while (!pq.isEmpty()) {
			Distance tmp = pq.poll();
			int v = tmp.v;
			long dist = tmp.dist;
			if (d[v] != dist) {
				continue;
			}
			
			for (Edge e : g[v]) {
				if (e.to != killed && d[e.to] > d[v] + e.cost) {
					d[e.to] = d[v] + e.cost;
					pq.add(new Distance(e.to, d[e.to]));
				}
			}
		}
		
		return d;
	}
	
	int brute() {
		long[] d = shortestPaths(root, -1);
		int ret = 0;
		for (int i = 0; i < n; i++) {
			if (i == root) {
				continue;
			}
			long[] d2 = shortestPaths(root, i);
			
			int cur = 0;
			for (int j = 0; j < n; j++) {
				if (d[j] != d2[j]) {
					cur++;
				}
			}
			
			ret = Math.max(ret, cur);
		}
		
		return ret;
	}
	
	int[] depth;
	
	static final int LOG = 18;
	
	boolean[] vis;

	int[] order;
	int ptr;
	
	void dfs(int v, int par, long[] dist) {
		
//		System.err.println(v + " " + par);
		
		
		vis[v] = true;
		
		
		for (Edge e : g[v]) {
			if (!vis[e.to] && dist[e.to] == dist[v] + e.cost) {
				dfs(e.to, v, dist);
			}
		}
		
		order[ptr++] = v;
	}

	int solve() {
		long[] d = shortestPaths(root, -1);
		
		
		vis = new boolean[n];
		order = new int[n];
		ptr = 0;
		
		dfs(root, root, d);
		
		for (int i = 0, j = ptr - 1; i < j; i++, j--) {
			int tmp = order[i];
			order[i] = order[j];
			order[j] = tmp;
		}
		int ret = 0;
		
//		System.err.println(Arrays.toString(order));
		
		int[] color = new int[n];
		int cnt = 0;
		
		int[] byColor = new int[n];
		
		for (int i = 1; i < ptr; i++) {
			int v = order[i];
			
			int cur = -1;
			
			for (Edge e : g[v]) {
				if (d[e.to] + e.cost == d[v]) {
					
					if (e.to == root) {
						cur = cnt++;
						break;
					}
					if (cur == -1) {
						cur = color[e.to];
					}
					if (cur != color[e.to]) {
						cur = cnt++;
						break;
					}
					
				}
			}
			
			color[v] = cur;
			byColor[cur]++;
			
			ret = Math.max(ret, byColor[cur]);
		}
		
		return ret;
	}
	
	void submit() throws IOException {
		n = nextInt();
		int m = nextInt();
		root = nextInt() - 1;
		
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		
		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			int len = nextInt();
			g[v].add(new Edge(u, len));
			g[u].add(new Edge(v, len));
		}
		
		out.println(solve());
//		out.println(brute());
	}
	
	static final Random rng = new Random();
	
	void stress(int maxN, int num, int denom, int bound) {
		for (int tst = 0; tst < Integer.MAX_VALUE; tst++) {
			
			n = rng.nextInt(maxN) + 1;
			
			g = new List[n];
			for (int i = 0; i < n; i++) {
				g[i] = new ArrayList<>();
			}
			
			for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++) {
					if (rng.nextInt(denom) < num) {
						
						int len = rng.nextInt(bound) + 1;
						g[i].add(new Edge(j, len));
						g[j].add(new Edge(i, len));
						
					}
				}
			
			if (solve() != brute()) {
				System.err.println(n);
				System.err.println(Arrays.toString(g));
				break;
			}
			
			System.err.println(tst);
			
		}
	}
	
	F() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
//		stress(10, 1, 2, 10);
		
		submit();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new F();
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