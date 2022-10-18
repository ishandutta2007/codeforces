import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Node {
		int l, r;
		Node left, right;

		int val; // -1 for no value

		public Node(int l, int r) {
			val = -1;
			this.l = l;
			this.r = r;
			if (l + 1 != r) {
				int mid = (l + r) >> 1;
				left = new Node(l, mid);
				right = new Node(mid, r);
			}
		}

		void set(int ql, int qr, int val) {
			if (ql >= r || l >= qr) {
				return;
			}
			if (ql <= l && r <= qr) {
				this.val = val;
				return;
			}

			if (this.val != -1) {
				left.val = this.val;
				right.val = this.val;
				this.val = -1;
			}

			left.set(ql, qr, val);
			right.set(ql, qr, val);
		}

		void writeToArray(int[] a) {
			if (l + 1 == r) {
				a[l] = val + 1;
				return;
			}
			if (val != -1) {
				left.val = val;
				right.val = val;
			}
			left.writeToArray(a);
			right.writeToArray(a);
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		Node a = new Node(0, n);
		int[] l = new int[m];
		int[] r = new int[m];
		int[] win = new int[m];

		for (int i = 0; i < m; i++) {
			l[i] = nextInt() - 1;
			r[i] = nextInt() - 1 + 1;
			win[i] = nextInt() - 1;
		}

		for (int i = m - 1; i >= 0; i--) {
			if (l[i] < win[i]) {
				a.set(l[i], win[i], win[i]);
			}
			if (win[i] + 1 < r[i]) {
				a.set(win[i] + 1, r[i], win[i]);
			}
		}

		int[] ans = new int[n];
		a.writeToArray(ans);

		for (int i = 0; i < n; i++) {
			out.print(ans[i] + " ");
		}
		out.println();
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
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