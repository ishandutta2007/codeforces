import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		
		long[] sum = new long[n + 1];
		for (int i = 0; i < n; i++) {
			sum[i + 1] = sum[i] + nextInt();
		}
		
		long[] sz = new long[n - k + 1];
		for (int i = 0; i <= n - k; i++) {
			sz[i] = sum[i + k] - sum[i];
		}
		
		long maxSecond = 0;
		int maxSecondPos = -1;
		
		long maxAns = 0;
		int maxAnsPos1 = -1;
		int maxAnsPos2 = -1;
		
		for (int i = n - 2 * k; i >= 0; i--) {
			if (sz[i + k] >= maxSecond) {
				maxSecond = sz[i + k];
				maxSecondPos = i + k;
			}
			if (sz[i] + maxSecond >= maxAns) {
				maxAns = sz[i] + maxSecond;
				maxAnsPos1 = i;
				maxAnsPos2 = maxSecondPos;
			}
		}
		
		out.println((maxAnsPos1 + 1) + " " + (maxAnsPos2 + 1));
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