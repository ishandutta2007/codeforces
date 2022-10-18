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
		int x = nextInt();
		
		long[] a = new long[n];
		
		for (int i = 0; i < n; i++) {
			a[i] = nextLong();
		}
		
		long[] pref = new long[n + 1];
		long[] suff = new long[n + 1];
		
		for (int i = 0; i < n; i++) {
			pref[i + 1] = pref[i] | a[i];
		}
		
		for (int i = n - 1; i >= 0; i--) {
			suff[i] = suff[i + 1] | a[i];
		}
		
		long ans = 0;
		for (int i = 0; i < n; i++) {
			long here = a[i];
			for (int j = 0; j < k; j++) {
				here *= x;
			}
			ans = Math.max(ans, here | pref[i] | suff[i + 1]);
		}
		
		out.println(ans);
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