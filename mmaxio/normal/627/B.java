import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static class Node {
		
		static int a, b;
		
		int l, r;
		Node left, right;
		
		int sumB, sumA;

		public Node(int l, int r) {
			this.l = l;
			this.r = r;
			if (r - l > 1) {
				int mid = (l + r) >> 1;
				left = new Node(l, mid);
				right = new Node(mid, r);
			}
		}
		
		void set(int pos, int val) {
			if (r - l == 1 && pos == l) {
				sumA = Math.min(a, val);
				sumB = Math.min(b, val);
				return;
			}
			(pos < left.r ? left : right).set(pos, val);
			sumA = left.sumA + right.sumA;
			sumB = left.sumB + right.sumB;
		}
		
		int get(int ql, int qr, boolean getA) {
			if (l >= qr || ql >= r) {
				return 0;
			}
			if (ql <= l && r <= qr) {
				return getA ? sumA : sumB;
			}
			return left.get(ql, qr, getA) + right.get(ql, qr, getA);
		}
		
	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		int a = nextInt();
		int b = nextInt();
		int q = nextInt();
		
		Node root = new Node(0, n);
		Node.a = a;
		Node.b = b;
		
		int[] arr = new int[n];
		
		while (q-- > 0) {
			int type = nextInt();
			if (type == 1) {
				int pos = nextInt() - 1;
				int delta = nextInt();
				arr[pos] += delta;
				root.set(pos, arr[pos]);
			} else {
				int pos = nextInt() - 1;
				
				int ret = root.get(0, pos, false) + root.get(pos + k, n, true);
				out.println(ret);
			}
		}
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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