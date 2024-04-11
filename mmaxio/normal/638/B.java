import java.io.*;
import java.util.*;

public class B_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();

		int[] next = new int[26];
		int[] prev = new int[26];
		Arrays.fill(next, -1);
		Arrays.fill(prev, -1);
		boolean[] seen = new boolean[26];

		for (int i = 0; i < n; i++) {
			String s = nextToken();
			for (int j = 0; j < s.length() - 1; j++) {
				int v = s.charAt(j) - 'a';
				int u = s.charAt(j + 1) - 'a';
				next[v] = u;
				prev[u] = v;
			}
			for (int j = 0; j < s.length(); j++) {
				seen[s.charAt(j) - 'a'] = true;
			}
		}

		for (int i = 0; i < 26; i++) {
			if (seen[i] && prev[i] == -1) {
				for (int v = i; v != -1; v = next[v]) {
					out.print((char) ('a' + v));
				}
			}
		}
		
		out.println();
	}

	B_new() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B_new();
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