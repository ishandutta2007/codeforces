import java.io.*;
import java.util.*;

public class cf559F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int P = 998244353;
	static final int DBL_P = 2 * P;
	static final long Q = 4L * P * P;

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

	int[][] bigC(int[] a, int c) {
		int n = a.length;

		int k = n / c;

		long[][] dp = new long[n + 1][k + 1];
		dp[0][0] = 1;

		int[] cf = new int[n + 1];
		int[] icf = new int[n + 1];
		cf[0] = 0;
		for (int i = 1; i < cf.length; i++) {
			cf[i] = 2 * cf[i - 1] + 1;
			if (cf[i] >= P) {
				cf[i] -= P;
			}
			icf[i] = pow(cf[i], P - 2);
		}

		for (int i = 0; i < n; i++) {
			int[] cnt = new int[c];
			int nz = 0;
			long prod = 1;
			
			long[] src = dp[i];
			for (int j = 0; j <= k; j++) {
				src[j] %= P;
			}
			
			int upto = k - 1;
			while (upto >= 0 && src[upto] == 0) {
				upto--;
			}
			
			for (int j = i; j < n; j++) {
				int x = a[j];

				if (cnt[x] > 0) {
					prod = prod * icf[cnt[x]] % P;
				}
				if (nz == c || (nz == c - 1 && cnt[x] == 0)) {

					long[] dst = dp[j + 1];

					for (int l = 0; l <= upto; l++) {
						
						long tmp = dst[l + 1] + src[l] * prod;
						if (tmp >= Q) {
							tmp -= Q;
						}
						dst[l + 1] = tmp;
					}
				}

				if (cnt[x] == 0) {
					nz++;
				}
				cnt[x]++;

				prod = prod * cf[cnt[x]] % P;
			}
		}

		int[][] ret = new int[k + 1][n + 1];
		for (int i = 0; i <= k; i++) {
			for (int j = 0; j <= n; j++) {
				ret[i][j] = (int) (dp[j][i] % P);
			}
		}
		return ret;
	}

	static final Random rng = new Random();

	int[][] smallC(int[] a, int c) {
		int n = a.length;

		int k = n / c;

		int[][] dp = new int[k + 1][n + 1];
		dp[0][0] = 1;

		int[][] aux = new int[k + 1][1 << c];

		aux[0][0] = 1;

		int all = (1 << c) - 1;

		for (int i = 0; i < n; i++) {
			int x = a[i];
			int mx = 1 << x;

			for (int j = Math.min(k - 1, i / c); j >= 0; j--) {
				int[] memo = aux[j];
				int delta = memo[all ^ (1 << x)];
				if (delta != 0) {
					dp[j + 1][i + 1] += delta;
					if (dp[j + 1][i + 1] >= P) {
						dp[j + 1][i + 1] -= P;
					}
					aux[j + 1][0] += delta;
					if (aux[j + 1][0] >= P) {
						aux[j + 1][0] -= P;
					}
				}

				int big = all ^ mx;

				for (int mask = big;; mask = (mask - 1) & big) {
					int z = mask ^ mx;

					int tmp = (memo[z] << 1) + memo[mask];

					if (tmp >= 0 && tmp < P) {

					} else {
						tmp -= P;
						if (tmp >= P) {
							tmp -= P;
						}
					}
					/*
					 * if (tmp < 0 || tmp >= DBL_P) { tmp -= DBL_P; } else if
					 * (tmp >= P) { tmp -= P; }
					 */
					memo[z] = tmp;
					if (mask == 0) {
						break;
					}
				}

			}

		}

		return dp;
	}

	void shuffle(int[] a) {
		for (int i = 0; i < a.length; i++) {
			int j = rng.nextInt(i + 1);
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}

	int[] badCase(int n, int c) {
		int[] a = new int[n];
		int[] b = new int[c];
		for (int i = 0; i < c; i++) {
			b[i] = i;
		}

		for (int i = 0; i < n;) {
			shuffle(b);
			for (int j = 0; j < c && i < n; i++, j++) {
				a[i] = b[j];
			}
		}

		return a;
	}

	void solve() throws IOException {
//		int n = 3000;
//		int c = 13;

		 int n = nextInt();
		 int c = nextInt();

		int[] a = new int[n];
		// if (n == 3000 && c == 12) {
//		a = badCase(n, c);
		// } else {
		 for (int i = 0; i < n; i++) {
		 a[i] = nextInt() - 1;
		 }
		// }

//		int[][] dp = bigC(a, c);
		 int[][] dp = c > 10 ? bigC(a, c) : smallC(a, c);

		int[] atL = new int[n + 2];
		long p2 = 1;
		for (int j = n; j >= 0; j--) {
			for (int i = 0; i < dp.length; i++) {
				atL[i] = (int) ((atL[i] + p2 * dp[i][j]) % P);
			}
			p2 = 2 * p2 % P;
		}

		atL[0]--;
		if (atL[0] < 0) {
			atL[0] += P;
		}

		for (int i = 0; i <= n; i++) {
			int x = atL[i] - atL[i + 1];
			if (x < 0) {
				x += P;
			}
			out.print(x + " ");
		}
		out.println();
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new cf559F().inp();
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