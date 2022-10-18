import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	class Query implements Comparable<Query> {
		int l, r, id;

		public Query(int l, int r, int id) {
			this.l = l;
			this.r = r;
			this.id = id;
		}

		@Override
		public int compareTo(Query o) {
			if (r != o.r)
				return Integer.compare(r, o.r);
			return Integer.compare(id, o.id);
		}

	}

	class Fenwick {
		private int[] a;
		int sz;

		Fenwick(int sz) {
			a = new int[sz];
			this.sz = sz;
		}

		void add(int i, int delta) {
			for (; i < sz; i |= i + 1)
				a[i] += delta;
		}

		int get(int l, int r) {
			return get(r) - get(l - 1);
		}

		int get(int i) {
			int res = 0;
			for (; i >= 0; i = (i & (i + 1)) - 1)
				res += a[i];
			return res;
		}
	}

	<K> ArrayList<Integer> lazyGet(HashMap<K, ArrayList<Integer>> map, K key) {
		ArrayList<Integer> res = map.get(key);
		if (res == null) {
			res = new ArrayList<Integer>();
			map.put(key, res);
		}
		return res;
	}

	void updateFen(Fenwick f, ArrayList<Integer> al, int x, int mult) {
		if (al.size() < x)
			return;

		if (al.size() > x)
			f.add(al.get(al.size() - x - 1), -mult);

		f.add(al.get(al.size() - x), mult);
	}

	void solve() throws IOException {
		int n = nextInt();
		int nQ = nextInt();

		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();

		Query[] qq = new Query[nQ];
		for (int i = 0; i < nQ; i++)
			qq[i] = new Query(nextInt() - 1, nextInt() - 1, i);

		Fenwick f = new Fenwick(n);

		int[] ans = new int[nQ];

		Arrays.sort(qq);
		HashMap<Integer, ArrayList<Integer>> pos = new HashMap<Integer, ArrayList<Integer>>();
		for (int ind = 0, curQ = 0; ind < n; ind++) {
			int x = a[ind];
			ArrayList<Integer> curPos = lazyGet(pos, x);
			updateFen(f, curPos, x, -1);
			curPos.add(ind);
			updateFen(f, curPos, x, 1);
			for (; curQ < nQ && qq[curQ].r == ind; curQ++) {
				ans[qq[curQ].id] = f.get(qq[curQ].l, ind);

			}
		}

		for (int i = 0; i < nQ; i++)
			out.println(ans[i]);

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