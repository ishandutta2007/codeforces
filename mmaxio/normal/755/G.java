import java.io.*;
import java.util.*;

public class G {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int P = 998244353;
	static final long P2 = (long) P * P;
	static final int[] A = { 1, 1 };
	static final int[] B = { 0, 1 };

	int[] prod(int[] a, int[] b, int len) {
		int[] c = new int[Math.min(a.length + b.length - 1, len)];

		for (int k = 0; k < c.length; k++) {
			long sum = 0;
			for (int i = 0; i <= k && i < a.length; i++) {
				if (k - i < b.length) {
					sum += (long) a[i] * b[k - i];
					if (sum >= P2) {
						sum -= P2;
					}
				}
			}
			c[k] = (int) (sum % P);
		}

		return c;
	}

	int[] sum(int[] a, int[] b, int len) {
		int[] c = new int[Math.min(Math.max(a.length, b.length), len)];
		for (int i = 0; i < c.length; i++) {
			c[i] = (i < a.length ? a[i] : 0) + (i < b.length ? b[i] : 0);
			if (c[i] >= P) {
				c[i] -= P;
			}
		}
		return c;
	}

	int[] pointwise(int[] a, int[] b) {
		if (a.length != b.length) {
			throw new AssertionError();
		}
		int[] c = new int[a.length];
		for (int i = 0; i < c.length; i++) {
			c[i] = (int) ((long) a[i] * b[i] % P);
		}
		return c;
	}

	int[][] get(int n, int len) {

		if (n == 0) {
			return new int[][] { {}, { 1 } };
		}

		if ((n & 1) == 1) {
			int[][] tmp = get(n - 1, len);
			return new int[][] { sum(prod(A, tmp[0], len), tmp[1], len),
					prod(B, tmp[0], len) };
		} else {
			int[][] tmp = get(n >> 1, len);

			int needLen = FFTDiscrete.nextPowerOf2(2 * Math.max(tmp[0].length,
					tmp[1].length) - 1);

			int[] fp = Arrays.copyOf(tmp[0], needLen);
			int[] fq = Arrays.copyOf(tmp[1], needLen);

			FFTDiscrete.fft(fp, false);
			FFTDiscrete.fft(fq, false);

			int[] pp = pointwise(fp, fp);
			int[] pq = pointwise(fp, fq);
			int[] qq = pointwise(fq, fq);

			FFTDiscrete.fft(pp, true);
			FFTDiscrete.fft(pq, true);
			FFTDiscrete.fft(qq, true);

			return new int[][] {
					sum(prod(A, pp, len), prod(new int[] { 2 }, pq, len), len),
					sum(prod(B, pp, len), qq, len) };
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();

		int[][] ps = get(n + 1, k + 1);
		for (int i = 1; i <= k; i++) {
			out.print((i >= ps[0].length ? 0 : ps[0][i]) + " ");
		}
		out.println();
	}

	static class FFTDiscrete {
		
		static final int PRIM = 3;
		static final int LOG = Integer.numberOfTrailingZeros(P - 1);
		static final int R = pow(PRIM, (P - 1) >> LOG);
		
//		static int[] POW = new int[(1 << LOG) + 1];
//		static {
//			POW[0] = 1;
//			for (int i = 1; i < POW.length; i++) {
//				POW[i] = (int)((long)POW[i - 1] * R % P);
//			}
//		}
		
		static int[][] ROWS = new int[LOG + 1][];
		static {
			int[] lastRow = ROWS[LOG] = new int[(1 << LOG) + 1];
			lastRow[0] = 1;
			for (int i = 1; i <= 1 << LOG; i++) {
				lastRow[i] = (int)((long)lastRow[i - 1] * R % P);
			}
			for (int i = 0; i < LOG; i++) {
				int[] thisRow = ROWS[i] = new int[(1 << i) + 1];
				for (int j = 0; j < ROWS[i].length; j++) {
					thisRow[j] = lastRow[j << (LOG - i)];
				}
				
//				if (i < 5)
//				System.err.println(i + " " + Arrays.toString(thisRow));
//				
			}
		}
		
		static int[] INV2_POW = new int[LOG];
		static {
			INV2_POW[0] = 1;
			int inv2 = pow(2, P - 2);
			for (int i = 1; i < LOG; i++) {
				INV2_POW[i] = (int)((long)INV2_POW[i - 1] * inv2 % P);
			}
		}
		
		static int pow(int a, int b) {
			int ret = 1;
			for (; b > 0; b >>= 1) {
				if ((b & 1) == 1) {
					ret = (int) ((long) ret * a % P);
				}
				a = (int) ((long) a * a % P);
			}
			return ret;
		}


		static int nextPowerOf2(int x) {
			return x == 1 ? 1 : Integer.highestOneBit(x - 1) << 1;
		}

		public static void fft(int[] a, boolean invert) {
			int n = a.length;
			int shift = Integer.numberOfTrailingZeros(n);
			prepareArrays(shift);
			int[] rev = rev2D[shift];
			// System.err.println(n + " " + shift);
			for (int i = 1; i < n; i++) {
				int j = rev[i];
				if (i < j) {
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}

			// this shit looks awkward
			int step = invert ? -1 : 1;
			 

			for (int len = 2, rowId = 1; len <= n; len <<= 1, rowId++) {
				int halfLen = len >> 1;
			
				int[] row = ROWS[rowId];
				int from = invert ? row.length - 1 : 0;
			
				for (int i = 0; i < n; i += len) {
					int toJ = i + halfLen;

					for (int j1 = i, j2 = toJ, k = from; j1 < toJ; j1++, j2++, k += step) {
						int p = a[j1];
						int q = (int)((long)a[j2] * row[k] % P);

						a[j1] = p + q;
						if (a[j1] >= P) {
							a[j1] -= P;
						}
						a[j2] = p - q;
						if (a[j2] < 0) {
							a[j2] += P;
						}
					}
				}
			}
			if (invert) {
				int mult = INV2_POW[shift];
				for (int i = 0; i < n; i++) {
					a[i] = (int)((long)a[i] * mult % P);
				}
			}
		}

		static int[][] rev2D = {};

		static void prepareArrays(int n) {
			if (rev2D.length < n + 1) {
					rev2D = Arrays.copyOf(rev2D, n + 1);
			}

			if (rev2D[n] == null) {
				int[] tmp = rev2D[n] = new int[1 << n];
				for (int i = 0; i < (1 << n); i++) {
					tmp[i] = tmp[i >> 1] >> 1;
					if ((i & 1) == 1) {
						tmp[i] |= 1 << (n - 1);
					}
				}
			}

		}
	}

	G() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new G();
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