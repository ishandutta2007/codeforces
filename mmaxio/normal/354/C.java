import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		int[] a = new int[n];
		int maxVal = 0;
		int minVal = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			maxVal = Math.max(maxVal, a[i]);
			minVal = Math.min(minVal, a[i]);
		}

		int[] cnt = new int[maxVal + 1];
		for (int i = 0; i < n; i++) {
			cnt[a[i]]++;
		}

		for (int i = 1; i <= maxVal; i++) {
			cnt[i] += cnt[i - 1];
		}

		for (int ans = maxVal; ans > k; ans--) {
			// System.err.println(ans);
			int tot = 0;
			for (int from = ans; from <= maxVal; from += ans) {
				int to = Math.min(from + k, maxVal);
				tot += cnt[to] - cnt[from - 1];
			}
			if (tot == n) {
				out.println(ans);
				return;
			}
		}

		out.println(minVal);
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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