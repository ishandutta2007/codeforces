import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void go(int ax, int ay, int bx, int by, StringBuilder sb) {
		System.err.printf(
				"Alice(%d, %d), Bob(%d, %d), x-y = %d - %d, pos = %s\n", ax,
				ay, bx, by, ax + bx, ay + by, sb.toString());
		System.err.println("Expected " + solve(ax + bx, ay + by));
		if (!stupidSolve(ax + bx, ay + by).equals(sb.toString())) {
			throw new AssertionError();
		}
		if (sb.length() == 10) {
			return;
		}
		sb.append('A');
		go(ax, ay, ax + bx, ay + by, sb);
		sb.deleteCharAt(sb.length() - 1);

		sb.append('B');
		go(ax + bx, ay + by, bx, by, sb);
		sb.deleteCharAt(sb.length() - 1);
	}

	String stupidSolve(long x, long y) {
		List<Long> ans = new ArrayList<>();
		while (x != y) {
			if (x > y) {
				long tmp = (x - 1) / y;
				ans.add(tmp);
				x -= y * tmp;
			} else {
				long tmp = (y - 1) / x;
				ans.add(~tmp);
				y -= x * tmp;
			}
		}

		StringBuilder ret = new StringBuilder();
		// Collections.reverse(ans);
		for (long v : ans) {
			if (v >= 0) {
				for (int i = 0; i < v; i++) {
					ret.append('A');
				}
			} else {
				for (int i = 0; i < ~v; i++) {
					ret.append('B');
				}
			}
		}
		return ret.toString();
	}

	String solve(long x, long y) {
		List<Long> ans = new ArrayList<>();
		while (x != y) {
			if (x > y) {
				long tmp = (x - 1) / y;
				ans.add(tmp);
				x -= y * tmp;
			} else {
				long tmp = (y - 1) / x;
				ans.add(~tmp);
				y -= x * tmp;
			}
		}
		
		if (x != 1) {
			return "Impossible";
		}

		StringBuilder ret = new StringBuilder();
		// Collections.reverse(ans);
		for (long v : ans) {
			if (v >= 0) {
				ret.append(v);
				ret.append('A');
			} else {
				ret.append(~v);
				ret.append('B');
			}
		}
		return ret.toString();
	}

	void solve() throws IOException {
//		go(1, 0, 0, 1, new StringBuilder());
		out.println(solve(nextLong(), nextLong()));
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