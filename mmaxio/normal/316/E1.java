import java.io.*;
import java.util.*;

public class cfABBYYCup3E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int MOD = 1_000_000_000;

	int[] fib;

	class Node {
		int l, r;
		Node left, right;
		int add;
		int sum0, sum1;

		public Node(int l, int r, int[] a) {
			this.l = l;
			this.r = r;
			if (r - l == 1) {
				sum0 = sum1 = a[l];
			} else {
				int mid = (l + r) >> 1;
				left = new Node(l, mid, a);
				right = new Node(mid, r, a);
				update();
			}
//			System.err.println(l + " " + r + " -> " + sum0 + " " + sum1);
		}

		void pushDown() {
			left.add += add;
			if (left.add >= MOD)
				left.add -= MOD;
			right.add += add;
			if (right.add >= MOD)
				right.add -= MOD;
			add = 0;
		}

		void update() {
			sum0 = left.getValue(l) + right.getValue(l);
			if (sum0 >= MOD)
				sum0 -= MOD;
			sum1 = left.getValue(l - 1) + right.getValue(l - 1);
			if (sum1 >= MOD)
				sum1 -= MOD;
		}

		int getValue(int qL) {

			int shift = l - qL;
			int res = (int) (((long) sum0 * fib[shift] + (long) sum1
					* fib[shift + 1]) % MOD);
//			System.err.println(l + " " + r + " " + qL);
//			System.err.println(sum0 + " " + fib[shift] + " " + sum1 + " " + fib[shift + 1]);
//			System.err.println();
			if (res >= MOD)
				res -= MOD;
			res += (int) ((long) add * fibSum(shift, shift + r - l));
			if (res >= MOD)
				res -= MOD;
			return res;
		}

		void set(int pos, int newVal) {
			if (l == pos && pos + 1 == r) {
				add = 0;
				sum0 = sum1 = newVal;
			} else {
				pushDown();
				(pos < left.r ? left : right).set(pos, newVal);
				update();
			}
		}

		int get(int qL, int qR) {
			if (qL <= l && r <= qR) {
				return getValue(qL);
			}
			if (qL >= r || l >= qR)
				return 0;
			pushDown();
			int ret = left.get(qL, qR) + right.get(qL, qR);
			if (ret >= MOD)
				ret -= MOD;
			update();
			return ret;
		}

		void add(int qL, int qR, int delta) {
			if (qL <= l && r <= qR) {
				add += delta;
				if (add >= MOD)
					add -= delta;
				return;
			}
			if (qL >= r || l >= qR)
				return;
			left.add(qL, qR, delta);
			right.add(qL, qR, delta);
			update();
		}

	}

	int[] fibSum;

	int fibSum(int l, int r) {
		int ret = fibSum[r] - fibSum[l];
		if (ret < 0)
			ret += MOD;
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();

		fib = new int[n + 3];
		fib[0] = 1;
		fib[1] = 0;
		for (int i = 2; i < n + 3; i++) {
			fib[i] = fib[i - 1] + fib[i - 2];
			if (fib[i] >= MOD)
				fib[i] -= MOD;
		}

		fibSum = new int[n + 2];
		for (int i = 0; i < n + 1; i++) {
			fibSum[i + 1] = fibSum[i] + fib[i + 2];
			if (fibSum[i + 1] >= MOD)
				fibSum[i + 1] -= MOD;
		}

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		Node root = new Node(0, n, a);

		while (m-- > 0) {
			int type = nextInt();
			switch (type) {
			case 1: {
				int pos = nextInt() - 1;
				int newVal = nextInt();
				root.set(pos, newVal);
				break;
			}
			case 2: {
				int left = nextInt() - 1;
				int right = nextInt() - 1;
				out.println(root.get(left, right + 1));
				break;
			}
			case 3: {
				int left = nextInt() - 1;
				int right = nextInt() - 1;
				int add = nextInt();
				root.add(left, right + 1, add);
				break;
			}
			default:
				throw new AssertionError();
			}
		}

	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new cfABBYYCup3E().inp();
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