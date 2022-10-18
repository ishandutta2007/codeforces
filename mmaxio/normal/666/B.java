import java.io.*;
import java.util.*;

public class B {

	static final int INF = Integer.MAX_VALUE / 3;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;
	List<Integer>[] gr;

	int n, m;

	static class CityInfo {
		int id, dist;

		public CityInfo(int id, int dist) {
			this.id = id;
			this.dist = dist;
		}
	}

	int[][] dg;
	int[][] dgr;

	CityInfo[] getBad(List<Integer>[] g, int s, int[][] bigD) {
		int[] d = new int[n];
		Queue<Integer> q = new ArrayDeque<>();
		Arrays.fill(d, INF);
		d[s] = 0;
		q.add(s);

		while (!q.isEmpty()) {
			int v = q.poll();
			for (int to : g[v]) {
				if (d[to] > d[v] + 1) {
					d[to] = d[v] + 1;
					q.add(to);
				}
			}
		}

		bigD[s] = d.clone();

		CityInfo[] ret = new CityInfo[4];
		for (int i = 0; i < 4; i++) {
			int maxDist = 0;
			int id = -1;

			for (int v = 0; v < n; v++) {
				if (d[v] > maxDist && d[v] < INF) {
					maxDist = d[v];
					id = v;
				}
			}

			if (id != -1) {
				d[id] = INF;
			}

			ret[i] = new CityInfo(id, maxDist);
		}

		return ret;
	}

	void solve() throws IOException {
		n = nextInt();
		m = nextInt();

		g = new List[n];
		gr = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
			gr[i] = new ArrayList<>();
		}

		int[] es = new int[2 * m];

		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			gr[v2].add(v1);
			es[2 * i] = v1;
			es[2 * i + 1] = v2;
		}

		CityInfo[][] ig = new CityInfo[n][];
		CityInfo[][] igr = new CityInfo[n][];

		dg = new int[n][];
		dgr = new int[n][];

		for (int i = 0; i < n; i++) {
			ig[i] = getBad(g, i, dg);
			igr[i] = getBad(gr, i, dgr);
		}

		int ans = 0;
		int[] outp = null;

		for (int b = 0; b < n; b++)
			for (int c = 0; c < n; c++) {
				if (b == c || dg[b][c] == INF) {
					continue;
				}

				for (CityInfo a : igr[b])
					for (CityInfo d : ig[c]) {
						if (a.id == c || a.id == d.id || d.id == b) {
							continue;
						}

						if (a.id == -1 || d.id == -1) {
							continue;
						}

						int cur = dg[b][c] + a.dist + d.dist;

						if (cur > ans) {
							ans = cur;
							outp = new int[] { a.id, b, c, d.id };
						}
					}

			}

		for (int x : outp) {
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