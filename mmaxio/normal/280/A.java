import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Point implements Comparable<Point>{
		double x, y;

		public Point(double x, double y) {
			this.x = x;
			this.y = y;
		}

		public Point rotate(double alph) {
			return new Point(x * Math.cos(alph) - y * Math.sin(alph), x
					* Math.sin(alph) + y * Math.cos(alph));
		}

		@Override
		public int compareTo(Point o) {
			if (cmp(y, o.y) != 0)
				return cmp(y, o.y);
			return cmp(x, o.x);
		}
		
		double vectMul(Point p) {
			return x * p.y - y * p.x;
		}

		@Override
		public String toString() {
			return "(" + x + ", " + y + ")";
		}
		
		
	}

	static class Line {
		double A, B, C;

		public Line(Point P, Point Q) {
			A = Q.y - P.y;
			B = P.x - Q.x;
			C = -A * P.x - B * P.y;
		}

		Point intersect(Line p) {
			double D = A * p.B - B * p.A;
			if (eqZero(D))
				return null;
			double x = C * p.B - B * p.C;
			double y = A * p.C - C * p.A;
			return new Point(-x / D, -y / D);
		}

	}

	static boolean eqZero(double d) {
		return Math.abs(d) < EPS;
	}

	static final double EPS = 1e-7;
	
	static int getTurn(Point A, Point B, Point C) {
		// angle between AB and AC
		double p1 = (B.x - A.x) * (C.y - A.y);
		double p2 = (B.y - A.y) * (C.x - A.x);
		return cmp(p1, p2);
	}
	
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

		double sx = a[0].x;
		double sy = a[0].y;

		for (int i = 0; i < a.length; i++) {
			a[i].x -= sx;
			a[i].y -= sy;
		}

		Arrays.sort(a, 1, a.length, new Comparator<Point>() {

			@Override
			public int compare(Point o1, Point o2) {
				if (o1.equals(o2))
					return 0;
				double val = o1.vectMul(o2);
				if (val != 0)
					return val > 0 ? -1 : 1;
				if (o1.y == 0) {
					return o1.x < o2.x ? -1 : 1;
				} else {
					return o1.y < o2.y ? -1 : 1;
				}
			}
		});

		ArrayList<Point> hAL = new ArrayList<Point>();
		hAL.add(a[0]);
		for (int i = 1; i < a.length; i++) {
			if (a[i].equals(hAL.get(hAL.size() - 1)))
				continue;
			while (hAL.size() > 1
					&& getTurn(hAL.get(hAL.size() - 2),
							hAL.get(hAL.size() - 1), a[i]) <= 0)
				hAL.remove(hAL.size() - 1);
			hAL.add(a[i]);
		}

		for (int i = 0; i < a.length; i++) {
			a[i].x += sx;
			a[i].y += sy;
		}

		Point[] h = new Point[hAL.size()];
		for (int i = 0; i < h.length; i++) {
			h[i] = hAL.get(i);
		}

		return h;
	}

	Point getInter(Point a, Point b, Point c, Point d) {
		
//		System.err.println(a + " " + b);
//		System.err.println(c + " " + d);
		
		Line A = new Line(a, b);
		Line B = new Line(c, d);
		Point res = A.intersect(B);
		
//		System.err.println(res);
//		System.err.println();
		
		if (res == null)
			return null;

		if (isInside(res.x, a.x, b.x) && isInside(res.y, a.y, b.y)) {
			return res;
		}
		
		return null;
	}
	
	static boolean isInside(double val, double x, double y) {
//		System.err.println(val + " " + x + " " + y);
		if (x > y) {
			double tmp = x;
			x = y;
			y = tmp;
		}
		return cmp(val, x) >= 0 && cmp(val, y) <= 0;
	}
	
	static int cmp(double a, double b) {
		if (eqZero(a - b))
			return 0;
		return Double.compare(a, b);
	}

	void solve() throws IOException {
		double w = nextInt() * 0.5;
		double h = nextInt() * 0.5;
		double ang = nextInt() / 180.0 * Math.PI;

		Point[] r1 = { new Point(w, h), new Point(-w, h), new Point(-w, -h),
				new Point(w, -h) };

		Point[] r2 = new Point[4];
		for (int i = 0; i < 4; i++) {
			r2[i] = r1[i].rotate(ang);
		}

		ArrayList<Point> a = new ArrayList<>();
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				Point tmp = getInter(r1[i], r1[(i + 1) % 4], r2[j],
						r2[(j + 1) % 4]);
				if (tmp != null)
					a.add(tmp);
			}
		
		Point[] d = convexHull((Point[]) a.toArray(new Point[a.size()]));
		
		double ans = 0;
		
		for (int i = 0; i < d.length - 1; i++) {
			ans += d[i].vectMul(d[i + 1]);
		}
		
		ans += d[d.length - 1].vectMul(d[0]);
		out.printf("%.12f\n", ans * 0.5);
		
		
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
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