import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final Random rng = new Random();

	static class Node {
		int size;
		int val;
		Node l, r;
		boolean rev;
		int sum;

		Node(int val) {
			this.val = val;
			makeInfo();
		}

		static int getSize(Node v) {
			return v == null ? 0 : v.size;
		}

		static void flipRev(Node v) {
			if (v == null) {
				return;
			}
			v.rev = !v.rev;
		}

		static int getSum(Node v) {
			return v == null ? 0 : v.sum;
		}

		void pushDown() {
			if (rev) {
				flipRev(l);
				flipRev(r);
				Node tmp1 = l;
				l = r;
				r = tmp1;
				rev = false;
			}
		}

		void makeInfo() {
			size = 1 + getSize(l) + getSize(r);
			sum = val + getSum(l) + getSum(r);
		}

		static Node merge(Node left, Node right) {
			if (left == null) {
				return right;
			}
			if (right == null) {
				return left;
			}
			Node res;
			if (rng.nextInt(getSize(left) + getSize(right)) < getSize(left)) {
				left.pushDown();
				res = left;
				left.r = merge(left.r, right);
			} else {
				right.pushDown();
				res = right;
				right.l = merge(left, right.l);
			}
			res.makeInfo();
			return res;
		}

		static Node[] split(Node v, int leftSize) {
			if (leftSize == 0) {
				return new Node[] { null, v };
			}
			if (leftSize == getSize(v)) {
				return new Node[] { v, null };
			}
			v.pushDown();
			Node[] ret;
			if (leftSize <= getSize(v.l)) {
				ret = split(v.l, leftSize);
				v.l = ret[1];
				ret[1] = v;
			} else {
				ret = split(v.r, leftSize - 1 - getSize(v.l));
				v.r = ret[0];
				ret[0] = v;
			}
			v.makeInfo();
			return ret;
		}

		static void writeToArray(Node v, Node[] arr, int off) {
			if (v == null) {
				return;
			}
			v.pushDown();
			arr[off + getSize(v.l)] = v;
			writeToArray(v.l, arr, off);
			writeToArray(v.r, arr, off + getSize(v.l) + 1);
		}
	}

	void solve() throws IOException {
		int curW = nextInt();
		int q = nextInt();

		Node root = null;
		for (int i = 0; i < curW; i++) {
			root = Node.merge(root, new Node(1));
		}

		while (q-- > 0) {
			int type = nextInt();
			if (type == 1) {
				int w = nextInt();
				if (w > curW - w) {
					Node.flipRev(root);
					w = curW - w;
				}
				Node[] a = Node.split(root, w);
				curW -= w;
				Node[] b = Node.split(a[1], w);
				Node.flipRev(a[0]);

				Node[] k1 = new Node[w];
				Node[] k2 = new Node[w];
				Node.writeToArray(a[0], k1, 0);
				Node.writeToArray(b[0], k2, 0);
				for (int i = 0; i < w; i++) {
					k2[i].val += k1[i].val;
					k2[i].l = k2[i].r = null;
					k2[i].makeInfo();
				}
				root = b[1];
				for (int i = w - 1; i >= 0; i--) {
					root = Node.merge(k2[i], root);
				}
			} else {
				int l = nextInt();
				int r = nextInt();
				Node[] a = Node.split(root, r);
				Node[] b = Node.split(a[0], l);
//				if (l == 1 && r == 3) {
//					Node[] tmp = new Node[b[1].size];
//					write
//				}
				out.println(Node.getSum(b[1]));
				root = Node.merge(Node.merge(b[0], b[1]), a[1]);
			}
		}

	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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