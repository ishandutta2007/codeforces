import java.io.*;
import java.util.*;

public class G_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final long INF = Long.MAX_VALUE / 3;
	static final int LOG = 18;
	List<Integer>[] g;

	int[][] up;
	int dfsTime;
	int[] tIn, tOut;
	int[] depth;

	void dfs(int v, int p) {
		tIn[v] = dfsTime++;
		up[0][v] = p;
		for (int i = 1; i < LOG; i++) {
			up[i][v] = up[i - 1][up[i - 1][v]];
		}
		for (int to : g[v]) {
			if (to != p) {
				depth[to] = depth[v] + 1;
				dfs(to, v);
			}
		}
		tOut[v] = dfsTime;
	}

	boolean isAnc(int v1, int v2) {
		return tIn[v1] <= tIn[v2] && tOut[v2] <= tOut[v1];
	}

	int LCA(int v1, int v2) {
		if (isAnc(v1, v2)) {
			return v1;
		}
		if (isAnc(v2, v1)) {
			return v2;
		}
		for (int i = LOG - 1; i >= 0; i--) {
			int to = up[i][v2];
			if (!isAnc(to, v1)) {
				v2 = to;
			}
		}
		return up[0][v2];
	}

	int dist(int v1, int v2) {
		return depth[v1] + depth[v2] - 2 * depth[LCA(v1, v2)];
	}

	long go(int s1, int t1, int s2, int t2) {
		int r1 = LCA(s1, t1);
		int r2 = LCA(s2, t2);
		int d1 = depth[s1] + depth[t1] - 2 * depth[r1];
		int d2 = depth[s2] + depth[t2] - 2 * depth[r2];

		int x = r1 ^ LCA(s2, s1) ^ LCA(s2, t1);
		int y = r1 ^ LCA(t2, s1) ^ LCA(t2, t1);
		if (x == y) {
			if ((LCA(s2, t2) ^ LCA(s2, s1) ^ LCA(t2, s1)) != x) {
				return -1;
			}
		}

		int len = dist(x, y);

		int s1x = dist(s1, x);
		int s1y = dist(s1, y);
		int t1x = d1 - s1x;
		int t1y = d1 - s1y;
		int s2x = dist(s2, x);
		int s2y = dist(s2, y);
		int t2x = d2 - s2x;
		int t2y = d2 - s2y;

		long ret = go(2 * d1, Math.min(s1x, s1y), 2 * d2, Math.min(s2x, s2y),
				len, (s1x < s1y) == (s2x < s2y));
		ret = Math.min(
				ret,
				go(2 * d1, Math.min(s1x, s1y), 2 * d2, d2 + Math.min(t2x, t2y),
						len, (s1x < s1y) == (t2x < t2y)));
		ret = Math.min(
				ret,
				go(2 * d1, d1 + Math.min(t1x, t1y), 2 * d2, Math.min(s2x, s2y),
						len, (t1x < t1y) == (s2x < s2y)));
		ret = Math.min(
				ret,
				go(2 * d1, d1 + Math.min(t1x, t1y), 2 * d2,
						d2 + Math.min(t2x, t2y), len,
						(t1x < t1y) == (t2x < t2y)));
		if (ret == INF) {
			ret = -1;
		}
		return ret;
	}

	static class ExtEuclid {
		int g;
		int x;
		int y;

		private ExtEuclid(int g, int x, int y) {
			this.g = g;
			this.x = x;
			this.y = y;
		}

		static ExtEuclid get(int a, int b) {
			if (b == 0) {
				return new ExtEuclid(a, 1, 0);
			}
			ExtEuclid ret = get(b, a % b);
			int newY = ret.x - a / b * ret.y;
			ret.x = ret.y;
			ret.y = newY;
			return ret;
		}
	}

	long go1(int m1, int r1, int m2, int r2) {
		// m1 * x + r1 = m2 * y + r2
		ExtEuclid e = ExtEuclid.get(m1, m2);
		if ((r2 - r1) % e.g != 0) {
			return INF;
		}
		long x = Math.floorMod((long) (r2 - r1) / e.g * e.x, m2 / e.g);
		return m1 * x + r1;
	}

	// min x : x >= 0, l <= (a*x) % m <= r
	// requirements: m >= 1, a >= 0
	long f(long m, long a, long l, long r) {
		// this is all obvious
		a %= m;
		l = Math.max(l, 0);
		r = Math.min(r, m - 1);
		if (l > r) {
			return -1;
		}
		if (l == 0) {
			return 0;
		}
		if (a == 0) {
			return -1;
		}

		// for sought x consider k >= 0 such that: mk + l <= ax <= mk + r
		// if we find min k for which such x exists, actual solution is obvious
		// - ceil((mk + l) / a)
		// rewriting a bit, our task is
		// [min k >= 0: exists x >= 0: ax - r <= mk <= ax - l]
		// in other words, mk % a should be "between" -r and -l
		// if [-r..-l] contains multiple of a, then so does [l..r] and k is 0!
		long cand = (l + a - 1) / a;
		if (a <= r / cand) // cand * a might overflow :D
		{
			return cand;
		}

		// otherwise recurse!
		long k = f(a, m, Math.floorMod(-r, a), Math.floorMod(-l, a));
		return (m * k + l + a - 1) / a;
	}

	long go2(int m1, int r1, int m2, int r2, int len) {
		if ((((r1 & 1) + (r2 & 1) + (len & 1)) & 1) == 1) {
			return INF;
		}
//		System.err.println(m1 + " " + r1 + " " + m2 + " " + r2 + " " + len);
		long low = r2 - r1 - len;
		long high = r2 - r1 + len;
		long p;
		if (Math.floorDiv(low, m2) != Math.floorDiv(high, m2)) {
			p = 0;
		} else {
			p = f(m2, m1, Math.floorMod(low, m2), Math.floorMod(high, m2));
		}
		if (p == -1) {
			return INF;
		}
		long arrive = m1 * p + r1;
		long prevArrive = Math.floorDiv(arrive - r2, m2) * m2 + r2;
		long nextArrive = prevArrive + m2;

		long meetPrev = getMeet(arrive, prevArrive, len);
		long meetNext = getMeet(arrive, nextArrive, len);
		return Math.min(meetPrev, meetNext);
	}

	long getMeet(long a, long b, long len) {
		// meet at x -> (x-a) + (x-b) = len
		long x = (len + a + b) / 2;
		if (x >= a && x >= b && x <= a + len && x <= b + len) {
			return x;
		} else {
			return INF;
		}
	}

	long go(int p1, int s1, int p2, int s2, int len, boolean same) {
//		System.err.println(p1 + " " + s1 + " " + p2 + " " + s2 + " " + len
//				+ " " + same);
		if (same) {
			return go1(p1, s1, p2, s2);
		} else {
			return go2(p1, s1, p2, s2, len);
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<Integer>(2);
		}
		for (int i = 0; i < n - 1; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}
		tIn = new int[n];
		tOut = new int[n];
		depth = new int[n];
		up = new int[LOG][n];
		dfs(0, 0);

		int q = nextInt();
		while (q-- > 0) {
			int from1 = nextInt() - 1;
			int to1 = nextInt() - 1;
			int from2 = nextInt() - 1;
			int to2 = nextInt() - 1;
			out.println(go(from1, to1, from2, to2));

		}
	}

	G_new() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new G_new();
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