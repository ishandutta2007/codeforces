import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class D_new {

	static final long INF = Long.MAX_VALUE / 10;

	static class Segment implements Comparable<Segment> {
		int l, r, k;

		public Segment(int l, int r, int k) {
			this.l = l;
			this.r = r;
			this.k = k;
		}

		@Override
		public int compareTo(Segment o) {
			return Integer.compare(r, o.r);
		}
	}

	long[] pref, suff;
	
	static class SegTree {
		Node root;
		int n;
		
		public SegTree(long[] pref, long[] suff) {
			root = new Node(0, pref.length, pref, suff);
			n = pref.length;
		}
		
		long[] query(int l, int r) {
			Node.ql = l;
			Node.qr = r;
			return root.query(0, n);
		}
		
		void update(int idx, long value) {
			Node.qIdx = idx;
			Node.qValue = value;
			root.set(0, n);
		}

		static class Node {
			static int ql, qr, qIdx;
			static long qValue;
			
			Node left, right;
			
			long vl, vr, vlr;
			
			public Node(int l, int r, long[] pref, long[] suff) {
				if (r - l == 1) {
					vl = pref[l];
					vr = suff[l];
					vlr = -INF;
					return;
				}
				
				int m = (l + r) >> 1;
				left = new Node(l, m, pref, suff);
				right = new Node(m, r, pref, suff);
				vr = Math.max(left.vr, right.vr);
				combine();
			}
			
			void combine() {
				vl = Math.max(left.vl, right.vl);
				vlr = Math.max(Math.max(left.vlr, right.vlr), left.vl + right.vr);
			}
			
			long[] query(int l, int r) {
				if (l >= qr || ql >= r) {
					return null;
				}
				if (ql <= l && r <= qr) {
					return new long[] {vl, vr, vlr};
				}
				int m = (l + r) >> 1;
				long[] a = left.query(l, m);
				long[] b = right.query(m, r);
				if (a == null) {
					return b;
				}
				if (b == null) {
					return a;
				}
				a[2] = Math.max(a[2], Math.max(b[2], a[0] + b[1]));
				a[0] = Math.max(a[0], b[0]);
				a[1] = Math.max(a[1], b[1]);
				return a;
			}
			
			void set(int l, int r) {
				if (r - l == 1) {
					vl = qValue;
					return;
				}
				int m = (l + r) >> 1;
				if (qIdx < m) {
					left.set(l, m);
				} else {
					right.set(m, r);
				}
				combine();
			}
			
		}
	}

	void submit() {
		int n = nextInt();
		int q = nextInt();

		int[][] a = new int[3][n];
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				a[i][j] = nextInt();
			}
		}

		long base = 0;
		for (long x : a[1]) {
			base += x;
		}

		pref = new long[n + 1];
		pref[0] = a[0][0];
		for (int i = 1; i < n; i++) {
			pref[i] = pref[i - 1] + a[0][i] - a[1][i - 1];
		}

		suff = new long[n + 1];
		suff[n] = a[2][n - 1];
		for (int i = n - 1; i > 0; i--) {
			suff[i] = suff[i + 1] + a[2][i - 1] - a[1][i];
		}
		
//		System.err.println(base);
//		System.err.println(Arrays.toString(pref));
//		System.err.println(Arrays.toString(suff));

		Segment[] b = new Segment[q];
		for (int i = 0; i < q; i++) {
			int l = nextInt() - 1;
			int r = nextInt();
			int k = nextInt();
			b[i] = new Segment(l, r, k);
		}
		
		SegTree t = new SegTree(pref, suff);
		
		Arrays.sort(b);
		long ans = -INF;
		
		for (Segment s : b) {
			long[] tmp = t.query(s.l, s.r + 1);
			ans = Math.max(ans, tmp[2] - s.k);
			long newVal = tmp[0] - s.k;
			if (newVal > pref[s.r]) {
				t.update(s.r, newVal);
				pref[s.r] = newVal; 
			}
		}
		
		out.println(ans + base);
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

	D_new() throws IOException {
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
		new D_new();
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