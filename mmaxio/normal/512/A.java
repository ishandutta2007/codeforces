import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		String[] a = new String[n];
		boolean[][] g = new boolean[26][26];
		for (int i = 0; i < n; i++) {
			a[i] = nextToken();
		}
		for (int i = 0; i < n - 1; i++) {
			int j = 0;
			while (j < a[i].length() && j < a[i + 1].length()
					&& a[i].charAt(j) == a[i + 1].charAt(j)) {
				j++;
			}
			if (j == a[i].length()) {
			} else if (j == a[i + 1].length()) {
				out.println("Impossible");
				return;
			} else {
				g[a[i].charAt(j) - 'a'][a[i + 1].charAt(j) - 'a'] = true;
			}
		}
		for (int k = 0; k < 26; k++)
			for (int i = 0; i < 26; i++)
				for (int j = 0; j < 26; j++) {
					g[i][j] |= g[i][k] && g[k][j];
				}

		for (int i = 0; i < 26; i++) {
			if (g[i][i]) {
				out.println("Impossible");
				return;
			}
		}

		boolean[] vis = new boolean[26];
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < 26; i++) {
			if (!vis[i]) {
				dfs(i, vis, sb, g);
			}
		}
		sb.reverse();

		out.println(sb.toString());
	}

	void dfs(int i, boolean[] vis, StringBuilder sb, boolean[][] g) {
		vis[i] = true;
		for (int j = 0; j < 26; j++) {
			if (!vis[j] && g[i][j]) {
				dfs(j, vis, sb, g);
			}
		}
		sb.append((char) ('a' + i));
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
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