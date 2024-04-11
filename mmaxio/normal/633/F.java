import java.io.*;
import java.util.*;

public class F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final long INF = Long.MAX_VALUE / 10;

	long[] a;
	List<Integer>[] g;

	long[] down;
	long[] down2;
	long[] down3;
	int[] downWho, downWho2;
	long[] diamSub;
	long[] diamSub2;
	int[] diamSubWho;

	long[] diamHereUp;
	long[] justDiamSub;

	void dfs(int v, int p) {
		g[v].remove(new Integer(p));
		down[v] = down2[v] = down3[v] = a[v];
		downWho[v] = v;

		diamSub[v] = diamSub2[v] = -1;
		diamSubWho[v] = -1;

		for (int to : g[v]) {
			dfs(to, v);
			long toDown = a[v] + down[to];
			if (toDown > down[v]) {
				down3[v] = down2[v];
				down2[v] = down[v];
				downWho2[v] = downWho[v];
				down[v] = toDown;
				downWho[v] = to;
			} else if (toDown > down2[v]) {			
				down3[v] = down2[v];
				downWho2[v] = to;
				down2[v] = toDown;
			} else if (toDown > down3[v]) {
				down3[v] = toDown;
			}

			if (diamSub[to] > diamSub[v]) {
				diamSub2[v] = diamSub[v];
				diamSub[v] = diamSub[to];
				diamSubWho[v] = to;
			} else if (diamSub[to] > diamSub2[v]) {
				diamSub2[v] = diamSub[to];
			}

		}
		
		justDiamSub[v] = diamSub[v];

		diamSub[v] = Math.max(diamSub[v], down[v] + down2[v] - a[v]);
	}

	void dfs2(int v, long maxUp) {
		for (int to : g[v]) {
			long nowDown = downWho[v] == to ? down2[v] : down[v];
			
			diamHereUp[to] = Math.max(diamHereUp[v], nowDown + maxUp - a[v]);
			if (downWho[v] == to) {
				diamHereUp[to] = Math.max(diamHereUp[to], down2[v] + down3[v] - a[v]);
			} else if (downWho2[v] == to) {
				diamHereUp[to] = Math.max(diamHereUp[to], down[v] + down3[v] - a[v]);
			} else {
				diamHereUp[to] = Math.max(diamHereUp[to], down[v] + down2[v] - a[v]);
			}
			
			long diamDown = diamSubWho[v] == to ? diamSub2[v] : justDiamSub[v];
			diamHereUp[to] = Math.max(diamHereUp[to], diamDown);

			long toMaxUp = Math.max(a[to] + maxUp, a[to] + nowDown);
			dfs2(to, toMaxUp);
		}
	}

	void solve() throws IOException {
		int n = nextInt();

		a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextLong();
		}

		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			g[v].add(u);
			g[u].add(v);
		}

		down = new long[n];
		down2 = new long[n];
		down3 = new long[n];
		downWho = new int[n];
		downWho2 = new int[n];
		diamSub = new long[n];
		diamSub2 = new long[n];
		diamSubWho = new int[n];
		justDiamSub = new long[n];
		dfs(0, -1);

		diamHereUp = new long[n];
		dfs2(0, a[0]);
		
		long ret = -1;
		for (int i = 1; i < n; i++) {
			ret = Math.max(ret, diamSub[i] + diamHereUp[i]);
		}
		
		out.println(ret);
	}

	F() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new F();
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