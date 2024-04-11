import java.io.*;
import java.util.*;

public class E {

	static final int MAX_B = 11;
	static final int MAX_LEN = 70;

	long go(int base, long x) {
		char[] s = Long.toString(x, base).toCharArray();

		long ret = 0;

		for (int len = 1; len < s.length; len++) {
			ret += (base - 1) * f[base][len - 1][1];
		}

		int maskOdd = 0;

		for (int i = 0; i < s.length; i++) {
			int dig = s[i] - '0';

			int from = i == 0 ? 1 : 0;

			for (int j = from; j < dig; j++) {
				maskOdd ^= (1 << j);
				ret += f[base][s.length - 1 - i][Integer.bitCount(maskOdd)];
				maskOdd ^= (1 << j);
			}

			maskOdd ^= (1 << dig);
		}

		return ret;
	}

	void submit() {
		int q = nextInt();
		while (q-- > 0) {
			int b = nextInt();
			long l = nextLong();
			long r = nextLong();
			out.println(go(b, r + 1) - go(b, l));
		}
	}

	long[][][] f;

	void preCalc() {
		f = new long[MAX_B][MAX_LEN][];
		for (int base = 2; base < MAX_B; base++) {

			for (int len = 0; len < MAX_LEN; len++) {

				f[base][len] = new long[base + 1];
				if (len == 0) {
					f[base][len][0] = 1;
					continue;
				}

				for (int odd = 0; odd <= base; odd++) {
					if (odd > 0) {
						f[base][len][odd] += f[base][len - 1][odd - 1] * odd;
					}
					if (odd < base) {
						f[base][len][odd] += f[base][len - 1][odd + 1]
								* (base - odd);
					}
				}
			}
		}
	}

	void stress() {

	}

	void test() {
		System.err.println(go(2, 3));
	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		 submit();
		// stress();
//		test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new E();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}