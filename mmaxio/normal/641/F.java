import java.io.*;
import java.util.*;

public class F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static class BitsetLong {

		static final int LOG = 6;
		static final int SIZE = 1 << LOG;
		static final int MASK = SIZE - 1;

		private long[] data;

		public BitsetLong(int n) {
			data = new long[(n >> LOG) + 2];
		}

		void set(int i) {
			data[i >> LOG] |= 1L << (i & MASK);
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

			if (rem == 0) {
				return data[idx];
			}

			long head = data[idx] >>> rem;
			long tail = data[idx + 1] & ((1L << rem) - 1);

			return head | (tail << (SIZE - rem));
		}
	}

	static class TwoSAT {

		int n, m;
		boolean[][] g;
		int[] v1, v2;

		BitsetLong[] gg;

		public TwoSAT(int n, int m, boolean[][] g, int[] v1, int[] v2) {
			this.n = n;
			this.m = m;
			this.g = g;
			this.v1 = v1;
			this.v2 = v2;

			gg = new BitsetLong[2 * n];
			for (int i = 0; i < 2 * n; i++) {
				gg[i] = new BitsetLong(2 * n);
				gg[i].set(i);
				for (int j = 0; j < 2 * n; j++) {
					if (g[i][j]) {
						gg[i].set(j);
					}
				}
			}
			
			int bs = gg[0].data.length;
			
			for (int k = 0; k < 2 * n; k++)
				for (int i = 0; i < 2 * n; i++) {
					
					if (gg[i].get(k) == 1) {
						for (int j = 0; j < bs; j++) {
							gg[i].data[j] |= gg[k].data[j];
						}
					}
				}
			

		}

		void dfs(int v, boolean[] vis, List<Integer> order) {
			vis[v] = true;
			for (int i = 0; i < 2 * n; i++) {
				if (g[v][i] && !vis[i]) {
					dfs(i, vis, order);
				}
			}
			order.add(v);
		}

		int[] color;
		int cnt = 0;

		void dfs2(int v, int col) {
			color[v] = col;
			for (int i = 0; i < 2 * n; i++) {
				if (color[i] == 0 && g[i][v]) {
					dfs2(i, col);
				}
			}
		}

		void solve() {
			List<Integer> order = new ArrayList<>(2 * n);
			boolean[] vis = new boolean[2 * n];
			for (int i = 0; i < 2 * n; i++) {
				if (!vis[i]) {
					dfs(i, vis, order);
				}
			}
			Collections.reverse(order);

			color = new int[2 * n];
			for (int v : order) {
				if (color[v] == 0) {
					cnt++;
					dfs2(v, cnt);
				}
			}
		}

		int[] getSolution() {
			int[] ret = new int[n];
			for (int i = 0; i < n; i++) {
				if (color[2 * i] == color[2 * i + 1]) {
					return null;
				}
				ret[i] = color[2 * i] > color[2 * i + 1] ? 1 : 0;
			}
			return ret;
		}

	}

	TwoSAT next2SAT(int n, int m) throws IOException {
		boolean[][] g = new boolean[2 * n][2 * n];

		int[] v1 = new int[m];
		int[] v2 = new int[m];

		for (int i = 0; i < m; i++) {
			v1[i] = nextInt();
			v2[i] = nextInt();
			
			if (v1[i] > 0) {
				v1[i] = 2 * (v1[i] - 1);
			} else {
				v1[i] = 2 * (-v1[i] - 1) + 1;
			}
			if (v2[i] > 0) {
				v2[i] = 2 * (v2[i] - 1);
			} else {
				v2[i] = 2 * (-v2[i] - 1) + 1;
			}

			g[v1[i] ^ 1][v2[i]] = true;
			g[v2[i] ^ 1][v1[i]] = true;
		}

		return new TwoSAT(n, m, g, v1, v2);
	}
	
	static final long EVEN_BITS = 0x5555555555555555L;
	static final long ODD_BITS = 0xAAAAAAAAAAAAAAAAL;
	
	boolean isBad(long mask) {
		return ((mask & EVEN_BITS) & ((mask & ODD_BITS) >>> 1)) != 0;
	}
	
	boolean check(TwoSAT wrong, TwoSAT right) {

		BitsetLong[] arr = right.gg;
		
		int bs = arr[0].data.length;
		
		outer: for (int i = 0; i < wrong.m; i++) {
			int p = wrong.v1[i] ^ 1;
			int q = wrong.v2[i] ^ 1;
			
			String tmp = "";
			
			for (int j = 0; j < bs; j++) {
				long here = arr[p].data[j] | arr[q].data[j];
				
				if (p == 1274 && q == 1275 && j == 19) {
					tmp += arr[p].data[j] + " " + arr[q].data[j] + " " + here;
				}
				
				if (isBad(here)) {
					continue outer;
				}
			}
			
			int newN = right.n;
			int newM = right.m + 2;
			
			boolean[][] newG = new boolean[newN * 2][newN * 2];
			for (int v = 0; v < newN * 2; v++)
				for (int u = 0; u < newN * 2; u++)
					newG[v][u] = right.g[v][u];
			
			newG[p ^ 1][p] = true;
			newG[q ^ 1][q] = true;
		
			TwoSAT twosat = new TwoSAT(newN, newM, newG, right.v1, right.v2);
			twosat.solve();
			int[] res = twosat.getSolution();
			if (res == null) {
				throw new AssertionError(tmp + " " + p + " " + q);
			}
			
			for (int x : res) {
				out.print(x + " ");
			}
			out.println();
			
			return true;
		}
		return false;
		
	}

	void solve() throws IOException {
		
		int n = nextInt();
		int m1 = nextInt();
		int m2 = nextInt();
		TwoSAT a = next2SAT(n, m1);
		TwoSAT b = next2SAT(n, m2);

		a.solve();
		b.solve();

		int[] sa = a.getSolution();
		int[] sb = b.getSolution();

		if (sa == null && sb == null) {
			out.println("SIMILAR");
			return;
		}
		if (sa == null && sb != null) {
			for (int x : sb) {
				out.print(x + " ");
			}
			out.println();
			return;
		}

		if (sa != null && sb == null) {
			for (int x : sa) {
				out.print(x + " ");
			}
			out.println();
			return;
		}
		
		if (check(a, b)) {
			return;
		}
		if (check(b, a)) {
			return;
		}
		
		out.println("SIMILAR");

	}

	F() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
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