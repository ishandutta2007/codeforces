	import java.io.*;
	import java.util.*;
	
	public class E {
	
		BufferedReader br;
		PrintWriter out;
		StringTokenizer st;
		boolean eof;
	
		static class JustMaxNode {
			int l, r;
			JustMaxNode left, right;
			int max;
	
			public JustMaxNode(int l, int r) {
				this.l = l;
				this.r = r;
				this.max = -1;
				if (r - l > 1) {
					int mid = (l + r) >> 1;
					left = new JustMaxNode(l, mid);
					right = new JustMaxNode(mid, r);
				}
			}
	
			int get(int ql, int qr) {
				if (l >= qr || ql >= r) {
					return -1;
				}
				if (ql <= l && r <= qr) {
					return max;
				}
				return Math.max(left.get(ql, qr), right.get(ql, qr));
			}
	
			void set(int pos, int val) {
				if (l == pos && pos + 1 == r) {
					max = val;
					return;
				}
				(pos < left.r ? left : right).set(pos, val);
				max = Math.max(left.max, right.max);
			}
		}
	
		void solve() throws IOException {
			int n = nextInt();
			int[] xs = new int[n];
			int[] lens = new int[n];
			for (int i = 0; i < n; i++) {
				xs[i] = nextInt();
				lens[i] = nextInt();
			}
	
			int[] justPos = new int[n];
			for (int i = 0; i < n; i++) {
				int pos = Arrays.binarySearch(xs, xs[i] + lens[i]);
				if (pos < 0) {
					pos = -pos - 2;
				}
				justPos[i] = pos;
			}
			JustMaxNode tmp = new JustMaxNode(0, n);
			int[] allX = new int[n];
			int[] allPos = new int[n + 1];
	
			for (int i = n - 1; i >= 0; i--) {
				allX[i] = xs[i] + lens[i];
				if (justPos[i] > i) {
					allX[i] = Math.max(allX[i], tmp.get(i + 1, justPos[i] + 1));
				}
				allPos[i] = Arrays.binarySearch(xs, allX[i]);
				if (allPos[i] >= 0) {
					throw new AssertionError();
				}
				allPos[i] = -allPos[i] - 2;
				tmp.set(i, allX[i]);
			}
			allPos[n] = n;
	
			int[][] nextPos = new int[LOG][n + 1];
			int[][] nextCost = new int[LOG][n + 1];
			for (int i = 0; i < n; i++) {
				int pos = allPos[i] + 1;
				nextPos[0][i] = pos;
				if (pos != n) {
					nextCost[0][i] = xs[pos] - allX[i];
				}
			}
			nextPos[0][n] = n;
			nextCost[0][n] = 0;
	
			for (int i = 1; i < LOG; i++) {
				for (int j = 0; j <= n; j++) {
					nextPos[i][j] = nextPos[i - 1][nextPos[i - 1][j]];
					nextCost[i][j] = nextCost[i - 1][j]
							+ nextCost[i - 1][nextPos[i - 1][j]];
				}
			}
	
			int q = nextInt();
			while (q-- > 0) {
				int from = nextInt() - 1;
				int to = nextInt() - 1;
				if (allPos[from] >= to) {
					out.println(0);
					continue;
				}
				int outp = 0;
				for (int i = LOG - 1; i >= 0; i--) {
					if (allPos[nextPos[i][from]] < to) {
						outp += nextCost[i][from];
						from = nextPos[i][from];
					}
				}
				if (allPos[from] >= to) {
					throw new AssertionError();
				}
				if (allPos[nextPos[0][from]] < to) {
					throw new AssertionError();
				}
				outp += nextCost[0][from];
				out.println(outp);
			}
	
		}
	
		static final int LOG = 18;
	
		E() throws IOException {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			out.close();
		}
	
		public static void main(String[] args) throws IOException {
			new E();
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