import java.io.*;
import java.util.*;

public class E_slow {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Cell implements Comparable<Cell> {
		int x, y;
		int bad;

		public Cell(int x, int y, int bad) {
			this.x = x;
			this.y = y;
			this.bad = bad;
		}

		@Override
		public int compareTo(Cell o) {
			return Integer.compare(x + y, o.x + o.y);
		}
	}

	static final int MAX_K = 22;
	static final int P = 1_000_000_007;
	static final long P2 = (Long.MAX_VALUE / P - P) * P;

	int[] fact, invFact;

	void solve() throws IOException {
		int r = nextInt();
		int c = nextInt();
		int n = nextInt();
		int s = nextInt();

		if (r == 1 && c == 1) {
			out.println(n == 1 ? ((s + 1) / 2) : s);
			return;
		}

		Cell[] a = new Cell[n + 2];

		boolean seenStart = false;
		boolean seenEnd = false;

		for (int i = 0; i < n; i++) {
			a[i] = new Cell(nextInt() - 1, nextInt() - 1, 1);
			seenStart |= (a[i].x + a[i].y == 0);
			seenEnd |= (a[i].x + a[i].y == r - 1 + c - 1);
		}

		int ptr = n;
		if (!seenStart) {
			a[ptr] = new Cell(0, 0, 0);
			ptr++;
		}

		if (!seenEnd) {
			a[ptr] = new Cell(r - 1, c - 1, 0);
			ptr++;
		}

		n = ptr;
		a = Arrays.copyOf(a, n);

		fact = new int[r + c + 1];
		fact[0] = 1;
		for (int i = 1; i < fact.length; i++) {
			fact[i] = (int) ((long) i * fact[i - 1] % P);
		}

		int[] inv = new int[fact.length];
		inv[0] = 0;
		inv[1] = 1;
		for (int i = 2; i < inv.length; i++) {
			inv[i] = P - (int) ((long) (P / i) * inv[P % i] % P);
		}

		invFact = new int[inv.length];
		invFact[0] = 1;
		for (int i = 1; i < invFact.length; i++) {
			invFact[i] = (int) ((long) inv[i] * invFact[i - 1] % P);
		}

		Arrays.sort(a);

		int add = a[0].bad + a[n - 1].bad;

		int[][] dp = new int[n][MAX_K];
		for (int i = 1; i < n; i++) {

			int[] waysFrom = new int[i];
			for (int j = 0; j < i; j++) {
				waysFrom[j] = getWays(a[i].x - a[j].x, a[i].y - a[j].y);
			}

			long prev = waysFrom[0];

			for (int j = 0; j < MAX_K; j++) {
				long cur = 0;
				for (int mid = 1; mid < i; mid++) {
					cur += (long) dp[mid][j] * waysFrom[mid];
					if (cur >= P2) {
						cur -= P2;
					}

					// cur -= ((~(cur - P2)) >> 63) & P2;
				}

				dp[i][j] = (int) ((prev - cur) % P);
				if (dp[i][j] < 0) {
					dp[i][j] += P;
				}
				prev = cur;
			}

			// System.err.println(a[i].x + " " + a[i].y + " " +
			// Arrays.toString(dp[i]));
		}

		int ans = 0;

		for (int i = 0; i < add; i++) {
			s = (s + 1) / 2;
		}

		for (int i = 0; i < MAX_K; i++) {
			ans += (int) ((long) dp[n - 1][i] * s % P);
			if (ans >= P) {
				ans -= P;
			}

			s = (s + 1) / 2;
		}

		int more = 0;
		for (int i = 1; i < n - 1; i++) {
			more += (int) ((long) dp[i][MAX_K - 1]
					* getWays(a[n - 1].x - a[i].x, a[n - 1].y - a[i].y) % P);
			if (more >= P) {
				more -= P;
			}
		}

		ans += more;
		if (ans >= P) {
			ans -= P;
		}

		ans = (int) ((long) ans * invFact[r - 1 + c - 1] % P * fact[r - 1] % P
				* fact[c - 1] % P);

		out.println(ans);

	}

	int getWays(int dx, int dy) {
		return (dx < 0 || dy < 0) ? 0 : (int) ((long) fact[dx + dy]
				* invFact[dx] % P * invFact[dy] % P);
	}

	E_slow() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E_slow();
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