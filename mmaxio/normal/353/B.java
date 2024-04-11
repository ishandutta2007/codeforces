import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int MIN = 10;
	static final int MAX = 100;
	static final int SIZE = MAX - MIN;

	void solve() throws IOException {
		int n = nextInt();

		int[] cnt = new int[SIZE];

		int[] a = new int[2 * n];
		for (int i = 0; i < 2 * n; i++) {
			a[i] = nextInt();
			cnt[a[i] - MIN]++;
		}

		int both = 0;
		int one = 0;

		for (int i = 0; i < SIZE; i++) {
			if (cnt[i] > 1)
				both++;
			else if (cnt[i] == 1)
				one++;
		}

		int oneHalf = one / 2;

		int outp = (both + (one - oneHalf)) * (both + oneHalf);

		out.println(outp);

		int cntOneHalf = 0;
		int[] was = new int[SIZE];

		int left1 = n;
		int left2 = n;

		int[] ans = new int[2 * n];
		for (int i = 0; i < 2 * n; i++) {
			int x = a[i] - MIN;
			if (cnt[x] == 1) {
				ans[i] = (cntOneHalf < oneHalf) ? 1 : 2;
				if (ans[i] == 1)
					left1--;
				else
					left2--;
				cntOneHalf++;
			} else {
				if (was[x] == 0) {
					ans[i] = 1;
					was[x]++;
					left1--;
				} else if (was[x] == 1) {
					ans[i] = 2;
					was[x]++;
					left2--;
				}
			}
		}

		if (left1 < 0 || left2 < 0)
			throw new AssertionError();

		for (int i = 0; i < 2 * n; i++) {
			if (ans[i] == 0) {
				if (left1 > 0) {
					ans[i] = 1;
					left1--;
				} else {
					ans[i] = 2;
					left2--;
				}
			}
		}

		if (left1 != 0 || left2 != 0) {
			throw new AssertionError();
		}

		for (int i = 0; i < 2 * n; i++) {
			out.print(ans[i] + " ");
		}
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