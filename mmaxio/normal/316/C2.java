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

	Edge[][] g;
	int[] gSz;

	void addEdge(int v1, int v2, int cost) {
		Edge e1 = new Edge(v2, 1, cost);
		Edge e2 = new Edge(v1, 0, -cost);
		e1.rev = e2;
		e2.rev = e1;
		g[v1][gSz[v1]++] = e1;
		g[v2][gSz[v2]++] = e2;
	}

	int S, T;

	void solve() throws IOException {
		n = nextInt();
		m = nextInt();

		int[][] f = new int[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				f[i][j] = nextInt();

		g = new Edge[n * m + 2][];
		gSz = new int[n * m + 2];
		S = n * m;
		T = n * m + 1;
		for (int i = 0; i < n * m; i++)
			g[i] = new Edge[5];
		g[S] = new Edge[n * m / 2];
		g[T] = new Edge[n * m / 2];
		
		int initFlow = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int v = i * m + j;
				int col = (i + j) & 1;
				if (col == 0) {
					addEdge(S, v, 0);
					Edge e1 = g[v][gSz[v] - 1];
					for (int dir = 0; dir < 4; dir++) {
						int ni = i + dx[dir];
						int nj = j + dy[dir];
						if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
							int to = ni * m + nj;
							int cost = (f[i][j] == f[ni][nj] ? 0 : 1);
							addEdge(v, to, cost);
							if (cost == 0) {
								Edge e2 = g[v][gSz[v] - 1];
								e1.flow--;
								e1.rev.flow++;
								e2.flow++;
								e2.rev.flow--;
								initFlow++;
							}
						}
					}
				} else {
					addEdge(v, T, 0);
					Edge e = g[v][gSz[v] - 1];
					for (int dir = 0; dir < 4; dir++) {
						int ni = i + dx[dir];
						int nj = j + dy[dir];
						if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
							if (f[i][j] == f[ni][nj]) {
								e.flow++;
								e.rev.flow--;
							}
						}
					}
				}
			}
		
		int ans = 0;
		
		final int[] d = new int[n * m + 2];
		Edge[] from = new Edge[n * m + 2];

		int N = n * m + 2;
		
		int[] q = new int[N];
		int head = 0;
		int tail = 0;
		boolean[] inQueue = new boolean[N];
		
		for (int iter = initFlow; iter < n * m / 2; iter++) {
			
			Arrays.fill(d, INF);
			d[S] = 0;
			
			q[tail++] = S;
			if (tail == N)
				tail = 0;
			inQueue[S] = true;
			
			while (head != tail) {
				int v = q[head++];
				if (head == N)
					head = 0;
				inQueue[v] = false;
								
				for (int i = 0; i < gSz[v]; i++) {
					Edge e = g[v][i];
					if (e.flow < e.cap) {
						if (d[e.to] > d[v] + e.cost) {
							from[e.to] = e; 
							d[e.to] = d[v] + e.cost;
							if (!inQueue[e.to]) {
								inQueue[e.to] = true;
								q[tail++] = e.to;
								if (tail == N)
									tail = 0;
							}
						}
					}
				}
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