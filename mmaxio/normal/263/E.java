import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int newR, newC;

	long get(long[][] a, int x, int y) {
		if (x < 0 || y < 0 || x >= newR || y >= newC)
			return 0;
		else
			return a[x][y];
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();

		int k = nextInt();

		int maxSum = (n - 1) + (m - 1);
		int minDiff = -(m - 1);
		int maxDiff = n - 1;

		newR = maxSum + 1;
		newC = maxDiff - minDiff + 1;

		long[][] f = new long[newR][newC];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				f[i + j][i - j - minDiff] = nextInt();
			}

		for (int i = 0; i < newR; i++)
			for (int j = 0; j < newC; j++) {
				if (i > 0)
					f[i][j] += f[i - 1][j];
				if (j > 0)
					f[i][j] += f[i][j - 1];
				if (i > 0 && j > 0)
					f[i][j] -= f[i - 1][j - 1];
			}

//		System.err.println("-------");
//		for (int i = 0; i < newR; i++)
//			System.err.println(Arrays.toString(f[i]));

		long[][] mainDiag = new long[newR][newC];
		long[][] secDiag = new long[newR][newC];

		for (int i = 0; i < newR; i++)
			for (int j = 0; j < newC; j++) {
				mainDiag[i][j] = secDiag[i][j] = f[i][j];
				if (i > 0 && j > 0)
					mainDiag[i][j] += mainDiag[i - 1][j - 1];
				if (i > 0 && j < newC - 1)
					secDiag[i][j] += secDiag[i - 1][j + 1];
			}

		// System.err.println("-------");
		// for (int i = 0; i < newR; i++)
		// System.err.println(Arrays.toString(mainDiag[i]));
		// for (int i = 0; i < newR; i++)
		// System.err.println(Arrays.toString(secDiag[i]));

		long ans = -1;
		int ansX = -1;
		int ansY = -1;

		for (int i = k - 1; i <= n - k; i++)
			for (int j = k - 1; j <= m - k; j++) {

				int x = i + j;
				int y = i - j - minDiff;

				long cur = get(mainDiag, x + k - 1, y + k - 1)
						- get(mainDiag, x - k - 1, y - k - 1);

				cur -= get(secDiag, x + k - 1, y - k)
						- get(secDiag, x - k - 1, y + k);
				if (cur > ans) {
					ans = cur;
					ansX = i;
					ansY = j;
				}

			}

		out.println((ansX + 1) + " " + (ansY + 1));

	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E();
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