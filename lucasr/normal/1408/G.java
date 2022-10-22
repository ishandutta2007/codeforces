import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
		GClusterizationCounting solver = new GClusterizationCounting();
		solver.solve(1, in, out);
		out.close();
	}

	static class GClusterizationCounting {
		static final long MOD = 998244353;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			int n = sc.nextInt();
			int total = 1 + (n * (n - 1)) / 2;
			int[] from = new int[total], to = new int[total];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					int edge = sc.nextInt();
					if (i < j) {
						from[edge] = i;
						to[edge] = j;
					}
				}
			}
			int[][] table = new int[n][2];
			int[] edges = new int[n];
			for (int i = 0; i < n; i++) {
				table[i][1] = 1;
			}
			UnionFind uf = new UnionFind(n);
			for (int i = 1; i < total; i++) {
				int a = uf.find(from[i]);
				int b = uf.find(to[i]);
				if (a != b) {
					uf.union(a, b);
					int c = uf.find(a);
					int[] tmp = new int[table[a].length + table[b].length - 1];
					for (int j = 1; j < table[a].length; j++) {
						for (int k = 1; k < table[b].length; k++) {
							tmp[j + k] += (table[a][j] * (long) table[b][k]) % MOD;
							tmp[j + k] %= MOD;
						}
					}
					table[c] = tmp;
					edges[c] = edges[a] + edges[b];
				}
				a = uf.find(a);
				edges[a]++;
				if (2 * edges[a] == (table[a].length - 1) * (table[a].length - 2)) {
					table[a][1]++;
					table[a][1] %= MOD;
				}
			}
			int rep = uf.find(0);
			for (int i = 1; i <= n; i++) {
				out.print(table[rep][i] + " ");
			}
			out.println();
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