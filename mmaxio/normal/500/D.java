import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static class Edge {
		int to, id;

		public Edge(int to, int id) {
			this.to = to;
			this.id = id;
		}
	}
	
	List<Edge>[] g;
	long[] pairs;
	int n;
	
	int dfs(int v, int p) {
		int sz = 1;
		for (Edge e : g[v]) {
			if (e.to == p) {
				continue;
			}
			int subSz = dfs(e.to, v);
			sz += subSz;
			pairs[e.id] = (long)subSz * (n - subSz);
		}
		return sz;
	}

	void solve() throws IOException {
		n = nextInt();
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		int[] lens = new int[n - 1];
		
		for (int i = 0; i < n - 1; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			lens[i] = nextInt();
			g[v1].add(new Edge(v2, i));
			g[v2].add(new Edge(v1, i));
		}
		
		pairs = new long[n - 1];
		dfs(0, -1);
		
		int q = nextInt();
		long totPairs = (long)n * (n - 1) / 2;
		double outp = 0;
		
//		System.err.println(Arrays.toString(lens));
//		System.err.println(Arrays.toString(pairs));
		
		for (int i = 0; i < n - 1; i++) {
			outp += 3.0 * lens[i] * pairs[i] / totPairs;
		}
//		System.err.println(outp);
		while (q-- > 0) {
			int id = nextInt() - 1;
			int newW = nextInt();
			int decr = lens[id] - newW;
			
			outp -= 3.0 * decr * pairs[id] / totPairs;
			
			out.println(outp);
			lens[id] = newW;
		}
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