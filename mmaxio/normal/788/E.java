import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int P = 1_000_000_007;

	static class Node {
		int w1, w2, w3, w12, w23, w123;

		int l, r;
		Node left, right;

		public Node(int l, int r) {
			this.l = l;
			this.r = r;

			if (r - l > 1) {
				int mid = (l + r) / 2;
				left = new Node(l, mid);
				right = new Node(mid, r);
			}
		}

		void combine() {
			w1 = (left.w1 + right.w1) % P;
			w2 = (left.w2 + right.w2) % P;
			w3 = (left.w3 + right.w3) % P;
			w12 = (int) ((left.w12 + (long) left.w1 * right.w2 + right.w12) % P);
			w23 = (int) ((left.w23 + (long) left.w2 * right.w3 + right.w23) % P);
			w123 = (int) ((left.w123 + (long) left.w12 * right.w3
					+ (long) left.w1 * right.w23 + right.w123) % P);
		}

		void set(int pos, int w1, int w2, int w3) {
			if (r - l == 1) {
				this.w1 = w1;
				this.w2 = w2;
				this.w3 = w3;
				return;
			}
			(pos < left.r ? left : right).set(pos, w1, w2, w3);
			combine();
		}

	}

	void add(int[] f, int pos, int delta) {
		for (int i = pos; i < f.length; i |= i + 1) {
			f[i] += delta;
		}
	}

	int get(int[] f, int pos) {
		int ret = 0;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
			ret += f[i];
		}
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		int[] b = unique(a);
		for (int i = 0; i < n; i++) {
			a[i] = Arrays.binarySearch(b, a[i]);
		}

		Integer[] order = new Integer[n];
		for (int i = 0; i < n; i++) {
			order[i] = i;
		}

		Arrays.sort(order, new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				return Integer.compare(a[o1], a[o2]);
			}

		});

		int ptr = 0;
		Node[] roots = new Node[n];
		int[] val1 = new int[n];
		int[] val3 = new int[n];
		int[] rootIdx = new int[n];
		int[] leafIdx = new int[n];

		int[] fen = new int[n];

		int answer = 0;

		for (int i = 0; i < n;) {
			int j = i;
			while (j < n && a[order[i]] == a[order[j]]) {
				j++;
			}
			for (int k = i; k < j; k++) {
				add(fen, order[k], 1);
			}

			for (int k = i; k < j; k++) {
				int pos = order[k];
				rootIdx[pos] = ptr;
				leafIdx[pos] = k - i;
				val1[pos] = get(fen, pos - 1);
				val3[pos] = j - 1 - val1[pos];
			}
			roots[ptr] = new Node(0, j - i);
			for (int k = i; k < j; k++) {
				roots[ptr].set(k - i, val1[order[k]], 1, val3[order[k]]);
			}

			answer += roots[ptr].w123;
			answer %= P;

			ptr++;
			i = j;
		}

		int q = nextInt();
		while (q-- > 0) {
			int t = nextInt();
			int pos = nextInt() - 1;
			Node root = roots[rootIdx[pos]];
			int leaf = leafIdx[pos];
			answer -= root.w123;
			if (answer < 0) {
				answer += P;
			}

			if (t == 1) {
				root.set(leaf, 0, 0, 0);
			} else {
				root.set(leaf, val1[pos], 1, val3[pos]);
			}

			answer += root.w123;
			answer %= P;

			out.println(answer);
		}
	}

	int[] unique(int[] a) {
		a = a.clone();
		Arrays.sort(a);
		int sz = 1;
		for (int i = 1; i < a.length; i++) {
			if (a[i] != a[sz - 1]) {
				a[sz++] = a[i];
			}
		}
		return Arrays.copyOf(a, sz);
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