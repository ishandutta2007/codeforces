import java.io.*;
import java.util.*;

public class E {

	static final boolean USE_FILES = false;

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[][] g;

	boolean[] dead;
	int[] sz;

	int m;

	void submit() throws IOException {
		int n = nextInt();
		m = nextInt();
		int q = nextInt();
		g = new int[n][];
		int[] a = new int[3 * n - 3];
		int[] deg = new int[n];
		for (int i = 0; i < n - 1; i++) {
			a[3 * i] = nextInt() - 1;
			a[3 * i + 1] = nextInt() - 1;
			a[3 * i + 2] = nextToken().charAt(0) - 'a';
			deg[a[3 * i]]++;
			deg[a[3 * i + 1]]++;
		}

		for (int i = 0; i < n; i++) {
			g[i] = new int[2 * deg[i]];
		}

		for (int i = 0; i < 3 * n - 3; i += 3) {
			int v = a[i];
			int u = a[i + 1];
			int symb = a[i + 2];
			--deg[v];
			g[v][2 * deg[v]] = u;
			g[v][2 * deg[v] + 1] = symb;
			--deg[u];
			g[u][2 * deg[u]] = v;
			g[u][2 * deg[u] + 1] = symb;
		}

		sz = new int[n];
		dead = new boolean[n];

		int[][] dict = new int[m][];
		int[][] rDict = new int[m][];

		for (int i = 0; i < m; i++) {
			String s = nextToken();
			dict[i] = new int[s.length()];
			rDict[i] = new int[s.length()];
			for (int j = 0; j < s.length(); j++) {
				dict[i][j] = rDict[i][s.length() - 1 - j] = s.charAt(j) - 'a';
			}
		}

		ahoDict = new AhoCorasick(dict);
		ahoRev = new AhoCorasick(rDict);

		allQs = new Query[q];
		int[] degQ = new int[n];

		for (int i = 0; i < q; i++) {
			int from = nextInt() - 1;
			int to = nextInt() - 1;
			int str = nextInt() - 1;
			allQs[i] = new Query(from, to, str, i);
			degQ[from]++;
			degQ[to]++;
		}

		gq = new Query[n][];
		for (int i = 0; i < n; i++) {
			gq[i] = new Query[degQ[i]];
		}

		for (Query qNow : allQs) {
			int from = qNow.from;
			int to = qNow.to;
			gq[from][--degQ[from]] = qNow;
			gq[to][--degQ[to]] = qNow;
		}

		ans = new int[q];
		subTree = new int[n];

		int bigLen = 0;
		for (int[] word : dict) {
			bigLen += word.length;
		}

		int[] bigDict = new int[bigLen];
		int[] bigRev = new int[bigLen];

		strId = new int[bigLen];
		compPos = new int[bigLen];
		addFrom = new int[bigLen];
		addTo = new int[bigLen];

		int ptr = 0;
		for (int j = 0; j < m; j++) {
			int sum = (ptr + 1) + (ptr + dict[j].length - 1);
			int oldPtr = ptr;
			for (int i = 0; i < dict[j].length; i++) {
				bigDict[ptr] = dict[j][i];
				bigRev[ptr] = rDict[j][i];
				strId[ptr] = j;
				compPos[ptr] = sum - ptr;
				ptr++;
			}
			strId[oldPtr] = -1;
		}

		stDict = new STree(bigDict);
		stRev = new STree(bigRev);

		markSuffixes(dict, stDict);
		markSuffixes(rDict, stRev);

		// IMPORTANT CHANGES
		// because Dumb needs actual lengths
		// actually only len[0] = 0 is needed
		for (STree t : new STree[] { stDict, stRev }) {
			t.len[0] = 0;
			for (int i = 1; i < t.sz; i++) {
				if (t.len[i] == STree.INF) {
					t.len[i] = t.s.length - t.from[i];
				}
			}
//			System.err.println(Arrays.toString(Arrays.copyOf(t.len, t.sz)));
		}

		go(0);

		askIdx = new int[q];
		Arrays.fill(askIdx, -1);
		traverseRevTree();

		fens = new int[m][];
		for (int i = 0; i < m; i++) {
			fens[i] = new int[time[i] + 1];
		}
		traverseTree();

		for (int x : ans) {
			out.println(x);
		}
	}

	int[] strId;
	int[] compPos;
	int[] addFrom;
	int[] addTo;
	int[] askIdx;

	int[][] fens;

	Query[] allQs;

