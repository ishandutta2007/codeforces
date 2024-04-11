import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int go(long x) {
		int ret = 0;
		while (x > 0) {
			System.err.println(x);
			int a = (int) Math.cbrt(x);
			x -= (long) a * a * a;
			ret++;
		}
		return ret;
	}

	long[] f(long x) {
		if (x < 8) {
			return new long[] { x, x };
		}
		long a = (long) Math.cbrt(x);
		
		long[] f1 = f(x - a * a * a);
		long[] f2 = f(a * a * a - (a - 1) * (a - 1) * (a - 1) - 1);
		
		f1[0]++;
		f1[1] = a * a * a + f1[1];
		
		f2[0] += 1;
		f2[1] = (a - 1) * (a - 1) * (a - 1) + f2[1];
		
		if (f1[0] != f2[0]) {
			return f1[0] > f2[0] ? f1 : f2; 
		}
		
		return f1[1] > f2[1] ? f1 : f2;
	}

	void solve() throws IOException {
		long x = nextLong();
		long[] ans = f(x);
		out.println(ans[0] + " " + ans[1]);
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