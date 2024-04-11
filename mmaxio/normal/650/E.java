import java.io.*;
import java.util.*;

public class E_nostack2 {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;
	List<Pair>[] g2;

	static class Pair { //l
		int x, y;
		boolean used;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	int[] par;

	int get(int v) {
		return par[v] == v ? v : (par[v] = get(par[v]));
	}

	void solve() throws IOException {
		int n = nextInt();
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
		
		int[] p = new int[n];
		
		int[] rec = new int[n];
		int recSz = 0;
		
		rec[recSz++] = 0;
		p[0] = -1;
		
		int[] dfs = new int[n];
		int dfsSz = 0;
		
		while (recSz > 0) {
			int v = rec[--recSz];
			dfs[dfsSz++] = v;
			for (int to : g[v]) {
				if (to != p[v]) {
					p[to] = v;
					rec[recSz++] = to;
				}
			}
		}
		
		g2 = new List[n];
		for (int i = 0; i < n; i++) {
			g2[i] = new ArrayList<>();
		}
		
		int ans = 0;
		
		boolean[] same = new boolean[n];

		for (int i = 0; i < n - 1; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			if (p[v1] != v2 && p[v2] != v1) {
				ans++;
				Pair tmp = new Pair(v1, v2);
				g2[v1].add(tmp);
				g2[v2].add(tmp);
			} else if (p[v1] == v2) {
				same[v1] = true;
			} else {
				same[v2] = true;
			}
		}

		out.println(ans);

		par = new int[n];
		for (int i = 0; i < n; i++) {
			par[i] = i;
		}
		
		for (int i = n - 1; i >= 1; i--) {
			int to = dfs[i];
			int v = p[to];
			if (v == -1) {
				break;
			}
			
			if (!same[to]) {
				Pair tmp;
				do {
					tmp = g2[to].remove(g2[to].size() - 1);
				} while (tmp.used);
				
				tmp.used = true;

				out.println((to + 1) + " " + (v + 1) + " " + (tmp.x + 1)
						+ " " + (tmp.y + 1));

				par[to] = get(tmp.x) != to ? tmp.x : tmp.y;
			} else {
				par[to] = v;
			}
			int u = get(to);
			if (g2[u].size() > g2[to].size()) {
				g2[u].addAll(g2[to]);
			} else {
				g2[to].addAll(g2[u]);
				g2[u] = g2[to];
			}
		}
		
	}

	E_nostack2() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);

		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E_nostack2();
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