import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Vector implements Comparable<Vector> {
		int x, y;

		public Vector(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Vector o) {
			if (x != o.x) {
				return x > o.x ? -1 : 1;
			}
			return -Integer.compare(y, o.y);
		}

		long vectProd(Vector o) {
			return (long) x * o.y - (long) y * o.x;
		}
	}
	
	boolean bad(Vector a, Vector b, Vector c) {
		int x1 = b.x - a.x;
		int y1 = b.y - a.y;
		int x2 = c.x - a.x;
		int y2 = c.y - a.y;
		return (long)x1 * y2 <= (long)x2 * y1;
	}

	void solve() throws IOException {
		int n = nextInt();
		int needX = nextInt();
		int needY = nextInt();

		Vector[] a = new Vector[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Vector(nextInt(), nextInt());
		}

		Arrays.sort(a);

		Vector[] hull = new Vector[n];
		hull[0] = a[0];
		int hullSz = 1;
		for (int i = 1; i < n; i++) {
			while (hullSz > 1 && bad(hull[hullSz - 2], hull[hullSz - 1], a[i])) {
				hullSz--;
			}
			hull[hullSz++] = a[i];
		}

		double ans = 1e100;

		for (int i = 0; i < hullSz; i++) {
			ans = Math.min(ans,
					Math.max(1.0 * needX / hull[i].x, 1.0 * needY / hull[i].y));
		}

		Vector tmp = new Vector(needX, needY);

		if (hull[0].vectProd(tmp) > 0 && hull[hullSz - 1].vectProd(tmp) < 0) {

			int i = 0;
			while (hull[i].vectProd(tmp) >= 0) {
				i++;
			}

//			 System.err.println(hullSz);
			// System.err.println(i);

			long A = hull[i].y - hull[i - 1].y;
			long B = hull[i - 1].x - hull[i].x;
			long C = A * hull[i].x + B * hull[i].y;
			
			// Ax + By = C
			
			double t = 1.0 * C / (A * needX + B * needY);
			
//			System.err.println(A + " " + B + " " + C);
//			System.err.println(t);
			
			ans = Math.min(ans, 1 / t);
		}

		out.println(ans);
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