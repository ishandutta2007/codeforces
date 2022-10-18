import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	class Edge {
		int to;
		String s;
		
		public Edge(int to, String s) {
			this.to = to;
			this.s = s;
		}
	}
	
	ArrayList<Edge>[] g;
	String t;
	int[] pi;
	
	int[] prefixFunction(String s) {
		int[] pi = new int[s.length()];
		for (int i = 1; i < s.length(); i++) {
			int q = pi[i - 1];
			while (q != 0 && s.charAt(i) != s.charAt(q))
				q = pi[q - 1];
			if (s.charAt(i) == s.charAt(q))
				q++;
			pi[i] = q;
		}
		return pi;
	}
	
	int dfs(int v, int qRoot) {
		int ans = 0;
		for (int i = 0; i < g[v].size(); i++) {
			Edge e = g[v].get(i);
			int q = qRoot;
			for (int j = 0; j < e.s.length(); j++) {
				while (q != 0 && e.s.charAt(j) != t.charAt(q))
					q = pi[q - 1];
				if (e.s.charAt(j) == t.charAt(q))
					q++;
				if (q == t.length()) {
					ans++;
					q = pi[q - 1];
				}
			}
			ans += dfs(e.to, q);
		}
		return ans;
	}

	void solve() throws IOException {
		int n = nextInt();
		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>(1);
		}
		for (int i = 1; i < n; i++) {
			int par = nextInt() - 1;
			String s = nextToken();
			g[par].add(new Edge(i, s));
		}
		
		t = nextString();
		pi = prefixFunction(t);
		
		out.println(dfs(0, 0));
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