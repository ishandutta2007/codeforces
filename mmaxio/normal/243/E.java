import java.io.*;
import java.util.*;

public class PQTree_test {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static PQNode[] collect(PQNode[] arr, int whatStatus) {
		int sz = 0;
		for (PQNode v : arr) {
			if (v.status == whatStatus) {
				sz++;
			}
		}

		PQNode[] ret = new PQNode[sz];
		int ptr = 0;
		for (PQNode v : arr) {
			if (v.status == whatStatus) {
				ret[ptr++] = v;
			}
		}

		return ret;
	}

	static PQNode makeNode(PQNode[] arr, int whatType) {
		if (arr.length == 0) {
			return null;
		}
		if (arr.length == 1) {
			return arr[0];
		}
		if (arr.length == 2) {
			whatType = PQNode.Q_NODE;
		}
		return new PQNode(whatType, arr);
	}

	static <T> void fullCopy(T[] src, T[] dest, int destPos) {
		System.arraycopy(src, 0, dest, destPos, src.length);
	}

	static PQNode[] appendFirst(PQNode v, PQNode[] arr) {
		if (v == null) {
			return arr;
		}
		PQNode[] ret = new PQNode[arr.length + 1];
		ret[0] = v;
		fullCopy(arr, ret, 1);
		return ret;
	}

	static PQNode[] appendLast(PQNode v, PQNode[] arr) {
		if (v == null) {
			return arr;
		}
		PQNode[] ret = new PQNode[arr.length + 1];
		fullCopy(arr, ret, 0);
		ret[arr.length] = v;
		return ret;
	}

	static PQNode[] concat(PQNode[] arr1, PQNode[] arr2) {
		PQNode[] ret = new PQNode[arr1.length + arr2.length];
		fullCopy(arr1, ret, 0);
		fullCopy(arr2, ret, arr1.length);
		return ret;
	}

