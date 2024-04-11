import java.io.*;
import java.util.*;

public class B {

	static final int INF = Integer.MAX_VALUE / 2;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int a = nextInt();
		int b = nextInt();
		int[] h = new int[n];

		int area = 0;

		for (int i = 0; i < n; i++) {
			h[i] = nextInt();
			area += h[i];
		}

		if (a + b < area) {
			out.println(-1);
			return;
		}

		int[][] dp = new int[2][a + 1];
		Arrays.fill(dp[0], INF);
		if (h[0] <= a)
			dp[0][h[0]] = 0;
		Arrays.fill(dp[1], INF);
		dp[1][0] = 0;

		for (int i = 1; i < n; i++) {
			int x = h[i];
			int val = Math.min(h[i], h[i - 1]);
			int[][] next = new int[2][a + 1];
			Arrays.fill(next[0], INF);
			Arrays.fill(next[1], INF);
			for (int prevC = 0; prevC < 2; prevC++)
				for (int prev = 0; prev <= a; prev++)
					if (dp[prevC][prev] != INF) {
						if (prev + x <= a)
							next[0][prev + x] = Math.min(next[0][prev + x],
									dp[prevC][prev] + (prevC == 0 ? 0 : val));
						next[1][prev] = Math.min(next[1][prev], dp[prevC][prev]
								+ (prevC == 1 ? 0 : val));
					}
			dp = next;
		}

		int ans = INF;
		for (int j = 0; j < 2; j++)
			for (int i = 0; i <= a; i++)
				if (area - i <= b)
					ans = Math.min(ans, dp[j][i]);

		out.println(ans == INF ? -1 : ans);

	}

	B() throws IOException {
		br = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
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