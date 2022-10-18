import java.io.*;
import java.util.*;

public class B {

	static final int INF = Integer.MAX_VALUE / 3;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int n, m;

	int[] getDists(int v) {
		int[] d = new int[n];
		Arrays.fill(d, INF);
		d[v] = 0;
		ArrayDeque<Integer> q = new ArrayDeque<>();
		q.add(v);
		while (!q.isEmpty()) {
			v = q.poll();
			for (int to : g[v]) {
				if (d[to] > d[v] + 1) {
					d[to] = d[v] + 1;
					q.add(to);
				}
			}
		}
		return d;
	}

	List<Integer>[] g;

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
			g[v1].add(v2);
			g[v2].add(v1);
		}

		int s1 = nextInt() - 1;
		int t1 = nextInt() - 1;
		int bound1 = nextInt();

		int s2 = nextInt() - 1;
		int t2 = nextInt() - 1;
		int bound2 = nextInt();

		int[][] allD = new int[n][];
		for (int i = 0; i < n; i++) {
			allD[i] = getDists(i);
		}

		int[] ds1 = allD[s1];
		int[] dt1 = allD[t1];
		int[] ds2 = allD[s2];
		int[] dt2 = allD[t2];

		if (ds1[t1] > bound1 || ds2[t2] > bound2) {
			out.println(-1);
			return;
		}

		int len1 = ds1[t1];
		int len2 = ds2[t2];

		int ans = len1 + len2;
		
		for (int v = 0; v < n; v++)
			for (int u = 0; u < n; u++) {
				if (ds1[v] + allD[v][u] + dt1[u] <= bound1) {
					if (ds2[v] + allD[v][u] + dt2[u] <= bound2) {
						ans = Math.min(ans, ds1[v] + dt1[u] + ds2[v] + dt2[u]
								+ allD[v][u]);
					}
					if (ds2[u] + allD[v][u] + dt2[v] <= bound2) {
						ans = Math.min(ans, ds1[v] + dt1[u] + ds2[u] + dt2[v]
								+ allD[v][u]);
					}
				}
			}
		out.println(m - ans);
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