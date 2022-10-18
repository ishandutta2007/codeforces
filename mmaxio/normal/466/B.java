import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	long ceilDiv(long x, long y) {
		return (x + y - 1) / y;
	}

	void solve() throws IOException {
		long n = nextInt();
		long a = nextInt();
		long b = nextInt();
		n *= 6;

		long x = Integer.MAX_VALUE / 2;
		long y = Integer.MAX_VALUE / 2;

		for (long a1 = a; a1 <= a + 100000; a1++) {
			long b1 = Math.max(ceilDiv(n, a1), b);
			if (a1 * b1 < x * y) {
				x = a1;
				y = b1;
			}
		}

		for (long b1 = b; b1 <= b + 100000; b1++) {
			long a1 = Math.max(ceilDiv(n, b1), a);
			if (a1 * b1 < x * y) {
				x = a1;
				y = b1;
			}
		}

		out.println(x * y);
		out.println(x + " " + y);
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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