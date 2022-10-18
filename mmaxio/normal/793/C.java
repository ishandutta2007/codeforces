import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static class Frac implements Comparable<Frac> {
		long num, denom;

		public Frac(long num, long denom) {
			if (denom == 0) {
				throw new AssertionError();
			}
			
			if (denom < 0) {
				denom = -denom;
				num = -num;
			}
			
			this.num = num;
			this.denom = denom;
		}

		@Override
		public int compareTo(Frac o) {
			return Long.compare(num * o.denom, o.num * denom);
		}
	}
	
	Frac low = new Frac(0, 1);
	Frac high = new Frac(1_000_000, 1);
	
	void update(int x0, int dx, int a) {
		// x0 + dx * t > a
		if (dx == 0) {
			if (x0 <= a) {
				high = new Frac(0, 1);
			}
			return;
		}
		
		if (dx > 0) {
			// t > (a - x0) / dx
			Frac now = new Frac(a - x0, dx);
			if (now.compareTo(low) > 0) {
				low = now;
			}
			return;
		}
		
		if (dx < 0) {
			// x0 - a > (-dx) * t
			// t < (x0 - a) / (-dx)
			Frac now = new Frac(x0 - a, -dx);
			if (now.compareTo(high) < 0) {
				high = now;
			}
			return;
		}
		
		throw new AssertionError();
		
	}

	void solve() throws IOException {
		int n = nextInt();
		int x1 = nextInt();
		int y1 = nextInt();
		int x2 = nextInt();
		int y2 = nextInt();
		
		for (int i = 0; i < n; i++) {
			int x0 = nextInt();
			int y0 = nextInt();
			int dx = nextInt();
			int dy = nextInt();
			
			update(x0, dx, x1);
			update(-x0, -dx, -x2);
			
			update(y0, dy, y1);
			update(-y0, -dy, -y2);
		}
		
		if (low.compareTo(high) < 0) {
			out.println(1.0 * low.num / low.denom);
		} else {
			out.println(-1);
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