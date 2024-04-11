import java.io.*;
import java.util.*;

public class C {

	void submit() {
		int n = nextInt();
		int m = nextInt();
		int[][] a = new int[n][];
		for (int i = 0; i < n; i++) {
			int len = nextInt();
			a[i] = new int[len];
			for (int j = 0; j < len; j++) {
				a[i][j] = nextInt() - 1;
			}
		}
		
		TwoSAT sat = new TwoSAT(m);
		
		for (int i = 0; i < n - 1; i++) {
			int j = 0;
			while (j < a[i].length && j < a[i + 1].length && a[i][j] == a[i + 1][j]) {
				j++;
			}
			boolean endI = j == a[i].length;
			boolean endI1 = j == a[i + 1].length;
			if (endI) {
				continue;
			}
			if (endI1) {
				out.println("No");
				return;
			}
			int x = a[i][j];
			int y = a[i + 1][j];
			if (x < y) {
				sat.add(2 * x, 2 * y + 1);
			} else {
				sat.add(2 * x, 2 * x);
				sat.add(2 * y + 1, 2 * y + 1);
			}
		}
		
		boolean[] ans = sat.solve();
		if (ans == null) {
			out.println("No");
			return;
		}
		
		out.println("Yes");
		int cnt = 0;
		for (boolean b : ans) {
			cnt += b ? 1 : 0;
		}
		out.println(cnt);
		for (int i = 0; i < m; i++) {
			if (ans[i]) {
				out.print((i + 1) + " ");
			}
		}
		out.println();
	}
	
	static class TwoSAT {
		int n;

		List<Integer>[] g;
		List<Integer>[] gRev;

		/**
		 * 
		 * @param n - numbers of variables
		 */
		public TwoSAT(int n) {
			this.n = n;
			g = new List[2 * n];
			gRev = new List[2 * n];
			for (int i = 0; i < 2 * n; i++) {
				g[i] = new ArrayList<>();
				gRev[i] = new ArrayList<>();
			}
			order = new int[2 * n];
			color = new int[2 * n];
			ptr = 2 * n;
		}

		/**
		 * 2x - x-th variable
		 * 2x + 1 - negation of x-th variable
		 */
		void add(int v, int u) {
			g[v ^ 1].add(u);
			gRev[u].add(v ^ 1);
			g[u ^ 1].add(v);
			gRev[v].add(u ^ 1);
		}

		private int[] order;
		private int ptr;
		private int[] color;

		private void dfs1(int v) {
			color[v] = -1;
			for (int u : g[v]) {
				if (color[u] == 0) {
					dfs1(u);
				}
			}
			order[--ptr] = v;
		}

		private void dfs2(int v) {
			color[v] = ptr;
			for (int u : gRev[v]) {
				if (color[u] == -1) {
					dfs2(u);
				}
			}
		}

		boolean[] solve() {
			for (int i = 0; i < 2 * n; i++) {
				if (color[i] == 0) {
					dfs1(i);
				}
			}
			ptr = 0;
			for (int v : order) {
				if (color[v] == -1) {
					dfs2(v);
					ptr++;
				}
			}
			
			boolean[] ret = new boolean[n];
			
			for (int i = 0; i < 2 * n; i += 2) {
				if (color[i] == color[i ^ 1]) {
					return null;
				}
				ret[i >> 1] = color[i] > color[i ^ 1];
			}

			return ret;
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
		//stress();
		//test();
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