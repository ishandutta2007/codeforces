import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	long[][] c = new long[64][];
	{
		for (int i = 0; i < 64; i++) {
			c[i] = new long[i + 1];
			c[i][0] = c[i][i] = 1;
			for (int j = 1; j < i; j++) {
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			}
		}
	}

	long C(int n, int k) {
		return n < 0 || k < 0 || k > n ? 0 : c[n][k];
	}

	long solve() throws IOException {
		long m = nextLong();
		int k = nextInt();
		if (k == 1) {
			if (m != 1) {
				throw new AssertionError();
			}
			return 1;
		}
		if (k > 60) {
			if (m == 0) {
				return 1;
			}
			throw new AssertionError();
		}
		

		for (int nLen = 1; nLen <= 60; nLen++) {
			long rest = m - C(nLen - 1, k - 1);
			
			long have = C(nLen - 1, k - 2);
			if (nLen == k - 1) {
				have--;
			}
			if (rest >= 0 && rest <= have) {
				// System.err.println(nLen + " " + rest + " " + have);
				if (rest == 0) {
					return (1L << (nLen - 1));
				}
				return (1L << (nLen - 1)) + get(rest - 1, k - 2) + 1;
			}
		}
		throw new AssertionError();
	}

	long get(long num, int k) {
		if (k == 0) {
			if (num != 0) {
				throw new AssertionError();
			}
			return 0;
		}
		int len = 0;
		do {
			len++;
			long cur = C(len - 1, k - 1);
			if (num < cur) {
				break;
			} else {
				num -= cur;
			}
		} while (true);
		long res = 1L << (len - 1);
		k--;
		
		for (int bit = len - 2; bit >= 0; bit--) {
			if (num >= C(bit, k)) {
				res |= 1L << bit;
				num -= C(bit, k);
				k--;
			}
		}
		return res;
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		out.println(solve());
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