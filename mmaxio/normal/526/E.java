import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int solve(long[] pref, int n, long x) {
		if (pref[n] <= x) {
			return 1;
		}
		int minLen = n + 1;
		int from = -1;
		int[] jumpLen = new int[n];
		for (int i = 0, j = 0; i < n; i++) {
			while (pref[j] - pref[i] <= x) {
				j++;
			}
			jumpLen[i] = j - i - 1;
			if (jumpLen[i] < minLen) {
				minLen = jumpLen[i];
				from = i;
			}
		}

//		System.err.println(minLen + " " + from);

		int ret = n + 1;
		for (int v = from; v <= from + minLen; v++) {

			int u = v;
			while (u >= n) {
				u -= n;
			}
			int jumps = 0;
			int steps = 0;
			while (steps < n) {
				steps += jumpLen[u];
				u += jumpLen[u];
				if (u >= n) {
					u -= n;
				}
				jumps++;
			}
			ret = Math.min(ret, jumps);
		}

		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int q = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		long[] pref = new long[2 * n + 1];
		for (int i = 0; i < n; i++) {
			pref[i + 1] = pref[i] + a[i];
		}
		for (int i = 0; i < n; i++) {
			pref[i + n + 1] = pref[i + n] + a[i];
		}
		while (q-- > 0) {
			long x = nextLong();
			out.println(solve(pref, n, x));
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