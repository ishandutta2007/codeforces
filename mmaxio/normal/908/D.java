import java.io.*;
import java.util.*;

public class D {

	static final int P = 1_000_000_007;

	void submit() {
		int k = nextInt();
		int pa = nextInt();
		int pb = nextInt();

		int p = (int) ((long) pa * inv(pa + pb) % P);
		int q = (int) ((long) pb * inv(pa + pb) % P);
		
		int z = (int)((long)p * inv(q) % P);

		int[][] dp = new int[k + 1][k + 1];

		int ans = 0;
		
		dp[1][0] = 1;
		for (int x = 0; x <= k; x++) {
			for (int y = 0; y <= k; y++) {
				if (x + y >= k) {
					
					int ev = y + x + z;
					if (ev >= P) {
						ev -= P;
					}
					
					ans += (int)((long)dp[x][y] * ev % P);
					if (ans >= P) {
						ans -= P;
					}
					
					// think about it
					continue;
				}
				dp[x + 1][y] += (int) ((long) dp[x][y] * p % P);
				if (dp[x + 1][y] >= P) {
					dp[x + 1][y] -= P;
				}

				dp[x][x + y] += (int) ((long) dp[x][y] * q % P);
				if (dp[x][x + y] >= P) {
					dp[x][x + y] -= P;
				}
			}
		}
		out.println(ans);
	}

	int inv(int x) {
		return x == 1 ? 1 : P - (int) ((long) (P / x) * inv(P % x) % P);
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new D();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}