import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	long f(int delta) {
		if (delta < 0)
			delta = ~delta;
		delta = delta * 2 + 1;
		return (long)delta * delta;
	}

	long[] get(int[] a) {

		long bestSum = Long.MAX_VALUE;
		long bestPos = -1;

		int n = a.length;

		for (int i = 0; i <= n; i++) {
			long curRes = 0;
			for (int j = 0; j < n; j++)
				curRes += f(j - i) * a[j];
			if (curRes < bestSum) {
				bestSum = curRes;
				bestPos = i;
			}
		}

		return new long[] { bestSum, bestPos };
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int[][] f = new int[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				f[i][j] = nextInt();

		int[] sumRow = new int[n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				sumRow[i] += f[i][j];

		long[] optRow = get(sumRow);
		
		int[] sumCol = new int[m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				sumCol[j] += f[i][j];

		long[] optCol = get(sumCol);

		out.println((optRow[0] + optCol[0]) * 4);
		out.println(optRow[1] + " " + optCol[1]);
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B().inp();
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