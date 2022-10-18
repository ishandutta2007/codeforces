import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int BITS = 20;

	boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	static final int INF = Integer.MAX_VALUE / 2;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();

		int[][] next = new int[n][BITS];
		int[] last = new int[BITS];
		Arrays.fill(last, INF);
		for (int i = n - 1; i >= 0; i--) {
			System.arraycopy(last, 0, next[i], 0, BITS);
			for (int j = 0; j < BITS; j++) {
				if (test(a[i], j))
					last[j] = i;
			}
		}

		boolean[] have = new boolean[1 << BITS];
		for (int i = 0; i < n; i++) {
			int pos = i;
			int num = a[i];
			while (true) {
				have[num] = true;
				int jump = INF;
				for (int j = 0; j < BITS; j++) {
					if (!test(num, j))
						jump = Math.min(jump, next[pos][j]);
				}
				if (jump == INF)
					break;
				pos = jump;
				num |= a[pos];
			}
		}

		int ans = 0;
		for (int i = 0; i < have.length; i++)
			if (have[i])
				ans++;

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