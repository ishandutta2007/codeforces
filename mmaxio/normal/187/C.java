import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int INF = Integer.MAX_VALUE / 2;

	ArrayList<Integer>[] g;

	int s, t;
	int[] nearDist;
	ArrayDeque<Integer> q;

	boolean[] use;

	boolean check(int v, int max) {
		if (v == t)
			return true;
		use[v] = true;
		for (int to : g[v])
			if (!use[to] && nearDist[v] + nearDist[to] + 1 <= max)
				if (check(to, max))
					return true;
		return false;
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();

		int[] good = new int[k + 1];
		for (int i = 0; i < k; i++)
			good[i] = nextInt() - 1;

		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<Integer>();

		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}

		s = nextInt() - 1;
		t = nextInt() - 1;

		good[k] = t;

		nearDist = new int[n];
		Arrays.fill(nearDist, INF);

		q = new ArrayDeque<Integer>();

		for (int v : good) {
			nearDist[v] = 0;
			q.add(v);
		}

		while (!q.isEmpty()) {
			int v = q.poll();
			for (int to : g[v])
				if (nearDist[to] > nearDist[v] + 1) {
					nearDist[to] = nearDist[v] + 1;
					q.add(to);
				}
		}

		int l = 0;
		int r = n;
		use = new boolean[n];
		while (l < r - 1) {
			int mid = (l + r) >> 1;
			Arrays.fill(use, false);
			if (check(s, mid))
				r = mid;
			else
				l = mid;
		}

		if (r == n)
			out.println(-1);
		else
			out.println(r);

	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C().inp();
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