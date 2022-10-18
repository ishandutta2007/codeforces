import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class D {

	static class Point {
		int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public String toString() {
			return "(" + x + ", " + y + ")";
		}
	}

	void submit() {
		int n = nextInt();
		int nn = n;
		Point[] a = new Point[n];
		long sx = 0;
		long sy = 0;
		for (int i = 0; i < n; i++) {
			int x = nextInt() * 2;
			int y = nextInt() * 2;
			a[i] = new Point(x, y);
			sx += x;
			sy += y;
		}
		
		boolean[] mark = new boolean[n];

		for (int i = 0; i < n; i++) {
			long ix = 2 * sx - (long)n * a[i].x;
			long iy = 2 * sy - (long)n * a[i].y;
			for (int j = i; j < n; j++) {
				if ((long)n * a[j].x == ix && (long)n * a[j].y == iy) {
					mark[j] = mark[i] = true;
					break;
				}
			}
		}

		{
			Point[] b = new Point[n];
			int ptr = 0;
			for (int i = 0; i < n; i++) {
				if (!mark[i]) {
					b[ptr++] = a[i];
				}
			}
			a = Arrays.copyOf(b, ptr);
		}
		
		n = a.length;
		
		if (n == 0) {
			out.println(-1);
			return;
		}
		
		BigInteger[] dx = new BigInteger[n];
		BigInteger[] dy = new BigInteger[n];
		
		for (int i = 0; i < n; i++) {
			int mx = (a[0].x + a[i].x) / 2;
			int my = (a[0].y + a[i].y) / 2;
			dx[i] = b((long)nn * my - sy);
			dy[i] = b(sx - (long)nn * mx);
		}

		BigInteger[] p = new BigInteger[n];
		
		int ans = 0;
		
		outer: for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (dx[i].multiply(dy[j]).equals(dy[i].multiply(dx[j]))) {
					continue outer;
				}
			}
			for (int j = 0; j < n; j++) {
				p[j] = dx[i].multiply(b(a[j].x)).add(dy[i].multiply(b(a[j].y)));
			}
			Arrays.sort(p);
			BigInteger sum = p[0].add(p[n - 1]);
			for (int p1 = 1, p2 = n - 2; p1 <= p2; p1++, p2--) {
				if (!p[p1].add(p[p2]).equals(sum)) {
					continue outer;
				}
			}
			ans++;
		}
		out.println(ans);
	}

	BigInteger b(long x) {
		return BigInteger.valueOf(x);
	}
	
	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	D() throws IOException {
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
		new D();
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