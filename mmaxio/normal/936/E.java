import java.io.*;
import java.math.*;
import java.util.*;

public class E_fenwick {

//	static final int INF = BigInteger.TEN.pow(7).intValueExact();
	static final int INF = 10_000_000;

	static final int N_LOG_N = 10_400_000;

	int[] infoKey = new int[N_LOG_N];
	int[] infoNext = new int[N_LOG_N / 2];
	int infoPtr;

	int get(int[] fen, int pos) {
		int ret = INF;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
			ret = Math.min(ret, fen[i]);
		}
		return ret;
	}

	void set(int[] fen, int pos, int val) {
		for (int i = pos; i < fen.length; i |= i + 1) {
			fen[i] = Math.min(fen[i], val);
		}
	}

	static class Cell implements Comparable<Cell> {
		int x, y;

		public Cell(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Cell o) {
			if (x != o.x) {
				return Integer.compare(x, o.x);
			}
			return Integer.compare(y, o.y);
		}
		
		int infoHead = -1;

		Node node;

	}

	static class Node {
		int x, y1, y2, id;

		public Node(int x, int y1, int y2, int id) {
			this.x = x;
			this.y1 = y1;
			this.y2 = y2;
			this.id = id;
		}

		int len() {
			return y2 - y1 + 1;
		}

		// ArrayList<int[]> info = new ArrayList<>(0);
		Cell[] cells;
		int[] fenPos;
		int[] fenNeg;
	}

	Node[] b;

	void submit() {
		int s = nextInt();
		Cell[] a = new Cell[s];
		for (int i = 0; i < s; i++) {
			a[i] = new Cell(nextInt(), nextInt());
		}

		Arrays.sort(a);

		b = new Node[s];
		int n = 0;

		for (int i = 0; i < s;) {
			int j = i;
			while (j < s && a[j].x == a[i].x && a[j].y - a[i].y == j - i) {
				j++;
			}
			Node tmp = new Node(a[i].x, a[i].y, a[j - 1].y, n);
			tmp.cells = new Cell[j - i];
			b[n++] = tmp;
			for (int k = i; k < j; k++) {
				a[k].node = b[n - 1];
				tmp.cells[k - i] = a[k];
			}
			i = j;
		}

		b = Arrays.copyOf(b, n);
		Cell[] tmpA = a.clone();
		Arrays.sort(tmpA, (Cell p, Cell q) -> {
			if (p.y != q.y) {
				return p.y < q.y ? -1 : 1;
			}
			return Integer.compare(p.x, q.x);
		});

		next = new int[2 * n - 2];
		head = new int[n];
		Arrays.fill(head, -1);
		to = new int[2 * n - 2];

		for (int i = 0; i < s - 1; i++) {
			if (tmpA[i].y == tmpA[i + 1].y && tmpA[i + 1].x - tmpA[i].x == 1) {
				if (tmpA[i].y == tmpA[i].node.y1
						|| tmpA[i + 1].y == tmpA[i + 1].node.y1) {
					addEdge(tmpA[i].node.id, tmpA[i + 1].node.id);
				}
			}
		}
		sz = new int[n];
		dead = new boolean[n];
		par = new int[n];
		go(0, -1);
		
		for (Node v : b) {
			v.cells = null;
		}
		tmpA = null;
		sz = null;
		dead = null;
		
//		System.gc();

		for (Node v : b) {
			// v.root = new MinNode(0, v.y2 - v.y1 + 1);
			v.fenNeg = new int[v.len()];
			Arrays.fill(v.fenNeg, INF);
			v.fenPos = v.fenNeg.clone();
		}

		int q = nextInt();
		while (q-- > 0) {
			int t = nextInt();
			Cell qc = new Cell(nextInt(), nextInt());
			int idx = Arrays.binarySearch(a, qc);

			qc = a[idx];

			Node v = qc.node;

			if (t == 2) {
				int ans = INF;
				int centre = v.id;
				// for (int i = v.info.size() - 2; i >= 0; i -= 2) {
				// int dist = v.info.get(i)[place];
				// int last = v.info.get(i + 1)[place];

				for (int i = qc.infoHead; i >= 0; i = infoNext[i]) {

					int dist = infoKey[2 * i];
					int last = infoKey[2 * i + 1];

					int kek = b[centre].len();

					ans = Math.min(ans,
							dist + last + get(b[centre].fenNeg, last));
					ans = Math
							.min(ans,
									dist
											- last
											+ get(b[centre].fenPos, kek - 1
													- last));

					centre = par[centre];
				}

				out.println(ans > INF / 2 ? -1 : ans);
			} else {
				int centre = v.id;
				for (int i = qc.infoHead; i >= 0; i = infoNext[i]) {

					int dist = infoKey[2 * i];
					int last = infoKey[2 * i + 1];
					int kek = b[centre].len();

					set(b[centre].fenNeg, last, dist - last);
					set(b[centre].fenPos, kek - 1 - last, dist + last);
					centre = par[centre];
				}
			}
		}
	}

	int[] sz;
	boolean[] dead;
	int[] par;

	void dfs2(int v, int p, int root, int[]arr) {//, int[] dist, int[] last) {
		// b[v].info.add(new int[][]{dist, last});
		// b[v].info.add(dist);
		// b[v].info.add(last);

//		infoNext[infoPtr] = b[v].infoHead;
//		b[v].infoHead = infoPtr;
//
//		infoKey[infoPtr++] = arr;
//		infoKey[infoPtr++] = last;
		
		for (int i = 0; i < arr.length; i += 2){
			Cell cell = b[v].cells[i / 2];
//			b[v].cells[]
			infoNext[infoPtr] = cell.infoHead;
			cell.infoHead = infoPtr;
			
			infoKey[2 * infoPtr] = arr[i];
			infoKey[2 * infoPtr + 1] = arr[i + 1];
			infoPtr++;
		}

		int y1 = b[v].y1;
		int y2 = b[v].y2;

		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			if (u == p || dead[u]) {
				continue;
			}

			Node nodeU = b[u];
			int[] newArr = new int[2 * nodeU.len()];

			for (int y = nodeU.y1, i = 0; y <= nodeU.y2; y++, i++) {
				if (y < y1) {
					newArr[2 * i] = arr[0] + 1 + y1 - y;
					newArr[2 * i + 1] = arr[1];
				} else if (y > y2) {
					newArr[2 * i] = arr[arr.length - 2] + 1 + y - y2;
					newArr[2 * i + 1] = arr[arr.length - 1];
				} else {
					newArr[2 * i] = arr[2 * (y - y1)] + 1;
					newArr[2 * i + 1] = arr[2 * (y - y1) + 1];
				}
			}

			dfs2(u, v, root, newArr);
		}
	}

	void goCentre(int v) {
		Node node = b[v];
		// int[] dist = new int[node.y2 - node.y1 + 1];
		// int[] last = new int[node.y2 - node.y1 + 1];
		int[] arr = new int[2 * node.len()];
		for (int i = 0; i < node.len(); i++) {
			arr[2 * i + 1] = i;
		}
		dfs2(v, -1, v, arr);
	}

	void go(int v, int father) {
		dfsSz(v, -1);
		int root = v;
		outer: while (true) {
			// for (int u : g[root]) {
			for (int e = head[root]; e >= 0; e = next[e]) {
				int u = to[e];
				if (!dead[u] && sz[u] < sz[root] && 2 * sz[u] > sz[v]) {
					root = u;
					continue outer;
				}
			}
			break;
		}

		par[root] = father;

		goCentre(root);
		dead[root] = true;
		for (int e = head[root]; e >= 0; e = next[e]) {
			int u = to[e];
			if (!dead[u]) {
				go(u, root);
			}
		}
	}

	void dfsSz(int v, int p) {
		sz[v] = 1;
		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			if (u != p && !dead[u]) {
				dfsSz(u, v);
				sz[v] += sz[u];
			}
		}
	}

	int[] next;
	int[] head;
	int[] to;
	int ptr;

	void addEdge(int v, int u) {
		to[ptr] = u;
		next[ptr] = head[v];
		head[v] = ptr++;

		to[ptr] = v;
		next[ptr] = head[u];
		head[u] = ptr++;
	}

	void preCalc() {

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

	E_fenwick() throws IOException {
		is = System.in;
		// is = new FileInputStream("shit.in");
		out = new PrintWriter(System.out);
		// out = new PrintWriter("shit.out");
		preCalc();
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
		new E_fenwick();
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