	static <T> void reverse(T[] a) {
		for (int i = 0, j = a.length - 1; i < j; i++, j--) {
			T tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}

	static class PQNode {
		static final int P_NODE = -1;
		static final int Q_NODE = -2;

		/**
		 * < 0 if P or Q node <br>
		 * otherwise this node is leaf and type is number of element
		 */
		int type;
		PQNode[] child;

		public PQNode(int type, PQNode[] child) {
			this.type = type;
			this.child = child;
		}

		static final int EMPTY = 0;
		static final int FULL = 1;
		static final int PARTIAL = 2;
		static final int CONTAINS_ALL = 3;
		/**
		 * see above for possible values <br>
		 * in case of partial, first children are in current query, then not
		 */
		int status;

		/**
		 * number of leafs from current query in this subtree
		 */
		int count;

		PQNode dfs(boolean[] b, int allQry) {

			if (type >= 0) {
				status = b[type] ? FULL : EMPTY;
				count = b[type] ? 1 : 0;
				return this;
			}

			count = 0;

			boolean allFull = true;
			boolean allEmpty = true;
			int cntPartial = 0;
			int[] idxPartial = new int[2];

			for (int i = 0; i < child.length; i++) {
				child[i] = child[i].dfs(b, allQry);
				if (child[i] == null) {
					return null;
				}
			}

			for (int i = 0; i < child.length; i++) {
				PQNode v = child[i];

				if (v.status == CONTAINS_ALL) {
					status = CONTAINS_ALL;
					return this;
				}
				allFull &= v.status == FULL;
				allEmpty &= v.status == EMPTY;
				if (v.status == PARTIAL) {
					if (cntPartial == 2) {
						return null;
					}
					idxPartial[cntPartial++] = i;
				}
				count += v.count;
			}

			boolean doesContainAll = count == allQry;

			if (allFull) {
				status = FULL;
				return this;
			}

			if (allEmpty) {
				status = EMPTY;
				return this;
			}

			if (cntPartial <= 1 && type == P_NODE && doesContainAll) {
				PQNode[] fulls = collect(child, FULL);
				PQNode[] emptys = collect(child, EMPTY);

				PQNode fullNode = makeNode(fulls, P_NODE);

				PQNode fullAndPartial;
				if (cntPartial == 0) {
					fullAndPartial = fullNode;
				} else {
					PQNode[] arr = appendFirst(fullNode,
							child[idxPartial[0]].child);
					fullAndPartial = makeNode(arr, Q_NODE);
				}

				PQNode[] arr = appendFirst(fullAndPartial, emptys);
				PQNode ret = makeNode(arr, P_NODE);
				ret.status = CONTAINS_ALL;
				return ret;
			}

			if (cntPartial <= 1 && type == P_NODE && !doesContainAll) {
				PQNode[] fulls = collect(child, FULL);
				PQNode[] emptys = collect(child, EMPTY);

				PQNode full = makeNode(fulls, P_NODE);
				if (full != null) {
					full.status = FULL;
				}
				PQNode empty = makeNode(emptys, P_NODE);
				if (empty != null) {
					empty.status = EMPTY;
				}
				
				PQNode ret;
				if (cntPartial == 1) {
					PQNode[] arr = appendFirst(full,
							appendLast(empty, child[idxPartial[0]].child));
					ret = makeNode(arr, Q_NODE);
				} else {
					ret = makeNode(new PQNode[] { full, empty }, Q_NODE);
				}
				ret.count = count;
				ret.status = PARTIAL;
				return ret;
			}

			if (cntPartial == 2 && type == P_NODE && doesContainAll) {
				PQNode[] fulls = collect(child, FULL);
				PQNode[] emptys = collect(child, EMPTY);

				PQNode fullNode = makeNode(fulls, P_NODE);

				reverse(child[idxPartial[0]].child);

				PQNode[] tmp = appendLast(fullNode, child[idxPartial[0]].child);
				PQNode fullAndPartial = makeNode(
						concat(tmp, child[idxPartial[1]].child), Q_NODE);

				PQNode[] arr = appendFirst(fullAndPartial, emptys);
				PQNode ret = makeNode(arr, P_NODE);
				ret.status = CONTAINS_ALL;
				return ret;
			}
			
			if (type == Q_NODE) {
				int size = child.length;
				for (int i = 0; i < cntPartial; i++) {
					size += child[idxPartial[i]].child.length - 1;
				}
				
				PQNode[] arr = new PQNode[size];
				int ptr = 0;
				
				boolean firstPartial = true;
				for (int i = 0; i< child.length; i++) {
					PQNode v = child[i];
					if (v.status == PARTIAL) { 
						
						boolean shouldRev;
						if (cntPartial == 1) {
							if (i == 0) {
								shouldRev = child[i + 1].status == FULL;
							} else {
								shouldRev = child[i - 1].status == EMPTY;
							}
						} else {
							shouldRev = firstPartial;
							firstPartial = !firstPartial;
						}
						
						if (shouldRev) {
							reverse(v.child);
						}
						
						for (PQNode u : v.child) {
							arr[ptr++] = u;
						}
					} else {
						arr[ptr++] = v;
					}
				}
				
				if (arr[arr.length - 1].status == FULL) {
					reverse(arr);
				}
				
				ptr = arr.length - 1;
				while (ptr >= 0 && arr[ptr].status == EMPTY) {
					ptr--;
				}
				while (ptr >= 0 && arr[ptr].status == FULL) {
					ptr--;
				}
				
				if (ptr == -1) {
					PQNode ret = makeNode(arr, Q_NODE);
					ret.count = count;
					ret.status = doesContainAll ? CONTAINS_ALL : PARTIAL;
					return ret;
				}
				
				while (ptr >= 0 && arr[ptr].status == EMPTY) {
					ptr--;
				}
				
				if (ptr == -1 && doesContainAll) {
					PQNode ret = makeNode(arr, Q_NODE);
					ret.status = CONTAINS_ALL;
					return ret;
				}
			}
			
			return null;
		}

		void genRepr(StringBuilder sb) {
			if (type >= 0) {
				sb.append(type + " ");
				return;
			}
			sb.append(type == P_NODE ? "[" : "(");
			for (PQNode v : child) {
				v.genRepr(sb);
			}
			sb.append(type == P_NODE ? "]" : ")");
		}
		
		void getOrder(List<Integer> ret) {
			if (type >= 0) {
				ret.add(type);
				return;
			}
			for (PQNode v : child) {
				v.getOrder(ret);
			}
		}
	}

	static class PQTree {
		/**
		 * null if there are no permutations
		 */
		PQNode root;
		int n;

		public PQTree(int n) {
			this.n = n;
			PQNode[] arr = new PQNode[n];
			for (int i = 0; i < n; i++) {
				arr[i] = new PQNode(i, null);
			}
			root = makeNode(arr, PQNode.P_NODE);
		}

		void update(boolean[] b) {
			if (root == null) {
				return;
			}
			int cnt = 0;
			for (boolean flag : b) {
				cnt += flag ? 1 : 0;
			}
			if (cnt <= 1 || cnt == b.length) {
//				System.err.println("skipped");
				return;
			}
			root = root.dfs(b, cnt);
			
//			System.err.println(this);
		}

		@Override
		public String toString() {
			if (root == null) {
				return "null";
			}
			StringBuilder sb = new StringBuilder();
			root.genRepr(sb);
			return sb.toString();
		}
		
		List<Integer> getOrder() {
			List<Integer> ret = new ArrayList<>(n);
			root.getOrder(ret);
			return ret;
		}
	}

	void submit() throws IOException {
//		PQTree tree = new PQTree(6);
//		tree.update(new boolean[] { true, false, false, false, true, false });
//		tree.update(new boolean[] { true, true, false, true, true, false });
//		tree.update(new boolean[] { false, true, true, false, false, true});
//		tree.update(new boolean[] { false, true, false, false, true, false});
//		tree.update(new boolean[] { false, false, false, true, false, false});
//		tree.update(new boolean[] { false, true, true, false, false, true});
		
		int n = nextInt();
		PQTree tree = new PQTree(n);
		char[][] f = new char[n][];
		for (int i = 0; i < n; i++) {
			f[i] = nextToken().toCharArray();
			boolean[] b = new boolean[n];
			for (int j = 0; j < n; j++) {
				b[j] = f[i][j] == '1';
			}
			tree.update(b);
		}
		
		if (tree.root == null) {
			out.println("NO");
			return;
		}
		
		out.println("YES");
		List<Integer> order = tree.getOrder();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				out.print(f[i][order.get(j)]);
			}
			out.println();
		}
		
	}
	
	static final Random rng = new Random();
	
	int[] genRandomPerm(int n) {
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			int j = rng.nextInt(i + 1);
			p[i] = p[j];
			p[j] = i;
		}
		return p;
	}
	
	void oneTest(int n) {
		int[] p = genRandomPerm(n);
		char[][] f = new char[n][n];
		
		PQTree t = new PQTree(n);
		
		for (int i = 0; i < n; i++) {
			Arrays.fill(f[i], '0');
			int low = rng.nextInt(n);
			int high = rng.nextInt(n);
			if (low > high) {
				int tmp = low;
				low = high;
				high = tmp;
			}
			
			boolean[] b = new boolean[n];
			for (int j = low; j <= high; j++) {
				f[i][p[j]] = '1';
				b[p[j]] = true;
			}
			
			t.update(b);
		}
		
		if (t.root == null) {
			System.err.println(n);
			System.err.println(Arrays.toString(p));
			for (int i = 0; i < n; i++) {
				System.err.println(f[i]);
			}
			throw new AssertionError();
		}
	}
	
	void stress(int n) {
		for (int tst = 0; tst >= 0; tst++) {
			oneTest(n);
			System.err.println(tst);
		}
	}
	
	void test() {
		PQTree t = new PQTree(5);
		t.update(new boolean[]{false, false, true, true, false});
		t.update(new boolean[]{true, true, true, true, false});
		t.update(new boolean[]{true, true, true, false, true});
	}

	PQTree_test() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		submit();
//		stress(100);
//		test();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new PQTree_test();
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