import java.io.*;
import java.util.*;

public class D_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Bag implements Comparable<Bag> {
		int val;
		int id;

		public Bag(int val, int id) {
			this.val = val;
			this.id = id;
		}

		@Override
		public int compareTo(Bag o) {
			return -Integer.compare(val, o.val);
		}
	}

	static class Pile {
		int l, r, size;;

		public Pile(int l, int r, int size) {
			this.l = l;
			this.r = r;
			this.size = size;
		}
	}

	List<Integer> makePiles(int x) {
		List<Integer> ret = new ArrayList<>();
		int p2 = 1;
		while (x > p2) {
			ret.add(p2);
			x -= p2;
			p2 *= 2;
		}
		ret.add(x);
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int s = nextInt();

		Bag[] a = new Bag[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Bag(nextInt(), i);
		}

		Arrays.sort(a);
		s -= a[0].val;
		if (s < 0) {
			out.println(-1);
			return;
		}

		Pile[] can = new Pile[s + 1];

		can[0] = new Pile(-1, -1, -1);
		for (int i = 1; i < n;) {
			int val = a[i].val;
			int nextI = i;
			while (nextI < n && a[i].val == a[nextI].val) {
				nextI++;
			}

			List<Integer> p = makePiles(nextI - i);
			for (int j = 0; j < p.size(); j++) {
				int curSz = p.get(j);

				long longSize = (long) curSz * val;
				if (longSize <= s) {

					int size = (int) longSize;
					Pile pp = new Pile(i, i + p.get(j), size);
					for (int k = s; k >= size; k--) {
						if (can[k] == null && can[k - size] != null) {
							can[k] = pp;
						}
					}
				}

				i += p.get(j);
			}
		}

		if (can[s] == null) {
			out.println(-1);
			return;
		}

		boolean[] top = new boolean[n];
		for (int i = s; i > 0;) {
			Pile cur = can[i];
			for (int j = cur.l; j < cur.r; j++) {
				top[j] = true;
			}
			i -= cur.size;
		}

		int[] next = new int[n];
		Arrays.fill(next, -1);
		int prev = 0;
		for (int i = 1; i < n; i++) {
			if (!top[i]) {
				next[prev] = i;
				prev = i;
			}
		}

		int[] inv = new int[n];
		for (int i = 0; i < n; i++) {
			inv[a[i].id] = i;
		}

		for (int i = 0; i < n; i++) {
			int pos = inv[i];
			if (next[pos] == -1) {
				out.println(a[pos].val + " 0");
			} else {
				out.println(a[pos].val - a[next[pos]].val + " 1 "
						+ (a[next[pos]].id + 1));
			}
		}
	}

	D_new() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D_new();
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