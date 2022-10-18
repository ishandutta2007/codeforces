import java.io.*;
import java.util.*;

public class YandexAlgo2011_Round2_D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int K;

	class Query implements Comparable<Query>{
		int l, r;
		int ind;
		int lBlock;

		public Query(int l, int r, int ind) {
			this.l = l;
			this.r = r;
			this.ind = ind;
			lBlock = l / K;
		}

		@Override
		public int compareTo(Query o) {
			if (ind == o.ind)
				return 0;
			if (lBlock != o.lBlock)
				return lBlock < o.lBlock ? -1 : 1;
			if (r != o.r)
				return r < o.r ? -1 : 1;
			return 0;
		}
	}
	
	int[] memo;
	
	long addNum(int x) {
		int prev = memo[x];
		memo[x] = prev + 1;
		return (long)b[x] * ((prev << 1) + 1);
	}
	
	long removeNum(int x) {
		int prev = memo[x];
		memo[x] = prev - 1;
		return (long)b[x] * ((prev << 1) - 1);
	}
	
	int[] b;

	void solve() throws IOException {

		int n = nextInt();
		int q = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		
		b = a.clone();
		Arrays.sort(b);
		int sz = 1;
		for (int i = 1; i < n; i++)
			if (b[i] != b[sz - 1])
				b[sz++] = b[i];
		
		for (int i = 0; i < n; i++)
			a[i] = Arrays.binarySearch(b, 0, sz, a[i]);

		K = (int) Math.sqrt(n);
		Query[] qq = new Query[q];
		for (int i = 0; i < q; i++)
			qq[i] = new Query(nextInt() - 1, nextInt(), i);
		
		Arrays.sort(qq);
		
		long[] ans = new long[q];
		
		int l = 0;
		int r = 0;
		//[l, r)
		memo = new int[sz];
		long val = 0;
		for (int i = 0; i < q; i++) {
			Query cur = qq[i];
			while (l > cur.l)
				val += addNum(a[--l]);
			while (r < cur.r)
				val += addNum(a[r++]);
			while (l < cur.l)
				val -= removeNum(a[l++]);
			while (r > cur.r)
				val -= removeNum(a[--r]);
			ans[cur.ind] = val;
		}
		
		for (int i = 0; i < q; i++)
			//out.print(ans[i] + " ");
			out.println(ans[i]);
		//out.println();
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new YandexAlgo2011_Round2_D().inp();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	String nextString() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken("\n");
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