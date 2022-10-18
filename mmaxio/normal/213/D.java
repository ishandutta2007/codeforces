import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	class Vector {
		double x, y;

		public Vector(double x, double y) {
			this.x = x;
			this.y = y;
		}

		Vector rotate(double ang) {
			double s = Math.sin(ang);
			double c = Math.cos(ang);
			return new Vector(x * c - y * s, x * s + y * c);
		}

		Vector add(Vector v) {
			return new Vector(x + v.x, y + v.y);
		}

		Vector mult(double coef) {
			return new Vector(coef * x, coef * y);
		}

//		@Override
//		public String toString() {
//			//return "(" + x + ", " + y + ")";
//		}
		
		void print() {
			out.printf("%.12f %.12f\n", x, y);
		}

	}

	void solve() throws IOException {
		int n = nextInt();
		Vector[] side = new Vector[5];
		side[0] = new Vector(10, 0);
		double alpha = 2 * Math.PI / 5;
		for (int i = 1; i < 5; i++)
			side[i] = side[i - 1].rotate(alpha);

		out.println(4 * n + 1);

		Vector[] star = { side[0].add(side[1]), side[2].add(side[3]),
				side[4].add(side[0]), side[1].add(side[2]),
				side[3].add(side[4]) };

		Vector main = star[4].mult(-1);

		Vector cur = new Vector(0, 0);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 4; j++) {
				//out.println(cur);
				cur.print();
				cur = cur.add(star[j]);
			}
		
		//out.println(cur);
		cur.print();
		for (int i = 0; i < n; i++) {
			int x = 4 * i + 1;
			out.println(x + " " + (x + 3) + " " + (x + 1) + " " + (x + 4) + " " + (x + 2));
		}
		
		for (int i = 0; i < 4 * n + 1; i++)
			out.print((i + 1) + " ");
		for (int i = 4 * n - 4; i > 0; i -= 4)
			out.print((i + 1) + " ");
		out.println(1);

	}

	void inp() throws IOException {
		Locale.setDefault(Locale.US);
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D().inp();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	String nextString() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken("\n");
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