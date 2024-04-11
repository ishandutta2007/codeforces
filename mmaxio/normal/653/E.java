import java.io.*;
import java.util.*;

public class E_faster {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();

		HashSet<Integer>[] g = new HashSet[n];
		for (int i = 0; i < n; i++) {
			g[i] = new HashSet<>();
		}

		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}

		int[] restNext = new int[n + 1];
		int[] restPrev = new int[n + 1];
		for (int i = 0; i <= n; i++) {
			restNext[i] = i + 1;
			restPrev[i] = i - 1;
		}

		int[] col = new int[n];
		Arrays.fill(col, -1);

		int cc = 0;

		ArrayDeque<Integer> q = new ArrayDeque<>();

		for (int i = 1; i < n; i++) {
			if (col[i] == -1) {
				q.add(i);
				col[i] = cc;
				
				int pr = restPrev[i];
				int ne = restNext[i];
				
				restNext[pr] = ne;
				restPrev[ne] = pr;

				while (!q.isEmpty()) {
					int v = q.poll();
					for (int u = restNext[0]; u != n; u = restNext[u]) {
						if (!g[v].contains(u)) {
							q.add(u);
							col[u] = cc;
							
							pr = restPrev[u];
							ne = restNext[u];
							
							restNext[pr] = ne;
							restPrev[ne] = pr;
						}
					}
					
				}

				cc++;
			}
		}

		if (cc > k) {
			out.println("impossible");
			return;
		}
			
		if (n - 1 - g[0].size() < k) {
			out.println("impossible");
			return;
		}
		
		HashSet<Integer> has = new HashSet<>();
		for (int u = 1; u < n; u++) {
			if (!g[0].contains(u)) {
				has.add(col[u]);
			}
		}
		
		out.println(has.size() == cc ? "possible" : "impossible");
	}

	E_faster() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E_faster();
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