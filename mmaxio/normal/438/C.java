import java.io.*;
import java.util.*;

public class C {

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

		@Override
		public String toString() {
			return "(" + x + ", " + y + ")";
		}
	}

	static boolean onSegment(Point a, Point p, Point q) {
		int x1 = p.x - a.x;
		int y1 = p.y - a.y;
		int x2 = q.x - a.x;
		int y2 = q.y - a.y;
		if ((long) x1 * y2 != (long) x2 * y1) {
			return false;
		}
		return Integer.signum(x1) * Integer.signum(x2) <= 0
				&& Integer.signum(y1) * Integer.signum(y2) <= 0;
	}

	static boolean goodOrder(int x1, int y1, int x2, int y2, int x3, int y3) {
//		System.err.println(x1 + " " + y1 + " " + x2 + " " + y2 + " " + x3 + " " + y3);
		long vp1 = (long) x1 * y2 - (long) x2 * y1;
		if (vp1 == 0) {
			return (long) x1 * y3 > (long) x3 * y1;
		}
		if (vp1 > 0) {
			return (long) x1 * y3 - (long) x3 * y1 > 0
					&& (long) x2 * y3 - (long) x3 * y2 < 0;
		}
		if (vp1 < 0) {
			return (long) x1 * y3 - (long) x3 * y1 >= 0
					|| (long) x2 * y3 - (long) x3 * y2 <= 0;
		}
		throw new AssertionError();
	}

	static boolean interSegments(Point a, Point b, Point c, Point d) {
		int x1 = c.x - a.x;
		int y1 = c.y - a.y;
		int x2 = d.x - a.x;
		int y2 = d.y - a.y;
		int x3 = b.x - a.x;
		int y3 = b.y - a.y;

		long vp1 = (long) x1 * y3 - (long) x3 * y1;
		long vp2 = (long) x2 * y3 - (long) x3 * y2;
		if (vp1 == 0 || vp2 == 0) {
			return false;
		}
		if (Long.signum(vp1) * Long.signum(vp2) > 0) {
			return false;
		}

		x1 = a.x - c.x;
		y1 = a.y - c.y;
		x2 = b.x - c.x;
		y2 = b.y - c.y;
		x3 = d.x - c.x;
		y3 = d.y - c.y;

		vp1 = (long) x1 * y3 - (long) x3 * y1;
		vp2 = (long) x2 * y3 - (long) x3 * y2;
		if (vp1 == 0 || vp2 == 0) {
			return false;
		}
		if (Long.signum(vp1) * Long.signum(vp2) > 0) {
			return false;
		}

		return true;
	}

	void solve() throws IOException {
		int n = nextInt();
		Point[] p = new Point[n + 1];
		for (int i = 0; i < n; i++) {
			p[i] = new Point(nextInt(), nextInt());
		}
		p[n] = p[0];

		long sq = 0;
		for (int i = 0; i < n; i++) {
			sq += (long) p[i].x * p[i + 1].y - (long) p[i + 1].x * p[i].y;
		}

		if (sq < 0) {
			for (int i = 1, j = n - 1; i < j; i++, j--) {
				Point tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}

//		System.err.println(Arrays.toString(p));

		boolean[][] ok = new boolean[n][n];
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				outer: do {
					if (j - i == 1 || j - i == n - 1) {
						ok[i][j] = true;
						break outer;
					}
					for (int k = 0; k < n; k++) {
						if (k != i && k != j && onSegment(p[k], p[i], p[j])) {
							ok[i][j] = false;
							break outer;
						}
					}
					for (int k = 0; k < n; k++) {
						if (interSegments(p[i], p[j], p[k], p[k + 1])) {
							ok[i][j] = false;
							break outer;
						}
					}
					int x1 = p[i + 1].x - p[i].x;
					int y1 = p[i + 1].y - p[i].y;
					Point prev = i == 0 ? p[n - 1] : p[i - 1];
					int x2 = prev.x - p[i].x;
					int y2 = prev.y - p[i].y;

//					if (i == 0 && j == 2) {
//						System.err.println(x1 + " " + y1 + " " + x2 + " " + y2
//								+ " " + (p[j].x - p[i].x) + " "
//								+ (p[j].y - p[i].y));
//					}

					ok[i][j] = goodOrder(x1, y1, x2, y2, p[j].x - p[i].x,
							p[j].y - p[i].y);

				} while (false);
//				System.err.println(i + " " + j + " " + ok[i][j]);
				ok[j][i] = ok[i][j];
			}

		int[][] ways = new int[n][n];
		for (int i = 0; i < n - 1; i++) {
			ways[i][i + 1] = 1;
		}

		for (int diff = 2; diff < n; diff++) {
			for (int i = 0; i + diff < n; i++) {
				int j = i + diff;
				for (int k = i + 1; k < j; k++) {
					if (ok[i][k] && ok[k][j]) {
						ways[i][j] += (int) ((long) ways[i][k] * ways[k][j] % MOD);
						if (ways[i][j] >= MOD) {
							ways[i][j] -= MOD;
						}
					}
				}
			}
		}

		out.println(ways[0][n - 1]);
	}

	static final int MOD = 1000000007;

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