import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	static class Point {
		long x;
		long y;

		public Point(long x, long y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + (int) (x ^ (x >>> 32));
			result = prime * result + (int) (y ^ (y >>> 32));
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Point other = (Point) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}
	}

	void solve() throws IOException {
		int n = nextInt();

		long[] x = new long[n];
		long[] y = new long[n];
		long[] det = new long[n];
		
		int cntZero = 0;
		
		int[] cs = new int[n];
		

		for (int i = 0; i < n; i++) {
			int a = nextInt();
			int b = nextInt();
			int c = nextInt();
			cs[i] = c;
			cntZero += (c == 0 ? 1 : 0);
			x[i] = a * c;
			y[i] = b * c;
			det[i] = a * a + b * b;
		}
		
		HashMap<Point, Integer> tmp = new HashMap<>();

		long ans = 0;

		for (int i = 0; i < n; i++) {
			tmp.clear();
			
//			System.err.println("!");
			boolean bad = false;

			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}
				if (cs[j] == 0) {
					if (bad) {
						continue;
					}
					bad = true;
				}
				long dx = x[i] * det[j] - x[j] * det[i];
				long dy = y[i] * det[j] - y[j] * det[i];

				long g = gcd(Math.abs(dx), Math.abs(dy));
				if (g == 0) {
					continue;
				}
				dx /= g;
				dy /= g;
				if (dx < 0 || (dx == 0 && dy < 0)) {
					dx = -dx;
					dy = -dy;
				}

				Point z = new Point(dx, dy);

				int prev = tmp.getOrDefault(z, 0);
				ans += prev;
				tmp.put(z, prev + 1);
			}
		}
		
		ans /= 3;
		
		if (cntZero == 2) {
			ans += n - 2;
		}

		out.println(ans);

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