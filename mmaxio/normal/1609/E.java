import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class E {
	
	// This is an implementation of add to segment/set or add to point/query max on segment/query point.
	static class SegTree {
		Node root;
		int n;

		public SegTree(int n, int[] s) {
			Node.initS = s;
			this.n = n;
			root = new Node(0, n);
		}

		public void setPoint(int idx, int val) {
			Node.ql = idx;
			Node.delta = val;
			root.setPoint(0, n);
		}

		static class Node {
			static int ql;
			static int delta;
			static int[] initS;
			
			Node left, right;
			int v012, v01, v12, v0, v1, v2;
			
			void initChar(int c) {
				v012 = v01 = v12 = 0;
				v0 = c == 0 ? 1 : 0;
				v1 = c == 1 ? 1 : 0;
				v2 = c == 2 ? 1 : 0;
			}
			
			void combine() {
				v0 = left.v0 + right.v0;
				v1 = left.v1 + right.v1;
				v2 = left.v2 + right.v2;
				v01 = Math.min(left.v01 + right.v1, left.v0 + right.v01);
				v12 = Math.min(left.v12 + right.v2, left.v1 + right.v12);
				v012 = Math.min(Math.min(left.v0 + right.v012, left.v012 + right.v2), left.v01 + right.v12);
			}

			public Node(int l, int r) {
				if (r - l > 1) {
					int m = (l + r) >> 1;
					left = new Node(l, m);
					right = new Node(m, r);
					combine();
				} else {
					initChar(initS[l]);
				}
			}

			void setPoint(int l, int r) {
				if (r - l == 1) {
					initChar(Node.delta);
					return;
				}
				int m = (l + r) >> 1;
				if (ql < m) {
					left.setPoint(l, m);
				} else {
					right.setPoint(m, r);
				}
				combine();
			}
		}
	}


	void submit() {
		int n = nextInt();
		int q = nextInt();
		int[] a = new int[n];
		String s = nextToken();
		for (int i = 0; i < n; i++) {
			a[i] = s.charAt(i) - 'a';
		}
		
		SegTree st = new SegTree(n, a);
		
		while (q-- > 0) {
			int idx = nextInt() - 1;
			int val = nextChar() - 'a';
			st.setPoint(idx, val);
			out.println(st.root.v012);
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