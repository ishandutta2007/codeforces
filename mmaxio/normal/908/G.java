import java.io.*;
import java.util.*;

public class G {

	static final int P = 1_000_000_007;

	int[][] ways;
	int[][] pow;

	void preCalc(int sz) {
		ways = new int[sz][];
		for (int i = 0; i < ways.length; i++) {
			ways[i] = new int[i + 1];
			ways[i][0] = ways[i][i] = 1;
			for (int j = 1; j < i; j++) {
				ways[i][j] = (ways[i - 1][j] + ways[i - 1][j - 1]) % P;
			}
		}

		pow = new int[10][sz];
		pow[0] = null;
		for (int i = 1; i <= 9; i++) {
			pow[i][0] = 1;
			for (int j = 1; j < sz; j++) {
				pow[i][j] = (int) ((long) pow[i][j - 1] * i % P);
			}
		}
	}

	int solve(String ss) {
		int n = ss.length();
		int[] s = new int[n];
		for (int i = 0; i < n; i++) {
			s[i] = ss.charAt(i) - '0';
		}

		preCalc(n + 10);

		int[] ans = new int[n + 1];

		int[] cnt = new int[10];

		for (int i = 0; i < n; i++) {

			int rest = n - i - 1;

			int dig = s[i];

			for (int j = 0; j <= (i == n - 1 ? dig : dig - 1); j++) {
				cnt[j]++; // now we have one more digit >= j

				for (int use = 1; use < 10; use++) {
					// use digits are bad, 10 - use are good
					for (int cntGood = 0; cntGood <= rest; cntGood++) {
						int delta = (int) ((long) ways[rest][cntGood]
								* pow[use][rest - cntGood] % P
								* pow[10 - use][cntGood] % P);
						int idx = cnt[use] + cntGood;
						ans[idx] += delta;
						if (ans[idx] >= P) {
							ans[idx] -= P;
						}
					}
				}

				// System.err.println(Arrays.toString(ans));

			}

			cnt[dig]++;

		}
		
		int ret = 0;
		long mult = 0;
		for (int i = 1; i < ans.length; i++) {
			mult = (10L * mult + 1) % P;
			ret += (int)(mult * ans[i] % P);
			if (ret >= P) {
				ret -= P;
			}
		}
		
		return ret;
	}

	void submit() {
		out.println(solve(nextToken()));
	}

	void stress() {

	}

	void test() {
		StringBuilder sb = new StringBuilder("1");
		for (int i = 0; i < 700; i++) {
			sb.append('0');
		}
		solve(sb.toString());
	}

	G() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		submit();
		// stress();
//		 test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new G();
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