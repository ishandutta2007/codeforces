import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int MOD = 1000000007;

	void solve() throws IOException {
		String s = nextToken();
		int k = nextInt();
		int n = s.length();

		long mult1 = 0;
		int p2 = 1;
		for (int i = 0; i < n; i++) {
			if (s.charAt(i) == '0' || s.charAt(i) == '5') {
				mult1 += p2;
			}
			p2 *= 2;
			if (p2 >= MOD)
				p2 -= MOD;
		}
		mult1 %= MOD;

		int num = pow(2, (int) ((long) n * k % (MOD - 1))) - 1;
		int denom = pow(2, n) - 1;
		long mult2 = (long) num * pow(denom, MOD - 2) % MOD;

		out.println(mult1 * mult2 % MOD);
	}
	
	static int pow(int a, int b) {
		int ret = 1;
		while (b > 0) {
			if ((b & 1) == 1)
				ret = (int)((long)ret * a % MOD);
			a = (int)((long)a * a % MOD);
			b >>= 1;
		}
		return ret;
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
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