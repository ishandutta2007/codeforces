import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int MOD = 1000000007;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		
		boolean[] lit = new boolean[n];
		for (int i = 0; i < m; i++) {
			int pos = nextInt() - 1;
			lit[pos] = true;
		}
		
		int st2 = 0;
		
		ArrayList<Integer> lens = new ArrayList<>();
		
		for (int i = 0; i < n; ) {
			if (lit[i]) {
				i++;
				continue;
			}
			int j = i;
			while (j < n && !lit[j])
				j++;
			lens.add(j - i);
			if (i != 0 && j != n)
				st2 += j - i - 1;
			i = j;
		}
		
		int sum = n - m;
		
		
		
		int[] fact = new int[n + 1];
		int[] invFact = new int[n + 1];
		fact[0] = invFact[0] = 1;
		for (int i = 1; i <= n; i++) {
			fact[i] = (int)((long)fact[i - 1] * i % MOD);
			invFact[i] = pow(fact[i], MOD - 2);
		}
		
		
		
		int res = (int)((long)fact[sum] * pow(2, st2) % MOD);
		for (int x : lens)
			res = (int)((long)res * invFact[x] % MOD);
		
		out.println(res);
	}
	
	int pow(int a, int b) {
		int res = 1;
		while (b != 0) {
			if ((b & 1) == 1) {
				res = (int)((long)res * a % MOD);
			}
			a = (int)((long)a * a % MOD);
			b >>= 1;
		}
		return res;
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