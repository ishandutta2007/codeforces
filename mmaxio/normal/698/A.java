import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		
		int dp0 = 0;
		int dp1 = 0;
		int dp2 = 0;
		
		for (int i = 0; i < n; i++) {
			int new0 = Math.max(Math.max(dp0, dp1), dp2);
			int new1 = new0;
			if ((a[i] == 2 || a[i] == 3)) {
				new1 = Math.max(new1, Math.max(dp0, dp2) + 1);
			}
			
			int new2 = new0;
			if ((a[i] == 1 || a[i] == 3)) {
				new2 = Math.max(new2, Math.max(dp0, dp1) + 1);
			}
			
			dp0 = new0;
			dp1 = new1;
			dp2 = new2;
		}
		
		out.println(n - Math.max(Math.max(dp0, dp1), dp2));
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
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