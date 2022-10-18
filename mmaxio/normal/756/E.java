import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int P = 1_000_000_007;
	
	int[] update(int[] dp, int cnt) {
		int[] ret = new int[dp.length + cnt];
		int sum = 0;
		for (int i = 0; i < ret.length; i++) {
			if (i < dp.length) {
				sum += dp[i];
				if (sum >= P) {
					sum -= P;
				}
			}
			ret[i] = sum;
			if (i >= cnt) {
				sum -= dp[i - cnt];
				if (sum < 0) {
					sum += P;
				}
			}
		}
		return ret;
	}
	
	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			a[i] = nextInt();
		}

		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			b[i] = nextInt();
		}

		int[] dp = { 1 };
		
		BigInteger big = new BigInteger(nextToken());
		
		for (int i = 0; i < n; i++) {
			dp = update(dp, b[i]);
			
			if (i == n - 1) {
				break;
			}
			
			if (a[i] == 1) {
				continue;
			}
			
			BigInteger[] tmp = big.divideAndRemainder(BigInteger.valueOf(a[i]));
			
			int rem = tmp[1].intValue();
			
			if (rem >= dp.length) {
				out.println(0);
				return;
			}
			
			int newLen = (dp.length - 1 - rem) / a[i] + 1;
			int[] newDp = new int[newLen];
			
			for (int ii = rem, j = 0; j < newLen; ii += a[i], j++) {
				newDp[j] = dp[ii];
			}
			
			big = tmp[0];
			dp = newDp;
		}
		
		if (big.compareTo(BigInteger.valueOf(dp.length)) < 0) {
			out.println(dp[big.intValue()]);
		} else {
			out.println(0);
		}
	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E();
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