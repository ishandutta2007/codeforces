import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		double[] p = new double[1026];
		p[0] = 1;
		double ans = 0;
		double here = 1.0 / k;
		for (int i = 0; i < n; i++) {
			for (int j = Math.min(i, 1024); j >= 0; j--) {
				double succ = here / (j + 2);
//				System.err.println(succ);
				ans += p[j] * (succ * (j + 1) + (here - succ) * 0.5 * (j + 2));
//				System.err.println(ans);
				p[j + 1] += p[j] * succ;
				p[j] *= 1 - succ;
			}
		}
		ans *= k;
		out.printf(Locale.US, "%.12f\n", ans);
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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