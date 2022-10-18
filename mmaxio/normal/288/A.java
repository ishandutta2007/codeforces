import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		if (n < k) {
			out.println("-1");
			return;
		}
		if (k == 1) {
			out.println(n == 1 ? "a" : "-1");
			return;
		}
		if (k == 2) {
			for (int i = 0; i < n; i++) {
				out.print(((i & 1) == 0) ? 'a' : 'b');
			}
			out.println();
			return;
		}
		
		for (int i = 0; i < n - (k - 2); i++) {
			out.print(((i & 1) == 0) ? 'a' : 'b');
		}
		for (int i = 2; i < k; i++)
			out.print((char)('a' + i));
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