import java.io.*;
import java.util.*;

public class D_opt3 {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int n;
	int dn1;
	int m;

	long solve() {
		long start = System.currentTimeMillis();
		dn1 = (n + 1) * 2;
		long ans = 0;
		for (int i = 2 * (m + 1); i <= n + 1; i += 2) {
			int shiftI = (i == n + 1) ? 0 : 1;

			int tmp = dn1 - i;
			int num = (i - (m + 1)) * tmp - 1;
			int denom = i + (m + 1) * 2;
			

			
			for (int j = m + 1; j < i; j++, num -= tmp, denom += 2) {

				int k = num / denom;
				if (k >= n - m)
					k = n - m;
				if (k >= m)
					ans += (k - m) << shiftI;
			}
		}

//		System.err.println(System.currentTimeMillis() - start);
		return 3 * ans;
	}

	D_opt3() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		n = nextInt();
		m = nextInt();
		out.println(solve());
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D_opt3();
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