import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();

		final int[] a = new int[n];
		for (int i = 0; i < m; i++) {
			a[i] = nextInt();
		}

		int pref = 0;
		int maxPref = 0;

		for (int i = 0; i < m; i++) {
			pref += a[i];
			maxPref += 2 * (n - 1 - i);
			if (pref > maxPref) {
				out.println("no");
				return;
			}
		}

		for (int i = m; i < n; i++) {
			maxPref += 2 * (n - 1 - i);
			int atLeast = ceilDiv(n * (n - 1) - pref, n - i);
			int atMost = maxPref - pref;
			if (i > 0) {
				atMost = Math.min(atMost, a[i - 1]);
			}
			if (atLeast > atMost) {
				out.println("no");
				return;
			}
			a[i] = atMost;
			pref += atMost;

		}
		
//		System.err.println(Arrays.toString(a));
		
		out.println("yes");

		Integer[] order = new Integer[n];
		for (int i = 0; i < n; i++) {
			order[i] = i;
		}

		Comparator<Integer> comp = (Integer i, Integer j) -> -Integer.compare(
				a[i], a[j]);

		char[][] ans = new char[n][n];
		for (int i = 0; i < n; i++) {
			ans[i][i] = 'X';
		}

		for (int i = 0; i < n; i++) {
			Arrays.sort(order, i, n, comp);

			int who = order[i];

			for (int j = n - 1; j > i; j--) {
				int opp = order[j];
				int count = Math.min(a[who], 2);
				ans[who][opp] = STRING.charAt(count);
				ans[opp][who] = STRING.charAt(2 - count);
				a[who] -= count;
				a[opp] -= 2 - count;
			}
		}

		for (int i = 0; i < n; i++) {
			out.println(ans[i]);
		}
	}

	static final String STRING = "LDW";

	int ceilDiv(int a, int b) {
		return (a + b - 1) / b;
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