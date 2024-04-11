import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		long k = nextLong();

		long[] a = new long[n + 1];
		for (int i = 0; i <= n; i++) {
			a[i] = nextLong();
		}

		long[] b = Arrays.copyOf(a, n + 300);

		for (int i = 0; i < n; i++) {
			long delta = 0;
			if (b[i] < 0) {
				delta = -((-b[i] + 1) / 2);
			} else if (b[i] > 0) {
				delta = b[i] / 2;
			}
			if (delta != 0) {
				b[i] -= delta * 2;
				b[i + 1] += delta;
			}
		}

		if (b[n] < 0) {
			for (int i = 0; i <= n; i++) {
				a[i] = -a[i];
				b[i] = -b[i];
			}
		}

		boolean hasNeg = false;
		for (int i = 0; i < n; i++) {
			if (b[i] < 0) {
				hasNeg = true;
				break;
			}
		}

		if (hasNeg) {
			b[n]--;
			for (int i = 0; i < n; i++) {
				b[i]++;
			}

			int ptr = 0;
			while (b[ptr] == 1) {
				b[ptr] = 0;
				ptr++;
			}

			b[ptr] = 1;

		}

		int m = n;
		while (b[m] > 0) {
			b[m + 1] = b[m] / 2;
			b[m] %= 2;
			m++;
		}

		// find leftmost 1
		int ptr = 0;
		while (b[ptr] == 0) {
			ptr++;
		}

		long cur = 0;
		for (int i = b.length - 1; i >= ptr; i--) {
			cur = Math.min(2 * cur + b[i], 2 * k + 1);
		}

		int ans = 0;

		for (int i = ptr; i >= 0; i--) {
			if (cur > 2 * k) {
				break;
			}

			if (i <= n) {

				long res = a[i] - cur;

				if (!(i == n && res == 0)) {

					if (Math.abs(res) <= k) {
						ans++;
					}
				}
			}
			cur *= 2;
		}

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