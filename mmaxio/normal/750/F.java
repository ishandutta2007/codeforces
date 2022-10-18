import java.io.*;
import java.util.*;

public class F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final boolean LOCAL = false;
	static final int MAX_QUERIES = 16;

	int localH;
	int[] localOrder;
	int[] localInv;
	int localN;

	boolean localAnswer;

	int localQueryCnt;

	static final Random rng = new Random();

	void prepareLocal() {
		localH = 7;
		localN = (1 << localH) - 1;
		localAnswer = false;

		localInv = new int[localN];

		 localOrder = new int[localN];
		 for (int i = 0; i < localN; i++) {
		 int j = rng.nextInt(i + 1);
		 localOrder[i] = localOrder[j];
		 localOrder[j] = i;
		 }

//		localOrder = new int[] { 10, 3, 19, 9, 0, 20, 5, 29, 28, 14, 18, 27,
//				24, 8, 11, 13, 1, 21, 15, 17, 22, 4, 26, 23, 30, 16, 6, 2, 12,
//				7, 25 };

		for (int i = 0; i < localN; i++) {
			localInv[localOrder[i]] = i;
		}

		localQueryCnt = 0;
	}

	int askHeight() throws IOException {
		if (!LOCAL) {
			return nextInt();
		} else {
			return localH;
		}
	}

	int[] properAsk(int v) throws IOException {
		if (!LOCAL) {
			out.println("? " + (v + 1));
			out.flush();
			int cnt = nextInt();
			int[] ret = new int[cnt];
			for (int i = 0; i < cnt; i++) {
				ret[i] = nextInt() - 1;
			}

			return ret;
		} else {

			if (++localQueryCnt > MAX_QUERIES) {
				throw new AssertionError("Too many queries");
			}

			int where = localInv[v];
			int[] ret = new int[3];
			int ptr = 0;
			if (where != 0) {
				ret[ptr++] = localOrder[(where - 1) / 2];
			}
			if (2 * where + 1 < localN) {
				ret[ptr++] = localOrder[2 * where + 1];
				ret[ptr++] = localOrder[2 * where + 2];
			}
			ret = Arrays.copyOf(ret, ptr);
			Arrays.sort(ret);
			return ret;
		}
	}

	void properAnswer(int v) {
		if (!LOCAL) {
			out.println("! " + (v + 1));
			out.flush();
			return;
		} else {
			if (localAnswer) {
				throw new AssertionError("Two answers");
			}
			if (v != localOrder[0]) {
				// System.err.println(Arrays.toString(localOrder));
				throw new AssertionError("Wrong answer");
			}
			System.err.println("OK! " + localQueryCnt + " queries");
			localAnswer = true;
		}
	}

	int[] ask(int v) throws IOException {

		if (g[v] != null) {
			return g[v];
		}

		int[] ret = properAsk(v);
		g[v] = ret;
		for (int i = 0; i < ret.length; i++) {
			if (par[ret[i]] == -1) {
				par[ret[i]] = v;
			}
		}

		if (ret.length == 2) {
			properAnswer(v);
			return null;
		}

		return ret;
	}

	int[] par;
	int[][] g;

	int deeper(int v) {
		if (g[v] == null) {
			throw new AssertionError("Haven't asked yet");
		}
		for (int u : g[v]) {
			if (u != par[v] && g[u] != null) {
				return u;
			}
		}
		for (int u : g[v]) {
			if (u != par[v]) {
				return u;
			}
		}
		throw new AssertionError("Can't go deeper");
	}

	void solve() throws IOException {
		int h = askHeight();

		int n = (1 << h) - 1;
		par = new int[n];
		Arrays.fill(par, -1);
		par[0] = 0;
		g = new int[n][];

//		if (h <= 4) {
//			for (int i = 0; i < n; i++) {
//				int[] tmp = ask(i);
//				if (tmp == null) {
//					return;
//				}
//			}
//		}

		int[] root = ask(0);
		if (root == null) {
			return;
		}

		int curV, curDepth;

		if (root.length == 3) {
			int[] cur = root.clone();
			int[] initCur = cur.clone();
			int dist = 1;
			int nonLeaf, leaf;
			initSearch: for (;; dist++) {

				nonLeaf = -1;
				leaf = -1;

				for (int i = 0; i < 3; i++) {
					int[] tmp = ask(cur[i]);
					if (tmp == null) {
						return;
					}
					if (tmp.length == 1) {
						leaf = i;
					} else {
						nonLeaf = i;
					}

					if (leaf != -1 && nonLeaf != -1) {
						break initSearch;
					}
				}

				for (int i = 0; i < 3; i++) {
					cur[i] = deeper(cur[i]);
				}
			}

			curV = initCur[nonLeaf];
			curDepth = h - 2 - dist;
		} else {
			curV = root[0];
			curDepth = h - 2;
		}

		while (curDepth > 2) {

			if (ask(curV) == null) {
				return;
			}

			int[] cur = remove(g[curV], par[curV]);
			if (cur.length != 2) {
				throw new AssertionError();
			}

			int[] initCur = cur.clone();

			int nonLeaf, leaf;
			sndSearch: while (true) {

				nonLeaf = -1;
				leaf = -1;

				for (int i = 0; i < 2; i++) {
					int[] tmp = ask(cur[i]);
					if (tmp == null) {
						return;
					}
					if (tmp.length == 1) {
						leaf = i;
					} else {
						nonLeaf = i;
					}

					if (leaf != -1 && nonLeaf != -1) {
						break sndSearch;
					}
				}

				for (int i = 0; i < 2; i++) {
					cur[i] = deeper(cur[i]);
				}
			}

			curV = initCur[nonLeaf];
			curDepth--;

		}

		int[] tmp = ask(curV);
		if (tmp == null) {
			return;
		}

		if (curDepth == 1) {
			for (int u : g[curV]) {
				if (u != par[curV]) {
					tmp = ask(u);
					if (tmp == null) {
						return;
					}

					int output = g[curV][0] ^ g[curV][1] ^ g[curV][2] ^ u
							^ par[curV];
					// out.println("! " + (output + 1));
					// out.flush();
					properAnswer(output);
					return;

				}
			}
		}

		if (curDepth == 2) {
			ArrayDeque<Integer> q = new ArrayDeque<>();
			q.add(curV);

			boolean[] used = new boolean[n];
			used[par[curV]] = true;

			for (int i = 0; i < 6; i++) {
				int top = q.poll();
				used[top] = true;
				if (ask(top) == null) {
					return;
				}

				for (int u : g[top]) {
					if (!used[u]) {
						q.add(u);
					}
				}

			}

			int output = q.poll();
			properAnswer(output);
			return;
		}

	}

	int[] remove(int[] arr, int value) {
		int idx = -1;
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] == value) {
				if (idx != -1) {
					throw new AssertionError("Two values");
				}
				idx = i;
			}
		}
		if (idx == -1) {
			throw new AssertionError("No values");
		}

		int[] ret = new int[arr.length - 1];

		System.arraycopy(arr, 0, ret, 0, idx);
		System.arraycopy(arr, idx + 1, ret, idx, ret.length - idx);

		return ret;
	}

	void localWrapper() throws IOException {
		if (LOCAL) {
			prepareLocal();
		}
		solve();
		if (LOCAL) {
			if (!localAnswer) {
				throw new AssertionError("No answer");
			}
		}
	}

	F() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		int t = nextInt();
		while (t-- > 0) {
			localWrapper();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new F();
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