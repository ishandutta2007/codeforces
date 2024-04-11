import java.io.*;
import java.util.*;

public class D_prior {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final Random rng = new Random(3);

	static class Node {
		int val;
		int size;
		int prior;

		Node left, right;

		public Node(int val, Node left, Node right) {
			this.val = val;
			this.left = left;
			this.right = right;
			this.prior = rng.nextInt();
			updateInfo();
		}

		Node updateInfo() {
			size = 1 + getSize(left) + getSize(right);
			return this;
		}

		static int getSize(Node v) {
			return v == null ? 0 : v.size;
		}

		static Node merge(Node left, Node right) {
			if (left == null)
				return right;
			if (right == null)
				return left;
			Node ret;
			if (left.prior < right.prior) {
				left.right = merge(left.right, right);
				ret = left;
			} else {
				right.left = merge(left, right.left);
				ret = right;
			}
			return ret.updateInfo();
		}

		static Node[] getRemove(Node v, int ind) {
//			System.err.println(getSize(v) + " " + ind);
//			System.err.println(getSize(v.left) + " " + getSize(v.right));
//			System.err.println("-----------");
			if (ind == getSize(v.left)) {
				return new Node[] { merge(v.left, v.right), v };
			}
			Node[] tmp;
			if (ind < getSize(v.left)) {
				tmp = getRemove(v.left, ind);
				v.left = tmp[0];
			} else {
				tmp = getRemove(v.right, ind - getSize(v.left) - 1);
				v.right = tmp[0];
			}
			tmp[0] = v.updateInfo();
			return tmp;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int q = nextInt();
		Node root = null;
		for (int i = 0; i < n; i++) {
			root = Node.merge(root, new Node(i, null, null));
		}

		boolean[] taken = new boolean[n];
		int[] ans = new int[n];
		Arrays.fill(ans, -1);
		while (q-- > 0) {
			int val = nextInt() - 1;
			int pos = nextInt() - 1;
			
			// System.err.println(Node.getSize(root) + " " + pos);
			
			Node[] tmp = Node.getRemove(root, pos);
			int num = tmp[1].val;
			if (ans[num] != -1) {
				if (ans[num] != val) {
					out.println(-1);
					return;
				}
			} else {
				if (taken[val]) {
					out.println(-1);
					return;
				}
				ans[num] = val;
				taken[val] = true;
			}

			tmp[1].left = tmp[1].right = null;
			tmp[1].updateInfo();
			root = Node.merge(tmp[1], tmp[0]);
		}

		// System.err.println(Arrays.toString(ans));
		// System.err.println(Arrays.toString(taken));

		for (int i = 0, j = 0; i < n; i++) {
			if (ans[i] == -1) {
				while (taken[j]) {
					j++;
				}
				ans[i] = j;
				taken[j] = true;
			}
		}

		for (int i = 0; i < n; i++) {
			out.print((ans[i] + 1) + " ");
		}
		out.println();
	}

	D_prior() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D_prior();
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