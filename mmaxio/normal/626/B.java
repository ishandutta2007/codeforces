import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final String COLS = "BGR";
	static final int N = 200;

	void solve() throws IOException {
		int n = nextInt();
		boolean[][][] can = new boolean[N + 1][N + 1][N + 1];
		int[] cnt = new int[3];
		String s = nextToken();
		for (char c : s.toCharArray()) {
			cnt[COLS.indexOf(c)]++;
		}
		can[cnt[0]][cnt[1]][cnt[2]] = true;

		for (int sum = n; sum > 1; sum--) {

			for (int i = N; i >= 0; i--)
				for (int j = N; j >= 0; j--) {
					int k = sum - i - j;
					if (k < 0 || k > N) {
						continue;
					}

					if (!can[i][j][k]) {
						continue;
					}
					// System.err.println(i + " " + j + " " + k);
					if (i > 0 && j > 0) {
						can[i - 1][j - 1][k + 1] = true;
					}
					if (i > 0 && k > 0) {
						can[i - 1][j + 1][k - 1] = true;
					}
					if (j > 0 && k > 0) {
						can[i + 1][j - 1][k - 1] = true;
					}
					if (i > 1) {
						can[i - 1][j][k] = true;
					}
					if (j > 1) {
						can[i][j - 1][k] = true;
					}
					if (k > 1) {
						can[i][j][k - 1] = true;
					}
				}
		}
		if (can[1][0][0]) {
			out.print("B");
		}
		if (can[0][1][0]) {
			out.print("G");
		}
		if (can[0][0][1]) {
			out.print("R");
		}
		out.println();

	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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