import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	double[] prefSum;
	
	long[] pref;
	double[] prefInv;
	
	/**
	 * [l; r)
	 */
	double cost(int l, int r) {
		double ret = prefSum[r] - prefSum[l];
		
		double invSum = prefInv[r] - prefInv[l];
		long justSum = pref[l];
		
//		System.err.println(l + " " + r + " " + (ret - justSum * invSum));
		
		return ret - justSum * invSum;
	}
	
	void go(int l, int r, int lowK, int highK, double[] dp, double[] prev) {
		if (r - l <= 0) {
			return;
		}
		int mid = (l + r) >> 1;

		double best = 1e30;
		int opt = -1;
		for (int k = lowK; k <= highK && k < mid; k++) {
			double val = prev[k] + cost(k, mid);
			if (val < best) {
				best = val;
				opt = k;
			}
		}
		dp[mid] = best;

		go(l, mid, lowK, opt, dp, prev);
		go(mid + 1, r, opt, highK, dp, prev);
	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		
		
		long sum = 0;
		prefSum = new double[n + 1];
		pref = new long[n + 1];
		prefInv = new double[n + 1];
		for (int i = 0; i < n; i++) {
			sum += a[i];
			prefSum[i + 1] = prefSum[i] + 1.0 * sum / a[i];
			
			pref[i + 1] = pref[i] + a[i];
			prefInv[i + 1] = prefInv[i] + 1.0 / a[i];
		}
		
		
		double[] dp = new double[n + 1];
		Arrays.fill(dp, 1e30);
		dp[0] = 0;
		
		for (int j = 0; j < k; j++) {
			double[] nextDp = new double[n + 1];
			go(1, n + 1, 0, n, nextDp, dp);
			dp = nextDp;
		}
		
		out.println(dp[n]);
		
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