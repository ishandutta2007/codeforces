import java.io.*;
import java.util.*;

public class cf328D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;
	int[] d;
	boolean[] def;

	boolean dfs(int v, int p, int c) {
		d[v] = c;
		boolean hasDef = def[v];
		for (int to : g[v]) {
			if (to != p) {
				boolean tmp = dfs(to, v, c + 1); 
				if (tmp) {
					sz++;
				}
				hasDef |= tmp;
			}
		}
		return hasDef;
	}

	int sz;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>(2);
		}
		for (int i = 0; i < n - 1; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}
		d = new int[n];
		int[] list = new int[m];
		def = new boolean[n];
		for (int i = 0; i < m; i++) {
			list[i] = nextInt() - 1;
			def[list[i]] = true;
		}

		dfs(list[0], -1, 0);
		int maxD = -1;
		int ans1 = -1;
		for (int i = 0; i < n; i++) {
			if (!def[i]) {
				continue;
			}
			if (d[i] > maxD || (d[i] == maxD && i < ans1)) {
				maxD = d[i];
				ans1 = i;
			}
		}
		sz = 0;
		dfs(ans1, -1, 0);
		maxD = -1;
		int ans2 = -1;
		for (int i = 0; i < n; i++) {
			if (!def[i]) {
				continue;
			}
			if (d[i] > maxD || (d[i] == maxD && i < ans2)) {
				maxD = d[i];
				ans2 = i;
			}
		}
		out.println(Math.min(ans1, ans2) + 1);
		out.println(2 * sz - maxD);
	}

	cf328D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new cf328D();
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