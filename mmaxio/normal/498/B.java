import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int t = nextInt();
		double[] ps = new double[n];
		int[] needs = new int[n];
		for (int i = 0; i < n; i++) {
			ps[i] = nextInt() * 0.01;
			needs[i] = nextInt();
		}
		
		
		double ret = 0;
		
		double[] dp = new double[t + 1];
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			double[] next = new double[t + 1];
			double p = ps[i];
			int need = needs[i];
			double val = 0;
			double sure = 1;
			for (int j = 1; j < need; j++) {
				val = val * (1 - p) + dp[j - 1] * p;
				sure *= 1 - p; 
				if (sure < 1e-15) {
					sure = 0;
				}
				next[j] = val;
			}
 			val = val * (1 - p) + dp[need - 1] * p;
			val += (1 - p) * sure * dp[0];			
			next[need] = val;

			for (int j = need + 1; j <= t; j++) {
				val -= dp[j - need - 1] * sure;
				val = val * (1 - p) + dp[j - 1] * p;
				val += (1 - p) * sure * dp[j - need];
				next[j] = val;
			}
			
			dp = next;
//			System.err.println(Arrays.toString(dp));
			for (int j = 0; j <= t; j++) {
				if (dp[j] < 1e-15) {
					dp[j] = 0;
				}
				ret += dp[j];
			}
		}
		out.println(ret);
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
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