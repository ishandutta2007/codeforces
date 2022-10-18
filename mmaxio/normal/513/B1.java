import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	long go(int[] a, int fill, int n) {

		for (int i = 0; i + 1 < fill; i++) {
			if (a[i] > a[i + 1]) {
				if (a[i] != n - 1) {
					return 0;
				}
				boolean[] used = new boolean[n];
				for (int j = 0; j < i; j++) {
					used[a[j]] = true;
				}
				int cur = n - 2;
				for (int j = i + 1; j < fill; j++) {
					while (used[cur]) {
						cur--;
					}
					if (a[j] != cur) {
						return 0;
					}
					cur--;
				}
				return 1;
			}
		}

		int rest = (n - 1) - a[fill - 1];
		if (rest == 0) {
			return 1;
		}
		return 1L << (rest - 1);
	}

	void solve() throws IOException {
		int n = nextInt();
		long pos = nextLong();
		boolean[] used = new boolean[n];
		int[] ret = new int[n];
		outer: for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!used[j]) {
					ret[i] = j;
					long count = go(ret, i + 1, n);
//					System.err.println(Arrays.toString(Arrays
//							.copyOf(ret, i + 1)) + " " + count);
					if (count >= pos) {
						used[j] = true;
						continue outer;
					} else {
						pos -= count;
					}
				}
			}
		}
		for (int x : ret) {
			out.print(x + 1 + " ");
		}
		out.println();
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