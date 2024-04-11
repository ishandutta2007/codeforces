import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int MOD = 1_000_000_007;

	static int more(char c) {
		return 'z' - c;
	}

	static int less(char c) {
		return c - 'a';
	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		char[] s = nextToken().toCharArray();
		
		int[][] dp = new int[n + 1][k + 1];

		// end
		dp[n][0] = 1;
		
		// equal suffix
		for (int i = 0; i < n; i++) {
			dp[i][0] = 1;
		}
		
		int[] curAdd = new int[k + 1];
		
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j <= k; j++) {
				dp[i + 1][j] += curAdd[j];
				if (dp[i + 1][j] >= MOD) {
					dp[i + 1][j] -= MOD;
				}
				if (dp[i + 1][j] == 0) {
					continue;
				}
				// put less
				int value = (int)((long)less(s[i]) * dp[i + 1][j] % MOD);
				curAdd[j] += value;
				if (curAdd[j] >= MOD) {
					curAdd[j] -= MOD;
				}
				
				// put more
				value = (int)((long)more(s[i]) * dp[i + 1][j] % MOD);
				int addBad = n - i;
				for (int newI = i, newJ = j + addBad; newI >= 0 && newJ <= k; newI--, newJ += addBad) {
					dp[newI][newJ] += value;
					if (dp[newI][newJ] >= MOD) {
						dp[newI][newJ] -= MOD;
					}
				}
				
			}
		}
		
		int ret = dp[0][k] + curAdd[k];
		if (ret >= MOD) {
			ret -= MOD;
		}
		
		out.println(ret);

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