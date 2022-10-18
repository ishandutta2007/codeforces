import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	long solve(long x, long y) {
		if (y == 0) {
			return 0;
		}
		if (Long.numberOfLeadingZeros(x) != Long.numberOfLeadingZeros(y)) {
			long tmp = Long.highestOneBit(y);
			if (y == tmp * 2 - 1) {
				return y;
			} else {
				return tmp - 1;
			}
		}
		long sub = Long.highestOneBit(x);
		return sub + solve(x - sub, y - sub);
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		int t = nextInt();
		while (t-- > 0) {
			long l = nextLong();
			long r = nextLong();
			out.println(solve(l, r));
		}
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