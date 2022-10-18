import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	
	int solve(int bigLen, int ins, int smallLen) {
		int low = Math.max(ins - smallLen, 0);
		int high = Math.min(ins, bigLen - smallLen);
		
		int doubleOpt = 2 * ins - smallLen;
		if (doubleOpt < 2 * low)
			return low;
		if (doubleOpt > 2 * high)
			return high;
		return doubleOpt / 2;
	}

	void solve(int n, int m, int x, int y, int a, int b) {
		int gcd = gcd(a, b);
		a /= gcd;
		b /= gcd;
		
		int sz = Math.min(n / a, m / b);
		a *= sz;
		b *= sz;
		
		int x1 = solve(n, x, a);
		int y1 = solve(m, y, b);
		out.println(x1 + " " + y1 + " " + (x1 + a) + " " + (y1 + b));
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		int n = nextInt();
		int m = nextInt();
		int x = nextInt();
		int y = nextInt();
		int a = nextInt();
		int b = nextInt();
		solve(n, m, x, y, a, b);
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