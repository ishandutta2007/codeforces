import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	long g(int a, int b, int c, int l) {
		// add up to l to b and c so that a >= b + c
		l = Math.min(l, a - b - c);
		if (l >= 0) {
			return (long) (l + 2) * (l + 1) / 2;
		} else
			return 0;
	}

	long f(int a, int b, int c, int l) {
		long ret = 0;
		for (int i = 0; i <= l; i++) {
			ret += g(a + i, b, c, l - i);
		}
//		System.err.println(a + " " + b + " " + c + " " + l + " " + ret);
		return ret;
	}

	void solve() throws IOException {
		int a = nextInt();
		int b = nextInt();
		int c = nextInt();
		int l = nextInt();
		long ret = (long) (l + 1) * (l + 2) * (l + 3) / 6 - f(a, b, c, l)
				- f(b, c, a, l) - f(c, a, b, l);
		out.println(ret);
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