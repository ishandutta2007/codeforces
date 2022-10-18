import java.io.*;
import java.util.*;

public class G {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;
	int time;

	int[] from, to;

	void dfs(int v, int p) {
		from[v] = time++;
		for (int u : g[v]) {
			if (u != p) {
				dfs(u, v);
			}
		}
		to[v] = time;
	}

	static class BitsetLong {

		static final int LOG = 6;
		static final int SIZE = 1 << LOG;
		static final int MASK = SIZE - 1;

		private long[] data;
		private int n;

		public BitsetLong(int n) {
			this.n = n;
			data = new long[(n + MASK) >> LOG];
		}

		void set(int i) {
			data[i >> LOG] |= 1L << (i & MASK);
		}

		void unset(int i) {
			data[i >> LOG] &= ~(1L << (i & MASK));
		}

		void flip(int i) {
			data[i >> LOG] ^= 1L << (i & MASK);
		}

		int get(int i) {
			return (int) ((data[i >> LOG] >>> (i & MASK)) & 1);
		}

		/**
		 * pads with zeroes if end of word is outside of range
		 */
		long getWord(int i) {
			int rem = i & MASK;
			int idx = i >> LOG;

			long ret;

			if (rem == 0) {
				ret = data[idx];
			} else {

				long head = data[idx] >>> rem;
				long tail = (idx == data.length - 1) ? 0 : (data[idx + 1]
						& ((1L << rem) - 1));

				ret = head | (tail << (SIZE - rem));
			}
			if (i + SIZE > n) {
				long rest = data[0] & ((1L << (i + SIZE - n)) - 1);
				ret |= rest << (n - i);
			}

			return ret;
		}
	}

	static class Node {
		static int m;
		int l, r;
		Node left, right;

		int shift;

		BitsetLong data;

		void combineData() {
			for (int i = 0; i < data.data.length; i++) {
				data.data[i] = left.data.getWord(Math.floorMod(i
						* BitsetLong.SIZE - left.shift, m))
						| right.data.getWord(Math.floorMod(i * BitsetLong.SIZE
								- right.shift, m));
			}
		}

		public Node(int l, int r, int[] a) {
			this.l = l;
			this.r = r;

			data = new BitsetLong(m);

			if (r - l == 1) {
				data.set(a[l]);
			} else {
				int mid = (l + r) >> 1;
				left = new Node(l, mid, a);
				right = new Node(mid, r, a);
				combineData();
			}
		}

		void add(int ql, int qr, int delta) {
			if (l >= qr || ql >= r) {
				return;
			}
			if (ql <= l && r <= qr) {
				shift += delta;
				if (shift >= m) {
					shift -= m;
				}
				return;
			}

			left.shift += shift;
			if (left.shift >= m) {
				left.shift -= m;
			}

			right.shift += shift;
			if (right.shift >= m) {
				right.shift -= m;
			}
			
			shift = 0;

			left.add(ql, qr, delta);
			right.add(ql, qr, delta);
			combineData();
		}

		void get(int ql, int qr, BitsetLong bs) {
			if (l >= qr || ql >= r) {
				return;
			}
			if (ql <= l && r <= qr) {
//				System.err.println(l + " " + r + " " + data.data[0]);
				for (int i = 0; i < data.data.length; i++) {
					bs.data[i] |= data.getWord(Math.floorMod(i
							* BitsetLong.SIZE - shift, m));
				}
				return;
			}

			left.shift += shift;
			if (left.shift >= m) {
				left.shift -= m;
			}

			right.shift += shift;
			if (right.shift >= m) {
				right.shift -= m;
			}
			
			shift = 0;

			left.get(ql, qr, bs);
			right.get(ql, qr, bs);
			combineData();
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt() % m;
		}

		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}

		for (int i = 0; i < n - 1; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			g[v].add(u);
			g[u].add(v);
		}

		from = new int[n];
		to = new int[n];
		dfs(0, -1);

		int[] actualA = new int[n];
		for (int i = 0; i < n; i++) {
			actualA[from[i]] = a[i];
		}

		Node.m = m;

		BitsetLong primes = new BitsetLong(m);
		
		boolean[] isPrime = new boolean[m];
		Arrays.fill(isPrime, true);
		for (int i = 2; i < m; i++) {
			if (isPrime[i]) {
				primes.set(i);
				for (int j = i * i; j < m; j += i) {
					isPrime[j] = false;
				}
			}
		}
		
//		System.err.println(Arrays.toString(actualA));
		
//		System.err.println(Arrays.toString(from));
//		System.err.println(Arrays.toString(to));

		Node root = new Node(0, n, actualA);
		int q = nextInt();
		while (q-- > 0) {
			int type = nextInt();
			int v = nextInt() - 1;
			if (type == 1) {
				int x = nextInt();
				root.add(from[v], to[v], x % m);
			} else {
				BitsetLong ret = new BitsetLong(m);
				root.get(from[v], to[v], ret);
				
				int outp = 0;
				
				for (int i = 0; i < primes.data.length; i++) {
					outp += Long.bitCount(primes.data[i] & ret.data[i]);
				}
				
				out.println(outp);
			}
		}
		
	}

	G() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new G();
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