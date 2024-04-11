import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	class Edge {
		int to, id, cap;
		boolean rev;
		public Edge(int to, int id, int cap, boolean rev) {
			this.to = to;
			this.id = id;
			this.cap = cap;
			this.rev = rev;
		}
		
		
	}
	
	ArrayList<Edge>[] g;
	
	long[] disbal, free;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		
		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<>();
			
		disbal = new long[n];
		free = new long[n];
		
		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			int cap = nextInt();
			g[v1].add(new Edge(v2, i, cap, false));
			g[v2].add(new Edge(v1, i, cap, true));
			free[v1] += cap;
			free[v2] += cap;
		}
		
		int[] ans = new int[m];
		Arrays.fill(ans, -1);
		
		ArrayDeque<Integer> q = new ArrayDeque<>();
		q.add(0);
		
		while (!q.isEmpty()) {
			int v = q.poll();
			
			if (v == n - 1)
				continue;
			
			for (int i = 0; i < g[v].size(); i++) {
				Edge e = g[v].get(i);
				if (ans[e.id] != -1)
					continue;
				ans[e.id] = e.rev ? 1 : 0;
				free[e.to] -= e.cap;
				disbal[e.to] += e.cap;
				if (free[e.to] == disbal[e.to])
					q.add(e.to);
			}
			
		}
		
		for (int i = 0; i < m; i++)
			out.println(ans[i]);
		
		
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