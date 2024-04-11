import java.io.*;
import java.util.*;

public class D_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int FAST_THRESHOLD = 6;
	static final int INF = Integer.MAX_VALUE / 2;

	static int shortestTandem(String s, int bound) {
		String rev = new StringBuilder(s).reverse().toString();
		return shortestTandem(s, rev, bound);
	}

	static int shortestTandem(String s, String rev, int bound) {

		if (s.length() < FAST_THRESHOLD) {
			for (int len = bound; len * 2 <= s.length(); len++) {
				for (int i = len; i <= s.length() - len; i++) {
					if (s.substring(i - len, i).equals(s.substring(i, i + len))) {
						return len;
					}
				}
			}
			return INF;
		}
		
		int n = s.length();
		int lenL = n / 2;
		int lenR = n - lenL;
		String left = s.substring(0, lenL);
		String right = s.substring(lenL);
		String leftRev = rev.substring(lenR);
		String rightRev = rev.substring(0, lenR);

		int ret = Math.min(shortestTandem(left, leftRev, bound),
				shortestTandem(right, rightRev, bound));

		int[] z1 = zFunc(right + left);
		int[] z2 = zFunc(leftRev + rightRev);
		// left
		for (int len = bound; len < ret && len <= lenL; len++) {
			int forw = Math.min(len, z1[n - len]);
			int back = Math.min(z2[len], Math.min(lenL - len, len));

			if (forw > 0 && forw + back >= len) {
				ret = len;
				break;
			}
		}

		// right
		for (int len = bound; len < ret && len <= lenR; len++) {
			int forw = Math.min(z1[len], Math.min(len, lenR - len));
			int back = Math.min(len, z2[n - len]);
			if (back > 0 && forw + back >= len) {
				ret = len;
				break;
			}
		}

		return ret;
	}

	static int[] zFunc(String s) {
		int n = s.length();
		int[] z = new int[n];
		for (int i = 1, l = 0, r = 0; i < n; i++) {
			int val = i < r ? Math.min(r - i, z[i - l]) : 0;
			while (i + val < n && s.charAt(val) == s.charAt(i + val))
				val++;
			if (i + val > r) {
				l = i;
				r = i + val;
			}
			z[i] = val;
		}
		return z;
	}

	static String solve(String s) {
		int prevLen = 0;
		while (true) {
			int len = shortestTandem(s, prevLen + 1);
//			System.err.println(s + " " + len);
			if (len == INF) {
				break;
			}
			prevLen = len;
			StringBuilder sb = new StringBuilder();
			int same = 0;
			for (int i = 0; i < s.length(); i++) {
				sb.append(s.charAt(i));
				if (sb.length() > len
						&& sb.charAt(sb.length() - 1) == sb.charAt(sb.length()
								- len - 1))
					same++;
				else
					same = 0;
				if (same == len) {
					sb.setLength(sb.length() - len);
					same = 0;
				}
			}
			s = sb.toString();
		}
		return s;
	}

	void solve() throws IOException {
		String s = br.readLine();
		out.println(solve(s));
	}

	D_new() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);

		out.println(solve(br.readLine()));

		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D_new();
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