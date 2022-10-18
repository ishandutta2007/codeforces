import java.io.*;
import java.util.*;

public class E_noacc {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int FULL = 360;
	static double[] XS = new double[FULL];
	static double[] YS = new double[FULL];
	static {
		for (int i = 0; i < FULL; i++) {
			XS[i] = Math.cos(-2 * Math.PI * i / FULL);
			YS[i] = Math.sin(-2 * Math.PI * i / FULL);
		}
	}
	
	static class Point {
		double x, y;

		public Point(double x, double y) {
			this.x = x;
			this.y = y;
		}
		
		void set(double x, double y) {
			this.x = x;
			this.y = y;
		}
	}

	static class Node {
		int l, r;
		Node left, right;

		int rotate;
		
		Point sum;

		public Node(int l, int r) {
			this.l = l;
			this.r = r;
			
			sum = new Point(r - l, 0);
			
			if (r - l > 1) {
				int mid = (l + r) >> 1;
				left = new Node(l, mid);
				right = new Node(mid, r);
			}
		}

		void update() {
			Point a = left.getReal();
			Point b = right.getReal();
			sum.set(a.x + b.x, a.y + b.y);
		}

		Point getReal() {
			// 0 <= rotate < full
			double cos = XS[rotate];
			double sin = YS[rotate];
			return new Point(sum.x * cos - sum.y * sin, sum.x * sin + sum.y * cos);
		}

		void goLen(int pos, int delta) {
			if (l == pos && pos + 1 == r) {
				// never rotated here
				sum.x += delta;
				return;
			}
			(pos < left.r ? left : right).goLen(pos, delta);
			update();
		}

		void goAngle(int ql, int qr, int delta) {
			if (r <= ql || qr <= l) {
				return;
			}
			if (ql <= l && r <= qr) {
				rotate += delta;
				if (rotate >= FULL) {
					rotate -= FULL;
				}
				return;
			}
			left.goAngle(ql, qr, delta);
			right.goAngle(ql, qr, delta);
			update();
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();

		Node root = new Node(0, n);
		for (int i = 0; i < m; i++) {
			int type = nextInt();
			int pos = nextInt() - 1;
			int delta = nextInt();

			if (type == 1) {
				root.goLen(pos, delta);
			} else {
				root.goAngle(pos, n, delta);
			}

			Point p = root.getReal();

//			for (int j = 0; j < FULL; j++) {
//				if (lens[j] != 0) {
//					System.err.println(j + " " + lens[j]);
//				}
//			}
//			System.err.println("!!!");

			out.println(p.x + " " + p.y);
		}
	}

	E_noacc() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E_noacc();
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