import java.io.*;
import java.util.*;

public class F_mew {

	static final int INF = -(Integer.MAX_VALUE / 2);
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int t = nextInt();

		int[] maxD = new int[n];
		int[] value = new int[n];

		List<Integer>[] byMaxD = new List[101];
		for (int i = 0; i < 101; i++) {
			byMaxD[i] = new ArrayList<>();
		}

		for (int i = 0; i < n; i++) {
			maxD[i] = t - nextInt();
			value[i] = nextInt();
			if (maxD[i] >= 0) {
				byMaxD[maxD[i]].add(value[i]);
			}
		}

		int[] dp = new int[1001];
		Arrays.fill(dp, INF);
		dp[0] = 0;

		for (int i = 100; i >= 0; i--) {
			int[] next = new int[1001];
			Arrays.fill(next, INF);
			next[0] = 0;
			for (int j = 1; j <= 1000; j++) {
				next[(j + 1) / 2] = Math.max(next[(j + 1) / 2], dp[j]);
			}
			dp = next;
			for (int val : byMaxD[i]) {
//				System.err.println(i + " " + val);
				for (int j = 1000; j >= 1; j--) {
					if (dp[j - 1] != INF) {
						dp[j] = Math.max(dp[j], dp[j - 1] + val);
					}
				}
			}
//			System.err.println(Arrays.toString(Arrays.copyOf(dp, 10)));
		}
		
		out.println(dp[1]);
	}

	F_mew() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new F_mew();
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