import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
		AParsasHumongousTree solver = new AParsasHumongousTree();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class AParsasHumongousTree {
		public static MyScanner sc;
		public static PrintWriter out;
		int n;
		int[] l;
		int[] r;
		IntArray[] adj;
		long[][] cache;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			AParsasHumongousTree.sc = sc;
			AParsasHumongousTree.out = out;

			n = sc.nextInt();
			l = new int[n];
			r = new int[n];
			adj = new IntArray[n];
			for (int i = 0; i < n; i++) {
				l[i] = sc.nextInt();
				r[i] = sc.nextInt();
				adj[i] = new IntArray();
			}
			for (int i = 0; i < n - 1; i++) {
				int a = sc.nextInt() - 1;
				int b = sc.nextInt() - 1;
				adj[a].add(b);
				adj[b].add(a);
			}
			cache = new long[2][n];
			Arrays.fill(cache[0], -1);
			Arrays.fill(cache[1], -1);
			out.println(Math.max(calc(0, 0, -1), calc(1, 0, -1)));
		}

		private long calc(int left, int node, int par) {
			long ret = cache[left][node];
			if (ret != -1) return ret;
			ret = 0;
			for (int i = 0; i < adj[node].size(); i++) {
				int v = adj[node].get(i);
				if (v != par) {
					long tmp1 = calc(1, v, node) + Math.abs((left == 1 ? l[node] : r[node]) - l[v]);
					long tmp2 = calc(0, v, node) + Math.abs((left == 1 ? l[node] : r[node]) - r[v]);
					ret += Math.max(tmp1, tmp2);
				}
			}
			return cache[left][node] = ret;
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

	static class IntArray {
		int[] arr;
		int size;

		public IntArray() {
			arr = new int[4];
		}

		public void add(int val) {
			if (size == arr.length) {
				arr = Arrays.copyOf(arr, 2 * arr.length);
			}
			arr[size++] = val;
		}

		public int get(int pos) {
			return arr[pos];
		}

		public int size() {
			return size;
		}

		public int[] toArray() {
			return Arrays.copyOf(arr, size);
		}

		public String toString() {
			return "IntArray " + Arrays.toString(toArray());
		}

	}
}