import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Node {
		int l, r;
		Node left, right;

		int val;
		int type;

		static int makeType(int len) {
			return (Integer.numberOfTrailingZeros(len) & 1) ^ 1;
		}

		public Node(int l, int r, int[] init) {
			this.l = l;
			this.r = r;
			type = makeType(r - l);
			if (r - l == 1) {
				val = init[l];
			} else {
				int mid = (l + r) >> 1;
				left = new Node(l, mid, init);
				right = new Node(mid, r, init);
				calcVal();
			}
		}

		void calcVal() {
			val = type == 0 ? (left.val | right.val) : (left.val ^ right.val);
		}
		
		void set(int pos, int val) {
			if (l == pos && pos == r - 1) {
				this.val = val;
				return;
			}
			(pos < left.r ? left : right).set(pos, val);
			calcVal();
		}

	}

	void solve() throws IOException {
		int n = 1 << nextInt();
		int m = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		
		Node root = new Node(0, n, a);
		for (int i = 0; i < m; i++) {
			int pos = nextInt() - 1;
			int val = nextInt();
			root.set(pos, val);
			out.println(root.val);
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