import java.io.*;
import java.util.*;

public class cdEdu9F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Elem implements Comparable<Elem> {
		int x, y, val;

		@Override
		public int compareTo(Elem o) {
			return -Integer.compare(val, o.val);
		}

		public Elem(int x, int y, int val) {
			this.x = x;
			this.y = y;
			this.val = val;
		}
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

	void solve() throws IOException {
		int n = nextInt();
		int[][] a = new int[n][n];
		Elem[] b = new Elem[n * (n - 1) / 2];
		int ptr = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = nextInt();
				if (i == j) {
					if (a[i][j] != 0) {
						out.println("NOT MAGIC");
						return;
					}
				}
				if (i > j) {
					if (a[i][j] != a[j][i]) {
						out.println("NOT MAGIC");
						return;
					}
				}
				if (i < j) {
					b[ptr++] = new Elem(i, j, a[i][j]);
				}
			}
		}

		BitsetLong bs[] = new BitsetLong[n];
		for (int i = 0; i < n; i++) {
			bs[i] = new BitsetLong(n);
			for (int j = 0; j < n; j++) {
				if (i != j) {
					bs[i].set(j);
				}
			}
		}
		
		int bsLen = bs[0].data.length;

		Arrays.sort(b);
		for (int i = 0; i < b.length;) {
			int val = b[i].val;
			if (val == 0) {
				break;
			}
			int j = i;
			while (j < b.length && b[j].val == val) {
				int v1 = b[j].x;
				int v2 = b[j].y;
				bs[v1].unset(v2);
				bs[v2].unset(v1);
				j++;
			}
			
			for (int k = i; k < j; k++) {
				BitsetLong bs1 = bs[b[k].x];
				BitsetLong bs2 = bs[b[k].y];
				for (int kk = 0; kk < bsLen; kk++) {
					if ((bs1.data[kk] & bs2.data[kk]) != 0) {
						out.println("NOT MAGIC");
						return;
					}
				}
			}
			
			i = j;
		}
		
		out.println("MAGIC");
	}

	cdEdu9F() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new cdEdu9F();
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