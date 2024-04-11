import java.io.*;
import java.util.*;

public class A_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int p = nextInt();
		String ss = nextToken();
		char[] s = ss.toCharArray();
		if (p == 1) {
			out.println("NO");
			return;
		}
		if (p == 2) {
			if (s[0] == 'b') {
				out.println("NO");
			} else {
				for (int i = 0; i < n; i++) {
					out.print("ba".charAt(i % 2));
				}
				out.println();
			}
			return;
		}
		char last = (char) ('a' + p - 1);
		for (int i = n - 1; i >= 0; i--) {
			for (char j = (char) (s[i] + 1); j <= last; j++) {
				if (i >= 2 && j == s[i - 2]) {
					continue;
				}
				if (i >= 1 && j == s[i - 1]) {
					continue;
				}
				s[i] = j;
				for (int k = i + 1; k < n; k++) {
					for (char c = 'a'; c <= last; c++) {
						if (k >= 2 && c == s[k - 2]) {
							continue;
						}
						if (k >= 1 && c == s[k - 1]) {
							continue;
						}
						s[k] = c;
						break;
					}
				}
				out.println(new String(s));
				return;
			}
		}
		out.println("NO");
	}

	A_new() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A_new();
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