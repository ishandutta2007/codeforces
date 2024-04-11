import java.io.*;
import java.util.*;

public class F {

	long[][] ways;

	static class Half implements Comparable<Half> {
		long match;
		long value;

		public Half(long match, long value) {
			this.match = match;
			this.value = value;
		}

		@Override
		public int compareTo(Half o) {
			return Long.compare(value, o.value);
		}
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

	long getWins(char[] s, int r, int c) {
		int curA = 0;
		int curB = 0;
		long ret = 0;
		for (char cc : s) {
			if (cc == 'A') {
				curA++;
			} else {
				ret += choose(curB, r - 1) * choose(curA, r);
				curB++;
			}
		}
		return ret;
	}

	long slow(int r, int c, String s) {
		int[] as = new int[r + c];
		for (int i = 0; i < r + c; i++) {
			as[i] = i;
		}
		long totalWays = ways[r + c][r] * ways[r + c][c];

		char[] buf = new char[2 * (r + c)];

		long bestDiff = Integer.MAX_VALUE;
		long ans = 0;
		
		List<String> good = new ArrayList<>();

		outer: do {
			Arrays.fill(buf, 'B');
			for (int pos : as) {
				buf[pos] = 'A';
			}
			int match = 1;
			for (int i = 0; i < 2 * (r + c); i++) {
				if (s.charAt(i) != '?' && s.charAt(i) != buf[i]) {
					match = 0;
					break;
				}
			}
			long winsA = getWins(buf, r, c);
			long diff = Math.abs(2 * winsA - totalWays);
			if (diff < bestDiff) {
				bestDiff = diff;
				good.clear();
				if (match == 1)
				good.add(new String(buf));
				ans = match;
			} else if (diff == bestDiff) {
				ans += match;
				if (match == 1)
				good.add(new String(buf));
			}
		} while (nextCombination(as, 2 * (r + c)));
//		System.err.println(good);
		return ans;
	}

	long solve(int r, int c, String s) {

		bestDiff = Long.MAX_VALUE;
		ans = 0;

		long maskA = 0;
		long maskB = 0;
		int[][] cnt = new int[s.length() + 1][2];
		for (int i = 0; i < s.length(); i++) {
			cnt[i + 1] = cnt[i].clone();
			if (s.charAt(i) == 'A') {
				cnt[i + 1][0]++;
				maskA |= 1L << i;
			}
			if (s.charAt(i) == 'B') {
				cnt[i + 1][1]++;
				maskB |= 1L << i;
			}
		}

		long lastA = maskA >> (2 * r + c - 1);
		long lastB = maskB >> (2 * r + c - 1);

		Half[][] fst = new Half[c + 2][];
		Half[][] snd = new Half[c + 2][];
		int[] sz = new int[c + 2];
		for (int i = 0; i < c + 2; i++) {
			sz[i] = (int) ways[c + 1][i];
			fst[i] = new Half[sz[i]];
			snd[i] = new Half[sz[i]];
		}

		for (int mask = 0; mask < 1 << (c + 1); mask++) {
			// 0 - a, 1 - b
			int btc = Integer.bitCount(mask);
			int compBtc = c + 1 - btc;
			int idx = --sz[btc];
			{
				int samePref = Math.min(Integer
						.numberOfTrailingZeros((mask & 1) == 0 ? mask
								: (mask + 1)), c + 1);

				int totalA = r - 1 - cnt[2 * r - 2 + samePref][0];
				int totalB = r - 1 - cnt[2 * r - 2 + samePref][1];
				if ((mask & 1) == 0) {
					totalA += samePref;
				} else {
					totalB += samePref;
				}

				long winsA = 0;

				int curA = 0;
				int curB = 0;
				for (int i = 0; i < c + 1; i++) {
					if (test(mask, i)) {
						winsA += ways[r - 1 + curB][r - 1]
								* choose(r - 1 + curA, r);
						curB++;
					} else {
						curA++;
					}
				}

				// can be optimized into some bit operations
				int exactMatch = 1;
				for (int i = samePref; i < c + 1; i++) {
					if (!test(mask, i) && s.charAt(2 * r - 2 + i) == 'B') {
						exactMatch = 0;
						break;
					}
					if (test(mask, i) && s.charAt(2 * r - 2 + i) == 'A') {
						exactMatch = 0;
						break;
					}
				}

				fst[btc][idx] = new Half(choose(totalA + totalB, totalA)
						* exactMatch, winsA);
			}

			{
				int match = 1;
				if (((~mask) & lastB) != 0) {
					match = 0;
				}
				if ((mask & lastA) != 0) {
					match = 0;
				}

				long winsA = 0;

				int curA = btc;
				int curB = compBtc;
				for (int i = 0; i < c + 1; i++) {
					if (test(mask, i)) {
						winsA += ways[r - 1 + curB][r - 1]
								* choose(r - 1 + curA, r);
						curB++;
					} else {
						curA++;
					}
				}

				snd[btc][idx] = new Half(match, winsA);
			}
		}

		totalWays = ways[r + c][r] * ways[r + c][r];
		long halfTotal = totalWays / 2;

		for (int i = 0; i <= c + 1; i++) {
			Half[] one = compress(fst[i]);
			Half[] two = compress(snd[c + 1 - i]);

			int ptr = two.length - 1;

			for (Half a : one) {
				while (ptr >= 0 && a.value + two[ptr].value > halfTotal) {
					ptr--;
				}
				if (ptr >= 0) {
					update(a, two[ptr]);
				}
				if (ptr + 1 < two.length) {
					update(a, two[ptr + 1]);
				}
			}
		}
		return ans;
	}

