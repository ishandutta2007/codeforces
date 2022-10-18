import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static class Edge {
		int to, len;

		public Edge(int to, int len) {
			this.to = to;
			this.len = len;
		}
	}
	
	List<Edge>[] g;
	
	long[] dist;
	
	int[] from;
	int[] to;
	
	int time;

	void dfs(int v) {
		from[v] = time++;
		for (Edge e : g[v]) {
			dist[e.to] = dist[v] + e.len;
			dfs(e.to);
		}
		to[v] = time;
	}
	
	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		
		
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		
		for (int i = 1; i < n; i++) {
			int p = nextInt() - 1;
			int w = nextInt();
			g[p].add(new Edge(i, w));
		}
		
		dist = new long[n];
		
		from = new int[n];
		to = new int[n];
		dfs(0);
		
//		System.err.println(Arrays.toString(dist));
		
		Event[] evs = new Event[2 * n];
		for (int i = 0; i < n; i++) {
			evs[2 * i] = new Event(dist[i] - a[i], i, false);
			evs[2 * i + 1] = new Event(dist[i], i, true);
		} 
		
		Arrays.sort(evs);
		
		int[] ans = new int[n];
		int[] fen = new int[n];
		
		for (Event ev : evs) {
			if (ev.type) {
				ans[ev.pos] = get(fen, from[ev.pos] + 1, to[ev.pos] - 1); 
			} else {
				add(fen, from[ev.pos]);
			}
		}
		
		for (int x : ans) {
			out.print(x + " ");
		}
		out.println();
		
	}
	
	int get(int[] f, int l, int r) {
		return get(f, r) - get(f, l - 1);
	}
	
	int get(int[] f, int pos) {
		int ret = 0;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
			ret += f[i];
		}
		return ret;
	}
	
	void add(int[] f, int pos) {
		for (int i = pos; i < f.length; i |= i + 1) {
			f[i]++;
		}
	}
	
	static class Event implements Comparable<Event> {
		long val;
		int pos;
		
		boolean type;

		public Event(long val, int pos, boolean type) {
			this.val = val;
			this.pos = pos;
			this.type = type;
		}

		@Override
		public int compareTo(Event o) {
			if (val != o.val) {
				return val < o.val ? -1 : 1;
			}
			return Boolean.compare(type, o.type);
		}
		
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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