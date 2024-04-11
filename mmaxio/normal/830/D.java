import java.io.*;
import java.util.*;

public class D {

	static final int P = 1_000_000_007;

	void submit() {
		int n = nextInt();
		int[] dp = new int[n + 2];
		dp[0] = 1;
		for (int k = 1; k <= n; k++) {
			int[] nxt = new int[n + 1];
			int need = n + 1 - k;
			for (int i = 0; i <= need + 1; i++) {
				for (int j = 0; i + j - 1 <= need; j++) {
					int prod = (int) ((long) dp[i] * dp[j] % P);

					if (i + j <= need) {
						nxt[i + j] += prod;
						if (nxt[i + j] >= P) {
							nxt[i + j] -= P;
						}
						nxt[i + j] += (int) (2L * prod * (i + j) % P);
						if (nxt[i + j] >= P) {
							nxt[i + j] -= P;
						}
						
						if (i + j + 1 <= need) {
							nxt[i + j + 1] += prod;
							if (nxt[i + j + 1] >= P) {
								nxt[i + j + 1] -= P;
							}
						}
					}

					if (i + j > 0) {
						int mult = (i + j) * (i + j) - i - j;
						nxt[i + j - 1] += (int) ((long)mult * prod % P);
						if (nxt[i + j - 1] >= P) {
							nxt[i + j - 1] -= P;
						}
					}
				}
			}
			dp = nxt;
//			System.err.println(Arrays.toString(dp));
		}

		out.println(dp[1]);
	}

	void preCalc() {

	}

	void stress() {

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