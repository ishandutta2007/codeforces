import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class E {

	static class Edge implements Comparable<Edge> {
		int v, u, cost, id;

		public Edge(int v, int u, int cost, int id) {
			this.v = v;
			this.u = u;
			this.cost = cost;
			this.id = id;
		}

		@Override
		public int compareTo(Edge o) {
			return Integer.compare(cost, o.cost);
		}
	}

	interface Mergable<T, U, V> {
		T merge(T o, U extraInfo, V mergeWatcher);
	}

	static class DSU<T extends Mergable<T, U, V>, U, V> {
		private int[] p; // p[v] >= 0 is a parent of v
							// p[v] < 0 means v is a root with size of (-p[v])
		private T[] data;

		public DSU(int n, T[] initData) {
			p = new int[n];
			data = initData;
			Arrays.fill(p, -1);
		}

		int get(int v) {
			return p[v] < 0 ? v : (p[v] = get(p[v]));
		}

		boolean unite(int v, int u, U extraInfo, V mergeWatcher, boolean needMerging) {
			v = get(v);
			u = get(u);
			if (v == u) {
				return false;
			}
			if (p[v] > p[u]) {
				int tmp = v;
				v = u;
				u = tmp;
			}
			if (needMerging) {
				data[v] = data[v].merge(data[u], extraInfo, mergeWatcher);
			}
			p[v] += p[u];
			p[u] = v;
			return true;
		}

	}

	static class EdgePath implements Mergable<EdgePath, Edge, Object> {

		ArrayList<Integer> nodes = new ArrayList<>();
		ArrayList<Integer> costs = new ArrayList<>();

		public EdgePath(int node) {
			nodes.add(node);
		}

		@Override
		public EdgePath merge(EdgePath o, Edge edge, Object ignore) {
			if (nodes.size() > o.nodes.size()) {
				nodes.addAll(o.nodes);
				costs.add(edge.cost);
				costs.addAll(o.costs);
				return this;
			} else {
				o.nodes.addAll(nodes);
				o.costs.add(edge.cost);
				o.costs.addAll(costs);
				return o;
			}
		}
	}

	static class Dummy implements Mergable<Dummy, Object, Object> {
		@Override
		public Dummy merge(Dummy ignore1, Object ignore2, Object ignore3) {
			return null;
		}
	}

	static class MaxOnPathQueries implements Mergable<MaxOnPathQueries, Edge, Outputter> {

		ArrayList<Edge> paths;

		public MaxOnPathQueries() {
			paths = new ArrayList<>();
		}

		@Override
		public MaxOnPathQueries merge(MaxOnPathQueries o, Edge mergingEdge, Outputter outputter) {
			MaxOnPathQueries dst;
			ArrayList<Edge> src;
			if (paths.size() > o.paths.size()) {
				dst = this;
				src = o.paths;
			} else {
				dst = o;
				src = paths;
			}
			for (Edge query : src) {
				if (!outputter.tryAnswer(query, mergingEdge)) {
					dst.paths.add(query);
				}
			}
			return dst;
		}
	}

	static class Outputter {
		int[] ans;
		DSU dsu;

		public Outputter(int m, DSU dsu) {
			ans = new int[m];
			this.dsu = dsu;
		}

		boolean tryAnswer(Edge query, Edge mergingEdge) {
			int rv = dsu.get(query.v);
			int ru = dsu.get(query.u);

			if (ru != rv) {
				int mergeU = dsu.get(mergingEdge.u);
				int mergeV = dsu.get(mergingEdge.v);
				if ((rv == mergeV || rv == mergeU) && (ru == mergeV || ru == mergeU)) {
					ans[query.id] = mergingEdge.cost;
					return true;
				}
			}
			return false;
		}
	}

	int[] solve(int n, int m, Edge[] es) {
		Arrays.sort(es);
		EdgePath[] tmp = new EdgePath[n];
		for (int i = 0; i < n; i++) {
			tmp[i] = new EdgePath(i);
		}
		DSU<EdgePath, Edge, Object> mstDsu = new DSU<>(n, tmp);
		for (Edge e : es) {
			mstDsu.unite(e.v, e.u, e, null, true);
		}
		EdgePath path = mstDsu.data[mstDsu.get(0)];
		int[] edgeCosts = new int[n - 1];
		int[] nodes = new int[n];
		for (int i = 0; i < n - 1; i++) {
			edgeCosts[i] = path.costs.get(i);
		}
		for (int i = 0; i < n; i++) {
			nodes[i] = path.nodes.get(i);
		}
		
		int[] inv = new int[n];
		for (int i = 0; i < n; i++) {
			inv[nodes[i]] = i;
		}

		int[] deg = new int[n];

		for (Edge e : es) {
			e.v = inv[e.v];
			e.u = inv[e.u];
			deg[e.v]++;
			deg[e.u]++;
		}

		int[][] adj = new int[n][];
		for (int i = 0; i < n; i++) {
			adj[i] = new int[deg[i]];
		}
		for (Edge e : es) {
			adj[e.v][--deg[e.v]] = e.u;
			adj[e.u][--deg[e.u]] = e.v;
		}

		ArrayList<Integer>[] comps = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			comps[i] = new ArrayList<>();
			comps[i].add(i);
		}

		DSU<Dummy, Object, Object> bka = new DSU<>(n, new Dummy[n]);

		Edge[] outpEs = new Edge[n - 1];
		int ptr = 0;

		Jumper jumper = new Jumper(edgeCosts);
		
//		System.err.println(Arrays.deepToString(adj));

		do {
//			System.err.println(Arrays.toString(comps));
			ArrayList<Edge> adds = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				if (bka.get(i) != i) {
					continue;
				}
				ArrayList<Integer> what = comps[i];
				for (int v : what) {
					jumper.permaMark(v);
				}
				Edge best = new Edge(-1, -1, Integer.MAX_VALUE, -1);
				for (int v : what) {
					for (int u : adj[v]) {
						jumper.tempMark(u);
					}
					Edge fromV = jumper.findBestEdge(v);
					if (fromV.cost < best.cost) {
						best = fromV;
					}
					for (int u : adj[v]) {
						jumper.tempUnmark(u);
					}
				}
				adds.add(best);
				for (int v : what) {
					jumper.permaUnmark(v);
				}
			}

			for (Edge e : adds) {
				int rv = bka.get(e.v);
				int ru = bka.get(e.u);
				if (rv == ru) {
					continue;
				}
				ArrayList<Integer> newComp;
				if (comps[rv].size() > comps[ru].size()) {
					(newComp = comps[rv]).addAll(comps[ru]);
				} else {
					(newComp = comps[ru]).addAll(comps[rv]);
				}
				bka.unite(e.v, e.u, null, null, false);
				comps[bka.get(rv)] = newComp;
				outpEs[ptr++] = e;

			}

		} while (ptr < n - 1);

		MaxOnPathQueries[] qryArr = new MaxOnPathQueries[n];
		for (int i = 0; i < n; i++) {
			qryArr[i] = new MaxOnPathQueries();
		}
		for (Edge e : es) {
			qryArr[e.v].paths.add(e);
			qryArr[e.u].paths.add(e);
		}
		DSU<MaxOnPathQueries, Edge, Outputter> outpDSU = new DSU<>(n, qryArr);
		Outputter outputter = new Outputter(m, outpDSU);

		Arrays.sort(outpEs);
		for (Edge e : outpEs) {
			outpDSU.unite(e.v, e.u, e, outputter, true);
		}

		return outputter.ans;
	}

	static class Jumper {
		int[] nxt, nxtPath, nxtCost, nxtPathMax;
		int[] prv, prvPath, prvCost, prvPathMax;

		int n;

		int[] status;

		public Jumper(int[] edgeCosts) {
			n = edgeCosts.length + 1;
			status = new int[n];
			nxt = new int[n];
			nxtPath = new int[n];
			nxtCost = new int[n];
			nxtPathMax = new int[n];
			prv = new int[n];
			prvPath = new int[n];
			prvCost = new int[n];
			prvPathMax = new int[n];
			for (int i = 0; i < n; i++) {
				prv[i] = prvPath[i] = i - 1;
				prvCost[i] = prvPathMax[i] = i == 0 ? Integer.MAX_VALUE : edgeCosts[i - 1];
				nxt[i] = nxtPath[i] = i + 1;
				nxtCost[i] = nxtPathMax[i] = i == n - 1 ? Integer.MAX_VALUE : edgeCosts[i];
			}
		}

		void permaMark(int v) {
			status[v] = 2;
		}

		void tempMark(int v) {
			status[v] = Math.max(status[v], 1);
		}

		void tempUnmark(int v) {
			if (status[v] == 1) {
				status[v] = 0;
			}
		}

		void permaUnmark(int v) {
			status[v] = 0;
		}

		void dfsPerma(int v, int[] jmp, int[] costPath) {
			int u = jmp[v];
			if (u < 0 || u >= n) {
				costPath[v] = Integer.MAX_VALUE;
				return;
			}
			if (status[u] != 2) {
				return;
			}
			dfsPerma(u, jmp, costPath);
			jmp[v] = jmp[u];
			costPath[v] = Math.max(costPath[v], costPath[u]);
		}

		Edge findBestEdge(int v, int[] jmp, int[] next, int[] cost, int[] costPath) {
			int u = v;
			int ret = 0;
			while (status[u] == 2) {
				dfsPerma(u, jmp, costPath);
				if (jmp[u] < 0 || jmp[u] >= n) {
					return new Edge(-1, -1, Integer.MAX_VALUE, -1);
				}
				ret = Math.max(ret, costPath[u]);
				u = jmp[u];
				// status[to] can't be 2!
				while (u >= 0 && u < n && status[u] == 1) {
					ret = Math.max(ret, cost[u]);
					u = next[u];
				}
				if (u < 0 || u >= n) {
					return new Edge(-1, -1, Integer.MAX_VALUE, -1);
				}
			}
			return new Edge(v, u, ret, -1);
		}

		Edge findBestEdge(int v) {
			Edge forw = findBestEdge(v, nxtPath, nxt, nxtCost, nxtPathMax);
			Edge back = findBestEdge(v, prvPath, prv, prvCost, prvPathMax);
			return forw.cost < back.cost ? forw : back;
		}

	}

	int[] getNodes(Edge[] es) {
		int n = es.length + 1;
		int[] ret = new int[n];
		if (n == 2) {
			ret[0] = es[0].v;
			ret[1] = es[0].u;
			return ret;
		}

		int last = (es[0].v == es[1].v || es[0].v == es[1].u) ? es[0].u : es[0].v;
		ret[0] = last;
		for (int i = 0; i < n - 1; i++) {
			last ^= es[i].v ^ es[i].u;
			ret[i + 1] = last;
		}
		return ret;
	}

	void submit() {
		int t = nextInt();
		while (t-- > 0) {
			int n = nextInt();
			int m = nextInt();
			Edge[] es = new Edge[m];
			for (int i = 0; i < m; i++) {
				int v = nextInt() - 1;
				int u = nextInt() - 1;
				int cost = nextInt();
				es[i] = new Edge(v, u, cost, i);
			}
			int[] ans = solve(n, m, es);
			for (int x : ans) {
				out.print(x + " ");
			}
			out.println();
		}
	}

	void test() {

	}

	void stress() {
		for (int tst = 0;; tst++) {
			if (false) {
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	E() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 5;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new E();
	}

	private InputStream is;
	PrintWriter out;

	private byte[] buf = new byte[1 << 14];
	private int bufSz = 0, bufPtr = 0;

	private int readByte() {
		if (bufSz == -1)
			throw new RuntimeException("Reading past EOF");
		if (bufPtr >= bufSz) {
			bufPtr = 0;
			try {
				bufSz = is.read(buf);
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			if (bufSz <= 0)
				return -1;
		}
		return buf[bufPtr++];
	}

	private boolean isTrash(int c) {
		return c < 33 || c > 126;
	}

	private int skip() {
		int b;
		while ((b = readByte()) != -1 && isTrash(b))
			;
		return b;
	}

	String nextToken() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	String nextString() {
		int b = readByte();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b) || b == ' ') {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	char nextChar() {
		return (char) skip();
	}

	int nextInt() {
		int ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}

	long nextLong() {
		long ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}
}