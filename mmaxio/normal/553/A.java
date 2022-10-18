import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int P = 1_000_000_007;

	void solve() throws IOException {
		int k = nextInt();
		int[] a = new int[k];
		int sum = 0;
		for (int i = 0; i < k; i++) {
			a[i] = nextInt();
			sum += a[i];
		}
		
		int[][] c = new int[1001][];
		for (int i = 0; i < c.length; i++) {
			c[i] = new int[i + 1];
			c[i][0] = c[i][i] = 1;
			for (int j = 1; j < i; j++) {
				c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % P;
			}
		}
		
		int ret = 1;
		for (int i = k - 1; i >= 0; i--) {
			ret = (int)((long)ret * c[sum - 1][a[i] - 1] % P);
			sum -= a[i];
		}
		
		out.println(ret);
		
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