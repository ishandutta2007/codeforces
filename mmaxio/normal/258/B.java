import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int MOD = 1_000_000_007;
	
	static final int[] POW2 = new int[10];
	static final int[] POW8 = new int[10];
	{
		POW2[0] = POW8[0] = 1;
		for (int i = 1; i < 10; i++) {
			POW2[i] = POW2[i - 1] * 2;
			POW8[i] = POW8[i - 1] * 8;
		}
	}
	
	static final int[][] c = new int[10][];
	{
		for (int i = 0; i < c.length; i++) {
			c[i] = new int[i + 1];
			c[i][0] = c[i][i] = 1;
			for (int j = 1; j < i; j++)
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	
	int[] getCnt(int m) {
		m++;
		int[] res = new int[10];
		char[] x = Integer.toString(m).toCharArray();
		int prefLucky = 0;
		for (int i = 0; i < x.length; i++) {
			int dig = x[i] - '0';
			for (int j = 0; j < dig; j++) {
				int curLucky = prefLucky + (isLucky(j) ? 1 : 0);
				int sufLen = x.length - 1 - i;
				
				for (int k = 0; k <= sufLen; k++) {
					res[curLucky + k] += c[sufLen][k] * POW2[k] * POW8[sufLen - k];
				}
				
			}
			prefLucky += (isLucky(dig) ? 1 : 0);
		}
		res[0]--; // no zero
		return res;
	}

	boolean isLucky(int j) {
		return j == 4 || j == 7;
	}
	
	int[] cnt;
	
	int[] cntPicked = new int[10];
	
	int go(int left, int i) {
		if (i == 6) {
			if (left == 0) {
				int res = 1;
				for (int j = 0; j < 10; j++) {
					if (cntPicked[j] > cnt[j])
						return 0;
					for (int k = cnt[j]; k > cnt[j] - cntPicked[j]; k--)
						res = (int)((long)res * k % MOD);
				}
				return res;
			}
			return 0;
		}
		int res = 0;
		for (int j = 0; j <= left; j++) {
			cntPicked[j]++;
			res += go(left - j, i + 1);
			if (res >= MOD)
				res -= MOD;
			cntPicked[j]--;
		}
		return res;
	}

	void solve() throws IOException {
		int m = nextInt();
		cnt = getCnt(m);
		
		System.err.println(Arrays.toString(cnt));
		
		int[] res = new int[cnt.length];
		for (int i = 0; i < cnt.length; i++)
			res[i] = go(i, 0);
		
		int sum = 0;
		
		int ans = 0;
		
		for (int i = 1; i < cnt.length; i++) {
			sum += res[i - 1];
			if (sum >= MOD)
				sum -= MOD;
			ans += (int)((long)sum * cnt[i] % MOD);
			if (ans >= MOD)
				ans -= MOD;
		}
		
		out.println(ans);
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