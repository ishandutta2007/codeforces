import java.io.*;
import java.util.*;

public class F {

	static final String S = "GRB";

	long fast(int[] type, long[] xs) {
		int last = -1;
		int n = xs.length;
		long ret = 0;
		for (int i = 0; i < n; i++) {
			if (type[i] == 0) {
				if (last == -1) {
					ret += goTail(Arrays.copyOf(type, i), Arrays.copyOf(xs, i),
							xs[i]);
				} else {
					ret += goUsual(Arrays.copyOfRange(type, last + 1, i),
							Arrays.copyOfRange(xs, last + 1, i), xs[last],
							xs[i]);
				}

				last = i;
			}
		}

		if (last == -1) {
			ret = 0;
			for (int j = 1; j <= 2; j++) {
				long min = Long.MAX_VALUE;
				long max = Long.MIN_VALUE;
				for (int i = 0; i < xs.length; i++) {
					if (type[i] == j) {
						min = Math.min(min, xs[i]);
						max = Math.max(max, xs[i]);
					}
				}

				if (min <= max) {
					ret += max - min;
				}

			}
			return ret;
		}

		if (last != n - 1) {
			ret += goTail(reverse(Arrays.copyOfRange(type, last + 1, n)),
					reverseNegate(Arrays.copyOfRange(xs, last + 1, n)),
					-xs[last]);
		}

		return ret;
	}

	int[] reverse(int[] a) {
		int[] b = new int[a.length];
		for (int i = 0; i < b.length; i++) {
			b[i] = a[a.length - 1 - i];
		}
		return b;
	}

	long[] reverseNegate(long[] a) {
		long[] b = new long[a.length];
		for (int i = 0; i < b.length; i++) {
			b[i] = -a[a.length - 1 - i];
		}
		return b;
	}

	long goUsual(int[] type, long[] xs, long beg, long end) {
		long base = 2 * (end - beg);

		long other = 3 * (end - beg);

		for (int j = 1; j <= 2; j++) {
			long last = beg;
			long longest = 0;
			for (int i = 0; i < xs.length; i++) {
				if (type[i] == j) {
					longest = Math.max(longest, xs[i] - last);
					last = xs[i];
				}
			}

			longest = Math.max(longest, end - last);
			other -= longest;
		}

		return Math.min(base, other);
	}

	long goTail(int[] type, long[] xs, long end) {
		long ret = 0;
		for (int j = 1; j <= 2; j++) {
			for (int i = 0; i < type.length; i++) {
				if (type[i] == j) {
					ret += end - xs[i];
					break;
				}
			}
		}
		return ret;
	}

	void submit() {
		int n = nextInt();
		int[] type = new int[n];
		long[] xs = new long[n];
		for (int i = 0; i < n; i++) {
			xs[i] = nextInt();
			type[i] = S.indexOf(nextToken().charAt(0));
		}

		out.println(fast(type, xs));

	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	F() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new F();
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