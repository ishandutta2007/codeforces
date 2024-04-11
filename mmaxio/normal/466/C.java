import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		long[] p = new long[n + 1];
		for (int i = 0; i < n; i++) {
			p[i + 1] = p[i] + nextInt();
		}
		if (p[n] % 3 != 0) {
			out.println(0);
			return;
		}
		long v1 = p[n] / 3;
		long v2 = v1 * 2;
		long ans = 0;
		int cnt2 = 0;
		for (int i = n - 1; i >= 1; i--) {
			if (p[i] == v1) {
				ans += cnt2;
			}
			if (p[i] == v2) {
				cnt2++;
			}
		}
		out.println(ans);
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