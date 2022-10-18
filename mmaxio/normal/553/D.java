import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;

	static class City implements Comparable<City> {
		int id, good, total;

		@Override
		public int compareTo(City o) {
			long val1 = (long) good * o.total;
			long val2 = (long) o.good * total;
			if (val1 != val2) {
				return val1 < val2 ? -1 : 1;
			}
			return Integer.compare(id, o.id);
		}

		public City(int id, int good, int total) {
			this.id = id;
			this.good = good;
			this.total = total;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		List<Integer> bad = new ArrayList<>(n);
		boolean[] isBad = new boolean[n];
		for (int i = 0; i < k; i++) {
			int v = nextInt() - 1;
			isBad[v] = true;
			bad.add(v);
		}

		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}

		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}

		TreeSet<City> set = new TreeSet<>();
		City[] cities = new City[n];
		
		for (int i = 0; i < n; i++) {
			if (!isBad[i]) {

				int good = 0;
				int total = g[i].size();
				for (int v : g[i]) {
					if (!isBad[v]) {
						good++;
					}
				}
				cities[i] = new City(i, good, total); 
				set.add(cities[i]);
			}
		}
		
		int optGood = 0;
		int optTotal = 1;
		int optCount = -1;
		
		while (!set.isEmpty()) {
			City c = set.pollFirst();
			bad.add(c.id);
//			System.err.println(c.id + " " + c.good + "/" + c.total);
			if (optCount == -1 || (long)c.good * optTotal > (long)c.total * optGood) {
//				System.err.println("!");
				optGood = c.good;
				optTotal = c.total;
				optCount = bad.size() - 1;
			}
			isBad[c.id] = true;
			for (int v : g[c.id]) {
				if (!isBad[v]) {
					set.remove(cities[v]);
					cities[v].good--;
					set.add(cities[v]);
				}
			}
		}
		
		out.println(n - optCount);
		for (int i = optCount; i < n; i++) {
			out.print(bad.get(i) + 1 + " ");
		}
		out.println();
		
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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