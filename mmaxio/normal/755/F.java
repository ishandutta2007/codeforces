import java.io.*;
import java.util.*;

public class F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int get(int mask, int i) {
		return (mask >> i) & 1;
	}

	int[] f(int n, int k) {

		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;

		for (int mask = 0; mask < (1 << n); mask++) {
			if (Integer.bitCount(mask) == k) {

				int tot = 0;
				for (int i = 0; i < n; i++) {
					tot += get(mask, i) & get(mask, (i + 1) % n);
				}

				min = Math.min(min, tot);
				max = Math.max(max, tot);

			}
		}

		// return new int[] { min, max };
		return new int[] { max };
	}

	int getMin(int[] a, int k) {
		int[] cnt = new int[3];
		for (int x : a) {
			cnt[0] += x / 2;
			cnt[1] += x % 2;
			cnt[2] += x / 2;
		}

		int ret = 0;
		for (int i = 0;; i++) {
			if (cnt[i] >= k) {
				return ret + k * i;
			}
			ret += cnt[i] * i;
			k -= cnt[i];
		}
	}

	int getMax(int[] a, int k) {

		int sum = 0;
		for (int x : a) {
			sum += x;
		}

		int[] cnt = new int[sum + 1];
		for (int x : a) {
			cnt[x]++;
		}

		BitsetLong bs = new BitsetLong(sum);
		bs.set(0);

		long[] data = bs.data;

		// for (int x : a) {

		for (int ii = 1; ii <= sum; ii++) {
			
			if (cnt[ii] == 0) {
				continue;
			}
			
			for (int rest = cnt[ii], p2 = 1; rest > 0; p2 <<= 1) {
				int use = Math.min(rest, p2);
				int x = ii * use;
				
				for (int i = data.length - 1; (i << 6) - x > -64; i--) {
					data[i] |= bs.getWord((i << 6) - x);
				}
				
				rest -= use;
			}
			
			
		}
		// }

		if (bs.get(k) == 1) {
			return k;
		} else {
			return k - 1;
		}

	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();

		k = n - k;

		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt() - 1;
		}

		int[] arr = new int[n];
		int ptr = 0;

		boolean[] vis = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (vis[i]) {
				continue;
			}
			vis[i] = true;
			int len = 1;
			for (int v = p[i]; v != i; v = p[v]) {
				vis[v] = true;
				len++;
			}
			arr[ptr++] = len;
		}

		arr = Arrays.copyOf(arr, ptr);

		out.println(n - getMax(arr, k) + " " + (n - getMin(arr, k)));
	}

	F() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);

		// for (int n = 1; n <= 10; n++) {
		// for (int k = 0; k <= n; k++) {
		// System.err.println(n + " " + k + " -> "
		// + Arrays.toString(f(n, k)));
		// }
		// System.err.println();
		// }
		solve();
		
//		List<Integer> tmp = new ArrayList<>();
//		for (int i = 1, rest = 1_000_000; rest > 0; i++) {
//			int use = Math.min(rest, i);
//			tmp.add(use);
//			rest -= use;
//		}
//		int[] arr = new int[tmp.size()];
//		for (int i = 0; i < tmp.size(); i++) {
//			arr[i] = tmp.get(i);
//		}
		
//		out.println(getMax(arr, 999999));

		out.close();
	}

	static class BitsetLong {

		static final int LOG = 6;
		static final int SIZE = 1 << LOG;
		static final int MASK = SIZE - 1;

		private long[] data;

		public BitsetLong(int n) {
			data = new long[(n >> LOG) + 2];
		}

		void set(int i) {
			data[i >> LOG] |= 1L << (i & MASK);
		}

		void unset(int i) {
			data[i >> LOG] &= ~(1L << (i & MASK));
		}

		void flip(int i) {
			data[i >> LOG] ^= 1L << (i & MASK);
		}

		int get(int i) {
			return (int) ((data[i >> LOG] >>> (i & MASK)) & 1);
		}

		/**
		 * pads with zeroes if end of word is outside of range
		 */
		long getWord(int i) {
			if (i <= -SIZE) {
				return 0;
			}
			if (i < 0) {
				return data[0] << (-i);
			}
			int rem = i & MASK;
			int idx = i >> LOG;

			if (rem == 0) {
				return data[idx];
			}

			long head = data[idx] >>> rem;
			long tail = data[idx + 1] & ((1L << rem) - 1);

			return head | (tail << (SIZE - rem));
		}
	}

	public static void main(String[] args) throws IOException {
		new F();
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