	void traverseTree() {
		for (int i = 1; i < stDict.sz; i++) {
			Collections.sort(stDict.ins[i]);
		}

		dfsTree(0);
	}

	void addFen(int[] fen, int pos, int delta) {
		for (int i = pos; i < fen.length; i |= i + 1) {
			fen[i] += delta;
		}
	}

	int getFen(int[] fen, int pos) {
		int ret = 0;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
			ret += fen[i];
		}
		return ret;
	}

	void dfsTree(int v) {
		for (int u : stDict.to[v]) {
			if (u == 0) {
				continue;
			}

			for (EdgePosition ep : stDict.ins[u]) {
				if (ep.tag >= 0) {
					int str = strId[ep.tag];
					if (str == -1) {
						continue;
					}

					addFen(fens[str], addFrom[ep.tag], 1);
					addFen(fens[str], addTo[ep.tag], -1);
				} else {
					int qry = ~ep.tag;
					int str = allQs[qry].str;
					if (askIdx[qry] != -1) {
						ans[qry] += getFen(fens[str], askIdx[qry]);
					}
				}
			}

			dfsTree(u);

			Collections.reverse(stDict.ins[u]);
			for (EdgePosition ep : stDict.ins[u]) {
				if (ep.tag >= 0) {
					int str = strId[ep.tag];
					if (str == -1) {
						continue;
					}

					addFen(fens[str], addFrom[ep.tag], -1);
					addFen(fens[str], addTo[ep.tag], 1);
				}
			}
		}
	}

	void traverseRevTree() {
		time = new int[m];
		// things in root are useless!
		// but of course we still need to not get an exception while handling
		// them...
		for (int i = 1; i < stRev.sz; i++) {
			Collections.sort(stRev.ins[i]);
		}

		dfsRevTree(0);
	}

	void dfsRevTree(int v) {
		for (int u : stRev.to[v]) {
			if (u == 0) {
				continue;
			}

			for (EdgePosition ep : stRev.ins[u]) {

				if (ep.tag >= 0) {
					int str = strId[ep.tag];
					if (str == -1) {
						continue;
					}

					int i = compPos[ep.tag];
					addFrom[i] = time[str];
				} else {
					int qry = ~ep.tag;
					int str = allQs[qry].str;
					askIdx[qry] = time[str];
					time[str]++;
				}
			}

			dfsRevTree(u);

			Collections.reverse(stRev.ins[u]);
			for (EdgePosition ep : stRev.ins[u]) {
				if (ep.tag >= 0) {
					int str = strId[ep.tag];
					if (str == -1) {
						continue;
					}

					int i = compPos[ep.tag];
					addTo[i] = time[str];
				}
			}
		}
	}

	int[] time;

	void markSuffixes(int[][] dict, STree t) {
		int offset = 0;
		Seeker s = new Seeker();
		for (int[] word : dict) {
			s.node = 0;
			s.down = word.length;

			for (int i = 0; i < word.length; i++) {

				t.skipCount(s, word);

				int actualNode = t.to[s.node][word[word.length - s.down]];
				t.ins[actualNode].add(new EdgePosition(s.down, offset + i));

				if (s.node == 0) {
					s.down--;
				} else {
					s.node = t.suf[s.node];
				}
			}

			offset += word.length;
		}
	}

	static class Seeker {
		int node, down;
	}

	static class Dumb {
		int node, went;
		boolean dead;
	}

	AhoCorasick ahoDict, ahoRev;
	Query[][] gq;

	STree stDict, stRev;

	int[] ans;

	static final int ALPH = 26;

	static class Query {
		int from, to;
		int str;

		int id;

		int dead = 0;

		public Query(int from, int to, int str, int id) {
			this.from = from;
			this.to = to;
			this.str = str;
			this.id = id;
		}
	}

	static class AhoCorasick {
		int[][] go;
		int[] link;

		int[] endNode;

		int size;

		private int[] head;
		private int[] next;

		// to is just idx + 1

		public AhoCorasick(int[][] dict) {
			int maxSize = 1;
			for (int[] word : dict) {
				maxSize += word.length;
			}

			go = new int[maxSize][];
			link = new int[maxSize];
			endNode = new int[dict.length];

			int root = newNode();
			for (int i = 0; i < dict.length; i++) {
				int v = root;
				for (int symb : dict[i]) {
					int u = go[v][symb];
					if (u == -1) {
						u = go[v][symb] = newNode();
					}
					v = u;
				}
				endNode[i] = v;
			}

			int[] que = new int[size];
			int qh = 0, qt = 0;

			for (int symb = 0; symb < ALPH; symb++) {
				int u = go[root][symb];
				if (u != -1) {
					que[qt++] = u;
					link[u] = root;
				} else {
					go[root][symb] = root;
				}
			}

			while (qh < qt) {
				int v = que[qh++];
				for (int symb = 0; symb < ALPH; symb++) {
					int u = go[v][symb];
					if (u != -1) {
						que[qt++] = u;
						link[u] = go[link[v]][symb];
					} else {
						go[v][symb] = go[link[v]][symb];
					}
				}
			}

			head = new int[size];
			Arrays.fill(head, -1);
			next = new int[size - 1];

			for (int u = 1; u < size; u++) {
				int v = link[u];
				next[u - 1] = head[v];
				head[v] = u - 1;
			}

			tIn = new int[size];
			tOut = new int[size];
			dfs(root);

			fen = new int[size];
		}

		private int time;
		private int[] tIn;
		private int[] tOut;

		int[] fen;

		private void dfs(int v) {
			tIn[v] = time++;
			for (int e = head[v]; e >= 0; e = next[e]) {
				int u = e + 1; // yep
				dfs(u);
			}
			tOut[v] = time;
		}

		private int newNode() {
			go[size] = new int[ALPH];
			Arrays.fill(go[size], -1);
			return size++;
		}

		void editFen(int node, int delta) {
			int pos = tIn[node];
			for (int i = pos; i < size; i |= i + 1) {
				fen[i] += delta;
			}
		}

		int getFen(int wordIdx) {
			return internalGet(tOut[endNode[wordIdx]] - 1)
					- internalGet(tIn[endNode[wordIdx]] - 1);
		}

		private int internalGet(int pos) {
			int ret = 0;
			for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
				ret += fen[i];
			}
			return ret;
		}
	}

	int[] subTree;

	void goCentre(int v) {
		fillSubTree(v, v, v);
		Dumb sDict = new Dumb();
		Dumb sRev = new Dumb();
		sDict.node = 0;
		sDict.went = 0;
		sRev.node = 0;
		sRev.went = 0;
		dfsWork(v, v, 0, 0, sDict, sRev);
	}

	void dfsWork(int v, int p, int nodeDict, int nodeRev, Dumb dDict, Dumb dRev) {
		ahoDict.editFen(nodeDict, 1);
		ahoRev.editFen(nodeRev, 1);
		for (Query q : gq[v]) {
			if (q.dead == 2 || subTree[q.from] == subTree[q.to]) {
				continue;
			}

			if (v == q.from) {
				stRev.ins[dRev.node].add(new EdgePosition(dRev.went, ~q.id));
				ans[q.id] += ahoRev.getFen(q.str);
			} else if (v == q.to) {
				stDict.ins[dDict.node].add(new EdgePosition(dDict.went, ~q.id));
				ans[q.id] += ahoDict.getFen(q.str);
			}
			q.dead++;
		}

		for (int i = 0; i < g[v].length; i += 2) {
			int u = g[v][i];
			int symb = g[v][i + 1];
			if (dead[u] || u == p) {
				continue;
			}
			Dumb newDDict = stDict.moveDumb(dDict, symb);
			Dumb newDRev = stRev.moveDumb(dRev, symb);
			dfsWork(u, v, ahoDict.go[nodeDict][symb], ahoRev.go[nodeRev][symb],
					newDDict, newDRev);
		}

		ahoDict.editFen(nodeDict, -1);
		ahoRev.editFen(nodeRev, -1);
	}

	void fillSubTree(int v, int p, int mark) {
		subTree[v] = mark;
		for (int i = 0; i < g[v].length; i += 2) {
			int u = g[v][i];
			if (!dead[u] && u != p) {
				fillSubTree(u, v, v == p ? u : mark);
			}
		}
	}

	void go(int v) {
		dfsSz(v, -1);
		int root = v;
		outer: while (true) {
			for (int i = 0; i < g[root].length; i += 2) {
				int u = g[root][i];
				if (!dead[u] && sz[u] < sz[root] && 2 * sz[u] > sz[v]) {
					root = u;
					continue outer;
				}
			}
			break;
		}

		goCentre(root);
		dead[root] = true;
		for (int i = 0; i < g[root].length; i += 2) {
			int u = g[root][i];
			if (!dead[u]) {
				go(u);
			}
		}
	}

	void dfsSz(int v, int p) {
		sz[v] = 1;
		for (int i = 0; i < g[v].length; i += 2) {
			int u = g[v][i];
			if (u != p && !dead[u]) {
				dfsSz(u, v);
				sz[v] += sz[u];
			}
		}
	}

	static class EdgePosition implements Comparable<EdgePosition> {
		int lenDown;
		int tag; // >= 0 -> position of suffix start

		// < 0 -> query id, look it up in allQs

		@Override
		public int compareTo(EdgePosition o) {
			if (lenDown != o.lenDown) {
				return lenDown < o.lenDown ? -1 : 1;
			}
			return -Integer.compare(tag, o.tag);
		}

		public EdgePosition(int lenDown, int tag) {
			this.lenDown = lenDown;
			this.tag = tag;
		}
	}

	static class STree {
		static final int ALPH = 26;
		static final int INF = Integer.MAX_VALUE / 3;

		int[] s;
		/**
		 * to[v][c] = 0 means there is no edge; it helps since len[0] is INF so
		 * we never go down by such edges in goEdge()
		 */
		int[][] to;
		int[] len, from;
		/**
		 * suf[0] is some shit since we use "suf[last] = node" often in
		 * addLetter() and last is 0 when we don't need to make a new suffix
		 * link
		 */
		int[] suf;

		int node;
		int down;

		int sz;
		int idx;

		ArrayList<EdgePosition> ins[];

		int newNode(int from, int len) {
			this.from[sz] = from;
			this.len[sz] = len;
			to[sz] = new int[ALPH];
			return sz++;
		}

		public STree(int[] s) {
			int n = s.length;
			int maxSize = 2 * n + 1;
			this.s = s;
			to = new int[maxSize][];
			len = new int[maxSize];
			from = new int[maxSize];
			suf = new int[maxSize];
			newNode(0, INF);

			for (int i = 0; i < n; i++) {
				addLetter();
			}

			ins = new ArrayList[sz];
			for (int i = 0; i < sz; i++) {
				ins[i] = new ArrayList<>();
			}

		}

		void addLetter() {
			int c = s[idx++];
			down++;
			int last = 0;
			while (down > 0) {
				skipCount();
				int letEdge = s[idx - down];
				int v = to[node][letEdge];
				int nxtLet = s[from[v] + down - 1];
				if (v == 0) {
					// we are staying at inner node with no appropriate
					// edge going down; down == 1
					to[node][letEdge] = newNode(idx - 1, INF);
					suf[last] = node;
					last = 0;
				} else if (nxtLet == c) {
					suf[last] = node;
					return;
				} else {
					int u = newNode(from[v], down - 1);
					to[u][c] = newNode(idx - 1, INF);
					to[u][nxtLet] = v;
					from[v] += down - 1;
					if (len[v] != INF) {
						len[v] -= down - 1;
					}
					to[node][letEdge] = u;
					suf[last] = u;
					last = u;
				}
				if (node == 0) {
					down--;
				} else {
					node = suf[node];
				}
			}
		}

		void skipCount() {
			while (down > len[to[node][s[idx - down]]]) {
				node = to[node][s[idx - down]];
				down -= len[node];
			}
		}

		void skipCount(Seeker s, int[] word) {
			while (s.down > len[to[s.node][word[word.length - s.down]]]) {
				s.node = to[s.node][word[word.length - s.down]];
				s.down -= len[s.node];
			}
		}

		Dumb moveDumb(Dumb was, int symb) {
			if (was.dead) {
				return was;
			}
			int node = was.node;
			int went = was.went;
			Dumb ret = new Dumb();
			if (went < len[node]) {
//				System.err.println(from[node]);
//				System.err.println(from[node] + went);
//				System.err.println(s.length);
//				System.err.println(from[node] + len[node]);
//				System.err.println(len[node] == INF);
				int expect = s[from[node] + went];
				if (expect == symb) {
					ret.node = node;
					ret.went = went + 1;
				} else {
					ret.node = node;
					ret.went = went;
					ret.dead = true;
				}
			} else if (to[node][symb] == 0) {
				ret.node = node;
				ret.went = went;
				ret.dead = true;
			} else {
				ret.node = to[node][symb];
				ret.went = 1;
			}
			return ret;
		}

	}

	E() throws IOException {
		if (!USE_FILES) {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		} else {
			br = new BufferedReader(new FileReader("in.txt"));
			out = new PrintWriter("out.txt");
		}
		submit();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E();
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