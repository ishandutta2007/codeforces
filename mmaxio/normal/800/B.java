import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Point {
		int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
		
		Point to(Point p) {
			return new Point(p.x - x, p.y - y);
		}
		
		long cross(Point p) {
			return (long)x * p.y - (long)y * p.x;
		}
		
		long sqLen() {
			return (long)x * x + (long)y * y;
		}
	}
	
	double dist(Point A, Point P, Point Q) {
		// from A to PQ
		return A.to(P).cross(A.to(Q)) / Math.sqrt(P.to(Q).sqLen());
	}
	
	void solve() throws IOException {
		int n = nextInt();
		Point[] a = new Point[n];
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			int y = nextInt();
			a[i] = new Point(x, y);
		}
		
		double ans = 1e100;
		for (int i = 0; i < n; i++) {
			Point A = a[i];
			Point P = a[(i + n - 1) % n];
			Point Q = a[(i + 1) % n];
			ans = Math.min(ans, dist(A, P, Q) * .5);
		}
		
		out.println(ans);
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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