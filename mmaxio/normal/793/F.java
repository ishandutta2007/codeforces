import java.io.*;
import java.util.*;

public class E {

	static final int INF = Integer.MAX_VALUE / 3;

	static class Node {
		int l, r;
		Node left, right;

		int setMin;
		int max;

		public Node(int l, int r) {
			this.l = l;
			this.r = r;

			setMin = max = INF;
			if (r - l > 1) {
				int m = (l + r) >> 1;
				left = new Node(l, m);
				right = new Node(m, r);
			}
		}

		void pushDown() {
			left.setMin = Math.min(left.setMin, setMin);
			right.setMin = Math.min(right.setMin, setMin);
			setMin = INF;
		}

		int getMax() {
			return Math.min(setMin, max);
		}

		void setMin(int ql, int qr, int val) {
			if (l >= qr || ql >= r) {
				return;
			}
			if (ql <= l && r <= qr) {
				setMin = Math.min(setMin, val);
				return;
			}
			pushDown();
			left.setMin(ql, qr, val);
			right.setMin(ql, qr, val);
			max = Math.max(left.getMax(), right.getMax());
		}

		int getNextMore(int pos, int moreThan) {
			if (r <= pos) {
				return -1;
			}
			if (getMax() <= moreThan) {
				return -1;
			}
			if (r - l == 1) {
				return l;
			}
			pushDown();
			int ret;
			int tmp = left.getNextMore(pos, moreThan);
			if (tmp != -1) {
				ret = tmp;
			} else {
				ret = right.getNextMore(pos, moreThan);
			}
			max = Math.max(left.getMax(), right.getMax());
			return ret;
		}

	}

	void submit() {
		int n = nextInt();
		int m = nextInt();

		int[] headRope = new int[n];
		int[] nextRope = new int[m];
		int[] upRope = new int[m];
		Arrays.fill(headRope, -1);

		for (int i = 0; i < m; i++) {
			int from = nextInt() - 1;
			int to = nextInt() - 1;
			upRope[i] = to;
			nextRope[i] = headRope[from];
			headRope[from] = i;
		}

		int q = nextInt();
		int[] headQ = new int[n];
		int[] nextQ = new int[q];
		int[] upQ = new int[q];
		Arrays.fill(headQ, -1);

		for (int i = 0; i < q; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			nextQ[i] = headQ[x];
			upQ[i] = y;
			headQ[x] = i;
		}

		Node root = new Node(0, n);

		int[] ans = new int[q];

		for (int i = n - 1; i >= 0; i--) {

			for (int e = headRope[i]; e >= 0; e = nextRope[e]) {
				int up = upRope[e];
				if (up != i) {
					root.setMin(i, up, up);
				}
			}
			
			for (int e = headQ[i]; e >= 0; e = nextQ[e]) {
				int up = upQ[e];
				ans[e] = root.getNextMore(i, up) + 1;
			}

		}
		for (int x : ans) {
			out.println(x);
		}
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	public static void main(String[] args) throws IOException {
		new E();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}