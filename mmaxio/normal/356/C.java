import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] p;

	int calc(int val, int low, int high) {
		int ret = 0;
		for (int i = 0; i < 5; i++) {
			int from = Math.max(low, p[i]);
			int to = Math.min(high, p[i + 1]);
			if (from < to) {
				ret += (to - from) * Math.abs(val - i);
			}
		}
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[5];

		int tot = 0;
		for (int i = 0; i < n; i++) {
			int cnt = nextInt();
			a[cnt]++;
			tot += cnt;
		}

		// MAGICK(with k!)
		p = new int[6];
		for (int i = 0; i < 5; i++) {
			p[i + 1] = p[i] + a[i];
		}

		int ans = Integer.MAX_VALUE;
		for (int c3 = 0; c3 * 3 <= tot; c3++) {
			if (((tot - 3 * c3) % 4) != 0) {
				continue;
			}
			int c4 = (tot - 3 * c3) / 4;
			if (c3 + c4 > n) {
				continue;
			}
			int c0 = n - c3 - c4;

			int cur = calc(0, 0, c0) + calc(3, c0, c0 + c3)
					+ calc(4, c0 + c3, c0 + c3 + c4);
			ans = Math.min(ans, cur / 2);
		}
		if (ans == Integer.MAX_VALUE)
			ans = -1;
		out.println(ans);

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