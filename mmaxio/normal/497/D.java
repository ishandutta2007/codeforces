import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Point {
		int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public Point to(Point p) {
			return new Point(p.x - x, p.y - y);
		}

		public Point add(Point p) {
			return new Point(x + p.x, y + p.y);
		}

		int sqLen() {
			return x * x + y * y;
		}

		public Point neg() {
			return new Point(-x, -y);
		}

		public int scProd(Point p) {
			return x * p.x + y * p.y;
		}
	}

	Point nextPoint() throws IOException {
		int x = nextInt();
		int y = nextInt();
		return new Point(x, y);
	}

	boolean go(Point p, Point[] a, Point q, Point[] b) {
		Point[] aa = new Point[a.length];
		for (int i = 0; i < a.length; i++) {
			aa[i] = p.to(a[i]);
		}
		Point[] bb = new Point[b.length + 1];
		for (int i = 0; i < b.length; i++) {
			bb[i] = p.to(b[i]);
		}
		bb[b.length] = p.to(b[0]);
		q = p.to(q);
		for (Point pa : aa) {
			Point c = pa.add(q);
			int r2 = q.sqLen();
			// radius is |q|
			for (int i = 0; i < bb.length - 1; i++) {
				Point p1 = c.to(bb[i]);
				Point p2 = c.to(bb[i + 1]);
				double maxDist = Math.max(p1.sqLen(), p2.sqLen());
				double minDist = Math.min(p1.sqLen(), p2.sqLen());
				if (p1.neg().scProd(p1.to(p2)) > 0
						&& p2.neg().scProd(p2.to(p1)) > 0) {
					int A = p2.y - p1.y;
					int B = p1.x - p2.x;
					int C = -p1.x * A - p1.y * B;
					double lineD = 1.0 * C * C / (A * A + B * B);
					minDist = lineD;
				}
				if (minDist - 1e-7 <= r2 && maxDist >= r2) {
					return true;
				}
			}
		}
		return false;
	}

	void solve() throws IOException {
		Point p = nextPoint();
		int n = nextInt();
		Point[] a = new Point[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextPoint();
		}

		Point q = nextPoint();
		int m = nextInt();
		Point[] b = new Point[m];
		for (int i = 0; i < m; i++) {
			b[i] = nextPoint();
		}

		out.println(go(p, a, q, b) || go(q, b, p, a) ? "YES" : "NO");
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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