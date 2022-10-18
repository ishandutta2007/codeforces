import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		int[] ans = new int[m];
		for (int i = 0; i < n; i++) {
			char[] f = nextToken().toCharArray();
			for (int j = 0; j < m; j++) {
				if (f[j] == 'L') {
					int tmp = j - i;
					if (tmp >= 0 && tmp < m) {
						ans[tmp]++;
					}
				} else if (f[j] == 'R') {
					int tmp = j + i;
					if (tmp >= 0 && tmp < m) {
						ans[tmp]++;
					}
				} else if (f[j] == 'U') {
					if (i % 2 == 0) {
						ans[j]++;
					}
				}
			}
		}
		
		for (int x : ans) {
			out.print(x + " " );
		}
		out.println();
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