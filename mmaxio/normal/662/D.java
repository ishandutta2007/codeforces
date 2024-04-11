import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Olymp {
		int id;
		String s;

		public Olymp(int id, String s) {
			this.id = id;
			this.s = s;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			s = s.substring(4);
			int len = s.length();
			long tail = Integer.parseInt(s);

			long start = 1989;
			long pw = 10;
			for (int j = 1; j < len; j++) {
				start += pw;
				pw *= 10;
			}

//			System.err.println(start);

			long res = (Math.floorDiv(start - 1 - tail, pw) + 1) * pw + tail;
			out.println(res);

		}

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