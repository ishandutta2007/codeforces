import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final Random rng = new Random();

	static final int M1 = BigInteger.probablePrime(30, rng).intValue();
	static final int M2 = BigInteger.probablePrime(30, rng).intValue();
	static final int LEN = 1500000;
	static final int[] P1 = new int[LEN + 1];
	static final int[] P2 = new int[LEN + 1];
	static {
		P1[0] = P2[0] = 1;
		for (int i = 1; i < P1.length; i++) {
			P1[i] = (int) (31L * P1[i - 1] % M1);
			P2[i] = (int) (31L * P2[i - 1] % M2);
		}
	}

	int[] h1, h2;

	int getHash(int[] h, int[] p, int mod, int l, int r) {
		int ret = h[r] - (int) ((long) h[l] * p[r - l] % mod);
		if (ret < 0) {
			ret += mod;
		}
		return ret;
	}

	boolean check(char[] s, int lenA, int lenB, int[] h1, int[] h2) {
		// assuming lenA and lenB are consistent with array lengths
		int hA1 = -1, hA2 = -1, hB1 = -1, hB2 = -1;
		int j = 0;
		for (int i = 0; i < s.length; i++) {
			if (s[i] == '0') {
				int cur1 = getHash(h1, P1, M1, j, j + lenA);
				int cur2 = getHash(h2, P2, M2, j, j + lenA);
				if (hA1 == -1) {
					hA1 = cur1;
					hA2 = cur2;
				} else {
					if (hA1 != cur1 || hA2 != cur2) {
						return false;
					}
				}
				j += lenA;
			} else {
				int cur1 = getHash(h1, P1, M1, j, j + lenB);
				int cur2 = getHash(h2, P2, M2, j, j + lenB);
				if (hB1 == -1) {
					hB1 = cur1;
					hB2 = cur2;
				} else {
					if (hB1 != cur1 || hB2 != cur2) {
						return false;
					}
				}
				j += lenB;
			}
		}
		if (j + 1 != h1.length) {
			throw new AssertionError();
		}
		if (hA1 == hB1 && hA2 == hB2 && lenA == lenB) {
			return false;
		}
		return true;
	}

	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	void solve() throws IOException {
		char[] s = nextToken().toCharArray();
		String t = nextToken();
		int n = t.length();
		h1 = new int[n + 1];
		h2 = new int[n + 1];
		for (int i = 0; i < n; i++) {
			h1[i + 1] = (int) ((31L * h1[i] + t.charAt(i) - 'a' + 1) % M1);
			h2[i + 1] = (int) ((31L * h2[i] + t.charAt(i) - 'a' + 1) % M2);
		}
		int a = 0, b = 0;
		for (int i = 0; i < s.length; i++) {
			if (s[i] == '0') {
				a++;
			} else {
				b++;
			}
		}

		int outp = 0;

		for (int lenA = 1;; lenA++) {
			long left = n - (long) a * lenA;
			if (left <= 0) {
				break;
			}
			if (left % b != 0) {
				continue;
			}
			int lenB = (int) (left / b);
			if (check(s, lenA, lenB, h1, h2)) {
				outp++;
			}
		}
		out.println(outp);
	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E();
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