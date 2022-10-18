import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final String COLS = "RGBYW";

	void solve() throws IOException {
		boolean[][] f = new boolean[5][5];
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			f[s.charAt(1) - '1'][COLS.indexOf(s.charAt(0))] = true;
		}
		int ans = 10;
		for (int mask = 0; mask < 1024; mask++) {
			if (can(mask, f)) {
				ans = Math.min(ans, Integer.bitCount(mask));
			}
		}
		out.println(ans);
	}

	boolean can(int mask, boolean[][] f) {
		int[][] cnt = new int[6][6];
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++) {
				if (f[i][j]) {
					int x, y;
					if (test(mask, i)) {
						x = i;
					} else {
						x = 5;
					}
					if (test(mask, j + 5)) {
						y = j;
					} else {
						y = 5;
					}
					cnt[x][y]++;
				}
			}
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 6; j++)
				if (cnt[i][j] > 1) {
					return false;
				}
		return true;

	}

	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
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