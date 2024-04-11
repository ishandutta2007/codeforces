import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] go(int s, int e, int x, int y, int m) {
		int[] tme = new int[m];
		Arrays.fill(tme, -1);
		for (int i = 0;; i++) {
			if (tme[s] != -1) {
				if (tme[e] == -1) {
					return null;
				}
				if (tme[e] < tme[s]) {
					return new int[] { tme[e] };
				}
				return new int[] { tme[e], i - tme[s] };
			}
			tme[s] = i;
			s = (int) (((long) s * x + y) % m);
		}
	}

	void solve() throws IOException {
		int m = nextInt();
		int s1 = nextInt();
		int e1 = nextInt();
		int x1 = nextInt();
		int y1 = nextInt();

		int s2 = nextInt();
		int e2 = nextInt();
		int x2 = nextInt();
		int y2 = nextInt();

		int[] a = go(s1, e1, x1, y1, m);
		int[] b = go(s2, e2, x2, y2, m);
		if (a == null || b == null) {
			out.println(-1);
			return;
		}
		if (a.length > b.length) {
			int[] tmp = a;
			a = b;
			b = tmp;
		}
		if (b.length == 1) {
			if (a[0] == b[0]) {
				out.println(a[0]);
			} else {
				out.println(-1);
			}
		} else if (a.length == 1 && b.length == 2) {
			if (a[0] >= b[0] && (a[0] - b[0]) % b[1] == 0) {
				out.println(a[0]);
			} else {
				out.println(-1);
			}
		} else {
			int x = a[0];
			int y = a[1];
			int z = b[0];
			int t = b[1];
//			System.err.println(x + " " + y + " " + z + " " + t);
			for (int i = 0; i < 2 * m; i++) {
				long tme = (long)y * i + x;
				if (tme >= z && (tme - z) % t == 0) {
					out.println(tme);
					return;
				}
			}
			out.println(-1);
		}
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A().inp();
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