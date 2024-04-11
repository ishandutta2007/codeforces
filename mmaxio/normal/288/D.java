import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	ArrayList<Integer>[] g;
	int[] sz;
	int n;
	
	int[] parent;

	long[] pathLCA;
	long[] pathsAll;

	void go(int v, int p) {
		sz[v] = 1;
		parent[v] = p;

		pathsAll[v] = (long) n * (n - 1) / 2;

		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to != p) {
				go(to, v);
				sz[v] += sz[to];

				pathsAll[v] -= (long) sz[to] * (sz[to] - 1) / 2;
			}
		}

		pathsAll[v] -= (long) (n - sz[v]) * (n - 1 - sz[v]) / 2;

		// not starting at root
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to != p) {
				pathLCA[v] += (long) sz[to] * (sz[v] - 1 - sz[to]);
			}
		}

		pathLCA[v] = pathLCA[v] / 2 + (sz[v] - 1);
	}

	void solve() throws IOException {
		n = nextInt();

		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<>();

		for (int i = 0; i < n - 1; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}

		sz = new int[n];
		pathLCA = new long[n];
		pathsAll = new long[n];
		parent = new int[n];
		go(0, -1);

		long ans = 0;
		// subtrees
		for (int i = 1; i < n; i++) {
			ans += ((long) sz[i] * (sz[i] - 1) / 2)
					* (pathsAll[parent[i]] - (long) sz[i] * (n - sz[i])); // !!!!!!!!
		}
		
//		System.err.println(Arrays.toString(parent));
//		System.err.println(Arrays.toString(sz));
//		System.err.println(Arrays.toString(pathsAll));
//		System.err.println(Arrays.toString(pathLCA));

		// everything but subtrees
		for (int i = 1; i < n; i++) {
			ans += ((long) (n - sz[i]) * (n - sz[i] - 1) / 2) * pathLCA[i];
		}

		out.println(ans);
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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