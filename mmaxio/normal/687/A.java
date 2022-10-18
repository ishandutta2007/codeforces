import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	List<Integer>[] g;
	
	int[] col;
	
	boolean dfs(int v, int c, List<Integer> one, List<Integer> two) {
		col[v] = c;
		(c == 1 ? one : two).add(v);
		for (int u : g[v]) {
			if (col[u] == 0) {
				if (!dfs(u, 3 - c, one, two)) {
					return false;
				}
			} else if (col[u] == c) {
				return false;
			}
		}
		return true;
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		
		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}
		
		List<Integer> one = new ArrayList<>();
		List<Integer> two = new ArrayList<>();
		
		col = new int[n];
		for (int i = 0; i < n; i++) {
			if (col[i] == 0) {
				if (!dfs(i, 1, one, two)) {
					out.println(-1);
					return;
				}
			}
		}
		
		out.println(one.size());
		for (int x : one) {
			out.print((x + 1) + " ");
		}
		out.println();
		
		out.println(two.size());
		for (int x : two) {
			out.print((x + 1) + " ");
		}
		out.println();
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