import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		char[] ans = new char[16];
		ans[0] = '1';
		ans[1] = '0';
		ans[2] = '0';
		ans[3] = '1';
		ans[4] = '0';
		ans[5] = '1';
		ans[6] = '0';
		ans[7] = '1';
		ans[8] = '1';
		ans[9] = '1';
		ans[10] = '0';
		ans[11] = '0';
		ans[12] = '1';
		ans[13] = '0';
		ans[14] = '1';
		ans[15] = '0';
		out.println(ans[nextInt() - 1]);
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