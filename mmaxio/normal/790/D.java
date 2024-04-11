import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int slow(int[][] a) {
		int n = a[0].length;

		long[] p1 = new long[n + 1];
		long[] p2 = new long[n + 1];
		long[] pBoth = new long[n + 1];

		for (int i = 0; i < n; i++) {
			p1[i + 1] = p1[i] + a[0][i];
			p2[i + 1] = p2[i] + a[1][i];
			pBoth[i + 1] = p1[i + 1] + p2[i + 1];
		}

		// System.err.println(Arrays.toString(p1));
		// System.err.println(Arrays.toString(p2));
		// System.err.println(Arrays.toString(pBoth));

		int[][] dp = new int[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {

				if (i + 1 <= n) {
					dp[i + 1][j] = Math.max(dp[i + 1][j], dp[i][j]);
				}
				if (j + 1 <= n) {
					dp[i][j + 1] = Math.max(dp[i][j + 1], dp[i][j]);
				}

				for (int toI = i + 1; toI <= n; toI++) {
					if (p1[i] == p1[toI]) {
						dp[toI][j] = Math.max(dp[toI][j], dp[i][j] + 1);
					}
				}

				for (int toJ = j + 1; toJ <= n; toJ++) {
					if (p2[j] == p2[toJ]) {
						dp[i][toJ] = Math.max(dp[i][toJ], dp[i][j] + 1);
					}
				}

				if (i == j) {
					for (int to = i + 1; to <= n; to++) {
						if (pBoth[to] == pBoth[i]) {
							dp[to][to] = Math.max(dp[to][to], dp[i][i] + 1);
						}
					}
				}

			}
		}

		// System.err.println(Arrays.deepToString(dp));

		return dp[n][n];
	}

	static class State implements Comparable<State> {
		int x, y, min, max;

		public State(int x, int y) {
			this.x = x;
			this.y = y;
			min = Math.min(x, y);
			max = Math.max(x, y);
		}

		@Override
		public int compareTo(State o) {
			if (min != o.min) {
				return min < o.min ? -1 : 1;
			}
			if (max != o.max) {
				return max < o.max ? -1 : 1;
			}
			return Integer.compare(x, o.x);
		}

		@Override
		public String toString() {
			return "(" + x + ", " + y + ")";
		}

	}

	int fast(int[][] a) {
		int n = a[0].length;

		long[] p1 = new long[n + 1];
		long[] p2 = new long[n + 1];
		long[] pBoth = new long[n + 1];

		for (int i = 0; i < n; i++) {
			p1[i + 1] = p1[i] + a[0][i];
			p2[i + 1] = p2[i] + a[1][i];
			pBoth[i + 1] = p1[i + 1] + p2[i + 1];
		}

		int[] nxt1 = genNext(p1);
		int[] nxt2 = genNext(p2);
		int[] nxtBoth = genNext(pBoth);

		// System.err.println(Arrays.toString(nxt1));
		// System.err.println(Arrays.toString(nxt2));
		// System.err.println(Arrays.toString(nxtBoth));

		TreeMap<State, Integer> map = new TreeMap<>();
		int[] dp = new int[n + 1];
		dp[0] = 0;
		map.put(new State(0, 0), 0);

		boolean[] hadX = new boolean[n + 1];
		boolean[] hadY = new boolean[n + 1];

		int ptr = 0;

		while (!map.isEmpty()) {
			Map.Entry<State, Integer> e = map.pollFirstEntry();
			State s = e.getKey();
			int val = e.getValue();

			while (ptr < s.min) {
				dp[ptr + 1] = dp[ptr];
				ptr++;
			}

			if (s.x == s.y) {
				if (val < dp[s.x]) {
					val = dp[s.x];
				} else if (val > dp[s.x]) {
					dp[s.x] = val;
				}
				State goX = new State(nxt1[s.x], s.y);
				if (goX.x <= n) {
					Integer prev = map.get(goX);
					if (prev == null) {
						prev = -1;
					}
					map.put(goX, Math.max(prev, val + 1));
				}
				State goY = new State(s.x, nxt2[s.y]);
				if (goY.y <= n) {
					Integer prev = map.get(goY);
					if (prev == null) {
						prev = -1;
					}
					map.put(goY, Math.max(prev, val + 1));
				}
				State goBoth = new State(nxtBoth[s.x], nxtBoth[s.x]);
				if (goBoth.x <= n) {
					Integer prev = map.get(goBoth);
					if (prev == null) {
						prev = -1;
					}
					map.put(goBoth, Math.max(prev, val + 1));
				}
			} else if (s.x < s.y) {
				if (val <= dp[s.x]) {
					continue;
				}
				if (hadY[s.x]) {
					continue;
				}
				hadY[s.x] = true;

				State makeSame = new State(s.y, s.y);
				{
					Integer prev = map.get(makeSame);
					if (prev == null) {
						prev = -1;
					}
					map.put(makeSame, Math.max(prev, val));
				}
				State goX = new State(nxt1[s.x], s.y);
				if (goX.x <= n) {
					Integer prev = map.get(goX);
					if (prev == null) {
						prev = -1;
					}
					map.put(goX, Math.max(prev, val + 1));
				}
			} else { // s.x > s.y
				if (val <= dp[s.y]) {
					continue;
				}
				if (hadX[s.y]) {
					continue;
				}
				hadX[s.y] = true;

				State makeSame = new State(s.x, s.x);
				{
					Integer prev = map.get(makeSame);
					if (prev == null) {
						prev = -1;
					}
					map.put(makeSame, Math.max(prev, val));
				}
				State goY = new State(s.x, nxt2[s.y]);
				if (goY.y <= n) {
					Integer prev = map.get(goY);
					if (prev == null) {
						prev = -1;
					}
					map.put(goY, Math.max(prev, val + 1));
				}

			}
		}

		int ret = 0;
		for (int i = 0; i <= n; i++) {
			ret = Math.max(ret, dp[i]);
		}

		return ret;
	}

	int[] genNext(long[] a) {
		HashMap<Long, Integer> map = new HashMap<>();
		int n = a.length;
		int[] nxt = new int[n + 1];

		Arrays.fill(nxt, n);

		int from = 0;

		for (int i = 0; i < n; i++) {
			if (map.containsKey(a[i])) {
				int where = map.get(a[i]);
				nxt[where] = i;
				while (from <= where) {
					map.remove(a[from]);
					from++;
				}
			}
			map.put(a[i], i);
		}

		int lastNotBad = n;
		for (int i = n - 1; i >= 0; i--) {
			if (nxt[i] != n) {
				lastNotBad = nxt[i];
			} else {
				nxt[i] = lastNotBad;
			}
		}

		return nxt;
	}

	void submit() throws IOException {
		int n = nextInt();

		int[][] a = new int[2][n];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = nextInt();
			}
		}

		out.println(fast(a));
	}

	static final Random rng = new Random();
	static final int B = 3;

	void stress() {
		for (int tst = 0;; tst++) {
			int n = rng.nextInt(50) + 1;
			int[][] a = new int[2][n];
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < n; j++) {
					a[i][j] = rng.nextInt(2 * B + 1) - B;
				}
			}

			int fast = fast(a);
			int slow = slow(a);
			if (fast != slow) {
				System.err.println(Arrays.deepToString(a));
				System.err.println(fast);
				System.err.println(slow);
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		 submit();
//		stress();
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