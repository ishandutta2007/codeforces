import java.io.*;
import java.util.*;

public class D_faster2 {

	static final long INF = Long.MAX_VALUE / 4;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Edge {
		int to, cost;

		public Edge(int to, int cost) {
			this.to = to;
			this.cost = cost;
		}
	}

	List<Edge>[] g;

	int n;

	long[] dijkstra(int S) {
		final long[] d = new long[n];
		Arrays.fill(d, INF);
		d[S] = 0;
		TreeSet<Integer> set = new TreeSet<>(new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				if (d[o1] != d[o2]) {
					return d[o1] < d[o2] ? -1 : 1;
				}
				return o1.compareTo(o2);
			}
		});
		set.add(S);
		while (!set.isEmpty()) {
			int v = set.pollFirst();
			for (Edge e : g[v]) {
				if (d[e.to] > d[v] + e.cost) {
					set.remove(e.to);
					d[e.to] = d[v] + e.cost;
					set.add(e.to);
				}
			}
		}
		return d;
	}

	long[][][] dp;
	boolean[][][] vis;

	int[][] cntCorner;
	int[][] cntRow;
	int[][] cntCol;
	long[][] sumRow;
	long[][] sumCol;

	int w, h;

	long go(int x, int y, int move, int canStop) {
		int fst = 2 * move + canStop;
		if (vis[fst][x][y]) {
			return dp[fst][x][y];
		}

		if (cntCorner[x][y] == 0) {
			vis[fst][x][y] = true;
			return dp[fst][x][y] = 0;
		}

		if (move == 0) {
			long ret = Long.MIN_VALUE;
			if (canStop == 1) {
				ret = Math.max(ret, -go(x, y, 1, 0));
			}

			int canStopAfter = cntRow[x][y] > 0 ? 1 : 0;
			long val = go(x + 1, y, 0, canStop | canStopAfter);
			if (val == Long.MIN_VALUE) {
				throw new AssertionError();
			}
			val += sumRow[x][y];
			ret = Math.max(ret, val);

			vis[fst][x][y] = true;
			return dp[fst][x][y] = ret;
		}

		if (move == 1) {
			long ret = Long.MIN_VALUE;
			if (canStop == 1) {
				ret = Math.max(ret, -go(x, y, 0, 0));
			}
			int canStopAfter = cntCol[x][y] > 0 ? 1 : 0;
			long val = go(x, y + 1, 1, canStop | canStopAfter);
			if (val == Long.MIN_VALUE) {
				throw new AssertionError();
			}
			val += sumCol[x][y];
			ret = Math.max(ret, val);

			vis[fst][x][y] = true;
			return dp[fst][x][y] = ret;
		}

		throw new AssertionError();

	}

	void solve() throws IOException {
		n = nextInt();
		int m = nextInt();
		int s = nextInt() - 1;
		int t = nextInt() - 1;

		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt();
		}
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			int len = nextInt();
			g[v1].add(new Edge(v2, len));
			g[v2].add(new Edge(v1, len));
		}

		long[] ds = dijkstra(s);
		long[] dt = dijkstra(t);

		long[] allS = unique(ds.clone());
		long[] allT = unique(dt.clone());

		int[] x = new int[n];
		int[] y = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = Arrays.binarySearch(allS, ds[i]);
			y[i] = Arrays.binarySearch(allT, dt[i]);
		}

		w = allS.length;
		h = allT.length;
		long[][] sum_ = new long[w][h];
		int[][] cnt_ = new int[w][h];
		for (int i = 0; i < n; i++) {
			sum_[x[i]][y[i]] += p[i];
			cnt_[x[i]][y[i]]++;
		}

		cntCorner = new int[w + 1][h + 1];
		for (int i = w - 1; i >= 0; i--)
			for (int j = h - 1; j >= 0; j--) {
				cntCorner[i][j] = cntCorner[i + 1][j] + cntCorner[i][j + 1]
						- cntCorner[i + 1][j + 1] + cnt_[i][j];
			}
		
		cntRow = new int[w + 1][h + 1];
		for (int i = w - 1; i >= 0; i--)
			for (int j = h - 1; j >= 0; j--) {
				cntRow[i][j] = cntRow[i][j + 1] + cnt_[i][j];
			}
		
		cntCol = new int[w + 1][h + 1];
		for (int i = w - 1; i >= 0; i--)
			for (int j = h - 1; j >= 0; j--) {
				cntCol[i][j] = cntCol[i + 1][j] + cnt_[i][j];
			}
		
		sumRow = new long[w + 1][h + 1];
		for (int i = w - 1; i >= 0; i--)
			for (int j = h - 1; j >= 0; j--) {
				sumRow[i][j] = sumRow[i][j + 1] + sum_[i][j];
			}
		
		sumCol = new long[w + 1][h + 1];
		for (int i = w - 1; i >= 0; i--)
			for (int j = h - 1; j >= 0; j--) {
				sumCol[i][j] = sumCol[i + 1][j] + sum_[i][j];
			}
		

		dp = new long[4][w + 1][h + 1];
		vis = new boolean[4][w + 1][h + 1];

		long ret = go(0, 0, 0, 0);
		if (ret > 0) {
			out.println("Break a heart");
		} else if (ret == 0) {
			out.println("Flowers");
		} else {
			out.println("Cry");
		}
	}

	long[] unique(long[] a) {
		Arrays.sort(a);
		int sz = 1;
		for (int i = 1; i < a.length; i++) {
			if (a[i] != a[sz - 1]) {
				a[sz++] = a[i];
			}
		}
		return Arrays.copyOf(a, sz);
	}

	D_faster2() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D_faster2();
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