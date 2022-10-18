import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		String s = nextToken();
		TreeSet<String> ans = new TreeSet<>();

		int n = s.length();

		boolean[] ok2 = new boolean[n];
		boolean[] ok3 = new boolean[n];

		for (int i = n - 1; i >= 5; i--) {
			for (int len = 2; len <= 3; len++) {

				boolean[] ok = (len == 2 ? ok2 : ok3);
				int nxt = i + len;
				if (nxt > n) {
					continue;
				}
				if (nxt == n) {
					ok[i] = true;
					continue;
				}
				for (int len2 = 2; len2 <= 3; len2++) {
					boolean[] okNxt = (len2 == 2 ? ok2 : ok3);
					if (!okNxt[nxt]) {
						continue;
					}
					if (len == len2) {
						String here = s.substring(i, i + len);
						String check = s.substring(nxt, nxt + len);
						if (!here.equals(check)) {
							ok[i] = true;
						}
					} else {
						ok[i] = true;
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			if (ok2[i]) {
				ans.add(s.substring(i, i + 2));
			}
			if (ok3[i]) {
				ans.add(s.substring(i, i + 3));
			}
		}

		out.println(ans.size());
		for (String ss : ans) {
			out.println(ss);
		}
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