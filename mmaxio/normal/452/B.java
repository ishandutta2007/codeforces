import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Point implements Comparable<Point> {
		int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		double dist(Point o) {
			int dx = x - o.x;
			int dy = y - o.y;
			return Math.sqrt(dx * dx + dy * dy);
		}

		@Override
		public int compareTo(Point o) {
			if (x != o.x) {
				return x < o.x ? -1 : 1;
			}
			return Integer.compare(y, o.y);
		}

		@Override
		public String toString() {
			return x + " " + y;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		List<Point> all = new ArrayList<Point>(64);
		for (int dx = 0; dx < Math.min(4, n + 1); dx++)
			for (int dy = 0; dy < Math.min(4, m + 1); dy++) {
				int x1 = dx;
				int y1 = dy;
				int x2 = n - dx;
				int y2 = m - dy;
				all.add(new Point(x1, y1));
				all.add(new Point(x1, y2));
				all.add(new Point(x2, y1));
				all.add(new Point(x2, y2));
			}

		double maxDist = 0;
		Point[] ans = null;

		for (Point p1 : all) {
			for (Point p2 : all) {
				for (Point p3 : all) {
					for (Point p4 : all) {
						if (p1.compareTo(p2) == 0 || p1.compareTo(p3) == 0
								|| p1.compareTo(p4) == 0
								|| p2.compareTo(p3) == 0
								|| p2.compareTo(p4) == 0
								|| p3.compareTo(p4) == 0) {
							continue;
						}
						double cand = p1.dist(p2) + p2.dist(p3) + p3.dist(p4);
						if (cand > maxDist) {
							maxDist = cand;
							ans = new Point[] { p1, p2, p3, p4 };
						}
					}
				}
			}
		}

		for (Point p : ans) {
			out.println(p);
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