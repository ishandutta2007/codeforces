import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Point {
		int x, y;

		@Override
		public int hashCode() {
			return x * 1235768 + y * 8636123;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			Point other = (Point) obj;
			return x == other.x && y == other.y;
		}

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	Comparator<Point> byX = new Comparator<Point>() {

		@Override
		public int compare(Point o1, Point o2) {
			if (o1.x != o2.x) {
				return Integer.compare(o1.x, o2.x);
			}
			return Integer.compare(o1.y, o2.y);
		}
	};

	Comparator<Point> byY = new Comparator<Point>() {

		@Override
		public int compare(Point o1, Point o2) {
			if (o1.y != o2.y) {
				return Integer.compare(o1.y, o2.y);
			}
			return Integer.compare(o1.x, o2.x);
		}
	};

	void solve() throws IOException {
		int n = nextInt();
		Point[] ax = new Point[n];
		Set<Point> set = new HashSet<>();
		for (int i = 0; i < n; i++) {
			ax[i] = new Point(nextInt(), nextInt());
			set.add(ax[i]);
		}
		
		Point[] ay = ax.clone();
		Arrays.sort(ax, byX);
		Arrays.sort(ay, byY);
		
		Point tmp = new Point(0, 0);
		
		long ans = 0;
		
		for (int ix = 0; ix < n; ix++) {
			Point cur = ax[ix];
			int x1 = cur.x;
			int y1 = cur.y;
			int iy = Arrays.binarySearch(ay, cur, byY);
			
			tmp.x = x1;
			tmp.y = INF;
			int jx = ~Arrays.binarySearch(ax, tmp, byX);
			
			tmp.x = INF;
			tmp.y = y1;
			int jy = ~Arrays.binarySearch(ay, tmp, byY);
			
			if (jx - ix < jy - iy) {
				for (int k = ix + 1; k < jx; k++) {
					Point p = ax[k];
					int y2 = p.y;
					int x2 = x1 + (y2 - y1);
					tmp.x = x2;
					tmp.y = y1;
					if (set.contains(tmp)) {
						tmp.y = y2;
						if (set.contains(tmp)) {
							ans++;
						}
					}
				}
			} else {
				for (int k = iy + 1; k < jy; k++) {
					Point p = ay[k];
					int x2 = p.x;
					int y2 = y1 + (x2 - x1);
					tmp.x = x1;
					tmp.y = y2;
					if (set.contains(tmp)) {
						tmp.x = x2;
						if (set.contains(tmp)) {
							ans++;
						}
					}
				}
			}
		}
		
		out.println(ans);

	}
	
	static final int INF = 100001;

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