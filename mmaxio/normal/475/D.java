import java.io.*;
import java.util.*;

public class E_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	static class Node {
		int l, r;
		Node left, right;
		int gcd;

		public Node(int l, int r, int[] a) {
			this.l = l;
			this.r = r;
			if (r - l > 1) {
				int mid = (l + r) >> 1;
				left = new Node(l, mid, a);
				right = new Node(mid, r, a);
				gcd = gcd(left.gcd, right.gcd);
			} else {
				gcd = a[l];
			}
		}

		int get(int ql, int qr) {
			if (l >= qr || ql >= r) {
				return 0;
			}
			if (ql <= l && r <= qr) {
				return gcd;
			}
			return gcd(left.get(ql, qr), right.get(ql, qr));
		}
		
		void clear(int pos) {
			if (l == pos && pos + 1 == r) {
				gcd = 0;
				return;
			}
			(pos < left.r ? left : right).clear(pos);
			gcd = gcd(left.gcd, right.gcd);
		}
	}

	Map<Integer, Long> memo = new HashMap<>();

	void update(int x, int y) {
		Long prev = memo.get(x);
		long p = prev == null ? 0 : prev;
		memo.put(x, p + y);
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		int[] suff = new int[n + 1];
		suff[n] = 0;
		for (int i = n - 1; i >= 0; i--) {
			suff[i] = gcd(suff[i + 1], a[i]);
		}

		Node root = new Node(0, n, a);
		outer: for (int i = 0; i < n; i++) {
			int j = i + 1;
			
			while (true) {
				int val = root.get(i, j);
				if (suff[j] % val == 0) {
					update(val, n - j + 1);
					root.clear(i);
					continue outer;
				}
				
				int curL = 0;
				int curR = n;
				Node curV = root;
				
				while (curR - curL > 1) {
					int mid = (curL + curR) >> 1;
					if (curV.left.gcd % val == 0) {
						curV = curV.right;
						curL = mid;
					} else {
						curV = curV.left;
						curR = mid;
					}
				}
				
//				System.err.println(i + " " + curL + " " + curR);
				
				update(val, curL - j + 1);
				j = curR;

			}
		}
		// System.err.println(memo);
		int q = nextInt();
		while (q-- > 0) {
			int x = nextInt();
			Long ans = memo.get(x);
			if (ans == null) {
				out.println(0);
			} else {
				out.println(ans);
			}
		}
	}

	E_new() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E_new();
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