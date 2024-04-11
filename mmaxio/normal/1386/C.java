import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class BOI2020C {

	static class StackDSU {
		int[] p;

		int[] idxH;
		int[] valH;
		int time = 0;

		int[] snap;
		int snapSz;

		public StackDSU(int n, int maxStackSize, int histSize) {
			p = new int[n];
			Arrays.fill(p, -1);
			idxH = new int[histSize];
			valH = new int[histSize];
			snap = new int[maxStackSize + 1];
		}

		int get(int v) {
			int ret = 0;
			while (p[v] >= 0) {
				ret ^= p[v];
				v = p[v] >> 1;
			}
			return (v << 1) | (ret & 1);
		}

		boolean canAdd(int v, int u) {
			v = get(v);
			u = get(u);

			int diff = (v ^ u) & 1;
			return ((v >> 1) != (u >> 1)) || (diff == 1);
		}

		void unite(int v, int u) {
			v = get(v);
			u = get(u);

			int diff = (v ^ u) & 1;
			v >>= 1;
			u >>= 1;

			if (v == u) {
				if (diff == 0) {
					throw new AssertionError();
				}
				return;
			}
			if (p[v] < p[u]) {
				int tmp = v;
				v = u;
				u = tmp;
			}
			set(u, p[v] + p[u]);
			set(v, (u << 1) | (diff ^ 1));
			return;
		}

		void set(int idx, int val) {
			if (p[idx] != val) {
				idxH[time] = idx;
				valH[time] = p[idx];
				p[idx] = val;
				++time;
			}
		}

		public void push(UpdateInfo upd) {
			snap[snapSz++] = time;
			unite(upd.u, upd.v);
		}

		public void pop() {
			int rollTo = snap[--snapSz];
			while (time > rollTo) {
				--time;
				p[idxH[time]] = valH[time];
			}
		}
	}

	// Must have auto-incrementable ID.
	static class UpdateInfo {
		private static int count;
		int id;

		int v, u;

		public UpdateInfo(int v, int u) {
			id = count++;
			this.v = v;
			this.u = u;
		}
	}

	static class QueueFromStack {
		public StackDSU ds;

		// stack of updates that shows in which order they were actually applied
		private UpdateInfo[] stack;
		private int size;

		private UpdateInfo[] buf;

		// updates with id < mark are grouped into power-of-2 length blocks
		// and are in the "correct"(i.e. reversed) order
		private int mark;

		// id of queue's head or mark if queue is empty
		private int head;

		public QueueFromStack(StackDSU ds, int maxQueueSize) {
			UpdateInfo.count = 0;
			this.ds = ds;
			stack = new UpdateInfo[maxQueueSize];
			buf = new UpdateInfo[maxQueueSize];
		}

		public void add(UpdateInfo upd) {
			stack[size++] = upd;
			ds.push(upd);
		}

		public void poll() {
			if (mark == head) {
				mark = UpdateInfo.count;
				for (int i = size - 1; i >= 0; --i) {
					ds.pop();
					buf[i] = stack[i];
				}
				for (int i = 0; i < size; ++i) {
					ds.push(stack[i] = buf[size - 1 - i]);
				}
			}
			int ptr = 0;
			while (stack[size - 1].id != head) {
				// must have id >= mark
				buf[ptr++] = stack[--size];
				ds.pop();
			}

			if (ptr == 0) {
				ds.pop();
				--size;
				++head;
				return;
			}

			int skip = ptr;
			int chunk = Integer.lowestOneBit(mark - head);
			for (int i = 0; i < chunk; ++i) {
				// must have id < mark
				buf[ptr++] = stack[--size];
				ds.pop();
			}

			// putting back id >= mark
			for (int i = skip - 1; i >= 0; --i) {
				ds.push(stack[size++] = buf[i]);
			}
			// putting back id < mark except id == head
			for (int i = ptr - 1; i > skip; --i) {
				ds.push(stack[size++] = buf[i]);
			}

			++head;
		}
	}

	boolean[] fast(int n, int[] vs, int[] us, int[] ls, int[] rs) {
		int m = vs.length;
		int q = ls.length;

		StackDSU dsu = new StackDSU(n, 2 * m, 2_000_000);
		QueueFromStack que = new QueueFromStack(dsu, 2 * m);

		int[] stop = new int[m];

		for (int i = 0, j = 0; i < m; i++) {
			while (j < i + m) {
				int v = vs[j % m];
				int u = us[j % m];
				if (!dsu.canAdd(v, u)) {
					break;
				}
				que.add(new UpdateInfo(v, u));
				++j;
			}
			stop[i] = j;
			que.poll();
		}

		boolean[] ret = new boolean[q];

		for (int i = 0; i < q; i++) {
			int l = ls[i];
			int r = rs[i];
			boolean ans;
			if (r == m - 1) {
				ans = stop[0] < l;
			} else {
				ans = stop[r + 1] < l + m;
			}
			ret[i] = ans;
		}

		return ret;
	}

	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}
	
	boolean slowSingle(int n, int[] vs, int[] us, int l, int r) {
		outer: for (int mask = 0; mask < 1 << n; mask++) {
			for (int i = 0; i < vs.length; i++) {
				if (l <= i && i <= r) {
					continue;
				}
				if (test(mask, vs[i]) == test(mask, us[i])) {
					continue outer;
				}
			}
			return false;
		}
		return true;
	}

	boolean[] slow(int n, int[] vs, int[] us, int[] ls, int[] rs) {
		boolean[] ret = new boolean[ls.length];

		for (int i = 0; i < ls.length; i++) {
			ret[i] = slowSingle(n, vs, us, ls[i], rs[i]);
		}

		return ret;
	}

	void submit() {
		int n = nextInt();
		int m = nextInt();
		int q = nextInt();
		int[] vs = new int[m];
		int[] us = new int[m];
		for (int i = 0; i < m; i++) {
			vs[i] = nextInt() - 1;
			us[i] = nextInt() - 1;
		}

		int[] ls = new int[q];
		int[] rs = new int[q];

		for (int i = 0; i < q; i++) {
			ls[i] = nextInt() - 1;
			rs[i] = nextInt() - 1;
		}

		boolean[] ans = fast(n, vs, us, ls, rs);
//		boolean[] ans = slow(n, vs, us, ls, rs);

		for (boolean b : ans) {
			out.println(b ? "YES" : "NO");
		}
	}

	void test() {

	}

	static final int B = 10;
	
	void stress() {
		for (int tst = 0;; tst++) {
			int n = rand(2, B);
			int m = rand(1, B);
			int q = B;
			int[] vs = new int[m];
			int[] us = new int[m];
			for (int i = 0; i < m; i++) {
				vs[i] = rand(0, n - 1);
				us[i] = (vs[i] + rand(1, n - 1)) % n;
			}
			int[] ls = new int[q];
			int[] rs = new int[q];
			for (int i = 0; i < q; i++) {
				ls[i] = rand(0, m - 1);
				rs[i] = rand(ls[i], m - 1);
			}
			
			boolean[] fast = fast(n, vs, us, ls, rs);
			boolean[] slow = slow(n, vs, us, ls, rs);
			
			if (!Arrays.equals(fast, slow)) {
				System.err.println(n + " " + m + " " + q);
				System.err.println(Arrays.toString(vs));
				System.err.println(Arrays.toString(us));
				System.err.println(Arrays.toString(ls));
				System.err.println(Arrays.toString(rs));
				
				System.err.println("fast " + Arrays.toString(fast));
				System.err.println("slow " + Arrays.toString(slow));
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	BOI2020C() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		submit();
//		 stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 5;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new BOI2020C();
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