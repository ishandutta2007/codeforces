import java.io.*;
import java.util.*;

public class B {
	
	int[][] g;

	void submit() {
		int n = nextInt();
		nextInt();

		g = new int[n][];
		for (int i = 0; i < n; i++) {
			int deg = nextInt();
			g[i] = new int[deg];
			for (int j = 0; j < deg; j++) {
				g[i][j] = nextInt() - 1;
			}
		}

		int src = nextInt() - 1;

		boolean[][] can = new boolean[2][n];
		int[][] from = new int[2][n];
		int[] que = new int[4 * n];

		int qh = 0, qt = 0;

		can[0][src] = true;
		que[qt++] = 0;
		que[qt++] = src;

		while (qh < qt) {
			int odd = que[qh++];
			int v = que[qh++];
//			System.err.println(odd + " " + v);
			for (int u : g[v]) {
				if (!can[odd ^ 1][u]) {
					from[odd ^ 1][u] = v;
					can[odd ^ 1][u] = true;
					que[qt++] = odd ^ 1;
					que[qt++] = u;
				}
			}
		}
		
		
		for (int sink = 0; sink < n; sink++) {
			if (g[sink].length == 0 && can[1][sink]) {
				out.println("Win");
				ArrayList<Integer> ans = new ArrayList<>(n);
				for (int v = sink, par = 1; v != src || par != 0; v = from[par][v], par ^= 1) {
//					System.err.println("! " + v + " " + par);
					ans.add(v);
				}
				ans.add(src);
				Collections.reverse(ans);
				for (int v : ans) {
					out.print((v + 1) + " ");
				}
				return;
			}
		}
		
		vis = new int[n];
		if (dfs(src)) {
			out.println("Draw");
		} else {
			out.println("Lose");
		}
	}
	
	boolean dfs(int v) {
		vis[v] = 1;
		for (int u : g[v]) {
			if (vis[u] == 1) {
				return true;
			} else if (vis[u] == 0) {
				if (dfs(u)) {
					return true;
				}
			}
		}
		vis[v] = 2;
		return false;
	}
	
	int[] vis;

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new B();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}