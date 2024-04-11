import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	static final int INF = Integer.MAX_VALUE / 4;

	static boolean nextPermutation(int[] a) {
		int n = a.length;
		int ptr = n - 2;
		while (ptr >= 0 && a[ptr] > a[ptr + 1]) {
			ptr--;
		}
		if (ptr < 0) {
			return false;
		}

		for (int i = ptr + 1, j = n - 1; i < j; i++, j--) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}

		for (int i = ptr + 1;; i++) {
			if (a[ptr] < a[i]) {
				int tmp = a[ptr];
				a[ptr] = a[i];
				a[i] = tmp;
				return true;
			}
		}
	}

	class Solver {

		int[] xs, ys;

		public Solver(int[] xs, int[] ys) {
			this.xs = xs;
			this.ys = ys;
		}

		int ans;
		int[] outpX;
		int[] outpY;

		int go(int x1, int x2, int y1, int y2) {

			if (x1 >= x2 || y1 >= y2 || x2 - x1 != y2 - y1) {
				throw new AssertionError();
			}

			int[] goalX = new int[4];
			int[] goalY = new int[4];

			int goRet = INF;

			// String tmp = x1 + " " + y1 + " " + x2 + " " + y2;
			// System.err.println(tmp);
			
			int[] p = {0, 1, 2, 3};

			outer: do {
				goalX[p[0]] = x1;
				goalY[p[0]] = y1;

				goalX[p[1]] = x1;
				goalY[p[1]] = y2;

				goalX[p[2]] = x2;
				goalY[p[2]] = y1;

				goalX[p[3]] = x2;
				goalY[p[3]] = y2;

				int cur = 0;

				for (int i = 0; i < 4; i++) {
					int dx = Math.abs(xs[i] - goalX[i]);
					int dy = Math.abs(ys[i] - goalY[i]);

					if (Math.min(dx, dy) != 0) {
						continue outer;
					}

					cur = Math.max(cur, Math.max(dx, dy));
				}

				if (cur < ans) {
					ans = cur;
					outpX = goalX.clone();
					outpY = goalY.clone();
				}

				goRet = Math.min(goRet, cur);
			} while (nextPermutation(p));

			return goRet;

		}

		void solve() {

			ans = INF;

			for (int mask = 0; mask < 16; mask++) {

				TreeSet<Integer> haveX = new TreeSet<>();
				TreeSet<Integer> haveY = new TreeSet<>();
				for (int i = 0; i < 4; i++) {
					if (test(mask, i)) {
						haveX.add(xs[i]);
					} else {
						haveY.add(ys[i]);
					}
				}

				if (haveX.size() > 2 || haveY.size() > 2) {
					continue;
				}

				if (haveX.size() == 2 && haveY.size() == 0) {

					int x1 = haveX.first();
					int x2 = haveX.last();

					int yLow = -INF;
					int yHigh = INF;

					while (yHigh - yLow >= 3) {
						int y1 = (2 * yLow + yHigh) / 3;
						int y2 = (yLow + 2 * yHigh) / 3;

						int val1 = go(x1, x2, y1, y1 + x2 - x1);
						int val2 = go(x1, x2, y2, y2 + x2 - x1);

						if (val1 < val2) {
							yHigh = y2;
						} else {
							yLow = y1;
						}
					}

					for (int y = yLow; y <= yHigh; y++) {
						go(x1, x2, y, y + x2 - x1);
					}

				}

				else if (haveX.size() == 2 && haveY.size() == 1) {

					int x1 = haveX.first();
					int x2 = haveX.last();

					int y = haveY.first();

					go(x1, x2, y - (x2 - x1), y);
					go(x1, x2, y, y + (x2 - x1));
				}

				else if (haveX.size() == 2 && haveY.size() == 2) {
					int x1 = haveX.first();
					int x2 = haveX.last();

					int y1 = haveY.first();
					int y2 = haveY.last();

					if (x2 - x1 == y2 - y1)

						go(x1, x2, y1, y2);
				} else if (haveX.size() == 1 && haveY.size() == 0) {

				} else if (haveX.size() == 1 && haveY.size() == 1) {

				} else if (haveX.size() == 0 && haveY.size() == 2) {

					int y1 = haveY.first();
					int y2 = haveY.last();

					int xLow = -INF;
					int xHigh = INF;

					while (xHigh - xLow >= 3) {
						int x1 = (2 * xLow + xHigh) / 3;
						int x2 = (xLow + 2 * xHigh) / 3;

						int val1 = go(x1, x1 + y2 - y1, y1, y2);
						int val2 = go(x2, x2 + y2 - y1, y1, y2);

						if (val1 < val2) {
							xHigh = x2;
						} else {
							xLow = x1;
						}
					}

					for (int x = xLow; x <= xHigh; x++) {
						go(x, x + y2 - y1, y1, y2);
					}

				}

				else if (haveX.size() == 1 && haveY.size() == 2) {

					int y1 = haveY.first();
					int y2 = haveY.last();

					int x = haveX.first();

					go(x, x + (y2 - y1), y1, y2);
					go(x - (y2 - y1), x, y1, y2);
				}

			}

			if (ans == INF) {
				out.println(-1);
			} else {
				out.println(ans);
				for (int i = 0; i < 4; i++) {
					out.println(outpX[i] + " " + outpY[i]);
				}
			}
		}
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		int t = nextInt();
		while (t-- > 0) {

			int[] xs = new int[4];
			int[] ys = new int[4];
			for (int i = 0; i < 4; i++) {
				xs[i] = nextInt();
				ys[i] = nextInt();
			}

			new Solver(xs, ys).solve();
		}
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