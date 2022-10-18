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
		
		if (m == n * (n - 1) / 2) {
			out.println("Yes");
			for (int i = 0; i < n; i++) {
				out.print("a");
			}
			out.println();
			return;
		}
		
		boolean[][] g = new boolean[n][n];
		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1][v2] = g[v2][v1] = true;
		}
		
		boolean[] isA = new boolean[n];
		boolean[] isC = new boolean[n];
		
		outer: for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				if (!g[i][j]) {
					
					
					
					for (int k = 0; k < n; k++) {
						if (i != k && !g[i][k]) {
							isA[k] = true;
						}
						if (j != k && !g[j][k]) {
							isC[k] = true;
						}
					}
					break outer;
					
				}
			}
		
//		System.err.println(Arrays.toString(isA));
//		System.err.println(Arrays.toString(isC));
		
		for (int i = 0; i < n; i++) {
			if (isA[i] && isC[i]) {
				out.println("No");
				return;
			}
		}
		
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				boolean shouldNotHave = (isA[i] && isC[j]) || (isA[j] && isC[i]);
				if (shouldNotHave == g[i][j]) {
					out.println("No");
					return;
				}
			}
		
		out.println("Yes");
		for (int i = 0; i < n; i++) {
			if (isA[i]) {
				out.print("a");
			} else if (isC[i]) {
				out.print("c");
			} else {
				out.print("b");
			}
		}
		
		out.println();
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