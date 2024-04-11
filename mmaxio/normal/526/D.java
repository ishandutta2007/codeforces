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
		String s = nextToken();

		int[] pi = new int[s.length()];
		out.print(k == 1 ? '1' : '0');
		for (int i = 1, q = 0; i < s.length(); i++) {
			while (q > 0 && s.charAt(i) != s.charAt(q)) {
				q = pi[q - 1];
			}
			if (s.charAt(i) == s.charAt(q)) {
				q++;
			}
			pi[i] = q;
			int per = i + 1 - q;
//			System.err.println((i + 1) + " " + per);
			int ab = (i + 1) / per / k;
			int rest = i + 1 - ab * k * per;
			out.print(rest <= ab * per ? 1 : 0);
		}
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