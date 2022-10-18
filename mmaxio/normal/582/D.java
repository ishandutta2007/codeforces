import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int MOD = 1_000_000_007;

	void solve() throws IOException {
		int p = nextInt();
		BigInteger bigP = BigInteger.valueOf(p);
		int need = nextInt();
		BigInteger A = new BigInteger(nextToken());
		// BigInteger A = BigInteger.TEN.pow(1000);

		List<Integer> digs = new ArrayList<>();
		while (A.signum() != 0) {
			// System.err.println(A);
			BigInteger[] tmp = A.divideAndRemainder(bigP);
			digs.add(tmp[1].intValue());
			A = tmp[0];
		}

		int[][] dpEq = new int[2][1];
		int[][] dpLess = new int[2][1];

		// no next carry/next
		// carry, total carries
		dpEq[0][0] = 1;

		int smallSumNoCarry = (int) ((long) p * (p + 1) / 2 % MOD);
		int smallSumCarry = (int) ((long) p * (p - 1) / 2 % MOD);
		int tot = (int) ((long) p * p % MOD);
		int bigSumNoCarry = tot - smallSumNoCarry;
		if (bigSumNoCarry < 0) {
			bigSumNoCarry += MOD;
		}

		int bigSumCarry = tot - smallSumCarry;
		if (bigSumCarry < 0) {
			bigSumCarry += MOD;
		}

		Collections.reverse(digs);
		for (int x : digs) {
			int N = dpEq[0].length;
			int[][] nextEq = new int[2][N + 1];
			int[][] nextLess = new int[2][N + 1];
			// make exactly x

			for (int i = 0; i < N; i++) {
				// --without carry here
				nextEq[0][i] += (int) ((long) dpEq[0][i] * (x + 1) % MOD);
				if (nextEq[0][i] >= MOD) {
					nextEq[0][i] -= MOD;
				}
				nextEq[1][i] += (int) ((long) dpEq[0][i] * x % MOD);
				if (nextEq[1][i] >= MOD) {
					nextEq[1][i] -= MOD;
				}

				// -- with carry here
				nextEq[0][i + 1] += (int) ((long) dpEq[1][i] * (p - 1 - x) % MOD);
				if (nextEq[0][i + 1] >= MOD) {
					nextEq[0][i + 1] -= MOD;
				}
				nextEq[1][i + 1] += (int) ((long) dpEq[1][i] * (p - x) % MOD);
				if (nextEq[1][i + 1] >= MOD) {
					nextEq[1][i + 1] -= MOD;
				}
			}

			int smNo = (int) ((long) (x + 1) * x / 2 % MOD);
			int smCarr = (int) ((long) x * (x - 1) / 2 % MOD);
			int bigNo = (int)((long)(2 * p - 1 - x) * x / 2 % MOD);
			

			int bigCarr = (int)((long)(2 * p + 1 - x) * x / 2 % MOD);
			// eq to less

			for (int i = 0; i < N; i++) {
				// --without carry here
				nextLess[0][i] += (int) ((long) dpEq[0][i] * smNo % MOD);
				if (nextLess[0][i] >= MOD) {
					nextLess[0][i] -= MOD;
				}
				nextLess[1][i] += (int) ((long) dpEq[0][i] * smCarr % MOD);
				if (nextLess[1][i] >= MOD) {
					nextLess[1][i] -= MOD;
				}

				// -- with carry here
				nextLess[0][i + 1] += (int) ((long) dpEq[1][i] * bigNo % MOD);
				if (nextLess[0][i + 1] >= MOD) {
					nextLess[0][i + 1] -= MOD;
				}
				nextLess[1][i + 1] += (int) ((long) dpEq[1][i] * bigCarr % MOD);
				if (nextLess[1][i + 1] >= MOD) {
					nextLess[1][i + 1] -= MOD;
				}
			}

			// make whatever
			for (int i = 0; i < N; i++) {
				// --without carry here
				nextLess[0][i] += (int) ((long) dpLess[0][i] * smallSumNoCarry % MOD);
				if (nextLess[0][i] >= MOD) {
					nextLess[0][i] -= MOD;
				}
				nextLess[1][i] += (int) ((long) dpLess[0][i] * smallSumCarry % MOD);
				if (nextLess[1][i] >= MOD) {
					nextLess[1][i] -= MOD;
				}

				// -- with carry here
				nextLess[0][i + 1] += (int) ((long) dpLess[1][i]
						* bigSumNoCarry % MOD);
				if (nextLess[0][i + 1] >= MOD) {
					nextLess[0][i + 1] -= MOD;
				}
				nextLess[1][i + 1] += (int) ((long) dpLess[1][i] * bigSumCarry % MOD);
				if (nextLess[1][i + 1] >= MOD) {
					nextLess[1][i + 1] -= MOD;
				}
			}

			dpEq = nextEq;
			dpLess = nextLess;

//			System.err.println(Arrays.deepToString(dpEq));
//			System.err.println(Arrays.deepToString(dpLess));

		}

		int ret = 0;
		for (int i = need; i < dpLess[0].length; i++) {
			ret += dpLess[0][i];
			if (ret >= MOD) {
				ret -= MOD;
			}
			ret += dpEq[0][i];
			if (ret >= MOD) {
				ret -= MOD;
			}
		}

		out.println(ret);
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