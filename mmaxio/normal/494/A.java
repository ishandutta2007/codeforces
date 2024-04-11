import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		String s = nextToken();
		int bal = 0;
		int hash = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '(') {
				bal++;
			} else if (s.charAt(i) == ')') {
				bal--;
			} else {
				hash++;
			}
		}
		if (bal - hash < 0) {
			out.println(-1);
			return;
		}
		int lastHash = s.length() - 1;
		while (s.charAt(lastHash) != '#') {
			lastHash--;
		}

		int lastRep = bal - (hash - 1);
		int curBal = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '(') {
				curBal++;
			} else if (s.charAt(i) == ')') {
				curBal--;
			} else {
				if (i == lastHash) {
					curBal -= lastRep;
				} else {
					curBal--;
				}

			}
			if (curBal < 0) {
				out.println(-1);
				return;
			}
		}
		if (curBal != 0) {
			out.println(-1);
			return;
		}
		for (int i = 0; i < hash - 1; i++) {
			out.println(1);
		}
		out.println(lastRep);
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