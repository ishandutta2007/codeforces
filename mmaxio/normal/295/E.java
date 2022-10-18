import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final Random rng = new Random();

	static class Node {
		Node l, r;
		int value;
		int size;

		long sum, sumDiff;

		static int getSize(Node v) {
			return v == null ? 0 : v.size;
		}

		static long getSum(Node v) {
			return v == null ? 0 : v.sum;
		}

		static long getSumDiff(Node v) {
			return v == null ? 0 : v.sumDiff;
		}

		Node makeInfo() {
			size = 1 + getSize(l) + getSize(r);
			sum = value + getSum(l) + getSum(r);
			sumDiff = getSumDiff(l) + getSumDiff(r) - getSum(l)
					* (1 + getSize(r)) + getSum(r) * (1 + getSize(l))
					+ (long) value * (getSize(l) - getSize(r));
			return this;
		}
		
		@Override
		public String toString() {
			String ret = "";
			if (l != null)
				ret += "(" + l.toString() + ") ";
			ret += value + ", " + size + ", " + sum + ", " + sumDiff;
			if (r != null)
				ret += " (" + r.toString() + ")";
			return ret;
		}

		static Node merge(Node left, Node right) {
			if (left == null)
				return right;
			if (right == null)
				return left;
			Node res;
			if (rng.nextInt(getSize(left) + getSize(right)) < getSize(left)) {
				res = left;
				res.r = merge(left.r, right);
			} else {
				res = right;
				res.l = merge(left, right.l);
			}
			return res.makeInfo();
		}

		static Node[] split(Node v, int mid) {
			if (v == null)
				return new Node[2];
			Node[] res;
			if (v.value <= mid) {
				res = split(v.r, mid);
				v.r = res[0];
				res[0] = v;
			} else {
				res = split(v.l, mid);
				v.l = res[1];
				res[1] = v;
			}
			v.makeInfo();
			return res;
		}

		static Node erase(Node v, int val) {
			if (v == null)
				return null;
			if (v.value == val) {
				return merge(v.l, v.r);
			}
			if (v.value < val) {
				v.r = erase(v.r, val);
			} else {
				v.l = erase(v.l, val);
			}
			return v.makeInfo();
		}

		public Node(int value, Node l, Node r) {
			this.value = value;
			this.l = l;
			this.r = r;
			this.makeInfo();
		}

		static Node insert(Node v, int val) {
			if (rng.nextInt(1 + getSize(v)) == 0) {
				Node[] tmp = split(v, val);
				return new Node(val, tmp[0], tmp[1]);
			}
			if (v.value <= val)
				v.r = insert(v.r, val);
			else
				v.l = insert(v.l, val);
			return v.makeInfo();
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] x = new int[n];

		Node root = null;

		for (int i = 0; i < n; i++) {
			x[i] = nextInt();
			root = Node.insert(root, x[i]);
		}
		
//		System.err.println(root);

		int q = nextInt();
		while (q-- > 0) {
			int type = nextInt();
			if (type == 1) {
				int i = nextInt() - 1;
				int delta = nextInt();
				root = Node.erase(root, x[i]);
				x[i] += delta;
				root = Node.insert(root, x[i]);
			} else {
				int low = nextInt();
				int high = nextInt();
				Node[] tmp0 = Node.split(root, low - 1);
				Node[] tmp1 = Node.split(tmp0[1], high);
				out.println(Node.getSumDiff(tmp1[0]));
//				System.err.println(tmp1[0]);
				root = Node.merge(tmp0[0], Node.merge(tmp1[0], tmp1[1]));
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