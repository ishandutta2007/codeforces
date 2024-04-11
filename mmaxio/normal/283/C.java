import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int MOD = 1000000007;

	void solve() throws IOException {
		int n = nextInt();
		int q = nextInt();

		long sum = nextLong();

		int[] val = new int[n];
		for (int i = 0; i < n; i++)
			val[i] = nextInt();

		boolean[] hasIn = new boolean[n];
		int[] to = new int[n];
		Arrays.fill(to, -1);

		for (int i = 0; i < q; i++) {
			int more = nextInt() - 1;
			int less = nextInt() - 1;
			hasIn[less] = true;
			to[more] = less;
		}

		ArrayList<Integer> order = new ArrayList<>();

		ArrayList<Long> newVals = new ArrayList<>();

		for (int i = 0; i < n; i++) {
			if (!hasIn[i]) {

				for (int j = i; j != -1; j = to[j])
					order.add(val[j]);

				long pref = 0;

				for (int j = 0; j < order.size(); j++) {
					pref += order.get(j);
					newVals.add(pref);
					if (j != order.size() - 1) {
						sum -= pref;
					}
				}

			}
			
			order.clear();
		}
		
		//System.err.println(newVals);
		
		if (newVals.size() != n || sum < 0) {
			out.println(0);
			return;
		}

		int sz = (int) sum;
		int[] dp = new int[sz + 1];
		
		dp[0] = 1;

		for (int i = 0; i < n; i++) {
			long longCur = newVals.get(i);

			if (longCur > sz)
				continue;
			int cur = (int) longCur;
			
			for (int j = cur; j <= sz; j++) {
				dp[j] += dp[j - cur];
				if (dp[j] >= MOD)
					dp[j] -= MOD;
			}
			
		}
		
		out.println(dp[sz]);

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