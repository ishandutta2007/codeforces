import java.io.*;
import java.util.*;

public class F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int P = 1_000_000_007;

	static final String DIRS = "DRUL";
	static final int[] DX = { 1, 0, -1, 0 };
	static final int[] DY = { 0, 1, 0, -1 };

	SparseTableMin minDx;
	SparseTableMax maxDx;
	SparseTableMin minDy;
	SparseTableMax maxDy;

	public class SparseTableMin {

		private int getLog(int len) {
			return len <= 2 ? 0 : 31 - Integer.numberOfLeadingZeros(len - 1);
		}

		private/* 1 */int[][] d;

		public SparseTableMin( /* 1 */int[] a) {
			int n = getLog(a.length);
			d = new /* 1 */int[n + 1][];
			d[0] = a.clone();
			for (int i = 1; i <= n; i++) {
				d[i] = new /* 1 */int[a.length - (1 << i) + 1];
				for (int j = 0; j < d[i].length; j++) {
					d[i][j] = /* 2 */Math.min(d[i - 1][j], d[i - 1][j
							+ (1 << (i - 1))]);
				}
			}
		}

		public/* 1 */int get(int l, int r) {
			int i = getLog(r - l);
			return /* 2 */Math.min(d[i][l], d[i][r - (1 << i)]);
		}

	}

	public class SparseTableMax {

		private int getLog(int len) {
			return len <= 2 ? 0 : 31 - Integer.numberOfLeadingZeros(len - 1);
		}

		private/* 1 */int[][] d;

		public SparseTableMax( /* 1 */int[] a) {
			int n = getLog(a.length);
			d = new /* 1 */int[n + 1][];
			d[0] = a.clone();
			for (int i = 1; i <= n; i++) {
				d[i] = new /* 1 */int[a.length - (1 << i) + 1];
				for (int j = 0; j < d[i].length; j++) {
					d[i][j] = /* 2 */Math.max(d[i - 1][j], d[i - 1][j
							+ (1 << (i - 1))]);
				}
			}
		}

		public/* 1 */int get(int l, int r) {
			int i = getLog(r - l);
			return /* 2 */Math.max(d[i][l], d[i][r - (1 << i)]);
		}

	}

	int n, h, w;

	int[] dx, dy;

	int getFirstMax(SparseTableMax st, int from, int more) {
		if (st.get(from, n + 1) <= more) {
			return n + 1;
		}

		int l = from + 1;
		int r = n + 1;
		while (r - l > 1) {
			int mid = (l + r) >> 1;
			if (st.get(from, mid) <= more) {
				l = mid;
			} else {
				r = mid;
			}
		}
		return l;
	}

	int getFirstMin(SparseTableMin st, int from, int less) {
		if (st.get(from, n + 1) >= less) {
			return n + 1;
		}

		int l = from + 1;
		int r = n + 1;
		while (r - l > 1) {
			int mid = (l + r) >> 1;
			if (st.get(from, mid) >= less) {
				l = mid;
			} else {
				r = mid;
			}
		}
		return l;
	}

	int getNextPos(int x1, int y1, int x2, int y2, int pos) {
		int needMoreDx = dx[pos] + (h - x2);
		int ret1 = getFirstMax(maxDx, pos, needMoreDx);
		int needLessDx = dx[pos] - x1;
		int ret2 = getFirstMin(minDx, pos, needLessDx);

		int needMoreDy = dy[pos] + (w - y2);
		int ret3 = getFirstMax(maxDy, pos, needMoreDy);
		int needLessDy = dy[pos] - y1;
		int ret4 = getFirstMin(minDy, pos, needLessDy);

		return Math.min(Math.min(ret1, ret2), Math.min(ret3, ret4));
	}

	int solve(int n, int h, int w, String ss) {

		this.n = n;
		this.h = h;
		this.w = w;

		int[] dir = new int[n];
		for (int i = 0; i < n; i++) {
			dir[i] = DIRS.indexOf(ss.charAt(i));
		}

		int x1 = 0;
		int x2 = h;
		int y1 = 0;
		int y2 = w;

		int ret = 0;

		dx = new int[n + 1];
		dy = new int[n + 1];
		for (int i = 0; i < n; i++) {
			dx[i + 1] = dx[i] + DX[dir[i]];
			dy[i + 1] = dy[i] + DY[dir[i]];
		}

		minDx = new SparseTableMin(dx);
		maxDx = new SparseTableMax(dx);
		minDy = new SparseTableMin(dy);
		maxDy = new SparseTableMax(dy);

		outer: while (true) {
			int pos = 0;

			// int oldX1 = x1;
			// int oldY1 = y1;
			// int oldX2 = x2;
			// int oldY2 = y2;

			while (pos < n) {
				int nextPos = getNextPos(x1, y1, x2, y2, pos);
//				System.err.println(pos + " " + nextPos);
				if (nextPos == n + 1) {

					ret += (int) ((long) (x2 - x1) * (y2 - y1) % P * (n - pos) % P);
					if (ret >= P) {
						ret -= P;
					}

					x1 += dx[n] - dx[pos];
					x2 += dx[n] - dx[pos];
					y1 += dy[n] - dy[pos];
					y2 += dy[n] - dy[pos];

					if (pos == 0) {
						return -1;
					} else {
						continue outer;
					}
				}

				ret += (int) ((long) (x2 - x1) * (y2 - y1) % P
						* (nextPos - pos) % P);
				if (ret >= P) {
					ret -= P;
				}

				x1 += dx[nextPos] - dx[pos];
				x2 += dx[nextPos] - dx[pos];
				y1 += dy[nextPos] - dy[pos];
				y2 += dy[nextPos] - dy[pos];

				if (x1 < 0) {
					x1 = 0;
				}
				if (x2 > h) {
					x2 = h;
				}
				if (y1 < 0) {
					y1 = 0;
				}
				if (y2 > w) {
					y2 = w;
				}

				pos = nextPos;

				if (x1 == x2 || y1 == y2) {
					break outer;
				}
			}
			// if (x1 == oldX1 && x2 == oldX2 && y1 == oldY1 && y2 == oldY2) {
			// out.println(-1);
			// return;
			// }
		}

		return ret;
	}

	int f(int x, int y, int h, int w, String s) {
		int ret = 0;
		// System.err.println("!");
		while (true) {
			// System.err.println(x + " " + y);
			int oldX = x;
			int oldY = y;
			for (char c : s.toCharArray()) {
				int d = DIRS.indexOf(c);
				x += DX[d];
				y += DY[d];
				ret++;
				if (x < 0 || x >= h || y < 0 || y >= w) {
					return ret;
				}
			}
			if (x == oldX && y == oldY) {
				return -1;
			}
		}
	}

	int stupid(int n, int h, int w, String s) {
		int ret = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				int delta = f(i, j, h, w, s);
				if (delta == -1) {
					return -1;
				}
				ret += delta;
			}
		return ret;
	}

	String genString(int n) {
		Random rng = new Random();
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.append(DIRS.charAt(rng.nextInt(4)));
		}
		return sb.toString();
	}

	F() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		int n = nextInt();
		int h = nextInt();
		int w = nextInt();
		String ss = nextToken();
		out.println(solve(n, h, w, ss));

		// while (true) {
		// int n = 1;
		// int h = 2;
		// int w = 1;
		// String s = genString(n);
		//
		// int ret1 = solve(n, h, w, s);
		// int ret2 = stupid(n, h, w, s);
		//
		// if (ret1 != ret2) {
		// System.err.println(h + " " + w + " " + s);
		// break;
		// } else {
		// System.err.println("ok");
		// }
		// }

		out.close();
	}

	public static void main(String[] args) throws IOException {
		new F();
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