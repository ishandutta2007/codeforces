import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Bridge implements Comparable<Bridge> {
		int id;
		long len;

		@Override
		public int compareTo(Bridge o) {
			if (len != o.len) {
				return len < o.len ? -1 : 1;
			}
			return Integer.compare(id, o.id);
		}

		public Bridge(int id, long len) {
			this.id = id;
			this.len = len;
		}
	}

	static class Query implements Comparable<Query> {
		long low, high;
		int id;

		@Override
		public int compareTo(Query o) {
			return Long.compare(high, o.high);
		}

		public Query(long low, long high, int id) {
			this.low = low;
			this.high = high;
			this.id = id;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		long[] l = new long[n];
		long[] r = new long[n];
		for (int i = 0; i < n; i++) {
			l[i] = nextLong();
			r[i] = nextLong();
		}
		Bridge[] a = new Bridge[m];
		for (int i = 0; i < m; i++) {
			long len = nextLong();
			a[i] = new Bridge(i, len);
		}
		Arrays.sort(a);

		Query[] qs = new Query[n - 1];
		for (int i = 0; i < n - 1; i++) {
			qs[i] = new Query(l[i + 1] - r[i], r[i + 1] - l[i], i);
		}

		Arrays.sort(qs);
		int[] ans = new int[n - 1];
		TreeSet<Bridge> set = new TreeSet<>();
		
		Bridge seeker = new Bridge(-1, 0);
		
		for (int i = 0, j = 0; i < n - 1; i++) {
			while (j < m && a[j].len <= qs[i].high) {
				set.add(a[j]);
				j++;
			}
			seeker.len = qs[i].low;
			Bridge tmp = set.higher(seeker);
			if (tmp == null) {
				out.println("No");
				return;
			}
			ans[qs[i].id] = tmp.id;
			set.remove(tmp);
		}
		out.println("Yes");
		for (int x : ans) {
			out.print((x + 1) + " ");
		}
		out.println();
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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