import java.io.*;
import java.util.*;

public class H {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] fib;
	int m;

	static class Query implements Comparable<Query> {
		int l, r, lBlock, id;

		@Override
		public int compareTo(Query o) {
			if (lBlock != o.lBlock) {
				return lBlock < o.lBlock ? -1 : 1;
			}
			return (1 - lBlock % 2 * 2) * Integer.compare(r, o.r);
		}

		public Query(int l, int r, int lBlock, int id) {
			this.l = l;
			this.r = r;
			this.lBlock = lBlock;
			this.id = id;
		}
	}

	class Node {
		int l, r;
		Node left, right;

		int sum0, sum1, cnt;

		public Node(int l, int r) {
			this.l = l;
			this.r = r;
			if (r - l > 1) {
				int mid = (l + r) >> 1;
				left = new Node(l, mid);
				right = new Node(mid, r);
			}
		}

		int getShifted(int shift) {
			return (fib[shift] * sum0 + fib[shift + 1] * sum1) % m;
		}

		void set(int pos, int val) { // val = -1 to unset
			if (r - l == 1 && pos == l) {
				sum0 = sum1 = val == -1 ? 0 : val % m;
				cnt = val == -1 ? 0 : 1;
				return;
			}
			(pos < left.r ? left : right).set(pos, val);
			cnt = left.cnt + right.cnt;
			sum0 = (left.sum0 + right.getShifted(left.cnt)) % m;
			sum1 = (left.sum1 + right.getShifted(left.cnt + 1)) % m;
		}

	}
	
	int[] b;
	int[] cnt;
	
	Node root;
	
	void update(int x, int delta) {
		cnt[x] += delta;
		if (cnt[x] == 1 && delta == 1) {
			root.set(x, b[x]);
		} 
		if (cnt[x] == 0 && delta == -1) {
			root.set(x, -1);
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		m = nextInt();

		fib = new int[n + 2];
		fib[0] = 1 % m;
		fib[1] = 0;
		for (int i = 2; i < n + 2; i++) {
			fib[i] = (fib[i - 1] + fib[i - 2]) % m;
		}

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		b = unique(a.clone());
		
		for (int i = 0; i < n; i++) {
			a[i] = Arrays.binarySearch(b, a[i]);
		}
		
		cnt = new int[b.length];

		int qq = nextInt();
		int k = (int) Math.sqrt(n);

		Query[] qs = new Query[qq];
		for (int i = 0; i < qq; i++) {
			int l = nextInt() - 1;
			int r = nextInt();
			qs[i] = new Query(l, r, l / k, i);
		}

		root = new Node(0, b.length);

		Arrays.sort(qs);
		int[] ans = new int[qq];
		int l = 0, r = 0;
		for (Query q : qs) {
			while (l > q.l) {
				update(a[--l], 1);
			}

			while (r < q.r) {
				update(a[r++], 1);
			}

			while (l < q.l) {
				update(a[l++], -1);
			}

			while (r > q.r) {
				update(a[--r], -1);
			}

			ans[q.id] = root.sum0;
		}

		for (int x : ans) {
			out.println(x);
		}
	}

	int[] unique(int[] a) {
		Arrays.sort(a);
		int sz = 1;
		for (int i = 1; i < a.length; i++) {
			if (a[i] != a[sz - 1]) {
				a[sz++] = a[i];
			}
		}
		return Arrays.copyOf(a, sz);
	}

	H() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new H();
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