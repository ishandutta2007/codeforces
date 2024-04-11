import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int MOD = 1_000_000_009;
	
	int[] fact, invFact;
	
	int pow(int a, int b) {
		int res = 1;
		while (b != 0) {
			if ((b & 1) == 1) {
				res = (int)((long) res * a % MOD);
			}
			a = (int)((long)a * a % MOD);
			b >>= 1;
		}
		return res;
	}
	
	int C(int n, int k) {
		if (n < 0 || k < 0 || k > n)
			return 0;
		return (int)((long)fact[n] * invFact[k] % MOD * invFact[n - k] % MOD);
	}

	void solve() throws IOException {
		int n = nextInt();
		int w = nextInt();
		int b = nextInt();
		
		fact = new int[n + Math.max(w, b)];
		invFact = new int[fact.length];
		
		fact[0] = invFact[0] = 1;
		for (int i = 1; i < fact.length; i++) {
			fact[i] = (int)((long)fact[i - 1] * i % MOD);
			invFact[i] = pow(fact[i], MOD - 2);
		}
		
		int ans = 0;
		
		for (int lenB = 1; lenB <= n - 2 && lenB <= b; lenB++) {
			int ways = (int)((long)(n - 1 - lenB) * C(b - 1, lenB - 1) % MOD * C(w - 1, n - lenB - 1) % MOD);
//			System.err.println(b + " " + lenB);
//			System.err.println(w + " " + (n - lenB));
			ans += ways;
			if (ans >= MOD)
				ans -= MOD;
		}
		
		ans = (int)((long)ans * fact[b] % MOD * fact[w] % MOD);
		out.println(ans);
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