import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.util.ArrayDeque;
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
		DCowAndFields solver = new DCowAndFields();
		solver.solve(1, in, out);
		out.close();
	}

	static class DCowAndFields {
		public static MyScanner sc;
		public static PrintWriter out;
		int[] d1;
		int[] d2;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			DCowAndFields.sc = sc;
			DCowAndFields.out = out;
			int n = sc.nextInt();
			int m = sc.nextInt();
			int k = sc.nextInt();
			Integer[] special = new Integer[k];
			for (int i = 0; i < k; i++) {
				special[i] = sc.nextInt() - 1;
			}
			List<Integer>[] adj = new List[n];
			for (int i = 0; i < n; i++) {
				adj[i] = new ArrayList<>();
			}
			for (int i = 0; i < m; i++) {
				int a = sc.nextInt() - 1;
				int b = sc.nextInt() - 1;
				adj[a].add(b);
				adj[b].add(a);
			}
			d1 = bfs(adj, 0);
			d2 = bfs(adj, n - 1);
			Arrays.sort(special, Comparator.comparingInt(this::value));
			int ans = d1[n - 1], max = 0;
			int maxd1 = 0;
			for (int i = 0; i < k; i++) {
				if (i > 0) {
					max = Math.max(max, maxd1 + 1 + d2[special[i]]);
				}
				maxd1 = Math.max(maxd1, d1[special[i]]);
			}
			out.println(Math.min(ans, max));
		}

		int value(int pos) {
			return d1[pos] - d2[pos];
		}

		int[] bfs(List<Integer>[] adj, int from) {
			ArrayDeque<Integer> queue = new ArrayDeque<>();
			int[] dist = new int[adj.length];
			Arrays.fill(dist, -1);
			dist[from] = 0;
			queue.add(from);
			while (!queue.isEmpty()) {
				int cur = queue.pollFirst();
				int d = dist[cur];
				for (int v : adj[cur])
					if (dist[v] == -1) {
						dist[v] = d + 1;
						queue.addLast(v);
					}
			}
			return dist;
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
}