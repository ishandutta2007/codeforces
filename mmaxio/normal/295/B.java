import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[][] a = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = nextInt();
			}
		}

		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			int v = nextInt() - 1;
			p[n - 1 - i] = v;
		}

		int[][] b = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				b[i][j] = a[p[i]][p[j]];
			}
		}
		
		long[] ans = new long[n];
		for (int k = 0; k < n; k++) {

			int[] bk = b[k];
			
			if (k != 0) {
				ans[k] = ans[k - 1];
				for (int i = 0; i < k; i++) {
					ans[k] += b[i][k] + bk[i];
				}
				ans[k] += bk[k];
			}


			
			for (int i = 0; i < n; i++) {
				int[] bi = b[i];
				for (int j = 0; j < n; j++) {
					int decr = bi[j] - bi[k] - bk[j];
					if (decr > 0) {
						bi[j] -= decr;
						if (i <= k && j <= k)
							ans[k] -= decr;
					}
				}
			}
		}
		
		for (int i = n - 1; i >= 0; i--) {
			out.print(ans[i] + " ");
		}

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