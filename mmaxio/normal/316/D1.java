import java.io.*;
import java.util.*;

public class cfABBYYCup3D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int MOD = 1000000007;

	void solve() throws IOException {
		int n = nextInt();
		String s = br.readLine();
		
		int one = 0;
		int two = 0;
		for (int i = 0; i < s.length(); i += 2) {
			if (s.charAt(i) == '1')
				one++;
			else
				two++;
		}
		
		int res = 1;
		if (one > 1) {
			int a = 1;
			int b = 1;
			for (int i = 2; i <= one; i++) {
				int next = (int)((long)a * (i - 1) % MOD);
				next += b;
				if (next >= MOD)
					next -= MOD;
				a = b;
				b = next;
			}
			res = b;
		}
		
		for (int i = one + 1; i <= one + two; i++)
			res = (int)((long)res * i % MOD);
		
		out.println(res);
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new cfABBYYCup3D().inp();
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