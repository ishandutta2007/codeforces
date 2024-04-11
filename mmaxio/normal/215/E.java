import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	long go2(char[] s, int fix, int per) {
		int cntFree = 0;
		for (int rem = 0; rem < per; rem++) {
			boolean has0 = false;
			boolean has1 = false;
			for (int i = rem; i < fix; i += per) {
				has0 |= (s[i] == '0');
				has1 |= (s[i] == '1');
			}
			if (has0 && has1)
				return 0;
			if (!has0 && !has1)
				cntFree++;
		}
		return 1L << cntFree;
	}
	
	long go(char[] s, int fix) {
		long[] dp = new long[s.length];
		long res = 0;
		for (int per = 1; per < s.length; per++)
			if (s.length % per == 0) {
				dp[per] = go2(s, fix, per);
				for (int lessPer = 1; lessPer < per; lessPer++)
					if (per % lessPer == 0)
						dp[per] -= dp[lessPer];
				res += dp[per];
			}
		return res;
	}
	
	long f(long x) {
		
		long res = 0;
		
		char[] s = Long.toBinaryString(x).toCharArray();
		for (int i = 1; i < s.length; i++) {
			char[] tmp = new char[i];
			tmp[0] = '1';
			res += go(tmp, 1);
		}
		
		for (int i = 1; i < s.length; i++)
			if (s[i] == '1') {
				s[i] = '0';
				res += go(s, i + 1);
				s[i] = '1';
			}
		
		return res;
	}

	void solve() throws IOException {
		long l = nextLong();
		long r = nextLong();
		
		out.println(f(r + 1) - f(l));
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E().inp();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	String nextString() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken("\n");
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