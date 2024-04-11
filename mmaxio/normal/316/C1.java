import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int n, m;

	class Edge {
		int to, flow, cap, cost;
		Edge rev;

		public Edge(int to, int cap, int cost) {
			this.to = to;
			this.cap = cap;
			this.cost = cost;
		}
	}

	static final int[] dx = { -1, 0, 1, 0 };
	static final int[] dy = { 0, -1, 0, 1 };
	static final int INF = Integer.MAX_VALUE / 3;

	List<Edge>[] g;

	void addEdge(int v1, int v2, int cost) {
		Edge e1 = new Edge(v2, 1, cost);
		Edge e2 = new Edge(v1, 0, -cost);
		e1.rev = e2;
		e2.rev = e1;
		g[v1].add(e1);
		g[v2].add(e2);
	}

	int S, T;

	void solve() throws IOException {
		n = nextInt();
		m = nextInt();

		int[][] f = new int[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				f[i][j] = nextInt();

		g = new ArrayList[n * m + 2];
		S = n * m;
		T = n * m + 1;
		for (int i = 0; i < n * m; i++)
			g[i] = new ArrayList<>(5);
		g[S] = new ArrayList<>(n * m / 2);
		g[T] = new ArrayList<>(n * m / 2);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int v = i * m + j;
				int col = (i + j) & 1;
				if (col == 0) {
					addEdge(S, v, 0);
					for (int dir = 0; dir < 4; dir++) {
						int ni = i + dx[dir];
						int nj = j + dy[dir];
						if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
							int to = ni * m + nj;
							int cost = (f[i][j] == f[ni][nj] ? 0 : 1);
							addEdge(v, to, cost);
						}
					}
				} else {
					addEdge(v, T, 0);
				}
			}
		
		int ans = 0;
		int[] pi = new int[n * m + 2];
		
		final int[] d = new int[n * m + 2];
		Edge[] from = new Edge[n * m + 2];
		
		Integer[] Integers = new Integer[n * m + 2];
		for (int i = 0; i < n * m + 2; i++)
			Integers[i] = i;
		
		TreeSet<Integer> set = new TreeSet<>(new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				if (d[o1] != d[o2])
					return Integer.compare(d[o1], d[o2]);
				return o1.compareTo(o2);
			}
			
		});
		
		int[] permLabel = new int[n * m + 2];
		int permLabelSz = 0;
		
		for (int iter = 0; iter < n * m / 2; iter++) {
			
			Arrays.fill(d, INF);
			d[S] = 0;
			
			set.add(Integers[S]);
			
			permLabelSz = 0;
			
			while (true) {
				int v = set.pollFirst();
				
				if (v == T) {
					set.clear();
					break;
				}
				
				permLabel[permLabelSz++] = v;
				
				for (int i = 0; i < g[v].size(); i++) {
					Edge e = g[v].get(i);
					if (e.flow < e.cap) {
						int redCost = e.cost - pi[v] + pi[e.to];
						if (redCost < 0)
							throw new AssertionError();
						if (d[e.to] > d[v] + redCost) {
							set.remove(Integers[e.to]);
							from[e.to] = e; 
							d[e.to] = d[v] + redCost;
							set.add(Integers[e.to]);
						}
					}
				}
			}
			
			for (int i = 0; i < permLabelSz; i++) {
				int v = permLabel[i];
				pi[v] -= d[v] - d[T];
			}
			
			for (int v = T; v != S; ) {
				Edge last = from[v];
				last.flow++;
				last.rev.flow--;
				ans += last.cost;
				v = last.rev.to;
			}
			
		}
		
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