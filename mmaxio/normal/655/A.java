import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		char[][] a = new char[2][2];
		char[][] b = new char[2][2];
		for (int i = 0; i < 2; i++) {
			a[i] = nextToken().toCharArray();
		}

		for (int i = 0; i < 2; i++) {
			b[i] = nextToken().toCharArray();
		}

		String s = "" + a[0][0] + a[0][1] + a[1][1] + a[1][0];
		String t = "" + b[0][0] + b[0][1] + b[1][1] + b[1][0];
		
		int x = s.indexOf('A');
		s = s.substring(x) + s.substring(0, x);

		x = t.indexOf(s.charAt(0));
		String ss = t.substring(x) + t.substring(0, x);
		
		x = s.indexOf('X');
		s = s.substring(0, x) + s.substring(x + 1);
		
		x = ss.indexOf('X');
		ss = ss.substring(0, x) + ss.substring(x + 1);

		out.println(s.equals(ss) ? "YES" : "NO");
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