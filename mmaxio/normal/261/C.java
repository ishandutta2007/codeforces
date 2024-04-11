import java.io.*;
import java.util.*;

public class C_submit {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static long[][] c = new long[61][];
	static {
		for (int i = 0; i < c.length; i++) {
			c[i] = new long[i + 1];
			c[i][0] = c[i][i] = 1;
			for (int j = 1; j < i; j++)
				c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
	
	long c(int n, int k) {
		return n < 0 || k < 0 || k > n ? 0 : c[n][k];
	}
	
	void solve() throws IOException {
		long n = nextLong();
		long t = nextLong();
		if (Long.bitCount(t) != 1) {
			out.println(0);
			return;
		}
		
		int need = Long.numberOfTrailingZeros(t) + 1;
		
		// return numbers of x : 2 <= x <= n + 1, bitcount(x) = need
		
		n += 2;
		
		String s = Long.toBinaryString(n);
		
		int prefBitCnt = 0;
		
		long ans = 0;
		
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '1') {
				int sufLen = s.length() - i - 1;
				ans += c(sufLen, need - prefBitCnt);
				prefBitCnt++;
			}
		}
		
		if (need == 1)
			ans--;
		
		out.println(ans);
	}

	C_submit() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C_submit();
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