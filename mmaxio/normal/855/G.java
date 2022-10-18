import java.io.*;
import java.util.*;

public class G_fast {

	static class TreeEdge {
		int from, to;
		int sz;

		public TreeEdge(int from, int to, int sz) {
			this.from = from;
			this.to = to;
			this.sz = sz;
		}
	}

	int[] next;
	int[] head;
	int[] to;

	int ptr = 0;

	void addEdge(int v, int u) {
		next[ptr] = head[v];
		head[v] = ptr;
		to[ptr] = u;
		ptr++;
	}

	int[] par;
	int[] repr;
	int[] sz;

	int[] szTree;
	
	long[] sum2;

	int get(int v) {
		return repr[v] == v ? v : (repr[v] = get(repr[v]));
	}

	ArrayList<TreeEdge>[] adj;

	void dfs(int v, int parent) {
		szTree[v] = 1;
		par[v] = parent;

		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			if (u != parent) {
				dfs(u, v);
				szTree[v] += szTree[u];

				adj[v].add(new TreeEdge(v, u, szTree[u]));
				adj[u].add(new TreeEdge(u, v, n - szTree[u]));
			}
		}
	}

	long[] value;

	int n;

	void submit() {
		n = nextInt();

		next = new int[2 * n - 2];
		head = new int[n];
		to = new int[2 * n - 2];
		Arrays.fill(head, -1);

		adj = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			adj[i] = new ArrayList<>();
		}

		for (int i = 0; i < n - 1; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			addEdge(v, u);
			addEdge(u, v);
		}

		par = new int[n];
		repr = new int[n];
		sz = new int[n];

		value = new long[n];

		for (int i = 0; i < n; i++) {
			repr[i] = i;
			sz[i] = 1;
		}

		// tIn = new int[n];
		// tOut = new int[n];
		szTree = new int[n];

		dfs(0, 0);

		sum2 = new long[n];
		for (int i = 0; i < n; i++) {
			for (TreeEdge te : adj[i]) {
				sum2[i] += (long)te.sz * (te.sz - 1);
			}
		}
		
		long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += getValue(i);
		}

		out.println(ans);

		int[] mark = new int[n];
		int markVer = 0;

		int q = nextInt();

		int[] cycle = new int[n];
		int cycleSz = 0;

		while (q-- > 0) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;

			v = get(v);
			u = get(u);

			if (v == u) {
				out.println(ans);
				continue;
			}

			markVer++;

			int lca = -1;
			int vv = v;
			int uu = u;
			
			boolean atRootV = false;
			boolean atRootU = false;

			while (true) {
				if (!atRootV) {
					if (mark[vv] == markVer) {
						lca = vv;
						break;
					}
					mark[vv] = markVer;
					atRootV |= vv == 0;
					vv = get(par[vv]);
				}

				if (!atRootU) {
					if (mark[uu] == markVer) {
						lca = uu;
						break;
					}
					atRootU |= uu == 0;
					mark[uu] = markVer;
					uu = get(par[uu]);
				}
			}

			cycleSz = 0;
			vv = v;

			while (vv != lca) {
				cycle[cycleSz++] = vv;
				vv = get(par[vv]);
			}

			uu = u;
			while (uu != lca) {
				cycle[cycleSz++] = uu;
				uu = get(par[uu]);
			}

			int bigSz = adj[lca].size();
			int bigNode = lca;
			int totalSz = bigSz;
			
			ans -= value[lca];
			
			markVer++;
			
			mark[lca] = markVer;
			
			for (int i = 0; i < cycleSz; i++) {
				int now = cycle[i];
				mark[now] = markVer;
				if (adj[now].size() > bigSz) {
					bigSz = adj[now].size();
					bigNode = now;
				}
				totalSz += adj[now].size();
				
				ans -= value[now];
			}
			
			ArrayList<TreeEdge> tmp = adj[lca];
			adj[lca] = adj[bigNode];
			adj[bigNode] = tmp;
			
			adj[lca].ensureCapacity(totalSz);

			
			// now we visit all except bigNode
			for (int i = 0; i < cycleSz; i++) {
				int now = cycle[i];
				
				for (TreeEdge te : adj[now]) {
					te.from = get(te.from);
					te.to = get(te.to);
					
					if (te.from == te.to) {
						continue;
					}
					
					adj[lca].add(te);
					
					if (mark[te.from] == markVer && mark[te.to] == markVer) {
						
						sum2[lca] -= (long)te.sz * (te.sz - 1);
						
						if (te.from == bigNode || te.to == bigNode) {
							sum2[lca] -= (long)(n - te.sz) * (n - te.sz - 1);
						}
					}
				}
			}
			
			for (int i = 0; i < cycleSz; i++) {
				int now = cycle[i];
				sz[lca] += sz[now];
				repr[now] = lca;

				sum2[lca] += sum2[now];
				
				adj[now] = null;
			}

			ans += getValue(lca);
			out.println(ans);
		}
	}

	long getValue(int v) {

		v = get(v);

		long ret = (long) sz[v] * (n - 1) * (n - 2);
		
		ret -= sz[v] * sum2[v];
		
		return value[v] = ret;
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	G_fast() throws IOException {
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
		new G_fast();
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