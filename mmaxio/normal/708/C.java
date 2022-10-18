import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;
	int[] size;
	int[] bigC;

	int[] max1;
	int[] whoMax1;
	int[] max2;

	void dfs1(int v, int p) {
		size[v] = 1;
		for (int u : g[v]) {
			if (u == p) {
				continue;
			}
			dfs1(u, v);
			size[v] += size[u];

			if (bigC[v] == -1 || size[bigC[v]] < size[u]) {
				bigC[v] = u;
			}
		}
	}

	void dfs2(int v, int p) {
		size[v] = 1;

		for (int u : g[v]) {
			if (u == p) {
				continue;
			}
			dfs2(u, v);
			size[v] += size[u];

			if (size[u] > max1[v]) {
				max2[v] = max1[v];
				max1[v] = size[u];
				whoMax1[v] = u;
			} else if (size[u] > max2[v]) {
				max2[v] = size[u];
			}

		}
	}

	void dfs3(int v, int p, int maxUp) {

		if (maxUp > n / 2) {
			throw new AssertionError();
		}

		if (p != -1) {
			int upSize = n - size[v];
			ans[v] = upSize - maxUp <= n / 2;
		}

		for (int u : g[v]) {
			if (u == p) {
				continue;
			}

			int nextMaxUp = Math.max(maxUp, u == whoMax1[v] ? max2[v] : max1[v]);
			if (2 * size[u] == n) {
				nextMaxUp = Math.max(nextMaxUp, n / 2);
			}
			dfs3(u, v, nextMaxUp);
		}
	}

	boolean[] ans;

	int n;

	Random rng = new Random();

	void solve() throws IOException {
		n = nextInt();
		// n = 1000;

		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}

		for (int i = 0; i < n - 1; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			// int v = i + 1;
			// int u = rng.nextInt(v);
			g[v].add(u);
			g[u].add(v);
		}

		if (n == 2) {
			out.println("1 1");
			return;
		}

		bigC = new int[n];
		Arrays.fill(bigC, -1);
		size = new int[n];
		dfs1(0, -1);

		int root = 0;
		while (true) {
			int nxt = bigC[root];
			if (nxt != -1 && size[nxt] > n / 2) {
				root = nxt;
			} else {
				break;
			}
		}

		max1 = new int[n];
		whoMax1 = new int[n];
		max2 = new int[n];

		Arrays.fill(max1, -1);
		Arrays.fill(max2, -1);
		Arrays.fill(whoMax1, -1);
		dfs2(root, -1);

		ans = new boolean[n];
		ans[root] = true;

		dfs3(root, -1, -1);

		for (boolean b : ans) {
			out.print(b ? "1 " : "0 ");
		}
		out.println();
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		// int i = 0;
		// while (i < Integer.MAX_VALUE) {
		// solve();
		// System.err.println(i++);
		// }

		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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