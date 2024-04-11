import java.io.*;
import java.util.*;

public class cf327E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] goA, goB; // 80 mb
	int[] sufLink; // 40 mb
	int[] which; // 40 mb

	int size = 2;

	int add(char[] s, int id) {
		int v = 1;
		for (int i = 0; i < s.length; i++) {
			char c = s[i];
			int[] tr = c == 'a' ? goA : goB;
			if (tr[v] == 0) {
				tr[v] = size++;
			}
			v = tr[v];
		}
		which[v] = id;
		return v;
	}

	int[] pair1, pair2;
	boolean[] used1;
	boolean[] used2;
	BitSet[] g;

	int n;

	boolean dfs(int v) {
		used1[v] = true;
		for (int u = 0; u < n; u++) {
			if (!g[v].get(u)) {
				continue;
			}
			if (pair2[u] == -1 || (!used1[pair2[u]] && dfs(pair2[u]))) {
				pair1[v] = u;
				pair2[u] = v;
				return true;
			}
		}
		return false;
	}

	void dfs2(int v) {
		used1[v] = true;
		for (int u = 0; u < n; u++) {
			if (!g[v].get(u) || pair1[v] == u) {
				continue;
			}
			used2[u] = true;
			if (!used1[pair2[u]]) {
				dfs2(pair2[u]);
			}
		}
	}

	void solve() throws IOException {
		n = nextInt();
		char[][] s = new char[n][]; // 20 mb

		int maxSize = 2;

		for (int i = 0; i < n; i++) {
			s[i] = nextToken().toCharArray();
			maxSize += s[i].length;
		}

		goA = new int[maxSize];
		goB = new int[maxSize];
		sufLink = new int[maxSize];
		which = new int[maxSize];
		Arrays.fill(which, -1);

		for (int i = 0; i < n; i++) {
			add(s[i], i);
		}

		int[] q = new int[size]; // 10 mb
		int qHead = 0;
		int qTail = 0;

		sufLink[1] = 0;
		goA[0] = goB[0] = 1;

		q[qTail++] = 1;

		while (qHead < qTail) {
			int v = q[qHead++];
			int suf = sufLink[v];

			if (which[v] == -1) {
				which[v] = which[suf];
			}

			for (int i = 0; i < 2; i++) {
				int[] go = i == 0 ? goA : goB;
				if (go[v] == 0) {
					go[v] = go[suf];
				} else {
					int to = go[v];
					sufLink[to] = go[suf];
					q[qTail++] = to;
				}
			}

		}

		g = new BitSet[n];
		for (int i = 0; i < n; i++) {
			g[i] = new BitSet(n);
			int v = 1;
			char[] cur = s[i];
			for (int j = 0; j < cur.length; j++) {
				v = cur[j] == 'a' ? goA[v] : goB[v];
				if (j == cur.length - 1) {
					if (which[sufLink[v]] != -1) {
						g[i].set(which[sufLink[v]]);
						;
					}
				} else if (which[v] != -1) {
					g[i].set(which[v]);
				}
			}
		}

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++) {
				if (g[i].get(k)) {
					g[i].or(g[k]);
				}
			}

		pair1 = new int[n];
		pair2 = new int[n];
		used1 = new boolean[n];
		used2 = new boolean[n];
		Arrays.fill(pair1, -1);
		Arrays.fill(pair2, -1);

		int ans = n;

		for (int i = 0; i < n; i++) {
			Arrays.fill(used1, false);
			if (dfs(i)) {
				ans--;
			}
		}

		Arrays.fill(used1, false);
		out.println(ans);
		for (int i = 0; i < n; i++) {
			if (pair1[i] == -1) {
				dfs2(i);
			}
		}

		for (int i = 0; i < n; i++) {
			if (used1[i] && !used2[i]) {
				out.print((i + 1) + " ");
			}
		}
		out.println();
	}

	cf327E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new cf327E();
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