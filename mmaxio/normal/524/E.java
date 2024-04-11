import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Rook {
		int x, y;

		public Rook(int x, int y) {
			this.x = x;
			this.y = y;
		}

		static Comparator<Rook> byX = (Rook a, Rook b) -> {
			return Integer.compare(a.x, b.x);
		};
	}

	static class Query {
		int x1, y1, x2, y2, id;

		public Query(int x1, int y1, int x2, int y2, int id) {
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
			this.id = id;
		}

		static Comparator<Query> byX2 = (Query a, Query b) -> {
			return Integer.compare(a.x2, b.x2);
		};
	}

	static class Node {
		int l, r;
		Node left, right;
		int min;

		public Node(int l, int r) {
			this.l = l;
			this.r = r;
			min = -1;
			if (r - l > 1) {
				int mid = (l + r) >> 1;
				left = new Node(l, mid);
				right = new Node(mid, r);
			}
		}

		void set(int pos, int x) {
			if (l == pos && pos + 1 == r) {
				min = x;
				return;
			}
			(pos < left.r ? left : right).set(pos, x);
			min = Math.min(left.min, right.min);
		}

		int get(int ql, int qr) {
			if (ql >= r || l >= qr) {
				return Integer.MAX_VALUE;
			}
			if (ql <= l && r <= qr) {
				return min;
			}
			return Math.min(left.get(ql, qr), right.get(ql, qr));
		}

	}

	boolean[] go(Rook[] rs, Query[] qs, int size) {
		Node root = new Node(0, size);
		boolean[] ret = new boolean[qs.length];
		for (int i = 0, j = 0; i < qs.length; i++) {
			while (j < rs.length && rs[j].x <= qs[i].x2) {
				root.set(rs[j].y, rs[j].x);
				j++;
			}
			int val = root.get(qs[i].y1, qs[i].y2 + 1);
			ret[qs[i].id] = val >= qs[i].x1;
		}
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		int q = nextInt();
		Rook[] rx = new Rook[k];
		Rook[] ry = new Rook[k];
		for (int i = 0; i < k; i++) {
			int x1 = nextInt() - 1;
			int y1 = nextInt() - 1;
			rx[i] = new Rook(x1, y1);
			ry[i] = new Rook(y1, x1);
		}
		Arrays.sort(rx, Rook.byX);
		Arrays.sort(ry, Rook.byX);

		Query[] qx = new Query[q];
		Query[] qy = new Query[q];
		for (int i = 0; i < q; i++) {
			int x1 = nextInt() - 1;
			int y1 = nextInt() - 1;
			int x2 = nextInt() - 1;
			int y2 = nextInt() - 1;
			qx[i] = new Query(x1, y1, x2, y2, i);
			qy[i] = new Query(y1, x1, y2, x2, i);
		}
		Arrays.sort(qx, Query.byX2);
		Arrays.sort(qy, Query.byX2);

		boolean[] ansX = go(rx, qx, m);
		boolean[] ansY = go(ry, qy, n);

		for (int i = 0; i < q; i++) {
			out.println(ansX[i] || ansY[i] ? "YES" : "NO");
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