import java.io.*;
import java.util.*;

public class D {

	static class Node {
		int l, r;
		Node left, right;

		int delta;
		int min, cnt;

		public Node(int l, int r) {
			this.l = l;
			this.r = r;
			min = delta = 0;
			cnt = r - l;
			if (r - l > 1) {
				int m = (l + r) >> 1;
				left = new Node(l, m);
				right = new Node(m, r);
			}
		}

		int getMin() {
			return min + delta;
		}

		void combine() {
			int lMin = left.getMin();
			int rMin = right.getMin();
			min = Math.min(lMin, rMin);
			cnt = (min == lMin ? left.cnt : 0) + (min == rMin ? right.cnt : 0);
		}

		void add(int ql, int qr, int qDelta) {
			if (l >= qr || ql >= r) {
				return;
			}
			if (ql <= l && r <= qr) {
				delta += qDelta;
				return;
			}
			left.add(ql, qr, qDelta);
			right.add(ql, qr, qDelta);
			combine();
		}
	}

	void submit() {
		int n = nextInt();
		int[] a = new int[n];

		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		SparseTable st = new SparseTable(a);

		int[] upTo = new int[n];
		for (int i = 0; i < n; i++) {
			upTo[i] = i;
		}

		int[] head = new int[n + 1];
		Arrays.fill(head, -1);
		int[] next = new int[2 * n];
		Event[] key = new Event[2 * n];

		for (int i = 0; i < n; i++) {
			int left = -1;
			int right = i;
			while (right - left > 1) {
				int mid = (left + right) >> 1;
				int get = st.get(mid, i + 1);
				if (get == a[i]) {
					right = mid;
				} else {
					left = mid;
				}
			}

			int from = right;

			left = i;
			right = n;
			while (right - left > 1) {
				int mid = (left + right) >> 1;
				int get = st.get(i, mid + 1);
				if (get == a[i]) {
					left = mid;
				} else {
					right = mid;
				}
			}

			int to = left;

			key[2 * i] = new Event(i, to, 1);
			next[2 * i] = head[from];
			head[from] = 2 * i;

			key[2 * i + 1] = new Event(i, to, -1);
			next[2 * i + 1] = head[i + 1];
			head[i + 1] = 2 * i + 1;
		}
		
		long ans = 0;
		
		Node root = new Node(0, n);
		for (int i = 0; i < n; i++) {
			for (int e = head[i]; e >= 0; e = next[e]) {
				Event ev = key[e];
				root.add(ev.l, ev.r + 1, ev.delta);
			}
			root.add(i, i + 1, 1);
			
			if (root.getMin() == 0) {
				ans += root.cnt;
			}
		}
		
		out.println(ans);
	}

	static class Event {
		int l, r, delta;

		public Event(int l, int r, int delta) {
			this.l = l;
			this.r = r;
			this.delta = delta;
		}
	}

	static class SparseTable {

		private int getLog(int len) {
			return len <= 2 ? 0 : 31 - Integer.numberOfLeadingZeros(len - 1);
		}

		private/* 1 */int[][] d;

		public SparseTable(/* 1 */int[] a) {
			int n = getLog(a.length);
			d = new /* 1 */int[n + 1][];
			d[0] = a.clone();
			for (int i = 1; i <= n; i++) {
				d[i] = new /* 1 */int[a.length - (1 << i) + 1];
				for (int j = 0; j < d[i].length; j++) {
					d[i][j] = d[i - 1][j] | d[i - 1][j + (1 << (i - 1))];
				}
			}
		}

		public/* 1 */int get(int l, int r) {
			int i = getLog(r - l);
			return d[i][l] | d[i][r - (1 << i)];
		}

	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new D();
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