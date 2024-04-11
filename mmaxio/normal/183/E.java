import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		
		long[] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = nextLong();
		
		long ans = 0;
		
		int maxP = m / n;
		for (int p = 1; p <= maxP; p++) {
			long minLastSum = (long)p * (p + 1) / 2 * n;
			if (a[n - 1] < minLastSum)
				continue;
			long maxLastSum = (long)m * p - (long)n * p * (p - 1) / 2;
			long[] money = new long[n];
			money[n - 1] = Math.min(maxLastSum, a[n - 1]);
			for (int i = n - 2; i >= 0; i--)
				money[i] = Math.min(a[i], money[i + 1] - p);
			
			long firstMax = (long)(m + 1) * p - (long)n * p * (p + 1) / 2;
			long diff = firstMax - money[0];
			if (diff < 0)
				throw new AssertionError();
			long firstPay = diff <= m - p * n ? (m - p * n + 1 - diff) : 1;
			long free = (m - firstPay + 1) - n * p;
			
			long cur = money[0];
			long last = money[0];
			for (int j = 1; j < n; j++) {
				long now = last + p;
				long shift = Math.min(free, money[j] - now);
				free -= shift;
				last = now + shift;
				cur += last;
			}
			
			ans = Math.max(ans, cur);
		}
		
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