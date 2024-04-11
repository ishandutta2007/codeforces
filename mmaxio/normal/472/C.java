import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		String[][] a = new String[n][2];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				a[i][j] = nextToken();
			}
		}
		String[][] b = new String[n][2];
		for (int i = 0; i < n; i++) {
			int which = nextInt() - 1;
			b[i][0] = a[which][0];
			b[i][1] = a[which][1];
		}

		boolean[] can = { true, true };
		for (int i = 1; i < n; i++) {
			boolean[] next = new boolean[2];
			for (int j0 = 0; j0 < 2; j0++)
				for (int j1 = 0; j1 < 2; j1++) {
					next[j1] |= can[j0] && b[i - 1][j0].compareTo(b[i][j1]) < 0;
				}
			can = next;
		}
		out.println(can[0] || can[1] ? "YES" : "NO");
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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