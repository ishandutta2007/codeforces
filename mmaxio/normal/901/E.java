import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class cfShit {

	int pow(int a, int b, int p) {
		int ret = 1;
		for (; b > 0; b >>= 1) {
			if ((b & 1) == 1) {
				ret = (int) ((long) ret * a % p);
			}
			a = (int) ((long) a * a % p);
		}
		return ret;
	}

	int primitiveRoot(int p) {
		loop: for (int i = 2;; i++) {
			for (int j = 2; j * j <= p - 1; j++) {
				if ((p - 1) % j != 0) {
					continue;
				}
				if (pow(i, (p - 1) / j, p) == 1) {
					continue loop;
				}
				if (pow(i, j, p) == 1) {
					continue loop;
				}
			}
			return i;
		}
	}

	static final int C = 5000;

	int[] chirp(int[] a, int[] pz, int p) {
		int n = a.length;
		// pz[1] has order 2 * n modulo prime p

		a = a.clone();
		for (int i = 0; i < n; i++) {
			a[i] %= p;
		}

		int[] one = new int[n];
		for (int i = 0; i < n; i++) {
			one[i] = (int) ((long) a[i] * pz[(int) ((long)i * i % (2 * n))] % p);
		}

		int[] two = new int[2 * n - 1];
		for (int i = 0; i <= 2 * n - 2; i++) {
			two[i] = pz[(int) Math.floorMod(-(long)(n - 1 - i) * (n - 1 - i), 2 * n)];
		}

		int[] prod = mult(one, two, p);

		prod = Arrays.copyOfRange(prod, n - 1, 2 * n - 1);
		for (int i = 0; i < n; i++) {
			prod[i] = (int) ((long) prod[i] * pz[(int) ((long)i * i % (2 * n))] % p);
		}

		return prod;
		// returns polynomial a modulo p at points 1, rootZ^2, rootZ^4, ...
	}

	void submit() {
		int n = nextInt();
		int[] b = new int[n];
		int[] c = new int[n];
		
		for (int i = 0; i < n; i++) {
			b[i] = nextInt();
		}
		
		int[] initB = b.clone();
		
		b = makeInvPows(b);
		
		for (int i = 0; i < n; i++) {
			c[i] = nextInt();
		}
		

		int z, p;
		int[] pz;

		int[] fb;

		for (int i = 1;; i++) {
			p = 2 * n * i + 1;
			if (p < C) {
				continue;
			}
			if (!BigInteger.valueOf(p).isProbablePrime(30)) {
				continue;
			}
			z = pow(primitiveRoot(p), (p - 1) / (2 * n), p);
			pz = new int[2 * n];
			pz[0] = 1;
			for (int j = 1; j < pz.length; j++) {
				pz[j] = (int) ((long) pz[j - 1] * z % p);
			}

			fb = chirp(b, pz, p);
			boolean allGood = true;
			for (int coef : fb) {
				allGood &= coef != 0;
			}

			if (allGood) {
				break;
			}
		}

		int[] cc = new int[n];
		int inv2 = (p + 1) / 2;
		for (int i = 0; i < n; i++) {
			cc[i] = (c[(i + n - 1) % n] - c[i]) % p;
			if (cc[i] < 0) {
				cc[i] += p;
			}
			cc[i] = (int)((long)cc[i] * inv2 % p);
		}
		
		int[] fc = chirp(cc, pz, p);
		
		int[] fa = new int[n];
		for (int i = 0; i < n; i++) {
			fa[i] = (int)((long)fc[i] * pow(fb[i], p - 2, p) % p);
		}
		
		int[] aa = chirp(fa, makeInvPows(pz), p);
		int invN = pow(n, p - 2, p);
		for (int i = 0; i < n; i++) {
			aa[i] = (int)((long)aa[i] * invN % p);
		}
		
		long[] d = new long[n];
		for (int i = 1; i < n; i++) {
			d[i] = d[i - 1] + makeInt(aa[i], p);
		}
		
//		System.err.println(Arrays.toString(realAa));
		
		long A = n;
		long B = 0;
		long C = -c[0];
		for (int i = 0; i < n; i++) {
			long diff = initB[i] - d[i];
			B -= diff;
			C += diff * diff;
		}
		
//		System.err.println(A + " " + B + " " + C);
		
		List<Long> x0s = new ArrayList<>();
		
		long D = B * B - A * C;
		if (D < 0) {
		} else if (D == 0) {
			if ((-B % A) == 0) {
				x0s.add((-B) / A);
			}
		} else {
			long rd = (long) Math.sqrt(D);
			if (rd * rd == D) {
				if ((-B - rd) % A == 0) {
					x0s.add((-B - rd) / A);
				}
				if ((-B + rd) % A == 0) {
					x0s.add((-B + rd) / A);
				}
			}
		}
		
		out.println(x0s.size());
		for (long x0 : x0s) {
			for(int i = 0; i < n; i++) {
				out.print(d[i] + x0 + " ");
			}
			out.println();
		}
		
	}
	
	int makeInt(int x, int p) {
		return x < p / 2 ? x : x - p;
	}
	
	int[] makeInvPows(int[] a) {
		int[] b = new int[a.length];
		b[0] = a[0];
		for (int i = 1, j = a.length - 1; i < a.length; i++, j--) {
			b[i] = a[j];
		}
		return b;
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	cfShit() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static int nextPowerOf2(int x) {
		return x == 1 ? 1 : Integer.highestOneBit(x - 1) << 1;
	}

	static double[][] foo(int[] intV, int len, int L) {
		// pack into one complex vector
		double[] f = new double[len << 1];
		for (int i = 0; i < intV.length; i++) {
			f[i << 1] = intV[i] % L;
			f[i << 1 | 1] = intV[i] / L;
		}

		fft(f, false);

		// unpack
		double[] f1 = new double[len << 1];
		double[] f2 = new double[len << 1];

		// LEN MUST BE A POWER OF 2!!!
		int zzz = (len << 1) - 1;
		for (int i = 0; i < len << 1; i += 2) {
			int j = (-i) & zzz;
			f1[i] = .5 * (f[i] + f[j]);
			f1[i + 1] = .5 * (f[i + 1] - f[j + 1]);
			f2[i] = .5 * (f[i + 1] + f[j + 1]);
			f2[i + 1] = .5 * (f[j] - f[i]);
		}

		return new double[][] { f1, f2 };
	}

	public static int[] mult(int[] a, int[] b, int pMod) {
		
		int k = (int) (Math.sqrt(pMod) + 1);
		int k2 = k * k % pMod;
		
		int len = nextPowerOf2(a.length + b.length - 1);
		int len2 = len << 1;

		double[][] fA = foo(a, len, k);
		double[][] fB = foo(b, len, k);

		double[][] invF = new double[2][len2];

		for (int ia = 0; ia < 2; ia++) {
			for (int ib = 0; ib < 2; ib++) {

				double[] r = invF[(ia + ib) >> 1];
				double[] p = fA[ia];
				double[] q = fB[ib];

				if (((ia + ib) & 1) == 0) {
					for (int i = 0; i < len2; i += 2) {
						r[i] += p[i] * q[i] - p[i + 1] * q[i + 1];
						r[i + 1] += p[i] * q[i + 1] + p[i + 1] * q[i];
					}

				} else {
					for (int i = 0; i < len2; i += 2) {
						r[i] -= p[i] * q[i + 1] + p[i + 1] * q[i];
						r[i + 1] += p[i] * q[i] - p[i + 1] * q[i + 1];
					}
				}

			}
		}

		fft(invF[0], true);
		fft(invF[1], true);

		int[] ret = new int[len];

		for (int i = 0; i < len2; i += 2) {
//			long v0 = Math.round(invF[0][i]) % P;
//			long v1 = Math.round(invF[0][i + 1]) % P * L % P;
//			long v2 = Math.round(invF[1][i]) % P * L2 % P;
			long v0 = (long)(invF[0][i] + .5);
			long v1 = ((long)(invF[0][i + 1] + .5)) % pMod * k;
			long v2 = ((long)(invF[1][i] + .5)) % pMod * k2;
			ret[i >> 1] = (int) ((v0 + v1 + v2) % pMod);
		}

		return ret;
	}

	public static void fft(double[] v, boolean invert) {
		int n2 = v.length;
		int n = n2 >> 1;
		int logN = Integer.numberOfTrailingZeros(n);
		prepareArrays(logN);
		int[] rev = rev2D[logN];

		for (int i = 0; i < n2; i += 2) {
			int j = rev[i >> 1] << 1;
			if (i < j) {
				double t = v[i];
				v[i] = v[j];
				v[j] = t;
				t = v[i + 1];
				v[i + 1] = v[j + 1];
				v[j + 1] = t;
			}
		}

		double conj = invert ? -1 : 1;

		for (int len = 2, row = 0; len <= n; len <<= 1, row++) {
			double[] pow = pow2D[row];
			for (int i = 0; i < n; i += len) {
				for (int j1 = i << 1, j2 = j1 + len, k = 0; k < len; j1 += 2, j2 += 2, k += 2) {
					double uA = v[j1];
					double uB = v[j1 + 1];

					double mRe = pow[k];
					double mIm = pow[k + 1] * conj;

					double vA = v[j2] * mRe - v[j2 + 1] * mIm;
					double vB = v[j2] * mIm + v[j2 + 1] * mRe;

					v[j1] = uA + vA;
					v[j1 + 1] = uB + vB;
					v[j2] = uA - vA;
					v[j2 + 1] = uB - vB;
				}
			}
		}
		if (invert) {
			for (int i = 0; i < n2; i++) {
				v[i] /= n;
			}
		}
	}

	static double[][] pow2D = { { 1, 0 } };
	static int[][] rev2D = {};

	static void prepareArrays(int n) {
		if (rev2D.length < n + 1) {
			rev2D = Arrays.copyOf(rev2D, n + 1);
		}

		if (rev2D[n] == null) {
			int[] tmp = rev2D[n] = new int[1 << n];
			for (int i = 0; i < (1 << n); i++) {
				tmp[i] = (tmp[i >> 1] >> 1) | ((i & 1) << (n - 1));
			}
		}

		int oldN = pow2D.length;

		if (oldN >= n) {
			return;
		}

		pow2D = Arrays.copyOf(pow2D, n);

		for (int i = oldN; i < n; i++) {
			double angle = Math.PI / (1 << i);

			double mRe = Math.cos(angle);
			double mIm = Math.sin(angle);

			double[] dst = pow2D[i] = new double[2 << i];
			double[] src = pow2D[i - 1];

			for (int j = 0; j < 1 << i; j += 2) {
				double re = src[j];
				double im = src[j + 1];

				dst[j << 1] = re;
				dst[j << 1 | 1] = im;
				dst[j << 1 | 2] = re * mRe - im * mIm;
				dst[j << 1 | 3] = re * mIm + im * mRe;
			}
		}
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new cfShit();
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