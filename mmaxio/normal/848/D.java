import java.io.*;
import java.util.*;

public class D {

	static final int P = 1_000_000_007;

	static final int N = 52;
	
	void submit() {
		int n = nextInt();
		int m = nextInt();

		int[][] f = new int[N + 1][N + 1];

		f[0][1] = 1;

		for (int sz = 1; sz <= n; sz++) {

			int[][] dp = new int[sz + 1][N + 1];
			dp[0][1] = 1;

			int[][] cnt = new int[sz + 1][N + 1]; // [size][cut]

			for (int szL = 0; szL + 1 <= sz; szL++) {
				for (int cutL = 1; cutL <= N; cutL++) {
					for (int szR = 0; szL + szR + 1 <= sz; szR++) {
						for (int cutR = 1; cutR <= N; cutR++) {

							int szLR = szL + szR + 1;
							int cutLR = Math.min(cutL, cutR);

							cnt[szLR][cutLR] += (int) ((long) f[szL][cutL]
									* f[szR][cutR] % P);
							if (cnt[szLR][cutLR] >= P) {
								cnt[szLR][cutLR] -= P;
							}
						}
					}
				}
			}


			for (int addSz = 1; addSz <= sz; addSz++) {
				for (int addCut = 1; addCut <= N; addCut++) {
					
					if (cnt[addSz][addCut] == 0) {
						continue;
					}
					
					int[][] nextDp = new int[sz + 1][];
					for (int i = 0; i <= sz; i++) {
						nextDp[i] = dp[i].clone();
					}
					
					int smth = sz / addSz;
					
					int[] arrWays = new int[smth + 1];
					int base = cnt[addSz][addCut];
					
					arrWays[0] = 1;
					
					for (int i = 1; i <= smth; i++) {
						arrWays[i] = (int)((long)arrWays[i - 1] * inv[i] % P * base % P);
						base++;
						if (base == P) {
							base = 0;
						}
					}
					
					for (int cntAdd = 1; cntAdd <= smth; cntAdd++) {

						int ways = arrWays[cntAdd];

						for (int i = sz - addSz * cntAdd; i >= 0; i--) {
							for (int j = N - addCut * cntAdd; j >= 1; j--) {

								if (i + addSz * cntAdd <= sz
										&& j + addCut * cntAdd <= N) {

									nextDp[i + addSz * cntAdd][j + addCut * cntAdd] += (int) ((long) dp[i][j]
											* ways % P);
									if (nextDp[i + addSz * cntAdd][j + addCut
											* cntAdd] >= P) {
										nextDp[i + addSz * cntAdd][j + addCut
												* cntAdd] -= P;
									}

								}

							}
						}

					}
					
					dp = nextDp;
					
				}
			}

			for (int j = 1; j <= N; j++) {
				f[sz][j] = dp[sz][j];
			}

		}

//		for (int i = 0; i <= n; i++) {
//			for (int j = 1; j <= N; j++) {
//				if (f[i][j] != 0) {
//					System.err.println(i + " " + j + " -> " + f[i][j]);
//				}
//			}
//			
//			System.err.println();
//		}
		
		out.println(f[n][m]);

	}

	int[] inv = new int[1000];
	{
		inv[0] = 0;
		inv[1] = 1;
		for (int i = 2; i < inv.length; i++) {
			inv[i] = P - (int) ((long) (P / i) * inv[P % i] % P);
		}
	}
	
	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	D() throws IOException {
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
		new D();
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