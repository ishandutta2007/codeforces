import java.io.*;
import java.util.*;

public class cf690B3 {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int SHIFT = 17;

	HashSet<Long> set;

	boolean good(long v) {
		if (set.contains(v)) {
			return false;
		}
		for (int dx = -1; dx <= 1; dx++)
			for (int dy = -1; dy <= 1; dy++) {
				if (dx == 0 && dy == 0) {
					continue;
				}
				long u = v + (dx << SHIFT) + dy;
				if (set.contains(u)) {
					return true;
				}
			}
		return false;
	}

	void dfs(long v, HashSet<Long> cur) {
		cur.add(v);
		for (int dx = -1; dx <= 1; dx++)
			for (int dy = -1; dy <= 1; dy++) {
				if (dx == 0 && dy == 0) {
					continue;
				}
				long u = v + (dx << SHIFT) + dy;
				if (!cur.contains(u) && good(u)) {
					dfs(u, cur);
				}
			}
	}

	boolean solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		if (n == 0 && m == 0) {
			return false;
		}

		long[] ps = new long[m];

		set = new HashSet<>();

		int[] xs = new int[m];
		int[] ys = new int[m];

		int idx = 0;

		for (int i = 0; i < m; i++) {
			xs[i] = nextInt();
			ys[i] = nextInt();

			if (xs[i] < xs[idx] || (xs[i] == xs[idx] && ys[i] < ys[idx])) {
				idx = i;
			}
			ps[i] = ((1L * xs[i]) << SHIFT) | ys[i];
			set.add(ps[i]);
		}

		HashSet<Long> set1 = new HashSet<>();
		dfs(ps[idx] - (1 << SHIFT) - 1, set1);

		List<Point> a = new ArrayList<>();
		HashSet<Long> setA = new HashSet<>();
		for (int i = 0; i < m; i++) {
			for (int dx = -1; dx <= 0; dx++)
				for (int dy = -1; dy <= 0; dy++) {
					int x = xs[i] + dx;
					int y = ys[i] + dy;
					long hash = ((1L * x) << SHIFT) | y;
					if (setA.contains(hash)) {
						continue;
					}

					setA.add(hash);

					boolean ok = true;
					outer: for (int xx = 0; xx <= 1; xx++)
						for (int yy = 0; yy <= 1; yy++) {
							long hash1 = hash + (xx << SHIFT) + yy;
							if (set1.contains(hash1)) {
								ok = false;
								break outer;
							}
						}

					if (ok) {
						a.add(new Point(x, y));
					}
				}
		}

		Point[] arr = a.toArray(new Point[a.size()]);
		Point[] h = convexHull(arr);

		for (int i = 0, j = h.length - 1; i < j; i++, j--) {
			Point tmp = h[i];
			h[i] = h[j];
			h[j] = tmp;
		}

		int start = 0;
		for (int i = 1; i < h.length; i++) {
			if (h[i].x < h[start].x
					|| (h[i].x == h[start].x && h[i].y < h[start].y)) {
				start = i;
			}
		}

		out.println(h.length);
		for (int i = start; i < h.length; i++) {
			Point p = h[i];
			out.println(p.x + " " + p.y);
		}

		for (int i = 0; i < start; i++) {
			Point p = h[i];
			out.println(p.x + " " + p.y);
		}

		return true;
	}

	String asPoint(long q) {
		return "(" + (q >> SHIFT) + ", " + (q & ((1 << SHIFT) - 1)) + ")";
	}

	static class Point implements Comparable<Point> {
		static final Point ZERO = new Point(0, 0);
		int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Point o) {
			if (y != o.y)
				return y < o.y ? -1 : 1;
			if (x != o.x)
				return x < o.x ? -1 : 1;
			return 0;
		}

		long vectMul(Point p) {
			return (long) x * p.y - (long) y * p.x;
		}

		@Override
		public String toString() {
			return "(" + x + ", " + y + ")";
		}

		public boolean equals(Point p) {
			return x == p.x && y == p.y;
		}
	}

	static int getTurn(Point A, Point B, Point C) {
		// angle between AB and AC
		long p1 = (long) (B.x - A.x) * (C.y - A.y);
		long p2 = (long) (B.y - A.y) * (C.x - A.x);
		if (p1 == p2)
			return 0;
		else
			return p1 < p2 ? -1 : 1;
	}

	/**
	 * PERMUTES POINTS IN ARRAY, consider using convexHull(a.clone()) Points
	 * themselves are modified inside method too, but changes are reverted at
	 * the end
	 * 
	 * @param a
	 *            - array of points
	 * @return convexHull of these point in CCW order, no duplicates, no three
	 *         points on one side
	 */
	static Point[] convexHull(Point[] a) {

		if (a == null)
			return null;
		if (a.length == 0)
			return new Point[] {};

		int st = 0;
		for (int i = 1; i < a.length; i++)
			if (a[i].compareTo(a[st]) < 0)
				st = i;

		Point tmp = a[0];
		a[0] = a[st];
		a[st] = tmp;

		int sx = a[0].x;
		int sy = a[0].y;

		for (int i = 0; i < a.length; i++) {
			a[i].x -= sx;
			a[i].y -= sy;
		}

		Arrays.sort(a, 1, a.length, new Comparator<Point>() {

			@Override
			public int compare(Point o1, Point o2) {
				if (o1.equals(o2))
					return 0;
				if (o1.equals(Point.ZERO)) {
					return -1;
				}
				if (o2.equals(Point.ZERO)) {
					return 1;
				}
				long val = o1.vectMul(o2);
				if (val != 0)
					return val > 0 ? -1 : 1;
				if (o1.y == 0) {
					return o1.x < o2.x ? -1 : 1;
				} else {
					return o1.y < o2.y ? -1 : 1;
				}
			}
		});

		Point[] h = new Point[a.length];
		int sz = 0;
		h[sz++] = a[0];
		for (int i = 1; i < a.length; i++) {
			if (a[i].equals(h[sz - 1]))
				continue;
			while (sz > 1 && getTurn(h[sz - 2], h[sz - 1], a[i]) <= 0)
				sz--;
			h[sz++] = a[i];
		}

		for (int i = 0; i < a.length; i++) {
			a[i].x += sx;
			a[i].y += sy;
		}

		return Arrays.copyOf(h, sz);
	}

	cf690B3() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		while (solve())
			;
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new cf690B3();
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