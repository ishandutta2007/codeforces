import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	static final int P = 1_000_000_007;

	void solve() throws IOException {
		String s = nextString();
		String t = nextString();

		String ts = t + "#" + s;
		int[] pi = new int[ts.length()];
		for (int i = 1; i < ts.length(); ++i) {
			int j = pi[i - 1];
			while (j > 0 && ts.charAt(i) != ts.charAt(j))
				j = pi[j - 1];
			if (ts.charAt(i) == ts.charAt(j))
				++j;
			pi[i] = j;
		}
		boolean[] end = new boolean[s.length()];
		for (int i = t.length() - 1; i < s.length(); i++) {

			end[i] = pi[i + t.length() + 1] == t.length();

		}
		
		int[] dp = new int[s.length() + 1];
		int[] pref = new int[s.length() + 1];
		dp[0] = 1;
		pref[0] = 1;
		int need = -1;
		for (int i = 0; i < s.length(); i++) {
			if (end[i]) {
				need = i - t.length() + 1;
			}
			dp[i + 1] = dp[i];
			if (need != -1) {
				dp[i + 1] += pref[need];
				dp[i + 1] %= P;
			}
//			System.err.println(i + " " + dp[i + 1]);
			pref[i + 1] = (pref[i] + dp[i + 1]) % P; 
		}
		
		int ret = (dp[s.length()] - 1);
		if (ret < 0) {
			ret += P;
		}
		out.println(ret);

	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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