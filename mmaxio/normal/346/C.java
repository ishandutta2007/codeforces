import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] unique(int[] a) {
		Arrays.sort(a);
		int sz = 1;
		for (int i = 1; i < a.length; i++) {
			if (a[sz - 1] != a[i]) {
				a[sz++] = a[i];
			}
		}

		return Arrays.copyOf(a, sz);
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] xs = new int[n];
		for (int i = 0; i < n; i++) {
			xs[i] = nextInt();
		}

		xs = unique(xs);

		int a = nextInt();
		int b = nextInt();

		int[] canGo = new int[a - b + 1];
		Arrays.fill(canGo, Integer.MAX_VALUE);
		for (int i = 0; i < xs.length; i++) {
			int x = xs[i];
			int st = (b + x - 1) / x * x;
			for (int j = st; j <= a; j += x) {
				int ind = Math.min(j + x - 1, a) - b;
				canGo[ind] = Math.min(canGo[ind], j);
			}
		}

		int ans = 0;

		int curPos = a;
		int minReach = Integer.MAX_VALUE;
		for (int i = a; i > b; i--) {
			minReach = Math.min(minReach, Math.min(canGo[i - b], i - 1));
			if (i == curPos) {
				ans++;
				curPos = minReach;
			}
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