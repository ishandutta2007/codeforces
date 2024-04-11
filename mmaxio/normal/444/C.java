import java.io.*;
import java.util.*;

public class C_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Node {
		Node left, right;
		long add;
		long sum;
		int l, r;
		int color; // -1 for no color

		public Node(int l, int r) {
			this.l = l;
			this.r = r;
			if (r - l > 1) {
				int mid = (l + r) >> 1;
				left = new Node(l, mid);
				right = new Node(mid, r);
				color = -1;
			} else {
				color = l;
			}
		}

		long getSum() {
			return sum + (r - l) * add;
		}

		void paint(int ql, int qr, int newC) {
			if (l >= qr || ql >= r) {
				return;
			}
			if (color == -1) {
				left.paint(ql, qr, newC);
				right.paint(ql, qr, newC);
				sum = left.getSum() + right.getSum();
				if (ql <= l && r <= qr) {
					color = newC;
				}
				return;
			}
			if (ql <= l && r <= qr) {
				add += Math.abs(color - newC);
				color = newC;
				return;
			}
			left.color = color;
			right.color = color;
			color = -1;
			left.paint(ql, qr, newC);
			right.paint(ql, qr, newC);
			sum = left.getSum() + right.getSum();
		}

		long get(int ql, int qr) {
			if (l >= qr || ql >= r) {
				return 0;
			}
			if (ql <= l && r <= qr) {
				return getSum();
			}
			left.add += add;
			right.add += add;
			add = 0;
			long ret = left.get(ql, qr) + right.get(ql, qr);
			sum = left.getSum() + right.getSum();
			return ret;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int q = nextInt();

		Node root = new Node(0, n);

		while (q-- > 0) {
			int type = nextInt();
			if (type == 1) {
				int l = nextInt() - 1;
				int r = nextInt() - 1;
				int newC = nextInt() - 1;
				root.paint(l, r + 1, newC);
			} else {
				int l = nextInt() - 1;
				int r = nextInt() - 1;
				out.println(root.get(l, r + 1));
			}
		}
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