import java.io.*;
import java.util.*;

public class C {

	static class State {
		int[] pos;

		@Override
		public int hashCode() {
			int r = 0;
			for (int x : pos) {
				r = r * 8 + x;
			}
			return r;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			State other = (State) obj;
			if (!Arrays.equals(pos, other.pos))
				return false;
			return true;
		}

		public State(int[] pos) {
			this.pos = pos;
		}

	}

	void submit() {
		int x = nextInt();
		int k = nextInt();
		int n = nextInt();
		int q = nextInt();

		int[] costs = new int[k + 1];
		for (int i = 1; i <= k; i++) {
			costs[i] = nextInt();
		}

		HashMap<State, Integer> all = new HashMap<>();
		int[] tmp = new int[x];
		for (int i = 0; i < x; i++) {
			tmp[i] = i;
		}

		do {
			if (tmp[0] != 0) {
				break;
			}
			all.put(new State(tmp.clone()), all.size());
		} while (nextCombination(tmp, k));

		int S = all.size();
		List<Integer>[] g = new ArrayList[S];

		int maxDelta = 0;

		for (Map.Entry<State, Integer> e : all.entrySet()) {
			tmp = e.getKey().pos;
			int v = e.getValue();
			g[v] = new ArrayList<>();

			outer: for (int z = 1; z <= k; z++) {
				int[] newPos = tmp.clone();
				newPos[0] += z;
				Arrays.sort(newPos);
				for (int i = 0; i < newPos.length - 1; i++) {
					if (newPos[i] == newPos[i + 1]) {
						continue outer;
					}
				}

				int delta = newPos[0];
				maxDelta = Math.max(maxDelta, delta);
				for (int i = 0; i < newPos.length; i++) {
					newPos[i] -= delta;
				}

				// System.err.println(Arrays.toString(tmp));
				// System.err.println(z);
				// System.err.println(Arrays.toString(newPos));

				int idxTo = all.get(new State(newPos));
				g[v].add(idxTo);
				g[v].add(delta);
				g[v].add(z);
			}
		}

		int M = S * maxDelta;

		long[][] m = new long[M][M];

		for (long[] row : m) {
			Arrays.fill(row, INF);
		}

		for (int i = 1; i < maxDelta; i++) {
			for (int idx = 0; idx < S; idx++) {
				int from = i * S + idx;
				int to = (i - 1) * S + idx;
				m[from][to] = Math.min(m[from][to], 0);
			}
		}

		for (int v = 0; v < S; v++) {
			for (int i = 0; i < g[v].size(); i += 3) {
				int u = g[v].get(i);
				int delta = g[v].get(i + 1);
				int jumpLen = g[v].get(i + 2);

				int from = (maxDelta - delta) * S + v;
				int to = (maxDelta - 1) * S + u;

				m[from][to] = Math.min(m[from][to], costs[jumpLen]);
			}
		}

		HashMap<Integer, Integer> spMap = new HashMap<>();

		Special[] ss = new Special[q];
		for (int i = 0; i < q; i++) {
			int p = nextInt();
			int cost = nextInt();
			spMap.put(p, cost);
			ss[i] = new Special(p, cost);
		}

		long[] dp = new long[M];

		Arrays.fill(dp, INF);

		dp[(maxDelta - 1) * S + 0] = 0;
		int posDp = 2 - maxDelta; // posDp is THE FIRST ROW

		long[][][] powM = new long[28][][];
		powM[0] = m;
		for (int i = 1; i < powM.length; i++) {
			powM[i] = mult(powM[i - 1], powM[i - 1]);
		}

		while (posDp < n - x + 1) {

			boolean isSpecial = false;

			// !!!!!!!!!!!!!!!! I DON'T KNOW

			for (Special sp : ss) {
				if (posDp + 1 <= sp.idx && posDp + 2 * k >= sp.idx) {
					isSpecial = true;
				}
			}

			if (isSpecial) {
				long[] newDp = new long[M];
				Arrays.fill(newDp, INF);
				for (int i = 1; i < maxDelta; i++) {
					for (int idx = 0; idx < S; idx++) {
						int from = i * S + idx;
						int to = (i - 1) * S + idx;
						newDp[to] = Math.min(newDp[to], dp[from]);
					}
				}

				for (int v = 0; v < S; v++) {
					for (int i = 0; i < g[v].size(); i += 3) {
						int u = g[v].get(i);
						int delta = g[v].get(i + 1);
						int jumpLen = g[v].get(i + 2);

						int from = (maxDelta - delta) * S + v;
						int to = (maxDelta - 1) * S + u;

						long cost = costs[jumpLen];
						cost += spMap.getOrDefault(posDp + maxDelta - delta
								+ jumpLen, 0);
						newDp[to] = Math.min(newDp[to], dp[from] + cost);
					}
				}

				dp = newDp;
				posDp++;

				continue;
			}

			int nxtPosDp = n - x + 1;

			for (Special sp : ss) {
				if (sp.idx - 2 * k > posDp) {
					nxtPosDp = Math.min(nxtPosDp, sp.idx - 2 * k);
				}
			}

			int steps = nxtPosDp - posDp;

			for (int iter = 0; steps > 0; iter++) {
				if (steps % 2 == 1) {

					long[] nxtDp = new long[M];
					Arrays.fill(nxtDp, INF);

					long[][] tr = powM[iter];
					for (int i = 0; i < M; i++) {
						for (int j = 0; j < M; j++) {
							nxtDp[j] = Math.min(nxtDp[j], dp[i] + tr[i][j]);
						}
					}
					dp = nxtDp;
				}
				steps >>= 1;
			}

			posDp = nxtPosDp;

		}

		out.println(dp[0]);
	}

	static class Special implements Comparable<Special> {
		int idx;
		long cost;

		public Special(int idx, long cost) {
			this.idx = idx;
			this.cost = cost;
		}

		@Override
		public int compareTo(Special o) {
			return Integer.compare(idx, o.idx);
		}
	}

	long[][] mult(long[][] a, long[][] b) {
		int n = a.length;
		long[][] trB = new long[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				trB[i][j] = b[j][i];
			}
		}
		long[][] c = new long[n][n];
		for (int i = 0; i < n; i++) {
			long[] A = a[i];
			for (int j = 0; j < n; j++) {
				long[] B = trB[j];
				long tmp = INF;
				for (int k = 0; k < n; k++) {
					tmp = Math.min(tmp, A[k] + B[k]);
				}
				c[i][j] = tmp;
			}
		}
		return c;
	}

	static final long INF = Long.MAX_VALUE / 3;

	static boolean nextCombination(int[] a, int n) {
		int k = a.length;
		int ptr = k - 1;
		while (ptr >= 0 && a[ptr] == ptr - k + n) {
			ptr--;
		}
		if (ptr < 0) {
			return false;
		}
		a[ptr]++;
		for (int i = ptr + 1; i < k; i++) {
			a[i] = a[ptr] + i - ptr;
		}
		return true;
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new C();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}