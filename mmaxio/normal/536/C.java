import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Man implements Comparable<Man> {
		long x, y;
		int id;

		public Man(long x, long y, int id) {
			this.x = x;
			this.y = y;
			this.id = id;
		}

		@Override
		public int compareTo(Man o) {
			if (x != o.x) {
				return x < o.x ? 1 : -1;
			}
			return Long.compare(y, o.y);
		}
	}

	boolean bad(Man a, Man b, Man c) {
		long val = a.x * b.x * c.y * (b.y - a.y) + c.x * a.x * b.y
				* (a.y - c.y) + b.x * c.x * a.y * (c.y - b.y);
		return val < 0;
	}

	void solve() throws IOException {
		int n = nextInt();
		Man[] a = new Man[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Man(nextInt(), nextInt(), i);
		}
		int[] repr = new int[n];
		Arrays.fill(repr, -1);
		Arrays.sort(a);
		Man[] hull = new Man[n];
		int sz = 1;
		hull[0] = a[0];
		for (int i = 1; i < n; i++) {
			if (a[i].x == a[i - 1].x && a[i].y == a[i - 1].y) {
				repr[a[i].id] = a[i - 1].id;
				continue;
			}
			while (sz > 1 && bad(hull[sz - 2], hull[sz - 1], a[i])) {
				sz--;
			}
			hull[sz++] = a[i];
		}
		
		while (sz > 1 && hull[sz - 1].x <= hull[sz - 2].x && hull[sz - 1].y <= hull[sz - 2].y) {
			sz--;
		}
		
		long bestX = -1;
		for (int i = 0; i < n; i++) {
			bestX = Math.max(bestX, a[i].x);
		}
		long bestXbestY = -1;
		for (int i = 0; i < n; i++) {
			if (a[i].x == bestX) {
				bestXbestY = Math.max(bestXbestY, a[i].y);
			}
		}
		
		long bestY = -1;
		for (int i = 0; i < n; i++) {
			bestY = Math.max(bestY, a[i].y);
		}
		long bestYbestX = -1;
		for (int i = 0; i < n; i++) {
			if (a[i].y == bestY) {
				bestYbestX = Math.max(bestYbestX, a[i].x);
			}
		}
		
		
		
		boolean[] good = new boolean[n];
		for (int i = 0; i < sz; i++) {
			if (hull[i].x == bestX && hull[i].y < bestXbestY) {
				continue;
			}
			if (hull[i].y == bestY && hull[i].x < bestYbestX) {
				continue;
			}
			good[hull[i].id] = true;
		}
		for (int i = 0; i < n; i++) {
			if (repr[i] != -1) {
				good[i] = good[repr[i]];
			}
		}
		
		for (int i = 0; i < n; i++) {
			if (good[i]) {
				out.print((i + 1) + " ");
			}
		}
		
		out.println();
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