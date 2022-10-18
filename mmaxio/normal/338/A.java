import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int tot = nextInt();
		int ok = nextInt();
		
		int k = nextInt();
		
		int maxBad = tot / k;
		if (tot - maxBad >= ok) {
			out.println(ok);
			return;
		}
		
		
		int	dbl = ok + tot / k - tot;

		
		int dblPoints = pow(2, dbl + 1) - 2;
		while (dblPoints < 0)
			dblPoints += MOD;
		
		dblPoints = (int)((long)dblPoints * k % MOD);
		
		int rest = ok - dbl * k;
		
		int ans = dblPoints + rest;
		
		if (ans >= MOD)
			ans -= MOD;
		
		out.println(ans);
	}
	
	static int pow(int a, int b) {
		int ret = 1;
		while (b != 0) {
			if ((b & 1) == 1)
				ret = (int)((long)ret * a % MOD);
			a = (int)((long)a * a % MOD);
			b >>= 1;
		}
		return ret;
	}
	
	static final int MOD = 1000000009;

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