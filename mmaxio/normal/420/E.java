import java.io.*;
import java.util.*;
import static java.lang.Math.PI;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final double EPS = 1e-10;

	static class Point {
		int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		double len() {
			return Math.sqrt(x * x + y * y);
		}

		int sqLen() {
			return x * x + y * y;
		}
	}

	static class Circle {
		Point o;
		int r;

		public Circle(Point o, int r) {
			this.o = o;
			this.r = r;
		}
	}

	static boolean eq(double x, double y) {
		return Math.abs(x - y) < EPS;
	}

	static class Event implements Comparable<Event> {
		double angle;
		boolean start;

		public Event(double angle, boolean start) {
			this.angle = angle;
			this.start = start;
		}

		@Override
		public int compareTo(Event o) {
			if (o == this) {
				return 0;
			}
			if (!eq(angle, o.angle)) {
				return angle < o.angle ? -1 : 1;
			}
			if (start != o.start)
				return start ? -1 : 1;
			return 0;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int d = nextInt();

		Circle[] a = new Circle[n];

		for (int i = 0; i < n; i++) {
			int x = nextInt();
			int y = nextInt();
			int r = nextInt();
			a[i] = new Circle(new Point(x, y), r);
		}

		for (int i = 0; i < n; i++) {
			double dist = a[i].o.len();
			double lowR = dist - a[i].r;
			double highR = dist + a[i].r;
			
			int low = (int) Math.max((lowR - 20) / d, 1);
			
			for (int k = low; d * k <= highR + 20; k++) {
				go(a[i], d * k);
			}
		}
		
		int cur = 0;
		int best = 0;
		Collections.sort(evs);
		for (int i = 0; i < evs.size(); i++) {
			Event e = evs.get(i);
			if (e.start) {
				cur++;
				best = Math.max(best, cur);
			} else {
				cur--;
			}
		}
		
		out.println(best + always);

	}

	static int sq(int x) {
		return x * x;
	}

	int always = 0;
	
	List<Event> evs = new ArrayList<>();

	void go(Circle c, int r) {
		// doesn't intersect
		if (c.o.sqLen() > sq(r + c.r)) {
			return;
		}

		if (r > c.r && c.o.sqLen() < sq(r - c.r)) {
			// fully inside
			return;
		}

		if (r < c.r && c.o.sqLen() <= sq(r - c.r)) {
			always++;
			return;
		}

		double mid = Math.atan2(c.o.y, c.o.x);
		double delta = Math.acos((c.o.sqLen() + sq(r) - sq(c.r))
				/ (2 * c.o.len() * r));
		double low = mid - delta;
		double high = mid + delta;
		
		if (low < -PI) {
			evs.add(new Event(low + 2 * PI, true));
			evs.add(new Event(PI, false));
			evs.add(new Event(-PI, true));
			evs.add(new Event(high, false));
		} else if (high >= PI) {
			evs.add(new Event(low, true));
			evs.add(new Event(PI, false));
			evs.add(new Event(-PI, true));
			evs.add(new Event(high - 2 * PI, false));
		} else {
			evs.add(new Event(low, true));
			evs.add(new Event(high, false));
		}

	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E();
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