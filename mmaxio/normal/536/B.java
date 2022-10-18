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
		String p = nextToken();
		int[] pi = new int[p.length()];
		for (int i = 1, q = 0; i < p.length(); i++) {
			while (q > 0 && p.charAt(i) != p.charAt(q)) {
				q = pi[q - 1];
			}
			if (p.charAt(i) == p.charAt(q)) {
				q++;
			}
			pi[i] = q;
		}
		boolean[] good = new boolean[p.length()];
		for (int q = pi[p.length() - 1]; q != 0; q = pi[q - 1]) {
			good[q] = true;
		}
		int[] occ = new int[m];
		for (int i = 0; i < m; i++) {
			occ[i] = nextInt() - 1;
		}
		for (int i = 0; i < m - 1; i++) {
			int diff = occ[i + 1] - occ[i];
			if (diff < p.length() && !good[p.length() - diff]) {
				out.println(0);
				return;
			}
		}
		int ret = 1;
		int P = 1_000_000_007;
		for (int i = 0, j = 0, last = -1; i < n; i++) {
			if (j < m && i == occ[j]) {
				last = i;
				j++;
			}
//			System.err.println(i + " " + last);
			if (last == -1 || i - last >= p.length()) {
				ret = (int) (26L * ret % P);
			}
		}
		out.println(ret);
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