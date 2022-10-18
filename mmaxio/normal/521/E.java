import java.io.*;
import java.util.*;

public class E_clean {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;

	int[] up;
	int[] depth;
	int[] vis;
	int visVer;
	int[] par;
	boolean[] cut;
	int dfsTime;
	int[] tIn, tOut;
	int[] color;

	void dfs(int v, int p) {
		tIn[v] = dfsTime++;
		par[v] = p;
		vis[v] = visVer;
		up[v] = depth[v];
		for (int to : g[v]) {
			if (to == p) {
				continue;
			}
			if (vis[to] != visVer) {
				depth[to] = depth[v] + 1;
				dfs(to, v);
				up[v] = Math.min(up[v], up[to]);
				if (p != -1 && up[to] >= depth[v]) {
					cut[to] = true;
				}
			} else {
				up[v] = Math.min(up[v], depth[to]);
			}
		}
		if (p == -1) {
			for (int to : g[v]) {
				if (par[to] == v) {
					cut[to] = true;
				}
			}
		}
		tOut[v] = dfsTime;
	}

	boolean isAnc(int v, int u) {
		return tIn[v] <= tIn[u] && tOut[u] <= tOut[v];
	}

	int n, m;

	List<Integer> getCycle(int v, int c, List<Integer> path) {

		path.add(v);

//		System.err.println(v + " " + path);
		for (Integer to : g[v]) {
			if (to == par[v] || depth[to] > depth[v] + 1) {
				continue;
			}
			if (depth[to] < depth[v]) {
				return path.subList(path.indexOf(to), path.size());
			}
			if (to != c && cut[to]) {
				continue;
			}
			List<Integer> ret = getCycle(to, c, path);
			if (ret != null) {
				return ret;
			}
		}
		path.remove(path.size() - 1);
		return null;
	}

	void printPath(List<Integer> path) {
		out.print(path.size() + " ");
		for (int v : path) {
			out.print((v + 1) + " ");
		}
		out.println();
	}

	boolean getPath(int v, boolean[] goal, List<Integer> path) {
		vis[v] = visVer;
		path.add(v);
		if (goal[v]) {
			return true;
		}
		for (Integer to : g[v]) {
			if (vis[to] != visVer) {
				if (getPath(to, goal, path)) {
					return true;
				}
			}
		}
		path.remove(path.size() - 1);
		return false;
	}

	boolean checkAnswer(int v) {
		List<Integer> path = new ArrayList<>();
		path.add(par[v]);
		List<Integer> cycle = getCycle(v, v, path);
		
		if (cycle == null) {
			return false;
		}
//		System.err.println(cycle);
		for (int i = 0; i < cycle.size(); i++) {
			int cur = cycle.get(i);
			int prev = cycle.get(i == 0 ? cycle.size() - 1 : i - 1);
			int next = cycle.get(i == cycle.size() - 1 ? 0 : i + 1);
			for (Integer to : g[cur]) {
				if (to == prev || to == next) {
					continue;
				}
				if (color[to] != v && to != par[v]) {
					continue;
				}
//				System.err.println(cur + " " + to + " " + v);
				visVer++;
				boolean[] goal = new boolean[n];
				for (int u : cycle) {
					if (u != cur) {
						goal[u] = true;
					}
				}
				path = new ArrayList<>();
				path.add(cur);
				vis[cur] = visVer;
				if (!getPath(to, goal, path)) {
					throw new AssertionError();
				}
				out.println("YES");
				int end = path.get(path.size() - 1);
				printPath(path);
				List<Integer> p1 = new ArrayList<>();
				for (int j = i; cycle.get(j) != end; j = (j + 1) % cycle.size()) {
					p1.add(cycle.get(j));
				}
				p1.add(end);
				printPath(p1);
				List<Integer> p2 = new ArrayList<>();
				for (int j = i; cycle.get(j) != end; j = (j + cycle.size() - 1)
						% cycle.size()) {
					p2.add(cycle.get(j));
				}
				p2.add(end);
				printPath(p2);
				return true;
			}
		}
		return false;
	}
	
	void dfsColor(int v) {
		if (cut[v]) {
			color[v] = v;
		}
		for (int to : g[v]) {
			if (par[to] != v) {
				continue;
			}
			color[to] = color[v];
			dfsColor(to);
		}
	}

	void solve(int n, int[] v1, int[] v2) {
		this.n = n;
		m = v1.length;
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>(0);
		}
		for (int i = 0; i < m; i++) {
			g[v1[i]].add(v2[i]);
			g[v2[i]].add(v1[i]);
		}

		vis = new int[n];
		par = new int[n];
		up = new int[n];
		depth = new int[n];
		cut = new boolean[n];
		tIn = new int[n];
		tOut = new int[n];

		visVer++;
		for (int i = 0; i < n; i++) {
			if (vis[i] != visVer) {
				dfs(i, -1);
			}
		}
		
		color = new int[n];
		Arrays.fill(color, -1);
		for (int i = 0; i < n; i++) {
			if (par[i] == -1) {
				dfsColor(i);
			}
		}
//		System.err.println(Arrays.toString(par));
//		System.err.println(Arrays.toString(cut));
		for (int i = 0; i < n; i++) {
			if (cut[i]) {
				if (checkAnswer(i)) {
					return;
				}
			}
		}
		out.println("NO");
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		int n = nextInt();
		int m = nextInt();
		int[] v1 = new int[m];
		int[] v2 = new int[m];
		for (int i = 0; i < m; i++) {
			v1[i] = nextInt() - 1;
			v2[i] = nextInt() - 1;
		}
		solve(n, v1, v2);
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E_clean().inp();
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