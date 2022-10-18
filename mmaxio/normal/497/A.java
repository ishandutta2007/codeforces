import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		
		int m = nextInt();
		char[][] f = new char[n][];
		for (int i = 0; i < n; i++) {
			f[i] = nextToken().toCharArray();
		}
		int ret = 0;
		
		boolean[] arb = new boolean[n - 1];
		
		for (int j = 0; j < m; j++) {
			boolean good = true;
			for (int i = 0; i < n - 1; i++) {
				if (!arb[i] && f[i][j] > f[i + 1][j]) {
					good = false;
					break;
				}
			}
			if (!good) {
				ret++;
			} else {
				for (int i = 0; i < n - 1; i++) {
					if (f[i][j] < f[i + 1][j]) {
						arb[i] = true;
					}
				}
			}
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