import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int a = nextInt();
		char[] s = nextToken().toCharArray();
		int n = s.length;

		int[] sum = new int[s.length + 1];
		for (int i = 0; i < s.length; i++) {
			sum[i + 1] = sum[i] + (s[i] - '0');
		}

		int[] cnt = new int[10 * s.length + 1];
		for (int i = 0; i < s.length; i++) {
			for (int j = i + 1; j <= s.length; j++) {
				cnt[sum[j] - sum[i]]++;
			}
		}

		if (a == 0) {
			long tot = n * (n + 1) / 2;
			long notNull = tot - cnt[0];
			out.println(tot * tot - notNull * notNull);
			return;
		}

		// System.err.println(Arrays.toString(cnt));

		long ans = 0;
		for (int x = 1; x * x <= a; x++) {
			if (a % x == 0) {
				if (x <= 10 * s.length && a / x <= 10 * s.length) {
					long add = (long) cnt[x] * cnt[a / x];
					if (x * x != a) {
						ans += 2 * add;
					} else {
						ans += add;
					}
				}
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