import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final String DIRS = "NESW";

	void solve() throws IOException {

		int n = nextInt();
		int[] s = new int[2 * n - 1];
		String sa = nextToken();
		for (int i = 0; i < n - 1; i++) {
			s[n - 2 - i] = DIRS.indexOf(sa.charAt(i)) ^ 2;
		}

		s[n - 1] = -1;

		String sb = nextToken();
		for (int i = n; i < 2 * n - 1 ; i++) {
			s[i] = DIRS.indexOf(sb.charAt(i - n));
		}
		
		int[] pi = new int[2 * n - 1];
		for (int i = 1, q = 0; i < pi.length; i++) {
			while (q > 0 && s[i] != s[q]) {
				q = pi[q - 1];
			}
			if (s[i] == s[q]) {
				q++;
			}
			pi[i] = q;
		}
		
		out.println(pi[2 * n - 2] > 0 ? "NO" : "YES");
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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