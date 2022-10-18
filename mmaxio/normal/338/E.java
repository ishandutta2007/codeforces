import java.io.*;
import java.util.*;

public class cf196E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Node {
		int vl, vr;
		Node left, right;

		int add;
		int min;

		public Node(int vl, int vr, int n) {
			this.vl = vl;
			this.vr = vr;
			if (vr == vl + 1) {
				min = vl - n;
			} else {
				int mid = (vl + vr) >> 1;
				left = new Node(vl, mid, n);
				right = new Node(mid, vr, n);
				min = Math.min(left.min, right.min);
			}
		}

		void add(int ql, int qr, int delta) {
			//System.err.println(vl + " " + vr + ", " + ql + " " + qr);
			if (ql >= vr || vl >= qr)
				return;
			if (ql <= vl && vr <= qr) {
				add += delta;
				return;
			}
			left.add(ql, qr, delta);
			right.add(ql, qr, delta);
			min = Math.min(left.min + left.add, right.min + right.add);
		}

	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int h = nextInt();

		int[] b = new int[m];
		for (int i = 0; i < m; i++) {
			b[i] = h - nextInt();
		}

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		Arrays.sort(b);
		Node root = new Node(0, m, m);

		for (int i = 0; i < m; i++) {
			int pos = getPos(a[i], b);
			if (pos != 0)
				root.add(0, pos, 1);
		}

		int ans = 0;
		if (root.min + root.add >= 0)
			ans++;

		for (int i = m; i < n; i++) {
			int pos = getPos(a[i], b);
			if (pos != 0)
				root.add(0, pos, 1);
			pos = getPos(a[i - m], b);
			if (pos != 0)
				root.add(0, pos, -1);
			if (root.min + root.add >= 0)
				ans++;
		}

		out.println(ans);
	}

	static int getPos(int x, int[] a) {
		int low = -1; // <=
		int high = a.length; // >
		while (low + 1 < high) {
			int mid = (low + high) >> 1;
			if (a[mid] <= x) {
				low = mid;
			} else {
				high = mid;
			}
		}
		return high;
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new cf196E().inp();
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