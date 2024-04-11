import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int ALL = (1 << 10) - 1;

	void solve() throws IOException {
		String s = nextToken();
		boolean[] have = new boolean[10];

		for (int i = 0; i < 10; i++) {
			have[i] = s.charAt(i) == '1';
		}

		int m = nextInt();

		int[][] can = new int[m][21];

		for (int i = 0; i < 10; i++) {
			if (have[i]) {
				can[0][10 + i + 1] |= 1 << i;
			}
		}

		for (int i = 1; i < m; i++) {

			if (i % 2 == 1) {

				for (int j = 11; j <= 20; j++) {
					if (can[i - 1][j] != 0) {

						for (int k = 0; k < 10; k++) {
							if (have[k] && (can[i - 1][j] & (~(1 << k))) != 0
									&& j - (k + 1) < 10) {
								can[i][j - (k + 1)] |= 1 << k;
							}
						}

					}
				}
			} else {
				for (int j = 0; j <= 9; j++) {
					if (can[i - 1][j] != 0) {
						for (int k = 0; k < 10; k++) {
							if (have[k] && (can[i - 1][j] & (~(1 << k))) != 0
									&& j + (k + 1) > 10) {
								can[i][j + (k + 1)] |= 1 << k;
							}
						}
					}
				}
			}
		}
		
		int balance = -1;
		
		for (int i = 0; i < 21; i++) {
			if (can[m - 1][i] != 0) {
				balance = i;
				break;
			}
		}
		
		if (balance == -1) {
			out.println("NO");
			return;
		}
		
		int prevTakenMask = 0;
		List<Integer> ans = new ArrayList<>();
		for (int i = m - 1; i > 0; i--) {
			int take = Integer.numberOfTrailingZeros(can[i][balance] & (~prevTakenMask));
			if (take == 32) {
				throw new AssertionError("Can't restore answer?");
			}
			ans.add(take + 1);
			
			if (i % 2 == 1) {
				balance += (take + 1);
			} else {
				balance -= (take + 1);
			}
			
			prevTakenMask = 1 << take;
		}
		
		ans.add(balance - 10);
		
		Collections.reverse(ans);
		out.println("YES");
		for (int x : ans) {
			out.print(x + " ");
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