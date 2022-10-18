import java.io.*;
import java.util.*;

public class D {

	static final int INF = Integer.MAX_VALUE / 10;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] v1, v2;
	int[][] g;
	int[][] d;

	int n, m;

	int[] deg;
	
	double[] ps;
	int[] psList;
	int psPtr = 0;
	
	double[] maxP;
	int[] maxPList;
	int maxPPtr = 0;

	double go2(Integer[] vs, int from, int to) {
		double stupid = 1.0 / (to - from);

		double smart = 0;
		
		for (int i = from; i < to; i++) {

			int v = vs[i];
			
			for (int j = 0; j < deg[v]; j++) {
				int u = g[v][j];
				if (ps[u] < 0) {
					ps[u] = 0;
					psList[psPtr++] = u;
				}
				ps[u] += stupid / deg[v];
			}
			
		}
		
		for (int v2 = 0; v2 < n; v2++) {
			for (int i = 0; i < psPtr; i++) {
				int u = psList[i];
				int dst = d[v2][u];
				if (maxP[dst] < 0) {
					maxP[dst] = 0;
					maxPList[maxPPtr++] = dst;
				}
				maxP[dst] = Math.max(maxP[dst], ps[u]);
			}
			double here = 0;
			for (int i = 0; i < maxPPtr; i++) {
				here += maxP[maxPList[i]];
			}
			smart = Math.max(smart, here);
			
			
			while (maxPPtr > 0) {
				int v = maxPList[--maxPPtr];
				maxP[v] = -1;
			}
		}
		
		while (psPtr > 0) {
			int v = psList[--psPtr];
			ps[v] = -1;
		}
		
//		System.err.println(from + " " + to + " -> " + smart + " " + stupid);

		return Math.max(smart, stupid);

	}

	double go(int v) {
		final int[] dist = d[v];
		Integer[] a = new Integer[n];
		for (int i = 0; i < n; i++) {
			a[i] = i;
		}
		Arrays.sort(a, new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				return Integer.compare(dist[o1], dist[o2]);
			}

		});

		double ret = 0;

		for (int i = 0; i < n;) {
			int j = i;
			while (j < n && dist[a[i]] == dist[a[j]]) {
				j++;
			}

			ret += 1.0 * (j - i) / n * go2(a, i, j);
			i = j;
		}

		return ret;
	}

	void solve() throws IOException {
		n = nextInt();
		m = nextInt();

		v1 = new int[m];
		v2 = new int[m];
		deg = new int[n];

		d = new int[n][n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(d[i], INF);
			d[i][i] = 0;
		}

		for (int i = 0; i < m; i++) {
			v1[i] = nextInt() - 1;
			v2[i] = nextInt() - 1;
			d[v1[i]][v2[i]] = d[v2[i]][v1[i]] = 1;
			deg[v1[i]]++;
			deg[v2[i]]++;
		}

		g = new int[n][];
		for (int i = 0; i < n; i++) {
			g[i] = new int[deg[i]];
		}

		int[] ptrDeg = deg.clone();

		for (int i = 0; i < m; i++) {
			int v = v1[i];
			int u = v2[i];
			g[v][--ptrDeg[v]] = u;
			g[u][--ptrDeg[u]] = v;
		}

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
				}
		
		ps = new double[n];
		Arrays.fill(ps, -1);
		psList = new int[n];
		
		maxP = new double[n];
		Arrays.fill(maxP, -1);
		maxPList = new int[n];
		
		double ans = 0;
		for (int i = 0; i < n; i++) { // !!!
			ans = Math.max(ans, go(i));
		}

		out.println(ans);

	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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