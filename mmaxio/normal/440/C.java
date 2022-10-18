import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static long[] ONES = new long[17];
	static {
		ONES[1] = 1;
		for (int i = 2; i < 17; i++) {
			ONES[i] = 10 * ONES[i - 1] + 1;
		}
	}

	long go(long x, int len) {
		x = Math.abs(x);
//		System.err.println(x + " " + len);
		if (x % ONES[len] == 0) {
			return x / ONES[len] * len;
		}
		long low = x / ONES[len];
		long high = low + 1;

		long ret1 = low * len + go(x - low * ONES[len], len - 1);
		long ret2 = high * len + go(high * ONES[len] - x, len - 1);
		return Math.min(ret1, ret2);
	}

	long solve(long x) {
		return go(x, 16);
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		out.println(solve(nextLong()));
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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