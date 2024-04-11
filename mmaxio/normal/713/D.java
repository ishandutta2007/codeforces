import java.io.*;
import java.util.*;

public class D_2d_sparse {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int n, m;

	static int log2(int x) {
		return 31 - Integer.numberOfLeadingZeros(x);
	}

	void solve() throws IOException {
		n = nextInt();
		m = nextInt();
		int[][] a = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = nextInt();
			}
		}

		int[][] b = new int[n + 1][m + 1];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				b[i + 1][j + 1] = a[i][j] + b[i][j + 1] + b[i + 1][j] - b[i][j];
			}
		}

		int maxLen = Math.min(n, m);

		int[] cnt = new int[maxLen + 1];

		int[][] c = new int[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int low = 0;
				int high = Math.min(n - i, m - j) + 1;

				while (high - low > 1) {
					int mid = (low + high) >> 1;
					if (b[i + mid][j + mid] - b[i + mid][j] - b[i][j + mid]
							+ b[i][j] == mid * mid) {
						low = mid;
					} else {
						high = mid;
					}
				}

				c[i][j] = low;
				cnt[low]++;
			}
		
//		System.err.println(Arrays.deepToString(c));

		int[][][][] s = new int[log2(n) + 1][log2(m) + 1][][];

		s[0][0] = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				s[0][0][i][j] = c[i][j];
			}
		}

		for (int i = 0; i <= log2(n); i++)
			for (int j = 0; j <= log2(m); j++) {
				if (i + j == 0) {
					continue;
				}
				int[][] tmp = s[i][j] = new int[n - (1 << i) + 1][m
						- (1 << j) + 1];
				if (i == 0) {
					int[][] prev = s[i][j - 1];
					for (int x = 0; x < tmp.length; x++)
						for (int y = 0; y < tmp[0].length; y++) {
							tmp[x][y] = Math.max(prev[x][y], prev[x][y
									+ (1 << (j - 1))]);
						}
				} else {
					int[][] prev = s[i - 1][j];
					for (int x = 0; x < tmp.length; x++)
						for (int y = 0; y < tmp[0].length; y++) {
							tmp[x][y] = Math.max(prev[x][y], prev[x
									+ (1 << (i - 1))][y]);
						}
				}
//				System.err.println(i + " " + j + " " + Arrays.deepToString(tmp));
			}

		int qs = nextInt();

		for (int i = 0; i < qs; i++) {

			int x1 = nextInt() - 1;
			int y1 = nextInt() - 1;
			int x2 = nextInt();
			int y2 = nextInt();

			int low = 0;
			int high = Math.min(x2 - x1, y2 - y1) + 1;

			binSearch: while (high - low > 1) {
				int mid = (low + high) >> 1;

				int lowX = x1;
				int lowY = y1;
				int highX = x2 - mid + 1;
				int highY = y2 - mid + 1;

				int logX = log2(highX - lowX);
				int logY = log2(highY - lowY);

				int[][] tmp = s[logX][logY];
				
				int oldLow = low;
				low = mid;

				if (tmp[lowX][lowY] >= mid) {
					continue binSearch;
				}
				if (tmp[lowX][highY - (1 << logY)] >= mid) {
					continue binSearch;
				}
				if (tmp[highX - (1 << logX)][lowY] >= mid) {
					continue binSearch;
				}
				if (tmp[highX - (1 << logX)][highY - (1 << logY)] >= mid) {
					continue binSearch;
				}
				low = oldLow;
				high = mid;
			}
			out.println(low);
		}

	}

	D_2d_sparse() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D_2d_sparse();
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