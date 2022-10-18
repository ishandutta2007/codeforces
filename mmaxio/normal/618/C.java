import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Point implements Comparable<Point>{
		int x, y, id;

		public Point(int x, int y, int id) {
			this.x = x;
			this.y = y;
			this.id = id;
		}

		@Override
		public int compareTo(Point o) {
			if (x != o.x) {
				return x < o.x ? -1 : 1;
			}
			return Integer.compare(y, o.y);
		}

	}

	static long det(Point a, Point b, Point c) {
		long x1 = b.x - a.x;
		long y1 = b.y - a.y;
		long x2 = c.x - a.x;
		long y2 = c.y - a.y;
		return x1 * y2 - x2 * y1;
	}

	void solve() throws IOException {
		int n = nextInt();
		Point[] a = new Point[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Point(nextInt(), nextInt(), i + 1);
		}

		Arrays.sort(a);
		
		long A = a[0].y - a[1].y;
		long B = a[1].x - a[0].x;
		long C = -A * a[0].x - B * a[0].y;
		
		long min = Long.MAX_VALUE;
		int ans = -1;

		for (int i = 2; i < n; i++) {
				
				long tmp = Math.abs(A * a[i].x + B * a[i].y + C);
				if (tmp == 0) {
					continue;
				}
				if (tmp < min) {
					min = tmp;
					ans = i;
				}
				
		}
		
		out.println(a[0].id + " " + a[1].id + " " + a[ans].id);

	}

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