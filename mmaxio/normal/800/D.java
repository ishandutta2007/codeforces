import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int N = 1_000_000;
	static final int P = 1_000_000_007;

	boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] cnt = new int[N];
		int[] val = new int[N];
		int[] val2 = new int[N];

		int[] pw2 = new int[N + 1];
		pw2[0] = 1;
		for (int i = 1; i <= N; i++) {
			pw2[i] = 2 * pw2[i - 1] % P;
		}

		int[] maskDeltas = new int[64];
		int[] maskSigns = new int[64];
		for (int i = 0; i < 64; i++) {
			int pw10 = 1;
			maskSigns[i] = 1;
			for (int j = 0; j < 6; j++) {
				if (test(i, j)) {
					maskDeltas[i] += pw10;
					maskSigns[i] *= -1;
				}
				pw10 *= 10;
			}
		}

		for (int i = 0; i < n; i++) {
			int x = nextInt();
			val[x] += x;
			val[x] %= P;
			int sqX = (int) ((long) x * x % P);
			val2[x] += sqX;
			val2[x] %= P;
			cnt[x]++;
		}

		for (int i = N - 1; i >= 0; i--) {
			int maskCan = 0;
			for (int j = 0, ii = i; j < 6; j++) {
				if (ii % 10 != 9) {
					maskCan |= 1 << j;
				}
				ii /= 10;
			}

			for (int sub = maskCan; sub > 0; sub = (sub - 1) & maskCan) {
				int sign = maskSigns[sub];
				int pos = i + maskDeltas[sub];
				if (sign == -1) {
					cnt[i] += cnt[pos];
					val[i] += val[pos];
					if (val[i] >= P) {
						val[i] -= P;
					}
					val2[i] += val2[pos];
					if (val2[i] >= P) {
						val2[i] -= P;
					}
				} else {
					cnt[i] -= cnt[pos];
					val[i] -= val[pos];
					if (val[i] < 0) {
						val[i] += P;
					}
					val2[i] -= val2[pos];
					if (val2[i] < 0) {
						val2[i] += P;
					}
				}
			}
		}

		int[] goodVals = new int[N];

		for (int i = 0; i < N; i++) {
			
//			if (cnt[i] != 0) {
//				System.err.println(i + ": " + val[i] + " " + val2[i] + " " + cnt[i]);
//			}
			
			if (cnt[i] == 0) {
				goodVals[i] = 0;
			} else if (cnt[i] == 1) {
				goodVals[i] = val2[i];
			} else {
				goodVals[i] = (int) ((long) val[i] * val[i] % P);
				goodVals[i] += val2[i];
				if (goodVals[i] >= P) {
					goodVals[i] -= P;
				}
				goodVals[i] = (int) ((long) goodVals[i] * pw2[cnt[i] - 2] % P);
			}
//			if (goodVals[i] != 0) {
//				System.err.println(i + " " + goodVals[i]);
//			}
		}

		long ansXor = 0;

		for (int i = 0; i < N; i++) {
			int maskCan = 0;
			for (int j = 0, ii = i; j < 6; j++) {
				if (ii % 10 != 9) {
					maskCan |= 1 << j;
				}
				ii /= 10;
			}

			int realVal = goodVals[i];

			for (int sub = maskCan; sub > 0; sub = (sub - 1) & maskCan) {
				int sign = maskSigns[sub];
				int pos = i + maskDeltas[sub];
				if (sign == 1) {
					realVal += goodVals[pos];
					if (realVal >= P) {
						realVal -= P;
					}
				} else {
					realVal -= goodVals[pos];
					if (realVal < 0) {
						realVal += P;
					}
				}
			}
			
			long shitForAns = (long) i * realVal;
			ansXor ^= shitForAns;
		}

		out.println(ansXor);
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