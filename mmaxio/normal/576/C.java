import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Point implements Comparable<Point> {
		int x, y;
		int xBin;

		int id;

		public Point(int x, int y, int id) {
			this.x = x;
			this.y = y;
			this.id = id;
			xBin = x / 1000;
		}

		@Override
		public int compareTo(Point o) {
			if (xBin != o.xBin) {
				return xBin < o.xBin ? -1 : 1;
			}
			return (xBin % 2 == 0 ? 1 : -1) * Integer.compare(y, o.y);
		}

	}

	void solve() throws IOException {
		int n = nextInt();
		Point[] a = new Point[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Point(nextInt(), nextInt(), i);
		}
		Arrays.sort(a);
		
		long dist = 0;
		for (int i = 0; i < n - 1; i++) {
			dist += Math.abs(a[i].x - a[i + 1].x) + Math.abs(a[i].y - a[i + 1].y);
		}
		
		if (dist > 2_500_000_000L) {
			throw new AssertionError();
		}
		
		for (int i = 0; i < n; i++) {
			out.print(a[i].id + 1 + " ");
		}
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