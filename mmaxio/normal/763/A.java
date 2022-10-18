import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;
	int[] col;
	
	boolean dfs(int v, int p, int req) {
		if (col[v] != req) {
			return false;
		}
		for (int u : g[v]) {
			if (u != p && !dfs(u, v, req)) {
				return false;
			}
		}
		return true;
	}
	
	boolean good(int v) {
//		System.err.println(v);
		for (int u : g[v]) {
			if (!dfs(u, v, col[u])) {
				return false;
			}
		}
		return true;
	}

	void solve() throws IOException {
		int n = nextInt();
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			g[v].add(u);
			g[u].add(v);
		}

		col = new int[n];
		for (int i = 0; i < n; i++) {
			col[i] = nextInt();
		}
		
		for (int v = 0; v < n; v++) {
			for (int u : g[v]) {
				if (col[v] == col[u]) {
					continue;
				}
				
//				System.err.println(v + " " + u);
				
				if (good(v)) {
					out.println("YES");
					out.println(v + 1);
					return;
				}
				
				if (good(u)) {
					out.println("YES");
					out.println(u + 1);
					return;
				}
				
				out.println("NO");
				return;
			}
		}
		
		out.println("YES");
		out.println(1);
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
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