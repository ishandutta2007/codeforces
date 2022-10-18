import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final String[] s = { "IMPOSSIBLE", "SEGMENT", "TRIANGLE" };
	
	int f(int a, int b, int c) {
		if (a + b > c && a + c > b && b + c > a)
			return 2;
		if (a + b == c || a + c == b || b + c == a)
			return 1;
		return 0;
	}

	void solve() throws IOException {
		int a = nextInt();
		int b = nextInt();
		int c = nextInt();
		int d = nextInt();

		int ans = Math.max(Math.max(f(a, b, c), f(a, b, d)),
				Math.max(f(a, c, d), f(b, c, d)));
		out.println(s[ans]);
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A().inp();
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