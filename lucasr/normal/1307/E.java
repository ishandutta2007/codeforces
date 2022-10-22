import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lucasr
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		MyScanner in = new MyScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		ECowAndTreats solver = new ECowAndTreats();
		solver.solve(1, in, out);
		out.close();
	}

	static class ECowAndTreats {
		static long MOD = 1000000007;
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			ECowAndTreats.sc = sc;
			ECowAndTreats.out = out;
			int n = sc.nextInt();
			int m = sc.nextInt();
			int[] elems = sc.nextIntArray(n);
			int[] sweetCount = new int[n + 1];
			boolean[][] present = new boolean[n + 1][n + 1];
			for (int i = 0; i < n; i++) {
				sweetCount[elems[i]]++;
			}
			IntArray[] cant = new IntArray[n + 1];
			for (int i = 1; i <= n; i++) {
				cant[i] = new IntArray();
			}
			for (int i = 0; i < m; i++) {
				int a = sc.nextInt();
				int cc = sc.nextInt();
				present[a][cc] = true;
				cant[a].add(cc);
			}
			for (int i = 1; i <= n; i++) {
				cant[i].sort();
			}
			int ans = 0;
			long tot = 1;

			int[] acumLeft = new int[n + 1];
			for (int i = 1; i <= n; i++) {
				int got = 0;
				for (int ii = 0; ii < cant[i].size(); ii++) {
					if (cant[i].get(ii) <= sweetCount[i]) got++;
					else break;
				}
				if (got > 0) {
					ans++;
					tot = (tot * got) % MOD;
				}
			}
			for (int pos = 0; pos < n; pos++) {
				int sw = elems[pos];
				acumLeft[sw]++;
				if (present[sw][acumLeft[sw]]) {
					int curAns = 1;
					long curTot = 1;
					for (int i = 1; i <= n; i++)
						if (cant[i].size() > 0) {
							if (i == sw) {
								int got = 0;
								for (int ii = 0; ii < cant[i].size(); ii++) {
									int val = cant[i].get(ii);
									if (val <= sweetCount[i] - acumLeft[i] && val != acumLeft[i]) got++;
								}
								if (got > 0) {
									curAns++;
									curTot = (curTot * got) % MOD;
								}
							} else {
								int min = Math.min(sweetCount[i] - acumLeft[i], acumLeft[i]);
								int max = Math.max(sweetCount[i] - acumLeft[i], acumLeft[i]);
								int totMin = 0, totMax = 0;
								for (int ii = 0; ii < cant[i].size(); ii++) {
									int val = cant[i].get(ii);
									if (val <= min) totMin++;
									else if (val <= max) totMax++;
									else break;
								}
								totMax += totMin;
								long tot2 = totMin * (long) (totMax - 1);
								if (tot2 > 0) {
									curAns += 2;
									curTot = (curTot * tot2) % MOD;
								} else if (totMax > 0) {
									curAns++;
									curTot = (curTot * (totMin + totMax)) % MOD;
								}
							}
						}
					if (curAns >= ans) {
						if (curAns > ans) {
							ans = curAns;
							tot = curTot;
						} else {
							tot = (tot + curTot) % MOD;
						}
					}
				}
			}

			out.println(ans + " " + tot);
		}

	}

	static class IntArray {
		int[] arr;
		int size;

		public IntArray() {
			arr = new int[4];
		}

		public void add(int val) {
			if (size == arr.length) {
				arr = Arrays.copyOf(arr, 2 * arr.length);
			}
			arr[size++] = val;
		}

		public int get(int pos) {
			return arr[pos];
		}

		public int size() {
			return size;
		}

		public void sort() {
			Arrays.sort(arr, 0, size);
		}

	}

	static class MyScanner {
		private BufferedReader br;
		private StringTokenizer tokenizer;

		public MyScanner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public int[] nextIntArray(int n) {
			int[] ret = new int[n];
			for (int i = 0; i < n; i++) {
				ret[i] = nextInt();
			}
			return ret;
		}

	}
}