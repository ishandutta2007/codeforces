import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[][] a = new int[5][5];
	int ans = -1;

	boolean[] use = new boolean[5];
	int[] p = new int[5];

	void check() {
		int val = a[p[0]][p[1]] + a[p[2]][p[3]] + a[p[1]][p[2]] + a[p[3]][p[4]]
				+ a[p[2]][p[3]] + a[p[3]][p[4]];
		ans = Math.max(ans, val);
	}

	void go(int pos) {
		if (pos == 5) {
			check();
			return;
		}
		for (int i = 0; i < 5; i++) {
			if (!use[i]) {
				p[pos] = i;
				use[i] = true;
				go(pos + 1);
				use[i] = false;
			}
		}
	}

	void solve() throws IOException {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++) {
				a[i][j] = nextInt();
			}

		for (int i = 0; i < 5; i++)
			for (int j = 0; j < i; j++) {
				a[i][j] = a[j][i] = a[i][j] + a[j][i];
			}

		go(0);
		out.println(ans);
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