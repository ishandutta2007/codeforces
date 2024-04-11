import java.io.*;
import java.util.*;

public class D_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	ArrayList<Integer> lucky;

	void gen(int cur, int len) {
		lucky.add(cur);
		if (len < 9) {
			gen(cur * 10 + 4, len + 1);
			gen(cur * 10 + 7, len + 1);
		}
	}

	int indLucky;

	void addSwap(int a, int b) {
		if (a != b) {
			from.add(a + 1);
			to.add(b + 1);
		}
	}

	ArrayList<Integer> from;
	ArrayList<Integer> to;

	void solve() throws IOException {
		lucky = new ArrayList<Integer>();
		gen(4, 1);
		gen(7, 1);
		Collections.sort(lucky);

		int n = nextInt();

		int[] a = new int[n];

		indLucky = -1;

		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			if (Collections.binarySearch(lucky, a[i]) >= 0)
				indLucky = i;
		}

		boolean sorted = true;
		for (int i = 0; i < n - 1; i++)
			if (a[i] > a[i + 1]) {
				sorted = false;
				break;
			}

		if (sorted) {
			out.println(0);
			return;
		}

		if (indLucky == -1) {
			out.println(-1);
			return;
		}

		TreeMap<Integer, Integer> where = new TreeMap<Integer, Integer>();

		int[] res = a.clone();

		Arrays.sort(res);

		int[] perm = new int[n];

		for (int i = 0; i < n; i++)
			if (i == 0 || res[i] != res[i - 1])
				where.put(res[i], i);

		for (int i = 0; i < res.length; i++) {
			int x = a[i];

			perm[i] = where.get(x);
			where.put(x, perm[i] + 1);
		}

		 //System.err.println(Arrays.toString(perm));

		boolean[] use = new boolean[n];

		from = new ArrayList<Integer>();
		to = new ArrayList<Integer>();

		ArrayList<Integer> cycle = new ArrayList<Integer>();

		int ii = perm[indLucky];
		cycle.clear();
		for (int cur = ii; !use[cur]; cur = perm[cur]) {
			use[cur] = true;
			cycle.add(cur);
		}

		if (cycle.size() != 1) {

			for (int k = cycle.size() - 2; k >= 0; k--)
				addSwap(cycle.get(k), cycle.get(k + 1));
			
			indLucky = perm[indLucky];

		}

		for (int i = 0; i < n; i++)
			if (!use[i]) {
				cycle.clear();
				for (int cur = i; !use[cur]; cur = perm[cur]) {
					use[cur] = true;
					cycle.add(cur);
				}

				if (cycle.size() == 1)
					continue;

				addSwap(cycle.get(cycle.size() - 1), indLucky);
				for (int k = cycle.size() - 2; k >= 0; k--)
					addSwap(cycle.get(k), cycle.get(k + 1));
				addSwap(cycle.get(0), indLucky);
			}

		out.println(from.size());
		for (int i = 0; i < from.size(); i++)
			out.println(from.get(i) + " " + to.get(i));

	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D_new().inp();
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