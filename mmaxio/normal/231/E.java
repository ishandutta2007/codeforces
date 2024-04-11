import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int MOD = 1000000007;
	static int[] POW2 = new int[100000];
	{
		POW2[0] = 1;
		for (int i = 1; i < 100000; i++) {
			POW2[i] = POW2[i - 1] << 1;
			if (POW2[i] >= MOD)
				POW2[i] -= MOD;
		}
	}

	ArrayList<Integer>[] g;

	int[] p;
	boolean[] use;
	int[] cycleNum;
	int[] depth;
	int N = 0;

	int[][] up;
	int[] cnt;

	int time = 0;
	int[] timeIn;
	int[] timeOut;

	int cycles;

	void dfs(int v, int par, int curD) {
		p[v] = par;
		use[v] = true;
		depth[v] = curD;
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to == par)
				continue;
			if (!use[to])
				dfs(to, v, curD + 1);
			else if (depth[to] < depth[v]) {
				for (int j = v; j != to; j = p[j])
					cycleNum[j] = N;
				cycleNum[to] = N++;
			}
		}
	}

	void dfs2(int v, int par, int curCnt) {
		
		use[v] = true;
		int newV = cycleNum[v];
		boolean calc = par == -1 || cycleNum[par] != newV;
		
		if (calc) {
			//System.err.println(v + " " + newV);
			timeIn[newV] = time++;
			if (newV < cycles)
				curCnt++;
			cnt[newV] = curCnt;

			up[0][newV] = par == -1 ? -1 : cycleNum[par];
			for (int i = 1; i < 17; i++) {
				up[i][newV] = (up[i - 1][newV] == -1) ? -1 : up[i - 1][up[i - 1][newV]];
			}
		}

		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (!use[to])
				dfs2(to, v, curCnt);
		}

		if (calc)
			timeOut[newV] = time++;
	}

	boolean isAnc(int v1, int v2) {
		return timeIn[v1] <= timeIn[v2] && timeOut[v2] <= timeOut[v1];
	}

	int lca(int v1, int v2) {
		for (int i = 16; i >= 0; i--) {
			int to = up[i][v1];
			if (to != -1 && !isAnc(to, v2))
				v1 = to;
		}
		return up[0][v1];
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();

		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<>();

		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}

		use = new boolean[n];
		p = new int[n];
		cycleNum = new int[n];
		depth = new int[n];
		Arrays.fill(cycleNum, -1);

		dfs(0, -1, 0);

		cycles = N;
		for (int i = 0; i < n; i++)
			if (cycleNum[i] == -1)
				cycleNum[i] = N++;

		Arrays.fill(use, false);
		up = new int[17][N];
		cnt = new int[N];
		timeIn = new int[N];
		timeOut = new int[N];

		dfs2(0, -1, 0);
		int q = nextInt();
		while (q-- > 0) {
			int v1 = cycleNum[nextInt() - 1];
			int v2 = cycleNum[nextInt() - 1];
			int res;
			if (v1 == v2)
				res = (v1 < cycles ? 1 : 0);
			else if (isAnc(v1, v2)) {
				res = cnt[v2] - cnt[v1];
				if (v1 < cycles)
					res++;
			} else if (isAnc(v2, v1)) {
				res = cnt[v1] - cnt[v2];
				if (v2 < cycles)
					res++;
			} else {
				int v3 = lca(v1, v2);
				// System.err.println(v1 + " " + v2 + " " + v3);
				res = cnt[v1] + cnt[v2] - 2 * cnt[v3];
				if (v3 < cycles)
					res++;
			}

			out.println(POW2[res]);
		}
	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E();
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