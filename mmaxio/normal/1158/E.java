import java.io.*;
import java.util.*;

public class cf559E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	interface Interactor {
		int getN();

		char[] ask(int[] d);

		void answer(int[] es);
	}

	abstract class LocalInteractor implements Interactor {

		int qryCount;

		int[][] g;
		int n;

		int[] es;

		void prepare() {
			n = (es.length / 2) + 1;
			g = new int[n][n];
			for (int i = 0; i < n; i++) {
				Arrays.fill(g[i], 100000);
				g[i][i] = 0;
			}
			for (int i = 0; i < es.length; i += 2) {
				int v = es[i];
				int u = es[i + 1];
				g[v][u] = g[u][v] = 1;
			}
			for (int k = 0; k < n; k++) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
					}
				}
			}
		}

		public int getN() {
			prepare();
			return n;
		}

		@Override
		public char[] ask(int[] d) {
			++qryCount;
			if (qryCount > 80) {
				throw new AssertionError("too many queries");
			}
			if (d.length != n) {
				throw new AssertionError("bad array length");
			}

			for (int i = 0; i < n; i++) {
				if (d[i] < 0 || d[i] >= n) {
					throw new AssertionError("bad values in array");
				}
			}
			char[] ret = new char[n];
			Arrays.fill(ret, '0');
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i != j && g[i][j] <= d[j]) {
						ret[i] = '1';
					}
				}
			}
			return ret;
		}

		@Override
		public void answer(int[] es) {
			if (es.length != 2 * n - 2) {
				throw new AssertionError("bad answer length");
			}

			if (Arrays.equals(fix(es), fix(this.es))) {
				System.err.println("OK " + qryCount + " queries");
			} else {
				System.err.println("got " + Arrays.toString(es));
				System.err.println("was " + Arrays.toString(this.es));
				throw new AssertionError("WA");
			}
		}

		int[] fix(int[] es) {
			// System.err.println(Arrays.toString(es));
			int[] a = new int[es.length / 2];
			for (int i = 0; i < es.length; i += 2) {
				int v = es[i];
				int u = es[i + 1];
				if (v == u || Math.min(v, u) < 0 || Math.max(v, u) >= n) {
					throw new AssertionError(
							"bad edge(might be interactor PepeLaugh)");
				}
				if (v > u) {
					int tmp = v;
					v = u;
					u = tmp;
				}
				a[i / 2] = v * n + u;
			}
			Arrays.sort(a);
			return a;
		}

	}

	static final Random rng = new Random();

	int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	class RandomLocalInteractor extends LocalInteractor {

		public RandomLocalInteractor(int n) {
			int[] par = new int[n];
			for (int i = 1; i < n; i++) {
				par[i] = rand(0, i - 1);
			}

			int[] perm = new int[n];
			for (int i = 0; i < n; i++) {
				int j = rand(0, i);
				perm[i] = perm[j];
				perm[j] = i;
			}

			es = new int[2 * n - 2];
			for (int i = 0; i < n - 1; i++) {
				es[2 * i] = perm[i + 1];
				es[2 * i + 1] = perm[par[i + 1]];
			}
		}

	}

	class FixedLocalInteractor extends LocalInteractor {

		public FixedLocalInteractor(int[] es) {
			this.es = es;
		}

	}

	class SubmitInteractor implements Interactor {

		@Override
		public char[] ask(int[] d) {
			out.print("?");
			for (int x : d) {
				out.print(" " + x);
			}
			out.println();
			out.flush();
			return nextToken().toCharArray();
		}

		@Override
		public void answer(int[] es) {
			out.println("!");
			for (int i = 0; i < es.length; i += 2) {
				out.println((es[i] + 1) + " " + (es[i + 1] + 1));
			}
		}

		@Override
		public int getN() {
			return nextInt();
		}
	}

	void go(Interactor it) {
		int n = it.getN();

		// if (n == 2) {
		// it.ask(new int[] { 0, 1 });
		// }

		boolean[] fix = new boolean[n];
		int[] dist = new int[n];
		ArrayList<Integer> fixDist = new ArrayList<>();

		fix[0] = true;
		fixDist.add(0);
		fixDist.add(n);

		while (true) {
			boolean stop = true;
			for (int i = 0; i < fixDist.size() - 1; i++) {
				if (fixDist.get(i + 1) - fixDist.get(i) > 2) {
					stop = false;
					break;
				}
			}
			if (stop) {
				break;
			}

			ArrayList<Integer> newFixDist = new ArrayList<>(fixDist);
			ArrayList<Integer> newInfo = new ArrayList<>();

			for (int z = 0; z < 2; z++) {

				int[] q1 = new int[n];
				int[] q2 = new int[n];

				for (int i = z; i < fixDist.size() - 1; i += 2) {
					int l = fixDist.get(i);
					int r = fixDist.get(i + 1);
					if (r - l <= 2) {
						continue;
					}
					int m = (l + r) >> 1;

					newFixDist.add(m);

					for (int v = 0; v < n; v++) {
						if (dist[v] == l && fix[v]) {
							q1[v] = m - l;
							q2[v] = m - l - 1;
						}
					}
				}

				char[] r1 = it.ask(q1);
				char[] r2 = it.ask(q2);

				for (int v = 0; v < n; v++) {
					if (fix[v]) {
						continue;
					}

					int idx = Collections.binarySearch(fixDist, dist[v]);

					if (idx % 2 != z) {
						continue;
					}

					int newD = (fixDist.get(idx) + fixDist.get(idx + 1)) >> 1;

					if (fixDist.get(idx + 1) - fixDist.get(idx) == 2) {
						newInfo.add(v);
						newInfo.add(newD);
						newInfo.add(1);
						continue;
					}

					if (r1[v] == '1' && r2[v] == '0') {
						newInfo.add(v);
						newInfo.add(newD);
						newInfo.add(1);
					} else if (r1[v] == '0' && r2[v] == '0') {
						newInfo.add(v);
						newInfo.add(newD);
						newInfo.add(0);
					} else if (r1[v] == '1' && r2[v] == '1') {

					} else {
						throw new AssertionError();
					}
				}
			}

			Collections.sort(newFixDist);
			fixDist = newFixDist;

			for (int i = 0; i < newInfo.size(); i += 3) {
				int v = newInfo.get(i);
				int d = newInfo.get(i + 1);
				int fixed = newInfo.get(i + 2);
				fix[v] = fixed == 1;
				dist[v] = d;
			}

			// System.err.println(fixDist);
			// System.err.println(Arrays.toString(fix));
			// System.err.println(Arrays.toString(dist));
		}

		for (int i = 0; i < n; i++) {
			if (!fix[i]) {
				dist[i]++;
			}
		}

		// System.err.println(Arrays.toString(dist));

		ArrayList<Integer>[] byD = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			byD[i] = new ArrayList<>();
		}

		for (int i = 0; i < n; i++) {
			byD[dist[i]].add(i);
		}

		int[] es = new int[2 * n - 2];

		for (int z = 0; z < 3; z++) {
			int maxSz = 0;
			for (int i = z; i < n; i += 3) {
				maxSz = Math.max(maxSz, byD[i].size());
			}

			ArrayList<char[]> ans = new ArrayList<>();

			// 4 -> 2, 5 -> 3

			for (int bit = 0; 1 << bit < maxSz; bit++) {
				int[] qry = new int[n];
				for (int i = z; i < n; i += 3) {
					for (int j = 0; j < byD[i].size(); j++) {
						if (test(j, bit)) {
							qry[byD[i].get(j)] = 1;
						}
					}
				}
				ans.add(it.ask(qry));
			}

			for (int i = z + 1; i < n; i += 3) {
				for (int v : byD[i]) {
					int mask = 0;
					for (int j = 0; j < ans.size(); j++) {
						if (ans.get(j)[v] == '1') {
							mask |= 1 << j;
						}
					}
					es[2 * (v - 1)] = v;
					es[2 * (v - 1) + 1] = byD[i - 1].get(mask);
				}
			}
		}

		// 1 -> 0
		// 2 -> 1
		// 3 -> 1
		// 8 -> 2
		// 9 -> 3
		// 10 -> 3

		it.answer(es);
	}

	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	// 0 1 2 3 4 5 6 7

	// ask 1357, 2367, 4567
	//

	void solve() throws IOException {
		// go(new FixedLocalInteractor(new int[] {
		// 0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8}));
//		for (int n = 2; n <= 1000; n++) {
//			System.err.println("n = " + n);
//			for (int i = 0; i < 10; i++) {
//				go(new RandomLocalInteractor(1000 -i));
//			}
//		}
//		go(new RandomLocalInteractor(750));
		go(new SubmitInteractor());
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new cf559E().inp();
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