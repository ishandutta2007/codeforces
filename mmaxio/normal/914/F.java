import java.io.*;
import java.util.*;

public class cf458E {

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
		 * bits [i; i + SIZE) of infinite array with this bitset starting at 0
		 */
		long getWord(int i) {
			if (i <= -SIZE || (i >> LOG) + 1 >= data.length) {
				return 0;
			}
			int rem = i & MASK;
			int idx = i >> LOG;

			if (rem == 0) {
				return data[idx];
			}

			long head = idx < 0 ? 0 : (data[idx] >>> rem);
			long tail = data[idx + 1] << (SIZE - rem);

			return head | tail;
		}
	}

	void submit() {
		String ss = nextToken();
		int n = ss.length();
		int[] s = new int[n];
		
		BitsetLong[] a = new BitsetLong[26];
		for (int i = 0; i < 26; i++) {
			a[i] = new BitsetLong(n);
		}
		
		for (int i = 0; i < n; i++) {
			int symb = ss.charAt(i) - 'a';
			s[i] = symb;
			a[symb].set(i);
		}
		
		int q = nextInt();
		
		while (q-- > 0) {
			int type = nextInt();
			if (type == 1) {
				int idx = nextInt() - 1;
				int symb = nextToken().charAt(0) - 'a';
				a[s[idx]].unset(idx);
				a[symb].set(idx);
				s[idx] = symb;
			} else {
				int l = nextInt() - 1;
				int r = nextInt() - 1;
				String qs = nextToken();
				
				if (r - l + 1 < qs.length()) {
					out.println(0);
					continue;
				}
				
				long[] res = a[qs.charAt(0) - 'a'].data.clone();
				for (int i = 1; i < qs.length(); i++) {
					int symb = qs.charAt(i) - 'a';
					
					for (int j = 0; j < res.length; j++) {
						res[j] &= a[symb].getWord((j << 6) + i);
					}
				}
				
				out.println(count(res, r - qs.length() + 2) - count(res, l));
			}
		}
	}
	
	int count(long[] bs, int len) {
		int ret = 0;
		for (int i = 0; i << 6 < len; i++) {
			if ((i + 1) << 6 <= len) {
				ret += Long.bitCount(bs[i]);
			} else {
				int rem = len & 63;
				ret += Long.bitCount(bs[i] << (64 - rem));
			}
		}
		return ret;
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	cf458E() throws IOException {
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
		new cf458E();
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