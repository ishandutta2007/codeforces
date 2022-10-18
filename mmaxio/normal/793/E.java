import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int n;
	int[] p;
	int[] sz;
	int[] who;

	int[] to;
	int[] head;
	int[] next;

	void addEdge(int v, int u, int idx) {
		to[idx] = u;
		next[idx] = head[v];
		head[v] = idx;
	}

	boolean cool(int a, int b, int c, int d, int leaves) {
		boolean[] can = new boolean[leaves + 1];
		can[0] = true;

		for (int v = p[a]; v != 0; v = p[v]) {

			for (int e = head[v]; e >= 0; e = next[e]) {
				int u = to[e];
				if (who[u] == a) {
					// System.err.println(v + " a " + u);
					continue;
				}

				int nowSz = sz[u];

				for (int i = can.length - 1; i >= nowSz; i--) {
					can[i] |= can[i - nowSz];
				}
			}
		}

		for (int v = p[b]; v != 0; v = p[v]) {
			for (int e = head[v]; e >= 0; e = next[e]) {
				int u = to[e];
				if (who[u] == b) {
					continue;
				}

				int nowSz = sz[u];

				for (int i = can.length - 1; i >= nowSz; i--) {
					can[i] |= can[i - nowSz];
				}
			}
		}

		int szC = -1;
		int szD = -1;
		for (int e = head[0]; e >= 0; e = next[e]) {
			int u = to[e];
			if (who[u] == c) {
				szC = sz[u];
			} else if (who[u] == d) {
				szD = sz[u];
			} else if (who[u] == -1) {
				int nowSz = sz[u];
				for (int i = can.length - 1; i >= nowSz; i--) {
					can[i] |= can[i - nowSz];
				}
			}
		}

		int need = (leaves - 2) / 2 - szC;

		if (need < 0 || need >= can.length || !can[need]) {
			return false;
		}

		return true;
	}

	void solve() throws IOException {
		n = nextInt();
		int a = nextInt() - 1;
		int b = nextInt() - 1;
		int c = nextInt() - 1;
		int d = nextInt() - 1;

		head = new int[n];
		Arrays.fill(head, -1);
		to = new int[n - 1];
		next = new int[n - 1];
		
		p = new int[n];
		p[0] = -1;
		for (int i = 1; i < n; i++) {
			p[i] = nextInt() - 1;
			addEdge(p[i], i, i - 1);
		}

		sz = new int[n];
		who = new int[n];

		Arrays.fill(who, -1);
		who[a] = a;
		who[b] = b;
		who[c] = c;
		who[d] = d;

		int leaves = 0;
		
		for (int i = 0; i < n; i++) {
			sz[i] = head[i] == -1  ? 1 : 0;
			leaves += sz[i];
		}
		
		if (leaves % 2 != 0) {
			out.println("NO");
			return;
		}
		
		for (int i = n - 1; i >= 1; i--) {
			sz[p[i]] += sz[i];
			if (who[i] != -1) {
				if (who[p[i]] != -1 && p[i] != 0) {
					throw new AssertionError();
				}
				who[p[i]] = who[i];
			}
		}

		out.println(cool(a, b, c, d, leaves) && cool(c, d, a, b, leaves) ? "YES" : "NO");

	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E();
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