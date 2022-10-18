import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final long INF = Long.MAX_VALUE / 3;

	void solve() throws IOException {
		int n = nextInt();
		int q = nextInt();

		long[] val = new long[n];
		int[] col = new int[n];

		for (int i = 0; i < n; i++)
			val[i] = nextInt();

		for (int i = 0; i < n; i++)
			col[i] = nextInt() - 1;

		long[] maxColor = new long[n];

		while (q-- > 0) {

			long res = 0;

			Arrays.fill(maxColor, -INF);

			long max = -INF;
			long max2 = -INF;

			long same = nextLong();
			long diff = nextLong();

			for (int i = 0; i < n; i++) {
				int c = col[i];
				long v = val[i];

				// System.err.println(Arrays.toString(maxColor));

				long maxThisColor = maxColor[c];
				long maxDiffColor = (max == maxColor[c] ? max2 : max);

				long curMax = v * diff;
				if (maxThisColor != -INF)
					curMax = Math.max(curMax, maxThisColor + v * same);
				if (maxDiffColor != -INF)
					curMax = Math.max(curMax, maxDiffColor + v * diff);
				res = Math.max(curMax, res);

				if (curMax > maxColor[c]) {
					// we was the only maximum
					if (maxColor[c] == max && maxColor[c] != max2)
						max = curMax;
					else if (curMax >= max) {
						max2 = max;
						max = curMax;
					} else if (curMax >= max2) {
						max2 = curMax;
					}

					maxColor[c] = curMax;
				}
			}
			out.println(res);
		}
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