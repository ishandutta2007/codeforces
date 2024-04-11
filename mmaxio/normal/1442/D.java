import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class C {

	int[] readArray() {
		int len = nextInt();
		int[] a = new int[len];
		for (int i = 0; i < len; i++) {
			a[i] = nextInt();
		}
		return a;
	}

	long go(int[][] a, int k, int idx) {
		if (k == 0 || idx == a.length) {
			return 0;
		}
		long ret = go(a, k, idx + 1);
		long delta = 0;
		for (int pick = 1; pick <= k && pick <= a[idx].length; pick++) {
			delta += a[idx][pick - 1];
			ret = Math.max(ret, go(a, k - pick, idx + 1) + delta);
		}
		return ret;
	}

	long slow(int[][] a, int k) {
		return go(a, k, 0);
	}

	static final long INF = Long.MAX_VALUE / 4;

	static final long start = System.currentTimeMillis();

	static class StackKnapsack {
		long[][] dp;
		int curOps = 0;

		int k;

		public StackKnapsack(int maxOps, int k) {
			this.k = k;
			dp = new long[maxOps + 1][k + 1];
			Arrays.fill(dp[0], -INF);
			dp[0][0] = 0;
		}

		public void push(UpdateInfo upd) {// cost, profit
			long p = upd.profit;
			int c = upd.cost;
			long[] src = dp[curOps];
			long[] dst = dp[curOps + 1];
			System.arraycopy(src, 0, dst, 0, c);
			for (int i = c; i <= k; ++i) {
				dst[i] = Math.max(src[i], src[i - c] + p);
			}
			++curOps;
		}

		public void pop() {
			--curOps;
		}
	}

	// Must have auto-incrementable ID.
	static class UpdateInfo {
		private static int count;
		int id;

		int cost;
		long profit;

		public UpdateInfo(int cost, long profit) {
			id = count++;
			this.cost = cost;
			this.profit = profit;
		}
	}

	static class QueueFromStack {
		public StackKnapsack ds;

		// stack of updates that shows in which order they were actually applied
		private UpdateInfo[] stack;
		private int size;

		private UpdateInfo[] buf;

		// updates with id < mark are grouped into power-of-2 length blocks
		// and are in the "correct"(i.e. reversed) order
		private int mark;

		// id of queue's head or mark if queue is empty
		private int head;

		public QueueFromStack(StackKnapsack ds, int maxQueueSize) {
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

	long fast(int[][] a, int k) {
		int n = a.length;
		StackKnapsack sack = new StackKnapsack(n - 1, k);
		QueueFromStack que = new QueueFromStack(sack, n - 1);

		long[] sum = new long[n];
		int[] cnt = new int[n];

		for (int i = 0; i < n; i++) {
			cnt[i] = Math.min(a[i].length, k);
			for (int j = 0; j < cnt[i]; j++) {
				sum[i] += a[i][j];
			}
		}

		for (int i = 1; i < n; i++) {
			que.add(new UpdateInfo(cnt[i], sum[i]));
		}

		long ret = 0;

		for (int i = 0; i < n; i++) {
			long[] dp = sack.dp[sack.curOps];
			ret = Math.max(ret, dp[k]);
			long pref = 0;
			for (int j = 1; j <= k && j <= a[i].length; j++) {
				pref += a[i][j - 1];
				ret = Math.max(ret, dp[k - j] + pref);
			}
			if (i != n - 1) {
				que.poll();
				que.add(new UpdateInfo(cnt[i], sum[i]));
			}
		}
		return ret;
	}

	void submit() {
		int n = nextInt();
		int k = nextInt();
		int[][] g = new int[n][];
		for (int i = 0; i < n; i++) {
			g[i] = readArray();
		}
		out.println(fast(g, k));
		// out.println(slow(g, k));
	}

	void test() {
		int[][] a = new int[3][];
		a[0] = new int[] { 0, 3, 4, 4 };
		a[1] = new int[] { 3 };
		a[2] = new int[] { 2, 3 };
		int k = 4;
		System.err.println(fast(a, k));
	}

	static final int B = 8;

	void stress() {
		for (int tst = 0;; tst++) {
			int n = rand(1, B);
			int[][] a = new int[n][];
			int tot = 0;
			for (int i = 0; i < n; i++) {
				int len = rand(1, B);
				a[i] = new int[len];
				int last = 0;
				for (int j = 0; j < len; j++) {
					a[i][j] = rand(last, B);
					last = a[i][j];
				}
				tot += len;
			}
			int k = rand(1, tot);

			long slow = slow(a, k);
			long fast = fast(a, k);

			if (fast != slow) {
				System.err.println(Arrays.deepToString(a));
				System.err.println(k);
				System.err.println("fast " + fast);
				System.err.println("slow " + slow);
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	C() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		 submit();
//		stress();
		// test();
		out.close();
	}

	static final Random rng = new Random(1);
	static final int C = 5;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new C();
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