import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class cfGlobal15I {
	
	static final int P = 998244353;
	
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

		// not necessary methods below

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
		
		void getCounts(int[] a) {
			if (type >= 0) {
				return;
			}
			if (type == P_NODE) {
				a[child.length]++;
			} else {
				a[2]++;
			}
			for (PQNode v : child) {
				v.getCounts(a);
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
				return;
			}
			root = root.dfs(b, cnt);
		}

		// not necessary methods below

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
		
		int[] getCounts() {
			int[] ret = new int[n + 1];
			root.getCounts(ret);
			return ret;
		}
	}

	void submit() {
		int n = nextInt();
		int m = nextInt();
		PQTree pq = new PQTree(n);
		for (int i=  0;i < m; i++) {
			boolean[] b = new boolean[n];
			int k = nextInt();
			while (k-- > 0) {
				b[nextInt() - 1] = true;
			}
			pq.update(b);
		}
		
		int[] fact = new int[n + 1];
		fact[0] = 1;
		for (int i = 1; i < fact.length; i++) {
			fact[i] = (int)((long)fact[i - 1] * i % P);
		}
		
		if (pq.root == null) {
			out.println(0);
		} else {
			int ret = 1;
			int[] cnt = pq.getCounts();
			for (int i = 1; i < cnt.length; i++) {
				for (int j = 0; j < cnt[i]; j++) {
					ret = (int)((long)ret * fact[i] % P);
				}
			}
			out.println(ret);
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

	cfGlobal15I() throws IOException {
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
		new cfGlobal15I();
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