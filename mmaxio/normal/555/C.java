import java.io.*;
import java.util.*;

public class C_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Node {
		int l, r;
		Node left, right;

		int val;

		public Node(int l, int r) {
			this.l = l;
			this.r = r;
			if (r - l > 1) {
				int mid = (l + r) >> 1;
				left = new Node(l, mid);
				right = new Node(mid, r);
			}
		}

		void set(int ql, int qr, int newVal) {
			if (ql >= r || l >= qr) {
				return;
			}
			if (ql <= l && r <= qr) {
				val = Math.max(val, newVal);
				return;
			}
			left.set(ql, qr, newVal);
			right.set(ql, qr, newVal);
		}

		int get(int pos) {
			if (l == pos && pos + 1 == r) {
				return val;
			}
			int ret = (pos < left.r ? left : right).get(pos);
			return Math.max(ret, val);
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int q = nextInt();
		int[] xs = new int[q];
		char[] type = new char[q];
		for (int i = 0; i < q; i++) {
			nextInt();
			xs[i] = nextInt();
			type[i] = nextToken().charAt(0);
		}
		int[] tmp = Arrays.copyOf(xs, xs.length + 2);
		tmp[xs.length] = 0;
		tmp[xs.length + 1] = n + 1;
		int[] u = unique(tmp);
		for (int i = 0; i < q; i++) {
			xs[i] = Arrays.binarySearch(u, xs[i]);
		}

		int m = u.length;

		Node rootL = new Node(0, m);
		Node rootU = new Node(0, m);

		boolean[] eatL = new boolean[m];
		boolean[] eatU = new boolean[m];

		outer: for (int i = 0; i < q; i++) {
			int pos = xs[i];
			if (type[i] == 'U') {
				if (eatU[pos]) {
					out.println(0);
					continue outer;
				}
				eatU[pos] = true;
				int to = rootU.get(pos);
				out.println(u[pos] - u[to]);
				rootL.set(to + 1, pos + 1, m - 1 - pos);
			} else {
				if (eatL[pos]) {
					out.println(0);
					continue outer;
				}
				eatL[pos] = true;
				int to = m - 1 - rootL.get(pos);
//				System.err.println(pos + " " + to);
				out.println(u[to] - u[pos]);
				rootU.set(pos, to, pos);
				
			}
		}
	}

	int[] unique(int[] a) {
		Random rng = new Random();
		int n = a.length;
		for (int i = 0; i < n; i++) {
			int j = rng.nextInt(i + 1);
			int tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
		}
		Arrays.sort(a);
		int sz = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] != a[sz - 1]) {
				a[sz++] = a[i];
			}
		}
		return Arrays.copyOf(a, sz);
	}

	C_new() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C_new();
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