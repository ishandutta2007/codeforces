import java.io.*;
import java.util.*;

public class E_lowmem {

	BufferedReader br;
	PrintWriter out;  
	StringTokenizer st;
	boolean eof;

	static final int INF = 1_000_000_001; 
	static final int MOD = 1_000_000_007;

	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] sum = new int[1 << n];
		for (int i = 0; i < n; i++)
			sum[1 << i] = nextInt();

		for (int mask = 1; mask < (1 << n); mask++) {
			int prev = mask & (mask - 1);
			int val = sum[prev] + sum[mask ^ prev];
			sum[mask] = Math.min(val, INF);
		}
		
		sum[0] = 1;

		int k = nextInt();
		int bad0 = -1, bad1 = -1;
		if (k >= 1)
			bad0 = nextInt();
		if (k >= 2)
			bad1 = nextInt();

		outer: for (int mask = 1; mask < (1 << n); mask++) {
			if ((sum[mask] == bad0) || (sum[mask] == bad1)) {
				sum[mask] = 0;
				continue outer;
			}

			long val = 0;

			for (int i = 0; i < n; i++) {
				int prev = mask ^ (1 << i);
				if (prev < mask) {
					val += sum[prev];
				}
			}
			sum[mask] = (int) (val % MOD);
		}

		out.println(sum[(1 << n) - 1]);
	}

	E_lowmem() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E_lowmem();
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