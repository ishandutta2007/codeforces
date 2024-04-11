import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	ArrayList<Integer>[] g;

	int[] depth;

	void dfs(int v, int p, int d) {
		depth[v] = d;
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to != p)
				dfs(to, v, d + 1);
		}
	}

	void solve() throws IOException {
		int n = nextInt();

		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<>();

		for (int i = 0; i < n - 1; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}
		depth = new int[n];
		dfs(0, -1, 1);

		double res = 0;
		for (int i = 0; i < n; i++)
			res += 1.0 / depth[i];

		out.printf("%.12f\n", res);
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
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