import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] head;
	int[] next;
	int[] to;

	int[] sz;

	void dfsSizes(int v, int p) {
		sz[v] = 1;
		for (int idx = head[v]; idx >= 0; idx = next[idx]) {
			int u = to[idx];
			if (u != p) {
				dfsSizes(u, v);
				sz[v] += sz[u];
			}
		}
	}

	int[] ret1;
	int[] leafPath;

	void dfs1(int v, int p) {

		int curPath = -2;
		// -2 -- no path
		// -1 -- bad shit or 2 different paths
		// otherwise -- length of all paths

		for (int idx = head[v]; idx >= 0; idx = next[idx]) {
			int u = to[idx];
			if (u == p) {
				continue;
			}
			dfs1(u, v);
			if (ret1[u] == -1) {
				curPath = -1;
			} else {
				if (curPath == -2 || curPath == ret1[u]) {
					curPath = ret1[u];
				} else {
					curPath = -1;
				}
			}
		}

		if (curPath == -2) {
			ret1[v] = leafPath[v];
		} else if (curPath == -1) {
			ret1[v] = -1;
		} else {
			ret1[v] = curPath + 1;
		}
	}

	int go(int v) {
		dfsSizes(v, -1);

		int sizeAll = sz[v];

		int root = v;
		outer: while (true) {
			for (int idx = head[root]; idx >= 0; idx = next[idx]) {
				int u = to[idx];
				if (sz[u] < sz[root] && sz[u] > sizeAll / 2) {
					root = u;
					continue outer;
				}
			}
			break;
		}

		dfs1(root, -1);

		int nextDfs = -1;
		int path1 = -1, path2 = -1;

		for (int idx = head[root]; idx >= 0; idx = next[idx]) {
			int u = to[idx];
			if (ret1[u] == -1) {
				if (nextDfs == -1) {
					nextDfs = u;
				} else {
					return -1;
				}
			} else {
				if (ret1[u] + 1 == path1 || ret1[u] + 1 == path2) {
					continue;
				}
				if (path1 == -1) {
					path1 = ret1[u] + 1;
				} else if (path2 == -1) {
					path2 = ret1[u] + 1;
				} else {
					return -1;
				}
			}
		}

		if (nextDfs == -1) {
			if (path1 == -1) {
				throw new AssertionError();
			}
			int paths = path1;
			if (path2 != -1) {
				paths += path2;
			}
			while (paths % 2 == 0) {
				paths /= 2;
			}
			return paths;
		}
		
		// nextDfs != -1
		if (path1 == -1) {
			leafPath[root] = 0;
		} else if (path2 == -1) {
			leafPath[root] = path1;
		} else {
			return -1;
		}
		
		// leave only one edge from root: to nextDfs
		to[head[root]] = nextDfs;
		next[head[root]] = -1;
		
		return go(nextDfs);
	}

	void solve() throws IOException {
		int n = nextInt();

		head = new int[n];
		next = new int[2 * n - 2];
		to = new int[2 * n - 2];

		Arrays.fill(head, -1);

		for (int i = 0; i < n - 1; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;

			to[2 * i] = u;
			next[2 * i] = head[v];
			head[v] = 2 * i;

			to[2 * i + 1] = v;
			next[2 * i + 1] = head[u];
			head[u] = 2 * i + 1;
		}

		ret1 = new int[n];
		sz = new int[n];
		leafPath = new int[n];
		out.println(go(0));
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