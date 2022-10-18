import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		String s1 = nextToken();
		int x1 = s1.charAt(0) - 'a';
		int y1 = s1.charAt(1) - '1';
		String s2 = nextToken();
		int x2 = s2.charAt(0) - 'a';
		int y2 = s2.charAt(1) - '1';

		int dx = x2 - x1;
		int dy = y2 - y1;

		out.println(Math.max(Math.abs(dx), Math.abs(dy)));

		while (dx != 0 || dy != 0) {
			if (dx < 0) {
				out.print("L");
				dx++;
			}
			if (dx > 0) {
				out.print("R");
				dx--;
			}
			if (dy < 0) {
				out.print("D");
				dy++;
			}
			if (dy > 0) {
				out.print("U");
				dy--;
			}
			out.println();
		}
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