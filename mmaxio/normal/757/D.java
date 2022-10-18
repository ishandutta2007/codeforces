import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int P = 1_000_000_007;
	static final Random rng = new Random();
	
	String rand(int n) {
		char[] buf = new char[n];
		for (int i = 0; i < n; i++) {
			buf[i] = (char)('0' + rng.nextInt(2));
		}
		return new String(buf);
	}
	
	String concat(int n) {
		String ret = "";
		for (int x = 1; x <= 20; x++) {
			ret += Integer.toBinaryString(x);
		}
		return ret + "1";
	}

	void solve() throws IOException {
		int n = nextInt();
		String ss = nextToken();
		
//		int n = 75;
//		String ss = concat(20);
//		System.err.println(ss.length());
		
		int[] s = new int[n];
		for (int i = 0; i < n; i++) {
			s[i] = ss.charAt(i) - '0';
		}
		
		int[][] dp = new int[n + 1][1 << 20];
		
		for (int i = 0; i <= n; i++) {
			dp[i][0] = 1;
		}
		
		int ans = 0;
		
		for (int pos = 0; pos <= n; pos++) {
			for (int mask = 0; mask < (1 << 20); mask++) {
				
				int delta = dp[pos][mask];
				if (delta == 0) {
					continue;
				}
//				System.err.println(pos + " " + mask + "->" + delta);
				
				if (mask != 0 && (mask & (mask + 1)) == 0) {
					
//					System.err.println(pos + " " + mask + "->" + delta);
					
					ans += delta;
					if (ans >= P) {
						ans -= P;
					}
				}
				
				int cur = 0;
				
				for (int to = pos + 1; to <= n; to++) {
					cur = (cur << 1) + s[to - 1];
					if (cur > 20) {
						break;
					}
					if (cur != 0) {
						int newMask = mask | (1 << (cur - 1));
						
						int newVal = dp[to][newMask] + delta;
						if (newVal >= P) {
							newVal -= P;
						}
						
						dp[to][newMask] = newVal;
					}
				}
			}
		}
		
		out.println(ans);
		
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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