import java.io.*;
import java.util.*;

public class C {

	int[] head;
	int[] next;
	int[] to;

	int[] sz;

	int[] par;

	void dfs1(int v, int p) {
		par[v] = p;
		sz[v] = 1;
		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			if (u == p) {
				continue;
			}
			dfs1(u, v);
			sz[v] += sz[u];
		}
	}

	void dfsMarkLeaves(int v, int p, int bigRoot) {
//		prevForPaths[v] = bigRoot;
		if (graph[v].size() == 1) {
			leaves[leavesPtr++] = v;
		}

		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			if (u == p) {
				continue;
			}
			dfsMarkLeaves(u, v, bigRoot);
		}
	}

	int[] ansArr;
	int ansPtr;

	TreeSet<Integer>[] graph;
	int[] leaves;
	int leavesPtr;

	int[] prevForPaths;

	void go2(int v, int root) {

		if (graph[v].size() == 1) {
			return;
		}

		int upV = root;

		leavesPtr = 0;
		dfsMarkLeaves(v, root, root);

		int cur;

		while (true) {
			while (graph[v].size() == 2) {
				int next = graph[v].first() ^ graph[v].last() ^ upV;
				prevForPaths[v] = upV;
				upV = v;
				v = next;
			}

			if (graph[v].size() == 1) {
				prevForPaths[v] = upV;
				cur = v;
				break;
			}

			int leaf = leaves[--leavesPtr];

			ansArr[ansPtr++] = upV;
			ansArr[ansPtr++] = v;
			ansArr[ansPtr++] = leaf;

			graph[leaf].add(upV);
			graph[v].remove(upV);

			v = leaf;
		}

		int last = cur;

		cur = prevForPaths[cur];
		if (cur == -1) {
			throw new AssertionError();
		}
		while (prevForPaths[cur] != -1) {
			ansArr[ansPtr++] = prevForPaths[cur];
			ansArr[ansPtr++] = cur;
			ansArr[ansPtr++] = last;
			cur = prevForPaths[cur];
		}
	}

	void go(int root, int bad) {
		for (int e = head[root]; e >= 0; e = next[e]) {
			int v = to[e];
			if (v == bad) {
				continue;
			}
			go2(v, root);
		}
	}

	void solve(int[] vs, int[] us) {
		int n = vs.length + 1;

		head = new int[n];
		next = new int[2 * n - 2];
		to = new int[2 * n - 2];
		Arrays.fill(head, -1);

		graph = new TreeSet[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new TreeSet<>();
		}

		for (int i = 0; i < n - 1; i++) {
			int v = vs[i];
			int u = us[i];

			to[2 * i] = u;
			next[2 * i] = head[v];
			head[v] = 2 * i;

			to[2 * i + 1] = v;
			next[2 * i + 1] = head[u];
			head[u] = 2 * i + 1;

			graph[v].add(u);
			graph[u].add(v);
		}

		sz = new int[n];
		par = new int[n];
		dfs1(0, -1);

		int root1 = 0;

		outer: while (true) {
			for (int e = head[root1]; e >= 0; e = next[e]) {
				int u = to[e];
				if (u == par[root1]) {
					continue;
				}
				if (2 * sz[u] >= n) {
					root1 = u;
					continue outer;
				}
			}
			break;
		}

		int root2 = -1;
		if (2 * sz[root1] == n) {
			root2 = par[root1];
		}

		ansArr = new int[6 * n];
		ansPtr = 0;

		leaves = new int[n];
		prevForPaths = new int[n];
		Arrays.fill(prevForPaths, -1);

		go(root1, root2);
		if (root2 != -1) {
			go(root2, root1);
		}

		out.println(ansPtr / 3);
		for (int i = 0; i < ansPtr; i += 3) {
			out.println((ansArr[i] + 1) + " " + (ansArr[i + 1] + 1) + " "
					+ (ansArr[i + 2] + 1));
		}
	}

	void submit() {
		int n = nextInt();

		int[] vs = new int[n - 1];
		int[] us = new int[n - 1];

		for (int i = 0; i < n - 1; i++) {
			vs[i] = nextInt() - 1;
			us[i] = nextInt() - 1;
		}

		solve(vs, us);
	}

	void preCalc() {

	}

	void stress() {
		for (int tst = 0;; tst++) {
			oneTest();
			System.err.println(tst);
		}
	}

	void oneTest() {
		int n = rand(1, 10);
		int[] vs = new int[n - 1];
		int[] us = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			vs[i] = i + 1;
			us[i] = rand(0, i);
		}
		solve(vs, us);

		boolean[][] g = new boolean[n][n];
		for (int i = 0; i < n - 1; i++) {
			g[vs[i]][us[i]] = g[us[i]][vs[i]] = true;
		}

		for (int i = 0; i < ansPtr; i += 3) {
			int x = ansArr[i];
			int y = ansArr[i + 1];
			int z = ansArr[i + 2];
			if (!g[x][y] || g[x][z]) {
				System.err.println(Arrays.toString(vs));
				System.err.println(Arrays.toString(us));
				throw new AssertionError();
			}
			g[x][y] = g[y][x] = false;
			g[x][z] = g[z][x] = true;
		}

		int[][] d = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					d[i][j] = 0;
				} else {
					d[i][j] = g[i][j] ? 1 : Integer.MAX_VALUE / 3;
				}
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}

		int bound = n % 2 == 1 ? 4 : 5;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][j] > bound) {
					System.err.println(Arrays.toString(vs));
					System.err.println(Arrays.toString(us));
					throw new AssertionError();
				}
			}
		}

	}	

	void test() {
		int[] vs = { 1, 2, 3, 4, 5, 6, 7, 8 };
		int[] us = { 0, 1, 2, 2, 0, 0, 4, 7 };

		solve(vs, us);
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
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
		new C();
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