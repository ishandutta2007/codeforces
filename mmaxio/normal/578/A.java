import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	double f1(int x, int y) {
		if (x == y) {
			return x;
		}
		x -= y;
		
		int maxDiv = x / y;
		if (maxDiv % 2 == 1) {
			maxDiv--;
		}
		return 1.0 * x / maxDiv;
	}
	
	double f2(int x, int y) {
		x += y;
		int maxDiv = x / y;
		if (maxDiv % 2 == 1) {
			maxDiv--;
		}
		return 1.0 * x / maxDiv;
	}

	void solve() throws IOException {
		int x0 = nextInt();
		int y0 = nextInt();
		if (x0 < y0) {
			out.println(-1);
			return;
		}
		double a = f1(x0, y0);
		double b = f2(x0, y0);
		
		if (a < -0.5 && b < -0.5) {
			out.println(-1);
			return;
		} else if (a < -0.5) {
			out.println(b);
		} else if (b < -0.5) {
			out.println(a);
		} else {
			out.println(Math.min(a, b));
		}
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