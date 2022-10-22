import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lucasr
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		MyScanner in = new MyScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		FPhoenixAndEarthquake solver = new FPhoenixAndEarthquake();
		solver.solve(1, in, out);
		out.close();
	}

	static class FPhoenixAndEarthquake {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			FPhoenixAndEarthquake.sc = sc;
			FPhoenixAndEarthquake.out = out;
			int n = sc.nextInt();
			int m = sc.nextInt();
			long x = sc.nextLong();
			long[] a = sc.nextLongArray(n);
			long tot = 0;
			for (int i = 0; i < n; i++) {
				tot += a[i];
			}
			int[] from = new int[m], to = new int[m];
			List<Integer>[] adj = new List[n];
			int[] adjFrom = new int[n];
			for (int i = 0; i < n; i++) {
				adj[i] = new ArrayList<>();
			}
			for (int i = 0; i < m; i++) {
				from[i] = sc.nextInt() - 1;
				to[i] = sc.nextInt() - 1;
				adj[from[i]].add(i);
				adj[to[i]].add(i);
			}
			if (tot < x * (n - 1)) {
				out.println("NO");
				return;
			}
			out.println("YES");
			UnionFind uf = new UnionFind(n);
			TreeSet<Integer> sorted = new TreeSet<>(Comparator.comparingLong(id -> a[(int) id]).thenComparingInt(id -> (int) id).reversed());
			for (int i = 0; i < n; i++) {
				sorted.add(i);
			}
			for (int i = 0; i < n - 1; i++) {
				int bigId = sorted.pollFirst();
				for (int j = adjFrom[bigId]; j < adj[bigId].size(); j++) {
					int next = adj[bigId].get(j);
					int rep = uf.find(from[next]) + uf.find(to[next]) - bigId;
					if (rep == bigId) {
						adjFrom[bigId]++;
					} else {
						sorted.remove(rep);
						uf.union(bigId, rep);
						int united = uf.find(bigId);
						a[united] = a[bigId] + a[rep] - x;
						int ttt = newFrom(adj[bigId], adjFrom[bigId], adj[rep], adjFrom[rep]);
						adj[united] = join(adj[bigId], adjFrom[bigId], adj[rep], adjFrom[rep]);
						adjFrom[united] = ttt;
						sorted.add(united);
						out.println(next + 1);
						break;
					}
				}
			}
		}

		static int newFrom(List<Integer> a, int fromA, List<Integer> b, int fromB) {
			if (a.size() - fromA > b.size() - fromB) {
				return fromA;
			} else {
				return fromB;
			}
		}

		static List<Integer> join(List<Integer> a, int fromA, List<Integer> b, int fromB) {
			if (a.size() - fromA > b.size() - fromB) {
				for (int i = fromB; i < b.size(); i++) {
					a.add(b.get(i));
				}
				return a;
			} else {
				for (int i = fromA; i < a.size(); i++) {
					b.add(a.get(i));
				}
				return b;
			}
		}

	}

	static class MyScanner {
		private BufferedReader br;
		private StringTokenizer tokenizer;

		public MyScanner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public long[] nextLongArray(int n) {
			long[] ret = new long[n];
			for (int i = 0; i < n; i++) {
				ret[i] = nextLong();
			}
			return ret;
		}

	}

	static class UnionFind {
		int[] rep;

		public UnionFind(int size) {
			rep = new int[size];
			for (int i = 0; i < size; i++) {
				rep[i] = i;
			}
		}

		public int find(int val) {
			if (rep[val] != val) {
				return rep[val] = find(rep[val]);
			}
			return val;
		}

		public boolean union(int a, int b) {
			int aRep = find(a);
			int bRep = find(b);
			if (aRep == bRep) return false;
			rep[aRep] = bRep;
			return true;
		}

	}
}