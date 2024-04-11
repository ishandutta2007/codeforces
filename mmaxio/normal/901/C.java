import java.io.*;
import java.util.*;

public class C {

	int[] head;
	int[] to;
	int[] next;

	int[] vis;
	int[] path;
	int sz = 0;

	List<Integer> bad = new ArrayList<>();

	void dfs(int v, int p) {
		vis[v] = 1;
		path[sz++] = v;

		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			if (u == p) {
				continue;
			}
			if (vis[u] == 1) {
				int min = u, max = u;
				for (int i = sz - 1; path[i] != u; i--) {
					min = Math.min(min, path[i]);
					max = Math.max(max, path[i]);
				}
				bad.add(min);
				bad.add(max);
			} else if (vis[u] == 0) {
				dfs(u, v);
			}
		}
		sz--;
		vis[v] = 2;
	}

	void submit() {
		int n = nextInt();
		int m = nextInt();

		head = new int[n];
		Arrays.fill(head, -1);
		to = new int[2 * m];
		next = new int[2 * m];

		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;

			to[2 * i] = u;
			next[2 * i] = head[v];
			head[v] = 2 * i;

			to[2 * i + 1] = v;
			next[2 * i + 1] = head[u];
			head[u] = 2 * i + 1;
		}

		vis = new int[n];
		path = new int[n];
		for (int i = 0; i < n; i++) {
			if (vis[i] == 0) {
				dfs(i, -1);
			}
		}

		int[] markFrom = new int[n + 1];
		Arrays.fill(markFrom, Integer.MAX_VALUE);
		for (int i = 0; i < bad.size(); i += 2) {
			int from = bad.get(i);
			int to = bad.get(i + 1);
			markFrom[from] = Math.min(markFrom[from], to);
		}

		for (int i = n - 1; i >= 0; i--) {
			markFrom[i] = Math.min(markFrom[i], markFrom[i + 1]);
		}

		int q = nextInt();

		Query[] qs = new Query[2 * q];

		for (int i = 0; i < q; i++) {
			int x = nextInt() - 1;
			int y = nextInt();
			qs[2 * i] = new Query(x, x, y, -1, i);
			qs[2 * i + 1] = new Query(y, x, y, 1, i);
		}

		Arrays.sort(qs);

		Node root = new Node(0, n);

		long[] outp = new long[q];

		int j = 0;
		for (int i = 0; i <= n; i++) {
			while (j < qs.length && qs[j].l == i) {
				long val = root.get(qs[j].lowR, qs[j].highR);
//				System.err.println(qs[j].lowR + " " + qs[j].highR + " " + val);
				outp[qs[j].qryId] += qs[j].sign * val;
				j++;
			}

			int ql = i;
			int qr = Math.min(markFrom[i], n);

//			System.err.println(ql + " " + qr);

			if (ql < qr) {
				root.add(ql, qr);
			}

		}

		for (long x : outp) {
			out.println(x);
		}

	}

	static class Query implements Comparable<Query> {
		int l;
		int lowR, highR;
		int sign;
		int qryId;

		public Query(int l, int lowR, int highR, int sign, int qryId) {
			this.l = l;
			this.lowR = lowR;
			this.highR = highR;
			this.sign = sign;
			this.qryId = qryId;
		}

		@Override
		public int compareTo(Query o) {
			return Integer.compare(l, o.l);
		}
	}

	static class Node {
		int l, r;
		Node left, right;

		long sum;
		int add;

		public Node(int l, int r) {
			this.l = l;
			this.r = r;
			if (r - l > 1) {
				int m = (l + r) >> 1;
				left = new Node(l, m);
				right = new Node(m, r);
			}
		}

		long getSum() {
			return sum + (long) add * (r - l);
		}

		void add(int ql, int qr) {
			if (l >= qr || ql >= r) {
				return;
			}
			if (ql <= l && r <= qr) {
				add += 1;
				return;
			}
			left.add += add;
			right.add += add;
			add = 0;

			left.add(ql, qr);
			right.add(ql, qr);
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

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	C() throws IOException {
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
		new C();
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