import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] p, size;

	int get(int x) {
		return p[x] == x ? x : (p[x] = get(p[x]));
	}

	Random rng = new Random();

	void union(int v, int u) {
		if (rng.nextBoolean()) {
			p[v] = u;
			size[u] += size[v];
		} else {
			p[u] = v;
			size[v] += size[u];
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();

		List<Integer>[] g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}

		final int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}

		Integer[] order = new Integer[n];
		for (int i = 0; i < n; i++) {
			order[i] = i;
		}

		Arrays.sort(order, new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				return -Integer.compare(a[o1], a[o2]);
			}

		});

		boolean[] built = new boolean[n];

		long sum = 0;
		p = new int[n];
		size = new int[n];

		for (int v : order) {
			built[v] = true;
			p[v] = v;
			size[v] = 1;
			for (int i = 0; i < g[v].size(); i++) {
				int u = g[v].get(i);
				if (!built[u]) {
					continue;
				}
				// System.err.println(v + " " + u);
				u = get(u);
				int vv = get(v);
				if (u == vv) {
					continue;
				}

				sum += (long) size[vv] * size[u] * a[v];
//				System.err.println(size[vv] + " " + size[u]);
				union(u, vv);
			}
		}
		
//		System.err.println(sum);

		double ans = 2.0 * sum / n / (n - 1);
		out.println(ans);
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