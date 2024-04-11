import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		char[] s = nextToken().toCharArray();
		
		long ret = (long)n * (m - 1); // one char different
		
		for (int i = 0; i < n - 1; i++) {
			if (s[i] != s[i + 1]) {
				ret += n * (m - 1); // as prefix and suffix
			}
		}
		
		// ababa?
		
		for (int i = 0, j = 0; i < n - 1; ) {
			if (s[i] == s[i + 1]) {
				i++;
				continue;
			}
			j = Math.max(j, i + 1);
			char c1 = s[i];
			char c2 = s[i + 1];
			while (j < n && s[j] == ((j - i & 1) == 0 ? c1 : c2)) {
				j++;
			}
			ret -= j - i - 1;
			i++;
		}
		
		out.println(ret);
		
	}

	boolean even(int i) {
		return (i & 1) == 0;
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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