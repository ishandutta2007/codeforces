import java.io.*;
import java.util.*;

public class D_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;

	int[] size;
	int[] bad;
	int[] dpDown;

	int[] fullMax2;
	int[] fullMax;
	int[] fullWhoMax;

	int[] dpFull;

	int[] a;
	int n;
	int totBad;

	int curBest;

	void dfs(int v, int p, int least) {
		size[v] = 1;
		bad[v] = a[v] < least ? 1 : 0;

		dpDown[v] = 0;
		int maxDown = 0;

		for (int to : g[v]) {
			if (to == p) {
				continue;
			}
			dfs(to, v, least);
			if (bad[to] == 0) {
				dpDown[v] += size[to];
			} else {
				maxDown = Math.max(maxDown, dpDown[to]);
			}
			size[v] += size[to];
			bad[v] += bad[to];
		}

		if (a[v] < least) {
			dpDown[v] = 0;
		} else {
			dpDown[v] += 1 + maxDown;
		}
	}

	void dfs2(int v, int p, int least) {

		dpFull[v] = 0;

		fullMax[v] = 0;
		fullMax2[v] = 0;
		fullWhoMax[v] = -1;

		for (int to : g[v]) {
			if (to != p) {
				if (bad[to] == 0) {
					dpFull[v] += size[to];
					continue;
				}

				if (dpDown[to] > fullMax[v]) {
					fullMax2[v] = fullMax[v];
					fullMax[v] = dpDown[to];
					fullWhoMax[v] = to;
				} else if (dpDown[to] > fullMax2[v]) {
					fullMax2[v] = dpDown[to];
				}
			}
		}
		
		int upMax = 0;

		if (p != -1) {
			if (bad[v] == totBad) {
				dpFull[v] += n - size[v];
			} else if (a[p] >= least) {
				if (bad[v] == 0) {
					upMax = dpFull[p] - size[v];
				} else if (v != fullWhoMax[p]) {
					upMax = dpFull[p];
				} else {
					upMax = dpFull[p] - fullMax[p] + fullMax2[p];
				}
			}
		}
		
		if (upMax > fullMax[v]) {
			fullMax2[v] = fullMax[v];
			fullMax[v] = upMax;
			fullWhoMax[v] = p;
		} else if (upMax > fullMax2[v]) {
			fullMax2[v] = upMax;
		}

		if (a[v] >= least) {
			dpFull[v] += 1 + fullMax[v];
		} else {
			dpFull[v] = 0;
		}
		
		for (int to : g[v]) {
			if (to != p) {
				dfs2(to, v, least);
			}
		}

	}

	boolean can(int least, int need) {
		totBad = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < least) {
				totBad++;
			}
		}
		dfs(0, -1, least);

		dfs2(0, -1, least);

		for (int i = 0; i < n; i++) {
			if (dpFull[i] >= need) {
				return true;
			}
		}

		return false;
	}

	void solve() throws IOException {
		n = nextInt();
		int k = nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}

		for (int i = 0; i < n - 1; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}

		int low = 0;
		int high = 1_000_001;

		size = new int[n];
		bad = new int[n];
		dpDown = new int[n];
		fullMax = new int[n];
		fullMax2 = new int[n];
		fullWhoMax = new int[n];
		
		dpFull = new int[n];
		

		while (high - low > 1) {
			int mid = (low + high) >> 1;
			if (can(mid, k)) {
				low = mid;
			} else {
				high = mid;
			}
		}

		out.println(low);
	}

	D_new() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D_new();
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