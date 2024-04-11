import java.io.*;
import java.util.*;

public class D {

	static class HLD {
		final List<Integer>[] g;
		final int[] par;
		final int[] heavy;
		final int[] depth;
		final int[] pathPos;
		final int[] pathId;

		final int[] pathSize;
		final int[] pathRoot;

		public HLD(List<Integer>[] g) {
			this.g = g;
			int n = g.length;

			par = new int[n];
			heavy = new int[n];
			depth = new int[n];
			pathPos = new int[n];
			pathId = new int[n];
			pathRoot = new int[n];

			Arrays.fill(heavy, -1);
			par[0] = -1;
			depth[0] = 0;
			dfs(0);

			int pathCount = 0;

			for (int v = 0; v < n; v++) {
				if (par[v] == -1 || heavy[par[v]] != v) {
					pathCount++;
				}
			}

			pathSize = new int[pathCount];

			for (int v = 0, curPathId = 0; v < n; v++) {
				if (par[v] == -1 || heavy[par[v]] != v) {
					for (int u = v, pos = 0; u != -1; u = heavy[u], pos++) {
						pathRoot[u] = v;
						pathSize[curPathId]++;
						pathPos[u] = pos;
						pathId[u] = curPathId;
					}
					curPathId++;
				}
			}
		}

		private int dfs(int v) {
			int size = 1;
			int maxSubtree = 0;
			for (int u : g[v]) {
				if (u == par[v])
					continue;
				par[u] = v;
				depth[u] = depth[v] + 1;
				int subtree = dfs(u);
				if (maxSubtree < subtree) {
					maxSubtree = subtree;
					heavy[v] = u;
				}
				size += subtree;

			}
			return size;
		}

		/**
		 * @return list of triplets [pathId; pos1; pos2] in order corresponding
		 *         to path from v to u <br>
		 *         pos1 < pos2 = going down <br>
		 *         pos1 > pos2 = going up
		 */
		List<Integer> getPath(int v, int u) {
			List<Integer> head = new ArrayList<Integer>();
			List<Integer> tail = new ArrayList<Integer>();
			while (true) {
				int upV = pathRoot[v];
				int upU = pathRoot[u];
				if (upV == upU) {
					break;
				}
				if (depth[upV] > depth[upU]) {
					head.add(pathId[v]);
					head.add(pathPos[v]);
					head.add(0);
					v = par[upV];
				} else {
					tail.add(pathPos[u]);
					tail.add(0);
					tail.add(pathId[u]);
					u = par[upU];
				}
			}
			int pv = pathPos[v];
			int pu = pathPos[u];
			if (pv > pu) {
				head.add(pathId[v]);
				head.add(pv);
				head.add(pu);
			} else {
				tail.add(pu);
				tail.add(pv);
				tail.add(pathId[v]);
			}
			Collections.reverse(tail);
			head.addAll(tail);
			return head;
		}

		int getLCA(int v, int u) {

			int ret = v;

			while (true) {

				if (depth[v] < depth[ret]) {
					ret = v;
				}

				if (depth[u] < depth[ret]) {
					ret = u;
				}

				int upV = pathRoot[v];
				int upU = pathRoot[u];
				if (upV == upU) {
					break;
				}
				if (depth[upV] > depth[upU]) {
					v = par[upV];
				} else {
					u = par[upU];
				}
			}

			if (depth[v] < depth[ret]) {
				ret = v;
			}

			if (depth[u] < depth[ret]) {
				ret = u;
			}

			return ret;
		}

	}

	static class Query {
		int v, u, cost;

		public Query(int v, int u, int cost) {
			this.v = v;
			this.u = u;
			this.cost = cost;
		}
	}

	int[] next;
	int[] head;
	Query[] key;

	long[][] fenSumChild;
	long[][] fenValue;

	long[] dp;

	List<Integer>[] g;
	
	HLD hld;
	
	void add(long[] fen, int pos, long delta) {
		for (int i = pos; i < fen.length; i |= i + 1) {
			fen[i] += delta;
		}
	}
	
	long get(long[] fen, int from, int to) {
		return get(fen, to) - get(fen, from - 1);
	}
	
	long get(long[] fen, int pos) {
		long ret = 0;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
			ret += fen[i];
		}
		return ret;
	}

	void dfs(int v) {
		
		int path = hld.pathId[v];
		int pos = hld.pathPos[v];
		
		long sumChild = 0;
		for (int u : g[v]){
			dfs(u);
			sumChild += dp[u];
		}
		
		dp[v] = sumChild;
		add(fenSumChild[path], pos, sumChild);
		
		for (int e = head[v]; e >= 0; e = next[e]) {
			
			Query q = key[e];
			
			List<Integer> lst = hld.getPath(q.v, q.u);
			
			long sum = 0;
			for (int i = 0; i < lst.size(); i += 3) {
				int nowPath = lst.get(i);
				int nowPos1 = lst.get(i + 1);
				int nowPos2 = lst.get(i + 2);
				
				int pos1 = Math.min(nowPos1, nowPos2);
				int pos2 = Math.max(nowPos1, nowPos2);
				
				sum += get(fenSumChild[nowPath], pos1, pos2) - get(fenValue[nowPath], pos1, pos2);
			}
			
			dp[v] = Math.max(dp[v], sum + q.cost);
		}
		
		add(fenValue[path], pos, dp[v]);
	}

	void submit() {
		int n = nextInt();
		int q = nextInt();

		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 1; i < n; i++) {
			int par = nextInt() - 1;
			g[par].add(i);
		}

		hld = new HLD(g);

		head = new int[n];
		Arrays.fill(head, -1);
		next = new int[q];
		key = new Query[q];

		for (int i = 0; i < q; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			int cost = nextInt();

			int lca = hld.getLCA(v, u);
			
			key[i] = new Query(v, u, cost);
			next[i] = head[lca];
			head[lca] = i;
		}

		int pathCount = hld.pathSize.length;

		fenSumChild = new long[pathCount][];
		fenValue = new long[pathCount][];

		for (int i = 0; i < pathCount; i++) {
			fenSumChild[i] = new long[hld.pathSize[i]];
			fenValue[i] = new long[hld.pathSize[i]];
		}

		dp = new long[n];

		dfs(0);

		out.println(dp[0]);
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	D() throws IOException {
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
		new D();
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