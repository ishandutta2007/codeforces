import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	class Query implements Comparable<Query>{
		int from;
		int to;
		int maxChange;
		int ind;
		
		public Query(int from, int to, int maxChange, int ind) {
			super();
			this.from = from;
			this.to = to;
			this.maxChange = maxChange;
			this.ind = ind;
		}

		@Override
		public int compareTo(Query o) {
			if (maxChange != o.maxChange)
				return maxChange < o.maxChange ? -1 : 1;
			if (ind != o.ind)
				return ind < o.ind ? -1 : 1;
			return 0;
		}
		
	}
	
	int n;
	
	int[][] update(int[][] cur, int[][] best) {
		int[][] res = new int[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				res[i][j] = Integer.MAX_VALUE;
				for (int k = 0; k < n; k++)
					res[i][j] = Math.min(res[i][j], cur[i][k] + best[k][j]);
			}
		return res;
	}

	void solve() throws IOException {
		n = nextInt();
		int m = nextInt();
		int qq = nextInt();
		
		int[][][] d = new int[m][n][n];
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					d[i][j][k] = nextInt();
			for (int j = 0; j < n; j++)
				for (int k1 = 0; k1 < n; k1++)
					for (int k2 = 0; k2 < n; k2++) {
						d[i][k1][k2] = Math.min(d[i][k1][k2], d[i][k1][j] + d[i][j][k2]);
					}
		}
		
		Query[] qs = new Query[qq];
		
		for (int i = 0; i < qq; i++) {
			int from = nextInt() - 1;
			int to = nextInt() - 1;
			int maxChange = Math.min(nextInt(), 2 * n);
			qs[i] = new Query(from, to, maxChange, i);
		}
		
		Arrays.sort(qs);
		int[][] best = new int[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				best[i][j] = Integer.MAX_VALUE;
				for (int k = 0; k < m; k++)
					best[i][j] = Math.min(best[i][j], d[k][i][j]);
			}
		
		int[][] cur = new int[n][];
		for (int i = 0; i < n; i++)
			cur[i] = best[i].clone();
		
		int[] ans = new int[qq];
		
		int prevChange = 0;
		for (Query q : qs) {
			while (prevChange < q.maxChange) {
				cur = update(cur, best);
				prevChange++;
			}
			ans[q.ind] = cur[q.from][q.to];
		}
		
		for (int x : ans)
			out.println(x);
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B().inp();
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