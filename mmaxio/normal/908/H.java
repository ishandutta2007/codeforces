import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class H {

	void submit() {
		int n = nextInt();
		char[][] f = new char[n][];
		for (int i = 0; i < n; i++) {
			f[i] = nextToken().toCharArray();
		}

		boolean[][] g = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				g[i][j] = i == j || f[i][j] == 'A';
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					g[i][j] |= g[i][k] && g[k][j];
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (g[i][j] && f[i][j] == 'X') {
					out.println(-1);
					return;
				}
			}
		}

		int[] rs = new int[n / 2];
		int k = 0;

		outer: for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (g[i][j]) {
					continue outer;
				}
			}
			int sz = 0;
			for (int j = i; j < n; j++) {
				sz += g[i][j] ? 1 : 0;
			}
			if (sz > 1) {
				rs[k++] = i;
			}
		}

		boolean[] bad = new boolean[1 << k];
		for (int i = 0; i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				boolean good = true;

				int ri = rs[i];
				int rj = rs[j];

				for (int vi = ri; vi < n; vi++) {
					for (int vj = rj; vj < n; vj++) {
						if (g[ri][vi] && g[rj][vj] && f[vi][vj] == 'X') {
							good = false;
						}
					}
				}


				if (!good) {
					bad[(1 << i) | (1 << j)] = true;
				}
			}
		}

		if (k == 0) {
			out.println(n - 1);
			return;
		}

		for (int mask = 0; mask < 1 << k; mask++) {
			for (int i = 0; i < k; i++) {
				if (test(mask, i)) {
					bad[mask] |= bad[mask ^ (1 << i)];
				}
			}
		}

		int[] a = new int[1 << k];
		for (int i = 0; i < 1 << k; i++) {
			a[i] = bad[i] ? 0 : 1;
		}

		int p = BigInteger.probablePrime(30, new Random()).intValue();

		for (int i = 0; i < k; i++) {
			for (int mask = 0; mask < 1 << k; mask++) {
				if (test(mask, i)) {
					int u = a[mask ^ (1 << i)];
					int v = a[mask];
					a[mask ^ (1 << i)] = u + v;
					if (a[mask ^ (1 << i)] >= p) {
						a[mask ^ (1 << i)] -= p;
					}

					a[mask] = u - v;
					if (a[mask] < 0) {
						a[mask] += p;
					}
				}
			}
		}

		int[] cur = a.clone();
		
		int[] sign = new int[1 << k];
		sign[0] = 1;
		for (int i = 1; i < 1 << k; i++) {
			sign[i] = -sign[i ^ (i & -i)];
		}

		int ans = 0;
		while (true) {
			ans++;
			long val = 0;
			for (int i = 0; i < 1 << k; i++) {
				val += sign[i] * cur[i];
			}
			if (Math.floorMod(val, p) != 0) {
				break;
			}

			for (int i = 0; i < 1 << k; i++) {
				cur[i] = (int) ((long) cur[i] * a[i] % p);
			}
		}

		out.println(n - 1 + ans);
	}

	boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	H() throws IOException {
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
		new H();
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