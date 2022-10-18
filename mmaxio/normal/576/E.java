import java.io.*;
import java.util.*;

public class E_lowmem {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	DSU[] dsus;
	int[] idxs;
	int[] vals;
	int ptr;

	void set(DSU dsu, int idx, int val) {
		if (dsu.p[idx] != val) {
			dsus[ptr] = dsu;
			idxs[ptr] = idx;
			vals[ptr] = dsu.p[idx];
			dsu.p[idx] = val;
			ptr++;
		}
	}

	void rollback(int time) {
		while (ptr > time) {
			DSU dsu = dsus[ptr - 1];
			int idx = idxs[ptr - 1];
			int val = vals[ptr - 1];
			dsu.p[idx] = val;
			ptr--;
		}
	}

	class DSU {
		int[] p;

		public DSU(int n) {
			p = new int[n];
			Arrays.fill(p, -1);
		}

		int get(int v) {
			int ret = 0;
			while (p[v] >= 0) {
				ret ^= p[v];
				v = p[v] >> 1;
			}
			return (v << 1) | (ret & 1);
		}

		boolean unite(int v, int u) {
			v = get(v);
			u = get(u);

			int diff = (v ^ u) & 1;
			v >>= 1;
			u >>= 1;

			if (v == u) {
				return diff == 1;
			}
			if (p[v] < p[u]) {
				int tmp = v;
				v = u;
				u = tmp;
			}
			set(this, u, p[v] + p[u]);
			set(this, v, (u << 1) | (diff ^ 1));
			return true;
		}
	}

	DSU[] g;

	int[] v1, v2, curC;

	int[] qEdge, qCol;

	int[] mark;
	int markVer;

	void prepare(int l0, int r0, int l1, int r1) {
		markVer++;
		for (int i = l0; i < r0; i++) {
			mark[qEdge[i]] = markVer;
		}
		for (int i = l1; i < r1; i++) {
			int edge = qEdge[i];
			if (mark[edge] != markVer) {
				mark[edge] = markVer;
				if (curC[edge] != -1) {
					g[curC[edge]].unite(v1[edge], v2[edge]);
				}
			}
		}
	}

	void go(int l, int r) {
		if (r - l == 1) {
			int edge = qEdge[l];
			if (g[qCol[l]].unite(v1[edge], v2[edge])) {
				curC[edge] = qCol[l];
				out.println("YES");
			} else {
				out.println("NO");
			}
			return;
		}
		int time = ptr;
		int mid = (l + r) >> 1;
		prepare(l, mid, mid, r);
		go(l, mid);
		rollback(time);
		prepare(mid, r, l, mid);
		go(mid, r);
		rollback(time);
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		int q = nextInt();
		g = new DSU[k];
		for (int i = 0; i < k; i++) {
			g[i] = new DSU(n);
		}

		v1 = new int[m];
		v2 = new int[m];
		curC = new int[m];
		Arrays.fill(curC, -1);
		for (int i = 0; i < m; i++) {
			v1[i] = nextInt() - 1;
			v2[i] = nextInt() - 1;
		}

		qEdge = new int[q];
		qCol = new int[q];
		for (int i = 0; i < q; i++) {
			qEdge[i] = nextInt() - 1;
			qCol[i] = nextInt() - 1;
		}

		mark = new int[m];
		dsus = new DSU[q << 1];
		idxs = new int[q << 1];
		vals = new int[q << 1];
		go(0, q);

	}

	E_lowmem() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E_lowmem();
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