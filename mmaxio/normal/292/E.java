import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	class Node {
		int l, r;
		Node left, right;

		int aInd;

		public Node(int l, int r) {
			this.l = l;
			this.r = r;
			aInd = -1;
			if (r - l > 1) {
				int mid = (l + r) >> 1;
				left = new Node(l, mid);
				right = new Node(mid, r);
			}
		}

		void set(int aSt, int l, int r) {
			// System.err.println(aSt + " " + l + " " + r + " in [" + this.l +
			// "; " + this.r + ")");
			if (l <= this.l && this.r <= r) {
				aInd = aSt + (this.l - l);
				return;
			}
			if (this.r <= l || r <= this.l) {
//				System.err.println(aSt + " " + l + " " + r + " in [" + this.l
//						+ "; " + this.r + ")");
				return;
			}
			if (aInd != -1) {
				left.aInd = aInd;
				right.aInd = aInd + (left.r - left.l);
				aInd = -1;
			}
			left.set(aSt, l, r);
			right.set(aSt, l, r);
		}

		int go(int pos) {
//			System.err.println(l + " " + r + " " + pos + " " + aInd);
			if (r - l == 1)
				return aInd;
			if (aInd != -1)
				return aInd + (pos - l);
			return (pos < left.r ? left : right).go(pos);
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		for (int i = 0; i < n; i++) {
			b[i] = nextInt();
		}

		Node root = new Node(0, n);

		for (int i = 0; i < m; i++) {
			int type = nextInt();
			if (type == 1) {
				int aSt = nextInt() - 1;
				int bSt = nextInt() - 1;
				int len = nextInt();
				root.set(aSt, bSt, bSt + len);
			} else {
				int pos = nextInt() - 1;
				int res = root.go(pos);
				if (res == -1)
					out.println(b[pos]);
				else
					out.println(a[res]);
			}
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