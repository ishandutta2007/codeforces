import java.io.*;
import java.util.*;

public class E {

	int[] next;
	int[] head;
	int[] to;

	boolean[] vis;
	int[] path;
	int[] deg;
	int[] ret;
	int n;
	int[] par;

	List<Integer> leaves = new ArrayList<>();
	int deg3;

	boolean dfs(int v, int p, int depth) {
		// System.err.println(v);
		vis[v] = true;
		par[v] = p;
		path[depth] = v;

		if (deg[v] == 1) {
			leaves.add(v);
			leaves.add(depth);
		}

		if (deg[v] == 3 && depth != 0) {
			deg3 = v;
		}

		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			if (u == p) {
				continue;
			}
			if (vis[u]) {
				for (int i = depth; path[i] != u; i--) {
					ret[path[i]] = 1;
				}
				ret[u] = 1;
				return true;
			}
			if (dfs(u, v, depth + 1)) {
				return true;
			}
		}
		return false;
	}

	int[] go(int n, int[] vs, int[] us) {
		this.n = n;
		int m = vs.length;
		next = new int[2 * m];
		to = new int[2 * m];
		head = new int[n];
		Arrays.fill(head, -1);

		ret = new int[n];
		deg = new int[n];
		for (int i = 0; i < m; i++) {
			int v = vs[i];
			int u = us[i];

			to[2 * i] = u;
			next[2 * i] = head[v];
			head[v] = 2 * i;

			to[2 * i + 1] = v;
			next[2 * i + 1] = head[u];
			head[u] = 2 * i + 1;

			deg[v]++;
			deg[u]++;
		}

		for (int v = 0; v < n; v++) {
			if (deg[v] >= 4) {
				ret[v] = 2;
				for (int i = head[v]; i >= 0; i = next[i]) {
					ret[to[i]] = 1;
				}
				return ret;
			}
		}

		vis = new boolean[n];
		path = new int[n];
		par = new int[n];

		deg3 = -1;

		for (int i = 0; i < n; i++) {
			if (deg[i] == 3 && !vis[i]) {
				leaves.clear();
				if (dfs(i, -1, 0)) {
					return ret;
				}

				if (deg3 != -1) {
					for (int e = head[i]; e >= 0; e = next[e]) {
						ret[to[e]] = 1;
					}
					for (int e = head[deg3]; e >= 0; e = next[e]) {
						ret[to[e]] = 1;
					}
					for (int v = deg3; v != -1; v = par[v]) {
						ret[v] = 2;
					}
					return ret;
				}

				if (leaves.size() != 6) {
					throw new AssertionError();
				}

				int p = leaves.get(1);
				int q = leaves.get(3);
				int r = leaves.get(5);
				int pp = Math.min(p, 5);
				int qq = Math.min(q, 5);
				int rr = Math.min(r, 5);
				
//				if (n == 100000 && vs[0] != 0) {
//					throw new AssertionError(p + " " + q + " " + r);
//				}

				long prod = (long)(p + 1) * (q + 1) * (r + 1);

				
				
				if (prod / (p + 1) + prod / (q + 1) + prod / (r + 1) <= prod) {
					
					prod = (pp + 1) * (qq + 1) * (rr + 1);
					ret[i] = (int) prod;
					
					for (int v = leaves.get(0), j = 1; v != i; v = par[v], j++) {
//						ret[v] = (int) (prod / (p + 1) * j);
//						ret[v] = 1_000_000 / (p + 1) * j;
						ret[v] = (int) (prod / (pp + 1) * Math.max(j - p + pp, 0));
					}

					for (int v = leaves.get(2), j = 1; v != i; v = par[v], j++) {
//						ret[v] = (int) (prod / (q + 1) * j);
//						ret[v] = 1_000_000 / (q + 1) * j;
						ret[v] = (int) (prod / (qq + 1) * Math.max(j - q + qq, 0));
					}

					for (int v = leaves.get(4), j = 1; v != i; v = par[v], j++) {
//						ret[v] = (int) (prod / (r + 1) * j);
//						ret[v] = 1_000_000 / (r + 1) * j;
						ret[v] = (int) (prod / (rr + 1) * Math.max(j - r + rr, 0));
					}
					return ret;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				if (dfs(i, -1, 0)) {
					return ret;
				}
			}
		}

		return null;
	}

	void submit() {
		int t = nextInt();
		for (int tst = 1; tst <= t; tst++) {
			int n = nextInt();
			int m = nextInt();
			int[] vs = new int[m];
			int[] us = new int[m];
			for (int i = 0; i < m; i++) {
				vs[i] = nextInt() - 1;
				us[i] = nextInt() - 1;
			}

			int[] ans = go(n, vs, us);
			if (ans == null) {
				out.println("NO");
			} else {
				out.println("YES");
				for (int x : ans) {
					out.print(x + " ");
				}
				out.println();
			}
		}
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {
		int n = 20;
		int[] vs = { 0, 12, 15, 13, 11, 2, 1, 0, 11, 16, 17, 18, 16, 7, 19, 5,
				9, 7, 3 };
		int[] us = { 18, 6, 11, 9, 7, 8, 12, 10, 3, 4, 14, 4, 14, 4, 6, 2, 10,
				19, 2 };
		out.println(n + " " + vs.length);
		for (int i = 0; i < vs.length; i++) {
			out.println(vs[i] + " " + us[i]);
		}
		int[] tmp = go(n, vs, us);
		int power = 0;
		for (int i = 0; i < n; i++) {
			power += tmp[i] * tmp[i];
		}
		for (int i = 0; i < vs.length; i++) {
			power -= tmp[vs[i]] * tmp[us[i]];
		}
		System.err.println(power);
		System.err.println(Arrays.toString(go(n, vs, us)));
	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		// out.println("NO");
		 submit();
//		 stress();
//		test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new E();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}