import java.io.*;
import java.util.*;

public class E {

	boolean[] fast(String s) {
		int n = s.length();
		double[] vs = new double[n];
		double[] ks = new double[n];
		for (int i = 0; i < n; i++) {
			if (s.charAt(i) == 'V') {
				vs[i] = 1;
			} else if (s.charAt(i) == 'K') {
				ks[n - 1 - i] = 1;
			}
		}
		
		double[] prod = mult(vs, ks);
		boolean[] bad = new boolean[n + 1];
		for (int i = 0; i < 2 * n - 1; i++) {
			if (prod[i] > 0.5) {
//				System.err.println(i);
				bad[Math.abs(i - (n - 1))] = true;
			}
		}
		
//		System.err.println(Arrays.toString(bad));

		boolean[] ret = new boolean[n + 1];
		Arrays.fill(ret, true);
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j += i) {
				if (bad[j]) {
					ret[i] = false;
				}
			}
		}
		
		return ret;
	}

	void submit() {
		int t = nextInt();
		while (t-- > 0) {
			int n = nextInt();
			String s = nextToken();
			boolean[] ans = fast(s);
			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (ans[i]) {
					cnt++;
				}
			}
			out.println(cnt);
			for (int i = 1; i <= n; i++) {
				if (ans[i]) {
					out.print(i + " ");
				}
			}
			out.println();
		}
	}

	static int nextPowerOf2(int x) {
		return x == 1 ? 1 : Integer.highestOneBit(x - 1) << 1;
	}

	static class CompV {
		double[] re, im;

		void add(CompV o) {
			for (int i = 0; i < re.length; i++) {
				re[i] += o.re[i];
				im[i] += o.im[i];
			}
		}

		static CompV times(CompV a, CompV b) {
			double[] aRe = a.re;
			double[] aIm = a.im;
			double[] bRe = b.re;
			double[] bIm = b.im;
			double[] re = new double[aRe.length];
			double[] im = new double[aRe.length];

			for (int i = 0; i < aRe.length; i++) {
				re[i] = aRe[i] * bRe[i] - aIm[i] * bIm[i];
				im[i] = aRe[i] * bIm[i] + aIm[i] * bRe[i];
			}

			return new CompV(re, im);
		}

		/**
		 * @return a + bi
		 */
		static CompV packFFT(CompV a, CompV b) {
			double[] aRe = a.re;
			double[] aIm = a.im;
			double[] bRe = b.re;
			double[] bIm = b.im;
			double[] re = new double[aRe.length];
			double[] im = new double[aRe.length];
			for (int i = 0; i < aRe.length; i++) {
				re[i] = aRe[i] - bIm[i];
				im[i] = aIm[i] + bRe[i];
			}
			return new CompV(re, im);
		}

		/**
		 * for real-valued a and b restores FFT(a) and FFT(b) from FFT(a + bi)
		 */
		void unpackFFT(CompV a, CompV b) {
			int n = re.length;
			double[] aRe = a.re;
			double[] aIm = a.im;
			double[] bRe = b.re;
			double[] bIm = b.im;
			for (int i = 0; i < n; i++) {
				int j = i == 0 ? 0 : n - i;
				aRe[i] = (re[i] + re[j]) * 0.5;
				aIm[i] = (im[i] - im[j]) * 0.5;
				bRe[i] = (im[i] + im[j]) * 0.5;
				bIm[i] = (re[j] - re[i]) * 0.5;
			}
		}

		public CompV(double[] re, double[] im) {
			this.re = re;
			this.im = im;
		}

		public CompV(int len) {
			re = new double[len];
			im = new double[len];
		}
	}

	public static double[] mult(double[] a, double[] b) {
		int len = nextPowerOf2(a.length + b.length - 1);

		CompV abPack = new CompV(Arrays.copyOf(a, len), Arrays.copyOf(b, len));

		fft(abPack, false);

		CompV fa = new CompV(len);
		CompV fb = new CompV(len);
		abPack.unpackFFT(fa, fb);

		CompV fProd = CompV.times(fa, fb);

		fft(fProd, true);

		return fProd.re;
	}

	public static void fft(CompV v, boolean invert) {
		double[] a = v.re;
		double[] b = v.im;
		int n = a.length;
		int shift = 32 - Integer.numberOfTrailingZeros(n);
		prepareArrays(32 - shift);
		int[] rev = rev2D[32 - shift];
		// System.err.println(n + " " + shift);
		for (int i = 1; i < n; i++) {
			int j = rev[i];
			if (i < j) {
				double temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}

		// this shit looks awkward
		double multInv = invert ? -1 : 1;

		for (int len = 2, row = 0; len <= n; len <<= 1, row++) {
			int halfLen = len >> 1;
			double[] multReArr = powRe[row];
			double[] multImArr = powIm[row];
			for (int i = 0; i < n; i += len) {
				int toJ = i + halfLen;

				for (int j1 = i, j2 = toJ, k = 0; k < halfLen; j1++, j2++, k++) {
					double uA = a[j1];
					double uB = b[j1];

					double multRe = multReArr[k];
					double multIm = multImArr[k] * multInv;

					double vA = a[j2] * multRe - b[j2] * multIm;
					double vB = a[j2] * multIm + b[j2] * multRe;
					a[j1] = uA + vA;
					b[j1] = uB + vB;
					a[j2] = uA - vA;
					b[j2] = uB - vB;
				}
			}
		}
		if (invert) {
			for (int i = 0; i < n; i++) {
				a[i] /= n;
				b[i] /= n;
			}
		}
	}

	static double[][] powRe = { { 1 } };
	static double[][] powIm = { { 0 } };
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

		int oldN = powRe.length;

		if (oldN >= n) {
			return;
		}

		powRe = Arrays.copyOf(powRe, n);
		powIm = Arrays.copyOf(powIm, n);

		for (int i = oldN; i < n; i++) {

			double angle = Math.PI / (1 << i);

			double multRe = Math.cos(angle);
			double multIm = Math.sin(angle);

			double[] toRe = powRe[i] = new double[1 << i];
			double[] toIm = powIm[i] = new double[1 << i];

			double[] fromRe = powRe[i - 1];
			double[] fromIm = powIm[i - 1];

			for (int j = 0; j < 1 << (i - 1); j++) {

				double re = fromRe[j];
				double im = fromIm[j];

				toRe[j << 1] = re;
				toIm[j << 1] = im;
				toRe[(j << 1) | 1] = re * multRe - im * multIm;
				toIm[(j << 1) | 1] = re * multIm + im * multRe;
			}

			// System.err.println(Arrays.toString(toRe));
			// System.err.println(Arrays.toString(toIm));
		}
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