import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Point implements Comparable<Point> {
		int x, y;
		int id;

		int getSide() {
			if (y != 0) {
				return y > 0 ? -1 : 1;
			}
			return x > 0 ? -1 : 1;
		}

		int angleCompare(Point o) {
			if (getSide() != o.getSide()) {
				return getSide();
			}
			return -Long.signum((long) x * o.y - (long) y * o.x);
		}

		@Override
		public int compareTo(Point o) {
			int tmp = angleCompare(o);
			if (tmp != 0) {
				return tmp;
			}
			return Long.compare(sqLen(), o.sqLen());
		}

		long sqLen() {
			return (long) x * x + (long) y * y;
		}

		public Point(int x, int y, int id) {
			this.x = x;
			this.y = y;
			this.id = id;
		}

		@Override
		public int hashCode() {
			return id;
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
			if (id != other.id)
				return false;
			return true;
		}

	}
	
	int[][] prev;

	void solve() throws IOException {
		int k = nextInt();
		int n = nextInt();
		Point[] a = new Point[k];
		Point[] b = new Point[n];

		for (int i = 0; i < k; i++) {
			a[i] = new Point(nextInt(), nextInt(), i);
		}

		for (int i = 0; i < n; i++) {
			b[i] = new Point(nextInt(), nextInt(), i);
		}

		prev = new int[k][n];


		for (int i = 0; i < k; i++) {
			for (int j = 0; j < n; j++) {
				b[j].x -= a[i].x;
				b[j].y -= a[i].y;

			}

			Arrays.sort(b);

			Arrays.fill(prev[i], -1);

			for (int j = 0; j < n;) {
				int j1 = j;
				while (j1 < n && b[j].angleCompare(b[j1]) == 0) {
					j1++;
				}

				while (j + 1 < j1) {
					prev[i][b[j + 1].id] = b[j].id;
					j++;
				}

				j = j1;
			}

			for (int j = 0; j < n; j++) {
				b[j].x += a[i].x;
				b[j].y += a[i].y;
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			Set<Integer> set = new HashSet<>();
			set.add(b[i].id);
			if (can(set, (1 << k) - 1, k)) {
				ans++;
			}
		}
		out.println(ans);
	}
	
	boolean can(Set<Integer> set, int mask, int k) {
		if (set.isEmpty()) {
			return true;
		}
		int canKill = Integer.bitCount(mask);
		for (int last = 0; last < k; last++) {
			if (!test(mask, last)) {
				continue;
			}
			outer: for (int p : set) {
				Set<Integer> nxt = new HashSet<>(set);
				nxt.remove(p);
				while (prev[last][p] != -1) {
					nxt.add(prev[last][p]);
					if (nxt.size() > canKill - 1) {
						continue outer;
					}
					p = prev[last][p];
				}
				if (can(nxt, mask ^ (1 << last), k)) {
					return true;
				}
			}
		}
		return false;
	}

	boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
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