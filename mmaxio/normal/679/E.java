import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final long BAD = 42;

	static List<Long> bad = new ArrayList<>();

	static class Node {
		int l, r;

		Node left, right;

		long toNext;
		int whoNext;

		long add;

		public Node(int l, int r, int[] a) {
			this.l = l;
			this.r = r;
			if (r - l == 1) {
				add = a[l];
				whoNext = 0;
				toNext = bad.get(whoNext) - add;
			} else {
				int mid = (l + r) >> 1;
				left = new Node(l, mid, a);
				right = new Node(mid, r, a);
				whoNext = -1;
				toNext = Math.min(left.toNext, right.toNext);
			}
		}

		void updateNext() {
			if (toNext >= 0) {
				return;
			}
			if (whoNext >= 0) {
				while (add > bad.get(whoNext)) {
					whoNext++;
				}
				toNext = bad.get(whoNext) - add;
			} else {
				distribute();
				left.updateNext();
				right.updateNext();
				add = 0;
				toNext = Math.min(left.toNext, right.toNext);
			}
		}

		long getValue(int pos) {
			if (whoNext >= 0) {
				return add;
			}
			return add + (pos < left.r ? left : right).getValue(pos);
		}
	
		void distribute() {
			if (whoNext >= 0) {
				left.whoNext = right.whoNext = whoNext;
				left.add = right.add = add;
				left.toNext = right.toNext = toNext;
			} else {
				left.add += add;
				right.add += add;
				left.toNext -= add;
				right.toNext -= add;
			}		
		}
		
		void set(int ql, int qr, int val, int valNext) {
			if (l >= qr || ql >= r) {
				return;
			}
			if (ql <= l && r <= qr) {
				add = val;
				whoNext = valNext;
				toNext = bad.get(whoNext) - val;
				return;
			}
			
			distribute();
			
			left.set(ql, qr, val, valNext);
			right.set(ql, qr, val, valNext);
			add = 0;
			whoNext = -1;
			toNext = Math.min(left.toNext, right.toNext);
		}
	
		void add(int ql, int qr, int delta) {
			if (l >= qr || ql >= r) {
				return;
			}
			if (ql <= l && r <= qr) {
				add += delta;
				toNext -= delta;
				return;
			}
			distribute();
			
			left.add(ql, qr, delta);
			right.add(ql, qr, delta);
			add = 0;
			whoNext = -1;
			toNext = Math.min(left.toNext, right.toNext);
		}
	}

	void solve() throws IOException {
		long tmp = 1;
		while (tmp <= Long.MAX_VALUE / BAD) {
			bad.add(tmp);
			tmp *= BAD;
		}
		bad.add(tmp);

		int n = nextInt();
		int q = nextInt();

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		Node root = new Node(0, n, a);
		root.updateNext();

		while (q-- > 0) {
			int type = nextInt();
			if (type == 1) {
				int pos = nextInt() - 1;
				out.println(root.getValue(pos));
			} else {
				int l = nextInt() - 1;
				int r = nextInt();
				int x = nextInt();
				if (type == 2) {
					int whoNext = Collections.binarySearch(bad, (long)x);
					if (whoNext < 0) {
						whoNext = -whoNext - 1;
					}
					root.set(l, r, x, whoNext);
					root.updateNext();
				} else {
					do {
						root.add(l, r, x);
						root.updateNext();
					} while (root.toNext == 0);
				}
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