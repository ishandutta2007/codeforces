import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class FastKnapsack {

	int simplerKnapsack(int[] w, int C) {
		boolean[] can = new boolean[C + 1];
		can[0] = true;
		for (int x : w) {
			for (int i = C - x; i >= 0; i--) {
				can[i + x] |= can[i];
			}
		}
		int ans = C;
		while (!can[ans]) {
			ans--;
		}
		return ans;
	}

	/**
	 * Returns the biggest sum <= C you can get if you multiply each number from w by either 0 or 1.
	 * All numbers in w[] must be non-negative.
	 * O(max(w) * len(w)) time, O(max(w)) memory.
	 * 
	 * TODO: implement a version that returns the certificate(this will need O(max(w) * len(w)) memory(unless?))
	 * TODO: implement a "weight/cost" version, it'd have O(max(w) * max(cost) * len(w)) complexity.
	 * Which is pretty good if all costs are small? Even though the naive algorithm doesn't care about costs. 
	 * 
	 *  @author https://codeforces.com/blog/entry/99883?#comment-886765 Elegia
	 *  @author "Linear Time Algorithms for Knapsack Problems with Bounded Weights" by David Pisinger
	 *  
	 */
	int fast01Knapsack(int[] w, int C) {
		int n = w.length;
		int base = 0;
		int stop = -1;
		int maxW = 0;
		for (int i = 0; i < n; i++) {
			if (w[i] < 0) {
				throw new AssertionError("w < 0");
			}
			if (w[i] == C) {
				return C;
			}
			if (w[i] == 0 || w[i] > C) {
				continue;
			}
			maxW = Math.max(maxW, w[i]);
			if (stop < 0) {
				if (base + w[i] > C) {
					stop = i;
				} else {
					base += w[i];
				}
			}
		}

		if (stop < 0 || base == C) {
			return base;
		}

		// [C - maxW; C + maxW]
		int[] dp = new int[2 * maxW + 1];
		int[] oldDp = new int[2 * maxW + 1];
		Arrays.fill(dp, stop + 1);
		dp[base - (C - maxW)] = 0;

		for (int i = stop; i < n; i++) {
			int x = w[i];
			if (x == 0 || x > C) {
				continue;
			}
			if (dp[maxW] != stop + 1) {
				return C;
			}
			// add x
			for (int j = maxW - 1; j >= 0; j--) {
				oldDp[j + x] = dp[j + x];
				dp[j + x] = Math.min(dp[j + x], dp[j]);
			}
			
			// remove items that are over C
			//
			// Namely, use the transitions that were "unlocked" during the loop above.
			// (that's why we need oldDp)
			//
			// we might have to remove more than one item, so iterate in descending order
			for (int j = maxW - 1 + x; j > maxW; j--) {
				// this "k < stop" condition is pretty funny
				// it should be actually present because the items starting from "stop"
				// aren't in the base solution and hence can't be removed.
				// BUT it doesn't matter if we use k == stop transition
				// since it would relax some dp state with "stop + 1" which means impossible.
				for (int k = dp[j]; k < oldDp[j] && k < stop; k++) {
					if (w[k] == 0 || w[k] > C) {
						continue;
					}
					dp[j - w[k]] = Math.min(dp[j - w[k]], k + 1);
				}
			}
		}

		int ret = maxW;
		while (dp[ret] == stop + 1) {
			ret--;
		}

		return C - maxW + ret;
	}

	void submit() {
		int t = nextInt();
		while (t-- > 0) {
			int n = nextInt();
			int[] a = new int[n];
			long ret = 0;
			int diff = 0;
			int low = 0;
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
				ret += a[i] * a[i];
			}
			int[] b = new int[n];
			for (int i = 0; i < n; i++) {
				int x = nextInt();
				ret += x * x;
				b[i] = Math.abs(a[i] - x);
				low += Math.min(a[i], x);
				diff += b[i];
			}
			ret *= (n - 2);
			int best = fast01Knapsack(b, diff / 2);
			out.println(ret + (low + best) * (low + best) + (low + diff - best) * (low + diff - best));
		}
	}

	void test() {
		System.err.println(fast01Knapsack(new int[] { 3, 1, 3 }, 5));
	}

	void stress() {
		for (int tst = 0;; tst++) {
			int n = rand(1, C);
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = rand(1, C);
			}
			int b = rand(1, C);
			if (fast01Knapsack(a, b) != simplerKnapsack(a, b)) {
				System.err.println(Arrays.toString(a) + " " + b);
				System.err.println(fast01Knapsack(a, b) + " " + simplerKnapsack(a, b));
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	FastKnapsack() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		submit();
//		 stress();
//		test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 5;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new FastKnapsack();
	}

	private InputStream is;
	PrintWriter out;

	private byte[] buf = new byte[1 << 14];
	private int bufSz = 0, bufPtr = 0;

	private int readByte() {
		if (bufSz == -1)
			throw new RuntimeException("Reading past EOF");
		if (bufPtr >= bufSz) {
			bufPtr = 0;
			try {
				bufSz = is.read(buf);
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			if (bufSz <= 0)
				return -1;
		}
		return buf[bufPtr++];
	}

	private boolean isTrash(int c) {
		return c < 33 || c > 126;
	}

	private int skip() {
		int b;
		while ((b = readByte()) != -1 && isTrash(b))
			;
		return b;
	}

	String nextToken() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	String nextString() {
		int b = readByte();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b) || b == ' ') {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	char nextChar() {
		return (char) skip();
	}

	int nextInt() {
		int ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}

	long nextLong() {
		long ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}
}