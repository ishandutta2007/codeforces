import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int[] dx = { 1, 1, 0, -1, -1, 0 };
	static final int[] dy = { 0, 1, 1, 0, -1, -1 };

	void solve() throws IOException {
		int ans = 0;
		int x0 = 0;
		int y0 = 0;
		for (int i = 0; i < 6; i++) {
			int len = nextInt();
			int x1 = x0 + len * dx[i];
			int y1 = y0 + len * dy[i];
			ans += x0 * y1 - x1 * y0;
			x0 = x1;
			y0 = y1;
		}
		out.println(ans);
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