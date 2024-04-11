import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int MAX_T = 86400;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		
		if (k == n) {
			out.println(MAX_T);
			return;
		}
		
		int[] st = new int[n];
		int[] len = new int[n];
		
		for (int i = 0; i < n; i++) {
			st[i] = nextInt();
			len[i] = nextInt();
		}
		
		int[] dp = new int[k + 1];
		Arrays.fill(dp, 1);
		
		int ans = 0;
		
		for (int i = 0; i < n; i++) {
			ans = Math.max(ans, st[i] - dp[k]);
			for (int j = k; j > 0; j--)
				dp[j] = Math.min(Math.max(dp[j], st[i]) + len[i], dp[j - 1]);
			dp[0] = Math.max(dp[0], st[i]) + len[i];
		}
		
		ans = Math.max(ans, MAX_T + 1 - dp[k]);
		out.println(ans);
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E().inp();
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