import java.io.*;
import java.util.*;

public class E {

	static final int BASE = 16;

	void submit() {
		String s = nextToken();
		int len = s.length();
		int[] x = new int[s.length()];
		int sumD = 0;
		for (int i = 0; i < x.length; i++) {
			x[x.length - 1 - i] = Integer.parseInt(s.substring(i, i + 1), BASE);
			sumD += x[x.length - 1 - i];
		}

		if (sumD % (BASE - 1) != 0) {
			out.println("NO");
			return;
		}
		int carries = sumD / (BASE - 1);
		if (carries >= len) {
			out.println("NO");
			return;
		}

		int[] carPos = new int[carries];
		for (int i = 0; i < carries; i++) {
			carPos[i] = i;
		}

		long ans = Long.MAX_VALUE;

		do {
			ans = Math.min(ans, go(carPos, x));
		} while (nextCombination(carPos, len - 1));

		if (ans == Long.MAX_VALUE) {
			out.println("NO");
		} else {
			String ret = Long.toHexString(ans);
			while (ret.length() < len) {
				ret = "0" + ret;
			}
			out.println(ret);
		}
	}

	long go(int[] carries, int[] diff) {
		boolean[] isCarry = new boolean[diff.length];
		for (int pos : carries) {
			isCarry[pos] = true;
		}

		int n = diff.length;
		long[] dp = new long[1 << n];
		int[] nextDigit = new int[1 << n];
		Arrays.fill(dp, Long.MAX_VALUE);
		for (int i = 0; i < n; i++) {
			int digHere = getNextDigit(i, 0, isCarry, diff);
			if (digHere != -1) {
				dp[1 << i] = 0;
				nextDigit[1 << i] = digHere;
			}
		}

		for (int mask = 1; mask < (1 << n); mask++) {
			if (dp[mask] == Long.MAX_VALUE) {
				continue;
			}
			for (int i = 0; i < n; i++) {
				if (test(mask, i)) {
					continue;
				}
				int prevDig = nextDigit[mask];
				int nextDig = getNextDigit(i, nextDigit[mask], isCarry, diff);
				if (nextDig != -1) {
					// hardcoded base 16 here :(
					dp[mask | (1 << i)] = Math.min(dp[mask | (1 << i)], dp[mask] + (((long) prevDig) << (4 * i)));
					nextDigit[mask | (1 << i)] = nextDig;
				}
			}
		}

		return dp[(1 << n) - 1];
	}

	boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	int getNextDigit(int pos, int prev, boolean[] isCarry, int[] diff) {
		int nextVal = prev + diff[pos]
				+ (pos == 0 || !isCarry[pos - 1] ? 0 : 1);
		if ((nextVal >= BASE) != isCarry[pos]) {
			return -1;
		}
		return nextVal >= BASE ? nextVal - BASE : nextVal;
	}

	boolean nextCombination(int[] a, int n) {
		int k = a.length;
		int ptr = k - 1;
		while (ptr >= 0 && a[ptr] == ptr - k + n) {
			ptr--;
		}
		if (ptr < 0) {
			return false;
		}
		a[ptr]++;
		for (int i = ptr + 1; i < k; i++) {
			a[i] = a[ptr] + i - ptr;
		}
		return true;
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	E() throws IOException {
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