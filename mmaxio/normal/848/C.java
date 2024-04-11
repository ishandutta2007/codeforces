import java.io.*;
import java.util.*;

public class C {

	static final int QUERIES = 900000;

	int[] qx = new int[QUERIES];
	int[] qy = new int[QUERIES];
	int[] qd = new int[QUERIES];
	int qPtr = 0;

	void addModify(int x, int y, int d) {
		qx[qPtr] = x;
		qy[qPtr] = y;
		qd[qPtr] = d;
		qPtr++;
	}

	void addQuery(int x, int y) {
		qx[qPtr] = x;
		qy[qPtr] = y;
		qd[qPtr] = Integer.MAX_VALUE;
		qPtr++;
	}

	TreeSet<Integer>[] set;

	int n;

	void submit() {
		n = nextInt();
		int q = nextInt();

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt() - 1;
		}

		int[] last = new int[n];
		Arrays.fill(last, -1);

		set = new TreeSet[n];
		for (int i = 0; i < n; i++) {
			set[i] = new TreeSet<>();
		}

		for (int i = 0; i < n; i++) {
			int x = a[i];
			if (last[x] != -1) {
				addModify(last[x], i, i - last[x]);
			}
			last[x] = i;
			set[x].add(i);
		}

		while (q-- > 0) {
			int type = nextInt();
			if (type == 1) {
				int pos = nextInt() - 1;
				int newVal = nextInt() - 1;

				modify(pos, a[pos], -1);

				a[pos] = newVal;
				modify(pos, a[pos], 1);
			} else {
				int l = nextInt() - 1;
				int r = nextInt() - 1;
				addQuery(l, r);
			}
		}

		// goStupid();
		goSmart();
	}
	
	static void addFen(long[] fen, int idx, int delta) {
		for (int i = idx; i < fen.length; i |= i + 1) {
			fen[i] += delta;
		}
	}
	
	static long getFen(long[] fen, int idx) {
		long ret = 0;
		for (int i = idx; i >= 0; i = (i & (i + 1)) - 1) {
			ret += fen[i];
		}
		return ret;
	}

	static class Node {
		int l, r;
		Node left, right;

		ArrayList<Integer> allY = new ArrayList<>();
		int[] uniqueY;
		long[] fen;

		public Node(int l, int r) {
			this.l = l;
			this.r = r;

			if (r - l > 1) {
				int m = (l + r) >> 1;
				left = new Node(l, m);
				right = new Node(m, r);
			}
		}

		void mark(int x, int y) {
			if (l >= x) {
				allY.add(y);
				return;
			}
			if (r <= x) {
				return;
			}
			left.mark(x, y);
			right.mark(x, y);
		}

		void makeUnique() {
			makeUniqueHere();
			if (r - l > 1) {
				left.makeUnique();
				right.makeUnique();
			}
		}
		
		void add(int x, int y, int d) {
			int idx = Arrays.binarySearch(uniqueY, y);
			if (idx < 0) {
				idx = -idx - 1;
			}
			if (idx < fen.length) {
				addFen(fen, idx, d);
			}
			if (r - l > 1) {
				(x < left.r ? left : right).add(x, y, d);
			}
		}
		
		long getSum(int x, int y) {
			if (l >= x) {
				int idx = Arrays.binarySearch(uniqueY, y);
				return getFen(fen, idx);
			}
			if (r <= x) {
				return 0;
			}
			return left.getSum(x, y) + right.getSum(x, y);
		}

		void makeUniqueHere() {
			if (allY.isEmpty()) {
				uniqueY = new int[0];
				fen = new long[0];
			} else {
				Collections.sort(allY);
				int sz = 1;
				for (int i = 1; i < allY.size(); i++) {
					if (!allY.get(i).equals(allY.get(sz - 1))) {
						allY.set(sz, allY.get(i));
						sz++;
					}
				}

				uniqueY = new int[sz];
				fen = new long[sz];
				for (int i = 0; i < sz; i++) {
					uniqueY[i] = allY.get(i);
				}
			}
			allY = null;
		}
	}

	void goSmart() {
		Node root = new Node(0, n);
		for (int i = 0; i < qPtr; i++) {
			int x = qx[i];
			int y = qy[i];
			int d = qd[i];

			if (d == Integer.MAX_VALUE) {
				root.mark(x, y);
			}
		}

		root.makeUnique();
		
		for (int i = 0; i < qPtr; i++) {
			int x = qx[i];
			int y = qy[i];
			int d = qd[i];
			if (d == Integer.MAX_VALUE) {
				out.println(root.getSum(x, y));
			} else {
				root.add(x, y, d);
			}
		}
		
	}

	void goStupid() {
		int[][] arr = new int[n][n];
		for (int i = 0; i < qPtr; i++) {
			int x = qx[i];
			int y = qy[i];
			int d = qd[i];

			if (d == Integer.MAX_VALUE) {

				int ret = 0;

				for (int ix = x; ix < n; ix++) {
					for (int iy = 0; iy <= y; iy++) {
						ret += arr[ix][iy];
					}
				}

				out.println(ret);
			} else {
				arr[x][y] += d;
			}
		}
	}

	void modify(int pos, int val, int sign) {

		if (sign == 1) {
			set[val].add(pos);
		} else {
			set[val].remove(pos);
		}

		Integer prev = set[val].lower(pos);
		Integer next = set[val].higher(pos);

		if (prev != null) {
			addModify(prev, pos, sign * (pos - prev));
		}
		if (next != null) {
			addModify(pos, next, sign * (next - pos));
		}
		if (prev != null && next != null) {
			addModify(prev, next, -sign * (next - prev));
		}
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	C() throws IOException {
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
		new C();
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