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

		int[] left = new int[n];
		int[] right = new int[n];
		left[0] = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] > a[i - 1]) {
				left[i] = left[i - 1] + 1;
			} else {
				left[i] = 1;
			}
		}

		right[n - 1] = 1;
		for (int i = n - 2; i >= 0; i--) {
			if (a[i] < a[i + 1]) {
				right[i] = right[i + 1] + 1;
			} else {
				right[i] = 1;
			}
		}
		
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = Math.max(ans, left[i]);
			ans = Math.max(ans, right[i]);
			if (i != 0 && a[i] <= a[i - 1]) {
				ans = Math.max(ans, left[i - 1] + 1);
			}
			if (i != n - 1 && a[i] >= a[i + 1]) {
				ans = Math.max(ans, right[i + 1] + 1);
			}
			if (i != 0 && i != n - 1 && a[i + 1] - a[i - 1] >= 2) {
				ans = Math.max(ans, left[i - 1] + right[i + 1] + 1);
			}
		}
		
		out.println(ans);
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