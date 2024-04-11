import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	boolean train(char[][] f, int r, int c) {
		return r >= 0 && r < 3 && c < f[r].length && (f[r][c] >= 'A' && f[r][c] <= 'Z');
	}

	boolean solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		char[][] f = new char[3][];
		
		int stR = -1;
		
		for (int i = 0; i < 3; i++) {
			f[i] = nextToken().toCharArray();
			if (f[i][0] == 's') {
				stR = i;
			}
		}
		
		boolean[][] can = new boolean[3][n + 1];
		can[stR][0] = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				if (!can[j][i] || train(f, j, i + 2 * i) || train(f, j, i + 1 + 2 * i)) {
					continue;
				}
//				System.err.println(j + " " + i);
				for (int j1 = j - 1; j1 <= j + 1; j1++) {
					if (j1 >= 0 && j1 < 3 && !train(f, j1, i + 1 + 2 * i)) {
						can[j1][i + 1] = true;
					}
				}
			}
		}
		
		return can[0][n] || can[1][n] || can[2][n];
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		int t = nextInt();
		while (t-- > 0) {
			out.println(solve() ? "YES" : "NO");
		}
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