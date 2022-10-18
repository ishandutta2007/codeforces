import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	ArrayList<Integer>[] g, gr;
	int[] color;
	
	static final int NON_VISITED = Integer.MAX_VALUE;
	
	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	
	int ans = 0;
	
	void dfs(int v, int cur) {
		color[v] = cur;
		for (int to : g[v]) {
			if (color[to] == NON_VISITED)
				dfs(to, cur + 1);
			else {
				int tmp = Math.abs(color[to] - (cur + 1));
				ans = gcd(ans, tmp);
			}
		}
		for (int to : gr[v]) {
			if (color[to] == NON_VISITED)
				dfs(to, cur - 1);
			else {
				int tmp = Math.abs(color[to] - (cur - 1));
				ans = gcd(ans, tmp);
			}
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		g = new ArrayList[n];
		gr = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<Integer>();
			gr[i] = new ArrayList<Integer>();
		}
		
		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			gr[v2].add(v1);
		}
		
		color = new int[n];
		Arrays.fill(color, NON_VISITED);
		for (int i = 0; i < n; i++)
			if (color[i] == NON_VISITED)
				dfs(i, 0);
		out.println(ans == 0 ? n : ans);
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C().inp();
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