	void submit() {
		int r = nextInt();
		int c = nextInt();
		String s = nextToken();
		out.println(solve(r, c, s));
	}

	long totalWays;

	long bestDiff = Long.MAX_VALUE;
	long ans = 0;

	void update(Half a, Half b) {
		long totalValue = a.value + b.value;
		long diff = Math.abs(2 * totalValue - totalWays);
		long delta = a.match * b.match;
		if (diff < bestDiff) {
			bestDiff = diff;
			ans = delta;
		} else if (diff == bestDiff) {
			ans += delta;
		}
	}

	Half[] compress(Half[] arr) {
		Arrays.sort(arr);
		int sz = 1;
		for (int i = 1; i < arr.length; i++) {
			if (arr[i].value == arr[sz - 1].value) {
				arr[sz - 1].match += arr[i].match;
			} else {
				arr[sz++] = arr[i];
			}
		}
		return Arrays.copyOf(arr, sz);
	}

	long choose(int n, int k) {
		return n >= 0 && k >= 0 && k <= n ? ways[n][k] : 0;
	}

	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	void preCalc() {
		ways = new long[61][];
		for (int i = 0; i < ways.length; i++) {
			ways[i] = new long[i + 1];
			ways[i][0] = ways[i][i] = 1;
			for (int j = 1; j < i; j++) {
				ways[i][j] = ways[i - 1][j - 1] + ways[i - 1][j];
			}
		}
	}

	void stress() {
		for (int tst = 0;; tst++) {
			int r = rand(1, 3);
			int c = rand(1, 3);
			char[] buf = new char[2 * (r + c)];
			Arrays.fill(buf, '?');
			String s = new String(buf);
			long fast = solve(r, c, s);
			long slow = slow(r, c, s);
			if (fast != slow) {
				System.err.println(r + " " + c + " " + s);
				System.err.println(fast);
				System.err.println(slow);
				throw new AssertionError();
			}
			System.err.println(tst + " passed");
		}
	}

	void test() {
		int r = 1;
		int c = 3;
		String s = "ABBAABBA";
		System.err.println(solve(r, c, s));
//		System.err.println(slow(r, c, s));
	}

	F() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		 submit();
//		stress();
//		 test();
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