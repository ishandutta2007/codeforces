import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final String[] ALL = { "vaporeon", "jolteon", "flareon", "espeon",
			"umbreon", "leafeon", "glaceon", "sylveon" };
	
	boolean fit(String p, String s) {
		if (p.length() != s.length()) {
			return false;
		}
		for (int i = 0; i < p.length(); i++) {
			if (p.charAt(i) != '.' && p.charAt(i) != s.charAt(i)) {
				return false;
			}
		}
		return true;
	}

	void solve() throws IOException {
		nextInt();

		String s = nextToken();
		for (int i = 0; i < ALL.length; i++) {
			if (fit(s, ALL[i])) {
				out.println(ALL[i]);
				return;
			}
		}
		throw new AssertionError();
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