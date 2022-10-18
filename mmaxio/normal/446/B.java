import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	long[] gen(long[] val, int k, int dec) {
		PriorityQueue<Long> q = new PriorityQueue<>(val.length,
				new Comparator<Long>() {

					@Override
					public int compare(Long o1, Long o2) {
						return -o1.compareTo(o2);
					}

				});
		for (int i = 0; i < val.length; i++) {
			q.add(val[i]);
		}
		long[] ret = new long[k + 1];
		for (int i = 1; i <= k; i++) {
			long cur = q.poll();
			ret[i] = ret[i - 1] + cur;
			q.add(cur - dec);
		}
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		int p = nextInt();
		long[] row = new long[n];
		long[] col = new long[m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x = nextInt();
				row[i] += x;
				col[j] += x;
			}
		}

		long[] maxRow = gen(row, k, p * m);
		long[] maxCol = gen(col, k, p * n);

		long ans = Long.MIN_VALUE;
		for (int i = 0; i <= k; i++) {
			ans = Math.max(ans, maxRow[i] + maxCol[k - i] - (long) p * i
					* (k - i));
		}

		out.println(ans);
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