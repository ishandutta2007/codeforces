import java.io.*;
import java.util.*;

public class C_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int cnt1, cnt2;

	int getV(int c1, int c2, int side) {
		return c1 + c2 * (cnt1 + 1) + side * (cnt1 + 1) * (cnt2 + 1);
	}

	static final int MOD = 1000000007;
	static final int INF = Integer.MAX_VALUE / 3;

	class Edge {
		int to, ways;

		public Edge(int to, int ways) {
			this.to = to;
			this.ways = ways;
		}
	}

	int[][] arrC;

	void makeC(int n) {
		arrC = new int[n + 1][];
		for (int i = 0; i <= n; i++) {
			arrC[i] = new int[i + 1];
			arrC[i][0] = arrC[i][i] = 1;
			for (int j = 1; j < i; j++) {
				arrC[i][j] = arrC[i - 1][j - 1] + arrC[i - 1][j];
				if (arrC[i][j] >= MOD)
					arrC[i][j] -= MOD;
			}
		}
	}

	int c(int n, int k) {
		if (n < 0 || k < 0 || k > n)
			return 0;
		return arrC[n][k];
	}

	ArrayList<Edge>[] g;
	int N;

	void solve() throws IOException {
		int n = nextInt();
		int sz = nextInt() / 50;

		cnt1 = 0;
		cnt2 = 0;
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			if (x == 50)
				cnt1++;
			else
				cnt2++;
		}

		N = 2 * (cnt1 + 1) * (cnt2 + 1);

		makeC(Math.max(cnt1, cnt2));

		g = new ArrayList[N];
		for (int i = 0; i < N; i++) {
			g[i] = new ArrayList<>();
		}

		for (int left1 = 0; left1 <= cnt1; left1++) {
			for (int left2 = 0; left2 <= cnt2; left2++) {
				// from left to right
				int v = getV(left1, left2, 0);

				for (int send1 = 0; send1 <= left1 && send1 <= sz; send1++) {
					for (int send2 = 0; send2 <= left2
							&& send1 + 2 * send2 <= sz; send2++) {
						if (send1 + send2 == 0)
							continue;
						int ways = (int) ((long) c(left1, send1)
								* c(left2, send2) % MOD);
						// System.err.println(left1 + " " + left2 + " -> " +
						// send1
						// + " " + send2);
						g[v].add(new Edge(
								getV(left1 - send1, left2 - send2, 1), ways));
					}
				}
				
				v = getV(left1, left2, 1);
				// from right to left
				for (int send1 = 0; send1 <= cnt1 - left1 && send1 <= sz; send1++) {
					for (int send2 = 0; send2 <= cnt2 - left2
							&& send1 + 2 * send2 <= sz; send2++) {
						if (send1 + send2 == 0)
							continue;
						int ways = (int) ((long) c(cnt1 - left1, send1)
								* c(cnt2 - left2, send2) % MOD);
						// System.err.println(left1 + " " + left2 + " -> " +
						// send1
						// + " " + send2);
						g[v].add(new Edge(
								getV(left1 + send1, left2 + send2, 0), ways));
					}
				}
			}
		}
		int st = getV(cnt1, cnt2, 0);
		int en = getV(0, 0, 1);

		int[] d = new int[N];
		Arrays.fill(d, INF);
		d[st] = 0;

		int[] ways = new int[N];
		ways[st] = 1;

		ArrayDeque<Integer> q = new ArrayDeque<>();
		q.add(st);
		while (!q.isEmpty()) {
			int v = q.poll();
			for (int i = 0; i < g[v].size(); i++) {
				Edge e = g[v].get(i);
				if (d[e.to] > d[v] + 1) {
					d[e.to] = d[v] + 1;
					ways[e.to] = 0;
					q.add(e.to);
				}
				if (d[e.to] == d[v] + 1) {
					ways[e.to] += (int) ((long) ways[v] * e.ways % MOD);
					if (ways[e.to] >= MOD)
						ways[e.to] -= MOD;
				}
			}
		}

		if (d[en] == INF) {
			out.println(-1);
			out.println(0);
		} else {
			out.println(d[en]);
			out.println(ways[en]);
		}

	}

	C_new() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C_new();
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