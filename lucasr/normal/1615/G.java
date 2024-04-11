import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Set;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.ArrayDeque;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lucasr
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		MyScanner in = new MyScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		GMaximumAdjacentPairs solver = new GMaximumAdjacentPairs();
		solver.solve(1, in, out);
		out.close();
	}

	static class GMaximumAdjacentPairs {
		public static int MAX = 600;
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			GMaximumAdjacentPairs.sc = sc;
			GMaximumAdjacentPairs.out = out;
			int n = sc.nextInt();
			int[] vals = sc.nextIntArray(n);
			boolean[] used = new boolean[n + 1];
			List<GMaximumAdjacentPairs.Pair> and = new ArrayList<>();
			int SIZE = Math.min(MAX, n) + 1;
			List<GMaximumAdjacentPairs.Pair>[] orAdj = new List[SIZE];
			for (int i = 0; i < orAdj.length; i++) {
				orAdj[i] = new ArrayList<>();
			}

			boolean got = false;
			for (int i = 0; i < n; i++) {
				if (vals[i] != 0) {
					got = true;
					if (i + 1 < n && vals[i] == vals[i + 1]) {
						used[vals[i]] = true;
					}
				}
			}
			if (got) {
				int from = -1, to = -1;
				for (int i = 0; i + 1 < n; i += 2) {
					if (vals[i] != 0) {
						from = i;
						break;
					}
					if (vals[i + 1] != 0) {
						vals[i] = vals[i + 1];
						used[vals[i]] = true;
						from = i;
						break;
					}
				}
				for (int i = n - 1; i > 0; i -= 2) {
					if (vals[i] != 0) {
						to = i + 1;
						break;
					}
					if (vals[i - 1] != 0) {
						vals[i] = vals[i - 1];
						used[vals[i - 1]] = true;
						to = i + 1;
						break;
					}
				}
				UnionFind uf = new UnionFind(SIZE);
				List<GMaximumAdjacentPairs.Pair> cycleEdge = new ArrayList<>();
				boolean[] inOr = new boolean[SIZE];
				for (int i = from; i < to; i++) {
					if (vals[i] == 0) {
						int j = i;
						while (vals[j] == 0) j++;
						// [i, j)
						int size = j - i;
						GMaximumAdjacentPairs.Pair pair = new GMaximumAdjacentPairs.Pair(i, j - 1, vals[i - 1], vals[j]);
						if (vals[i - 1] != vals[j]) {
							if (size % 2 == 1) {
								orAdj[vals[i - 1]].add(pair);
								orAdj[vals[j]].add(pair);
								inOr[vals[i - 1]] = inOr[vals[j]] = true;
								if (!uf.union(vals[i - 1], vals[j])) {
									cycleEdge.add(pair);
								}
							} else {
								and.add(pair);
							}
						} else if (size % 2 == 1) {
							vals[i] = vals[i - 1];
							used[vals[i]] = true;
						}
						i = j;
					}
				}
				for (GMaximumAdjacentPairs.Pair edge : cycleEdge) {
					if (inOr[edge.val1]) {
						int rep = uf.find(edge.val1);
						for (int i = 1; i < SIZE; i++) {
							if (uf.find(i) == rep) inOr[i] = false;
						}
						edge.choose(edge.val1, vals, used);
						visit(edge.val1, orAdj, used, vals, edge);
					}
				}
				for (int i = 1; i < SIZE; i++) {
					if (used[i] && inOr[i]) {
						int rep = uf.find(i);
						for (int j = 1; j < SIZE; j++) {
							if (uf.find(j) == rep) inOr[j] = false;
						}
						visit(i, orAdj, used, vals, null);
					}
				}
				Blossom blossom = new Blossom(SIZE);
				for (GMaximumAdjacentPairs.Pair e : and) {
					if (valid(used, uf, inOr, e)) {
						int u = inOr[e.val1] ? uf.find(e.val1) : e.val1;
						int v = inOr[e.val2] ? uf.find(e.val2) : e.val2;
						blossom.addEdge(u, v);
					}
				}
				blossom.solve();
				Set<List<Integer>> matches = blossom.getMatches();
				for (GMaximumAdjacentPairs.Pair e : and) {
					if (valid(used, uf, inOr, e)) {
						int u = inOr[e.val1] ? uf.find(e.val1) : e.val1;
						int v = inOr[e.val2] ? uf.find(e.val2) : e.val2;
						List<Integer> match = Arrays.asList(Math.min(u, v), Math.max(u, v));
						if (matches.contains(match)) {
							matches.remove(match);
							e.both(vals, used);
							for (int me : new int[]{e.val1, e.val2}) {
								if (!inOr[me]) continue;
								int rep = uf.find(me);
								for (int j = 1; j < SIZE; j++) {
									if (uf.find(j) == rep) inOr[j] = false;
								}
								visit(me, orAdj, used, vals, null);
							}
						}
					}
				}
				for (int i = 1; i < SIZE; i++) {
					if (inOr[i]) {
						int rep = uf.find(i);
						for (int j = 1; j < SIZE; j++) {
							if (uf.find(j) == rep) inOr[j] = false;
						}
						visit(i, orAdj, used, vals, null);
					}
				}

			}
			int cur = 1;
			while (used[cur]) cur++;
			boolean first = true;
			for (int i = 0; i < n; i++) {
				if (vals[i] == 0) {
					vals[i] = cur;
					if (first) first = false;
					else {
						first = true;
						used[cur] = true;
						while (used[cur]) cur++;
					}
				}
				out.print(vals[i] + " ");
			}
			out.println();
		}

		private boolean valid(boolean[] used, UnionFind uf, boolean[] inOr, GMaximumAdjacentPairs.Pair e) {
			if (used[e.val1] || used[e.val2]) return false;
			int cant = 0;
			if (inOr[e.val1]) cant++;
			if (inOr[e.val2]) cant++;
			if (cant == 2 && uf.find(e.val1) == uf.find(e.val2)) return false;
			return true;
		}

		static void visit(int node, List<GMaximumAdjacentPairs.Pair>[] orAdj, boolean[] used, int[] vals, GMaximumAdjacentPairs.Pair ignoreEdge) {
			boolean[] vis = new boolean[orAdj.length];
			ArrayDeque<Integer> queue = new ArrayDeque<>();
			queue.add(node);
			vis[node] = true;
			while (!queue.isEmpty()) {
				int cur = queue.pollFirst();
				for (int i = 0; i < orAdj[cur].size(); i++) {
					GMaximumAdjacentPairs.Pair edge = orAdj[cur].get(i);
					if (edge == ignoreEdge) continue;
					int other = edge.other(cur);
					if (!edge.processed) {
						edge.choose(other, vals, used);
					}
					if (!vis[other]) {
						queue.add(other);
						vis[other] = true;
					}
				}
			}
		}

		static class Pair {
			int pos1;
			int pos2;
			int val1;
			int val2;
			boolean processed = false;

			public Pair(int pos1, int pos2, int val1, int val2) {
				this.pos1 = pos1;
				this.pos2 = pos2;
				this.val1 = val1;
				this.val2 = val2;
			}

			public int other(int me) {
				return val1 + val2 - me;
			}

			public void choose(int val, int[] vals, boolean[] used) {
				if (val1 == val) {
					vals[pos1] = val1;
					used[val1] = true;
				} else if (val2 == val) {
					vals[pos2] = val2;
					used[val2] = true;
				} else throw new RuntimeException();
				processed = true;
			}

			public void both(int[] vals, boolean[] used) {
				vals[pos1] = val1;
				used[val1] = true;
				vals[pos2] = val2;
				used[val2] = true;
			}

		}

	}

	static class MyScanner {
		private BufferedReader br;
		private StringTokenizer tokenizer;

		public MyScanner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public int[] nextIntArray(int n) {
			int[] ret = new int[n];
			for (int i = 0; i < n; i++) {
				ret[i] = nextInt();
			}
			return ret;
		}

	}

	static class Blossom {
		int n;
		int m;
		int[] mate;
		IntArray[] b;
		int[] p;
		int[] d;
		int[] bl;
		int[][] g;

		public Blossom(int n) {
			this.n = n;
			m = n + n / 2;
			mate = new int[n];
			Arrays.fill(mate, -1);
			b = new IntArray[m];
			for (int i = 0; i < m; i++) {
				b[i] = new IntArray();
			}
			p = new int[m];
			d = new int[m];
			bl = new int[m];
			g = new int[m][m];
			for (int i = 0; i < m; i++) {
				Arrays.fill(g[i], -1);
			}
		}

		public void addEdge(int u, int v) {
			g[u][v] = u;
			g[v][u] = v;
		}

		private void match(int u, int v) {
			g[u][v] = g[v][u] = -1;
			mate[u] = v;
			mate[v] = u;
		}

		private IntArray trace(int x) {
			IntArray vx = new IntArray();
			while (true) {
				while (bl[x] != x) x = bl[x];
				if (!vx.isEmpty() && vx.last() == x) break;
				vx.add(x);
				x = p[x];
			}
			return vx;
		}

		private void contract(int c, IntArray vx, IntArray vy) {
			b[c].clear();
			int r = vx.last();
			while (!vx.isEmpty() && !vy.isEmpty() && vx.last() == vy.last()) {
				r = vx.last();
				vx.removeLast();
				vy.removeLast();
			}
			b[c].add(r);
			for (int i = vx.size() - 1; i >= 0; i--) {
				b[c].add(vx.get(i));
			}
			for (int i = 0; i < vy.size(); i++) {
				b[c].add(vy.get(i));
			}
			for (int i = 0; i <= c; i++) {
				g[c][i] = g[i][c] = -1;
			}
			for (int i = 0; i < b[c].size(); i++) {
				int z = b[c].get(i);
				bl[z] = c;
				for (int j = 0; j < c; j++) {
					if (g[z][j] != -1) {
						g[c][j] = z;
						g[j][c] = g[j][z];
					}
				}
			}
		}

		private IntArray lift(int previous, IntArray vx) {
			IntArray A = new IntArray();
			while (vx.size() >= 1) {
				int z = vx.last();
				vx.removeLast();
				if (z < n) {
					A.add(z);
					continue;
				}
				int w = vx.isEmpty() ? previous : vx.last();
				int i = (A.size() % 2 == 0 ? b[z].indexOf(g[z][w]) : 0);
				int j = (A.size() % 2 == 1 ? b[z].indexOf(g[z][A.last()]) : 0);
				int k = b[z].size();
				int dif = (A.size() % 2 == 0 ? i % 2 == 1 : j % 2 == 0) ? 1 : k - 1;
				while (i != j) {
					vx.add(b[z].get(i));
					i = (i + dif) % k;
				}
				vx.add(b[z].get(i));
			}
			return A;
		}

		public int solve() {
			for (int ans = 0; ; ans++) {
				Arrays.fill(d, 0);
				ArrayDeque<Integer> Q = new ArrayDeque<>();
				for (int i = 0; i < m; i++) bl[i] = i;
				for (int i = 0; i < n; i++) {
					if (mate[i] == -1) {
						Q.addLast(i);
						p[i] = i;
						d[i] = 1;
					}
				}
				int c = n;
				boolean aug = false;
				while (!Q.isEmpty() && !aug) {
					int x = Q.removeFirst();
					if (bl[x] != x) continue;
					for (int y = 0; y < c; y++) {
						if (bl[y] == y && g[x][y] != -1) {
							if (d[y] == 0) {
								p[y] = x;
								d[y] = 2;
								p[mate[y]] = y;
								d[mate[y]] = 1;
								Q.addLast(mate[y]);
							} else if (d[y] == 1) {
								IntArray vx = trace(x);
								IntArray vy = trace(y);
								if (vx.last() == vy.last()) {
									contract(c, vx, vy);
									Q.addLast(c);
									p[c] = p[b[c].get(0)];
									d[c] = 1;
									c++;
								} else {
									aug = true;
									IntArray A = lift(y, vx);
									IntArray B = lift(x, vy);
									for (int i = B.size() - 1; i >= 0; i--) {
										A.add(B.get(i));
									}
									for (int i = 0; i < A.size(); i += 2) {
										match(A.get(i), A.get(i + 1));
										if (i + 2 < A.size()) addEdge(A.get(i + 1), A.get(i + 2));
									}
								}
								break;
							}
						}
					}
				}
				if (!aug) return ans;
			}
		}

		public Set<List<Integer>> getMatches() {
			Set<List<Integer>> ret = new HashSet<>();
			for (int i = 0; i < n; i++) {
				if (mate[i] != -1 && i < mate[i]) {
					ret.add(Arrays.asList(i, mate[i]));
				}
			}
			return ret;
		}

	}

	static class UnionFind {
		int[] rep;

		public UnionFind(int size) {
			rep = new int[size];
			for (int i = 0; i < size; i++) {
				rep[i] = i;
			}
		}

		public int find(int val) {
			if (rep[val] != val) {
				return rep[val] = find(rep[val]);
			}
			return val;
		}

		public boolean union(int a, int b) {
			int aRep = find(a);
			int bRep = find(b);
			if (aRep == bRep) return false;
			rep[aRep] = bRep;
			return true;
		}

	}

	static class IntArray {
		int[] arr;
		int size;

		public IntArray() {
			arr = new int[4];
		}

		public void add(int val) {
			if (size == arr.length) {
				arr = Arrays.copyOf(arr, 2 * arr.length);
			}
			arr[size++] = val;
		}

		public int get(int pos) {
			return arr[pos];
		}

		public int indexOf(int value) {
			for (int i = 0; i < size; i++) {
				if (arr[i] == value) return i;
			}
			return size;
		}

		public int last() {
			return arr[size - 1];
		}

		public void removeLast() {
			size--;
		}

		public void clear() {
			size = 0;
		}

		public int size() {
			return size;
		}

		public boolean isEmpty() {
			return size() == 0;
		}

		public int[] toArray() {
			return Arrays.copyOf(arr, size);
		}

		public String toString() {
			return "IntArray " + Arrays.toString(toArray());
		}

	}
}