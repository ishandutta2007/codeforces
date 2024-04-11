import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	Random rng = new Random();
	
	String getName() {
		char[] buf = new char[10];
		buf[0] = 'A';
		for (int i = 1; i < buf.length; i++) {
			buf[i] = (char)('a' + rng.nextInt(26));
		}
		return new String(buf);
	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		String[] ans = new String[n];
		for (int i = 0; i < k - 1; i++) {
			ans[i] = getName();
		}
		
		for (int i = k - 1; i < n; i++) {
			boolean diff = nextToken().equals("YES");
			if (diff) {
				ans[i] = getName();
			} else {
				ans[i] = ans[i - k + 1];
			}
		}
		
		for (String s : ans) {
			out.print(s + " ");
		}
		out.println();
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