import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int LOG = 6;
	static final int LEN = 1 << LOG;
	static final int MASK = LEN - 1;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();

		int bsLen = (n + LEN - 1) / LEN;

		long[][] g = new long[n][bsLen];

		int[] rs = new int[m];
		int[] cs = new int[m];
		
		for (int i = 0; i < m; i++) {
			int r = nextInt() - 1;
			int c = nextInt() - 1;
			
			rs[i] = r;
			cs[i] = c;

			g[r][c >> LOG] |= 1L << (c & MASK);
		}
		
		long[][] inv = new long[n][bsLen];
		
		boolean[] used = new boolean[n];
		for (int i = 0; i < n; i++) {
			inv[i][i >> LOG] |= 1L << (i & MASK);
		}

		for (int j = 0; j < n; j++) {

			int row = -1;

			for (int i = j; i < n; i++) {

				if (test(g[i], j)) {
					row = i;
					break;
				}

			}
			
			long[] tmp = g[j];
			g[j] = g[row];
			g[row] = tmp;
			
			tmp = inv[j];
			inv[j] = inv[row];
			inv[row] = tmp;

			for (int i = 0; i < n; i++) {
				if (i != j && test(g[i], j)) {

					for (int z = 0; z < bsLen; z++) {
						g[i][z] ^= g[j][z];
						inv[i][z] ^= inv[j][z];
					}

				}
			}
		}
		
//		System.err.println(Arrays.deepToString(inv));

		for (int i = 0; i < m; i++) {
			int r = rs[i];
			int c = cs[i];
			out.println(test(inv[c], r) ? "NO" : "YES");
		}


	}

	boolean test(long[] bs, int pos) {
		return ((bs[pos >> LOG] >>> (pos & MASK)) & 1) == 1;
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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