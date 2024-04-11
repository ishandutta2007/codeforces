import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;
	int[] a;
	int[] cnt;

	static final long BIG = 1_000_000_000_000_000L;

	long[] lcm;

	void dfs(int v, int p) {
		lcm[v] = 1;
		cnt[v] = 0;
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to == p) {
				continue;
			}
			cnt[v]++;
			dfs(to, v);
			lcm[v] = boundedLcm(lcm[v], lcm[to]);
		}
		if (cnt[v] == 0)
			return;
		if (lcm[v] > BIG / cnt[v])
			lcm[v] = BIG + 1;
		else
			lcm[v] *= cnt[v];
	}

	long boundedLcm(long a, long b) {
		if (a > BIG || b > BIG)
			return BIG + 1;
		long gcd = gcd(a, b);
		a /= gcd;
		if (a > BIG / b) {
			return BIG + 1;
		}
		return a * b;
	}

	long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	long dfs2(int v, int p) {
		if (cnt[v] == 0)
			return a[v];
		long needMod = lcm[v] / cnt[v];

		long minCan = Long.MAX_VALUE;

		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to == p) {
				continue;
			}

			long ret = dfs2(to, v);
			ret = ret / needMod * needMod;
			minCan = Math.min(minCan, ret);
		}

		return minCan * cnt[v];
	}

	void solve() throws IOException {
		int n = nextInt();

		long tot = 0;

		a = new int[n];

		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			tot += a[i];
		}

		g = new List[n];
		cnt = new int[n];

		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>(0);
		}

		for (int i = 0; i < n - 1; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}

		lcm = new long[n];
		dfs(0, -1);

		if (lcm[0] > BIG) {
			out.println(tot);
			return;
		}

		out.println(tot - dfs2(0, -1));
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