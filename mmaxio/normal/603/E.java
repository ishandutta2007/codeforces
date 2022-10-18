import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static boolean odd(int x) {
		return (x & 1) == 1;
	}

	static class DSU {

		private int[] histU;
		private int[] histPu;

		int time;

		int[] p;
		int cntOdd;

		boolean check() {
			return cntOdd == 0;
		}

		boolean union(int v, int u) {
			while (p[v] >= 0) {
				v = p[v];
			}
			while (p[u] >= 0) {
				u = p[u];
			}
			if (v == u) {
				return false;
			}
			if (p[v] > p[u]) {
				int tmp = v;
				v = u;
				u = tmp;
			}
			histU[time] = u;
			histPu[time] = p[u];
			time++;
			if (odd(p[v] & p[u])) {
				cntOdd -= 2;
			}
			p[v] += p[u];
			p[u] = v;
			return check();
		}

		void rollback(int to) {
			while (time > to) {
				--time;
				int u = histU[time];
				int pu = histPu[time];
				int v = p[u];
				p[v] -= pu;
				if (odd(p[v] & pu)) {
					cntOdd += 2;
				}
				p[u] = pu;
			}
		}

		public DSU(int n) {
			p = new int[n];
			Arrays.fill(p, -1);
			histU = new int[n - 1];
			histPu = new int[n - 1];
			cntOdd = n;
		}
	}

	static class Edge implements Comparable<Edge> {
		int v1, v2, len, order, lenRank;

		public Edge(int v1, int v2, int len) {
			this.v1 = v1;
			this.v2 = v2;
			this.len = len;
		}

		@Override
		public int compareTo(Edge o) {
			return Integer.compare(len, o.len);
		}
	}

	Edge[] es, esLen;
	int[] ans;
	
	int n, m;
	
	void go(int l1, int r1, int l2, int r2, DSU dsu) {

		if (r1 - l1 < 1) {
			return;
		}


		int mid = (l1 + r1) >> 1;
		int midAns = r2;

		int state = dsu.time;
		
		for (int i = l1; i <= mid; i++) {
			if (es[i].lenRank < l2) {
				dsu.union(es[i].v1, es[i].v2);
			}
		}

		for (int i = l2; i < r2; i++) {
			if (esLen[i].order <= mid) {
				if (dsu.union(esLen[i].v1, esLen[i].v2)) {
					midAns = i;
					break;
				}
			}
		}

		ans[mid] = midAns;

		dsu.rollback(state);

		if (midAns == r2) {
			for (int i = l1; i < mid; i++) {
				ans[i] = midAns;
			}
		} else {
			for (int i = l2; i < midAns; i++) {
				if (esLen[i].order < l1) {
					dsu.union(esLen[i].v1, esLen[i].v2);
				}
			}
			go(l1, mid, midAns, r2, dsu);
		}

		dsu.rollback(state);

		for (int i = l1; i <= mid; i++) {
			if (es[i].lenRank < l2) {
				dsu.union(es[i].v1, es[i].v2);
			}
		}
		go(mid + 1, r1, l2, Math.min(midAns + 1, m), dsu);

		dsu.rollback(state);
	}

	void solve() throws IOException {
		n = nextInt();
		m = nextInt();

		es = new Edge[m];
		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			int len = nextInt();
			es[i] = new Edge(v1, v2, len);
			es[i].order = i;
		}

		esLen = es.clone();
		Arrays.sort(esLen);

		for (int i = 0; i < m; i++) {
			esLen[i].lenRank = i;
		}

		DSU dsu = new DSU(n);

		ans = new int[m];
		go(0, m, 0, m, dsu);

		for (int i = 0; i < m; i++) {
			out.println(ans[i] == m ? -1 : esLen[ans[i]].len);
		}
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