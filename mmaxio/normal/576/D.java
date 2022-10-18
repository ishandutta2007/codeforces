import java.io.*;
import java.util.*;

public class D_fast {

	static final int INF = Integer.MAX_VALUE / 2;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Edge implements Comparable<Edge> {
		int from, to, need;

		public Edge(int from, int to, int need) {
			this.from = from;
			this.to = to;
			this.need = need;
		}

		@Override
		public int compareTo(Edge o) {
			return Integer.compare(need, o.need);
		}
	}

	List<Integer>[] g;

	int n;
	int nBit;

	int[] bfs(int v) {
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

	boolean test(long mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	long[][] mult(long[][] a, long[][] b) {

		long[][] c = new long[n][nBit];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (test(a[i][j >> 6], j & 63)) {
					for (int k = 0; k < nBit; k++) {
						c[i][k] |= b[j][k];
					}
				}
			}
		}
		return c;
	}

	long[][] pow(long[][] a, int b) {
		long[][] ret = new long[n][nBit];
		for (int i = 0; i < n; i++) {
			ret[i][i >> 6] |= 1L << (i & 63);
		}
		for (; b > 0; b >>= 1) {
			if ((b & 1) == 1) {
				ret = mult(ret, a);
			}
			a = mult(a, a);
		}
		return ret;
	}

	void solve() throws IOException {
		n = nextInt();
		nBit = (n + 63) / 64;
		int m = nextInt();
		
		boolean flag = false;

		Edge[] all = new Edge[m];
		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			int need = nextInt();
			flag |= v1 == 129 && v2 == 133;
			all[i] = new Edge(v1, v2, need);
		}

		Arrays.sort(all);
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}

		int ret = INF;

		long[][] adjM = new long[n][nBit];

		boolean[] can = new boolean[n];
		can[0] = true;

		int ptr = 0;
		while (ptr < m && all[ptr].need == 0) {

			int row = all[ptr].from;
			int col = all[ptr].to;

			adjM[row][col >> 6] |= 1L << (col & 63);
			g[all[ptr].to].add(all[ptr].from);
			ptr++;
		}

		if (ptr == 0) {
			out.println("Impossible");
			return;
		}

		int[] d = bfs(n - 1);
		for (int i = 0; i < n; i++) {
			if (can[i] && d[i] != INF) {
				ret = Math.min(ret, 0 + d[i]);
			}
		}

		while (ptr < m) {
			int tmp = all[ptr].need;
			int prev = all[ptr - 1].need;

			long[][] newAdjM = pow(adjM, tmp - prev);
			boolean[] newCan = new boolean[n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					newCan[j] |= can[i] && test(newAdjM[i][j >> 6], j & 63);
				}
			}

			can = newCan;
			

			// System.err.println(tmp + " " + " " + Arrays.toString(d) + " "
			// + Arrays.toString(can));

			for (int i = ptr; i < m && all[i].need == tmp; i++) {
				g[all[i].to].add(all[i].from);
			}
			d = bfs(n - 1);

			for (int i = 0; i < n; i++) {
				if (can[i] && d[i] != INF) {

					// System.err.println(tmp + " " + i + " " +
					// Arrays.toString(d)
					// + " " + Arrays.toString(can));

					ret = Math.min(ret, tmp + d[i]);
				}
			}

			while (ptr < m && all[ptr].need == tmp) {
				int row = all[ptr].from;
				int col = all[ptr].to;

				adjM[row][col >> 6] |= 1L << (col & 63);
				ptr++;
			}
		}

		out.println(ret == INF ? "Impossible" : ret);

	}

	D_fast() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D_fast();
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