import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();

		char[][] f = new char[n][];
		for (int i = 0; i < n; i++) {
			f[i] = nextToken().toCharArray();
		}

		everyRow: do {
			int[] ans = new int[n];

			row: for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (f[i][j] == '.') {
						ans[i] = j;
						continue row;
					}
				}
				break everyRow;
			}

			for (int i = 0; i < n; i++) {
				out.println((i + 1) + " " + (ans[i] + 1));
			}
			return;
		} while (false);

		everyCol: do {
			int[] ans = new int[n];

			col: for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (f[j][i] == '.') {
						ans[i] = j;
						continue col;
					}
				}
				break everyCol;
			}

			for (int i = 0; i < n; i++) {
				out.println((ans[i] + 1) + " " + (i + 1));
			}
			return;
		} while (false);
		
		out.println(-1);

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