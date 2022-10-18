import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int LOG = 20;
	static final int N = 1 << LOG;
	static final int MOD = 1_000_000_007;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[N];
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			a[N - 1 - x]++;
		}

		for (int i = 0; i < LOG; ++i)
			for (int mask = 0; mask < N; mask++)
				if (test(mask, i)) {
					a[mask] = (a[mask] + a[mask ^ (1 << i)]) % MOD;
				}

		for (int i = 0, j = N - 1; i < j; i++, j--) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}

		int[] p2 = new int[n + 1];
		p2[0] = 1;
		for (int i = 0; i < n; i++) {
			p2[i + 1] = (p2[i] << 1) % MOD;
		}

		int ans = 0;
		
//		System.err.println(Arrays.toString(a));

		for (int i = 0; i < N; i++) {
			int val = p2[a[i]];
			if ((Integer.bitCount(i) & 1) == 0) {
				ans += val;
			} else {
				ans += MOD - val;
			}
			ans %= MOD;
		}

		out.println(ans);

	}

	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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