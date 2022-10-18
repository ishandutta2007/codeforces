import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		int[][] a = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = nextInt();
			}
		}

		if (n < m) {
			int[][] newA = new int[m][n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					newA[j][i] = a[i][j];
				}
			}
			a = newA;
			int tmp = n;
			n = m;
			m = tmp;
		}

		// n >= m
		if (m == 1) {
			out.println(0);
			return;
		}
		
//		System.err.println(n + " " + m);
//		System.err.println(Arrays.deepToString(a));

		if (n > k) {
			int ans = Integer.MAX_VALUE;
			for (int i = 0; i < n; i++) {
				// don't change anything here
				int tot = 0;
				for (int j = 0; j < n; j++) {
					int diff = 0;
					for (int jj = 0; jj < m; jj++) {
						diff += a[i][jj] ^ a[j][jj];
					}
					tot += Math.min(diff, m - diff);
				}
				ans = Math.min(ans, tot);
			}
			out.println(ans <= k ? ans : -1);
			return;
		}

		// m <= n <= k
		int ans = Integer.MAX_VALUE;
		for (int mask = 0; mask < 1 << (m + n - 1); mask++) {
			int val = Integer.bitCount(mask);
			if (val > ans) {
				continue;
			}
			for (int i = 1; i < n; i++)
				for (int j = 1; j < m; j++) {
					int need = a[0][0] ^ a[i][0] ^ a[0][j] ^ test(mask, 0)
							^ test(mask, i) ^ test(mask, j + n - 1) ^ a[i][j];
					val += need;
				}
			ans = Math.min(ans, val);
		}

		out.println(ans <= k ? ans : -1);
	}
	
	static int test(int mask, int i) {
		return (mask >> i) & 1;
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