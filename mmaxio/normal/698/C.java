import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int oldN = n;
		int k = nextInt();

		int[] newIdx = new int[oldN];

		int sz = 0;

		double[] p = new double[n];
		for (int i = 0; i < n; i++) {
			double x = nextDouble();
			if (x != 0) {
				p[sz] = x;
				newIdx[i] = sz;
				sz++;
			} else {
				newIdx[i] = -1;
			}
		}

		n = sz;
		p = Arrays.copyOf(p, n);

		double[] ans = new double[n];

		if (sz <= k) {
			Arrays.fill(ans, 1);
		} else {

			double[] dp = new double[1 << n];
			dp[0] = 1;
			for (int i = 0; i < (1 << n); i++) {
				if (Integer.bitCount(i) == k) {
					for (int j = 0; j < n; j++) {
						if (test(i, j)) {
							ans[j] += dp[i];
						}
					}
					continue;
				} else if (Integer.bitCount(i) > k) {
					continue;
				}
				double rest = 0;
				for (int j = 0; j < n; j++) {
					if (!test(i, j)) {
						rest += p[j];
					}
				}
				for (int j = 0; j < n; j++) {
					if (!test(i, j)) {
						dp[i | (1 << j)] += dp[i] * p[j] / rest;
					}
				}
			}
		}
		
		for (int i = 0; i < oldN; i++) {
			if (newIdx[i] == -1) {
				out.print("0 ");
			} else {
				out.print(ans[newIdx[i]] + " ");
			}
		}

		out.println();
	}

	boolean test(int i, int j) {
		return ((i >> j) & 1) == 1;
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