import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	long ans = Long.MAX_VALUE;

	int n;

	int[][] adj;

	List<Integer>[] g;

	int paths = 0;

	boolean dfs(int v, int p) {
		int cnt = 0;
		int child = 0;
		for (int to : g[v]) {
			if (to != p) {
				child++;
				if (dfs(to, v)) {
					cnt++;
				}
			}
		}

		if (child == 0) {
			cnt++;
		}

		if (cnt <= 1) {
			return true;
		}
		
		paths += cnt - 1;
		
		return false;
	}

	void solve() throws IOException {
		n = nextInt();
		int x = nextInt();
		int y = nextInt();
		if (x == y) {
			out.println((long) x * (n - 1));
			return;
		}

		if (x > y) {
			int[] deg = new int[n];
			for (int i = 0; i < n - 1; i++) {
				int v1 = nextInt() - 1;
				int v2 = nextInt() - 1;
				deg[v1]++;
				deg[v2]++;
			}
			for (int i = 0; i < n; i++) {
				if (deg[i] == n - 1) {
					out.println((long)y * (n - 2) + x);
					return;
				}
			}
			out.println((long)y * (n - 1));
			return;
		}

		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}

		for (int i = 0; i < n - 1; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}

		if (dfs(0, -1)) {
			paths++;
		}

		// System.err.println(paths);

		long ret = (long) y * (paths - 1) + (long) x * ((n - 1) - (paths - 1));
		out.println(ret);
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