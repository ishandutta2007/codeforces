import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final String ALPH = "AGCT";
	static final double EPS = 0.001;

	double[] getProd(char[] s, char[] t, char c, int k) {
		double[] ss = new double[s.length];
		for (int i = 0, last = -1; i < s.length; i++) {
			if (s[i] == c) {
				last = i;
			}
			if (last != -1 && i - last <= k) {
				ss[i] = 1;
			}
		}

		for (int i = s.length - 1, last = s.length; i >= 0; i--) {
			if (s[i] == c) {
				last = i;
			}
			if (last != s.length && last - i <= k) {
				ss[i] = 1;
			}
		}

		double[] tt = new double[t.length];
		for (int i = 0; i < t.length; i++) {
			if (t[i] == c) {
				tt[t.length - 1 - i] = 1;
			}
		}
//		System.err.println(Arrays.toString(ss) + " " + Arrays.toString(tt));
		return FFTComplex.mulValueDomain(ss, tt);
	}

	void solve() throws IOException {
		int ns = nextInt();
		int nt = nextInt();
		int k = nextInt();
		char[] s = nextToken().toCharArray();
		char[] t = nextToken().toCharArray();
		double[][] prods = new double[4][];
		for (int i = 0; i < 4; i++) {
			prods[i] = getProd(s, t, ALPH.charAt(i), k);
			// System.err.println(Arrays.toString(prods[i]));
		}
		double[] sum = new double[prods[0].length];
		for (double[] a : prods)
			for (int j = 0; j < sum.length; j++) {
				sum[j] += a[j];
			}
		FFTComplex.fft(sum, true);
		// System.err.println(Arrays.toString(sum));
		int ret = 0;
		for (int i = t.length - 1; i <= s.length - 1; i++) {
			if (Math.abs(sum[i << 1] - t.length) < EPS) {
				ret++;
			}
		}
		out.println(ret);
	}

	static class FFTComplex {

		public static double[] mulValueDomain(double[] a, double[] b) {
			int len = nextPowerOf2(a.length + b.length - 1);
			double[] da = new double[len << 1];
			double[] db = new double[len << 1];
			for (int i = 0; i < a.length; ++i) {
				da[i << 1] = a[i];
			}
			for (int i = 0; i < b.length; ++i) {
				db[i << 1] = b[i];
			}
			fft(da, false);
			fft(db, false);
			return pointwiseMultiply(da, db);
		}

		public static double[] pointwiseMultiply(double[] da, double[] db) {
			if (da.length != db.length || (da.length & 1) != 0) {
				throw new AssertionError();
			}
			int len = da.length >> 1;
			double[] dc = new double[len << 1];
			for (int i = 0; i < len; ++i) {
				double aRe = da[i << 1];
				double aIm = da[(i << 1) + 1];
				double bRe = db[i << 1];
				double bIm = db[(i << 1) + 1];
				dc[i << 1] = aRe * bRe - aIm * bIm;
				dc[(i << 1) + 1] = aRe * bIm + aIm * bRe;
			}
			return dc;
		}

		static class RevOrderCache {
			private RevOrderCache() {
			}

			int[] getRevOrder(int size) {
				int log = Integer.numberOfTrailingZeros(size);
				if (log >= cache.length) {
					cache = Arrays.copyOf(cache, log + 1);
				}
				if (cache[log] == null) {
					cache[log] = makeRevOrder(log);
				}
				return cache[log];
			}

			private int[][] cache = new int[0][];
			static RevOrderCache INSTANCE = new RevOrderCache();

			private int[] makeRevOrder(int log) {
				int[] ret = new int[1 << log];
				for (int i = 0; i < (1 << log); i++) {
					ret[i] = ret[i >> 1] >> 1;
					if ((i & 1) == 1) {
						ret[i] |= 1 << (log - 1);
					}
				}
				return ret;
			}
		}

		static boolean isPowerOf2(int x) {
			return (x & (x - 1)) == 0;
		}

		static int nextPowerOf2(int x) {
			return isPowerOf2(x) ? x : Integer.highestOneBit(x) << 1;
		}

		public static void fft(double[] arr, boolean inv) {
			if ((arr.length & (arr.length - 1)) != 0) {
				throw new AssertionError();
			}
			int n = arr.length >> 1;
			int[] rev = RevOrderCache.INSTANCE.getRevOrder(n);
			for (int i = 0; i < n; ++i) {
				int j = rev[i];
				if (j > i) {
					double tmp = arr[i << 1];
					arr[i << 1] = arr[j << 1];
					arr[j << 1] = tmp;
					tmp = arr[(i << 1) + 1];
					arr[(i << 1) + 1] = arr[(j << 1) + 1];
					arr[(j << 1) + 1] = tmp;
				}
			}
			for (int p2 = 1; p2 < n; p2 *= 2) {
				double wre = Math.cos(Math.PI / p2);
				double wim = Math.sin(Math.PI / p2);
				if (inv)
					wim = -wim;
				for (int big = 0; big < n; big += p2 << 1) {
					double re = 1;
					double im = 0;
					for (int small = big; small < big + p2; ++small) {
						int i = small;
						int j = small + p2;
						double ure = arr[i << 1];
						double uim = arr[(i << 1) + 1];
						double ore = arr[j << 1];
						double oim = arr[(j << 1) + 1];
						double vre = re * ore - im * oim;
						double vim = re * oim + im * ore;
						arr[i << 1] = ure + vre;
						arr[(i << 1) + 1] = uim + vim;
						arr[j << 1] = ure - vre;
						arr[(j << 1) + 1] = uim - vim;
						double nre = re * wre - im * wim;
						im = re * wim + im * wre;
						re = nre;
					}
				}
			}
			if (inv) {
				for (int i = 0; i < arr.length; ++i) {
					arr[i] /= n;
				}
			}
		}
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
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