import java.io.*;
import java.util.*;

public class E {

	static class Factory implements Comparable<Factory> {
		int x, y;
		int cnt;
		long newY;

		int ix;

		public Factory(int x, int y, int cnt) {
			this.x = x;
			this.y = y;
			this.cnt = cnt;
		}

		void setNewY(long a, long b) {
			newY = a * x + b * y;
		}

		@Override
		public int compareTo(Factory o) {
			return Long.compare(newY, o.newY);
		}
	}

	static class Point {
		int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		Point plus(Point p) {
			return new Point(x + p.x, y + p.y);
		}

		@Override
		public String toString() {
			return "(" + x + ", " + y + ")";
		}

	}

	static Comparator<Point> byYThenX = Comparator.comparingInt(
			(Point p) -> p.y).thenComparingInt(p -> p.x);

	static Comparator<Point> byPolar = Comparator
			.comparing(
					(Point p) -> p.y == 0 ? -Integer.signum(p.x) : -Integer
							.signum(p.y)).thenComparing(
					(p1, p2) -> -Long.signum((long) p1.x * p2.y - (long) p1.y
							* p2.x));

	<T> T min(T a, T b, Comparator<T> comp) {
		return comp.compare(a, b) < 0 ? a : b;
	}

	int n, q;
	Factory[] fact;
	Point[] exh;
	int[] scale;

	int[] factX;

	int[] unique(int[] a) {
		Arrays.sort(a);
		int sz = 1;
		for (int i = 1; i < a.length; i++) {
			if (a[i] != a[sz - 1]) {
				a[sz++] = a[i];
			}
		}
		return Arrays.copyOf(a, sz);
	}

	long[] ans;

	void submit() {
		int k = nextInt();
		n = nextInt();
		q = nextInt();

		Point origin = new Point(0, 0);
		Point[] vecs = new Point[2 * k];
		for (int i = 0; i < k; i++) {
			int x = nextInt();
			int y = nextInt();
			vecs[2 * i] = new Point(2 * x, 2 * y);
			vecs[2 * i + 1] = new Point(-2 * x, -2 * y);

			origin = origin.plus(min(new Point(x, y), new Point(-x, -y),
					byYThenX));
		}

		Arrays.sort(vecs, byPolar);
		Point[] a = new Point[2 * k];
		for (int i = 0; i < 2 * k; i++) {
			a[i] = origin;
			origin = origin.plus(vecs[i]);
		}

		fact = new Factory[n];
		factX = new int[n];
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			int y = nextInt();
			int cnt = nextInt();
			fact[i] = new Factory(x, y, cnt);
			factX[i] = x;
		}

		factX = unique(factX);
		for (Factory f : fact) {
			f.ix = Arrays.binarySearch(factX, f.x);
		}

		exh = new Point[q];
		scale = new int[q];
		for (int i = 0; i < q; i++) {
			int x = nextInt();
			int y = nextInt();
			scale[i] = nextInt();
			exh[i] = new Point(x, y);
		}

		ans = new long[q];

		for (int i = 0; i < 2 * k; i++) {
			int j = (i + 1) % (2 * k);
			if (a[i].x == a[j].x) {
				continue;
			}
			if (a[i].x > a[j].x) {
				go(a[j], a[i], 1, false);
			} else {
				go(a[i], a[j], -1, false);
			}
		}

		int maxX = Integer.MIN_VALUE;
		for (Point p : a) {
			maxX = Math.max(maxX, p.x);
		}

		int minY = Integer.MAX_VALUE;
		int maxY = Integer.MIN_VALUE;
		for (Point p : a) {
			if (p.x == maxX) {
				minY = Math.min(minY, p.y);
				maxY = Math.max(maxY, p.y);
			}
		}

		go(new Point(maxX, maxY), new Point(maxX + 1, maxY), 1, true);
		go(new Point(maxX, minY), new Point(maxX + 1, minY), -1, true);
		
		for (long x : ans) {
			out.println(x);
		}
	}

	static class Query implements Comparable<Query> {
		int fromX, toX; // [from; to)
		long y;
		int id;

		public Query(int fromX, int toX, long y, int id) {
			this.fromX = fromX;
			this.toX = toX;
			this.y = y;
			this.id = id;
		}

		@Override
		public int compareTo(Query o) {
			return Long.compare(y, o.y);
		}
	}

	void go(Point l, Point r, int sign, boolean rightBorder) {
		long A = l.y - r.y;
		long B = r.x - l.x;
		// should be +oo at (0; +oo)

		for (Factory f : fact) {
			f.setNewY(A, B);
		}

		Query[] qs = new Query[q];
		for (int i = 0; i < q; i++) {

			int xl = exh[i].x + scale[i] * l.x;
			int xr = rightBorder ? (xl + 1) : (exh[i].x + scale[i] * r.x);
			long y = A * (exh[i].x + scale[i] * l.x) + B
					* (exh[i].y + scale[i] * l.y);
			qs[i] = new Query(xl, xr, y + (sign == 1 ? 0 : -1), i);
		}

		Arrays.sort(fact);
		Arrays.sort(qs);

		long[] fen = new long[factX.length];
		int ptr = 0;
		for (Query qry : qs) {
			while (ptr < n && fact[ptr].newY <= qry.y) {
				add(fen, fact[ptr].ix, fact[ptr].cnt);
				ptr++;
			}

			int nowFromX = Arrays.binarySearch(factX, qry.fromX);
			if (nowFromX < 0) {
				nowFromX = -nowFromX - 1;
			}

			int nowToX = Arrays.binarySearch(factX, qry.toX);
			if (nowToX < 0) {
				nowToX = -nowToX - 2;
			} else {
				nowToX = nowToX - 1;
			}

			if (nowFromX <= nowToX) {
				ans[qry.id] += sign * get(fen, nowFromX, nowToX);
			}
		}
	}
	
	void add(long[] fen, int pos, long delta) {
		for (int i = pos; i < fen.length; i |= i + 1) {
			fen[i] += delta;
		}
	}
	
	long get(long[] fen, int from, int to) {
		return get(fen, to) - get(fen, from - 1);
	}
	
	long get(long[] fen, int pos) {
		long ret = 0;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
			ret += fen[i];
		}
		return ret;
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new E();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}