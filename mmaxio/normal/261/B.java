import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		
		int sumA = 0;
		
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			sumA += a[i];
		}
		
		long[][] c = new long[n][];
		for (int i = 0; i < n; i++) {
			c[i] = new long[i + 1];
			c[i][0] = c[i][i] = 1;
			for (int j = 1; j < i; j++)
				c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
		
		int p = nextInt();
		if (sumA <= p) {
			out.println(n);
			return;
		}
		
		double ans = 0;
		
		for (int i = 0; i < n; i++) {
			int low = Math.max(p - a[i] + 1, 0);
			int high = p;
			
			long[][] ways = new long[n][high + 1];
			ways[0][0] = 1;
			
			for (int j = 0; j < n; j++)
				if (i != j) {
					int x = a[j];
					for (int cnt = n - 2; cnt >= 0; cnt--)
						for (int sum = high - x; sum >= 0; sum--) {
							ways[cnt + 1][sum + x] += ways[cnt][sum];
						}
				}
			
			for (int man = 0; man <= n - 1; man++) {
				long goodWays = 0;
				for (int len = low; len <= high; len++)
					goodWays += ways[man][len];
				
				long totWays = c[n - 1][man];
				ans += man * (1.0 * goodWays / totWays);
			}
			
			
		}
		
		out.println(1.0 * ans / n);
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