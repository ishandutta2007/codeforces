import java.io.*;
import java.util.*;

public class E_fast {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	class MultiTreeSet {
		private TreeMap<Integer, Integer> map;

		public MultiTreeSet() {
			map = new TreeMap<Integer, Integer>();
		}

		void add(int x) {
			Integer prev = map.get(x);
			if (prev == null)
				prev = 0;
			map.put(x, prev + 1);
		}

		void remove(int x) {
			Integer prev = map.get(x);
			if (prev == 1)
				map.remove(x);
			else
				map.put(x, prev - 1);
		}

		int first() {
			return map.firstKey();
		}

		int last() {
			return map.lastKey();
		}

	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();

		int maxLen = 0;
		ArrayList<Integer> ansStart = new ArrayList<Integer>();

		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();

		MultiTreeSet cur = new MultiTreeSet();
		cur.add(a[0]);
		for (int l = 0, r = 1; true;) {
			if (cur.last() - cur.first() <= k) {
				if (r - l > maxLen) {
					maxLen = r - l;
					ansStart.clear();
				}
				if (r - l == maxLen)
					ansStart.add(l);
				if (r == n)
					break;
				cur.add(a[r++]);
			} else
				cur.remove(a[l++]);
		}

		out.println(maxLen + " " + ansStart.size());
		for (int i = 0; i < ansStart.size(); i++) {
			int st = ansStart.get(i) + 1;
			int en = st + maxLen - 1;
			out.println(st + " " + en);
		}

	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E_fast().inp();
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