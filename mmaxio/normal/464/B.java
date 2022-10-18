import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int[][] P = { { 0, 1, 2 }, { 0, 2, 1 }, { 1, 0, 2 },
			{ 1, 2, 0 }, { 2, 0, 1 }, { 2, 1, 0 } };

	long f(int[] a, int[] b) {
		long ret = 0;
		for (int i = 0; i < 3; i++) {
			ret += (long) (b[i] - a[i]) * (b[i] - a[i]);
		}
		return ret;
	}

	static final int[] M = { 0, 1, 1, 1, 2, 2, 2, 3 };

	boolean check(int[][] x) {
		long[] d = new long[8];
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				d[j] = f(x[i], x[j]);
			}
			Arrays.sort(d);
			long base = d[1];
			if (base == 0) {
				return false;
			}
			for (int j = 0; j < 8; j++) {
				if (d[j] != base * M[j]) {
					return false;
				}
			}
		}
		return true;
	}

	void solve() throws IOException {
		int[][] a = new int[8][3];
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 3; j++) {
				a[i][j] = nextInt();
			}
		}
		int[][] b = new int[8][3];
		b[0] = a[0].clone();
		for (int X = 0; X < 279936; X++) {
			int tmp = X;
			for (int i = 1; i < 8; i++) {
				int[] perm = P[tmp % 6];
				tmp /= 6;
				for (int k = 0; k < 3; k++) {
					b[i][k] = a[i][perm[k]];
				}
			}
			if (check(b)) {
				out.println("YES");
				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 3; j++) {
						out.print(b[i][j] + " ");
					}
					out.println();
				}
				return;
			}
		}
		out.println("NO");
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