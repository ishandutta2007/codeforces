import java.io.*;
import java.util.*;

public class cfEdu1F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	/**
	 * @return x * 10^afterDot, where x is a value of number represented by
	 *         <i>s</i>
	 * @throws IllegalArgumentException
	 *             - if there are more than <i>afterDot</i> digits after the dot
	 *             Overflows are not handled at all.
	 */
	static long parseDecimal(String s, int afterDot) {
		if (s.charAt(0) == '-') {
			return -parseDecimal(s.substring(1), afterDot);
		}
		int dot = s.indexOf('.');
		long p10 = 1;
		for (int i = 0; i < afterDot; i++) {
			p10 *= 10;
		}
		if (dot == -1) {
			return Long.parseLong(s) * p10;
		}
		long whole = Long.parseLong(s.substring(0, dot));
		long frac = Long.parseLong(s.substring(dot + 1));
		int len = s.length() - dot - 1;
		if (len > afterDot) {
			throw new IllegalArgumentException("Too many digis after the dot");
		}
		while (len < afterDot) {
			len++;
			frac *= 10;
		}
		return whole * p10 + frac;
	}

	static class Point {
		int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
		
		long kindaDist(Point p, Point q) {
			return (long)(p.x - x) * (q.y - y) - (long)(q.x - x) * (p.y - y);
		}
	}

	static int getTurn(Point o, Point p, Point q) {
		return Long.signum(o.kindaDist(p, q));
	}

	static long vectProd(Point a, Point b) {
		return (long) a.x * b.y - (long) a.y * b.x;
	}

	static final double EPS = 1e-9;

	static int comp(double x, double y) {
		return Math.abs(x - y) < EPS ? 0 : (x < y ? -1 : 1);
	}

	static class Event implements Comparable<Event> {
		double t;
		int type; // 0 -> cross, -1/1 - from corresponding side to edge

		@Override
		public int compareTo(Event arg0) {
			return Double.compare(t, arg0.t);
		}

		private Event(int side1, int side2) {
			type = side1 + side2;
		}

		public Event(Point a, Point b, Point p, Point q, int side1,
				int side2) {
			this(side1, side2);
			long vp = p.kindaDist(a, b);
			long vq = q.kindaDist(b, a);
			t = 1.0 * vp / (vp + vq);
		}

		public Event(Point o, Point v, Point p, int side1, int side2) {
			this(side1, side2);
			if (v.x == 0) {
				t = 1.0 * (p.y - o.y) / v.y;
			} else {
				t = 1.0 * (p.x - o.x) / v.x;
			}
		}
	}

	double go(Point[] a, int n, Point p, Point q) {
		Point v = new Point(q.x - p.x, q.y - p.y);
		int[] side = new int[n + 2];
		for (int i = 0; i < n + 2; i++) {
			side[i] = getTurn(p, q, a[i]);
		}
		List<Event> evs = new ArrayList<>();
		for (int i = 1; i <= n; i++) {
			if (side[i] * side[i + 1] == -1) {
				evs.add(new Event(a[i], a[i + 1], p, q, side[i], side[i + 1]));
			}
			if (side[i] == 0 && side[i - 1] != side[i + 1]) {
				evs.add(new Event(p, v, a[i], side[i - 1], side[i + 1]));
			}
		}

		double ans = 0;

		Collections.sort(evs);
		boolean curIn = false;
		int edgeState = 0; // 0 -> not on edge, -1/1 -> on edge from
							// corresponding side
		for (int i = 0; i < evs.size(); i++) {
			Event e = evs.get(i);
			if (edgeState != 0 || curIn) {
				ans += e.t - evs.get(i - 1).t;
			}
			if (edgeState == 0) {
				if (e.type == 0) {
					curIn ^= true;
				} else {
					edgeState = e.type;
				}
			} else {
				if (e.type == 0) {
					throw new AssertionError();
				} else {
					curIn ^= (e.type != edgeState);
					edgeState = 0;
				}
			}
		}
		return ans * Math.sqrt((long)v.x * v.x + (long)v.y * v.y);
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();

		Point[] a = new Point[n + 2];
		for (int i = 1; i <= n; i++) {
			int x = (int) parseDecimal(nextToken(), 2);
			int y = (int) parseDecimal(nextToken(), 2);
			a[i] = new Point(x, y);
		}
		a[0] = a[n];
		a[n + 1] = a[1];

		for (int i = 0; i < m; i++) {
			int x1 = (int) parseDecimal(nextToken(), 2);
			int y1 = (int) parseDecimal(nextToken(), 2);
			int x2 = (int) parseDecimal(nextToken(), 2);
			int y2 = (int) parseDecimal(nextToken(), 2);
			out.println(go(a, n, new Point(x1, y1), new Point(x2, y2)) / 100);
		}
	}

	cfEdu1F() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new cfEdu1F();
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