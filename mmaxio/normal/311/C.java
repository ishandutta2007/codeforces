import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	//static final long INF = Long.MAX_VALUE / 3;

	class Treasure implements Comparable<Treasure> {
		long cell;
		int money;
		int id;

		public Treasure(long cell, int money, int id) {
			this.cell = cell;
			this.money = money;
			this.id = id;
		}

		@Override
		public int compareTo(Treasure o) {
			if (money != o.money) {
				return money > o.money ? -1 : 1;
			}
			return Integer.compare(id, o.id);
		}

	}

	void updateLow(final long[] low, long x) {
		int k = low.length;

		Integer[] rem = new Integer[k];
		for (int i = 0; i < k; i++)
			rem[i] = i;
		Arrays.sort(rem, new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				if (low[o1] == -1 && low[o2] == -1)
					return 0;
				if (low[o1] == -1)
					return 1;
				if (low[o2] == -1)
					return -1;
				return Long.compare(low[o1], low[o2]);
			}

		});

		int xRem = (int) (x % k);

		for (int i = 0; i < k; i++) {
			int v = rem[i];
			if (low[v] == -1)
				continue;
			while (true) {
				int next = v + xRem;
				if (next >= k)
					next -= k;
				if (low[next] != -1 && low[next] <= low[v] + x)
					break;
				low[next] = low[v] + x;
				v = next;
			}
		}
	}

	void solve() throws IOException {
		long h = nextLong();
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();

		long[] low = new long[k];
		Arrays.fill(low, -1);
		low[0] = 0;
		
//		System.err.println(Arrays.toString(low));

		Treasure[] all = new Treasure[n];

		TreeSet<Treasure> reach = new TreeSet<>();
		boolean[] added = new boolean[n];

		for (int i = 0; i < n; i++) {
			all[i] = new Treasure(nextLong() - 1, nextInt(), i);
			if (canReach(all[i].cell, low)) {
				reach.add(all[i]);
				added[i] = true;
			}
		}

		for (int curQ = 0; curQ < m; curQ++) {
			int type = nextInt();
			if (type == 1) {
				long x = nextLong();
				updateLow(low, x);
				
//				System.err.println(Arrays.toString(low));

				for (int i = 0; i < n; i++) {
					if (!added[i] && canReach(all[i].cell, low)) {
						reach.add(all[i]);
						added[i] = true;
					}
				}

			} else if (type == 2) {
				int i = nextInt() - 1;
				int delta = nextInt();

				Treasure cur = all[i];
				if (added[i]) {
					reach.remove(cur);
				}
				cur.money -= delta;
				if (added[i]) {
					reach.add(cur);
				}
			} else if (type == 3) {
				Treasure ret = reach.pollFirst();
				if (ret == null) {
					out.println(0);
				} else {
					out.println(ret.money);
				}
			} else {
				throw new AssertionError();
			}
		}

	}

	boolean canReach(long cell, long[] low) {
		int k = low.length;
		int rem = (int) (cell % k);
		return low[rem] != -1 && cell >= low[rem];
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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