import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		long n = nextLong();
		long m = nextLong();

		String a = nextToken();
		String b = nextToken();

		long mulAns = gcd(n, m);
		n /= mulAns;
		m /= mulAns;

		long len = (long) n * a.length();

		long gcd = gcd(a.length(), b.length());

		long eqPairs = 0;

		int[] cntA = new int[26];
		int[] cntB = new int[26];

		for (int rem = 0; rem < gcd; rem++) {
			Arrays.fill(cntA, 0);
			Arrays.fill(cntB, 0);
			for (int i = rem; i < a.length(); i += gcd) {
				cntA[a.charAt(i) - 'a']++;
			}
			for (int i = rem; i < b.length(); i += gcd) {
				cntB[b.charAt(i) - 'a']++;
			}

			for (int i = 0; i < 26; i++) {
				eqPairs += (long) cntA[i] * cntB[i];
			}
		}

		out.println(mulAns * (len - eqPairs));

	}

	static final long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
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