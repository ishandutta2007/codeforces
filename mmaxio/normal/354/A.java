import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int l = nextInt();
		int r = nextInt();
		int ql = nextInt();
		int qr = nextInt();
		int[] w = new int[n];

		int sumR = 0;
		int sumL = 0;

		for (int i = 0; i < n; i++) {
			w[i] = nextInt();
			sumR += w[i];
		}

		long ans = (long) sumR * r + (long) qr * (n - 1);

		for (int i = 0; i < n; i++) {
			sumR -= w[i];
			sumL += w[i];
			int cntL = i + 1;
			int cntR = n - cntL;

			long val = (long) sumL * l + (long) sumR * r;
			// System.err.println(cntL + " " + cntR + " " + val);
			if (cntL - cntR >= 2) {
				val += (long) (cntL - cntR - 1) * ql;
			}
			if (cntR - cntL >= 2) {
				val += (long) (cntR - cntL - 1) * qr;
			}

			ans = Math.min(ans, val);
		}

		out.println(ans);
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