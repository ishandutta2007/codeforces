import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Node {
		int l, r;

		Node left, right;

		int min, add;

		public Node(int l, int r) {
			this.l = l;
			this.r = r;
			if (r - l > 1) {
				int mid = (l + r) >> 1;
				left = new Node(l, mid);
				right = new Node(mid, r);
			}
		}
		
		int getMin() {
			return min + add;
		}

		void add(int ql, int qr, int delta) {
			if (l >= qr || ql >= r) {
				return;
			}
			if (ql <= l && r <= qr) {
				add += delta;
				return;
			}
			left.add(ql, qr, delta);
			right.add(ql, qr, delta);
			min = Math.min(left.getMin(), right.getMin());
		}
		
		int find(int val, int addTop) {
			if (r - l == 1) {
				return l;
			}
			addTop += add;
			if (right.getMin() + addTop >= val) {
				return left.find(val, addTop);
			} else {
				return right.find(val, addTop);
			}
		}

	}

	void solve() throws IOException {
		int m = nextInt();

		Node root = new Node(0, m + 1);
		
		int[] val = new int[m];
		
		int total = 0;
		
		for (int i = 0; i < m; i++) {
			int pos = nextInt() - 1;
			int type = nextInt();
			if (type == 0) {
				root.add(pos + 1, m + 1, -1);
				total--;
			} else {
				val[pos] = nextInt();
				root.add(pos + 1, m + 1, 1);
				total++;
			}
			
			int globalMin = root.getMin();
			if (globalMin == total) {
				out.println(-1);
				continue;
			}
			
			int where = root.find(total, 0);
//			out.println("???" + where);
			out.println(val[where]);
		}
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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