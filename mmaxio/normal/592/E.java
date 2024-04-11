import java.io.*;
import java.util.*;

public class cf328E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Point implements Comparable<Point> {
		int x, y, side;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
			side = y == 0 ? (x > 0 ? -1 : 1) : (y > 0 ? -1 : 1);
		}

		@Override
		public int compareTo(Point o) {
			if (side != o.side) {
				return side < o.side ? -1 : 1;
			}
			return -vectProd(o);
		}

		public int vectProd(Point o) {
			return Long.signum((long) x * o.y - (long) y * o.x);
		}

	}

	void solve() throws IOException {
		int n = nextInt();
		int x0 = nextInt();
		int y0 = nextInt();
		Point[] a = new Point[n];

		for (int i = 0; i < n; i++) {
			int x = nextInt() - x0;
			int y = nextInt() - y0;
			a[i] = new Point(x, y);
		}

		Arrays.sort(a);
		if (a[0].vectProd(a[n - 1]) == 0) {
			out.println(0);
			return;
		}
		int cnt = 0;
		long tot = 0;
		for (int i = 0, j = 1; i < n; i++) {
			int same = 0;
			if (i == 0 || a[i].compareTo(a[i - 1]) != 0) {
				int k = i + 1;
				while (k < n && a[i].compareTo(a[k]) == 0) {
					k++;
				}
				same = k - i;
			}
			if (i == j) {
				if (cnt != -1) {
					throw new AssertionError();
				}
				j = (j + 1 == n ? 0 : j + 1);
				cnt++;
			}
			int tmp = 0;
			while (j != i) {
				int cmp = a[i].vectProd(a[j]);
				if (cmp < 0 || (cmp == 0 && j < i && a[i].side == a[j].side)) {
					break;
				}
				if (cmp == 0 && a[i].side != a[j].side) {
					tmp++;
				}
				j = (j + 1 == n ? 0 : j + 1);
				cnt++;
			}
			tot += (long) cnt * (cnt - 1) / 2;
			if (a[i].side == -1) {
				tot -= (long) same * tmp * (tmp - 1) / 2 + (long) same
						* (same - 1) * tmp / 2;
			}
			cnt--;
		}
		long ret = (long) n * (n - 1) * (n - 2) / 6 - tot;
		out.println(ret);
	}

	cf328E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new cf328E();
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