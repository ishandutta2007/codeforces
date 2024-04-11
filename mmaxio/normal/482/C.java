import java.io.*;
import java.util.*;

public class C_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	String getSubmask(String s, int mask) {
		char[] buf = new char[Integer.bitCount(mask)];
		for (int i = 0, j = 0; i < s.length(); i++) {
			if (test(mask, i)) {
				buf[j++] = s.charAt(i);
			}
		}
		return new String(buf);
	}

	void solve() throws IOException {
		int n = nextInt();
		String[] ss = new String[n];
		for (int i = 0; i < n; i++) {
			ss[i] = nextToken();
		}
		int m = ss[0].length();

		long[] same = new long[1 << m];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					int here = 0;
					for (int k = 0; k < m; k++) {
						if (ss[i].charAt(k) == ss[j].charAt(k)) {
							here |= 1 << k;
						}
					}
					same[here] |= 1L << i;
				}
			}
		}
		
		for (int i = (1 << m) - 1; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				if (test(i, j)) {
					same[i ^ (1 << j)] |= same[i];
				}
			}
		}
		
		int[] dunno = new int[1 << m];
		for (int i = 0; i < (1 << m); i++) {
			dunno[i] = Long.bitCount(same[i]);
		}
		
//		System.err.println(Arrays.toString(dunno));
		

		double[] dp = new double[1 << m];
		dp[0] = 1;
		double ans = 0;
		for (int mask = 0; mask < (1 << m); mask++) {
			// System.err.println(dunno[mask] + " " + dp[mask]);
			if (dunno[mask] == 0) {
				continue;
			}
			int here = Integer.bitCount(mask);
			int tot = m - here;
			for (int ask = 0; ask < m; ask++) {
				if (!test(mask, ask)) {
					int to = mask | (1 << ask);
					ans += 1.0 / tot * (dunno[mask] - dunno[to]) / dunno[mask]
							* dp[mask] * (here + 1);
					dp[to] += 1.0 / tot * dunno[to] / dunno[mask] * dp[mask];
				}
			}
		}

		out.println(ans);
	}

	C_new() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C_new();
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