import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[] p = new int[n];
		
		boolean[] hasIn = new boolean[n];
		
		for (int i = 0; i < n; i++) {
			p[i] = nextInt() - 1;
			hasIn[p[i]] = true;
		}
		
		for (boolean b : hasIn) {
			if (!b) {
				out.println(-1);
				return;
			}
		}
		
		long ans = 1;
		
		boolean[] vis = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (vis[i]) {
				continue;
			}
			
			vis[i] = true;
			int len = 1;
			for (int j = p[i]; !vis[j]; j = p[j]) {
				vis[j] = true;
				len++;
			}
			
			if (len % 2 == 0) {
				len /= 2;
			}
			
			ans = lcm(ans, len);
		}
		
		out.println(ans);
	}
	
	long lcm(long a, long b) {
		return a / gcd(a, b) * b;
	}
	
	long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}

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