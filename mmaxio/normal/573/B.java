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
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		
		int[] here = new int[n];
		
		int ans = 1;
		
		for (int i = 0, min = 1; i < n; i++) {
			min = Math.min(min, a[i] - i);
			here[i] = min + i;
		}
		
//		System.err.println(Arrays.toString(here));
		
		for (int i = n - 1, min = n; i >= 0; i--) {
			min = Math.min(min, a[i] + i);
			here[i] = Math.min(here[i], min - i);
		}
		
		for (int i = 0; i < n; i++) {
			ans = Math.max(ans, here[i]);
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