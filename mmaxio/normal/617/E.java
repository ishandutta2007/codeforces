import java.io.*;
import java.util.*;

public class cf340E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static class Query implements Comparable<Query>{
		int l, r;
		int lBlock;
		int id;
		
		@Override
		public int compareTo(Query arg0) {
			if (lBlock != arg0.lBlock) {
				return lBlock < arg0.lBlock ? -1 : 1;
			}
			return Integer.compare(r, arg0.r);
		}

		public Query(int l, int r, int lBlock, int id) {
			this.l = l;
			this.r = r;
			this.lBlock = lBlock;
			this.id = id;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		int[] a = new int[n + 1];
		for (int i = 0; i < n; i++) {
			a[i + 1] = a[i] ^ nextInt();
		}
		
		int blockSize = (int) Math.sqrt(n);
		
		Query[] qs = new Query[m];
		for (int i = 0; i < m; i++) {
			int l = nextInt() - 1;
			int r = nextInt();
			qs[i] = new Query(l, r, l / blockSize, i);
		}
		
		Arrays.sort(qs);
		
		int curL = 0;
		int curR = 1;
		long curAns = 0;
		
		int[] map = new int[1 << 20];
		
		map[a[0]]++;
		map[a[1]]++;
		
		if ((a[1] ^ a[0]) == k) {
			curAns++;
		}
		
		long[] outp = new long[m];
		for (Query q : qs) {
			int newL = q.l;
			int newR = q.r;
			while (curL > newL) {
				curL--;
				curAns += map[a[curL] ^ k];
				map[a[curL]]++;
			}
			while (curR < newR) {
				curR++;
				curAns += map[a[curR] ^ k];
				map[a[curR]]++;
			}
			while (curL < newL) {
				map[a[curL]]--;
				curAns -= map[a[curL] ^ k];
				curL++;
			}
			while (curR > newR) {
				map[a[curR]]--;
				curAns -= map[a[curR] ^ k];
				curR--;
			}
			outp[q.id] = curAns;
		}
		
		for (long x : outp) {
			out.println(x);
		}
	}

	cf340E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new cf340E();
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