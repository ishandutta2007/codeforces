import java.io.*;
import java.util.*;

public class D_bad {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static class Edge implements Comparable<Edge> {
		int v1, v2, w, id;

		public Edge(int v1, int v2, int w, int id) {
			this.v1 = v1;
			this.v2 = v2;
			this.w = w;
			this.id = id;
		}

		@Override
		public int compareTo(Edge o) {
			return -Integer.compare(w, o.w);
		}
	}
	
	int[] p;
	int[] rank;
	
	int get(int v) {
		if ((v << 1) == p[v]) {
			return (v << 1);
		}
		int tmp = p[v];
		int ret = get(tmp >> 1) ^ (tmp & 1);
		return p[v] = ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int qs = nextInt();

		Edge[] es = new Edge[m];

		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			int w = nextInt();
			es[i] = new Edge(v1, v2, w, i);
		}
		
		Arrays.sort(es);
		
		int[] ids = new int[m];
		int[] ws = new int[m];
		int[] v1s = new int[m];
		int[] v2s = new int[m];
		
		for (int i = 0; i < m; i++) {
			ids[i] = es[i].id;
			ws[i] = es[i].w;
			v1s[i] = es[i].v1;
			v2s[i] = es[i].v2;
		}
		
		p = new int[n];
		rank = new int[n];
		
		outer: while (qs-- > 0) {
			int l = nextInt() - 1;
			int r = nextInt() - 1;
			
			for (int i = 0; i < n; i++) {
				p[i] = (i << 1);
				rank[i] = 0;
			}
			
			for (int i = 0; i < m; i++) {
				int tmp = ids[i];
				if (tmp < l || tmp > r) {
					continue;
				}
				
				int v1 = get(v1s[i]);
				int v2 = get(v2s[i]);
				
//				System.err.println(v1 + " " + v2);
				
				if (v1 == v2) {
					out.println(ws[i]);
					continue outer;
				}
				
				if ((v1 ^ v2) == 1) {
					continue;
				}
				
				if (rank[v1 >> 1] < rank[v2 >> 1]) {
					tmp = v1;
					v1 = v2;
					v2 = tmp;
				}
				
				if (rank[v1 >> 1] == rank[v2 >> 1]) {
					rank[v1 >> 1]++;
				}
				
				p[v2 >> 1] = ((v1 >> 1) << 1) | (1 ^ (v1 & 1) ^ (v2 & 1));
				
			}
			out.println(-1);
		}
		
		
	}

	D_bad() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D_bad();
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