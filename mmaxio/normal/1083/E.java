import java.io.*;
import java.util.*;

public class ConvexHullOnline {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Line {

		long k, b;
		long p;

		public int compareTo(Line o) {
			if (k != o.k) {
				return k < o.k ? -1 : 1;
			}
			return Long.compare(b, o.b);
		}

		public Line(long k, long b) {
			this.k = k;
			this.b = b;
		}

		Line l, r, up;
	}

	static class CHOnline {

		static long floorDiv(long a, long b) {
			long r = a / b;
			return r - ((a ^ b) < 0 && b * r != a ? 1 : 0);
		}

		static final long INF = Long.MAX_VALUE;

		static private void splay(Line v) {
			while (v.up != null) {
				Line u = v.up;
				Line t = u.up;
				if (u.up != null) {
					rotate((t.l == u) == (u.l == v) ? u : v);
				}
				rotate(v);
			}
		}

		static private void relink(Line v, Line u) {
			Line t = u.up;
			if (v != null) {
				v.up = t;
			}
			if (t != null) {
				if (t.l == u) {
					t.l = v;
				} else if (t.r == u) {
					t.r = v;
				}
			}
		}

		static private void rotate(Line v) {
			Line u = v.up;

			if (u.l == v) {
				relink(v.r, v);
				v.r = u;
			} else {
				relink(v.l, v);
				v.l = u;
			}

			relink(v, u);
			u.up = v;
		}

		private Line END = new Line(INF, 0);
		{
			END.p = INF;
		}

		private Line root = END;

		private boolean isect(Line x, Line y) {
			if (y == END) {
				x.p = INF;
				return false;
			}
			if (x.k == y.k) {
				x.p = x.b > y.b ? INF : -INF;
			} else {
				x.p = floorDiv(y.b - x.b, x.k - y.k);
			}
			return x.p >= y.p;
		}

		private boolean add(Line y) {
			Line v = root;
			while (true) {
				int cmp = v.compareTo(y);
				if (cmp == 0) {
					return false;
				}
				if (cmp > 0) {
					if (v.l == null) {
						v.l = y;
						break;
					} else {
						v = v.l;
					}
				} else {
					if (v.r == null) {
						v.r = y;
						break;
					} else {
						v = v.r;
					}
				}
			}
			y.up = v;
			splay(y);
			return true;
		}

		static private Line first(Line v) {
			while (v.l != null) {
				v = v.l;
			}
			return v;
		}

		static private Line last(Line v) {
			while (v.r != null) {
				v = v.r;
			}
			return v;
		}

		public void add(long k, long b) {
			// System.err.println("add " + k + " " + b);
			Line tmp = new Line(k, b);
			if (!add(tmp)) {
				return;
			}
			root = tmp;

			Line z = root.r;

			while (true) {
				z.up = null;

				splay(z = first(z));

				if (isect(root, z)) {
					z = z.r;
				} else {
					break;
				}
			}

			root.r = z;
			z.up = root;

			if (root.l == null) {
				return;
			}

			root.l.up = null;

			Line x = last(root.l);
			splay(x);
			if (isect(x, root)) {
				z.up = null;
				root = z;
				isect(x, root);
			}

			while (x.l != null) {
				z = x;
				splay(x = last(x.l));
				if (x.p >= z.p) {
					isect(x, root);
					x.r = null;
				} else {
					break;
				}
			}

			root.l = x;
			x.up = root;
		}

		long get(long x) {
			Line v = root;
			Line ret = null;
			Line newRoot = null;
			while (v != null) {
				newRoot = v;
				if (v.p >= x) {
					ret = v;
					v = v.l;
				} else {
					v = v.r;
				}
			}
			splay(newRoot);
			root = newRoot;
			return ret.k * x + ret.b;
		}

		void debug() {
			dfs(root);
		}

		void dfs(Line v) {
			if (v.l != null) {
				System.out.printf("%d -> %d;\n", v.k, v.l.k);
				dfs(v.l);
			}
			if (v.r != null) {
				System.out.printf("%d -> %d;\n", v.k, v.r.k);
				dfs(v.r);
			}
		}

	}

	static final int C = 3;
	static final int QRY_CNT = 5;
	static final int TST_CNT = 20;

	static final Random rng = new Random(1);

	static int rnd(int l, int r) { // [l; r]
		return l + rng.nextInt(r - l + 1);
	}

	void test() {
		CHOnline ch = new CHOnline();
		int[] ks = new int[QRY_CNT];
		int[] bs = new int[QRY_CNT];
		for (int i = 0; i < QRY_CNT; i++) {
			// System.err.println(i);
			ks[i] = rnd(-C, C);
			bs[i] = rnd(-C, C);
			ch.add(ks[i], bs[i]);

			for (int x = -2 * C * C; x <= 2 * C * C; x++) {
				long best = Long.MIN_VALUE;
				for (int j = 0; j <= i; j++) {
					best = Math.max(best, ks[j] * x + bs[j]);
				}
				if (best != ch.get(x)) {
					System.err
							.println(Arrays.toString(Arrays.copyOf(ks, i + 1)));
					System.err
							.println(Arrays.toString(Arrays.copyOf(bs, i + 1)));
					System.err.println("querying " + x);
					System.err.println("actual is " + best);
					System.err.println("we say " + ch.get(x));
					throw new AssertionError();
				}
			}
		}
	}

	void solve() throws IOException {
		// CHOnline ch = new CHOnline();
		// ch.add(-2, 2);
		// ch.add(0, 3);
		// ch.add(1, 0);
		// ch.add(0, -2);
		// System.err.println(ch.get(0));

		
		  /*for (int i = 0; i < TST_CNT; i++) {
			  test();
		  }*/ // System.err.println("test " +test(); }
		 

		REAL_SOLVE();

	}

	void REAL_SOLVE() throws IOException {
		int n = nextInt();
		// int n = 1_000_000;
		Triple[] a = new Triple[n];
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			int y = nextInt();
			long z = nextLong();
			// int x = i + 1;
			// int y = n - i;
			// double rt = Math.sqrt(i + 1);
			// long irt = (long) rt;
			// long z;
			// if (irt * irt == i + 1) {
			// z = irt * 1000;
			// if (i != 0) {
			// z--;
			// }
			// } else {
			// z = (long) (rt * 1000);
			// }
			a[i] = new Triple(x, y, z);
		}

		Arrays.sort(a);

		long ans = 0;

		CHOnline ch = new CHOnline();
		ch.add(0, 0);
		for (Triple t : a) {
			// for (int i = 0; i < a.length; i++) {
			// Triple t = a[i];

			// if (i == 500) {
			// ch.debug();
			// }
			int x = t.x;
			int y = t.y;
			long z = t.z;
			long f = ch.get(y);
			f += (long) x * y - z;
			ch.add(-x, f);
			ans = Math.max(ans, f);
		}

		out.println(ans);
	}

	static class Triple implements Comparable<Triple> {
		int x, y;
		long z;

		public Triple(int x, int y, long z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}

		@Override
		public int compareTo(Triple o) {
			if (x != o.x) {
				return x < o.x ? -1 : 1;
			}
			if (y != o.y) {
				return y < o.y ? -1 : 1;
			}
			return Long.compare(z, o.z);
		}
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		// test();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new ConvexHullOnline().inp();
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