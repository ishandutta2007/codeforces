import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	class Point {
		double x, y;

		public Point(double x, double y) {
			this.x = x;
			this.y = y;
		}

		Point mult(double len) {
			return new Point(x * len, y * len);
		}

		Point add(Point p) {
			return new Point(x + p.x, y + p.y);
		}

		double len() {
			return Math.sqrt(x * x + y * y);
		}

	}
	
	double dist(Point a, Point b) {
		return Math.sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	}
	
	static final double EPS = 1e-3;

	void solve() throws IOException {
		int n = nextInt();
		if (n <= 4) {
			out.println("No solution");
			return;
		}

		Point[] a = new Point[n];
		Random rng = new Random();

		BIG: while (true) {
			a[0] = new Point(0, 0);

			int[] len = new int[2 * (n - 2)];
			for (int i = 0; i < len.length; i++) {
				int j = rng.nextInt(i + 1);
				len[i] = len[j];
				len[j] = i + 1;
			}

			for (int i = 0; i < n - 2; i++) {

				Point dir = new Point(Math.cos(2 * Math.PI / n * i), Math.sin(2
						* Math.PI / n * i));

				a[i + 1] = a[i].add(dir.mult(len[i]));
			}

			double c1 = -a[n - 2].x;
			double c2 = -a[n - 2].y;
			double a1 = Math.cos(2 * Math.PI / n * (n - 2));
			double b1 = Math.cos(2 * Math.PI / n * (n - 1));
			double a2 = Math.sin(2 * Math.PI / n * (n - 2));
			double b2 = Math.sin(2 * Math.PI / n * (n - 1));

			// a1 * x + b1 * y = c1

			double det = a1 * b2 - a2 * b1;
			double x = c1 * b2 - c2 * b1;
			double y = a1 * c2 - a2 * c1;

			x /= det;
			y /= det;

			a[n - 1] = a[n - 2].add(new Point(Math.cos(2 * Math.PI / n
					* (n - 2)), Math.sin(2 * Math.PI / n * (n - 2))).mult(x));

//			System.err.println(x + " " + y);
			if (x < 0.1 || y < 0.1)
				continue;
			if (x >= 1000 || y >= 1000)
				continue;
			
			double mult = 1;

			if (Math.min(x, y) < 1.01) {
				mult = Math.min(1000 / Math.max(x, y), 1000.0 / (n - 2)) * 0.5;
				if (Math.min(x, y) * mult < 1.01)
					continue;
				
			}
			
			for (int i = 0; i < n; i++) {
				a[i] = a[i].mult(mult);
			}
			
			double[] sides = new double[n];
			for (int i = 0; i < n - 1; i++)
				sides[i] = dist(a[i], a[i + 1]);
			sides[n - 1] = dist(a[n - 1], a[0]);
			
			for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++)
					if (Math.abs(sides[i] - sides[j]) < EPS) {
						continue BIG;
					}

			break;
		}
//		for (int i = 0; i < n - 1; i++) {
//			System.err.print(dist(a[i], a[i + 1]) + " ");
//		}
//		System.err.println(dist(a[n - 1], a[0]));
//		
//		System.err.print(angle(a[0], a[n - 1], a[1]) + " ");
//		for (int i = 1; i < n - 1; i++)
//			System.err.print(angle(a[i], a[i - 1], a[i + 1]) + " ");
//		System.err.println(angle(a[n - 1], a[n - 2], a[0]));

		for (int i = 0; i < n; i++) {
			out.printf(Locale.US, "%.9f %.9f\n", a[i].x, a[i].y);
		}

	}

	double angle(Point A, Point B, Point C) {
		// AB and AC
		Point AB = new Point(B.x - A.x, B.y - A.y);
		Point AC = new Point(C.x - A.x, C.y - A.y);
		
		double vectMul = AB.x * AC.y - AB.y * AC.x;
		return vectMul / AB.len() / AC.len();
	}

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